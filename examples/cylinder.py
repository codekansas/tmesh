from fast_trimesh import Affine3D, linear_extrude, regular_polygon_mesh, save_stl

# Create a circle (approximated as a 20 sided polygon).
circ = regular_polygon_mesh(radius=1.0, n=20)

# Linear extrude the circle.
cyl = linear_extrude(
    circ.subdivide().subdivide(),
    height_func=lambda _, y: y**3 + 1.5,
)

# Linear extude the circle with a function.
cyl2 = linear_extrude(
    circ.subdivide().subdivide(),
    height_func=lambda x, _: x**2 + 0.5,
) << Affine3D(trans=(0, 3, 0))

# Save the result.
save_stl("cylinder.stl", cyl & cyl2)
