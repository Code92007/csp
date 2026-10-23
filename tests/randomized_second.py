from second_support import *
import second_first, second_last
(ROOT/'second-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(f'第二题：{len(report)} 道，{sum(report.values())} 组独立对拍通过。')
