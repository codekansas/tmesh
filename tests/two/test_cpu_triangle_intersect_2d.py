from tmesh import Point2D, Triangle2D, TriangleSplitTree2D


def test_triangle_split_tree_2d() -> None:
    """Tests the triangle split tree implementation."""

    triangle = Triangle2D(Point2D(0.0, 0.0), Point2D(1.0, 0.0), Point2D(0.0, 1.0))
    tree = TriangleSplitTree2D(triangle)
    assert tree[0] == (triangle, [])

    # Splits the root triangle into 4 subtriangles.
    sub_triangles = [
        Triangle2D(Point2D(0.0, 0.0), Point2D(0.5, 0.0), Point2D(0.0, 0.5)),
        Triangle2D(Point2D(0.5, 0.0), Point2D(1.0, 0.0), Point2D(0.5, 0.5)),
        Triangle2D(Point2D(0.0, 0.5), Point2D(0.5, 0.5), Point2D(0.0, 1.0)),
        Triangle2D(Point2D(0.5, 0.5), Point2D(0.0, 0.5), Point2D(0.5, 0.0)),
    ]
    for sub_triangle in sub_triangles:
        tree.add_triangle(sub_triangle, 0)
    assert tree[0] == (triangle, [1, 2, 3, 4])
    assert tree[1] == (sub_triangles[0], [])
    assert tree[2] == (sub_triangles[1], [])
    assert tree[3] == (sub_triangles[2], [])
    assert tree[4] == (sub_triangles[3], [])
