"""Tests boolean operations in two dimensions.

The validity of the assert statements can be checked using the plotting script.
"""

import math

from tmesh import Affine2D, regular_polygon_mesh


def test_union_2d() -> None:
    """Tests taking the union of two trimeshes."""

    scale = Affine2D(scale=1.0)
    rotate = Affine2D(rot=math.pi / 3)
    translate = Affine2D(trans=(0.75, 0.5))

    # Gets two regular polygons.
    mesh_a = regular_polygon_mesh(1.0, n=3)
    mesh_b = regular_polygon_mesh(1.0, n=3) << scale @ rotate @ translate

    # Checks the union of the two meshes.
    mesh_union = mesh_a & mesh_b
    assert len(mesh_union.faces) == 16
    assert len(mesh_union.vertices) == 12

    # Checks the intersection of the two meshes.
    mesh_intersection = mesh_a | mesh_b
    assert len(mesh_intersection.faces) == 4
    assert len(mesh_intersection.vertices) == 6

    # Checks the difference of the two meshes.
    mesh_difference = mesh_a - mesh_b
    assert len(mesh_difference.faces) == 6
    assert len(mesh_difference.vertices) == 7
