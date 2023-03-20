"""Utility functions for plotting in 3D."""

from typing import Sequence, Union

import matplotlib.pyplot as plt
import numpy as np

from tmesh import DelaunaySplitTree3D, Line3D, Point3D, Sphere3D, Tetrahedron3D, Tetramesh3D, Triangle3D, Trimesh3D

Thing = Union[DelaunaySplitTree3D, Line3D, Point3D, Sphere3D, Tetrahedron3D, Tetramesh3D, Triangle3D, Trimesh3D]


def get_color(i: int) -> str:
    """Returns the color of a thing.

    Args:
        i: Index of thing.

    Returns:
        Color of thing.
    """

    colors = ["r", "g", "b", "c", "m", "y", "k"]
    return colors[i % len(colors)]


def plot_line(axes: plt.Axes, line: Line3D, i: int, alpha: float = 1.0) -> None:
    """Plots a line.

    Args:
        axes: Axes to plot on.
        line: Line to plot.
        i: Index of line.
        alpha: Alpha value.
    """

    axes.plot3D([line.p1.x, line.p2.x], [line.p1.y, line.p2.y], [line.p1.z, line.p2.z], get_color(i), alpha=alpha)


def plot_point(axes: plt.Axes, point: Point3D, i: int, alpha: float = 1.0) -> None:
    """Plots a point.

    Args:
        axes: Axes to plot on.
        point: Point to plot.
        i: Index of point.
        alpha: Alpha value.
    """

    axes.plot3D(point.x, point.y, point.z, get_color(i) + "o", alpha=alpha)


def plot_sphere(axes: plt.Axes, sphere: Sphere3D, i: int, alpha: float = 1.0) -> None:
    """Plots a sphere.

    Args:
        axes: Axes to plot on.
        sphere: Sphere to plot.
        i: Index of sphere.
        alpha: Alpha value.
    """

    u, v = np.mgrid[0 : 2 * np.pi : 20j, 0 : np.pi : 10j]  # type: ignore
    x = sphere.center.x + sphere.radius * np.cos(u) * np.sin(v)
    y = sphere.center.y + sphere.radius * np.sin(u) * np.sin(v)
    z = sphere.center.z + sphere.radius * np.cos(v)
    axes.plot_wireframe(x, y, z, color=get_color(i), alpha=alpha)


def plot_triangle(
    axes: plt.Axes,
    triangle: Triangle3D,
    i: int,
    labels: tuple[str, str, str] | None = None,
    alpha: float = 1.0,
) -> None:
    """Plots a triangle.

    Args:
        axes: Axes to plot on.
        triangle: Triangle to plot.
        i: Index of triangle.
        lables: Labels for the vertices.
        alpha: Alpha value.
    """

    axes.plot3D(
        [triangle.p1.x, triangle.p2.x, triangle.p3.x, triangle.p1.x],
        [triangle.p1.y, triangle.p2.y, triangle.p3.y, triangle.p1.y],
        [triangle.p1.z, triangle.p2.z, triangle.p3.z, triangle.p1.z],
        get_color(i),
        alpha=alpha,
    )

    if labels is not None:
        axes.text(triangle.p1.x, triangle.p1.y, triangle.p1.z, labels[0])
        axes.text(triangle.p2.x, triangle.p2.y, triangle.p2.z, labels[1])
        axes.text(triangle.p3.x, triangle.p3.y, triangle.p3.z, labels[2])


