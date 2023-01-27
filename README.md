# tmesh

Fast operators for triangular meshes.

## Getting Started

`tmesh` is available on PyPI:

```bash
pip install tmesh
```

See the [examples](examples) directory to see how to use the package.

The following script demonstrates how to use the package to generate an
STL or OBJ file from a simple mesh:

```python
import math

from tmesh import *

# Create a cuboid.
a = regular_polygon_mesh(1.0, n=4)
b = regular_polygon_mesh(1.0, n=4)

# Move the second cuboid around.
rot = Affine2D(rot=math.pi / 4)
trans = Affine2D(trans=(0.0, 0.5))
b <<= rot @ trans

# Extrudes the intersection to a 3D shape with height 1.
cube = linear_extrude(a | b, 1.0)

# Save the resulting mesh.
save_stl_text("simple_example_ascii.stl", cube)
save_stl("simple_example.stl", cube)
save_obj("simple_example.obj", cube)
save_ply("simple_example.ply", cube)
```

## Motivation

At various times I have wished there were something like [OpenSCAD][openscad] for Python. Packages like [trimesh][trimesh] exist, but they come with a number of clunky dependencies (including, interestingly enough, OpenSCAD itself). This package is a standalone implementation of the core functionality of OpenSCAD, but with a Pythonic API, making it easy to integrate into existing Python code. It is also written in pure C++, so it's hopefully relatively fast.

[trimesh]: https://trimsh.org/trimesh.html
[openscad]: https://www.openscad.org/
