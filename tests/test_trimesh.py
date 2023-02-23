"""Tests the trimesh implementation."""

import pytest

from tmesh import (
    Point2D,
    Polygon2D,
)


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
        Polygon2D(points).get_trimesh()
    else:
        with pytest.raises(RuntimeError):
            Polygon2D(points).get_trimesh()
