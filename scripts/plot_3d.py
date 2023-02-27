# ruff: noqa
"""Plots 3D objects using Matplotlib. Useful for debugging."""

from tmesh import *
from utils.plot_3d import plot_things


def main() -> None:
    plot_things(
        [
            Tetrahedron3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(0.25, 0.25, 1)),
            Tetrahedron3D(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(0.25, 0.25, -1)),
        ]
    )


if __name__ == "__main__":
    # python -m scripts.plot_3d
    main()