def plot_tetrahedron(
    axes: plt.Axes,
    tetrahedron: Tetrahedron3D,
    i: int,
    labels: tuple[str, str, str, str] | None = None,
    alpha: float = 1.0,
) -> None:
    """Plots a tetrahedron.

    Args:
        axes: Axes to plot on.
        tetrahedron: Tetrahedron to plot.
        i: Index of tetrahedron.
        alpha: Alpha value.
    """

    # Scales down the tetrahedron a little bit.
    # from tmesh import Affine3D
    # c = tetrahedron.centroid()
    # v = (c.x / 2, c.y / 2, c.z / 2)
    # neg_v = (-v[0], -v[1], -v[2])
    # tetrahedron <<= Affine3D(trans=neg_v) @ Affine3D(scale=0.4) @ Affine3D(trans=v)

    for face in tetrahedron.faces:
        plot_triangle(axes, face, i, alpha=alpha)

    if labels is not None:
        axes.text(tetrahedron.p1.x, tetrahedron.p1.y, tetrahedron.p1.z, labels[0])
        axes.text(tetrahedron.p2.x, tetrahedron.p2.y, tetrahedron.p2.z, labels[1])
        axes.text(tetrahedron.p3.x, tetrahedron.p3.y, tetrahedron.p3.z, labels[2])
        axes.text(tetrahedron.p4.x, tetrahedron.p4.y, tetrahedron.p4.z, labels[3])


def plot_trimesh(axes: plt.Axes, trimesh: Trimesh3D, i: int, alpha: float = 1.0) -> None:
    """Plots a trimesh.

    Args:
        axes: Axes to plot on.
        trimesh: Trimesh to plot.
        i: Index of trimesh.
        alpha: Alpha value.
    """

    for triangle in trimesh.get_triangles():
        plot_triangle(axes, triangle, i, alpha=alpha)


def plot_tetramesh(axes: plt.Axes, tetramesh: Tetramesh3D, i: int, alpha: float = 1.0) -> None:
    """Plots a tetramesh.

    Args:
        axes: Axes to plot on.
        tetramesh: Tetramesh to plot.
        i: Index of tetramesh.
        alpha: Alpha value.
    """

    for volume in tetramesh.volumes:
        labels = (str(volume.a), str(volume.b), str(volume.c), str(volume.d))
        tetrahedron = tetramesh.get_tetrahedron(volume)
        plot_tetrahedron(axes, tetrahedron, i, labels=labels, alpha=alpha)


def plot_split_tree(
    axes: plt.Axes,
    split_tree: DelaunaySplitTree3D,
    i: int,
    alpha: float = 1.0,
) -> None:
    """Plots a split tree.

    Args:
        axes: Axes to plot on.
        split_tree: Split tree to plot.
        i: Index of split tree.
        alpha: Alpha value.
    """

    for leaf_index in split_tree.get_leaf_indices():
        v = split_tree.get_volume(leaf_index)
        labels = (str(v.a), str(v.b), str(v.c), str(v.d))
        plot_tetrahedron(axes, split_tree.get_tetrahedron(leaf_index), i, labels=labels, alpha=alpha)


def plot_things(things: Sequence[Thing], alpha: float = 1.0) -> None:
    """Plots the things.

    Args:
        things: Things to plot.
        alpha: Alpha value.

    Raises:
        ValueError: If things contains an unknown thing.
    """

    axes = plt.figure().add_subplot(projection="3d")

    for i, thing in enumerate(things):
        if isinstance(thing, Line3D):
            plot_line(axes, thing, i, alpha=alpha)
        elif isinstance(thing, Point3D):
            plot_point(axes, thing, i, alpha=alpha)
        elif isinstance(thing, Sphere3D):
            plot_sphere(axes, thing, i, alpha=alpha)
        elif isinstance(thing, Triangle3D):
            plot_triangle(axes, thing, i, alpha=alpha)
        elif isinstance(thing, Trimesh3D):
            plot_trimesh(axes, thing, i, alpha=alpha)
        elif isinstance(thing, Tetrahedron3D):
            plot_tetrahedron(axes, thing, i, alpha=alpha)
        elif isinstance(thing, Tetramesh3D):
            plot_tetramesh(axes, thing, i, alpha=alpha)
        elif isinstance(thing, DelaunaySplitTree3D):
            plot_split_tree(axes, thing, i, alpha=alpha)
        else:
            raise ValueError(f"Unknown thing to plot: {thing}")

    plt.show()
