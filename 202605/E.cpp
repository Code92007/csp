// Candidate-root algorithm described by zlxFTH:
// https://www.zhihu.com/question/2043989350854156307/answer/2044499207764105133
// Reimplemented with iterative traversals, binary lifting and lazy local heaps.
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class GatherSolver {
    using MinHeap = priority_queue<int, vector<int>, greater<int>>;
    const int inf;
    int n, levels, candidates, fixed_root = 0, cursor = 0;
    vector<vector<int>> graph, up;
    vector<int> depth, toward, sealed_count;
    vector<bool> emitted, black;
    vector<MinHeap> local;
    vector<int> leader, component_size, component_min;
    vector<set<int>> boundary;
    set<int> red_events;
    vector<int> answer;

    int step(int from, int destination) const {
        // First vertex on the path from 'from' to 'destination'.
        if (depth[destination] > depth[from]) {
            int v = destination;
            int jump = depth[destination] - depth[from] - 1;
            for (int bit = 0; jump; ++bit, jump >>= 1)
                if (jump & 1)
                    v = up[bit][v];
            if (up[0][v] == from)
                return v;
        }
        return up[0][from];
    }

    int minimum_other_neighbor(int vertex, int excluded) const {
        for (int i = 0; i < min(2, int(graph[vertex].size())); ++i)
            if (graph[vertex][i] != excluded)
                return graph[vertex][i];
        return inf;
    }

    int remaining_min(int vertex) {
        auto &heap = local[vertex];
        while (!heap.empty() && emitted[heap.top()])
            heap.pop();
        return heap.empty() ? inf : heap.top();
    }

    void output(int vertex) {
        assert(vertex >= 1 && vertex <= n && !emitted[vertex]);
        emitted[vertex] = true;
        answer.push_back(vertex);
    }

    int find_component(int vertex) {
        int root = vertex;
        while (leader[root] != root)
            root = leader[root];
        while (vertex != root) {
            int next = leader[vertex];
            leader[vertex] = root;
            vertex = next;
        }
        return root;
    }

    int join_components(int a, int b) {
        a = find_component(a);
        b = find_component(b);
        if (a == b)
            return a;
        if (component_size[a] < component_size[b])
            swap(a, b);
        leader[b] = a;
        component_size[a] += component_size[b];
        component_min[a] = min(component_min[a], component_min[b]);
        boundary[a].merge(boundary[b]);
        boundary[b].clear();
        return a;
    }

    int activate_black(int vertex) {
        if (black[vertex])
            return find_component(vertex);
        black[vertex] = true;
        component_min[vertex] = min(vertex, graph[vertex].front());
        boundary[vertex].insert(inf);
        int root = vertex;
        for (int adjacent : graph[vertex]) {
            if (!black[adjacent]) {
                boundary[find_component(root)].insert(minimum_other_neighbor(adjacent, vertex));
            } else {
                int other = find_component(adjacent);
                boundary[other].erase(minimum_other_neighbor(vertex, adjacent));
                boundary[other].insert(inf);
                root = join_components(root, other);
            }
        }
        return find_component(root);
    }

    void add_seals(int start, int increment) {
        if (increment == 0)
            return;
        vector<int> stack{start};
        while (!stack.empty()) {
            int vertex = stack.back();
            stack.pop_back();
            if (sealed_count[vertex] >= 2)
                continue;
            sealed_count[vertex] = min(2, sealed_count[vertex] + increment);
            for (int child : graph[vertex])
                if (toward[child] == vertex)
                    stack.push_back(child);
        }
    }

    void seal(int vertex, int entry) {
        if (sealed_count[vertex] > sealed_count[toward[vertex]])
            return;
        add_seals(vertex, 1);
        if (entry == graph[vertex].front())
            red_events.insert(entry);
    }

    void orient_branch(int first, int parent) {
        vector<pair<int, int>> stack{{first, parent}};
        while (!stack.empty()) {
            auto [vertex, next] = stack.back();
            stack.pop_back();
            assert(toward[vertex] == 0);
            toward[vertex] = next;
            --candidates;
            int inherited = sealed_count[next];
            sealed_count[vertex] = min(2, sealed_count[vertex] + inherited);
            for (int adjacent : graph[vertex]) {
                if (toward[adjacent] == vertex)
                    add_seals(adjacent, inherited);
                else if (adjacent != next && toward[adjacent] == 0)
                    stack.emplace_back(adjacent, vertex);
            }
        }
    }

    int next_for_root(int root = 0) {
        if (root != 0)
            fixed_root = cursor = root;
        while (true) {
            int direct = remaining_min(cursor);
            if (direct != inf)
                return direct;
            int group = activate_black(cursor);
            int head = component_min[group];
            int border = *boundary[group].upper_bound(head);
            auto event_it = red_events.lower_bound(head);
            int delayed_vertex = 0, delayed_value = inf;
            if (event_it != red_events.begin()) {
                int event = *prev(event_it);
                if (boundary[group].count(event)) {
                    delayed_vertex = toward[event];
                    delayed_value = remaining_min(delayed_vertex);
                    // Empty delayed region must be contracted before comparing exits.
                    if (delayed_value == inf)
                        delayed_value = 0;
                }
            }
            if (border < delayed_value)
                cursor = step(border, fixed_root);
            else {
                assert(delayed_vertex != 0 && delayed_value != inf);
                cursor = delayed_vertex;
            }
        }
    }

    int select_root() {
        int current = 1, stopping_root = 0;
        while (candidates > 1) {
            int parent = toward[current];
            output(current);
            if (parent)
                seal(parent, current);
            int next = current + 1, first = 0, second = 0;
            bool distant = false;
            for (; next <= n; ++next) {
                first = step(current, next);
                second = first == next ? 0 : step(first, next);
                distant = second != 0 && second != next;
                if (sealed_count[toward[next]] + int(distant) > 1)
                    continue;
                if (!parent && second && toward[distant ? second : first])
                    continue;
                break;
            }
            if (next > n)
                return parent ? parent : current;
            if (parent) {
                if (distant)
                    orient_branch(first, second);
                current = next;
                continue;
            }
            // The common prefix can also end at one initial central block.
            int stop = 0;
            if (candidates == 2 && second)
                stop = current;
            else if (stopping_root && !toward[stopping_root])
                stop = stopping_root;
            if (stop && next_for_root(stop) < next)
                return stop;
            if (stopping_root && first != stopping_root)
                seal(current, stopping_root);
            if (!second) {
                for (int neighbor : graph[current])
                    if (neighbor != next && !toward[neighbor])
                        orient_branch(neighbor, current);
                stopping_root = current;
            } else {
                if (distant && first != stopping_root)
                    stopping_root = 0;
                orient_branch(distant ? first : current, distant ? second : first);
                seal(first, current);
            }
            current = next;
        }
        return toward[current] ? toward[current] : current;
    }

  public:
    explicit GatherSolver(vector<vector<int>> adjacency)
        : inf(int(adjacency.size()) + 1), n(int(adjacency.size()) - 1), candidates(n),
          graph(std::move(adjacency)), depth(n + 1), toward(n + 1), sealed_count(n + 1),
          emitted(n + 1), black(n + 1), local(n + 1), leader(n + 1), component_size(n + 1, 1),
          component_min(n + 1), boundary(n + 1) {
        levels = 1;
        while ((1LL << levels) <= n)
            ++levels;
        up.assign(levels, vector<int>(n + 1));
        iota(leader.begin(), leader.end(), 0);
        for (int vertex = 1; vertex <= n; ++vertex) {
            sort(graph[vertex].begin(), graph[vertex].end());
            local[vertex].push(vertex);
            for (int neighbor : graph[vertex])
                local[vertex].push(neighbor);
        }
        vector<int> order{1};
        for (size_t i = 0; i < order.size(); ++i) {
            int vertex = order[i];
            for (int neighbor : graph[vertex]) {
                if (neighbor == up[0][vertex])
                    continue;
                up[0][neighbor] = vertex;
                depth[neighbor] = depth[vertex] + 1;
                order.push_back(neighbor);
            }
        }
        for (int bit = 1; bit < levels; ++bit)
            for (int vertex = 1; vertex <= n; ++vertex)
                up[bit][vertex] = up[bit - 1][up[bit - 1][vertex]];
    }

    vector<int> solve() {
        if (n == 1)
            return {1};
        int root = select_root();
        while (int(answer.size()) < n) {
            output(next_for_root(root));
            root = 0;
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto answer = GatherSolver(std::move(graph)).solve();
    for (int i = 0; i < n; ++i)
        cout << answer[i] << (i + 1 == n ? '\n' : ' ');
}
