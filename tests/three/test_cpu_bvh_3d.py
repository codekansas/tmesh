"""Tests axis aligned bounding box data structure for CPU."""

from fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.cpu.three.bvh import BVH
from fast_trimesh.cpu.types import Line3D, Point3D


def test_simple_aabb_tree_3d() -> None:
    """Creates a cuboid, builds AABB tree, and tests ray intersection."""

    # Creates a cuboid.
    trimesh = cuboid(1.0, 2.0, 3.0)

    # Builds AABB tree.
    bvh = BVH(trimesh)

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

    intrs = sorted(bvh.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(2.0, 0.25, 0.25))))
    assert intrs == [(1, (3, 0, 4), Point3D(0, 0.25, 0.25)), (5, (1, 2, 6), Point3D(1, 0.25, 0.25))]

    intrs = sorted(bvh.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(0.5, 0.25, 0.25))))
    assert intrs == [(1, (3, 0, 4), Point3D(0, 0.25, 0.25))]

    intrs = sorted(bvh.intersections(Line3D(Point3D(0.5, 0.25, 0.25), Point3D(2.0, 0.25, 0.25))))
    assert intrs == [(5, (1, 2, 6), Point3D(1, 0.25, 0.25))]

    intrs = sorted(bvh.intersections(Line3D(Point3D(0.0, 0.25, 0.25), Point3D(1.0, 0.25, 0.25))))
    assert intrs == [(1, (3, 0, 4), Point3D(0, 0.25, 0.25)), (5, (1, 2, 6), Point3D(1, 0.25, 0.25))]

    intrs = sorted(bvh.intersections(Line3D(Point3D(0.0, 0.0, 0.0), Point3D(1.0, 2.0, 3.0))))
    assert intrs == [
        (0, (4, 5, 6), Point3D(1, 2, 3)),
        (1, (3, 0, 4), Point3D(0, 0, 0)),
        (4, (4, 6, 7), Point3D(1, 2, 3)),
        (5, (1, 2, 6), Point3D(1, 2, 3)),
        (6, (1, 6, 5), Point3D(1, 2, 3)),
        (7, (0, 1, 5), Point3D(0, 0, 0)),
        (8, (0, 5, 4), Point3D(0, 0, 0)),
        (9, (0, 3, 2), Point3D(0, 0, 0)),
        (10, (2, 7, 6), Point3D(1, 2, 3)),
        (11, (0, 2, 1), Point3D(0, 0, 0)),
    ]

    intrs = sorted(bvh.intersections(Line3D(Point3D(-1.0, -2.0, 1.0), Point3D(2.0, 4.0, 1.0))))
    assert intrs == [
        (1, (3, 0, 4), Point3D(0, 0, 1)),
        (5, (1, 2, 6), Point3D(1, 2, 1)),
        (8, (0, 5, 4), Point3D(0, 0, 1)),
        (10, (2, 7, 6), Point3D(1, 2, 1)),
    ]
