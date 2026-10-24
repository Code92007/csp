# CSP 200 分以上备考：每天 2–3 小时，四周默认计划

更新日期：2026-10-23。推荐题目与逐场考点均按考试年月从新到旧排列。适用基础：已学 C/C++、数据结构，缺少独立在线评测练习。

四周总投入约 56–84 小时。备考分数设计为 220–260：争取 T1=100、T2=100，T3/T4 合计再拿 20–60；这是训练目标，不是结果保证。若 T2 只得 80，必须从其他题补到至少 30 才能严格超过 200。

官网说明为 5 题、每题 100 分、共 4 小时。练习优先用 C++，先补 STL、独立调试与复杂度判断。近年 T2 已涉及背包、BFS、二分，不能只靠早年的直接模拟。

## 数据范围与使用方式

本清单范围沿用此前从用户所给曙梦 OJ 整理的 32 个年月组，不是历届完整题库。原目录记录了 152 条 A–E 标准条目（含第 0 次练习题组 201312）及 4 条变体；其中 201712、202109 原来各缺四题。本工程已补上这八题的目录，合计 160 个标准题位，但题解完成状态需查看工程总目录。

2026-10-25 曙梦 OJ 已恢复访问。现有 160 个标准题位中，152 题在分类页公开可见；201712 和 202109 各有 4 题为隐藏题，当前账号无权查看。可见题优先链接原站，隐藏题跳转本工程题解；题面核对来源见 `docs/sources.md`。

未收录整套的日期包括：202212、202209、202203、202012、202009、201909、201903、201812、201803、201709、201612、201609。下文不会为这些缺失题目推断考点。

OJ 题面注明部分试题采用自造复刻数据，也存在调整后的时限；该站得分与正式认证得分不能直接画等号。本站编号后缀 A/B/C/D/E 对应 T1/T2/T3/T4/T5；后缀带 2、3 的加强版不列入必做任务。

考点是根据站内标签及抽查题面做的备考归纳，不是官方命题比例；某题可能有多种算法。T4/T5 标签只用于了解，短期先不系统学习其全部满分算法。

## 推荐题单：按考试年月从新到旧

从 2026-09 开始往前练。同场先做 A、B；C、D 标为选做，用来练额外得分。新到旧并不代表由易到难，遇到二分、BFS、背包时，先用当天的学习时间补必要基础，再做题。前两题未完成时，可把选做日改为补题日。

主线共 32 道题：27 道 A/B 优先练习，4 道 C 和 1 道 D 选做。下面的“目标”是练习要求；先尝试独立完成，再按需要看最小提示。

