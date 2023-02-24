"""Tests 3D IO functions."""

from pathlib import Path

import pytest

from tmesh import (
    Face,
    cuboid,
    load_obj,
    load_ply,
    load_stl,
    load_stl_text,
    save_obj,
    save_ply,
    save_stl,
    save_stl_text,
)


def test_trimesh_io(tmpdir: Path) -> None:
    """Tests serializing and deserializing 3D trimeshes.

    Args:
        tmpdir: The temporary directory to use for testing.
    """

    # Gets a trimesh.
    tr_a = cuboid(1.0, 1.0, 1.0)

    # Tests saving and loading the trimesh as an STL.
    stl_path = str(tmpdir / "file.stl")
    save_stl(stl_path, tr_a)
    tr_d = load_stl(stl_path)

    assert len(tr_d.vertices) == len(tr_a.vertices), len(tr_d.vertices)
    assert len(tr_d.faces) == len(tr_a.faces), len(tr_d.faces)
    assert sorted(tr_d.vertices) == sorted(tr_a.vertices)

    # Remaps `tr_d` faces to `tr_a` faces.
    tr_a_ids = {v: i for i, v in enumerate(tr_a.vertices)}
    tr_d_mappings = {i: tr_a_ids[v] for i, v in enumerate(tr_d.vertices)}
    tr_d_faces = [Face(tr_d_mappings[f.a], tr_d_mappings[f.b], tr_d_mappings[f.c]) for f in tr_d.faces]

    # Checks that the sorted faces are the same.
    for a_face, d_face in zip(sorted(tr_a.faces), sorted(tr_d_faces)):
        assert a_face == d_face

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

    # Remaps `tr_e` faces to `tr_a` faces.
    tr_e_mappings = {i: tr_a_ids[v] for i, v in enumerate(tr_e.vertices)}
    tr_e_faces = [Face(tr_e_mappings[f.a], tr_e_mappings[f.b], tr_e_mappings[f.c]) for f in tr_e.faces]

    # Checks that the sorted faces are the same.
    for a_face, e_face in zip(sorted(tr_a.faces), sorted(tr_e_faces)):
        assert a_face == e_face

    # Tests saving and loading the trimesh as an OBJ.
    obj_path = str(tmpdir / "file.obj")
    save_obj(obj_path, tr_a)
    tr_f = load_obj(obj_path)
    assert len(tr_f.vertices) == len(tr_a.vertices), len(tr_f.vertices)
    assert len(tr_f.faces) == len(tr_a.faces), len(tr_f.faces)
    assert all(a.distance_to_point(b) == pytest.approx(0, abs=1e-5) for a, b in zip(tr_f.vertices, tr_a.vertices))
    assert sorted(tr_f.faces) == sorted(tr_a.faces)

    # Tests saving and loading the trimesh as a PLY.
    ply_path = str(tmpdir / "file.ply")
    save_ply(ply_path, tr_a)
    tr_g = load_ply(ply_path)
    assert len(tr_g.vertices) == len(tr_a.vertices), len(tr_g.vertices)
    assert len(tr_g.faces) == len(tr_a.faces), len(tr_g.faces)
    assert all(a.distance_to_point(b) == pytest.approx(0, abs=1e-5) for a, b in zip(tr_g.vertices, tr_a.vertices))
    assert sorted(tr_g.faces) == sorted(tr_a.faces)


if __name__ == "__main__":
    outdir = Path("out")
    outdir.mkdir(exist_ok=True)
    for file in outdir.glob("*"):
        file.unlink()
    test_trimesh_io(outdir)
