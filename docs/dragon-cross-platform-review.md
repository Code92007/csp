# 《阴阳龙》两平台复验记录

更新时间：2026-10-26。当前题解使用的快版在曙梦 100 分、洛谷 30 分；旧版失败的具体原因尚未定位。下面各项成绩均关联各自的源码，不能相互继承。

| 源码版本（SHA-256 前缀） | 曙梦 OJ | 洛谷 | 状态 |
| --- | --- | --- | --- |
| 当前快版 `746784b9f382` | [100 Accepted](https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b) | [30 分，14/20 点 WA](https://www.luogu.com.cn/record/305837114) | 当前文章保留实际失败记录 |
| 保守候选 `79d35e9c66f3` | [55 分 TLE](https://oj.shumeng.tech/record/6ade248174ace1cba9a24539) | [100 Accepted](https://www.luogu.com.cn/record/305839060) | 正确性及性能比较使用 |
| 宽坐标槽位候选 `7582da8d38df` | [100 Accepted](https://oj.shumeng.tech/record/6ade253b74ace1cba9a24563)，最大单点 1152 ms / 2000 ms | 等待用户完成验证码提交，尚无本版记录 | 待洛谷实际终评后决定替换 |

[保守候选源码](../tests/diagnostics/202309D-conservative.cpp) · [宽坐标候选源码](../tests/diagnostics/202309D-wide.cpp) · [完整验证报告](../tests/dragon-wide-candidate-report.json)。

宽坐标版保留最多迁移 4 个槽位的更新算法，坐标与排序键改用 `long long` 二元组，输入使用关闭同步的 `cin`。这些改动同时发生；在没有确定性反例的情况下，不能将其中任意一项认定为旧版 WA 的已证实原因。

宽坐标版实际通过：1 个保存样例、700 组 Python 独立朴素模型随机测试、255 种八方向占用掩码、10000 组逐员工最终坐标对拍、300 组真实标准输入随机测试，以及 6 组 `p=q=100000` 压力构造。没有继承旧版的 ASan/UBSan 结果。完整坐标对拍使用 C++23 内存驱动；实际候选源码另以 C++17 编译运行样例、Python 对拍和压力构造。

两平台每次确认终评后，继续等待至少 120 秒再提交下一题。当前洛谷验证码提交页保留；普通补验队列仍有 22 题，暂停至此次人工验证完成。
