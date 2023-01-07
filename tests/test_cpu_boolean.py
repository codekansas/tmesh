"""Tests CPU boolean operations."""

import math
import random

import pytest

from fast_trimesh.cpu.boolean import triangulation
from fast_trimesh.cpu.bvh import intersections, BVH3D, TrimeshAdjacency
from fast_trimesh.cpu.shapes import cuboid, tetrahedron
from fast_trimesh.cpu.types import Affine3D, Point3D, Triangle3D, Line3D


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


def test_simple_boolean_ops() -> None:
    """Tests boolean ops on two tetrahedrons with simple intersections."""

    scale = Affine3D(scale=1.5)
    trans = Affine3D(trans=(0.0, 0.0, -1.5))
    rot = Affine3D(rot=(math.pi, 0.0, math.pi / 3))

    tetr = tetrahedron(radius=1.0)
    tetr_a = tetr
    tetr_b = tetr << scale @ trans @ rot

    # 12 intersections because each triangle has two (for two lines) and
    # there are six triangles. Since some edges are shared this has some
    # duplication.

    bvh = BVH3D(tetr_a)
    line = Line3D(tetr_b.vertices[3], tetr_b.vertices[1])
    intrs = bvh.intersections(line)
    face_pts = [Triangle3D(*(tetr_b.vertices[i] for i in face)) for _, face, _ in intrs]

    intersection_set = intersections(tetr_a, tetr_b)

    breakpoint()

    tetr_intersection = tetr_a | tetr_b
    assert len(tetr_intersection.faces) == 6

    tetr_union = tetr_a & tetr_b
    assert len(tetr_union.faces) == 10

    tetr_difference = tetr_a - tetr_b
    assert len(tetr_difference.faces) == 9


if __name__ == "__main__":
    test_simple_boolean_ops()
