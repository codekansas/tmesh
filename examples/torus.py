import math

from fast_trimesh import Affine2D, regular_polygon, rotate_extrude, save_stl

# Create a circle (approximated as a 20 sided polygon).
circ = regular_polygon(radius=1.0, n=20) << Affine2D(trans=(0.0, 2.0))

# Rotate extrude the circle.
torus_a = rotate_extrude(circ, angle=3 * math.pi / 2, n=10)

circ <<= Affine2D(trans=(10.0, 0.0))
torus_b = rotate_extrude(circ, n=10, axis=1)

# Save the result.
save_stl("torus.stl", torus_a | torus_b)
