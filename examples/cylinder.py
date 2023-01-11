from fast_trimesh.cpu.io import save_stl
from fast_trimesh.cpu.ops import linear_extrude
from fast_trimesh.cpu.shapes import regular_polygon_mesh
from fast_trimesh.cpu.types import Affine3D

# Create a circle (approximated as a 20 sided polygon).
circ = regular_polygon_mesh(radius=1.0, n=20)

# Linear extrude the circle.
cyl = linear_extrude(circ, height=2.0)

# Linear extude the circle with a function.
cyl2 = linear_extrude(
    circ.subdivide(at_edges=True).subdivide(at_edges=True),
    height_func=lambda x, _: x**2 + 1,
) << Affine3D(trans=(0, 3, 0))

# Save the result.
save_stl("cylinder.stl", cyl & cyl2)
