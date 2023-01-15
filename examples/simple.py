import math

from fast_trimesh import Affine3D, cuboid, save_stl

# Create some cuboids.
a = cuboid(1.0, 1.0, 1.0, center=True)
b = cuboid(1.0, 1.0, 1.0, center=True)

# Move the second cuboid around.
rot = Affine3D(rot=(math.pi / 4, 0.0, 0.0))
trans = Affine3D(trans=(0.0, 0.5, 0.0))
b <<= rot @ trans

# Save the resulting cuboid.
save_stl("simple.stl", a | b)
