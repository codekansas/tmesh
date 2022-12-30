"""Tests the CPU triangulate implementation."""

import math
import random

import pytest

from fast_trimesh.fast_trimesh.cpu import (
    angle,
    angle_sum,
    is_clockwise,
    is_convex,
    signed_angle,
    signed_area,
    triangulate,
)

Point2D = tuple[float, float]
Point3D = tuple[float, float, float]
Point = tuple[float, ...]
Angle2D = tuple[Point2D, Point2D, Point2D]
Angle3D = tuple[Point3D, Point3D, Point3D]


@pytest.mark.parametrize(
    "points,expected",
    [
        (((0, 0), (1, 0), (1, 1)), math.pi / 2),
        (((0, 0), (1, 0), (2, 0)), math.pi),
    ],
)
def test_angles_2d(points: Angle2D, expected: float) -> None:
    """Tests the angle calculation.

    Args:
        points: The points to test.
        expected: The expected angle.
    """

    aval = angle(points[0], points[1], points[2])
    assert aval == pytest.approx(expected), aval

    aval = angle(points[2], points[1], points[0])
    assert aval == pytest.approx(expected), aval


@pytest.mark.parametrize(
    "points,expected",
    [
        (((0, 0, 0), (1, 0, 0), (1, 1, 1)), math.pi / 2),
        (((0, 0, 0), (1, 0, 0), (2, 0, 0)), math.pi),
    ],
)
def test_angles_3d(points: Angle3D, expected: float) -> None:
    """Tests the angle calculation.

    Args:
        points: The points to test.
        expected: The expected angle.
    """

    aval = angle(points[0], points[1], points[2])
    assert aval == pytest.approx(expected), aval

    aval = angle(points[2], points[1], points[0])
    assert aval == pytest.approx(expected), aval


@pytest.mark.parametrize(
    "vertices,area,clockwise",
    [
        ([(0, 0), (1, 0), (1, 1), (0, 1)], 1.0, False),
        ([(0, 0), (0.5, 0.5), (0, 1), (1, 1), (1, 0)], 1.0 - 0.25, True),
        ([(0, 0), (1, 0), (1, 1), (0, 1), (0.1, 0.9), (0.1, 0.1)], 1.0 - 0.09, False),
    ],
)
def test_angle_sum(vertices: list[Point2D], area: float, clockwise: bool) -> None:
    """Tests the angle sum calculation.

    Args:
        vertices: The vertices of the polygon.
        area: The area of the polygon.
        clockwise: Whether the polygon is clockwise.
    """

    angles = []
    for j, vert_j in enumerate(vertices):
        i, k = (j - 1) % len(vertices), (j + 1) % len(vertices)
        vert_i, vert_k = vertices[i], vertices[k]
        ang = signed_angle(vert_i, vert_j, vert_k)
        angles.append(ang)
        assert is_convex(vert_i, vert_j, vert_k) == (ang < 0), (vert_i, vert_j, vert_k)

    expected = sum(angles)

    asum = angle_sum(vertices)
    assert asum == pytest.approx(expected, abs=1e-4), asum

    asum = angle_sum(vertices[::-1])
    assert asum == pytest.approx(-expected, abs=1e-4), asum

    # Checks the signed area function.
    sarea = signed_area(vertices[::-1] if clockwise else vertices)
    assert abs(sarea) == pytest.approx(area), sarea
    assert is_clockwise(vertices) == clockwise
    assert is_clockwise(vertices[::-1]) != clockwise


@pytest.mark.parametrize("random_points", [True, False])
def test_simple_triangulate(random_points: bool) -> None:
    """Tests simple triangulation.

    This test creates a polygon, adds some random vertices to it, and
    then tests triangulating the polygon.

    Args:
        random_points: Whether to use random points or a simple polygon.
    """

    if random_points:
        vertices = [(random.random() - 0.5, random.random() - 0.5) for _ in range(10)]
        vertices.sort(key=lambda v: -math.atan2(v[1], v[0]) % (2 * math.pi))
    else:
        vertices = [(math.cos(2 * math.pi * i / 10), math.sin(2 * math.pi * i / 10)) for i in range(10)]

    # Gets the triangulation.
    trimesh = triangulate(vertices, is_convex=False)

    assert len(trimesh.vertices) == 10, trimesh.vertices
    assert len(trimesh.faces) == 8, trimesh.faces
