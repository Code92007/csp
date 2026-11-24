# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058baee5d1fced2e4573bf)。 | `989231469a2f9c20915cf0e7f61764841be0b7dafdc0686f5fe9d9355742e329` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058c2ee5d1fced2e4574f2)。 | `324cab41522e451b36bd28fb780742a6ea8c1370350a0cf9e513e0d95a007508` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058c79e5d1fced2e457636)。 | `a51f06ea16a7bee371582cba56fecaacb30d80d8f0a0db11175168dafe05eed8` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058cbce5d1fced2e4576cf)。 | `85e29333f344fe8e9f2226f535e0be925c60105a05850d0895508233c8d60c40` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058d0fe5d1fced2e4577bc)。 | `6dc66659465e70fae3977dbe23dee8d0bee27051f2c5d23196ca0bebc5c55d64` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：201912。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 62 | 2 | 59 | 1 |
| B | 104 | 3 | 100 | 1 |
| C | 102 | 1 | 100 | 1 |
| D | 83 | 2 | 80 | 1 |
| E | 61 | 2 | 58 | 1 |

合计 412 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 201912 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

E 按最新 review 将模数 `P` 改为 `mod`；两版重新通过 61 个不同输入，另已核对仅名称变化。[当前 E 源码哈希](e-mod-followup-report.json)。原批次报告保留历史源码哈希。

## B 后续邻居检查排版

`ok(x,y)` 把四个相邻坐标放入局部短列表，引用遍历检查，任一个不存在即返回 false，全部存在返回 true；保持原四条件的合取含义。当前 O2、UBSan（含 `-Wshadow`）编译均无诊断，各通过104个不同输入：100组独立随机、3个保存样例和1个5×5坐标边界。 [本轮结果与当前哈希](b-neighbor-followup-report.json)，复现 `python3 tools/nightly/verify_short_review.py --repo /path/to/repository`。

- `B.cpp` 当前 SHA-256：`324cab41522e451b36bd28fb780742a6ea8c1370350a0cf9e513e0d95a007508`

## D 后续风格复验

链长度不超过新建区块数加一，至多30001，可安全转换为int；输出改为%d。 当前O2、UBSan（含-Wshadow）编译无诊断，各通过2个定向输入；历史完整对拍不重复计数。[本轮结果](d-print-followup-report.json)，复现 `python3 tools/nightly/verify_four_style.py --repo /path/to/repository`。

- `D.cpp` 当前 SHA-256：`85e29333f344fe8e9f2226f535e0be925c60105a05850d0895508233c8d60c40`

## E 后续风格复验

五个ull常量放在一行，所有数字与ull后缀保持精确。 当前O2、UBSan（含-Wshadow）编译无诊断，各通过2个定向输入；历史完整对拍不重复计数。[本轮结果](e-constants-followup-report.json)，复现 `python3 tools/nightly/verify_four_style.py --repo /path/to/repository`。

- `E.cpp` 当前 SHA-256：`6dc66659465e70fae3977dbe23dee8d0bee27051f2c5d23196ca0bebc5c55d64`
