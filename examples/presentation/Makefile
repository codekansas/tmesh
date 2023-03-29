# Makefile

all: run_all_py_files
.PHONY: all

run_all_py_files:
	@echo "Running all python files"
	@echo "========================"
	@echo
	@for file in *.py; do \
		echo "Running $$file"; \
		python $$file; \
		echo; \
	done
.PHONY: run_all_py_files

clean:
	rm -f *.stl *.svg
.PHONY: clean
