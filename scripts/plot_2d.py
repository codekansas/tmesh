from typing import List, Union

import matplotlib.pyplot as plt

from fast_trimesh import Line2D, Point2D, Triangle2D, Trimesh2D, regular_polygon_mesh

Thing = Union[Line2D, Point2D, Triangle2D, Trimesh2D]

# To plot things, add them to this list.
THINGS_TO_PLOT: List[Thing] = [
    Triangle2D(Point2D(-1.0, 2.0), Point2D(1.0, 2.0), Point2D(0.0, 1.0)),
    regular_polygon_mesh(1.0, 4),
]


def plot_line(line: Line2D) -> None:
    """Plots a line.

    Args:
        line: Line to plot.
    """

    plt.plot([line.p1.x, line.p2.x], [line.p1.y, line.p2.y], "k")


def plot_point(point: Point2D) -> None:
    """Plots a point.

    Args:
        point: Point to plot.
    """

    plt.plot(point.x, point.y, "ko")


def plot_triangle(triangle: Triangle2D) -> None:
    """Plots a triangle.

    Args:
        triangle: Triangle to plot.
    """

    plt.plot(
        [triangle.p1.x, triangle.p2.x, triangle.p3.x, triangle.p1.x],
        [triangle.p1.y, triangle.p2.y, triangle.p3.y, triangle.p1.y],
        "k",
    )


def plot_trimesh(trimesh: Trimesh2D) -> None:
    """Plots a trimesh.

    Args:
        trimesh: Trimesh to plot.
    """

    for triangle in trimesh.get_triangles():
        plot_triangle(triangle)


def main() -> None:
    """Plots some 2D objects."""

    plt.figure()

    for thing in THINGS_TO_PLOT:
        if isinstance(thing, Line2D):
            plot_line(thing)
        elif isinstance(thing, Point2D):
            plot_point(thing)
        elif isinstance(thing, Triangle2D):
            plot_triangle(thing)
        elif isinstance(thing, Trimesh2D):
            plot_trimesh(thing)
        else:
            raise ValueError(f"Unsupported type: {type(thing)}")

    plt.show()


if __name__ == "__main__":
    main()
