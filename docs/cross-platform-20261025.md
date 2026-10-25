# 2026-10-25 两平台交叉补验

包括两平台交叉补验与超时题优化复验。每个平台上一题终评确认后，再等待至少 120 秒才提交下一题；早期记录另保留实际提交间隔。源码 SHA256 与当前版本一致时才回填当前评测状态。

## 曙梦 OJ

| 时间（北京时间） | 题目 | 分数 | 结果 | 记录 |
|---|---|---:|---|---|
| 17:20:44 | CSP202312D 宝藏 | 85 | Time Exceeded | [记录](https://oj.shumeng.tech/record/6addc9ec74ace1cba9a21d5a) |
| 17:23:19 | CSP202309D 阴阳龙 | 15 | Time Exceeded | [记录](https://oj.shumeng.tech/record/6addca8774ace1cba9a21e22) |
| 17:25:25 | CSP202303C LDAP | 70 | Time Exceeded | [记录](https://oj.shumeng.tech/record/6addcb0574ace1cba9a21e46) |
| 17:27:47 | CSP202206E PS 无限版 | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addcb9374ace1cba9a21e80) |
| 17:32:28 | CSP202112E 极差路径 | 56 | Time Exceeded | [记录](https://oj.shumeng.tech/record/6addccac74ace1cba9a21f0f) |
| 17:34:49 | CSP201403A 相反数 | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addcd3974ace1cba9a21f70) |
| 20:31:17 | CSP201403C 命令行选项 | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addf69574ace1cba9a22df8) |
| 20:44:33 | CSP201403D 无线网络 | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addf9b174ace1cba9a22fa2) |
| 20:52:31 | CSP201312C 最大的矩形 | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addfb8f74ace1cba9a23115) |
| 17:30:00 | CSP202312D 宝藏 | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2) |
| 21:00:03 | CSP202309D 阴阳龙 | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b) |
| 21:02:34 | CSP202303C LDAP | 100 | Accepted | [记录](https://oj.shumeng.tech/record/6addfdea74ace1cba9a232ef) |
| 21:06:43 | CSP202112E 极差路径 | 84 | Time Exceeded | [记录](https://oj.shumeng.tech/record/6addfee374ace1cba9a233c6) |

隐藏题复查：CSP202109A、CSP202109B、CSP202109C、CSP202109E。当前账号无权查看，未尝试绕过权限。

## 洛谷

| 时间（北京时间） | 题目 | 洛谷题号 | 分数 | 结果 | 记录 |
|---|---|---|---:|---|---|
| 17:22:15 | CSP202403A 词频统计 | P16031 | 100 | Accepted | [记录](https://www.luogu.com.cn/record/305704089) |
| 17:24:28 | CSP202403B 相似度计算 | P16032 | 100 | Accepted | [记录](https://www.luogu.com.cn/record/305705069) |
| 17:26:43 | CSP202403C 化学方程式配平 | P16033 | 100 | Accepted | [记录](https://www.luogu.com.cn/record/305706100) |
| 17:29:06 | CSP202403D 十滴水 | P16034 | 100 | Accepted | [记录](https://www.luogu.com.cn/record/305707098) |
| 21:04:06 | CSP202403E 文件夹合并 | P16035 | 100 | Accepted | [记录](https://www.luogu.com.cn/record/305803314) |

曙梦本次补验实际最短提交间隔：126 秒。

洛谷本次补验实际最短提交间隔：133 秒。

## 继续处理状态

洛谷尚有 34 道已确认映射的题目在队列，按终评后 120 秒间隔继续处理；后续验证码由用户在可见页面完成。

《极差路径》的隔离优化候选获 84 分 Time Exceeded，仍在优化；工程继续保留原有源码及其独立评测记录，候选成绩不会套用到其他源码。

曙梦可访问题目的交叉补验已完成；隐藏题因当前账号无查看权限而保留待验状态。

[逐条结果与源码 SHA256](../tests/cross-platform-20261025.json)。只有 100 分 Accepted 才算该平台满分；两个平台的民间数据均不等同 CCF 官方成绩。
