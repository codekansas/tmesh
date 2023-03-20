"""Tests Delaunay triangulation in three dimensions."""

import random

import pytest

from tmesh import Point3D, triangulate_3d


@pytest.mark.parametrize("seed", [1337, 1338, 1339, 1340, 1341])
def test_simple_triangulate_3d(seed: int) -> None:
    """Tests Delaunay triangulation."""

    points = [
        Point3D(0, 0, 0),
        Point3D(1, 0, 0),
        Point3D(0, 1, 0),
        Point3D(0, 0, 1),
        Point3D(1, 1, 1),
    ]

    random.seed(seed)
    random.shuffle(points)

    tetramesh = triangulate_3d(points, shuffle=False)

    assert len(tetramesh.vertices) == 5
    assert len(tetramesh.volumes) in (2, 3)

    volumes = [t.signed_volume() for t in tetramesh.get_tetrahedra()]
    assert all(v > 0 for v in volumes)
    assert sum(volumes) == pytest.approx(0.5)


def test_random_triangulation() -> None:
    """Tests Delaunay triangulation."""

    random.seed(1337)
    points = [Point3D(*(random.random() for _ in range(3))) for _ in range(100)]

    tetramesh = triangulate_3d(points, shuffle=False)

    assert len(tetramesh.vertices) == 100

    volumes = [t.signed_volume() for t in tetramesh.get_tetrahedra()]
    assert all(v > 0 for v in volumes)


if __name__ == "__main__":
    # python -m tests.three.test_triangulate_3d
    # test_random_triangulation()
    for i in [1337, 1338, 1339, 1340, 1341]:
        test_simple_triangulate_3d(i)
