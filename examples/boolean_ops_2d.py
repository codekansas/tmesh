"""An example of doing boolean operations on two-dimensional meshes."""

import math

from tmesh import Affine2D, linear_extrude, regular_polygon_mesh, save_stl

scale = Affine2D(scale=1.0)
rotate = Affine2D(rot=math.pi / 3)
# translate = Affine2D(trans=(0.75, 0.5))

# For some reason, using this translation causes the boolean operations to
# break.
translate = Affine2D(trans=(0.75, 0.0))

mesh = regular_polygon_mesh(1.0, n=3)

mesh_union = mesh & (mesh << scale @ rotate @ translate)
mesh_intersection = (mesh | (mesh << scale @ rotate @ translate)) << Affine2D(trans=(2.0, 0.0))
mesh_difference = (mesh - (mesh << scale @ rotate @ translate)) << Affine2D(trans=(-2.0, 0.0))

combined_mesh = mesh_union & mesh_intersection & mesh_difference
final_mesh = linear_extrude(combined_mesh, 1.0)

save_stl("boolean_ops_2d.stl", final_mesh)
