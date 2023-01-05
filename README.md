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

from fast_trimesh.cpu.io import save_stl_text
from fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.cpu.types import Affine3D

# Create some cuboids.
a = cuboid(1.0, 1.0, 1.0, center=True)
b = cuboid(1.0, 1.0, 1.0, center=True)

# Move the second cuboid around.
rot = Affine3D(rot=(math.pi / 4, 0.0, 0.0))
trans = Affine3D(trans=(0.0, 0.5, 0.0))
b <<= rot @ trans

# Save the resulting cuboid.
save_stl("simple_example.stl", a + b)
save_obj("simple_example.obj", a + b)
```

This results in the below STL:

```stl
solid fast_trimesh STL file
facet normal 0 0 -1
outer loop
vertex -0.5 -0.5 -0.5
vertex 0.5 0.5 -0.5
vertex 0.5 -0.5 -0.5
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.5 -0.5 -0.5
vertex -0.5 0.5 -0.5
vertex 0.5 0.5 -0.5
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex -0.5 -0.5 -0.5
vertex 0.5 -0.5 0.5
vertex -0.5 -0.5 0.5
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex -0.5 -0.5 -0.5
vertex 0.5 -0.5 -0.5
vertex 0.5 -0.5 0.5
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 -0.5 -0.5
vertex 0.5 0.5 0.5
vertex 0.5 -0.5 0.5
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 -0.5 -0.5
vertex 0.5 0.5 -0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal 0 1 -0
outer loop
vertex 0.5 0.5 -0.5
vertex -0.5 0.5 0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal 0 1 0
outer loop
vertex 0.5 0.5 -0.5
vertex -0.5 0.5 -0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 0.5 -0.5
vertex -0.5 -0.5 0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 0.5 -0.5
vertex -0.5 -0.5 -0.5
vertex -0.5 -0.5 0.5
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 -0.5 0.5
vertex 0.5 0.5 0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 -0.5 0.5
vertex 0.5 -0.5 0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal 0 0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex 0.5 1.20711 0
vertex 0.5 0.5 -0.707107
endloop
endfacet
facet normal 0 0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex -0.5 1.20711 0
vertex 0.5 1.20711 0
endloop
endfacet
facet normal 0 -0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex 0.5 -0.207107 0
vertex -0.5 -0.207107 0
endloop
endfacet
facet normal 0 -0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex 0.5 0.5 -0.707107
vertex 0.5 -0.207107 0
endloop
endfacet
facet normal 1 0 -0
outer loop
vertex 0.5 0.5 -0.707107
vertex 0.5 0.5 0.707107
vertex 0.5 -0.207107 0
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 0.5 -0.707107
vertex 0.5 1.20711 0
vertex 0.5 0.5 0.707107
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 0.5 1.20711 0
vertex -0.5 0.5 0.707107
vertex 0.5 0.5 0.707107
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 0.5 1.20711 0
vertex -0.5 1.20711 0
vertex -0.5 0.5 0.707107
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 1.20711 0
vertex -0.5 -0.207107 0
vertex -0.5 0.5 0.707107
endloop
endfacet
facet normal -1 -0 0
outer loop
vertex -0.5 1.20711 0
vertex -0.5 0.5 -0.707107
vertex -0.5 -0.207107 0
endloop
endfacet
facet normal 0 -0.707107 0.707107
outer loop
vertex -0.5 -0.207107 0
vertex 0.5 0.5 0.707107
vertex -0.5 0.5 0.707107
endloop
endfacet
facet normal 0 -0.707107 0.707107
outer loop
vertex -0.5 -0.207107 0
vertex 0.5 -0.207107 0
vertex 0.5 0.5 0.707107
endloop
endfacet
endsolid fast_trimesh STL file
```

For more examples, see the [examples](examples).

### Unit Tests

To see examples of different parts of the API, it is helpful to try running
the tests. To do so, after cloning the repository, run:

```bash
pytest .
```
