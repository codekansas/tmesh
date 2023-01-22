import math

from tmesh import Affine3D, save_stl, tetrahedron

scale = Affine3D(scale=1.5)
trans = Affine3D(trans=(0.0, 0.0, -1.5))
rot = Affine3D(rot=(math.pi, 0.0, math.pi / 4))

tetr = tetrahedron(radius=1.0)
tetr_a = tetr
tetr_b = tetr << scale @ trans @ rot

# Save the result.
save_stl("intersection.stl", tetr_a & tetr_b)
