"""Tests the CPU trimesh implementation."""

import random
from pathlib import Path

import pytest

from fast_trimesh.fast_trimesh.cpu.io import load_obj, load_stl, save_obj, save_stl
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.fast_trimesh.cpu.trimesh import AffineTransformation, triangulate

Point2D = tuple[float, float]


@pytest.mark.parametrize(
    "polygon,valid",
    [
        ([], False),
        ([(0.0, 0.0)], False),
        ([(0.0, 0.0), (1.0, 0.0)], False),
        ([(0.0, 0.0), (1.0, 0.0), (0.0, 1.0)], True),
    ],
)
def test_validate_2d_trimesh(polygon: list[Point2D], valid: bool) -> None:
    """Tests validating a 2D trimesh.

    Args:
        polygon: The polygon to test.
        valid: Whether the polygon is valid.
    """

    if valid:
        triangulate(polygon).validate()
    else:
        with pytest.raises(RuntimeError):
            triangulate(polygon).validate()


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

    # Tests saving and loading the trimesh as an STL.
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

    # Tests saving and loading the trimesh as an OBJ.
    obj_path = str(tmpdir / "file.obj")
    save_obj(obj_path, tr_a)
    tr_e = load_obj(obj_path)
    assert len(tr_e.vertices) == 16, len(tr_e.vertices)
    assert len(tr_e.faces) == 24, len(tr_e.faces)
    assert all(a == pytest.approx(b, abs=1e-5) for a, b in zip(tr_e.vertices, tr_a.vertices))
    assert tr_e.faces == tr_a.faces
