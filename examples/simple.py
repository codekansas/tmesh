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
save_stl_text("simple.stl", a | b)
