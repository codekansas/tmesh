# ruff: noqa
"""Plots 3D objects using Matplotlib. Useful for debugging."""

import random
from tmesh import *
from tmesh.py.utils.plot_3d import plot_things


def main() -> None:
    # points = [
    #     Point3D(0, 0, 0),
    #     Point3D(1, 0, 0),
    #     Point3D(0, 1, 0),
    #     Point3D(0, 0, 1),
    #     Point3D(1, 1, 1),
    # ]

    # random.seed(1338)
    # random.shuffle(points)

    # tetramesh = triangulate_3d(points, shuffle=False)

    # plot_things([tetramesh])

    tetra = Tetrahedron3D(
        Point3D(0, 0, 0),
        Point3D(1, 0, 0),
        Point3D(0, 1, 0),
        Point3D(0.25, 0.25, 1),
    )
    tree = DelaunaySplitTree3D(tetra)

    points = [Point3D(0.25, 0.25, 0), Point3D(0.25, 0.3, 0)]

    # Inserts each point.
    for point in points:
        i = tree.find_leaf_index(point)
        tree.split_tetrahedron(point, i, make_delaunay=True)

    tetrahedra = [tree.get_tetrahedron(v) for v in tree.get_leaf_indices()]

    plot_things(tetrahedra, alpha=0.5)


if __name__ == "__main__":
    # python -m scripts.plot_3d
    main()
