from tmesh import Face, Line2D, Point2D, Triangle2D, TriangleSplitTree2D


def test_triangle_split_tree_2d_split_at_points() -> None:
    """Tests splitting a triangle into subtriangles at points."""

    # Create a triangle split tree.
    face = Face(0, 1, 2)
    vertices = [Point2D(0, 0), Point2D(1, 0), Point2D(0, 1)]
    tree = TriangleSplitTree2D(face, vertices)
    assert len(tree) == 1

    # Tests splitting the triangle at a point.
    tree.split_triangle_at_point(Point2D(0.25, 0.25), 0)
    assert len(tree) == 3

    # Check the triangles which intersect the split point.
    leaf_triangles = tree.get_leaf_triangles_which_intersect_point(Point2D(0.25, 0.25))
    assert len(leaf_triangles) == 3
    triangles = sorted([tree[i] for i in leaf_triangles], key=lambda t: (t.p1, t.p2, t.p3))
    assert triangles == [
        Triangle2D(Point2D(0, 1), Point2D(0.25, 0.25), Point2D(0, 0)),
        Triangle2D(Point2D(0.25, 0.25), Point2D(0, 0), Point2D(1, 0)),
        Triangle2D(Point2D(0.25, 0.25), Point2D(1, 0), Point2D(0, 1)),
    ]

    # Check the triangles which intersect another point.
    leaf_triangles = tree.get_leaf_triangles_which_intersect_point(Point2D(0.5, 0.25))
    assert len(leaf_triangles) == 1
    assert tree[leaf_triangles[0]] == Triangle2D(Point2D(0.25, 0.25), Point2D(1, 0), Point2D(0, 1))

    # Splits a triangle at another point.
    tree.split_triangle_at_point(Point2D(0.5, 0.25), leaf_triangles[0])
    assert len(tree) == 5

    # Check the triangles which intersect the split point.
    leaf_triangles = tree.get_leaf_triangles_which_intersect_point(Point2D(0.5, 0.25))
    assert len(leaf_triangles) == 3
    triangles = sorted([tree[i] for i in leaf_triangles], key=lambda t: (t.p1, t.p2, t.p3))
    assert triangles == [
        Triangle2D(Point2D(0, 1), Point2D(0.5, 0.25), Point2D(0.25, 0.25)),
        Triangle2D(Point2D(0.5, 0.25), Point2D(0.25, 0.25), Point2D(1, 0)),
        Triangle2D(Point2D(0.5, 0.25), Point2D(1, 0), Point2D(0, 1)),
    ]


def test_triangle_split_tree_2d_split_at_lines() -> None:
    """Tests splitting a triangle into subtriangles along lines."""

    # Create a triangle split tree.
    face = Face(0, 1, 2)
    vertices = [Point2D(0, 0), Point2D(2, 0), Point2D(0, 2)]
    tree = TriangleSplitTree2D(face, vertices)
    assert len(tree) == 1

    # Tests splitting the triangle along a line.
    tree.split_triangle_at_line(Line2D(Point2D(1, -1), Point2D(1, 3)), 0)
    assert len(tree) == 3

    # Checks the triangles which are next to the split line.
    leaf_triangles = tree.get_leaf_triangles_which_intersect_line(Line2D(Point2D(1, -1), Point2D(1, 3)))
    triangles = sorted([tree[i] for i in leaf_triangles])

    assert triangles == [
        Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(1, 1)),
        Triangle2D(Point2D(1, 0), Point2D(2, 0), Point2D(1, 1)),
        Triangle2D(Point2D(1, 1), Point2D(0, 2), Point2D(0, 0)),
    ]


def test_triangle_split_tree_2d_split_at_lines_through_vertex() -> None:
    """Tests splitting a triangle for a line that passes through a vertex."""

    # Create a triangle split tree.
    face = Face(0, 1, 2)
    vertices = [Point2D(0, 0), Point2D(2, 0), Point2D(0, 2)]
    tree = TriangleSplitTree2D(face, vertices)
    assert len(tree) == 1

    # Tests splitting the triangle along a line.
    tree.split_triangle_at_line(Line2D(Point2D(-1, -1), Point2D(3, 3)), 0)
    assert len(tree) == 2

    leaf_triangles = tree.get_leaf_triangles_which_intersect_line(Line2D(Point2D(-1, -1), Point2D(3, 3)))
    triangles = sorted([tree[i] for i in leaf_triangles])

    assert triangles == [
        Triangle2D(Point2D(0, 0), Point2D(2, 0), Point2D(1, 1)),
        Triangle2D(Point2D(1, 1), Point2D(0, 2), Point2D(0, 0)),
    ]


def test_triangle_split_tree_2d_split_at_lines_touches_edge() -> None:
    """Tests splitting a triangle for a line that just touches an edge."""

    # Create a triangle split tree.
    face = Face(0, 1, 2)
    vertices = [Point2D(0, 0), Point2D(2, 0), Point2D(0, 2)]
    tree = TriangleSplitTree2D(face, vertices)
    assert len(tree) == 1

    # Tests splitting the triangle along a line.
    tree.split_triangle_at_line(Line2D(Point2D(-1, 1), Point2D(0, 1)), 0)
    assert len(tree) == 2

    leaf_triangles = tree.get_leaf_triangles_which_intersect_line(Line2D(Point2D(-1, 1), Point2D(0, 1)))
    triangles = sorted([tree[i] for i in leaf_triangles])

    assert triangles == [
        Triangle2D(Point2D(0, 1), Point2D(0, 0), Point2D(2, 0)),
        Triangle2D(Point2D(0, 2), Point2D(0, 1), Point2D(2, 0)),
    ]
