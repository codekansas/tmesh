"""Tests axis aligned bounding box data structure for CPU."""

from fast_trimesh.cpu.aabb_tree import AABBTree3D
from fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.cpu.types import Line3D, Point3D


def test_simple_aabb_tree_3d() -> None:
    """Creates a cuboid, builds AABB tree, and tests ray intersection."""

    # Creates a cuboid.
    trimesh = cuboid(1.0, 2.0, 3.0)

    # Builds AABB tree.
    aabb_tree = AABBTree3D(trimesh)

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

    intrs = sorted(aabb_tree.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(2.0, 0.25, 0.25))))
    assert intrs == [((1, 2, 6), Point3D(1, 0.25, 0.25)), ((3, 0, 4), Point3D(0, 0.25, 0.25))]

    intrs = sorted(aabb_tree.intersections(Line3D(Point3D(-1.0, 0.25, 0.25), Point3D(0.5, 0.25, 0.25))))
    assert intrs == [((3, 0, 4), Point3D(0, 0.25, 0.25))]

    intrs = sorted(aabb_tree.intersections(Line3D(Point3D(0.5, 0.25, 0.25), Point3D(2.0, 0.25, 0.25))))
    assert intrs == [((1, 2, 6), Point3D(1, 0.25, 0.25))]

    intrs = sorted(aabb_tree.intersections(Line3D(Point3D(0.0, 0.25, 0.25), Point3D(1.0, 0.25, 0.25))))
    assert intrs == [((1, 2, 6), Point3D(1, 0.25, 0.25)), ((3, 0, 4), Point3D(0, 0.25, 0.25))]
