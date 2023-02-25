"""Tests types which are shared between two and three dimensions."""

import itertools
import random

from tmesh import Face, Point2D, Point3D, Tetrahedron3D, Triangle2D, Volume


def test_face_hashing() -> None:
    inds = list(range(100))
    get_face = lambda: Face(*random.sample(inds, k=3))
    faces = {get_face() for _ in range(100)}
    points = [Point2D(*(random.random() for _ in range(2))) for _ in range(100)]
    is_cw = lambda f: Triangle2D(*(points[i] for i in (f.a, f.b, f.c))).is_clockwise()
    for f in faces:
        for a, b, c in itertools.permutations([f.a, f.b, f.c], r=3):
            f2 = Face(a, b, c)
            if is_cw(f2) == is_cw(f):
                assert f2 in faces
            else:
                assert f2 not in faces


def test_volume_hashing() -> None:
    inds = list(range(100))
    get_volume = lambda: Volume(*random.sample(inds, k=4))
    volumes = {get_volume() for _ in range(100)}
    points = [Point3D(*(random.random() for _ in range(3))) for _ in range(100)]
    get_vol = lambda v: Tetrahedron3D(*(points[i] for i in (v.a, v.b, v.c, v.d))).signed_volume()
    for v in volumes:
        for a, b, c, d in itertools.permutations([v.a, v.b, v.c, v.d], r=4):
            v2 = Volume(a, b, c, d)
            if (get_vol(v2) > 0) == (get_vol(v) > 0):
                assert v2 in volumes
            else:
                assert v2 not in volumes
