import math

from fast_trimesh.cpu.boolean import TrimeshAdjacency
from fast_trimesh.cpu.io import save_stl_text
from fast_trimesh.cpu.shapes import cuboid, tetrahedron
from fast_trimesh.cpu.types import Affine3D

scale = Affine3D(scale=1.5)
trans = Affine3D(trans=(0.0, 0.0, -1.5))
rot = Affine3D(rot=(math.pi, 0.0, 0.0))

tetr = tetrahedron(radius=1.0)
tetr_a = tetr
tetr_b = tetr << scale @ trans @ rot

# Save the result.
save_stl_text("intersection.stl", tetr_a & tetr_b)

# cub_a = cuboid(2.0, 2.0, 2.0)
# cub_b = cuboid(2.0, 2.0, 2.0) << Affine3D(trans=(1, 1, 1))

# TrimeshAdjacency(cub_a).validate()

# save_stl_text("intersection.stl", cub_a & cub_b)
