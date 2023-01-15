from fast_trimesh import Affine2D, linear_extrude, regular_polygon, save_stl

a = regular_polygon(radius=1.0, n=5)
b = regular_polygon(radius=1.0, n=6) << Affine2D(trans=(0.0, 4.0))
c = regular_polygon(radius=1.0, n=10) << Affine2D(trans=(4.0, 3.0))
d = (a + b + c).convex_hull()
e = (
    linear_extrude(d, height=1.0)
    & linear_extrude(a, height=2.0)
    & linear_extrude(b, height=2.0)
    & linear_extrude(c, height=2.0)
)

# Save the result.
save_stl("convex_hull.stl", e)
