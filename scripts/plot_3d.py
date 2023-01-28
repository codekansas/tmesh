"""Plots 3D objects using Matplotlib. Useful for debugging."""

from typing import List, Union

import matplotlib.pyplot as plt

from tmesh import Line3D, Point3D, Tetrahedron3D, Triangle3D, Trimesh3D

Thing = Union[Line3D, Point3D, Tetrahedron3D, Triangle3D, Trimesh3D]

# To plot things, add them to this list.
THINGS_TO_PLOT: List[Thing] = []

ALPHA = 1.0


def get_color(i: int) -> str:
    """Returns the color of a thing.

    Args:
        i: Index of thing.

    Returns:
        Color of thing.
    """

    colors = ["r", "g", "b", "c", "m", "y", "k"]
    return colors[i % len(colors)]


def plot_line(axes: plt.Axes, line: Line3D, i: int) -> None:
    """Plots a line.

    Args:
        axes: Axes to plot on.
        line: Line to plot.
        i: Index of line.
    """

    axes.plot3D([line.p1.x, line.p2.x], [line.p1.y, line.p2.y], [line.p1.z, line.p2.z], get_color(i), alpha=ALPHA)


def plot_point(axes: plt.Axes, point: Point3D, i: int) -> None:
    """Plots a point.

    Args:
        axes: Axes to plot on.
        point: Point to plot.
        i: Index of point.
    """

    axes.plot3D(point.x, point.y, point.z, get_color(i) + "o", alpha=ALPHA)


def plot_triangle(axes: plt.Axes, triangle: Triangle3D, i: int) -> None:
    """Plots a triangle.

    Args:
        axes: Axes to plot on.
        triangle: Triangle to plot.
        i: Index of triangle.
    """

    axes.plot3D(
        [triangle.p1.x, triangle.p2.x, triangle.p3.x, triangle.p1.x],
        [triangle.p1.y, triangle.p2.y, triangle.p3.y, triangle.p1.y],
        [triangle.p1.z, triangle.p2.z, triangle.p3.z, triangle.p1.z],
        get_color(i),
        alpha=ALPHA,
    )


def plot_tetrahedron(axes: plt.Axes, tetrahedron: Tetrahedron3D, i: int) -> None:
    """Plots a tetrahedron.

    Args:
        axes: Axes to plot on.
        tetrahedron: Tetrahedron to plot.
        i: Index of tetrahedron.
    """

    for face in tetrahedron.faces:
        plot_triangle(axes, face, i)


def plot_trimesh(axes: plt.Axes, trimesh: Trimesh3D, i: int) -> None:
    """Plots a trimesh.

    Args:
        axes: Axes to plot on.
        trimesh: Trimesh to plot.
        i: Index of trimesh.
    """

    for triangle in trimesh.get_triangles():
        plot_triangle(axes, triangle, i)


def main() -> None:
    """Plots the things in THINGS_TO_PLOT.

    Raises:
        ValueError: If THINGS_TO_PLOT contains an unknown thing.
    """

    axes = plt.figure().add_subplot(projection="3d")

    for i, thing in enumerate(THINGS_TO_PLOT):
        if isinstance(thing, Line3D):
            plot_line(axes, thing, i)
        elif isinstance(thing, Point3D):
            plot_point(axes, thing, i)
        elif isinstance(thing, Triangle3D):
            plot_triangle(axes, thing, i)
        elif isinstance(thing, Trimesh3D):
            plot_trimesh(axes, thing, i)
        elif isinstance(thing, Tetrahedron3D):
            plot_tetrahedron(axes, thing, i)
        else:
            raise ValueError(f"Unknown thing to plot: {thing}")

    plt.show()


if __name__ == "__main__":
    main()
