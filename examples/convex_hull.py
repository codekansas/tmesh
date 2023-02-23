"""Shows how to get the convex hull of a set of polygons."""

from tmesh import Affine2D, regular_polygon_mesh, save_svg

a = regular_polygon_mesh(radius=1.0, n=5)
b = regular_polygon_mesh(radius=1.0, n=6) << Affine2D(trans=(0.0, 4.0))
c = regular_polygon_mesh(radius=1.0, n=10) << Affine2D(trans=(4.0, 3.0))
union = (a | b | c)
pa, pb, pc = [p for p, _ in union.get_polygons()]
d = (pa + pb + pc).convex_hull().get_trimesh().make_delaunay() << Affine2D(scale=20.0)

# Save the result.
save_svg("convex_hull.svg", d)
