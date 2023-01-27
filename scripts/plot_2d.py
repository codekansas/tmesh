"""Plots 2D objects using Matplotlib. Useful for debugging."""

from typing import List, Union

import matplotlib.pyplot as plt

from tmesh import Line2D, Point2D, Triangle2D, Trimesh2D

Thing = Union[Line2D, Point2D, Triangle2D, Trimesh2D]

import math
from tmesh import Affine2D, linear_extrude, regular_polygon_mesh, save_stl

scale = Affine2D(scale=1.0)
rotate = Affine2D(rot=math.pi / 3)
translate = Affine2D(trans=(0.75, 0.0))

mesh = regular_polygon_mesh(1.0, n=3)

mesh_union = mesh & (mesh << scale @ rotate @ translate)
mesh_intersection = (mesh | (mesh << scale @ rotate @ translate)) << Affine2D(trans=(2.0, 0.0))
mesh_difference = (mesh - (mesh << scale @ rotate @ translate)) << Affine2D(trans=(-2.0, 0.0))

combined_mesh = mesh_intersection & mesh_difference & mesh_union

# print("combined_mesh.faces:")
# for f in combined_mesh.faces:
#     print(f)

linear_extrude(combined_mesh, 1.0)

# To plot things, add them to this list.
THINGS_TO_PLOT: List[Thing] = [
    combined_mesh,
]

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


def plot_line(line: Line2D, i: int) -> None:
    """Plots a line.

    Args:
        line: Line to plot.
        i: Index of line.
    """

    plt.plot([line.p1.x, line.p2.x], [line.p1.y, line.p2.y], get_color(i), alpha=ALPHA)


def plot_point(point: Point2D, i: int) -> None:
    """Plots a point.

    Args:
        point: Point to plot.
        i: Index of point.
    """

    plt.plot(point.x, point.y, get_color(i) + "o", alpha=ALPHA)


def plot_triangle(triangle: Triangle2D, i: int, labels: tuple[str, str, str] | None = None) -> None:
    """Plots a triangle.

    Args:
        triangle: Triangle to plot.
        i: Index of triangle.
        labels: Labels for triangle vertices.
    """

    plt.plot(
        [triangle.p1.x, triangle.p2.x, triangle.p3.x, triangle.p1.x],
        [triangle.p1.y, triangle.p2.y, triangle.p3.y, triangle.p1.y],
        get_color(i),
        alpha=ALPHA,
    )

    if labels is not None:
        plt.text(triangle.p1.x, triangle.p1.y, labels[0])
        plt.text(triangle.p2.x, triangle.p2.y, labels[1])
        plt.text(triangle.p3.x, triangle.p3.y, labels[2])


def plot_trimesh(trimesh: Trimesh2D, i: int) -> None:
    """Plots a trimesh.

    Args:
        trimesh: Trimesh to plot.
        i: Index of trimesh.
    """

    vertices = trimesh.vertices
    for face in trimesh.faces:
        triangle = Triangle2D(vertices[face.a], vertices[face.b], vertices[face.c])
        plot_triangle(triangle, i, labels=(str(face.a), str(face.b), str(face.c)))


def main() -> None:
    """Plots the things in THINGS_TO_PLOT.

    Raises:
        ValueError: If THINGS_TO_PLOT contains an unknown thing.
    """

    plt.figure()

    for i, thing in enumerate(THINGS_TO_PLOT):
        if isinstance(thing, Line2D):
            plot_line(thing, i)
        elif isinstance(thing, Point2D):
            plot_point(thing, i)
        elif isinstance(thing, Triangle2D):
            plot_triangle(thing, i)
        elif isinstance(thing, Trimesh2D):
            plot_trimesh(thing, i)
        else:
            raise ValueError(f"Unsupported type: {type(thing)}")

    plt.show()


if __name__ == "__main__":
    main()
