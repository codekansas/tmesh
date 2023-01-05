"""Test CPU types."""

import math

import pytest

from fast_trimesh.fast_trimesh.cpu.types import (
    Affine3D,
    Angle,
    BoundingBox2D,
    Line2D,
    Line3D,
    Point2D,
    Point3D,
    Polygon2D,
    Triangle2D,
    Triangle3D,
)

SQRT_2 = math.sqrt(2)
SQRT_3 = math.sqrt(3)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point2D(1, 0), math.pi / 2, Point2D(0, 1)),
        (Point2D(1, 0), math.pi, Point2D(-1, 0)),
        (Point2D(0, 1), math.pi / 2, Point2D(-1, 0)),
        (Point2D(0, 1), 3 * math.pi / 2, Point2D(1, 0)),
        (Point2D(0, 1), 2 * math.pi, Point2D(0, 1)),
    ],
)
def test_rotate_2d(lhs: Point2D, rhs: float, expected: Point2D) -> None:
    """Test rotation of a point in 2D.

    Args:
        lhs: The point.
        rhs: The angle.
        expected: The expected point.
    """

    result = lhs.rotate(rhs)
    assert result == expected


def test_bboxes_2d_from_points() -> None:
    """Test bounding box from points in 2D."""

    points = [
        Point2D(0, 0),
        Point2D(1, 0),
        Point2D(0, 1),
        Point2D(1, 1),
    ]
    bbox = BoundingBox2D(points)
    assert bbox.min == Point2D(0, 0)
    assert bbox.max == Point2D(1, 1)


def test_bboxes_2d_from_lines() -> None:
    """Test bounding box from lines in 2D."""

    lines = [
        Line2D(Point2D(0, 0), Point2D(1, 0)),
        Line2D(Point2D(0, 1), Point2D(1, 1)),
    ]
    bbox = BoundingBox2D(lines)
    assert bbox.min == Point2D(0, 0)
    assert bbox.max == Point2D(1, 1)


def test_bboxes_2d_from_triangles() -> None:
    """Test bounding box from triangles in 2D."""

    triangles = [
        Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1)),
        Triangle2D(Point2D(0, 0), Point2D(1, 1), Point2D(0, 1)),
    ]
    bbox = BoundingBox2D(triangles)
    assert bbox.min == Point2D(0, 0)
    assert bbox.max == Point2D(1, 1)


def test_bboxes_2d_from_bboxes() -> None:
    """Test bounding box from bounding boxes in 2D."""

    bboxes = [
        BoundingBox2D(Point2D(0, 0), Point2D(1, 1)),
        BoundingBox2D(Point2D(1, 1), Point2D(2, 2)),
    ]
    bbox = BoundingBox2D(bboxes)
    assert bbox.min == Point2D(0, 0)
    assert bbox.max == Point2D(2, 2)


def test_affine_transformations() -> None:
    """Test affine transformations."""

    point = Point3D(1, 0, 0)

    scaled = Affine3D(scale=2.0) >> point
    assert scaled == Point3D(2, 0, 0)

    rot_x = Affine3D(rot=(math.pi / 2, 0.0, 0.0)) >> point
    assert rot_x == Point3D(1, 0, 0)

    rot_y = Affine3D(rot=(0.0, math.pi / 2, 0.0)) >> point
    assert rot_y == Point3D(0, 0, -1)

    rot_z = Affine3D(rot=(0.0, 0.0, math.pi / 2)) >> point
    assert rot_z == Point3D(0, 1, 0)

    rot_xyz = Affine3D(rot=(math.pi / 2, math.pi / 2, math.pi / 2)) >> point
    assert rot_xyz == Point3D(0, 0, 1)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point2D(0, 0), Point2D(1, 0), 1),
        (Point2D(0, 0), Point2D(0, 1), 1),
        (Point2D(0, 0), Point2D(1, 1), SQRT_2),
        (Point3D(0, 0, 0), Point3D(1, 0, 0), 1),
        (Point3D(0, 0, 0), Point3D(0, 1, 0), 1),
        (Point3D(0, 0, 0), Point3D(0, 0, 1), 1),
        (Point3D(0, 0, 0), Point3D(1, 1, 1), SQRT_3),
    ],
)
def test_distance(lhs: Point2D | Point3D, rhs: Point2D | Point3D, expected: float) -> None:
    """Test distance between two points.

    Args:
        lhs: The first point.
        rhs: The second point.
        expected: The expected distance.
    """

    assert lhs.distance_to_point(rhs) == pytest.approx(expected)  # type: ignore


