from first_support import *
import first_all
(ROOT/"first-report.json").write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n")
print(f"第一题：{len(report)} 道，{sum(report.values())} 组独立对拍通过。")
