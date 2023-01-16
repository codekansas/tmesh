"""Tests axis aligned bounding box data structure for CPU."""

from tmesh import BVH2D, Point2D, Triangle2D, regular_polygon_mesh


def test_simple_bvh_tree_2d() -> None:
    """Creates a square, builds BVH tree, and tests ray intersection."""

    # Creates a square.
    trimesh = regular_polygon_mesh(1.0, 4)

    assert trimesh.vertices == [
        Point2D(0, 0),
        Point2D(1, 0),
        Point2D(0, 1),
        Point2D(-1, 0),
        Point2D(0, -1),
    ]

    # Builds BVH tree.
    bvh = BVH2D(trimesh)

    # Tests intersection with a triangle that is a line.
    triangle = Triangle2D(Point2D(-1.0, 0.25), Point2D(2.0, 0.25), Point2D(0.5, 0.25))
    intrs = sorted(bvh.intersections(triangle))
    assert intrs == [(0, 1, 2), (0, 2, 3)]

    # Tests intersection with all four triangles.
    triangle = Triangle2D(Point2D(-1.0, 0.5), Point2D(1.0, 0.5), Point2D(0.0, -0.5))
    intrs = sorted(bvh.intersections(triangle))
    assert intrs == [(0, 1, 2), (0, 2, 3), (0, 3, 4), (0, 4, 1)]

    # Tests intersection with a single triangle.
    triangle = Triangle2D(Point2D(1.0, 0.25), Point2D(0.25, 1.0), Point2D(0.25, 0.25))
    intrs = sorted(bvh.intersections(triangle))
    assert intrs == [(0, 1, 2)]

    # Tests intersection a corner with an edge.
    triangle = Triangle2D(Point2D(1.0, 0.5), Point2D(0.5, 1.0), Point2D(0.5, 0.5))
    intrs = sorted(bvh.intersections(triangle))
    assert intrs == [(0, 1, 2)]

    # Tests intersection at two corners.
    triangle = Triangle2D(Point2D(-1.0, 2.0), Point2D(1.0, 2.0), Point2D(0.0, 1.0))
    intrs = sorted(bvh.intersections(triangle))
    assert intrs == [(0, 1, 2), (0, 2, 3)]
