# ruff: noqa
"""Plots 3D objects using Matplotlib. Useful for debugging."""

import random
from tmesh import *
from utils.plot_3d import plot_things


def main() -> None:
    random.seed(1337)
    points = [Point3D(*(random.random() for _ in range(3))) for _ in range(10)]
    tetramesh = triangulate_3d(points, shuffle=True)
    plot_things([tetramesh])


if __name__ == "__main__":
    # python -m scripts.plot_3d
    main()
