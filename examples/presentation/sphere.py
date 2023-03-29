"""Example of icospheres and UV spheres."""

from tmesh import icosphere, save_stl, uv_sphere

i = 3

icosphr = icosphere(radius=1.0, n=i)
uvsphr = uv_sphere(radius=1.0, n=(i + 1) * 3, m=(i + 1) * 3)

# Save the result.
save_stl("icosphere.stl", icosphr)
save_stl("uv_sphere.stl", uvsphr)
