"""Tests boundary volume hierarchy (BVH) acceleration structure for CPU."""

from fast_trimesh.fast_trimesh.cpu.bvh import BoundaryVolumeHierarchy
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid


def test_simple_bvh() -> None:
    """Creates a cuboid, builds BVH, and tests ray intersection."""

    # Creates a cuboid.
    trimesh = cuboid(1.0, 2.0, 3.0)

    # Builds BVH.
    bvh = BoundaryVolumeHierarchy(trimesh)

    assert bvh.tree == [
        (6, 1, 6, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (4, 2, 4, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (3, -1, 3, ((0.0, 0.0, 0.0), (1.0, 0.0, 3.0))),
        (2, -1, -1, ((0.0, 0.0, 0.0), (1.0, 0.0, 3.0))),
        (5, -1, 5, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (1, -1, -1, ((0.0, 0.0, 0.0), (1.0, 2.0, 0.0))),
        (9, 7, 9, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (8, -1, 8, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (7, -1, -1, ((0.0, 2.0, 0.0), (1.0, 2.0, 3.0))),
        (11, 10, 11, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (10, -1, -1, ((0.0, 0.0, 3.0), (1.0, 2.0, 3.0))),
        (0, -1, -1, ((0.0, 0.0, 0.0), (1.0, 2.0, 0.0))),
    ]

    assert set(bvh.intersections(((0.0, 0.0, 0.0), (1.0, 0.0, 0.0)))) == {9}
