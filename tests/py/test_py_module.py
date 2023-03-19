import math

import pytest

from tmesh import Affine2D, Affine3D, Module, Point2D, Point3D, linear_extrude, regular_polygon_mesh


def test_simple_py_module() -> None:
    """Tests the Python Module API."""

    class SimpleModule(Module):
        def __init__(self, radius: float, height: float, n: int = 3) -> None:
            super().__init__()

            self.radius = radius
            self.height = height
            self.n = n

            mesh_2d = regular_polygon_mesh(radius, n=n)
            mesh_3d = linear_extrude(mesh_2d, height)

            self.mesh_2d = mesh_2d
            self.mesh_3d = mesh_3d

    module = SimpleModule(1.0, 2.0, 3)

    point_2d = module.mesh_2d.vertices[0]
    point_2d = Point2D(point_2d.x, point_2d.y)

    point_3d = module.mesh_3d.vertices[0]
    point_3d = Point3D(point_3d.x, point_3d.y, point_3d.z)

    affine_2d = Affine2D(rot=math.pi / 2) @ Affine2D(trans=(1.0, 2.0))
    affine_3d = Affine3D(rot=(math.pi, 0, 0)) @ Affine3D(trans=(1.0, 2.0, 3.0))

    module <<= affine_2d
    module <<= affine_3d

    with pytest.raises(TypeError):
        module = module << 1

    assert module.mesh_2d.vertices[0] == point_2d << affine_2d
    assert module.mesh_3d.vertices[0] == point_3d << affine_3d

    assert module.radius == 1.0
    assert module.height == 2.0
    assert module.n == 3
