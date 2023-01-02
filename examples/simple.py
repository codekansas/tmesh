import math

from fast_trimesh.fast_trimesh.cpu.io import save_stl_text
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
save_stl_text("simple.stl", a + b)
