from fourth_support import *
import fourth_first, fourth_second, fourth_third, fourth_fourth, fourth_last
fourth_first.first()
for module in (fourth_second, fourth_third, fourth_fourth, fourth_last):
    rng.seed(9200704)
    module.run()
(ROOT/'fourth-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(f'第四题：{len(report)} 道，{sum(report.values())} 组独立对拍通过。')
