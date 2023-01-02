"""Tests boolean operations for CPU."""

from fast_trimesh.fast_trimesh.cpu.boolean import difference, intersection, union
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid, sphere


def test_simple_boolean() -> None:
    """Tests boolean operations on some simple shapes."""

    expected = cuboid(1.0, 2.0, 3.0)
    assert union(expected, sphere(0.0, 0.0, 0.0, 0.0)) == expected
    assert intersection(expected, sphere(0.0, 0.0, 0.0, 0.0)) == sphere(0.0, 0.0, 0.0, 0.0)
    assert difference(expected, sphere(0.0, 0.0, 0.0, 0.0)) == expected
