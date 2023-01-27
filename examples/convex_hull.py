"""Shows how to get the convex hull of a set of polygons."""

from tmesh import Affine2D, linear_extrude, regular_polygon_mesh, save_stl

a = regular_polygon_mesh(radius=1.0, n=5)
b = regular_polygon_mesh(radius=1.0, n=6) << Affine2D(trans=(0.0, 4.0))
c = regular_polygon_mesh(radius=1.0, n=10) << Affine2D(trans=(4.0, 3.0))
union = a | b | c
pa, pb, pc = [p for p, _ in union.get_polygons()]
d = (pa + pb + pc).convex_hull()
e = linear_extrude(d, height=1.0) | linear_extrude(union, height=2.0)

# Save the result.
save_stl("convex_hull.stl", e)
