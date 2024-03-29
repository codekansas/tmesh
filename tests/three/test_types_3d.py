"""Test 3D types."""

import math
import random

import pytest

from tmesh import Affine3D, BoundingBox3D, Line3D, Point3D, Sphere3D, Tetrahedron3D, Triangle3D

SQRT_2 = math.sqrt(2)
SQRT_3 = math.sqrt(3)


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
        assert rhs.point_from_barycentric_coords(bary) == lhs
    else:
        assert rhs.point_from_barycentric_coords(bary) != lhs


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
        (Point3D(0, 0, 0), Point3D(1, 0, 0), 1),
        (Point3D(0, 0, 0), Point3D(0, 1, 0), 1),
        (Point3D(0, 0, 0), Point3D(0, 0, 1), 1),
        (Point3D(0, 0, 0), Point3D(1, 1, 1), SQRT_3),
    ],
)
def test_distance(lhs: Point3D, rhs: Point3D, expected: float) -> None:
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
        (
            Tetrahedron3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(0, 0, 1)),
            Point3D(0, 1, 0),
            True,
        ),
        (
            Tetrahedron3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(0, 0, 1)),
            Point3D(0.2, 0.2, 0.2),
            True,
        ),
        (
            Tetrahedron3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(0, 0, 1)),
            Point3D(0.2, 0.2, 0.8),
            False,
        ),
    ],
)
def test_point_inside(lhs: Tetrahedron3D, rhs: Point3D, expected: bool) -> None:
    """Tests if a point is inside a tetrahedron.

    Args:
        lhs: The tetrahedron.
        rhs: The point.
        expected: The expected result.
    """

    assert lhs.point_is_inside(rhs) == expected


def test_bounding_box_tetrahedrons() -> None:
    bbox = BoundingBox3D([Point3D(*(random.random() for _ in range(3))) for _ in range(10)])
    volumes = [tetr.signed_volume() for tetr in bbox.tetrahedrons()]
    assert all(volume > 0 for volume in volumes)
    assert sum(volumes) == pytest.approx(bbox.volume())


@pytest.mark.parametrize("seed", [1337, 1338, 1339])
def test_signed_volume_faces_point_outwards(seed: int) -> None:
    """Tests that the signed volume of a tetrahedron is positive if the faces point outwards.

    Args:
        seed: The random seed.
    """

    random.seed(seed)

    points = [Point3D(*(random.random() for _ in range(3))) for _ in range(4)]
    tetr = Tetrahedron3D(*points)

    # Ensures that the tetrahedron's signed volume is positive.
    if tetr.signed_volume() < 0:
        tetr = tetr.flip()
    centroid = tetr.centroid()

    # Checks the normal vector of each face against the centroid.
    for face in tetr.faces:
        normal = face.normal()
        assert normal.dot(centroid - face.p1) < 0

    # Checks that flipping the tetrahedron inside out results in the opposite behavior.
    tetr = tetr.flip()
    for face in tetr.faces:
        normal = face.normal()
        assert normal.dot(centroid - face.p1) > 0


@pytest.mark.parametrize(
    "lhs,rhs,expected",
    [
        (Sphere3D(Point3D(0, 0, 0), 1), Sphere3D(Point3D(0, 0, 0), 1), None),
        (Sphere3D(Point3D(0, 0, 0), 1), Sphere3D(Point3D(0, 0, 0), 2), None),
        (Sphere3D(Point3D(0, 0, 0), 1), Sphere3D(Point3D(0, 0, 1), 1), Sphere3D(Point3D(0, 0, 0.5), SQRT_3 / 2)),
    ],
)
def test_sphere_intersection(lhs: Sphere3D, rhs: Sphere3D, expected: Sphere3D | None) -> None:
    """Tests the intersection of two spheres.

    Args:
        lhs: The first sphere.
        rhs: The second sphere.
        expected: The expected intersection.
    """

    assert lhs.intersection(rhs) == expected
