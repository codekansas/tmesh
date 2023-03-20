"""Tests axis aligned bounding box data structure for CPU."""

import pytest

from tmesh import DelaunaySplitTree3D, Point3D, Tetrahedron3D


@pytest.mark.parametrize(
    "point",
    [
        Point3D(0, 0, 0),  # On a vertex
        Point3D(0.5, 0, 0),  # On an edge
        Point3D(0.5, 0.5, 0),  # On a face
        Point3D(0.25, 0.25, 0.25),  # Inside
    ],
)
def test_simple_split_tree_3d(point: Point3D) -> None:
    """Creates a Delaunay split tree from a tetrahedron and inserts a point.

    Args:
        point: Point to insert.
    """

    tetra = Tetrahedron3D(
        Point3D(0, 0, 0),
        Point3D(1, 0, 0),
        Point3D(0, 1, 0),
        Point3D(0, 0, 1),
    )
    tree = DelaunaySplitTree3D(tetra)
    tree.split_tetrahedron(point, 0)


@pytest.mark.parametrize(
    "points,make_delaunay,num_tetras",
    [
        ([Point3D(0.5, 0.5, 0), Point3D(0.25, 0.25, 0), Point3D(0.25, 0.25, 0.5)], False, 8),
        ([Point3D(0.25, 0.25, 0.5)], False, 4),
        # ([Point3D(0.25, 0.25, 0), Point3D(0.25, 0.3, 0)], True, 6),
        # ([Point3D(0.25, 0.25, 0.5), Point3D(0.25, 0.3, 0.5)], True, 7),
        ([Point3D(0.2, 0.2, 0.2), Point3D(0.3, 0.3, 0.1)], True, 8),
    ],
)
def test_split_tree_multi_insert_3d(points: list[Point3D], make_delaunay: bool, num_tetras: int) -> None:
    """Creates a Delaunay split tree and inserts multiple points.

    Args:
        points: Points to insert.
        make_delaunay: Whether to make the split tree Delaunay.
        num_tetras: Number of tetrahedra in the split tree.
    """

    tetra = Tetrahedron3D(
        Point3D(0, 0, 0),
        Point3D(1, 0, 0),
        Point3D(0, 1, 0),
        Point3D(0.25, 0.25, 1),
    )
    tree = DelaunaySplitTree3D(tetra)

    # Inserts each point.
    for point in points:
        i = tree.find_leaf_index(point)
        tree.split_tetrahedron(point, i, make_delaunay=make_delaunay)

    assert len(tree.get_leaf_indices()) == num_tetras, f"{len(tree.get_leaf_indices())} != {num_tetras}"

    volumes = [tree.get_tetrahedron(i).signed_volume() for i in tree.get_leaf_indices()]
    assert all(v > 0 for v in volumes)
    assert sum(volumes) == pytest.approx(tetra.signed_volume())
