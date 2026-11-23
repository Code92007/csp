# 前端依赖

这些固定版本随工程保存。构建与浏览不需要访问 CDN，也不需要 npm install。

| 依赖 | 固定版本 | 用途 | 授权 |
|---|---|---|---|
| Marked | 12.0.2 | Markdown 渲染 | MIT，见 marked.LICENSE |
| DOMPurify | 3.3.0 | 清理渲染结果 | Apache-2.0 或 MPL-2.0，见 DOMPurify.LICENSE |
| KaTeX | 0.16.22 | 数学公式与字体 | MIT，见 katex/LICENSE |
| highlight.js | 11.11.1 | C++ 语法高亮 | BSD-3-Clause，见 highlight.LICENSE |

来源为各项目官方仓库或 npm 发行包。升级时应同时更新许可证，并验证公式、代码块与页面显示。

highlight.js 使用[官方 CDN 仓库的固定版本浏览器包](https://github.com/highlightjs/cdn-release/blob/11.11.1/build/highlight.min.js)，许可证来自[官方源码仓库](https://github.com/highlightjs/highlight.js/blob/11.11.1/LICENSE)。代码配色在 `web/style.css` 中定义。
