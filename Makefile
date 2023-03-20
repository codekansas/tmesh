# Makefile

define HELP_MESSAGE
			tmesh
			-----

Implementation of some operations on triangular meshes, with C++ and CUDA backends.

Getting Started:
	1. Create a new Conda environment: 'conda create --name tmesh python=3.10'
	2. Activate the environment: 'conda activate tmesh'
	3. Install dependencies: 'make install-conda ; make install-pip'
	4. Build the project: 'make build'

Usage:
	make: Show this help message
	make initialize: Install conda and mamba
	make install-conda: Install conda dependencies
	make format: Format C++ and CMake files

endef
export HELP_MESSAGE

all:
	@echo "$$HELP_MESSAGE"
.PHONY: all

# -----------------
# Conda environment
# -----------------

initialize:
ifeq (, $(shell which mamba))
ifeq (, $(shell which conda))
	$(error Conda is not installed)
else ifeq (, $(CONDA_DEFAULT_ENV))
	$(error Conda not installed or not initialized)
else ifeq (base, $(CONDA_DEFAULT_ENV))
	$(error Don't install this package into the base environment. Run 'conda create --name ml python=3.10' then 'conda activate ml`)
else
	conda install -c conda-forge mamba
endif
endif
.PHONY: initialize

install-conda: initialize
	@mamba install \
		-c conda-forge \
		cmake-format \
		clang-format
.PHONY: install-conda

install: initialize
	python -m pip install .
.PHONY: install

develop: initialize
	python setup.py develop
.PHONY: develop

# -----
# Build
# -----

build: initialize
	[[ -d build ]] || mkdir build
	cd build && \
		PYTHON_EXECUTABLE=$(shell which python) \
		PYTHON_INCLUDE_DIR=$(shell python -c 'import sysconfig; print(sysconfig.get_paths()["include"])') \
		PYTHON_LIBRARY=$(shell python -c 'import sysconfig; print(sysconfig.get_paths()["platlib"])') \
		CMAKE_PREFIX_PATH=$(shell python -c 'import pybind11; print(pybind11.get_cmake_dir())') \
		cmake ../src && make -j
	cp build/cpp.*.so tmesh/
	stubgen -p tmesh.cpp -o .
.PHONY: build

build-ext-inplace: initialize
	python setup.py build_ext --inplace
.PHONY: build-ext-inplace

# ----------
# Formatting
# ----------

cpp-files := $$(git ls-files '*.c' '*.cpp' '*.h' '*.hpp' '*.cu' '*.cuh')
cmake-files := $$(git ls-files '*/CMakeLists.txt')
py-files := $$(git ls-files '*.py')

format: initialize
	@cmake-format -i $(cmake-files)
	@clang-format -i $(cpp-files)
	@ruff --fix $(py-files)
.PHONY: format

check-formatting: initialize
	@cmake-format --check $(cmake-files) > /dev/null
	@clang-format --dry-run --Werror $(cpp-files) > /dev/null
	@ruff $(py-files)
	@darglint $(py-files)
.PHONY: check-formatting

# -----
# Clean
# -----

clean-py:
	rm -rf **/*.pyc **/*.pyd **/*.pyo **/__pycache__

clean-package:
	rm -rf build dist **/*.so **/*.pyi *.egg-info .eggs/

clean: clean-py clean-package
.PHONY: clean

# ------------
# Distribution
# ------------

dist: initialize
	python -m build

upload: initialize
	python -m twine upload dist/*
.PHONY: upload

# --------
# Examples
# --------

build-examples: initialize
	python -c "from examples.base import write_examples; write_examples('_site/')"
.PHONY: build-examples

serve-examples: initialize
	cd _site && python -m http.server
.PHONY: serve-examples
