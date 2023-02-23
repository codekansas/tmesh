"""Tests 2D IO functions."""

import random
from pathlib import Path

from tmesh import Affine2D, Point2D, regular_polygon_mesh, save_svg, triangulate_2d


def test_simple_trimesh_io_2d(tmpdir: Path) -> None:
    """Tests simple IO operations for a 2D Delaunay triangulation.

    Args:
        tmpdir: The temporary directory to use for testing.
    """

    random.seed(1337)
    points = [Point2D(random.random() * 1000.0, random.random() * 1000.0) for _ in range(100)]
    tr = triangulate_2d(points, shuffle=False)

    svg_path = str(tmpdir / "file.svg")
    save_svg(svg_path, tr)


def test_trimesh_union_io_2d(tmpdir: Path) -> None:
    """Tests simple IO operations for 2D triangular meshes.

    Args:
        tmpdir: The temporary directory to use for testing.
    """

    tr_a = regular_polygon_mesh(500.0, n=5) << Affine2D(trans=(250.0, 0.0))
    tr_b = regular_polygon_mesh(500.0, n=50) << Affine2D(trans=(0.0, 0.0))
    tr_c = (tr_a | tr_b).make_delaunay()

    svg_path = str(tmpdir / "file.svg")
    save_svg(svg_path, tr_c)
