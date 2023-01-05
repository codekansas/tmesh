"""Tests CPU boolean operations."""

import random

import pytest

from fast_trimesh.cpu.boolean import triangulation
from fast_trimesh.cpu.types import Point3D, Triangle3D


def test_triangulation() -> None:
    """Tests triangulation of a given point."""

    # Creates a random set of points.
    points = [Point3D(random.random(), random.random(), 0.0) for _ in range(3)]

    # Creates a triangle which will enclose all the points.
    triangle = Triangle3D(Point3D(0.0, 0.0, 0.0), Point3D(2.0, 0.0, 0.0), Point3D(0.0, 2.0, 0.0))

    # Gets the Delaunay triangulation.
    triangles = triangulation(triangle, points)

    # Ensures that the triangulation contains all the points.
    assert sorted(points + triangle.vertices()) == sorted(triangles.vertices)
    assert len(triangles.faces) == 7

    # Checks that the normals of all the triangles are pointing in the same
    # direction as the original triangle.
    for sub_triangle in triangles.get_triangles():
        assert sub_triangle.normal() == triangle.normal()

    # Checks that the areas of all the triangles are the same as the original
    # triangle.
    sub_areas = sum(sub_triangle.area() for sub_triangle in triangles.get_triangles())
    assert sub_areas == pytest.approx(triangle.area())
