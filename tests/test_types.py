import random

from tmesh import Face, Volume


def test_face_hashing() -> None:
    get_face = lambda v: Face(*(random.randint(0, v) for _ in range(3)))
    faces = {get_face(100) for _ in range(100)}
    for face in faces:
        assert Face(face.b, face.c, face.a) in faces
        assert Face(face.c, face.a, face.b) in faces


def test_volume_hashing() -> None:
    get_volume = lambda v: Volume(*(random.randint(0, v) for _ in range(4)))
    volumes = {get_volume(100) for _ in range(100)}
    for volume in volumes:
        assert Volume(volume.b, volume.c, volume.d, volume.a) in volumes
        assert Volume(volume.c, volume.d, volume.a, volume.b) in volumes
        assert Volume(volume.d, volume.a, volume.b, volume.c) in volumes