| 年月 | 题目 | 考点 | 建议目标 |
|---|---|---|---|
| 2026-09 | [202609A 流程规划（其一）](../202609/README.md#problem-a) | 按公式计算、查表、格式 | 优先练：争取独立满分 |
| 2026-09 | [202609B 流程规划（其二）](../202609/README.md#problem-b) | 01 背包建模 | 优先练：争取独立满分 |
| 2026-09 | [202609C 轮转调度](../202609/README.md#problem-c) | 队列、轮转调度模拟 | 选做：正确完成子任务，再争取满分 |
| 2026-05 | [202605B 机器人宿管指南](https://oj.shumeng.tech/p/CSP202605B) | 二分答案 + 过程模拟 | 优先练：争取独立满分 |
| 2026-03 | [202603B 机器人项目管理](https://oj.shumeng.tech/p/CSP202603B) | 分数背包贪心 + 01 背包 | 优先练：争取独立满分 |
| 2026-03 | [202603C 进程通信](https://oj.shumeng.tech/p/CSP202603C) | 内存分配、循环队列、空闲区间合并 | 选做：正确完成子任务，再争取满分 |
| 2025-12 | [202512A 集合](https://oj.shumeng.tech/p/CSP202512A) | 集合比较、异或 | 优先练：争取独立满分 |
| 2025-12 | [202512B 数字变换](https://oj.shumeng.tech/p/CSP202512B) | 位拆分、小状态变换 | 优先练：争取独立满分 |
| 2025-06 | [202506B 机器人复健指南](https://oj.shumeng.tech/p/CSP202506B) | 网格 BFS、去重可达状态 | 优先练：争取独立满分 |
| 2025-03 | [202503B 机器人饲养指南](https://oj.shumeng.tech/p/CSP202503B) | 完全背包 DP | 优先练：争取独立满分 |
| 2024-12 | [202412C 缓存模拟](https://oj.shumeng.tech/p/CSP202412C) | 缓存替换、状态模拟 | 选做：正确完成子任务，再争取满分 |
| 2024-03 | [202403A 词频统计](https://oj.shumeng.tech/p/CSP202403A) | 词频、按文档去重 | 优先练：争取独立满分 |
| 2024-03 | [202403B 相似度计算](https://oj.shumeng.tech/p/CSP202403B) | 字符串规范化、集合交并 | 优先练：争取独立满分 |
| 2024-03 | [202403D 十滴水](https://oj.shumeng.tech/p/CSP202403D) | 链表／有序集合、连锁模拟 | 选做：正确完成子任务，再争取满分 |
| 2023-12 | [202312B 因子化简](https://oj.shumeng.tech/p/CSP202312B) | 试除法、质因数分解 | 优先练：争取独立满分 |
| 2023-09 | [202309A 坐标变换（其一）](https://oj.shumeng.tech/p/CSP202309A) | 位移累加 | 优先练：争取独立满分 |
| 2023-09 | [202309B 坐标变换（其二）](https://oj.shumeng.tech/p/CSP202309B) | 旋转缩放、前缀积／和 | 优先练：争取独立满分 |
| 2023-05 | [202305B 矩阵运算](https://oj.shumeng.tech/p/CSP202305B) | 矩阵乘法结合律、复杂度 | 优先练：争取独立满分 |
| 2023-03 | [202303B 垦田计划](https://oj.shumeng.tech/p/CSP202303B) | 二分答案／贪心 | 优先练：争取独立满分 |
| 2021-04 | [202104B 邻域均值](https://oj.shumeng.tech/p/CSP202104B) | 二维前缀和、边界裁剪 | 优先练：争取独立满分 |
| 2020-06 | [202006B 稀疏向量](https://oj.shumeng.tech/p/CSP202006B) | 稀疏存储、双指针／映射 | 优先练：争取独立满分 |
| 2019-12 | [201912B 回收站选址](https://oj.shumeng.tech/p/CSP201912B) | 坐标集合、邻居查询 | 优先练：争取独立满分 |
| 2017-12 | [201712B 游戏](https://oj.shumeng.tech/p/CSP201712B) | 循环淘汰、队列 | 优先练：争取独立满分 |
| 2017-03 | [201703B 学生排队](https://oj.shumeng.tech/p/CSP201703B) | 序列删除与插入 | 优先练：争取独立满分 |
| 2015-12 | [201512B 消除类游戏](https://oj.shumeng.tech/p/CSP201512B) | 二维标记、同时消除 | 优先练：争取独立满分 |
| 2015-03 | [201503A 图像旋转](https://oj.shumeng.tech/p/CSP201503A) | 矩阵下标变换 | 优先练：争取独立满分 |
| 2015-03 | [201503B 数字排序](https://oj.shumeng.tech/p/CSP201503B) | 频次统计、自定义排序 | 优先练：争取独立满分 |
| 2014-09 | [201409B 画图](https://oj.shumeng.tech/p/CSP201409B) | 网格覆盖标记 | 优先练：争取独立满分 |
| 2014-03 | [201403B 窗口](https://oj.shumeng.tech/p/CSP201403B) | 窗口层叠、顺序模拟 | 优先练：争取独立满分 |
| 2014-03 | [201403C 命令行选项](https://oj.shumeng.tech/p/CSP201403C) | 命令行规则解析 | 选做：正确完成子任务，再争取满分 |
| 2013-12 | [201312A 出现次数最多的数](https://oj.shumeng.tech/p/CSP201312A) | 频次统计、并列取最小 | 优先练：争取独立满分 |
| 2013-12 | [201312B ISBN 号码](https://oj.shumeng.tech/p/CSP201312B) | 校验码、字符串 | 优先练：争取独立满分 |

## 每天怎么练

120 分钟版本：15 分钟复盘 + 20 分钟学一个必要知识点 + 65 分钟独立做题/调试 + 20 分钟记录和自测。若有 180 分钟，增加 60 分钟补题或重写。遇到长题时，两天做一题完全正常。

看题解前先写下输入规模、状态/转移、复杂度和卡住点。T1 独立尝试约 25–35 分钟，T2 约 50–70 分钟，T3 可跨两天。卡住后只看最小必要提示，关闭后独立重写；24–48 小时后再做一次。看懂题解不算掌握。

每题至少自造三类边界：最小输入；重复/全相同/无解/恰好贴边；最大规模和数值范围。重点检查 long long、乘法提升、数组边界、先后更新、getline 空行、浮点输出。

题量按完成质量调整：主线新题严格按年月倒序，复盘可回头重做。32 道是推荐范围，选做题和已经熟练的早年基础题可以跳过。优先保证 A/B 的独立正确率，不挤占错题重做时间。最近一套现在用于起步练习，不再保留作最后的陌生题测试。

## 28 天安排：新题从新到旧，每天 2–3 小时

每天的题号按下表顺序练。每周留一天复盘；同一长题可跨两天。选做日可以换成前两题补题日，做不完时延长天数，不要求靠压缩调试时间赶进度。

| 完成 | 天 | 题目年月 | 主题 | 练习题 | 当天检查点 |
|---|---|---|---|---|---|
| ☐ | 1 | 2026-09 | 熟悉评测、公式与输出 | [202609A 流程规划（其一）](../202609/README.md#problem-a) | 先熟悉 vector、string、输入输出；按题给公式计算，自测查表中点和小数格式。 |
| ☐ | 2 | 2026-09 | 第二题：01 背包 | [202609B 流程规划（其二）](../202609/README.md#problem-b) | 先学 01 背包状态、初始化和倒序更新；先做等收益的子任务，再争取完整解。 |
| ☐ | 3 | 2026-09 | 第三题选做：轮转调度（一） | [202609C 轮转调度](../202609/README.md#problem-c) | T2 尚未完成就继续补 T2；有余力再读 C，画出队列与时间片状态。 |
| ☐ | 4 | 2026-09 | 第三题选做：轮转调度（二） | 继续前一天题目或补前两题 | 完成前一天的模拟或一个明确子任务；也可用两天重写背包，不要求第三题满分。 |
| ☐ | 5 | 2026-05 | 第二题：二分答案 | [202605B 机器人宿管指南](https://oj.shumeng.tech/p/CSP202605B) | 先学单调性和二分边界，再写天数模拟；用整数向上取整，检查恰好吃完。 |
| ☐ | 6 | 2026-03 | 第二题：贪心与背包 | [202603B 机器人项目管理](https://oj.shumeng.tech/p/CSP202603B) | 先完成全灵活型任务的贪心子任务，再学习如何与普通任务的 01 背包结合。 |
| ☐ | 7 | 复盘 | 第一周复盘 | 复盘与重做 | 重做已练的 T1 与最弱的 T2；检查 01 背包倒序、二分边界和数值类型。 |
| ☐ | 8 | 2026-03 | 第三题选做：进程通信 | [202603C 进程通信](https://oj.shumeng.tech/p/CSP202603C) | 先列最佳适应分配、循环写入、删除后空闲区间合并的规则；若前两题仍不稳，这天继续补前两题。 |
| ☐ | 9 | 2025-12 | 集合与位运算 | [202512A 集合](https://oj.shumeng.tech/p/CSP202512A)；[202512B 数字变换](https://oj.shumeng.tech/p/CSP202512B) | 先补按位与、按位或、异或、移位、掩码；A 争取独立通过，B 先做小状态枚举。 |
| ☐ | 10 | 2025-06 | 第二题：BFS | [202506B 机器人复健指南](https://oj.shumeng.tech/p/CSP202506B) | 按题面图示确定移动；入队时去重；统计步数范围内的不同位置。 |
| ☐ | 11 | 2025-03 | 第二题：完全背包 | [202503B 机器人饲养指南](https://oj.shumeng.tech/p/CSP202503B) | 写清 dp 含义和转移，比较与 01 背包的更新顺序；检查能否恰好用完。 |
| ☐ | 12 | 2024-12 | 第三题选做：缓存模拟（一） | [202412C 缓存模拟](https://oj.shumeng.tech/p/CSP202412C) | 把命中、载入、替换、写回分别列规则，先实现小规模直接模拟。 |
| ☐ | 13 | 2024-12 | 第三题选做：缓存模拟（二） | 继续前一天题目或补前两题 | 补完边界或一个子任务；前两题不稳时改为重做 BFS/背包。 |
| ☐ | 14 | 复盘 | 第二周复盘 | 复盘与重做 | 独立重写 BFS 和背包中最不熟的一题；自造重复状态、最小容量等输入。 |
| ☐ | 15 | 2024-03 | 词频与集合交并 | [202403A 词频统计](https://oj.shumeng.tech/p/CSP202403A)；[202403B 相似度计算](https://oj.shumeng.tech/p/CSP202403B) | 先补 map/set、字符串规范化；按文档去重，避免把同一文档重复计数。 |
| ☐ | 16 | 2024-03 | 第四题选做：十滴水 | [202403D 十滴水](https://oj.shumeng.tech/p/CSP202403D) | 先正确完成题面限定的小规模子任务，严格遵守最左先爆的更新顺序。 |
| ☐ | 17 | 2023-12 | 第二题：质因数分解 | [202312B 因子化简](https://oj.shumeng.tech/p/CSP202312B) | 试除到 sqrt(n)，处理剩余质因子；留意 64 位整数。 |
| ☐ | 18 | 2023-09 | 坐标变换与前缀累计 | [202309A 坐标变换（其一）](https://oj.shumeng.tech/p/CSP202309A)；[202309B 坐标变换（其二）](https://oj.shumeng.tech/p/CSP202309B) | 先学前缀和/积，再处理旋转缩放；检查区间端点和浮点输出。 |
| ☐ | 19 | 2023-05 | 第二题：矩阵运算 | [202305B 矩阵运算](https://oj.shumeng.tech/p/CSP202305B) | 利用乘法结合律选择运算顺序，先估计时间和内存，避免生成 n×n 矩阵。 |
| ☐ | 20 | 2023-03 | 第二题：二分巩固 | [202303B 垦田计划](https://oj.shumeng.tech/p/CSP202303B) | 独立写 check 并解释单调性，重点复查左右边界和 64 位累计。 |
| ☐ | 21 | 复盘 | 第三周复盘 | 复盘与重做 | 对做过的同场 A/B 做限时重写；目标 100～120 分钟，重做分数与首次分数分开记录。 |
| ☐ | 22 | 2021-04 | 第二题：二维前缀和 | [202104B 邻域均值](https://oj.shumeng.tech/p/CSP202104B) | 推导四项公式，测试角落、边缘和邻域越界裁剪。 |
| ☐ | 23 | 2020-06 → 2019-12 | 稀疏存储与坐标集合 | [202006B 稀疏向量](https://oj.shumeng.tech/p/CSP202006B)；[201912B 回收站选址](https://oj.shumeng.tech/p/CSP201912B) | 练双指针、map/set/pair；区分坐标不存在与数值为零。 |
| ☐ | 24 | 2017-12 → 2017-03 | 队列与序列操作 | [201712B 游戏](https://oj.shumeng.tech/p/CSP201712B)；[201703B 学生排队](https://oj.shumeng.tech/p/CSP201703B) | 用 queue 处理循环淘汰，用 vector 处理删除与插入，检查下标偏移。 |
| ☐ | 25 | 2015-12 → 2015-03 | 二维更新、矩阵与排序 | [201512B 消除类游戏](https://oj.shumeng.tech/p/CSP201512B)；[201503A 图像旋转](https://oj.shumeng.tech/p/CSP201503A)；[201503B 数字排序](https://oj.shumeng.tech/p/CSP201503B) | 先标记再消除；画出旋转下标；检查排序的并列规则。时间不够时当天第三道题顺延或跳过。 |
| ☐ | 26 | 2014-09 → 2014-03 | 网格与窗口模拟 | [201409B 画图](https://oj.shumeng.tech/p/CSP201409B)；[201403B 窗口](https://oj.shumeng.tech/p/CSP201403B) | 检查矩形边界和窗口置顶顺序；已掌握同类题时选一题完成即可。 |
| ☐ | 27 | 2014-03 | 第三题选做：命令行解析 | [201403C 命令行选项](https://oj.shumeng.tech/p/CSP201403C) | 练 getline、分词和规则拆分；检查带参数选项、停止解析和重复选项。 |
| ☐ | 28 | 2013-12 | 入门题回顾与总复盘 | [201312A 出现次数最多的数](https://oj.shumeng.tech/p/CSP201312A)；[201312B ISBN 号码](https://oj.shumeng.tech/p/CSP201312B) | 这两题用于查漏，熟练可跳过；优先重做错题并整理 STL、二分、BFS、背包、前缀和简表。 |

## 阶段验收与时间不够时的取舍

- 第 1 周：熟悉评测；尝试最近的 A/B，初步掌握 01 背包与二分；记录首次独立得分，不把看题解后通过算作独立完成。
- 第 2 周：补齐位运算、BFS、完全背包；选做模拟题至少能把状态和规则列清楚。前两题不稳时减少 C 题时间。
- 第 3 周：巩固集合、质因数分解、前缀累计、矩阵复杂度与二分；重做已练的 A/B，目标 100～120 分钟。
- 第 4 周：补二维前缀和与模拟细节，重做错题。至少能独立写出二分、BFS、01/完全背包、二维前缀和，并解释适用条件。

仅 2–3 周：仍从新到旧，优先完成近年的 A/B；跳过选做的 C/D 和已掌握的老题。若有 5–6 周：继续保持倒序练题，增加陌生套题检验，再补 DFS/并查集/最短路基础。

用于最终验收的整套题必须是尚未练过的题，不能再用已经做过的 2026-09 套题。可从逐场考点表中选主线未覆盖的 2025-09 套题；为保持陌生度，模拟前不看该套题的考点或题解。需要验收时，可用这套模拟替换第 27～28 天的老题，这是独立于倒序主线的模拟环节。

若能协调出连续 4 小时，就做完整模拟；每天只能投入 2–3 小时时，可拆成两天，第一天 2 小时、第二天 2 小时。拆分成绩与连续 4 小时成绩分开记录。记录首次得分、耗时和错误原因；以陌生题达到 200 并能争取额外分作为分数验收目标，熟题重做成绩只用于检查掌握程度。

## 考场分配建议

建议预算：前 10 分钟浏览全卷；约 30 分钟完成 T1；约 65 分钟完成 T2；中段约 20 分钟比较 T3/T4/T5 的子任务；其后约 90 分钟实现最有把握的部分；最后 25 分钟做边界检查和提交。具体根据当场题目调整，T2 卡住也要有跳题检查其他子任务的意识。

部分分必须来自正确处理明确子任务，例如小 n、特殊输入、仅一种操作；随意删去规则不能认为会得分。程序要能正确解析完整输入。官方 FAQ 当前说明取最高一次提交、无罚分、每题 32 次提交，考试当天以正式系统公告为准。

## 逐场考点：按题库年月从新到旧

201312 在该站标注为“第 0 次”，单独看作入门题组。— 表示该站当前未收录该题，不表示那场没有这道题。

| 年月 | T1 | T2 | T3 | T4 | T5 |
|---|---|---|---|---|---|
| 2026-09 | [流程规划（其一）](../202609/README.md#problem-a)：按公式计算、查表、格式 | [流程规划（其二）](../202609/README.md#problem-b)：01 背包建模 | [轮转调度](../202609/README.md#problem-c)：队列、轮转调度模拟 | [数字分组](../202609/README.md#problem-d)：二分图、并查集 | [奇](../202609/README.md#problem-e)：树上分治、点分树 |
| 2026-05 | [银行家舍入](https://oj.shumeng.tech/p/CSP202605A)：舍入规则、字符串取数 | [机器人宿管指南](https://oj.shumeng.tech/p/CSP202605B)：二分答案 + 过程模拟 | [死锁优化](https://oj.shumeng.tech/p/CSP202605C)：资源与死锁状态模拟 | [石子游戏](https://oj.shumeng.tech/p/CSP202605D)：隔位异或、贪心、倍增 | [绝世好串](https://oj.shumeng.tech/p/CSP202605E)：树、字典序、贪心、候选根淘汰；完整题解与小规模 DP 对拍 |
| 2026-03 | [平衡数](https://oj.shumeng.tech/p/CSP202603A)：二进制、位统计 | [机器人项目管理](https://oj.shumeng.tech/p/CSP202603B)：分数背包贪心 + 01 背包 | [进程通信](https://oj.shumeng.tech/p/CSP202603C)：内存分配、循环队列、空闲区间合并 | [异或](https://oj.shumeng.tech/p/CSP202603D)：异或、分块／线段树 | [旅游计划 - Easy Ver.](https://oj.shumeng.tech/p/CSP202603E)：树上查询、分治 |
| 2025-12 | [集合](https://oj.shumeng.tech/p/CSP202512A)：集合比较、异或 | [数字变换](https://oj.shumeng.tech/p/CSP202512B)：位拆分、小状态变换 | [图片解码](https://oj.shumeng.tech/p/CSP202512C)：图片解码、模拟 | [C 形阵](https://oj.shumeng.tech/p/CSP202512D)：筛法、容斥、积性函数 | [数据抢修](https://oj.shumeng.tech/p/CSP202512E)：状态压缩、网络流等 |
| 2025-09 | [蒙特卡洛](https://oj.shumeng.tech/p/CSP202509A)：按定义计算、统计 | [水印检查](https://oj.shumeng.tech/p/CSP202509B)：水印规则检查、模拟 | [HTTP 头信息](https://oj.shumeng.tech/p/CSP202509C)：HTTP 文本解析 | [造题计划（上）](https://oj.shumeng.tech/p/CSP202509D)：树链剖分、LCA、二分 | [造题计划（下）](https://oj.shumeng.tech/p/CSP202509E)：反悔贪心、费用流等 |
| 2025-06 | [正态分布](https://oj.shumeng.tech/p/CSP202506A)：按题给公式做浮点计算 | [机器人复健指南](https://oj.shumeng.tech/p/CSP202506B)：网格 BFS、去重可达状态 | [消息解码](https://oj.shumeng.tech/p/CSP202506C)：消息格式解析、解码 | [月票发行](https://oj.shumeng.tech/p/CSP202506D)：容斥、DP、矩阵快速幂 | [博物馆](https://oj.shumeng.tech/p/CSP202506E)：虚树、圆方树、DP |
| 2025-03 | [数值积分](https://oj.shumeng.tech/p/CSP202503A)：按题给公式做数值计算 | [机器人饲养指南](https://oj.shumeng.tech/p/CSP202503B)：完全背包 DP | [模板展开](https://oj.shumeng.tech/p/CSP202503C)：字符串展开、依赖与记忆化 | [集体锻炼](https://oj.shumeng.tech/p/CSP202503D)：最大公约数、数论 | [收费标准评估](https://oj.shumeng.tech/p/CSP202503E)：动态 DP、动态树 |
| 2024-12 | [移动](https://oj.shumeng.tech/p/CSP202412A)：坐标移动、模拟 | [梦境巡查](https://oj.shumeng.tech/p/CSP202412B)：轨迹前缀和、统计 | [缓存模拟](https://oj.shumeng.tech/p/CSP202412C)：缓存替换、状态模拟 | [跳房子](https://oj.shumeng.tech/p/CSP202412D)：最短路、优化建图 | [梦魔](https://oj.shumeng.tech/p/CSP202412E)：单调栈、笛卡尔树、树形 DP |
| 2024-09 | [密码](https://oj.shumeng.tech/p/CSP202409A)：字符分类、条件判断 | [字符串变换](https://oj.shumeng.tech/p/CSP202409B)：字符置换、循环节／倍增 | [补丁应用](https://oj.shumeng.tech/p/CSP202409C)：补丁文本解析、状态机 | [通讯延迟](https://oj.shumeng.tech/p/CSP202409D)：图上最短路 | [木板切割](https://oj.shumeng.tech/p/CSP202409E)：平衡树、启发式合并 |
| 2024-06 | [矩阵重塑（其一）](https://oj.shumeng.tech/p/CSP202406A)：矩阵展平、重塑 | [矩阵重塑（其二）](https://oj.shumeng.tech/p/CSP202406B)：矩阵操作、下标映射 | [文本分词](https://oj.shumeng.tech/p/CSP202406C)：文本分词、合并规则模拟 | [货物调度](https://oj.shumeng.tech/p/CSP202406D)：背包 DP | [哥德尔机](https://oj.shumeng.tech/p/CSP202406E)：分块、离线、高级数据结构 |
| 2024-03 | [词频统计](https://oj.shumeng.tech/p/CSP202403A)：词频、按文档去重 | [相似度计算](https://oj.shumeng.tech/p/CSP202403B)：字符串规范化、集合交并 | [化学方程式配平](https://oj.shumeng.tech/p/CSP202403C)：建矩阵、高斯消元 | [十滴水](https://oj.shumeng.tech/p/CSP202403D)：链表／有序集合、连锁模拟 | [文件夹合并](https://oj.shumeng.tech/p/CSP202403E)：树结构、差分、树状数组 |
| 2023-12 | [仓库规划](https://oj.shumeng.tech/p/CSP202312A)：多维比较、枚举 | [因子化简](https://oj.shumeng.tech/p/CSP202312B)：试除法、质因数分解 | [树上搜索](https://oj.shumeng.tech/p/CSP202312C)：树遍历、子树权重模拟 | [宝藏](https://oj.shumeng.tech/p/CSP202312D)：矩阵、区间数据结构 | [彩色路径](https://oj.shumeng.tech/p/CSP202312E)：状态压缩 DP、折半搜索 |
| 2023-09 | [坐标变换（其一）](https://oj.shumeng.tech/p/CSP202309A)：位移累加 | [坐标变换（其二）](https://oj.shumeng.tech/p/CSP202309B)：旋转缩放、前缀积／和 | [梯度求解](https://oj.shumeng.tech/p/CSP202309C)：表达式栈、求导 | [阴阳龙](https://oj.shumeng.tech/p/CSP202309D)：坐标变换、有序数据结构 | [阻击](../202309/README.md#problem-e)：动态树形 DP、树链剖分 |
| 2023-05 | [重复局面](https://oj.shumeng.tech/p/CSP202305A)：局面编码、去重计数 | [矩阵运算](https://oj.shumeng.tech/p/CSP202305B)：矩阵乘法结合律、复杂度 | [解压缩](https://oj.shumeng.tech/p/CSP202305C)：字节／位运算、解码模拟 | [电力网络](https://oj.shumeng.tech/p/CSP202305D)：DP、图结构 | [闪耀巡航](https://oj.shumeng.tech/p/CSP202305E)：子集 DP、最短路 |
| 2023-03 | [田地丈量](https://oj.shumeng.tech/p/CSP202303A)：矩形相交面积 | [垦田计划](https://oj.shumeng.tech/p/CSP202303B)：二分答案／贪心 | [LDAP](https://oj.shumeng.tech/p/CSP202303C)：逻辑表达式、递归解析 | [星际网络 II](https://oj.shumeng.tech/p/CSP202303D)：区间数据结构、离散化 | [施肥](https://oj.shumeng.tech/p/CSP202303E)：分治、扫描线、线段树 |
| 2022-06 | [归一化处理](https://oj.shumeng.tech/p/CSP202206A)：均值、方差、浮点数 | [寻宝！大冒险！](https://oj.shumeng.tech/p/CSP202206B)：稀疏坐标、枚举匹配 | [角色授权](https://oj.shumeng.tech/p/CSP202206C)：权限规则、集合查询 | [光线追踪](https://oj.shumeng.tech/p/CSP202206D)：有序容器、模拟 | [PS 无限版](https://oj.shumeng.tech/p/CSP202206E)：矩阵变换、线段树 |
| 2021-12 | [序列查询](https://oj.shumeng.tech/p/CSP202112A)：分段函数查询 | [序列查询新解](https://oj.shumeng.tech/p/CSP202112B)：分段区间、跳段统计 | [登机牌条码](https://oj.shumeng.tech/p/CSP202112C)：编码模拟、多项式运算 | [磁盘文件操作](https://oj.shumeng.tech/p/CSP202112D)：区间数据结构 | [极差路径](https://oj.shumeng.tech/p/CSP202112E)：扫描线、分治、数据结构 |
| 2021-09 | — | — | — | [收集卡牌](https://oj.shumeng.tech/p/CSP202109D)：状态压缩／记忆化搜索、期望 | — |
| 2021-04 | [灰度直方图](https://oj.shumeng.tech/p/CSP202104A)：灰度值计数 | [邻域均值](https://oj.shumeng.tech/p/CSP202104B)：二维前缀和、边界裁剪 | [DHCP 服务器](https://oj.shumeng.tech/p/CSP202104C)：协议规则、状态模拟 | [校门外的树](https://oj.shumeng.tech/p/CSP202104D)：DP、约数 | [疫苗运输](https://oj.shumeng.tech/p/CSP202104E)：最短路、数论、剪枝 |
| 2020-06 | [线性分类器](https://oj.shumeng.tech/p/CSP202006A)：代入直线、符号判断 | [稀疏向量](https://oj.shumeng.tech/p/CSP202006B)：稀疏存储、双指针／映射 | [Markdown 渲染器](https://oj.shumeng.tech/p/CSP202006C)：Markdown 排版模拟 | [1246](https://oj.shumeng.tech/p/CSP202006D)：递推、DP、矩阵快速幂 | [乔乔和牛牛逛超市](https://oj.shumeng.tech/p/CSP202006E)：最大权闭合子图、搜索 |
| 2019-12 | [报数](https://oj.shumeng.tech/p/CSP201912A)：按规则报数、数位判断 | [回收站选址](https://oj.shumeng.tech/p/CSP201912B)：坐标集合、邻居查询 | [化学方程式](https://oj.shumeng.tech/p/CSP201912C)：括号表达式、递归解析 | [区块链](https://oj.shumeng.tech/p/CSP201912D)：事件模拟、区块链结构 | [魔数](https://oj.shumeng.tech/p/CSP201912E)：线段树、数论 |
| 2018-09 | [卖菜](https://oj.shumeng.tech/p/CSP201809A)：相邻元素平均 | [买菜](https://oj.shumeng.tech/p/CSP201809B)：时间区间交集 | [元素选择器](https://oj.shumeng.tech/p/CSP201809C)：文本解析、树上匹配 | [再卖菜](https://oj.shumeng.tech/p/CSP201809D)：前缀和、差分约束 | [线性递推式](https://oj.shumeng.tech/p/CSP201809E)：线性递推、多项式、NTT |
| 2017-12 | — | [游戏](https://oj.shumeng.tech/p/CSP201712B)：循环淘汰、队列 | — | — | — |
| 2017-03 | [分蛋糕](https://oj.shumeng.tech/p/CSP201703A)：累加、分组 | [学生排队](https://oj.shumeng.tech/p/CSP201703B)：序列删除与插入 | [Markdown](https://oj.shumeng.tech/p/CSP201703C)：Markdown 文本解析 | [地铁修建](https://oj.shumeng.tech/p/CSP201703D)：最小生成树／二分+BFS | [引水入城](https://oj.shumeng.tech/p/CSP201703E)：网络流、对偶图最短路 |
| 2016-04 | [折点计数](https://oj.shumeng.tech/p/CSP201604A)：相邻元素、转折判断 | [俄罗斯方块](https://oj.shumeng.tech/p/CSP201604B)：碰撞检测、落块模拟 | [路径解析](https://oj.shumeng.tech/p/CSP201604C)：路径字符串、栈式处理 | [游戏](https://oj.shumeng.tech/p/CSP201604D)：带时间状态的 BFS | [网络连接](https://oj.shumeng.tech/p/CSP201604E)：连通性／状态压缩 DP |
| 2015-12 | [数位之和](https://oj.shumeng.tech/p/CSP201512A)：十进制拆位 | [消除类游戏](https://oj.shumeng.tech/p/CSP201512B)：二维标记、同时消除 | [画图](https://oj.shumeng.tech/p/CSP201512C)：网格绘图、搜索填充 | [送货](https://oj.shumeng.tech/p/CSP201512D)：欧拉路径 | [矩阵](https://oj.shumeng.tech/p/CSP201512E)：矩阵运算、快速幂 |
| 2015-09 | [数列分段](https://oj.shumeng.tech/p/CSP201509A)：连续段统计 | [日期计算](https://oj.shumeng.tech/p/CSP201509B)：日期、闰年模拟 | [模板生成系统](https://oj.shumeng.tech/p/CSP201509C)：字符串替换、映射 | [高速公路](https://oj.shumeng.tech/p/CSP201509D)：有向图强连通分量 | [最佳文章](https://oj.shumeng.tech/p/CSP201509E)：AC 自动机、DP、快速幂 |
| 2015-03 | [图像旋转](https://oj.shumeng.tech/p/CSP201503A)：矩阵下标变换 | [数字排序](https://oj.shumeng.tech/p/CSP201503B)：频次统计、自定义排序 | [节日](https://oj.shumeng.tech/p/CSP201503C)：日期、闰年、星期模拟 | [网络延时](https://oj.shumeng.tech/p/CSP201503D)：树的直径、DFS／BFS | [最小花费](https://oj.shumeng.tech/p/CSP201503E)：树上倍增／分治 |
| 2014-12 | [门禁系统](https://oj.shumeng.tech/p/CSP201412A)：计数、映射 | [Z 字形扫描](https://oj.shumeng.tech/p/CSP201412B)：矩阵对角线遍历 | [集合竞价](https://oj.shumeng.tech/p/CSP201412C)：枚举价格、排序统计 | [最优灌溉](https://oj.shumeng.tech/p/CSP201412D)：最小生成树、并查集 | [货物调度](https://oj.shumeng.tech/p/CSP201412E)：费用流 |
| 2014-09 | [相邻数对](https://oj.shumeng.tech/p/CSP201409A)：排序、相邻关系 | [画图](https://oj.shumeng.tech/p/CSP201409B)：网格覆盖标记 | [字符串匹配](https://oj.shumeng.tech/p/CSP201409C)：大小写处理、子串匹配 | [最优配餐](https://oj.shumeng.tech/p/CSP201409D)：多源 BFS | [拼图](https://oj.shumeng.tech/p/CSP201409E)：状态压缩 DP、快速幂 |
| 2014-03 | [相反数](https://oj.shumeng.tech/p/CSP201403A)：集合查找／枚举 | [窗口](https://oj.shumeng.tech/p/CSP201403B)：窗口层叠、顺序模拟 | [命令行选项](https://oj.shumeng.tech/p/CSP201403C)：命令行规则解析 | [无线网络](https://oj.shumeng.tech/p/CSP201403D)：分层图、BFS／最短路 | [任务调度](https://oj.shumeng.tech/p/CSP201403E)：贪心、DP |
| 2013-12（第 0 次） | [出现次数最多的数](https://oj.shumeng.tech/p/CSP201312A)：频次统计、并列取最小 | [ISBN 号码](https://oj.shumeng.tech/p/CSP201312B)：校验码、字符串 | [最大的矩形](https://oj.shumeng.tech/p/CSP201312C)：区间枚举／单调栈 | [有趣的数](https://oj.shumeng.tech/p/CSP201312D)：状态 DP、组合计数 | [I’m stuck!](https://oj.shumeng.tech/p/CSP201312E)：网格可达性、BFS |


## 暂不列为必做的扩展条目

- [绝世好串 - Bonus Ver.（取消聚拢限制的拓展版本）](https://oj.shumeng.tech/p/CSP202605E3)
- [绝世好串 - 1e6 测试](https://oj.shumeng.tech/p/CSP202605E2)
- [旅游计划 - Hard Ver.](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603E2/)
- [C 形阵 - 加强版](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512D2/)

## 来源

- [曙梦 OJ CSP 第 1 页](https://oj.shumeng.tech/p?page=1&q=category%3ACSP)
- [曙梦 OJ CSP 第 2 页](https://oj.shumeng.tech/p?page=2&q=category%3ACSP)
- [曙梦 OJ CSP 第 3 页](https://oj.shumeng.tech/p?page=3&q=category%3ACSP)
- [曙梦 OJ CSP 第 4 页](https://oj.shumeng.tech/p?page=4&q=category%3ACSP)
- [CCF 第 43 次 CSP 认证报名通知及认证说明](https://www.cspro.org/cms/show.action?channelid=0000000103&code=publish_8ac21fad9d27f22a019f7e5a821c0129&newsid=1cc1a98caa94481a8a6473ca339230a4)
- [CCF CSP 系统使用答疑](https://cspro.org/cms/show.action?code=publish_8ac21fad692439c7016932b9e83e010d&siteid=100000)

每道题的链接指向本次核对的题库条目，可继续查看题面、数据范围与子任务。