@pytest.mark.parametrize(
    "lhs,expected",
    [
        (Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1)), 0.5),
        (Triangle2D(Point2D(0, 0), Point2D(0, 1), Point2D(1, 0)), 0.5),
        (Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(1, 1)), 0.5),
        (Triangle2D(Point2D(0, 0), Point2D(1, 1), Point2D(0, 1)), 0.5),
    ],
)
def test_area_triangle_2d(lhs: Triangle2D, expected: float) -> None:
    """Test area of a triangle in 2D.

    Args:
        lhs: The triangle.
        expected: The expected area.
    """

    assert lhs.area() == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,expected",
    [
        (Triangle3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0)), 0.5),
        (Triangle3D(Point3D(0, 0, 0), Point3D(0, 0, 1), Point3D(1, 1, 0)), SQRT_2 / 2),
    ],
)
def test_area_triangle_3d(lhs: Triangle3D, expected: float) -> None:
    """Test area of a triangle in 2D.

    Args:
        lhs: The triangle.
        expected: The expected area.
    """

    assert lhs.area() == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point2D(0, 0), Line2D(Point2D(0, 0), Point2D(1, 0)), Point2D(0, 0)),
        (Point2D(0, 0), Line2D(Point2D(0, 0), Point2D(0, 1)), Point2D(0, 0)),
        (Point2D(0, 0), Line2D(Point2D(1, 0), Point2D(2, 0)), None),
        (Point2D(0, 0), Line2D(Point2D(1, 0), Point2D(0, 1)), Point2D(0.5, 0.5)),
    ],
)
def test_project_point_to_line_2d(lhs: Point2D, rhs: Line2D, expected: Point2D | None) -> None:
    """Test projection of a point onto a line in 2D.

    Args:
        lhs: The point.
        rhs: The line.
        expected: The expected projection.
    """

    result = lhs.project_to_line(rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert result == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point3D(0, 0, 0), Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), Point3D(0, 0, 0)),
        (Point3D(0, 0, 0), Line3D(Point3D(0, 0, 0), Point3D(0, 1, 0)), Point3D(0, 0, 0)),
        (Point3D(0, 0, 0), Line3D(Point3D(0, 0, 0), Point3D(0, 0, 1)), Point3D(0, 0, 0)),
        (Point3D(0, 0, 0), Line3D(Point3D(1, 0, 0), Point3D(2, 0, 0)), None),
        (Point3D(0, 0, 0), Line3D(Point3D(1, 0, 0), Point3D(0, 1, 0)), Point3D(0.5, 0.5, 0)),
    ],
)
def test_project_point_to_line_3d(lhs: Point3D, rhs: Line3D, expected: Point3D | None) -> None:
    """Test projection of a point onto a line in 3D.

    Args:
        lhs: The point.
        rhs: The line.
        expected: The expected projection.
    """

    result = lhs.project_to_line(rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert result == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point3D(0, 0, 0), Triangle3D(Point3D(0, 0, 1), Point3D(0, 1, 1), Point3D(1, 0, 1)), Point3D(0, 0, 1)),
        (Point3D(0, 0, 0), Triangle3D(Point3D(0, -1, 1), Point3D(1, 1, 1), Point3D(-1, 0, 1)), Point3D(0, 0, 1)),
    ],
)
def test_project_point_to_triangle_3d(lhs: Point3D, rhs: Triangle3D, expected: Point3D | None) -> None:
    """Test projection of a point onto a triangle in 3D.

    Args:
        lhs: The point.
        rhs: The triangle.
        expected: The expected projection.
    """

    result = lhs.project_to_triangle(rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert result == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Line2D(Point2D(0, 1), Point2D(0, 2)), None),
        (Line2D(Point2D(0, 0), Point2D(1, 1)), Line2D(Point2D(1, 1), Point2D(2, 2)), None),
        (Line2D(Point2D(0, 0), Point2D(1, 1)), Line2D(Point2D(-1, -1), Point2D(2, 2)), None),
        (Line2D(Point2D(0, 0), Point2D(1, 1)), Line2D(Point2D(0, 1), Point2D(1, 0)), Point2D(0.5, 0.5)),
        (Line2D(Point2D(0, 0), Point2D(-1, -1)), Line2D(Point2D(0, 1), Point2D(1, 0)), None),
    ],
)
def test_line_line_intersection_2d(lhs: Line2D, rhs: Line2D, expected: Point2D | None) -> None:
    """Test intersection of two lines in 2D.

    Args:
        lhs: The first line.
        rhs: The second line.
        expected: The expected intersection.
    """

    result = lhs.intersection(rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert result == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (
            Line3D(Point3D(0, 0, 0), Point3D(0, 1, 1)),
            Line3D(Point3D(0, 0, 1), Point3D(0, 1, 0)),
            (Point3D(0, 0.5, 0.5), Point3D(0, 0.5, 0.5)),
        ),
        (
            Line3D(Point3D(0, 0, 0), Point3D(1, 1, 1)),
            Line3D(Point3D(0, 0, 1), Point3D(1, 1, 0)),
            (Point3D(0.5, 0.5, 0.5), Point3D(0.5, 0.5, 0.5)),
        ),
        (
            Line3D(Point3D(0, 0, 0), Point3D(1, 1, 1)),
            Line3D(Point3D(0, 0, 1), Point3D(1, 1, 2)),
            None,
        ),
    ],
)
def test_line_line_nearest_points_3d(lhs: Line3D, rhs: Line3D, expected: tuple[Point3D, Point3D] | None) -> None:
    """Test intersection of two lines in 3D.

    Args:
        lhs: The first line.
        rhs: The second line.
        expected: The expected intersection.
    """

    result = lhs.closest_points(rhs)
    if result is None:
        assert expected is None, result
    else:
        assert expected is not None, result
        assert result[0] == pytest.approx(expected[0])
        assert result[1] == pytest.approx(expected[1])


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (
            Line3D(Point3D(0, 0, -1), Point3D(0, 0, 1)),
            Triangle3D(Point3D(-1, -1, 0), Point3D(1, 1, 0), Point3D(1, -1, 0)),
            Point3D(0, 0, 0),
        ),
        (
            Line3D(Point3D(0, 0, -1), Point3D(0, 0, 1)),
            Triangle3D(Point3D(-1, -1, 0), Point3D(-1, 0, 0), Point3D(0, -1, 0)),
            None,
        ),
        (
            Line3D(Point3D(0, 0, 0), Point3D(1, 1, 1)),
            Triangle3D(Point3D(0, 0, 1), Point3D(0, 1, 1), Point3D(1, 0, 0)),
            Point3D(0.5, 0.5, 0.5),
        ),
        (
            Line3D(Point3D(-1, -1, -1.1), Point3D(1, 1, 0.9)),
            Triangle3D(Point3D(0, -0.5, 0.5), Point3D(0, 0.5, 0), Point3D(0, -0.5, -0.5)),
            Point3D(0, 0, -0.1),
        ),
    ],
)
def test_line_triangle_intersection_3d(lhs: Line3D, rhs: Triangle3D, expected: Point3D | None) -> None:
    """Test intersection of a line and a triangle in 3D.

    Args:
        lhs: The line.
        rhs: The triangle.
        expected: The expected intersection.
    """

    result = lhs.triangle_intersection(rhs)
    does_intersect = lhs.intersects_triangle(rhs)
    assert does_intersect == (result is not None)

    if result is None:
        assert expected is None
    else:
        assert expected is not None, result
        assert result == pytest.approx(expected)


