"""Tests linear extrude functions."""

import pytest

from tmesh import linear_extrude, regular_polygon, regular_polygon_mesh


def test_simple_linear_extrude() -> None:
    """Tests extruding a triangle to a tetrahedron."""

    height = 2.0

    mesh = regular_polygon(1.0, n=3).get_trimesh()
    extruded_mesh = linear_extrude(mesh, height)

    exp_volume = sum(t.area() for t in mesh.get_triangles()) * height

    assert len(extruded_mesh.vertices) == 6
    assert len(extruded_mesh.volumes) == 3

    # Checks that the tetrahedrons are all oriented correctly and have the
    # expected volume.
    assert sum(abs(t.signed_volume()) for t in extruded_mesh.get_tetrahedra()) == pytest.approx(exp_volume)

    # Checks the triangular mesh.
    trimesh = extruded_mesh.to_trimesh()
    assert len(trimesh.vertices) == 6
    assert len(trimesh.faces) == 8


def test_linear_extrude_polygon() -> None:
    """Tests extruding a regular polygon."""

    height = 2.0
    num_vertices = 10

    mesh = regular_polygon_mesh(1.0, n=num_vertices)
    extruded_mesh = linear_extrude(mesh, height)

    exp_volume = sum(t.area() for t in mesh.get_triangles()) * height

    # Top and bottom vertices, plus a center vertex.
    assert len(extruded_mesh.vertices) == 2 * (num_vertices + 1)

    # Each vertex has a face, each face has three volumes.
    assert len(extruded_mesh.volumes) == 3 * num_vertices

    signed_volumes = [t.signed_volume() for t in extruded_mesh.get_tetrahedra()]
    assert all(v > 0 for v in signed_volumes)
    assert sum(signed_volumes) == pytest.approx(exp_volume)

    # Checks the triangular mesh.
    trimesh = extruded_mesh.to_trimesh()
    assert len(trimesh.vertices) == 2 * (num_vertices + 1)
    assert len(trimesh.faces) == 4 * num_vertices


if __name__ == "__main__":
    test_linear_extrude_polygon()
