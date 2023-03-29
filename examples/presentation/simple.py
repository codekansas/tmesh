import math

from tmesh import Affine2D, linear_extrude, regular_polygon_mesh, save_stl, save_svg

# Create a square.
a = regular_polygon_mesh(1.0, n=4)
b = regular_polygon_mesh(1.0, n=4)

# Move the second square around.
rot = Affine2D(rot=math.pi / 4)
trans = Affine2D(trans=(0.0, 0.5))
b <<= rot @ trans

# Gets the union of A and B.
c = a | b

# Extrudes the 2D mesh to a 3D mesh with height 1.0.
mesh = linear_extrude(c, 1.0)

save_svg("simple.svg", c)
save_stl("simple.stl", mesh)
