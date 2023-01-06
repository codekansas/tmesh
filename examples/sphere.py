from fast_trimesh.cpu.io import save_stl_text
from fast_trimesh.cpu.shapes import cuboid, icosphere, uv_sphere
from fast_trimesh.cpu.types import Affine3D

num_iters = 5

mesh = cuboid(1.5 + 3 * (num_iters - 1) + 1.5, 1.0, 0.1)

for i in range(num_iters):
    icosphr = icosphere(radius=1.0, n=i)
    mesh &= icosphr << Affine3D(trans=(1.5 + 3.0 * i, 0.0, 2.0))

for i in range(num_iters):
    uvsphr = uv_sphere(radius=1.0, n=(i + 1) * 3, m=(i + 1) * 3)
    mesh &= uvsphr << Affine3D(trans=(1.5 + 3.0 * i, 0.0, -2.0))

# Save the result.
save_stl_text("sphere.stl", mesh)
