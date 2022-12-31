# Makefile

install-reqs:
	pip install sphinx sphinx-rtd-theme
.PHONY: install-requirements

build:
	sphinx-build -b html source/ build/
.PHONY: build

serve:
	cd build && python -m http.server
.PHONY: serve

clean:
	rm -rf build/ source/generated/
.PHONY: clean
