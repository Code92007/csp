'use strict';
const $ = (selector, scope=document) => scope.querySelector(selector);
const esc = value => String(value).replace(/[&<>"']/g, c=>({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[c]));
const tagColours=[['#e5eddf','#405e43'],['#eee4d5','#765d39'],['#e0e9ed','#42616d'],['#ede3e9','#765368'],['#e9e6f1','#66567d'],['#f4e2d6','#8a553a']];
let data, route, debounce, renderToken=0;
$('.skip').addEventListener('click',event=>{event.preventDefault();$('#main').focus();$('#main').scrollIntoView();});
try { const theme=localStorage.getItem('csp-theme'); if(theme)document.documentElement.dataset.theme=theme; } catch (_) {}
$('#theme').addEventListener('click',()=>{const theme=document.documentElement.dataset.theme==='dark'?'light':'dark';document.documentElement.dataset.theme=theme;try{localStorage.setItem('csp-theme',theme);}catch(_) {}});
function url(path, params={}) {const q=new URLSearchParams(Object.entries(params).filter(([,v])=>v!==''&&v!==null&&v!==undefined));return '#'+path+(q.size?'?'+q:'');}
function tag(tag, path='/problems', active=false, count) {
  let hash=0;for(const c of tag)hash=(hash+c.codePointAt(0))%tagColours.length;
  const [bg,ink]=tagColours[hash];
  return `<a class="tag${active?' active':''}" style="--tag-bg:${bg};--tag-ink:${ink}" href="${esc(url(path,{tag}))}">${esc(tag)}${count!==undefined?`<span class="count">${count}</span>`:''}</a>`;
}
function toast(text) {$('#toast').textContent=text;$('#toast').classList.add('visible');clearTimeout(toast.timer);toast.timer=setTimeout(()=>$('#toast').classList.remove('visible'),1800);}
function status(problem){return problem.status==='implemented'?'已实现':problem.status==='partial'?'部分分实现':'待编写';}
function ojBadge(problem){
  return [['曙梦',problem.oj],['洛谷',problem.luogu]].map(([site,oj])=>{
    if(!oj?.record)return '';
    const verified=oj.status==='accepted'&&oj.score===100;
    const label=verified?`${site}已验证`:oj.status==='failed'?`${site} ${oj.score} 分`:`${site}待核验`;
    const detail=verified?`${site}民间数据 100 分 Accepted`:oj.status==='failed'?`${site} ${oj.score} 分 ${oj.verdict}`:`${site}已提交，结果待核验`;
    return `<a class="oj-badge ${verified?'verified':oj.status==='failed'?'failed':'pending'}" href="${esc(oj.record)}" target="_blank" rel="noopener noreferrer" title="${esc(detail)}" aria-label="${esc(detail)}">${esc(label)}</a>`;
  }).join('');
}
function stateParams(){return Object.fromEntries(route.searchParams);}
function filtersChanged(){
  const params=stateParams();
  params.q=$('#query').value.trim();params.year=$('#year').value;params.status=$('#status').value;
  const hash=url(route.pathname,params);history.replaceState(null,'',hash);route=new URL('https://csp.local'+hash.slice(1));renderResults();
}
function hero(title,description){const s=data.stats;return `<section class="hero"><div><div class="eyebrow">THE CSP NOTEBOOK / 200+</div><h1>${title}</h1><p class="desc">${description}</p><p class="hero-note">按场次从新到旧整理 · 每天 2–3 小时 · 先稳住前两题</p></div><div class="hero-stats"><div class="stat"><strong>${s.contests}</strong><span>年月题组</span></div><div class="stat"><strong>${s.complete_contests}</strong><span>完整场次文章</span></div><div class="stat"><strong>${s.implemented}</strong><span>已实现题目</span></div><div class="stat"><strong>${s.problems-s.implemented}</strong><span>待补全题目</span></div></div></section>`;}
function sidebar(mode){
  const tags=Object.entries(data.tags).sort((a,b)=>b[1]-a[1]||a[0].localeCompare(b[0],'zh-CN'));
  const years=[...new Set(data.articles.map(a=>a.contest.slice(0,4)))];
  return `<aside class="sidebar"><section class="side-note"><h3>从会做，到稳定拿分</h3><p>先独立做 A、B，再对照题解补漏洞。C 题练习读题与实现，D、E 可用来扩展专题。</p><a href="#/plan">打开备考与练习计划 ↗</a><span class="tiny">201312 为第 0 次练习题组。原题与 Bonus 的区别见 202605E。</span></section><section><h2>按算法找题</h2><div class="side-tags">${tags.slice(0,24).map(([t,n])=>tag(t,mode,route.searchParams.get('tag')===t,n)).join('')}</div><a class="text-button" href="#/tags">查看全部 ${tags.length} 个标签 →</a></section><section><h2>年份索引</h2><div class="year-list">${years.map(y=>`<a href="${url(mode,{year:y})}">${y} ↗</a>`).join('')}</div></section></aside>`;
}
function listing(mode){
  const problemMode=mode==='/problems';
  const years=[...new Set(data.articles.map(a=>a.contest.slice(0,4)))];
  $('#main').innerHTML=hero(problemMode?'让同类题，连成一条线。':'一场比赛，一篇手记。',problemMode?'从算法标签找到相关题目，直接跳到题意、解法和 C++17 代码。相同知识点可以跨场次对照练习。':'把历次 CSP 拆成可以读懂、复现与练习的笔记。每场五题，逐题记录算法思路、代码和实际验证进度。')+`<div class="layout"><section><div class="toolbar"><label class="search-wrap"><span aria-hidden="true">⌕</span><input id="query" type="search" aria-label="搜索场次、题目或算法" placeholder="搜索场次、题名或算法，例如 202609 / 动态规划" value="${esc(route.searchParams.get('q')||'')}"></label><select id="year" aria-label="筛选年份"><option value="">全部年份</option>${years.map(y=>`<option value="${y}">${y} 年</option>`).join('')}</select><select id="status" aria-label="筛选完成状态"><option value="">全部进度</option><option value="implemented">${problemMode?'已实现题目':'五题完整'}</option><option value="pending">${problemMode?'待补全题目':'整理中的草稿'}</option></select></div><div id="results" aria-live="polite"></div></section>${sidebar(mode)}</div>`;
  $('#year').value=route.searchParams.get('year')||'';$('#status').value=route.searchParams.get('status')||'';
  $('#query').addEventListener('input',()=>{clearTimeout(debounce);debounce=setTimeout(filtersChanged,130);});
  for(const id of ['year','status'])$('#'+id).addEventListener('change',filtersChanged);
  renderResults();
}
function renderResults(){
  const p=route.searchParams,q=(p.get('q')||'').toLowerCase(),year=p.get('year'),selected=p.get('tag'),state=p.get('status');
  const problemMode=route.pathname==='/problems';
  const filterArticle=a=>(!year||a.contest.startsWith(year));
  const filterProblem=(problem,a)=>(!selected||problem.tags.includes(selected))&&(!q||[a.contest,problem.id,problem.title,...problem.tags].join(' ').toLowerCase().includes(q))&&(!state||(state==='implemented'?problem.status==='implemented':problem.status!=='implemented'));
  let results;
  if(problemMode)results=data.articles.filter(filterArticle).flatMap(a=>a.problems.filter(problem=>filterProblem(problem,a)).map(problem=>({a,problem})));
  else results=data.articles.filter(a=>filterArticle(a)&&(!selected||a.tags.includes(selected))&&(!q||a.search.includes(q))&&(!state||(state==='implemented'?a.ready===5:a.ready<5)));
  const heading=`<div class="result-heading"><span>${selected?'标签「'+esc(selected)+'」 · ':''}${results.length} ${problemMode?'道题目':'个题组'}</span><span class="rule"></span><span>新 → 旧</span>${q||year||selected||state?`<a class="clear" href="${url(route.pathname)}">清除筛选</a>`:''}</div>`;
  if(!results.length){$('#results').innerHTML=heading+'<div class="empty"><strong>没有找到相关内容</strong>试试其他标签、年份，或清除筛选。</div>';return;}
  $('#results').innerHTML=heading+(problemMode?`<div class="problem-list">${results.map(({a,problem})=>`<article class="problem-row"><div class="problem-id">${a.contest}<br>${problem.id} / 100</div><div><div class="problem-heading"><a class="question-link" href="${url('/contest/'+a.contest,{problem:problem.id})}">${esc(problem.title)}</a>${ojBadge(problem)}<span class="question-state">${status(problem)}</span></div><div class="tags">${problem.tags.map(t=>tag(t)).join('')}</div></div></article>`).join('')}</div>`:`<div class="post-list">${results.map(a=>`<article class="post-card"><div class="date-stamp"><strong>${a.contest.slice(4)}</strong><small>${a.contest.slice(0,4)}</small></div><div><div class="post-meta"><span>${a.contest==='201312'?'第 0 次练习题组':'CSP 认证题组'}</span><span>·</span><span class="badge${a.ready===5?' ready':''}">${a.ready===5?'五题已实现':'草稿 '+a.ready+'/5'}</span></div><h2><a href="${url('/contest/'+a.contest)}">${a.contest.slice(0,4)} 年 ${Number(a.contest.slice(4))} 月 · 五题题解</a></h2><div class="problem-preview">${a.problems.map(p=>`<a href="${url('/contest/'+a.contest,{problem:p.id})}"><b>${p.id}</b>${esc(p.title)}</a>`).join('')}</div><div class="tags">${a.tags.filter(t=>t!=='CSP').slice(0,7).map(t=>tag(t)).join('')}${a.tags.length>8?`<a class="tag" href="${url('/contest/'+a.contest)}">+${a.tags.length-8}</a>`:''}</div></div></article>`).join('')}</div>`);
}
function tagMap(){
  const entries=Object.entries(data.tags).sort((a,b)=>b[1]-a[1]||a[0].localeCompare(b[0],'zh-CN'));
  $('#main').innerHTML=hero('知识点，是另一种目录。','点一个标签，找到不同场次中使用相同方法的题目。每篇文章保留完整的一场五题，也为每道题单独标记算法。')+`<div class="result-heading" style="margin-top:24px"><span>${entries.length} 个标签 · 按题解使用的算法分类</span><span class="rule"></span></div><section class="tag-grid">${entries.map(([t,n])=>{const problems=data.articles.flatMap(a=>a.problems).filter(p=>p.tags.includes(t));const ready=problems.filter(p=>p.status==='implemented').length;return `<article class="tag-tile">${tag(t)}<p><strong>${problems.length}</strong>道题 · ${n} 个题组<br>${ready} 道已实现</p></article>`;}).join('')}</section>`;
}
function markdown(source){
  const math=[];
  const protectedSource=source.replace(/(```[^\n]*\n[\s\S]*?```)|(`[^`\n]*`)|(\$\$[\s\S]*?\$\$)|(\$(?!\s)[^$\n]+?\$)/g,(all,code,inline,block,single)=>{
    if(code||inline)return all;
    const display=Boolean(block),formula=all.slice(display?2:1,display?-2:-1),index=math.length;
    let html;
    try{html=katex.renderToString(formula,{displayMode:display,throwOnError:false,trust:false,strict:'ignore'});}catch(_){html=esc(all);}
    math.push(html);return 'CSPMATHTOKEN'+index+'END';
  });
  let html=marked.parse(protectedSource,{gfm:true,breaks:false});
  html=html.replace(/CSPMATHTOKEN(\d+)END/g,(_,index)=>math[Number(index)]);
  return DOMPurify.sanitize(html,{USE_PROFILES:{html:true,mathMl:true,svg:true}});
}
function enhanceArticle(container,contest){
  for(const a of container.querySelectorAll('a[href]')){
    const href=a.getAttribute('href');
    if(/^https?:\/\//.test(href)){a.target='_blank';a.rel='noopener noreferrer';}
    else if(href==='../README.md')a.href='#/contests';
    else if(/^\.\.\/\d{6}\/README\.md(?:#problem-[a-e])?$/.test(href)){const match=href.match(/(\d{6})\/README\.md(?:#problem-([a-e]))?/);a.href=url('/contest/'+match[1],{problem:match[2]?.toUpperCase()});}
    else if(contest&&/^[A-E]\.cpp$/.test(href)){a.href='content/'+contest+'/'+href;a.download=href;}
    else if(contest&&/^\.\.\/tests\/[A-Za-z0-9_./-]+$/.test(href)){a.href='content/'+href.slice(3);a.download=href.split('/').pop();}
    else if(/^#problem-[a-e]$/.test(href))a.href=url('/contest/'+contest,{problem:href.slice(-1).toUpperCase()});
  }
  for(const pre of container.querySelectorAll('pre')){
    const code=pre.querySelector('code');if(!code)continue;
    const button=document.createElement('button');button.className='copy-code';button.textContent='复制代码';button.type='button';button.addEventListener('click',async()=>{try{await navigator.clipboard.writeText(code.textContent);button.textContent='已复制';setTimeout(()=>button.textContent='复制代码',1500);}catch(_){toast('自动复制不可用，请手动选择代码。');}});pre.append(button);
  }
}
function showArticle(contest){
  const a=data.articles.find(a=>a.contest===contest);if(!a){$('#main').innerHTML='<div class="empty"><strong>尚未收录这个场次</strong><a href="#/contests">返回目录</a></div>';return;}
  document.title='CSP '+contest+' 五题题解 · CSP 手记';
  const index=data.articles.indexOf(a),newer=data.articles[index-1],older=data.articles[index+1];
  const links=`<div class="prev-next">${newer?`<a href="${url('/contest/'+newer.contest)}">← ${newer.contest}</a>`:'<span></span>'}${older?`<a href="${url('/contest/'+older.contest)}">${older.contest} →</a>`:''}</div>`;
  $('#main').innerHTML=`<header class="article-head"><div class="breadcrumbs"><a href="#/contests">全部场次</a> / ${contest.slice(0,4)} / ${contest.slice(4)}</div><div class="post-meta"><span class="badge${a.ready===5?' ready':''}">${a.ready===5?'五题已实现':'整理中 · '+a.ready+'/5'}</span><span>更新于 ${a.updated}</span></div><h1>${esc(a.title)}</h1><div class="tags">${a.tags.filter(t=>t!=='CSP').map(t=>tag(t)).join('')}</div><div class="article-actions"><a href="content/${contest}/README.md" download>下载 Markdown ↓</a><a href="#/problems?year=${contest.slice(0,4)}">查看同年题目 ↗</a></div></header><div class="article-layout"><article class="article-body" id="article"></article><aside class="toc"><h2>本场五题</h2>${a.problems.map(p=>`<a href="${url('/contest/'+contest,{problem:p.id})}"><span class="letter">${p.id}</span>${esc(p.title)}<span class="sub">${status(p)}</span></a>`).join('')}${links}<a href="#/contests">← 返回场次目录</a></aside></div>${links}`;
  const container=$('#article');container.innerHTML=markdown(a.body);enhanceArticle(container,contest);
  const problem=route.searchParams.get('problem');if(/^[A-E]$/.test(problem||''))requestAnimationFrame(()=>$('#problem-'+problem.toLowerCase(),container)?.scrollIntoView({behavior:'instant',block:'start'}));
}
async function showPlan(token){
  document.title='备考计划 · CSP 手记';
  $('#main').innerHTML='<header class="article-head"><div class="breadcrumbs"><a href="#/contests">全部场次</a> / 备考计划</div><h1>每天 2–3 小时，如何安排。</h1><div class="article-actions"><a href="study-plan.md" download>下载计划 Markdown ↓</a></div></header><div class="article-layout"><article class="article-body" id="article">正在读取…</article></div>';
  try{const response=await fetch('study-plan.md');if(!response.ok)throw new Error('计划文件未生成');const body=await response.text();if(token!==renderToken)return;$('#article').innerHTML=markdown(body);enhanceArticle($('#article'));}catch(e){if(token===renderToken)$('#article').textContent=e.message;}
}
async function render(){
  clearTimeout(debounce);const token=++renderToken;
  route=new URL('https://csp.local'+(location.hash.slice(1)||'/contests'));
  document.title='CSP 手记 · 场次与算法';
  const active=route.pathname==='/tags'?'tags':route.pathname==='/problems'?'problems':'contests';
  for(const a of document.querySelectorAll('[data-nav]')){a.classList.toggle('active',a.dataset.nav===active);if(a.dataset.nav===active)a.setAttribute('aria-current','page');else a.removeAttribute('aria-current');}
  if(route.pathname.startsWith('/contest/'))showArticle(route.pathname.split('/')[2]);
  else if(route.pathname==='/tags')tagMap();
  else if(route.pathname==='/plan')await showPlan(token);
  else {if(!['/contests','/problems'].includes(route.pathname))route.pathname='/contests';listing(route.pathname);}
  if(!route.searchParams.get('problem'))window.scrollTo({top:0,behavior:'instant'});
}
window.addEventListener('hashchange',()=>{if(data)render();});
(async()=>{try{const response=await fetch('content.json');if(!response.ok)throw new Error('无法读取索引');data=await response.json();await render();}catch(e){$('#main').innerHTML='<div class="error"><h1>内容暂时无法载入</h1><p>'+esc(e.message)+'</p><p>请在工程目录运行 make serve，再通过本地网址打开。</p></div>';}})();
