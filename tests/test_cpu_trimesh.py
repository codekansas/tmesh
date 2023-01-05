"""Tests the CPU trimesh implementation."""

import random
from pathlib import Path

import pytest

from fast_trimesh.cpu.io import (
    load_obj,
    load_ply,
    load_stl,
    load_stl_text,
    save_obj,
    save_ply,
    save_stl,
    save_stl_text,
)
from fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.cpu.trimesh import Trimesh2D
from fast_trimesh.cpu.types import Affine3D, Point2D, Polygon2D


@pytest.mark.parametrize(
    "points,valid",
    [
        ([], False),
        ([Point2D(0.0, 0.0)], False),
        ([Point2D(0.0, 0.0), Point2D(1.0, 0.0)], False),
        ([Point2D(0.0, 0.0), Point2D(1.0, 0.0), Point2D(0.0, 1.0)], True),
    ],
)
def test_validate_2d_trimesh(points: list[Point2D], valid: bool) -> None:
    """Tests validating a 2D trimesh.

    Args:
        points: The polygon to test.
        valid: Whether the polygon is valid.
    """

    if valid:
        Trimesh2D(Polygon2D(points)).validate()
    else:
        with pytest.raises(RuntimeError):
            Trimesh2D(Polygon2D(points)).validate()


def test_simple_trimesh_ops(tmpdir: Path) -> None:
    """Tests simple trimesh operations.

    This test creates two trimeshes, adds some random vertices and
    faces to each, and then tests adding the two trimeshes together.

    This test also tests serializing the trimeshes to disk using various
    formats.

    Args:
        tmpdir: The temporary directory to use for testing.
    """

    # Gets two trimeshes.
    tr_a, tr_b = cuboid(1.0, 1.0, 1.0), cuboid(1.0, 1.0, 1.0)

    # Applies a random transformation to the second trimesh, moving it
    # far enough away from the first trimesh that the two trimeshes
    # should not overlap.
    rot = Affine3D(rot=(random.random(), random.random(), random.random()))
    trans = Affine3D(trans=(3.0, 3.0, 3.0))
    tr_b = tr_b << rot @ trans

    # Tests the intersection of two trimeshes.
    tr_c = tr_a & tr_b

    # Tests adding the two trimeshes together in-place.
    tr_a &= tr_b
    assert tr_c.vertices == tr_a.vertices
    assert tr_c.faces == tr_a.faces

    # Tests saving and loading the trimesh as an STL.
    stl_path = str(tmpdir / "file.stl")
    save_stl(stl_path, tr_a)
    tr_d = load_stl(stl_path)

    assert len(tr_d.vertices) == len(tr_a.vertices), len(tr_d.vertices)
    assert len(tr_d.faces) == len(tr_a.faces), len(tr_d.faces)
    assert sorted(tr_d.vertices) == sorted(tr_a.vertices)

    # Converts the faces and vertices to the absolute vertices.
    tr_a_face_vertices = sorted([tuple(tr_a.vertices[j] for j in i) for i in tr_a.faces])
    tr_d_face_vertices = sorted([tuple(tr_d.vertices[j] for j in i) for i in tr_d.faces])
    assert tr_a_face_vertices == tr_d_face_vertices

    # Tests saving and loading the trimesh as a text STL.
    stl_path = str(tmpdir / "file.stl")
    save_stl_text(stl_path, tr_a)
    tr_e = load_stl_text(stl_path)

    assert len(tr_e.vertices) == len(tr_a.vertices), len(tr_e.vertices)
    assert len(tr_e.faces) == len(tr_e.faces), len(tr_e.faces)
    assert all(
        a.distance_to_point(b) == pytest.approx(0, abs=1e-3)
        for a, b in zip(sorted(tr_e.vertices), sorted(tr_a.vertices))
    )

    # Converts the faces and vertices to the absolute vertices.
    tr_a_face_vertices = sorted([tuple(tr_a.vertices[j] for j in i) for i in tr_a.faces])
    tr_e_face_vertices = sorted([tuple(tr_e.vertices[j] for j in i) for i in tr_e.faces])
    assert all(
        aa.distance_to_point(bb) == pytest.approx(0, abs=1e-3)
        for a, b in zip(tr_a_face_vertices, tr_e_face_vertices)
        for aa, bb in zip(a, b)
    )

    # Tests saving and loading the trimesh as an OBJ.
    obj_path = str(tmpdir / "file.obj")
    save_obj(obj_path, tr_a)
    tr_f = load_obj(obj_path)
    assert len(tr_f.vertices) == len(tr_a.vertices), len(tr_f.vertices)
    assert len(tr_f.faces) == len(tr_a.faces), len(tr_f.faces)
    assert all(a.distance_to_point(b) == pytest.approx(0, abs=1e-5) for a, b in zip(tr_f.vertices, tr_a.vertices))
    assert tr_f.faces == tr_a.faces

    # Tests saving and loading the trimesh as a PLY.
    ply_path = str(tmpdir / "file.ply")
    save_ply(ply_path, tr_a)
    tr_g = load_ply(ply_path)
    assert len(tr_g.vertices) == len(tr_a.vertices), len(tr_g.vertices)
    assert len(tr_g.faces) == len(tr_a.faces), len(tr_g.faces)
    assert all(a.distance_to_point(b) == pytest.approx(0, abs=1e-5) for a, b in zip(tr_g.vertices, tr_a.vertices))
    assert tr_g.faces == tr_a.faces