@pytest.mark.parametrize(
    "points,expected",
    [
        ((Point2D(0, 0), Point2D(1, 0), Point2D(1, 1)), math.pi / 2),
        ((Point2D(0, 0), Point2D(1, 0), Point2D(2, 0)), math.pi),
    ],
)
def test_angles_2d(points: tuple[Point2D, Point2D, Point2D], expected: float) -> None:
    """Tests the angle calculation.

    Args:
        points: The points to test.
        expected: The expected angle.
    """

    aval = abs(Angle(points[0], points[1], points[2]).value)
    assert aval == pytest.approx(expected), aval

    aval = abs(Angle(points[2], points[1], points[0]).value)
    assert aval == pytest.approx(expected), aval


@pytest.mark.parametrize(
    "points,expected",
    [
        ((Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(1, 1, 1)), math.pi / 2),
        ((Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(2, 0, 0)), math.pi),
    ],
)
def test_angles_3d(points: tuple[Point3D, Point3D, Point3D], expected: float) -> None:
    """Tests the angle calculation.

    Args:
        points: The points to test.
        expected: The expected angle.
    """

    aval = abs(Angle(points[0], points[1], points[2]).value)
    assert aval == pytest.approx(expected), aval

    aval = abs(Angle(points[2], points[1], points[0]).value)
    assert aval == pytest.approx(expected), aval


