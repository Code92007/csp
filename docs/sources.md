# 题面来源与核对进度

截至 2026-10-23，原数梦 OJ 请求返回 502。官方练习系统可访问，但题目接口要求登录。工程没有使用账号登录，也没有取得官方隐藏测试数据。

2026-10-24 补充前四题时，逐题读取可用题面并核对样例，使用以下替代入口：

- [公开题目存档](https://pcs2.roj.ac.cn/)及其公开 Markdown 源文件：用于多数场次的规则、约束与样例。最初目录发现了 128/160 题；正文来源以各篇逐题链接为准。
- [洛谷题库](https://www.luogu.com.cn/)：补齐 202309、202305、202303、202112、202109 的五题题面与样例。
- 201712 的四题分别通过公开转录核对：[最小差值](https://www.cnblogs.com/wydxry/p/10730131.html)、[游戏](https://blog.51cto.com/u_15346485/3677111)、[Crontab](https://www.cnblogs.com/imane/p/15095778.html)、[行车路线](https://www.dreamwings.cn/ccf201712-4/5213.html)。第五题《商路》也通过公开转录核对，并用独立树形 DP 对拍。
- [CSP Lab 独立题面与数据项目](https://github.com/Dejoy1202/csp-lab)：用于 202609、202605 及部分场次的规则与样例交叉核对。该项目自称题面、样例和数据独立编写，不能当作官方原始题面或正式评测。

202605E 后续根据用户补充的 [zlxFTH 非官方题解](https://www.zhihu.com/question/2043989350854156307/answer/2044499207764105133) 完成原题完整规模实现，并添加 [CYMario 的 Bonus 探索报告](https://zhuanlan.zhihu.com/p/2083646963501815540) 的版本区别说明。原题与取消限制的 Bonus 不能混用结论。现在 160 题均有完整实现，文章列出本地验证范围，未宣称正式评测 AC。

每题的实际来源链接写在 frontmatter 和正文中。题意为重新概述，代码与讲解为本工程独立编写，未复制缺少明确许可的参考仓库代码。原始题面和复刻规则可能存在差异，正式评测仍是最终依据。

更正前期清单中的两处题名：202309E 是《阻击》，201712E 是《商路》。

以下保留原存档的目录发现记录，按新到旧排列；“尚未在该存档找到”只指该入口，不代表本工程仍缺题面。实际采用的补充来源见每题正文。

| 场次 | 题号 | 标题 | 公开存档目录发现 |
|---|---|---|---|
| 202609 | A | 流程规划（其一） | 尚未在该存档找到 |
| 202609 | B | 流程规划（其二） | 尚未在该存档找到 |
| 202609 | C | 轮转调度 | 尚未在该存档找到 |
| 202609 | D | 数字分组 | 尚未在该存档找到 |
| 202609 | E | 奇 | 尚未在该存档找到 |
| 202605 | A | 银行家舍入 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605A/) |
| 202605 | B | 机器人宿管指南 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605B/) |
| 202605 | C | 死锁优化 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605C/) |
| 202605 | D | 石子游戏 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605D/) |
| 202605 | E | 绝世好串 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605E/) |
| 202603 | A | 平衡数 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603A/) |
| 202603 | B | 机器人项目管理 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603B/) |
| 202603 | C | 进程通信 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603C/) |
| 202603 | D | 异或 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603D/) |
| 202603 | E | 旅游计划 - Easy Ver. | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603E/) |
| 202512 | A | 集合 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512A/) |
| 202512 | B | 数字变换 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512B/) |
| 202512 | C | 图片解码 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512C/) |
| 202512 | D | C 形阵 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512D/) |
| 202512 | E | 数据抢修 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512E/) |
| 202509 | A | 蒙特卡洛 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509A/) |
| 202509 | B | 水印检查 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509B/) |
| 202509 | C | HTTP 头信息 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509C/) |
| 202509 | D | 造题计划（上） | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509D/) |
| 202509 | E | 造题计划（下） | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509E/) |
| 202506 | A | 正态分布 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506A/) |
| 202506 | B | 机器人复健指南 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506B/) |
| 202506 | C | 消息解码 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506C/) |
| 202506 | D | 月票发行 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506D/) |
| 202506 | E | 博物馆 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506E/) |
| 202503 | A | 数值积分 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503A/) |
| 202503 | B | 机器人饲养指南 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503B/) |
| 202503 | C | 模板展开 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503C/) |
| 202503 | D | 集体锻炼 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503D/) |
| 202503 | E | 收费标准评估 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503E/) |
| 202412 | A | 移动 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412A/) |
| 202412 | B | 梦境巡查 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412B/) |
| 202412 | C | 缓存模拟 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412C/) |
| 202412 | D | 跳房子 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412D/) |
| 202412 | E | 梦魔 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412E/) |
| 202409 | A | 密码 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409A/) |
| 202409 | B | 字符串变换 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409B/) |
| 202409 | C | 补丁应用 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409C/) |
| 202409 | D | 通讯延迟 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409D/) |
| 202409 | E | 木板切割 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409E/) |
| 202406 | A | 矩阵重塑（其一） | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406A/) |
| 202406 | B | 矩阵重塑（其二） | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406B/) |
| 202406 | C | 文本分词 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406C/) |
| 202406 | D | 货物调度 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406D/) |
| 202406 | E | 哥德尔机 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406E/) |
| 202403 | A | 词频统计 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403A/) |
| 202403 | B | 相似度计算 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403B/) |
| 202403 | C | 化学方程式配平 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403C/) |
| 202403 | D | 十滴水 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403D/) |
| 202403 | E | 文件夹合并 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403E/) |
| 202312 | A | 仓库规划 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312A/) |
| 202312 | B | 因子化简 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312B/) |
| 202312 | C | 树上搜索 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312C/) |
| 202312 | D | 宝藏 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312D/) |
| 202312 | E | 彩色路径 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312E/) |
| 202309 | A | 坐标变换（其一） | 尚未在该存档找到 |
| 202309 | B | 坐标变换（其二） | 尚未在该存档找到 |
| 202309 | C | 梯度求解 | 尚未在该存档找到 |
| 202309 | D | 阴阳龙 | 尚未在该存档找到 |
| 202309 | E | 阻击 | 尚未在该存档找到 |
| 202305 | A | 重复局面 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202305A/) |
| 202305 | B | 矩阵运算 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202305B/) |
| 202305 | C | 解压缩 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202305C/) |
| 202305 | D | 电力网络 | 尚未在该存档找到 |
| 202305 | E | 闪耀巡航 | 尚未在该存档找到 |
| 202303 | A | 田地丈量 | 尚未在该存档找到 |
| 202303 | B | 垦田计划 | 尚未在该存档找到 |
| 202303 | C | LDAP | 尚未在该存档找到 |
| 202303 | D | 星际网络 II | 尚未在该存档找到 |
| 202303 | E | 施肥 | 尚未在该存档找到 |
| 202206 | A | 归一化处理 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206A/) |
| 202206 | B | 寻宝！大冒险！ | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206B/) |
| 202206 | C | 角色授权 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206C/) |
| 202206 | D | 光线追踪 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206D/) |
| 202206 | E | PS 无限版 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206E/) |
| 202112 | A | 序列查询 | 尚未在该存档找到 |
| 202112 | B | 序列查询新解 | 尚未在该存档找到 |
| 202112 | C | 登机牌条码 | 尚未在该存档找到 |
| 202112 | D | 磁盘文件操作 | 尚未在该存档找到 |
| 202112 | E | 极差路径 | 尚未在该存档找到 |
| 202109 | A | 数组推导 | 尚未在该存档找到 |
| 202109 | B | 非零段划分 | 尚未在该存档找到 |
| 202109 | C | 脉冲神经网络 | 尚未在该存档找到 |
| 202109 | D | 收集卡牌 | 尚未在该存档找到 |
| 202109 | E | 箱根山岳险天下 | 尚未在该存档找到 |
| 202104 | A | 灰度直方图 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104A/) |
| 202104 | B | 邻域均值 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104B/) |
| 202104 | C | DHCP 服务器 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104C/) |
| 202104 | D | 校门外的树 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104D/) |
| 202104 | E | 疫苗运输 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104E/) |
| 202006 | A | 线性分类器 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006A/) |
| 202006 | B | 稀疏向量 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006B/) |
| 202006 | C | Markdown 渲染器 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006C/) |
| 202006 | D | 1246 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006D/) |
| 202006 | E | 乔乔和牛牛逛超市 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006E/) |
| 201912 | A | 报数 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912A/) |
| 201912 | B | 回收站选址 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912B/) |
| 201912 | C | 化学方程式 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912C/) |
| 201912 | D | 区块链 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912D/) |
| 201912 | E | 魔数 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912E/) |
| 201809 | A | 卖菜 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809A/) |
| 201809 | B | 买菜 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809B/) |
| 201809 | C | 元素选择器 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809C/) |
| 201809 | D | 再卖菜 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809D/) |
| 201809 | E | 线性递推式 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809E/) |
| 201712 | A | 最小差值 | 尚未在该存档找到 |
| 201712 | B | 游戏 | 尚未在该存档找到 |
| 201712 | C | Crontab | 尚未在该存档找到 |
| 201712 | D | 行车路线 | 尚未在该存档找到 |
| 201712 | E | 商路 | 尚未在该存档找到 |
| 201703 | A | 分蛋糕 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703A/) |
| 201703 | B | 学生排队 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703B/) |
| 201703 | C | Markdown | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703C/) |
| 201703 | D | 地铁修建 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703D/) |
| 201703 | E | 引水入城 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703E/) |
| 201604 | A | 折点计数 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604A/) |
| 201604 | B | 俄罗斯方块 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604B/) |
| 201604 | C | 路径解析 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604C/) |
| 201604 | D | 游戏 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604D/) |
| 201604 | E | 网络连接 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604E/) |
| 201512 | A | 数位之和 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512A/) |
| 201512 | B | 消除类游戏 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512B/) |
| 201512 | C | 画图 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512C/) |
| 201512 | D | 送货 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512D/) |
| 201512 | E | 矩阵 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512E/) |
| 201509 | A | 数列分段 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509A/) |
| 201509 | B | 日期计算 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509B/) |
| 201509 | C | 模板生成系统 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509C/) |
| 201509 | D | 高速公路 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509D/) |
| 201509 | E | 最佳文章 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509E/) |
| 201503 | A | 图像旋转 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503A/) |
| 201503 | B | 数字排序 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503B/) |
| 201503 | C | 节日 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503C/) |
| 201503 | D | 网络延时 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503D/) |
| 201503 | E | 最小花费 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503E/) |
| 201412 | A | 门禁系统 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412A/) |
| 201412 | B | Z 字形扫描 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412B/) |
| 201412 | C | 集合竞价 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412C/) |
| 201412 | D | 最优灌溉 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412D/) |
| 201412 | E | 货物调度 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412E/) |
| 201409 | A | 相邻数对 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409A/) |
| 201409 | B | 画图 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409B/) |
| 201409 | C | 字符串匹配 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409C/) |
| 201409 | D | 最优配餐 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409D/) |
| 201409 | E | 拼图 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409E/) |
| 201403 | A | 相反数 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403A/) |
| 201403 | B | 窗口 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403B/) |
| 201403 | C | 命令行选项 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403C/) |
| 201403 | D | 无线网络 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403D/) |
| 201403 | E | 任务调度 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403E/) |
| 201312 | A | 出现次数最多的数 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312A/) |
| 201312 | B | ISBN 号码 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312B/) |
| 201312 | C | 最大的矩形 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312C/) |
| 201312 | D | 有趣的数 | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312D/) |
| 201312 | E | I’m stuck! | [存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312E/) |
