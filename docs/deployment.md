# 静态部署

本工程部署到 [GitHub Pages](https://code92007.github.io/csp/)，源码仓库为 [Code92007/csp](https://github.com/Code92007/csp)。

每场内容以 `YYYYMM/README.md` 为准，独立 CPP 和网页可由 Markdown 生成。网站模板在 `web/`，构建工具在 `tools/`，不依赖数据库或 CDN。

## 本地验证

```sh
make sync
make check
make index
make site
```

## 发布更新

仓库 Settings → Pages 的构建来源为 GitHub Actions。`.github/workflows/pages.yml` 从 Markdown 生成网页，将 `site/` 上传为 Pages 构建产物并部署。

工作流采用手动触发，普通 push 不会自动发布。内容更新后先提交并推送，再执行：

```sh
git push origin main
gh workflow run pages.yml --repo Code92007/csp --ref main
gh run list --repo Code92007/csp --workflow pages.yml --limit 1
```

也可以打开仓库 Actions → Publish CSP notes → Run workflow。工作流完成后访问 https://code92007.github.io/csp/。场次与标签路由使用 URL hash，静态文件使用相对路径，可部署在 `/csp/` 子目录。

## 其他静态托管

构建命令为 `python3 tools/content.py --sync && python3 tools/build_site.py`，产物为 `site/`。需要 Python 3.9 或更新版本，不需要 Node.js、npm 或在线数据库。编译与算法测试在本地独立执行。

本地预览使用 `make serve`，访问 http://127.0.0.1:8765；不要直接用 file 协议打开 index.html，因为浏览器通常会限制读取 JSON。
