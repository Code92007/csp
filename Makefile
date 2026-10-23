PYTHON ?= python3
SESSION ?= 202609
PROBLEM ?= A
PORT ?= 8765
.PHONY: list build run check sync site serve random random-fifth random-fourth random-third random-second random-first random-gather stress-gather index
list:
	$(PYTHON) tools/project.py list
build:
	$(PYTHON) tools/project.py build $(SESSION) $(PROBLEM)
run:
	$(PYTHON) tools/project.py run $(SESSION) $(PROBLEM)
check:
	$(PYTHON) tools/project.py check
sync:
	$(PYTHON) tools/content.py --sync
site:
	$(PYTHON) tools/build_site.py
serve: site
	$(PYTHON) -m http.server $(PORT) --bind 127.0.0.1 --directory site
index:
	$(PYTHON) tools/update_index.py
random:
	$(PYTHON) tests/randomized.py
	$(PYTHON) tests/randomized_202605.py
	$(PYTHON) tests/randomized_fifth.py
random-fifth:
	$(PYTHON) tests/randomized_fifth.py

random-fourth:
	$(PYTHON) tests/randomized_fourth.py

random-third:
	$(PYTHON) tests/randomized_third.py

random-second:
	$(PYTHON) tests/randomized_second.py

random-first:
	$(PYTHON) tests/randomized_first.py

random-gather:
	$(PYTHON) tests/randomized_gather.py

stress-gather:
	$(PYTHON) tests/stress_gather.py
