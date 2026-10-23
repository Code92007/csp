# 如何维护题解

每个 `YYYYMM/README.md` 是一场比赛的完整内容源。文章中的代码块生成同目录的 `A.cpp` 至 `E.cpp`，网页索引也从文章读取。以后新增场次，只需要新增这个文件夹和 Markdown；没有需要手工维护的题目数据库。

## 文章元数据

文件最上方由两条 `---` 包围的部分是 YAML frontmatter。本工程约定“每行一个键，值采用 JSON 写法”，这样既是合法 YAML，又能用 Python 标准库读取，无需安装解析包。

```yaml
---
title: "CSP 202609 五题题解"
contest: "202609"
contest_month: "2026-09"
date: "2026-10-23"
updated: "2026-10-23"
tags: ["CSP", "模拟", "动态规划"]
status: "draft"
problems: [{"id":"A","title":"题目名","tags":["模拟"],"status":"pending","code":"A.cpp","anchor":"problem-a","validation":"待验证","sources":[]}]
---
```

上例只展示一题的字段，实际必须依次列出 A、B、C、D、E 五题。`contest` 用于比赛排序；`date` 是文章创建日期，`updated` 是文章更新日期，不用虚构比赛具体哪一天。文章 `tags` 汇总五题标签；`problems[*].tags` 用于按题筛选。标签尽量用统一名称，例如统一用“动态规划”，避免再创建含义相同的“DP”。

- `implemented`：已有完整算法与代码；验证情况另写在 `validation`。
- `partial`：只覆盖明确说明的子任务。正文写清适用范围，不能算整题完成。
- `pending`：只有目录或准备资料，尚未写成题解。
- 文章 `status`：五题都 `implemented` 后设为 `published`，否则保留 `draft`。

## 文章正文

每道题固定使用如下结构。每题保留一个 `cpp` 代码块，可在题解中使用其他语言标识的伪代码块。

````markdown
<a id="problem-a"></a>

## A. 题目名

### 题意

自行概述输入、目标、关键规则与数据范围，并保留来源链接。

### 题解

从直观做法讲到使用的算法，说明状态/转移或核心不变量，解释正确性、复杂度和边界。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
int main() { return 0; }
```
````

## 编辑与验证

以文章中的代码为准，编辑后执行：

```sh
make sync
make check
make site
```

如果先在 CPP 中调试，需要把最终代码完整放回文章，再运行检查。`make sync` 会用文章覆盖 CPP；不要在 CPP 中保留尚未回填的改动时运行它。

新增样例放在 `tests/202609A.json` 这类文件中，格式为 `[{"input":"输入\n","output":"输出\n"}]`。多解题应另写独立检查器，而不是拿文本逐字比较。随机对拍应使用与正式解法不同的暴力或模拟作为基准，并固定随机种子方便重现。

本地样例、自建数据、随机对拍与正式评测 AC 是四种不同证据。没有提交记录就不能写“已 AC”。草稿里的 `#error` 是明确的未实现标记，检查工具会跳过这些题。