@pytest.mark.parametrize(
    "vertices,area,clockwise",
    [
        ([Point2D(0, 0), Point2D(1, 0), Point2D(1, 1), Point2D(0, 1)], 1.0, False),
        ([Point2D(0, 0), Point2D(0.5, 0.5), Point2D(0, 1), Point2D(1, 1), Point2D(1, 0)], 1.0 - 0.25, True),
        (
            [Point2D(0, 0), Point2D(1, 0), Point2D(1, 1), Point2D(0, 1), Point2D(0.1, 0.9), Point2D(0.1, 0.1)],
            1.0 - 0.09,
            False,
        ),
    ],
)
def test_signed_area(vertices: list[Point2D], area: float, clockwise: bool) -> None:
    """Tests the signed area calculation.

    Args:
        vertices: The vertices of the polygon.
        area: The area of the polygon.
        clockwise: Whether the polygon is clockwise.
    """

    # Checks the signed area function.
    poly = Polygon2D(vertices)
    assert poly.signed_area() == pytest.approx(-area if clockwise else area), poly.signed_area()
    assert poly.is_clockwise() == clockwise
    poly.reverse()
    assert poly.is_clockwise() != clockwise


@pytest.mark.parametrize(
    "vertices,hull",
    [
        (
            [Point2D(0, 0), Point2D(1, 0), Point2D(1, 1), Point2D(0, 1)],
            [Point2D(0, 0), Point2D(1, 0), Point2D(1, 1), Point2D(0, 1)],
        ),
        (
            [Point2D(0, 0), Point2D(0.5, 0.5), Point2D(0, 1), Point2D(1, 1), Point2D(1, 0)],
            [Point2D(0, 0), Point2D(1, 0), Point2D(1, 1), Point2D(0, 1)],
        ),
        (
            [Point2D(0, 0), Point2D(1, 0), Point2D(1, 1), Point2D(0, 1), Point2D(0.1, 0.9), Point2D(0.1, 0.1)],
            [Point2D(0, 0), Point2D(1, 0), Point2D(1, 1), Point2D(0, 1)],
        ),
    ],
)
def test_convex_hull(vertices: list[Point2D], hull: list[Point2D]) -> None:
    """Tests the convex hull calculation.

    Args:
        vertices: The vertices of the polygon.
        hull: The vertices of the convex hull.
    """

    poly = Polygon2D(vertices)

    # Checks the convex hull function.
    pred_hull = [(i.x, i.y) for i in poly.convex_hull().points]
    pred_hull.sort()
    hull_xy = [(i.x, i.y) for i in hull]
    hull_xy.sort()
    assert pred_hull == pytest.approx(hull_xy), (pred_hull, hull_xy)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point2D(0, 0), Line2D(Point2D(0, 0), Point2D(1, 0)), 0),
        (Point2D(0, 0), Line2D(Point2D(0, 0), Point2D(0, 1)), 0),
        (Point2D(0, 0), Line2D(Point2D(1, 0), Point2D(2, 0)), 1),
        (Point2D(0, 0), Line2D(Point2D(0, 1), Point2D(1, 1)), 1),
    ],
)
def test_point_to_line_2d_min_distance(lhs: Point2D, rhs: Line2D, expected: float) -> None:
    """Test distance between a point and a line in 2D.

    Args:
        lhs: The point.
        rhs: The line.
        expected: The expected distance.
    """

    assert lhs.distance_to_line(rhs) == pytest.approx(expected)
    assert lhs.distance_to_line(Line2D(rhs.p2, rhs.p1)) == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Line2D(Point2D(0, 0), Point2D(1, 0)), 0),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Line2D(Point2D(0, 0), Point2D(0, 1)), 0),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Line2D(Point2D(1, 0), Point2D(2, 0)), 0),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Line2D(Point2D(0, 1), Point2D(1, 1)), 1),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Line2D(Point2D(0, 1), Point2D(0, 2)), 1),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Line2D(Point2D(0, 2), Point2D(0, 3)), 2),
        (Line2D(Point2D(0, 0), Point2D(0, 1)), Line2D(Point2D(1, 2), Point2D(1, 3)), SQRT_2),
    ],
)
def test_line_to_line_2d_min_distance(lhs: Line2D, rhs: Line2D, expected: float) -> None:
    """Tests minimum distances between two lines in 2D.

    Args:
        lhs: The first line.
        rhs: The second line.
        expected: The expected minimum distance.
    """

    assert lhs.distance_to_line(rhs) == pytest.approx(expected)
    assert lhs.distance_to_line(Line2D(rhs.p2, rhs.p1)) == pytest.approx(expected)
    assert Line2D(lhs.p2, lhs.p1).distance_to_line(rhs) == pytest.approx(expected)
    assert Line2D(lhs.p2, lhs.p1).distance_to_line(Line2D(rhs.p2, rhs.p1)) == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point2D(0, 0), Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1)), 0),
        (Point2D(0, 0), Triangle2D(Point2D(0, 0), Point2D(0, 1), Point2D(1, 0)), 0),
        (Point2D(0, 0), Triangle2D(Point2D(0, 1), Point2D(1, 1), Point2D(0, 2)), 1),
        (Point2D(0, 0), Triangle2D(Point2D(1, 1), Point2D(1, 2), Point2D(2, 2)), SQRT_2),
        (Point2D(0, 0), Triangle2D(Point2D(2, 1), Point2D(-1, -1), Point2D(-1, 1)), 0),
        (Point2D(0, 0), Triangle2D(Point2D(1, 0), Point2D(2, 0), Point2D(1, 1)), 1),
        (Point2D(0, 0), Triangle2D(Point2D(0, 2), Point2D(0, 3), Point2D(1, 2)), 2),
    ],
)
def test_point_to_triangle_2d_min_distance(lhs: Point2D, rhs: Triangle2D, expected: float) -> None:
    """Tests minimum distances between a point and a triangle in 2D.

    Args:
        lhs: The point.
        rhs: The triangle.
        expected: The expected minimum distance.
    """

    assert lhs.distance_to_triangle(rhs) == pytest.approx(expected)
    assert lhs.distance_to_triangle(Triangle2D(rhs.p2, rhs.p1, rhs.p3)) == pytest.approx(expected)
    assert lhs.distance_to_triangle(Triangle2D(rhs.p3, rhs.p1, rhs.p2)) == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1)), 0),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Triangle2D(Point2D(0, 0), Point2D(0, 1), Point2D(1, 0)), 0),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Triangle2D(Point2D(0, 1), Point2D(1, 1), Point2D(0, 2)), 1),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Triangle2D(Point2D(1, 1), Point2D(1, 2), Point2D(2, 2)), 1),
        (Line2D(Point2D(0, 0), Point2D(1, 0)), Triangle2D(Point2D(2, 1), Point2D(-1, -1), Point2D(-1, 1)), 0),
    ],
)
def test_line_to_triangle_2d_min_distance(lhs: Line2D, rhs: Triangle2D, expected: float) -> None:
    """Tests minimum distances between a line and a triangle in 2D.

    Args:
        lhs: The line.
        rhs: The triangle.
        expected: The expected minimum distance.
    """

    assert lhs.distance_to_triangle(rhs) == pytest.approx(expected)
    assert lhs.distance_to_triangle(Triangle2D(rhs.p2, rhs.p1, rhs.p3)) == pytest.approx(expected)
    assert lhs.distance_to_triangle(Triangle2D(rhs.p3, rhs.p1, rhs.p2)) == pytest.approx(expected)
    assert Line2D(lhs.p2, lhs.p1).distance_to_triangle(rhs) == pytest.approx(expected)
    assert Line2D(lhs.p2, lhs.p1).distance_to_triangle(Triangle2D(rhs.p2, rhs.p1, rhs.p3)) == pytest.approx(expected)
    assert Line2D(lhs.p2, lhs.p1).distance_to_triangle(Triangle2D(rhs.p3, rhs.p1, rhs.p2)) == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point3D(0, 0, 0), Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), 0),
        (Point3D(0, 0, 0), Line3D(Point3D(0, 0, 0), Point3D(0, 1, 0)), 0),
        (Point3D(0, 0, 0), Line3D(Point3D(0, 0, 0), Point3D(0, 0, 1)), 0),
        (Point3D(0, 0, 0), Line3D(Point3D(1, 0, 0), Point3D(2, 0, 0)), 1),
        (Point3D(0, 0, 0), Line3D(Point3D(0, 1, 0), Point3D(1, 1, 0)), 1),
        (Point3D(0, 0, 0), Line3D(Point3D(0, 0, -1), Point3D(0, 0, 1)), 0),
    ],
)
def test_point_to_line_3d_min_distance(lhs: Point3D, rhs: Line3D, expected: float) -> None:
    """Test distance between a point and a line.

    Args:
        lhs: The point.
        rhs: The line.
        expected: The expected minimum distance.
    """

    assert lhs.distance_to_line(rhs) == pytest.approx(expected)
    assert lhs.distance_to_line(Line3D(rhs.p2, rhs.p1)) == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), 0),
        (Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), Line3D(Point3D(0, 0, 0), Point3D(0, 1, 0)), 0),
        (Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), Line3D(Point3D(0, 0, 0), Point3D(0, 0, 1)), 0),
        (Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), Line3D(Point3D(1, 0, 1), Point3D(2, 0, 1)), 1),
        (Line3D(Point3D(0, 0, 0), Point3D(1, 0, 0)), Line3D(Point3D(0, 1, 0), Point3D(1, 1, 0)), 1),
        (Line3D(Point3D(0, 0, -1), Point3D(0, 0, 1)), Line3D(Point3D(-1, 1, 0), Point3D(1, 1, 0)), 1),
    ],
)
def test_line_to_line_3d_min_distance(lhs: Line3D, rhs: Line3D, expected: float) -> None:
    """Test distance between a line and a line.

    Args:
        lhs: The line.
        rhs: The line.
        expected: The expected minimum distance.
    """

    assert lhs.distance_to_line(rhs) == pytest.approx(expected)
    assert lhs.distance_to_line(Line3D(rhs.p2, rhs.p1)) == pytest.approx(expected)
    assert Line3D(lhs.p2, lhs.p1).distance_to_line(rhs) == pytest.approx(expected)
    assert Line3D(lhs.p2, lhs.p1).distance_to_line(Line3D(rhs.p2, rhs.p1)) == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Point3D(0, 0, 0), Triangle3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0)), 0),
        (Point3D(0, 0, 0), Triangle3D(Point3D(0, 0, 1), Point3D(1, 0, 1), Point3D(0, 1, 1)), 1),
        (Point3D(0, 2, 0), Triangle3D(Point3D(0, 0, -1), Point3D(1, 0, -1), Point3D(0, 0, 1)), 2),
        (Point3D(0, 0, 0), Triangle3D(Point3D(0, -1, 1), Point3D(1, 1, 1), Point3D(-1, 0, 1)), 1),
    ],
)
def test_point_to_triangle_3d_min_distance(lhs: Point3D, rhs: Triangle3D, expected: float) -> None:
    """Tests minimum distances between a point and a triangle in 3D.

    Args:
        lhs: The point.
        rhs: The triangle.
        expected: The expected minimum distance.
    """

    assert lhs.distance_to_triangle(rhs) == pytest.approx(expected)
    assert lhs.distance_to_triangle(Triangle3D(rhs.p2, rhs.p1, rhs.p3)) == pytest.approx(expected)
    assert lhs.distance_to_triangle(Triangle3D(rhs.p3, rhs.p1, rhs.p2)) == pytest.approx(expected)


