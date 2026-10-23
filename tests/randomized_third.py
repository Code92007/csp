from third_support import *
import third_first, third_second
rng.seed(9200704)
third_first.run()
rng.seed(9200704)
third_second.run()
import third_third, third_last
(ROOT/'third-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(f'第三题：{len(report)} 道，{sum(report.values())} 组独立对拍通过。')
