"""Tests boundary volume hierarchy (BVH) acceleration structure for CPU."""

from fast_trimesh.fast_trimesh.cpu.bvh import BoundaryVolumeHierarchy
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid


def test_simple_bvh() -> None:
    """Creates a cuboid, builds BVH, and tests ray intersection."""

    # Creates a cuboid.
    trimesh = cuboid(1.0, 2.0, 3.0)

    # Builds BVH.
    bvh = BoundaryVolumeHierarchy(trimesh)

    breakpoint()

    # TODO: Fix this, it is wrong.
    assert bvh.tree == [
        (6, 1, 6, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (3, 2, 3, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (2, 2, 2, ((0.0, 0.0, 0.0), (1.0, 0.0, 3.0))),
        (4, 4, 4, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (5, 5, 5, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (1, 5, 5, ((0.0, 0.0, 0.0), (1.0, 2.0, 0.0))),
        (9, 7, 9, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (8, 8, 8, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (7, 8, 8, ((0.0, 2.0, 0.0), (1.0, 2.0, 3.0))),
        (10, 10, 10, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (11, 11, 11, ((0.0, 0.0, 0.0), (1.0, 2.0, 3.0))),
        (0, 11, 11, ((0.0, 0.0, 0.0), (1.0, 2.0, 0.0))),
    ]
