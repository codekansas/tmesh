"""Example of using subdivide and linear extrude to create weird cylinders."""

from tmesh import linear_extrude, regular_polygon_mesh

from .base import Registry

# Create a circle (approximated as a 20 sided polygon).
circ = regular_polygon_mesh(radius=1.0, n=20)

# Linear extrude the circle.
cyl = linear_extrude(
    circ.subdivide().subdivide(),
    height_func=lambda _, y: y**3 + 1.5,
)

# Save the result.
# save_stl("cylinder.stl", cyl)
Registry.add_item("cylinder", cyl)
