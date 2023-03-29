from tmesh import Affine2D, regular_polygon_mesh, save_svg

pentagon = regular_polygon_mesh(500.0, n=5) << Affine2D(trans=(250.0, 0.0))
circle = regular_polygon_mesh(500.0, n=50) << Affine2D(trans=(0.0, 0.0))
union = pentagon | circle
delaunay_union = union.make_delaunay()

save_svg("not_delaunay.svg", union)
save_svg("delaunay.svg", delaunay_union)
