# Makefile

define HELP_MESSAGE
			Fast Trimesh
			------------

Fast trimesh implementation, with C++ and CUDA backends.

Getting Started:
	1. Create a new Conda environment: 'conda create --name fast-trimesh python=3.10'
	2. Activate the environment: 'conda activate fast-trimesh'
	3. Install dependencies: 'make install-conda'
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
	mamba install \
		-c conda-forge \
		cmake \
		cmake-format \
		clang-format \
		pybind11
.PHONY: install-conda

# -----
# Build
# -----

build: initialize
	mkdir -p build
	cd build && cmake ../fast_trimesh && make -j
.PHONY: build

build-ext-inplace: initialize
	python setup.py build_ext --inplace
.PHONY: build-ext-inplace

# ----------
# Formatting
# ----------

cpp-files := $$(git ls-files '*.c' '*.cpp' '*.h' '*.hpp' '*.cu' '*.cuh')
cmake-files := $$(git ls-files '*/CMakeLists.txt')

format: initialize
	cmake-format -i $(cmake-files)
	clang-format -i $(cpp-files)
.PHONY: format

# -----
# Clean
# -----

clean:
	rm -rf build **/*.so **/*.pyi **/*.pyc **/*.pyd **/*.pyo **/__pycache__
.PHONY: clean
