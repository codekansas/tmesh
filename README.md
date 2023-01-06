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

from fast_trimesh.cpu.io import save_stl_text, save_stl, save_obj, save_ply
from fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.cpu.types import Affine3D

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

See the [examples](examples) directory for more.

### Unit Tests

To see examples of different parts of the API, it is helpful to try running
the tests. To do so, after cloning the repository, run:

```bash
pytest .
```
