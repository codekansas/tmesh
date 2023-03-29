from tmesh import linear_extrude, regular_polygon_mesh, save_stl, save_svg

mesh_2d = regular_polygon_mesh(1.0, n=20).subdivide().subdivide()
mesh_3d = linear_extrude(mesh_2d, height_func=lambda x, y: x ** 2 + y ** 2 + 1)
save_svg("linear_extrude.svg", mesh_2d)
save_stl("linear_extrude.stl", mesh_3d)
