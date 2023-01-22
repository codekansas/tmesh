"""Tests the CPU triangulate implementation."""

import math
import random

import pytest

from tmesh import Point2D, Polygon2D


@pytest.mark.parametrize("random_points", [True, False])
def test_simple_triangulate(random_points: bool) -> None:
    """Tests simple triangulation.

    This test creates a polygon, adds some random vertices to it, and
    then tests triangulating the polygon.

    Args:
        random_points: Whether to use random points or a simple polygon.
    """

    if random_points:
        vertices = [Point2D(random.random() - 0.5, random.random() - 0.5) for _ in range(10)]
        vertices.sort(key=lambda v: -math.atan2(v.y, v.x) % (2 * math.pi))
    else:
        vertices = [Point2D(math.cos(2 * math.pi * i / 10), math.sin(2 * math.pi * i / 10)) for i in range(10)]

    # Gets the triangulation.
    poly = Polygon2D(vertices)
    trimesh = poly.get_trimesh(is_convex=False)

    assert len(trimesh.vertices) == 10, trimesh.vertices
    assert len(trimesh.faces) == 8, trimesh.faces
