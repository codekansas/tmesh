import math

from fast_trimesh.fast_trimesh.cpu.io import save_stl_text
from fast_trimesh.fast_trimesh.cpu.ops import rotate_extrude
from fast_trimesh.fast_trimesh.cpu.shapes import regular_polygon
from fast_trimesh.fast_trimesh.cpu.types import Affine2D

# Create a circle (approximated as a 20 sided polygon).
circ = regular_polygon(radius=1.0, n=20) << Affine2D(trans=(0.0, 2.0))

# Rotate extrude the circle.
torus_a = rotate_extrude(circ, angle=3 * math.pi / 2, n=20)

circ <<= Affine2D(trans=(-5.0, 0.0))
torus_b = rotate_extrude(circ, n=20, axis=1)

# Save the result.
save_stl_text("torus.stl", torus_a + torus_b)
