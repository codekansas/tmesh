import math

import pytest

from tmesh import Affine3D, tetrahedron


@pytest.mark.skip("Not implemented yet")
def test_union_3d() -> None:
    """Tests taking the union of two trimeshes."""

    scale = Affine3D(scale=1.5)
    trans = Affine3D(trans=(0.0, 0.0, -1.5))
    rot = Affine3D(rot=(math.pi, 0.0, math.pi / 4))

    tetr = tetrahedron(radius=1.0)
    mesh_a = tetr
    mesh_b = tetr << scale @ trans @ rot

    mesh_union = mesh_a & mesh_b
    mesh_intersection = mesh_a | mesh_b
    mesh_difference = mesh_a - mesh_b

    assert len(mesh_union.vertices) == 12
    assert len(mesh_intersection.vertices) == 4
    assert len(mesh_difference.vertices) == 8


if __name__ == "__main__":
    test_union_3d()
