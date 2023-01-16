from tmesh import Affine3D, cuboid, icosphere, save_stl, uv_sphere

num_iters = 4

mesh = cuboid(1.5 + 3 * (num_iters - 1) + 1.5, 1.0, 0.1)

for i in range(num_iters):
    icosphr = icosphere(radius=1.0, n=i)
    mesh &= icosphr << Affine3D(trans=(1.5 + 3.0 * i, 0.0, 2.0))

for i in range(num_iters):
    uvsphr = uv_sphere(radius=1.0, n=(i + 1) * 3, m=(i + 1) * 3)
    mesh &= uvsphr << Affine3D(trans=(1.5 + 3.0 * i, 0.0, -2.0))

# Save the result.
save_stl("sphere.stl", mesh)
