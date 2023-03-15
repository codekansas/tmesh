# ruff: noqa
"""Plots 3D objects using Matplotlib. Useful for debugging."""

import random
from tmesh import *
from utils.plot_3d import plot_things


def main() -> None:
    random.seed(1337)

    # points = [Point3D(*(random.random() for _ in range(3))) for _ in range(10)]
    # tetramesh = triangulate_3d(points, shuffle=True)
    # plot_things([tetramesh])

    v1 = Point3D(0, 0, 1)
    v2 = Point3D(1, 0, 0)
    v3 = Point3D(-1, 0, 0)
    v4 = Point3D(0, 0.5, 0)
    v5 = Point3D(0, -0.5, 0)

    fa = v1
    fb = v2
    fc = v3
    pi = v4
    pj = v5

    t1 = Tetrahedron3D(fa, fb, fc, pi)
    t2 = Tetrahedron3D(pj, fa, fb, fc)

    t3 = Tetrahedron3D(pi, fb, fa, pj)
    t4 = Tetrahedron3D(pi, fc, fb, pj)
    t5 = Tetrahedron3D(pi, fa, fc, pj)

    plot_things([t1, t2])
    # plot_things([t3, t4, t5])


if __name__ == "__main__":
    # python -m scripts.plot_3d
    main()
