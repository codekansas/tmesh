from fast_trimesh.fast_trimesh.cpu.io import save_stl_text
from fast_trimesh.fast_trimesh.cpu.ops import linear_extrude
from fast_trimesh.fast_trimesh.cpu.shapes import regular_polygon

# Create a circle (approximated as a 20 sided polygon).
circ = regular_polygon(radius=1.0, n=20)

# Linear extrude the circle.
cyl = linear_extrude(circ, height=2.0)

# Save the result.
save_stl_text("cylinder.stl", cyl)
