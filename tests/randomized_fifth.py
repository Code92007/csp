# -*- coding: utf-8 -*-
"""Run independent small-instance oracles against compiled fifth-problem binaries."""
import json
from pathlib import Path
import fifth_support as support
import fifth_extended, fifth_extra, fifth_geometry

support.random_first()
for date in ('202303','202112','202309','201503','201712','201809','201512','201604','201403','201703','202109'):
    fifth_extended.run(date)
for date in ('201912','202006','202409','202403','202603','202312','202305','201509','201409'):
    fifth_extra.run(date)
for date in ('202406','202104','202206'):
    fifth_geometry.run(date)
report={'seed':920072026,'cases':support.report,'total':sum(support.report.values()),'official_judge':'not_submitted'}
(Path(__file__).parent/'fifth-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
print(json.dumps(report,ensure_ascii=False,indent=2))
