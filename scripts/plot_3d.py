# ruff: noqa
"""Plots 3D objects using Matplotlib. Useful for debugging."""

import random
from tmesh import *
from utils.plot_3d import plot_things


def main() -> None:

    points = [
        Point3D(0, 0, 0),
        Point3D(1, 0, 0),
        Point3D(0, 1, 0),
        Point3D(0, 0, 1),
        Point3D(1, 1, 1),
    ]

    random.seed(1339)
    random.shuffle(points)

    tetramesh = triangulate_3d(points, shuffle=False)

    plot_things([tetramesh])


if __name__ == "__main__":
    # python -m scripts.plot_3d
    main()
