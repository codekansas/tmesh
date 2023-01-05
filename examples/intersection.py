import math

from fast_trimesh.fast_trimesh.cpu.io import save_stl_text
from fast_trimesh.fast_trimesh.cpu.shapes import tetrahedron
from fast_trimesh.fast_trimesh.cpu.types import Affine3D

tetr = tetrahedron(radius=1.0)

scale = Affine3D(scale=1.5)
trans = Affine3D(trans=(0.0, 0.0, -1.5))
rot = Affine3D(rot=(math.pi, 0.0, 0.0))

tetr_a = tetr
tetr_b = tetr << scale @ trans @ rot

# Save the result.
save_stl_text("intersection.stl", tetr_a & tetr_b)
