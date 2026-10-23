# -*- coding: utf-8 -*-
"""Read the project's deliberately small YAML/JSON frontmatter dialect.

One key per line; values use JSON syntax, which is also valid YAML. No packages
or executable YAML tags are needed. Markdown articles are the source of truth.
"""
from pathlib import Path
import json
import re

ROOT = Path(__file__).resolve().parents[1]

def read_article(path):
    text = path.read_text(encoding='utf-8')
    if not text.startswith('---\n') or '\n---\n' not in text[4:]:
        raise ValueError(f'{path}: missing frontmatter')
    header, body = text[4:].split('\n---\n', 1)
    metadata = {}
    for line in header.splitlines():
        if not line.strip() or line.lstrip().startswith('#'):
            continue
        key, value = line.split(':', 1)
        if key in metadata:
            raise ValueError(f'{path}: duplicate key {key}')
        metadata[key] = json.loads(value.strip())
    contest = metadata['contest']
    if not re.fullmatch(r'\d{6}', contest) or path.parent.name != contest:
        raise ValueError(f'{path}: contest must match its YYYYMM directory')
    if [p['id'] for p in metadata['problems']] != list('ABCDE'):
        raise ValueError(f'{path}: must contain exactly A, B, C, D, E')
    for p in metadata['problems']:
        if p['code'] != p['id']+'.cpp' or p['anchor'] != 'problem-'+p['id'].lower():
            raise ValueError(f'{path}: invalid problem path/anchor')
        if p['status'] not in ('implemented','partial','pending'):
            raise ValueError(f'{path}: invalid problem status')
    if not set(t for p in metadata['problems'] for t in p['tags']).issubset(set(metadata['tags'])):
        raise ValueError(f'{path}: article tags must include all problem tags')
    if metadata['status'] == 'published' and any(p['status'] != 'implemented' for p in metadata['problems']):
        raise ValueError(f'{path}: cannot publish an incomplete contest as complete')
    metadata.update(body=body.lstrip(), path=path.relative_to(ROOT).as_posix())
    return metadata

def articles():
    return [read_article(p) for p in sorted(ROOT.glob('[0-9][0-9][0-9][0-9][0-9][0-9]/README.md'), reverse=True)]

def code_blocks(article):
    sections = re.split(r'^## ([A-E])\. [^\n]+\n', article['body'], flags=re.M)
    found = {}
    for i in range(1, len(sections), 2):
        letter, text = sections[i], sections[i+1]
        matches = re.findall(r'^```cpp\n(.*?)^```\s*$', text, flags=re.M|re.S)
        if len(matches) != 1:
            raise ValueError(f'{article["contest"]}{letter}: expected exactly one cpp block')
        for required in ('### 题意','### 题解','### 代码'):
            if required not in text:
                raise ValueError(f'{article["contest"]}{letter}: missing {required}')
        found[letter] = matches[0].rstrip()+'\n'
    if set(found) != set('ABCDE'):
        raise ValueError(f'{article["contest"]}: missing a problem section')
    return found

def problem_items():
    for article in articles():
        for p in article['problems']:
            yield dict(p, date=article['contest'], letter=p['id'], code_file=article['contest']+'/'+p['code'], article_file=article['path'])

if __name__ == '__main__':
    import argparse
    parser=argparse.ArgumentParser(description='Validate Markdown or generate matching CPP files')
    parser.add_argument('--sync',action='store_true',help='overwrite A–E.cpp from article code fences')
    args=parser.parse_args()
    total=0
    for article in articles():
        for letter,code in code_blocks(article).items():
            target=ROOT/article['contest']/(letter+'.cpp')
            if args.sync:
                target.write_text(code,encoding='utf-8')
            elif not target.exists() or target.read_text(encoding='utf-8').rstrip()!=code.rstrip():
                raise SystemExit(f'{target}: differs from Markdown; run make sync after editing the article')
            total+=1
    print(('已同步' if args.sync else '已核对')+f' {total} 份 CPP 与 Markdown。')
