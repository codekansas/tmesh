"""Test CPU geometry functions."""

import pytest

import fast_trimesh.fast_trimesh.cpu as trimesh

Point2D = tuple[float, float]
Point3D = tuple[float, float, float]
Point = tuple[float, ...]
Line2D = tuple[Point2D, Point2D]
Line3D = tuple[Point3D, Point3D]
Line = tuple[Point, Point]
Triangle2D = tuple[Point2D, Point2D, Point2D]
Triangle3D = tuple[Point3D, Point3D, Point3D]
Triangle = tuple[Point, Point, Point]

SQRT_2 = 1.4142135623730951
SQRT_3 = 1.7320508075688772


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0), (1, 0), 1),
        ((0, 0), (0, 1), 1),
        ((0, 0), (1, 1), SQRT_2),
        ((0, 0, 0), (1, 0, 0), 1),
        ((0, 0, 0), (0, 1, 0), 1),
        ((0, 0, 0), (0, 0, 1), 1),
        ((0, 0, 0), (1, 1, 1), SQRT_3),
    ],
)
def test_distance(lhs: Point, rhs: Point, expected: float) -> None:
    """Test distance between two points."""

    assert abs(trimesh.distance(lhs, rhs) - expected) < 1e-7  # type: ignore[arg-type]


