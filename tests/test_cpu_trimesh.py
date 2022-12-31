"""Tests the CPU trimesh implementation."""

import random
from pathlib import Path

from fast_trimesh.fast_trimesh.cpu.io import load_stl, save_stl
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.fast_trimesh.cpu.trimesh import AffineTransformation


def test_simple_trimesh_ops(tmpdir: Path) -> None:
    """Tests simple trimesh operations.

    This test creates two trimeshes, adds some random vertices and
    faces to each, and then tests adding the two trimeshes together.
    """

    # Gets two trimeshes.
    tr_a, tr_b = cuboid(1.0, 1.0, 1.0), cuboid(1.0, 1.0, 1.0)

    # Applies a random transformation to the second trimesh, moving it
    # far enough away from the first trimesh that the two trimeshes
    # should not overlap.
    rand_tf = AffineTransformation(
        rotation=(random.random(), random.random(), random.random()),
        translation=(3.0, 3.0, 3.0),
    )
    tr_b <<= rand_tf

    # Tests adding the two trimeshes together.
    tr_c = tr_a + tr_b
    assert len(tr_c.vertices) == 16
    assert len(tr_c.faces) == 24

    # Tests adding the two trimeshes together in-place.
    tr_a += tr_b
    assert len(tr_a.vertices) == 16
    assert len(tr_a.faces) == 24

    assert tr_c.vertices == tr_a.vertices
    assert tr_c.faces == tr_a.faces

    # Tests saving and loading the trimesh.
    stl_path = str(tmpdir / "file.stl")
    save_stl(stl_path, tr_a)
    tr_d = load_stl(stl_path)

    assert len(tr_d.vertices) == 16, len(tr_d.vertices)
    assert len(tr_d.faces) == 24, len(tr_d.faces)
    assert set(tr_d.vertices) == set(tr_a.vertices)

    # Converts the faces and vertices to the absolute vertices.
    tr_a_face_vertices = [tuple(tr_a.vertices[j] for j in i) for i in tr_a.faces]
    tr_d_face_vertices = [tuple(tr_d.vertices[j] for j in i) for i in tr_d.faces]
    assert tr_a_face_vertices == tr_d_face_vertices
