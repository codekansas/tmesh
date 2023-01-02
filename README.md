# Fast Trimesh

Fast boolean operators for triangular meshes.

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

Alternatively, if you have `cmake` and `pybind` available, you can install
the package directly from Github using:

```bash
pip install git+https://github.com/codekansas/fast-trimesh.git
```

## Getting Started

### Simple Script

The following script demonstrates how to use the package to generate an
STL or OBJ file from a simple mesh:

```python
import math

from fast_trimesh.fast_trimesh.cpu.io import save_obj, save_stl
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.fast_trimesh.cpu.trimesh import AffineTransformation

# Create some cuboids.
a = cuboid(1.0, 1.0, 1.0)
b = cuboid(1.0, 1.0, 1.0)

# Move the second cuboid around.
rot = AffineTransformation(rotation=(math.pi / 4, 0.0, 0.0))
trans = AffineTransformation(translation=(0.0, 0.5, 0.5))
b = b << rot << trans

# Save the resulting cuboid.
save_stl("cuboid.stl", a + b)
save_obj("cuboid.obj", a + b)
```

### Unit Tests

To see examples of different parts of the API, it is helpful to try running
the tests. To do so, after cloning the repository, run:

```bash
pytest .
```
