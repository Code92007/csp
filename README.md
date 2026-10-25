# CSP 手记

按场次和算法标签组织的 CCF CSP 学习工程。面向已学 C/C++、数据结构、每天可练习 2–3 小时、目标超过 200 分的同学。文章与代码按比赛年月从新到旧维护。

[在线阅读](https://code92007.github.io/csp/) · [GitHub 仓库](https://github.com/Code92007/csp)

每场一个 `YYYYMM` 文件夹，里面是包含五题的 `README.md` 和 `A.cpp` 至 `E.cpp`。每题依次给出题意、题解、代码。Markdown 顶部记录场次、文章标签、逐题标签、来源与验证状态。

**本轮已按第四题、第三题、第二题、第一题的顺序补齐，同题号从新到旧。** 工程现有 32 场的五题现已全部实现；202605E《绝世好串》根据补充的参考资料完成原题完整规模版本，并保留小规模 DP 作为对拍基准。32 场是工程已有清单，并非历史所有场次。

全工程目前有 160 份完整实现、0 份部分分实现，剩余 0 题待补充。

## 开始阅读

- [按题号阅读（D → C → B → A，同题号从新到旧）](docs/problem-order.md)。
- [第五题目录（32 场，从新到旧）](docs/fifth-problems.md)：算法标签、文章跳转和实际完成状态。
- [202609 五题题解](202609/README.md)：公式与精度、01 背包、调度模拟、最少分组、树上动态计数。
- [202605 五题题解](202605/README.md)：舍入、二分答案、资源调度模拟、异或与倍增，以及树上字典序的候选根算法。
- [每天 2–3 小时的备考计划](docs/study-plan.md)。建议先独立完成 A/B，再用题解复盘。
- [曙梦 OJ 提交与核验记录](docs/oj-submissions.md)：逐题评测链接和当前状态。
- [题面来源与核对进度](docs/sources.md)。曙梦 OJ 已恢复访问，现有 160 题中 152 题可直接打开；另有 8 题为隐藏题，当前账号无权查看。

## 本地博客

需要 Python 3.9 或更新版本。网站的全部前端依赖和字体已保存在工程里，构建与阅读不需要 npm、数据库或 CDN。

```sh
cd ~/Documents/csp
make serve
```

浏览器打开 `http://127.0.0.1:8765`。端口占用时可运行 `make serve PORT=8766`。服务器只绑定本机。

网页提供从新到旧的场次索引、按题索引、可点击的彩色算法标签、题名与场次搜索、年份与完成状态筛选。点击某道题可以直接跳到文章内该题。公式本地渲染，代码可复制，Markdown 与 CPP 均可下载。草稿、完整实现和部分分实现分别标注。

## 编译与验证

使用支持 C++17 的 GCC 或 Clang；部分题目使用 `__int128` 扩展。可以通过环境变量 `CXX` 指定编译器。

```sh
make list
make build SESSION=202609 PROBLEM=A
make run SESSION=202609 PROBLEM=A < input.txt
make check
make random
```

`make check` 核对 160 个代码块与独立 CPP 的一致性，编译并运行保存的样例。`make random` 执行原有两场和第五题的随机/穷举对拍；新增前四题分别用 `make random-fourth`、`make random-third`、`make random-second`、`make random-first` 复现。测试脚本与结果报告在 `tests/`。

本轮新增 120 题通过 11,140 组独立随机/穷举校验，分题号记录与复现方法见 [前四题验证报告](docs/validation-ad.md)。各题的编译、保存样例与对拍记录也写在文章中。第五题原有 2200 组独立随机对拍，记录见 [fifth-report.json](tests/fifth-report.json)；原有两场的 1026 组校验记录另行保留。

部分复杂实现还做了最大规模构造的运行检查，旧版结果保留在 [fifth-stress-report.json](tests/fifth-stress-report.json)。2026-10-25 优化了 201809E 和 202406E，均已在曙梦 OJ 取得 100 分 Accepted；代码、独立对拍和新旧性能比较见对应文章及 [优化验证报告](tests/optimization-report.json)。运行 `python3 tests/optimized_regressions.py` 可复现两题共 1100 组独立对拍，追加 `--stress` 可检查 11 组最大规模构造。性能依赖机器与数据，民间 OJ 通过也不能视为 CCF 官方成绩保证。

202309B 另修复了低精度 `long double` 平台上大角度前缀相减的误差，新版已在曙梦 OJ 取得 100 分；上一版的洛谷 AC 作为历史版本单独保留。运行 `python3 tests/precision_regressions.py` 可复现 500 组逐次操作对拍与 70 位精度边界检查，详见 [精度报告](tests/precision-report.json) 和 [历史非满分记录审计](docs/remaining-failures-audit.md)。

202605E 另有 2,042 组与小规模 DP 的对拍及 7 组十万点运行检查，分别用 `make random-gather`、`make stress-gather` 复现，见 [gather-report.json](tests/gather-report.json) 与 [gather-stress-report.json](tests/gather-stress-report.json)。逐题在线评测状态以 [提交与核验记录](docs/oj-submissions.md) 为准。

## 维护与发布

**Markdown 是内容源。** 编辑文章中的代码后，用下面的命令生成独立源码和静态网页：

```sh
make sync
make check
make index
make site
```

`make sync` 会用文章代码块覆盖对应 CPP；先在 CPP 调试时，应先把最终版本回填到文章。网页读取的 `site/content.json` 是自动生成的索引，不需要手工编辑。

后续向远端更新时，主要维护 Markdown 即可；网页模板和生成工具只需随工程保留。`site/`、编译产物与缓存已加入 `.gitignore`。不依赖在线数据库或博客账号。

- [内容格式与标签约定](docs/content-guide.md)
- [静态部署说明](docs/deployment.md)：包含 GitHub Pages 地址与后续更新命令。
- [前端依赖与许可证](web/vendor/README.md)

题目版权归原出题方；题意为重新概述，代码为本工程重新编写。202605E 的完整算法注明 zlxFTH 的题解来源，Bonus 拓展讨论注明 CYMario 的报告来源。公开复刻规则、样例与自建数据可能与原题存在差异，需持续核对来源。

## 场次目录与实际进度

<!-- contest-index:start -->

| 年月 | 题解文章 | 完整实现 | 部分分实现 | 待编写 |
|---|---|---:|---:|---:|
| 202609 | [CSP 202609 五题题解](202609/README.md) | 5 | 0 | 0 |
| 202605 | [CSP 202605 五题题解](202605/README.md) | 5 | 0 | 0 |
| 202603 | [CSP 202603 五题题解](202603/README.md) | 5 | 0 | 0 |
| 202512 | [CSP 202512 五题题解](202512/README.md) | 5 | 0 | 0 |
| 202509 | [CSP 202509 五题题解](202509/README.md) | 5 | 0 | 0 |
| 202506 | [CSP 202506 五题题解](202506/README.md) | 5 | 0 | 0 |
| 202503 | [CSP 202503 五题题解](202503/README.md) | 5 | 0 | 0 |
| 202412 | [CSP 202412 五题题解](202412/README.md) | 5 | 0 | 0 |
| 202409 | [CSP 202409 五题题解](202409/README.md) | 5 | 0 | 0 |
| 202406 | [CSP 202406 五题题解](202406/README.md) | 5 | 0 | 0 |
| 202403 | [CSP 202403 五题题解](202403/README.md) | 5 | 0 | 0 |
| 202312 | [CSP 202312 五题题解](202312/README.md) | 5 | 0 | 0 |
| 202309 | [CSP 202309 五题题解](202309/README.md) | 5 | 0 | 0 |
| 202305 | [CSP 202305 五题题解](202305/README.md) | 5 | 0 | 0 |
| 202303 | [CSP 202303 五题题解](202303/README.md) | 5 | 0 | 0 |
| 202206 | [CSP 202206 五题题解](202206/README.md) | 5 | 0 | 0 |
| 202112 | [CSP 202112 五题题解](202112/README.md) | 5 | 0 | 0 |
| 202109 | [CSP 202109 五题题解](202109/README.md) | 5 | 0 | 0 |
| 202104 | [CSP 202104 五题题解](202104/README.md) | 5 | 0 | 0 |
| 202006 | [CSP 202006 五题题解](202006/README.md) | 5 | 0 | 0 |
| 201912 | [CSP 201912 五题题解](201912/README.md) | 5 | 0 | 0 |
| 201809 | [CSP 201809 五题题解](201809/README.md) | 5 | 0 | 0 |
| 201712 | [CSP 201712 五题题解](201712/README.md) | 5 | 0 | 0 |
| 201703 | [CSP 201703 五题题解](201703/README.md) | 5 | 0 | 0 |
| 201604 | [CSP 201604 五题题解](201604/README.md) | 5 | 0 | 0 |
| 201512 | [CSP 201512 五题题解](201512/README.md) | 5 | 0 | 0 |
| 201509 | [CSP 201509 五题题解](201509/README.md) | 5 | 0 | 0 |
| 201503 | [CSP 201503 五题题解](201503/README.md) | 5 | 0 | 0 |
| 201412 | [CSP 201412 五题题解](201412/README.md) | 5 | 0 | 0 |
| 201409 | [CSP 201409 五题题解](201409/README.md) | 5 | 0 | 0 |
| 201403 | [CSP 201403 五题题解](201403/README.md) | 5 | 0 | 0 |
| 201312 | [CSP 201312 五题题解](201312/README.md) | 5 | 0 | 0 |

<!-- contest-index:end -->
