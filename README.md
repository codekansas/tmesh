# Fast Trimesh

Fast operators for triangular meshes.

## Installation

Fast Trimesh is available on PyPI:

```bash
pip install fast-trimesh
```

### From source

To install from source, first create a Conda environment:

```bash
conda create -n fast-trimesh python=3.10
conda activate fast-trimesh
```

Next, clone and install the package:

```bash
git clone https://github.com/codekansas/fast-trimesh.git
cd fast-trimesh
make install-conda  # Installs Conda requirements
make install        # Builds and installs package
```

### From Github using `pip`

Alternatively, you can install the latest package version directly:

```bash
pip install git+https://github.com/codekansas/fast-trimesh.git
```

## Getting Started

The following script demonstrates how to use the package to generate an
STL or OBJ file from a simple mesh:

```python
import math

from fast_trimesh.fast_trimesh.cpu.io import save_obj, save_stl
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.fast_trimesh.cpu.trimesh import Affine3D

# Create some cuboids.
a = cuboid(1.0, 1.0, 1.0)
b = cuboid(1.0, 1.0, 1.0)

# Move the second cuboid around.
rot = Affine3D(rot=(math.pi / 4, 0.0, 0.0))
trans = Affine3D(trans=(0.0, 0.5, 0.5))
b = b << rot @ trans

# Save the resulting cuboid.
save_stl("simple_example.stl", a + b)
save_obj("simple_example.obj", a + b)
```

This results in the below STL:

```stl
solid fast_trimesh STL file
facet normal 0 0 -1
outer loop
vertex 0 0 0
vertex 1 1 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0 0 0
vertex 0 1 0
vertex 1 1 0
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex 0 0 0
vertex 1 0 1
vertex 0 0 1
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex 0 0 0
vertex 1 0 0
vertex 1 0 1
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 1 0 0
vertex 1 1 1
vertex 1 0 1
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 1 0 0
vertex 1 1 0
vertex 1 1 1
endloop
endfacet
facet normal 0 1 -0
outer loop
vertex 1 1 0
vertex 0 1 1
vertex 1 1 1
endloop
endfacet
facet normal 0 1 0
outer loop
vertex 1 1 0
vertex 0 1 0
vertex 0 1 1
endloop
endfacet
facet normal -1 0 0
outer loop
vertex 0 1 0
vertex 0 0 1
vertex 0 1 1
endloop
endfacet
facet normal -1 0 0
outer loop
vertex 0 1 0
vertex 0 0 0
vertex 0 0 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0 0 1
vertex 1 1 1
vertex 0 1 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0 0 1
vertex 1 0 1
vertex 1 1 1
endloop
endfacet
facet normal 0 0.707107 -0.707107
outer loop
vertex 0 0.5 0.5
vertex 1 1.20711 1.20711
vertex 1 0.5 0.5
endloop
endfacet
facet normal 0 0.707107 -0.707107
outer loop
vertex 0 0.5 0.5
vertex 0 1.20711 1.20711
vertex 1 1.20711 1.20711
endloop
endfacet
facet normal 0 -0.707107 -0.707107
outer loop
vertex 0 0.5 0.5
vertex 1 -0.207107 1.20711
vertex 0 -0.207107 1.20711
endloop
endfacet
facet normal 0 -0.707107 -0.707107
outer loop
vertex 0 0.5 0.5
vertex 1 0.5 0.5
vertex 1 -0.207107 1.20711
endloop
endfacet
facet normal 1 0 -0
outer loop
vertex 1 0.5 0.5
vertex 1 0.5 1.91421
vertex 1 -0.207107 1.20711
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 1 0.5 0.5
vertex 1 1.20711 1.20711
vertex 1 0.5 1.91421
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 1 1.20711 1.20711
vertex 0 0.5 1.91421
vertex 1 0.5 1.91421
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 1 1.20711 1.20711
vertex 0 1.20711 1.20711
vertex 0 0.5 1.91421
endloop
endfacet
facet normal -1 0 0
outer loop
vertex 0 1.20711 1.20711
vertex 0 -0.207107 1.20711
vertex 0 0.5 1.91421
endloop
endfacet
facet normal -1 -0 0
outer loop
vertex 0 1.20711 1.20711
vertex 0 0.5 0.5
vertex 0 -0.207107 1.20711
endloop
endfacet
facet normal 0 -0.707107 0.707107
outer loop
vertex 0 -0.207107 1.20711
vertex 1 0.5 1.91421
vertex 0 0.5 1.91421
endloop
endfacet
facet normal 0 -0.707107 0.707107
outer loop
vertex 0 -0.207107 1.20711
vertex 1 -0.207107 1.20711
vertex 1 0.5 1.91421
endloop
endfacet
endsolid fast_trimesh STL file
```

For more examples, see the `examples` directory.

### Unit Tests

To see examples of different parts of the API, it is helpful to try running
the tests. To do so, after cloning the repository, run:

```bash
pytest .
```
