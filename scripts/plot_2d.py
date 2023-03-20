# ruff: noqa
"""Plots 3D objects using Matplotlib. Useful for debugging."""

from tmesh import *
from tmesh.py.utils.plot_2d import plot_things


def main() -> None:
    plot_things(
        [
            Triangle2D(Point2D(0, 0), Point2D(1, 0), Point2D(0, 1)),
        ]
    )


if __name__ == "__main__":
    # python -m scripts.plot_2d
    main()
