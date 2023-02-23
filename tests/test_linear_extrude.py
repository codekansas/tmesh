"""Tests linear extrude functions."""

import math

import pytest

from tmesh import linear_extrude, regular_polygon


def test_simple_linear_extrude() -> None:
    """Tests extruding a triangle to a tetrahedron."""

    mesh = regular_polygon(1.0, n=3).get_trimesh()
    extruded_mesh = linear_extrude(mesh, 1.0)

    assert len(extruded_mesh.vertices) == 6
    assert len(extruded_mesh.volumes) == 3

    # Checks that the tetrahedrons are all oriented correctly and have the
    # expected volume.
    for tetra in extruded_mesh.get_tetraherdons():
        assert tetra.signed_volume() == pytest.approx(math.sqrt(3) / 4)

    # Checks the triangular mesh.
    trimesh = extruded_mesh.to_trimesh()
    assert len(trimesh.vertices) == 6
    assert len(trimesh.faces) == 8


if __name__ == "__main__":
    test_simple_linear_extrude()
