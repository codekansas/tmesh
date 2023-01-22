import math

import pytest

from tmesh import Affine2D, regular_polygon_mesh


@pytest.mark.skip("Not implemented yet")
def test_union_2d() -> None:
    """Tests taking the union of two trimeshes."""

    scale = Affine2D(scale=1.0)
    rotate = Affine2D(rot=math.pi / 3)
    translate = Affine2D(trans=(0.5, 0.5))

    # Gets two regular polygons.
    mesh_a = regular_polygon_mesh(1.0, n=3)
    mesh_b = regular_polygon_mesh(1.0, n=3) << scale @ rotate @ translate

    mesh_union = mesh_a & mesh_b
    mesh_intersection = mesh_a | mesh_b
    mesh_difference = mesh_a - mesh_b

    assert len(mesh_union.vertices) == 6
    assert len(mesh_intersection.vertices) == 3
    assert len(mesh_difference.vertices) == 3


if __name__ == "__main__":
    test_union_2d()