@pytest.mark.parametrize(
    "lhs,rhs",
    [
        (Point2D(0, 0), Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1))),
        (Point2D(0, 0), Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1))),
        (Point2D(0, 0), Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1))),
        (Point2D(0, 0), Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1))),
    ],
)
def test_barycentric_coordinates_2d(lhs: Point2D, rhs: Triangle2D) -> None:
    """Tests 2D barycentric coordinate conversion.

    Args:
        lhs: The point.
        rhs: The triangle.
    """

    bary = lhs.barycentric_coordinates(rhs)
    assert bary.u >= 0
    assert bary.v >= 0
    assert bary.w >= 0
    assert bary.u + bary.v + bary.w == pytest.approx(1)
    assert bary.get_point_2d(rhs) == lhs


@pytest.mark.parametrize(
    "lhs,rhs",
    [
        (Point3D(0, 0, 0), Triangle3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0))),
        (Point3D(0, 0, 0), Triangle3D(Point3D(0, 0, 1), Point3D(1, 0, 1), Point3D(0, 1, 1))),
        (Point3D(0, 2, 0), Triangle3D(Point3D(0, 0, -1), Point3D(1, 0, -1), Point3D(0, 0, 1))),
    ],
)
def test_barycentric_coordinates_3d(lhs: Point3D, rhs: Triangle3D) -> None:
    """Tests 2D barycentric coordinate conversion.

    Args:
        lhs: The point.
        rhs: The triangle.
    """

    bary = lhs.barycentric_coordinates(rhs)
    assert bary.u >= 0
    assert bary.v >= 0
    assert bary.w >= 0
    assert bary.u + bary.v + bary.w == pytest.approx(1)
    if lhs.is_coplanar(rhs):
        assert bary.get_point_3d(rhs) == lhs
    else:
        assert bary.get_point_3d(rhs) != lhs