@pytest.mark.parametrize(
    "lhs,expected",
    [
        (((0, 0), (1, 0), (0, 1)), 0.5),
        (((0, 0), (0, 1), (1, 0)), 0.5),
        (((0, 0), (1, 0), (1, 1)), 0.5),
        (((0, 0), (1, 1), (0, 1)), 0.5),
    ],
)
def test_area_triangle_2d(lhs: Triangle2D, expected: float) -> None:
    """Test area of a triangle in 2D."""

    assert abs(trimesh.area(lhs) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,expected",
    [
        (((0, 0, 0), (1, 0, 0), (0, 1, 0)), 0.5),
        (((0, 0, 0), (0, 0, 1), (1, 1, 0)), SQRT_2 / 2),
    ],
)
def test_area_triangle_3d(lhs: Triangle3D, expected: float) -> None:
    """Test area of a triangle in 2D."""

    assert abs(trimesh.area(lhs) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0), ((0, 0), (1, 0)), (0, 0)),
        ((0, 0), ((0, 0), (0, 1)), (0, 0)),
        ((0, 0), ((1, 0), (2, 0)), None),
        ((0, 0), ((1, 0), (0, 1)), (0.5, 0.5)),
    ],
)
def test_project_point_to_line_2d(lhs: Point2D, rhs: Line2D, expected: Point2D | None) -> None:
    """Test projection of a point onto a line in 2D."""

    result = trimesh.project(lhs, rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert abs(result[0] - expected[0]) < 1e-7
        assert abs(result[1] - expected[1]) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0, 0), ((0, 0, 0), (1, 0, 0)), (0, 0, 0)),
        ((0, 0, 0), ((0, 0, 0), (0, 1, 0)), (0, 0, 0)),
        ((0, 0, 0), ((0, 0, 0), (0, 0, 1)), (0, 0, 0)),
        ((0, 0, 0), ((1, 0, 0), (2, 0, 0)), None),
        ((0, 0, 0), ((1, 0, 0), (0, 1, 0)), (0.5, 0.5, 0)),
    ],
)
def test_project_point_to_line_3d(lhs: Point3D, rhs: Line3D, expected: Point3D | None) -> None:
    """Test projection of a point onto a line in 3D."""

    result = trimesh.project(lhs, rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert abs(result[0] - expected[0]) < 1e-7
        assert abs(result[1] - expected[1]) < 1e-7
        assert abs(result[2] - expected[2]) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0, 0), ((0, 0, 1), (0, 1, 1), (1, 0, 1)), (0, 0, 1)),
        ((0, 0, 0), ((0, -1, 1), (1, 1, 1), (-1, 0, 1)), (0, 0, 1)),
    ],
)
def test_project_point_to_triangle_3d(lhs: Point3D, rhs: Triangle3D, expected: Point3D | None) -> None:
    """Test projection of a point onto a triangle in 3D."""

    result = trimesh.project(lhs, rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert abs(trimesh.distance(result, expected)) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (((0, 0), (1, 0)), ((0, 1), (0, 2)), None),  # Intersect, but not in segment
        (((0, 0), (1, 1)), ((1, 1), (2, 2)), None),  # Parallel
        (((0, 0), (1, 1)), ((-1, -1), (2, 2)), None),  # Parallel, overlapping
        (((0, 0), (1, 1)), ((0, 1), (1, 0)), (0.5, 0.5)),  # Intersect
        (((0, 0), (-1, -1)), ((0, 1), (1, 0)), None),  # Intersect, but not in segment
    ],
)
def test_line_line_intersection_2d(lhs: Line2D, rhs: Line2D, expected: Point2D | None) -> None:
    """Test intersection of two lines in 2D."""

    result = trimesh.intersection(lhs, rhs)
    if result is None:
        assert expected is None
    else:
        assert expected is not None
        assert abs(trimesh.distance(result, expected)) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (((0, 0, 0), (0, 1, 1)), ((0, 0, 1), (0, 1, 0)), ((0, 0.5, 0.5), (0, 0.5, 0.5))),  # Intersect
        (((0, 0, 0), (1, 1, 1)), ((0, 0, 1), (1, 1, 0)), ((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))),  # Intersect
        (((0, 0, 0), (1, 1, 1)), ((0, 0, 1), (1, 1, 2)), None),  # Parallel
    ],
)
def test_line_line_nearest_intersection_3d(lhs: Line3D, rhs: Line3D, expected: tuple[Point3D, Point3D] | None) -> None:
    """Test intersection of two lines in 3D."""

    result = trimesh.nearest_intersection(lhs, rhs)
    if result is None:
        assert expected is None, result
    else:
        assert expected is not None, result
        assert abs(trimesh.distance(result[0], expected[0])) < 1e-7
        assert abs(trimesh.distance(result[1], expected[1])) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (((0, 0, -1), (0, 0, 1)), ((-1, -1, 0), (1, 1, 0), (1, -1, 0)), (0, 0, 0)),
        (((0, 0, -1), (0, 0, 1)), ((-1, -1, 0), (-1, 0, 0), (0, -1, 0)), None),
        (((0, 0, 0), (1, 1, 1)), ((0, 0, 1), (0, 1, 1), (1, 0, 0)), (0.5, 0.5, 0.5)),
    ],
)
def test_line_triangle_intersection_3d(lhs: Line3D, rhs: Triangle3D, expected: Point3D | None) -> None:
    """Test intersection of a line and a triangle in 3D."""

    result = trimesh.intersection(lhs, rhs)
    does_intersect = trimesh.intersects(lhs, rhs)
    assert does_intersect == (result is not None)

    if result is None:
        assert expected is None
    else:
        assert expected is not None, result
        assert abs(trimesh.distance(result, expected)) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0), ((0, 0), (1, 0)), 0),
        ((0, 0), ((0, 0), (0, 1)), 0),
        ((0, 0), ((1, 0), (2, 0)), 1),
        ((0, 0), ((0, 1), (1, 1)), 1),
    ],
)
def test_point_to_line_2d_min_distance(lhs: Point2D, rhs: Line2D, expected: float) -> None:
    """Test distance between a point and a line in 2D."""

    assert abs(trimesh.min_distance(lhs, rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[1], rhs[0])) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (((0, 0), (1, 0)), ((0, 0), (1, 0)), 0),
        (((0, 0), (1, 0)), ((0, 0), (0, 1)), 0),
        (((0, 0), (1, 0)), ((1, 0), (2, 0)), 0),
        (((0, 0), (1, 0)), ((0, 1), (1, 1)), 1),
        (((0, 0), (1, 0)), ((0, 1), (0, 2)), 1),
        (((0, 0), (1, 0)), ((0, 2), (0, 3)), 2),
        (((0, 0), (0, 1)), ((1, 2), (1, 3)), SQRT_2),
    ],
)
def test_line_to_line_2d_min_distance(lhs: Line2D, rhs: Line2D, expected: float) -> None:
    """Tests minimum distances between two lines in 2D."""

    assert abs(trimesh.min_distance(lhs, rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[1], rhs[0])) - expected) < 1e-7
    assert abs(trimesh.min_distance((lhs[1], lhs[0]), rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance((lhs[1], lhs[0]), (rhs[1], rhs[0])) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0), ((0, 0), (1, 0), (0, 1)), 0),
        ((0, 0), ((0, 0), (0, 1), (1, 0)), 0),
        ((0, 0), ((0, 1), (1, 1), (0, 2)), 1),
        ((0, 0), ((1, 1), (1, 2), (2, 2)), SQRT_2),
        ((0, 0), ((2, 1), (-1, -1), (-1, 1)), 0),
        ((0, 0), ((1, 0), (2, 0), (1, 1)), 1),
        ((0, 0), ((0, 2), (0, 3), (1, 2)), 2),
    ],
)
def test_point_to_triangle_2d_min_distance(lhs: Point2D, rhs: Triangle2D, expected: float) -> None:
    """Tests minimum distances between a point and a triangle in 2D."""

    assert abs(trimesh.min_distance(lhs, rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[1], rhs[2], rhs[0])) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[2], rhs[1], rhs[0])) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (((0, 0), (1, 0)), ((0, 0), (1, 0), (0, 1)), 0),
        (((0, 0), (1, 0)), ((0, 0), (0, 1), (1, 0)), 0),
        (((0, 0), (1, 0)), ((0, 1), (1, 1), (0, 2)), 1),
        (((0, 0), (1, 0)), ((1, 1), (1, 2), (2, 2)), 1),
        (((0, 0), (1, 0)), ((2, 1), (-1, -1), (-1, 1)), 0),
    ],
)
def test_line_to_triangle_2d_min_distance(lhs: Line2D, rhs: Triangle2D, expected: float) -> None:
    """Tests minimum distances between a line and a triangle in 2D."""

    assert abs(trimesh.min_distance(lhs, rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[1], rhs[2], rhs[0])) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[2], rhs[1], rhs[0])) - expected) < 1e-7
    assert abs(trimesh.min_distance((lhs[1], lhs[0]), rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance((lhs[1], lhs[0]), (rhs[1], rhs[2], rhs[0])) - expected) < 1e-7
    assert abs(trimesh.min_distance((lhs[1], lhs[0]), (rhs[2], rhs[1], rhs[0])) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0, 0), ((0, 0, 0), (1, 0, 0)), 0),
        ((0, 0, 0), ((0, 0, 0), (0, 1, 0)), 0),
        ((0, 0, 0), ((0, 0, 0), (0, 0, 1)), 0),
        ((0, 0, 0), ((1, 0, 0), (2, 0, 0)), 1),
        ((0, 0, 0), ((0, 1, 0), (1, 1, 0)), 1),
        ((0, 0, 0), ((0, 0, -1), (0, 0, 1)), 0),
    ],
)
def test_point_to_line_3d_min_distance(lhs: Point3D, rhs: Line3D, expected: float) -> None:
    """Test distance between a point and a line."""

    assert abs(trimesh.min_distance(lhs, rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[1], rhs[0])) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (((0, 0, 0), (1, 0, 0)), ((0, 0, 0), (1, 0, 0)), 0),
        (((0, 0, 0), (1, 0, 0)), ((0, 0, 0), (0, 1, 0)), 0),
        (((0, 0, 0), (1, 0, 0)), ((0, 0, 0), (0, 0, 1)), 0),
        (((0, 0, 0), (1, 0, 0)), ((1, 0, 1), (2, 0, 1)), 1),
        (((0, 0, 0), (1, 0, 0)), ((0, 1, 0), (1, 1, 0)), 1),
        (((0, 0, -1), (0, 0, 1)), ((-1, 1, 0), (1, 1, 0)), 1),
    ],
)
def test_line_to_line_3d_min_distance(lhs: Line3D, rhs: Line3D, expected: float) -> None:
    """Test distance between a line and a line."""

    assert abs(trimesh.min_distance(lhs, rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[1], rhs[0])) - expected) < 1e-7
    assert abs(trimesh.min_distance((lhs[1], lhs[0]), rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance((lhs[1], lhs[0]), (rhs[1], rhs[0])) - expected) < 1e-7


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        ((0, 0, 0), ((0, 0, 0), (1, 0, 0), (0, 1, 0)), 0),
        ((0, 0, 0), ((0, 0, 1), (1, 0, 1), (0, 1, 1)), 1),
        ((0, 2, 0), ((0, 0, -1), (1, 0, -1), (0, 0, 1)), 2),
        ((0, 0, 0), ((0, -1, 1), (1, 1, 1), (-1, 0, 1)), 1),
    ],
)
def test_point_to_triangle_3d_min_distance(lhs: Point3D, rhs: Triangle3D, expected: float) -> None:
    """Tests minimum distances between a point and a triangle in 3D."""

    assert abs(trimesh.min_distance(lhs, rhs) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[1], rhs[2], rhs[0])) - expected) < 1e-7
    assert abs(trimesh.min_distance(lhs, (rhs[2], rhs[1], rhs[0])) - expected) < 1e-7
