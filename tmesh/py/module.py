from typing import Any, Type, TypeVar

from tmesh.cpp import (
    Affine2D,
    Affine3D,
    BoundingBox2D,
    BoundingBox3D,
    Circle2D,
    Line2D,
    Line3D,
    Point2D,
    Point3D,
    Polygon2D,
    Polygon3D,
    Sphere3D,
    Tetrahedron3D,
    Tetramesh3D,
    Triangle2D,
    Triangle3D,
    Trimesh2D,
    Trimesh3D,
)

TwoTypes: tuple[Type, ...] = (
    Circle2D,
    Line2D,
    Point2D,
    Polygon2D,
    Sphere3D,
    Triangle2D,
    Trimesh2D,
    BoundingBox2D,
)

ThreeTypes: tuple[Type, ...] = (
    Line3D,
    Point3D,
    Polygon3D,
    Tetrahedron3D,
    Tetramesh3D,
    Triangle3D,
    Trimesh3D,
    BoundingBox3D,
)

T = TypeVar("T", bound="Module")


class Module:
    def __init__(self) -> None:
        self.__two_d_dict: dict[str, Affine2D] = {}
        self.__three_d_dict: dict[str, Affine3D] = {}

    def __setattr__(self, name: str, value: Any) -> None:
        if name in "__two_d_dict" or name in "__three_d_dict":
            super().__setattr__(name, value)
            return
        if isinstance(value, TwoTypes):
            if not hasattr(self, "_Module__two_d_dict"):
                raise ValueError("Missing call to super().__init__()")
            self.__two_d_dict[name] = value
        elif isinstance(value, ThreeTypes):
            if not hasattr(self, "_Module__three_d_dict"):
                raise ValueError("Missing call to super().__init__()")
            self.__three_d_dict[name] = value
        super().__setattr__(name, value)

    def __lshift__(self: T, other: Affine2D | Affine3D) -> T:
        self <<= other
        return self

    def __ilshift__(self: T, other: Affine2D | Affine3D) -> T:
        if isinstance(other, Affine2D):
            for name, value in self.__two_d_dict.items():
                super().__setattr__(name, value << other)
        elif isinstance(other, Affine3D):
            for name, value in self.__three_d_dict.items():
                super().__setattr__(name, value << other)
        else:
            raise TypeError(f"Invalid type: {type(other)}")
        return self
