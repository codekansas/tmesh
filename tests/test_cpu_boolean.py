"""Tests CPU boolean operations."""

import random

import pytest

from fast_trimesh.cpu.boolean import TrimeshAdjacency, triangulation
from fast_trimesh.cpu.shapes import cuboid, tetrahedron
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


def test_adjacency() -> None:
    """Tests adjacency data structure."""

    tetr = tetrahedron(radius=1.0)
    tetr_adj = TrimeshAdjacency(tetr)
    tetr_adj.validate()
    assert all(len(v) == 3 for v in tetr_adj.vertex_to_faces)

    cub = cuboid(2.0, 2.0, 2.0)
    cub_adj = TrimeshAdjacency(cub)
    assert all(len(v) in (4, 5) for v in cub_adj.vertex_to_faces)
    cub_adj.validate()


@pytest.mark.skip(reason="Not implemented")
def test_union() -> None:
    """Tests union of two cuboids."""

    # Creates a cuboid.
    cuboid1 = cuboid(1.0, 1.0, 1.0)

    # Creates a cuboid which is longer and shorter than the first cuboid.
    cuboid2 = cuboid(2.0, 0.5, 0.5)

    # Gets the union of the two cuboids.
    union = cuboid1 & cuboid2

    breakpoint()

    asdf
