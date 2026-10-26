# 《阴阳龙》两平台复验记录

更新时间：2026-10-26。当前题解已替换为宽坐标槽位版，同一份源码在曙梦与洛谷均为 100 分 Accepted；旧快版失败的具体原因尚未定位。下面各项成绩均关联各自的源码，不能相互继承。

| 源码版本（SHA-256 前缀） | 曙梦 OJ | 洛谷 | 状态 |
| --- | --- | --- | --- |
| 旧快版 `746784b9f382` | [100 Accepted](https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b) | [30 分，14/20 点 WA](https://www.luogu.com.cn/record/305837114) | 历史归档保留实际失败记录 |
| 保守候选 `79d35e9c66f3` | [55 分 TLE](https://oj.shumeng.tech/record/6ade248174ace1cba9a24539) | [100 Accepted](https://www.luogu.com.cn/record/305839060) | 正确性及性能比较使用 |
| 当前宽坐标槽位版 `7582da8d38df` | [100 Accepted](https://oj.shumeng.tech/record/6ade253b74ace1cba9a24563)，最大单点 1152 ms / 2000 ms | [100 Accepted](https://www.luogu.com.cn/record/305916165)，最大单点 673 ms / 1000 ms | 已替换正式源码与题解 |

[保守候选源码](../tests/diagnostics/202309D-conservative.cpp) · [宽坐标候选源码](../tests/diagnostics/202309D-wide.cpp) · [完整验证报告](../tests/dragon-wide-candidate-report.json)。

宽坐标版保留最多迁移 4 个槽位的更新算法，坐标与排序键改用 `long long` 二元组，输入使用关闭同步的 `cin`。这些改动同时发生；在没有确定性反例的情况下，不能将其中任意一项认定为旧版 WA 的已证实原因。

宽坐标版实际通过：1 个保存样例、700 组 Python 独立朴素模型随机测试、255 种八方向占用掩码、10000 组逐员工最终坐标对拍、300 组真实标准输入随机测试，以及 6 组 `p=q=100000` 压力构造。没有继承旧版的 ASan/UBSan 结果。完整坐标对拍使用 C++23 内存驱动；实际候选源码另以 C++17 编译运行样例、Python 对拍和压力构造。

用户在 2026-10-26 16:17:45 提交的[记录 305915328](https://www.luogu.com.cn/record/305915328)也是保守版，100 分；页面源码已逐字核对。此成绩保存在保守版历史中。随后在确认终评后等待至少 120 秒，独立提交宽坐标版，16:21:25 的记录 305916165 获 100 分；页面完整源码 4284 字符与当前文件一致。

宽坐标版的完整 SHA-256 为 `7582da8d38df5972c56e08c065b30d2add892ced43ea695e431a262a65f8b815`。当前[正式源码](../202309/D.cpp)、[题解](../202309/README.md#problem-d)与[当前回归报告](../tests/yin_yang_dragon-report.json)已同步。旧快版[回归与失败报告](../tests/yin_yang_dragon-packed-report.json)另存。

两平台每次确认终评后，继续等待至少 120 秒再提交下一题。普通补验队列已恢复，实际进度见[交叉补验记录](cross-platform-20261025.md)。
