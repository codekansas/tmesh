"""Tests Delaunay triangulation in three dimensions."""

from tmesh import Point3D, triangulate_3d


def test_simple_triangulate_3d() -> None:
    """Tests Delaunay triangulation."""

    points = [
        Point3D(0, 0, 0),
        Point3D(1, 0, 0),
        Point3D(0, 1, 0),
        Point3D(0, 0, 1),
        Point3D(1, 1, 1),
    ]

    tetramesh = triangulate_3d(points, shuffle=False)

    assert len(tetramesh.vertices) == 5
    assert len(tetramesh.volumes) == 2

    volumes = [t.signed_volume() for t in tetramesh.get_tetrahedra()]
    assert all(v > 0 for v in volumes)
    sum(volumes)
