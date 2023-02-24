"""Tests types which are shared between two and three dimensions."""

import itertools
import random

from tmesh import Face, Volume


def test_face_hashing() -> None:
    inds = list(range(100))
    get_face = lambda v: Face(*random.sample(inds, k=3))
    faces = {get_face(100) for _ in range(100)}
    for f in faces:
        valid_permutations = [
            Face(f.a, f.b, f.c),
            Face(f.c, f.a, f.b),
            Face(f.b, f.c, f.a),
        ]

        for a, b, c in itertools.permutations([f.a, f.b, f.c], r=3):
            f2 = Face(a, b, c)
            if f2 in valid_permutations:
                assert f2 in faces
            else:
                assert f2 not in faces


def test_volume_hashing() -> None:
    inds = list(range(100))
    get_volume = lambda v: Volume(*random.sample(inds, k=4))
    volumes = {get_volume(100) for _ in range(100)}

    for v in volumes:
        valid_permutations = [
            Volume(v.a, v.b, v.c, v.d),
            Volume(v.d, v.a, v.b, v.c),
            Volume(v.c, v.d, v.a, v.b),
            Volume(v.b, v.c, v.d, v.a),
        ]

        for a, b, c, d in itertools.permutations([v.a, v.b, v.c, v.d], r=4):
            v2 = Volume(a, b, c, d)
            if v2 in valid_permutations:
                assert v2 in volumes
            else:
                assert v2 not in volumes
