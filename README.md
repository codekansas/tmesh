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

# Create some cuboids.
a = cuboid(1.0, 1.0, 1.0, center=True)
b = cuboid(1.0, 1.0, 1.0, center=True)

# Move the second cuboid around.
rot = Affine3D(rot=(math.pi / 4, 0.0, 0.0))
trans = Affine3D(trans=(0.0, 0.5, 0.0))
b <<= rot @ trans

# Save the resulting mesh.
save_stl_text("simple_example_ascii.stl", a + b)
save_stl("simple_example.stl", a + b)
save_obj("simple_example.obj", a + b)
save_ply("simple_example.ply", a + b)
```

## Motivation

At various times I have wished there were something like [OpenSCAD][openscad] for Python. Packages like [trimesh][trimesh] exist, but they come with a number of clunky dependencies (including, interestingly enough, OpenSCAD itself). This package is a standalone implementation of the core functionality of OpenSCAD, but with a Pythonic API, making it easy to integrate into existing Python code. It is also written in pure C++, so it's hopefully relatively fast.

[trimesh]: https://trimsh.org/trimesh.html
[openscad]: https://www.openscad.org/
