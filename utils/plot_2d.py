"""Utility functions for plotting in 2D."""

from typing import List, Union

import matplotlib.pyplot as plt

from tmesh import Circle2D, Line2D, Point2D, Triangle2D, Trimesh2D

Thing = Union[Line2D, Point2D, Triangle2D, Trimesh2D, Circle2D]

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


def plot_circle(circle: Circle2D, i: int) -> None:
    """Plots a circle.

    Args:
        circle: Circle to plot.
        i: Index of circle.
    """

    plt_circle = plt.Circle((circle.center.x, circle.center.y), circle.radius, color=get_color(i), fill=False)
    plt.gca().add_patch(plt_circle)

    # Adjusts the plot to fit the circle.
    cur_min_x, cur_max_x = plt.xlim()
    cur_min_y, cur_max_y = plt.ylim()
    new_min_x, new_max_x = circle.center.x - circle.radius, circle.center.x + circle.radius
    new_min_y, new_max_y = circle.center.y - circle.radius, circle.center.y + circle.radius
    plt.xlim(min(cur_min_x, new_min_x), max(cur_max_x, new_max_x))
    plt.ylim(min(cur_min_y, new_min_y), max(cur_max_y, new_max_y))


def plot_things(things: List[Thing]) -> None:
    """Plots the things.

    Args:
        things: Things to plot.

    Raises:
        ValueError: If things contains an unknown thing.
    """

    plt.figure()

    for i, thing in enumerate(things):
        if isinstance(thing, Line2D):
            plot_line(thing, i)
        elif isinstance(thing, Point2D):
            plot_point(thing, i)
        elif isinstance(thing, Triangle2D):
            plot_triangle(thing, i)
        elif isinstance(thing, Trimesh2D):
            plot_trimesh(thing, i)
        elif isinstance(thing, Circle2D):
            plot_circle(thing, i)
        else:
            raise ValueError(f"Unsupported type: {type(thing)}")

    plt.show()
