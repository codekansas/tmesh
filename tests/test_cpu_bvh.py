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

    assert trimesh.vertices == [
        Point3D(0, 0, 0),
        Point3D(1, 0, 0),
        Point3D(1, 2, 0),
        Point3D(0, 2, 0),
        Point3D(0, 0, 3),
        Point3D(1, 0, 3),
        Point3D(1, 2, 3),
        Point3D(0, 2, 3),
    ]

    # Need to diagnose why this tree looks the way it does; it doesn't seem
    # balanced at all (child nodes are not evenly distributed).
    assert bvh.tree == [
        ((2, 3, 7), 1, 6, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        ((1, 2, 6), 2, 4, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        ((0, 5, 4), -1, 3, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 0, 3))),
        ((0, 1, 5), -1, -1, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 0, 3))),
        ((1, 6, 5), -1, 5, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        ((0, 3, 2), -1, -1, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 0))),
        ((3, 4, 7), 7, 9, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        ((3, 0, 4), -1, 8, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        ((2, 7, 6), -1, -1, BoundingBox3D(Point3D(0, 2, 0), Point3D(1, 2, 3))),
        ((4, 6, 7), 10, 11, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 3))),
        ((4, 5, 6), -1, -1, BoundingBox3D(Point3D(0, 0, 3), Point3D(1, 2, 3))),
        ((0, 2, 1), -1, -1, BoundingBox3D(Point3D(0, 0, 0), Point3D(1, 2, 0))),
    ]

    intrs = sorted(bvh.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(2.0, 0.25, 0.25))))
    assert intrs == [((1, 2, 6), Point3D(1, 0.25, 0.25)), ((3, 0, 4), Point3D(0, 0.25, 0.25))]

    intrs = sorted(bvh.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(0.5, 0.25, 0.25))))
    assert intrs == [((3, 0, 4), Point3D(0, 0.25, 0.25))]

    intrs = sorted(bvh.intersections(Line3D(Point3D(0.5, 0.25, 0.25), Point3D(2.0, 0.25, 0.25))))
    assert intrs == [((1, 2, 6), Point3D(1, 0.25, 0.25))]
