"""Tests the CPU trimesh implementation."""

import random

from fast_trimesh.fast_trimesh.cpu.trimesh import Trimesh3D


def test_simple_trimesh_ops() -> None:
    """Tests simple trimesh operations.

    This test creates two trimeshes, adds some random vertices and
    faces to each, and then tests adding the two trimeshes together.
    """

    tr_a, tr_b = Trimesh3D(), Trimesh3D()

    # Add some random vertices.
    for _ in range(10):
        tr_a.add_vertex((random.random(), random.random(), random.random()))
        tr_b.add_vertex((random.random(), random.random(), random.random()))

    # Add some random faces.
    for _ in range(10):
        tr_a.add_face(random.randint(0, 9), random.randint(0, 9), random.randint(0, 9))
        tr_b.add_face(random.randint(0, 9), random.randint(0, 9), random.randint(0, 9))

    # Tests adding the two trimeshes together.
    tr_c = tr_a + tr_b
    assert len(tr_c.vertices) == 20
    assert len(tr_c.faces) == 20

    # Tests adding the two trimeshes together in-place.
    tr_a += tr_b
    assert len(tr_a.vertices) == 20
    assert len(tr_a.faces) == 20

    assert tr_c.vertices == tr_a.vertices
    assert tr_c.faces == tr_a.faces
