"""Tests for the triangle split tree in 2D."""

import pytest

from tmesh import Face, Line2D, Point2D, Triangle2D, TriangleSplitTree2D


@pytest.mark.parametrize(
    "line,triangles",
    [
        (
            Line2D(Point2D(1, -1), Point2D(1, 3)),
            [
                Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(1, 1)),
                Triangle2D(Point2D(1, 0), Point2D(2, 0), Point2D(1, 1)),
                Triangle2D(Point2D(1, 1), Point2D(0, 2), Point2D(0, 0)),
            ],
        ),
        (
            Line2D(Point2D(-1, 1), Point2D(3, 1)),
            [
                Triangle2D(Point2D(1, 1), Point2D(0, 2), Point2D(0, 1)),
                Triangle2D(Point2D(2, 0), Point2D(1, 1), Point2D(0, 1)),
                Triangle2D(Point2D(0, 1), Point2D(0, 0), Point2D(2, 0)),
            ],
        ),
        (
            Line2D(Point2D(2, -1), Point2D(-1, 2)),
            [
                Triangle2D(Point2D(0, 1), Point2D(0, 0), Point2D(1, 0)),
                Triangle2D(Point2D(0, 2), Point2D(0, 1), Point2D(1, 0)),
                Triangle2D(Point2D(1, 0), Point2D(2, 0), Point2D(0, 2)),
            ],
        ),
    ],
)
def test_triangle_split_tree_2d_split_at_lines(line: Line2D, triangles: list[Triangle2D]) -> None:
    """Tests splitting a triangle into subtriangles along lines.

    Args:
        line: The line to use to split the triangles
        triangles: The triangles that result after splitting
    """

    # Create a triangle split tree.
    face = Face(0, 1, 2)
    vertices = [Point2D(0, 0), Point2D(2, 0), Point2D(0, 2)]
    tree = TriangleSplitTree2D(face, vertices)
    assert len(tree) == 1

    # Tests splitting the triangle along a line.
    tree.split_triangle(line, 0)
    assert len(tree) == 3

    # Checks the triangles which are next to the split line.
    leaf_triangles = tree.get_leaf_triangles_which_intersect(Line2D(Point2D(1, -1), Point2D(1, 3)))
    out_triangles = sorted([tree[i] for i in leaf_triangles])

    assert out_triangles == triangles


def test_triangle_split_tree_2d_split_at_lines_through_vertex() -> None:
    """Tests splitting a triangle for a line that passes through a vertex."""

    # Create a triangle split tree.
    face = Face(0, 1, 2)
    vertices = [Point2D(0, 0), Point2D(2, 0), Point2D(0, 2)]
    tree = TriangleSplitTree2D(face, vertices)
    assert len(tree) == 1

    # Tests splitting the triangle along a line.
    line = Line2D(Point2D(-1, -1), Point2D(3, 3))
    tree.split_triangle(line, 0)
    assert len(tree) == 2

    leaf_triangles = tree.get_leaf_triangles_which_intersect(line)
    triangles = sorted([tree[i] for i in leaf_triangles])

    assert triangles == [
        Triangle2D(Point2D(0, 0), Point2D(2, 0), Point2D(1, 1)),
        Triangle2D(Point2D(1, 1), Point2D(0, 2), Point2D(0, 0)),
    ]


@pytest.mark.parametrize(
    "line,triangles",
    [
        (
            Line2D(Point2D(-1, 1), Point2D(0, 1)),
            [
                Triangle2D(Point2D(0, 1), Point2D(0, 0), Point2D(2, 0)),
                Triangle2D(Point2D(0, 2), Point2D(0, 1), Point2D(2, 0)),
            ],
        ),
        (
            Line2D(Point2D(1, -1), Point2D(1, 0)),
            [
                Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 2)),
                Triangle2D(Point2D(1, 0), Point2D(2, 0), Point2D(0, 2)),
            ],
        ),
        (
            Line2D(Point2D(2, 2), Point2D(1, 1)),
            [
                Triangle2D(Point2D(1, 1), Point2D(0, 2), Point2D(0, 0)),
                Triangle2D(Point2D(2, 0), Point2D(1, 1), Point2D(0, 0)),
            ],
        ),
    ],
)
def test_triangle_split_tree_2d_split_at_lines_touches_edge(line: Line2D, triangles: list[Triangle2D]) -> None:
    """Tests splitting a triangle for a line that just touches an edge.

    Args:
        line: The line to use to split the triangles
        triangles: The triangles that result after splitting
    """

    # Create a triangle split tree.
    face = Face(0, 1, 2)
    vertices = [Point2D(0, 0), Point2D(2, 0), Point2D(0, 2)]
    tree = TriangleSplitTree2D(face, vertices)
    assert len(tree) == 1

    # Tests splitting the triangle along a line.
    tree.split_triangle(line, 0)
    assert len(tree) == 2

    leaf_triangles = tree.get_leaf_triangles_which_intersect(line)
    out_triangles = sorted([tree[i] for i in leaf_triangles])

    assert out_triangles == triangles
