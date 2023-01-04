"""Tests boundary volume hierarchy (BVH) acceleration structure for CPU."""

from fast_trimesh.fast_trimesh.cpu.bvh import BoundaryVolumeHierarchy
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.fast_trimesh.cpu.types import BoundingBox3D, Line3D, Point3D


def test_simple_bvh() -> None:
    """Creates a cuboid, builds BVH, and tests ray intersection."""

    # Creates a cuboid.
    trimesh = cuboid(1.0, 2.0, 3.0)

    # Builds BVH.
    bvh = BoundaryVolumeHierarchy(trimesh)

    assert bvh.tree == [
        (6, 1, 6, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        (4, 2, 4, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        (3, -1, 3, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 0, 3))),
        (2, -1, -1, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 0, 3))),
        (5, -1, 5, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        (1, -1, -1, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 0))),
        (9, 7, 9, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        (8, -1, 8, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        (7, -1, -1, BoundingBox3D(Point3D(0, 2, 0), Point3D(1, 2, 3))),
        (11, 10, 11, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        (10, -1, -1, BoundingBox3D(Point3D(0, 0, 3), Point3D(1, 2, 3))),
        (0, -1, -1, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 0))),
    ]

    assert len(bvh.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(2.0, 0.25, 0.25)))) == 2
    assert len(bvh.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(0.5, 0.25, 0.25)))) == 1
    assert len(bvh.intersections(Line3D(Point3D(0.5, 0.25, 0.25), Point3D(2.0, 0.25, 0.25)))) == 1
