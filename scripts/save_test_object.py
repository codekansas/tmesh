"""Save a test object to a file."""

import argparse
import math

from fast_trimesh.fast_trimesh.cpu.io import save_obj, save_stl
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.fast_trimesh.cpu.trimesh import AffineTransformation


def main() -> None:
    """Main entry point for the CLI."""

    parser = argparse.ArgumentParser(description="Save a test object to a file.")
    parser.add_argument("output", type=str, help="Output file path. Extension should be one of [obj, stl].")
    args = parser.parse_args()

    tf_1 = AffineTransformation(rotation=(math.pi / 4, 0.0, 0.0))
    tf_2 = AffineTransformation(translation=(0.0, 0.5, 0.5))

    a = cuboid(1.0, 1.0, 1.0)
    b = cuboid(1.0, 1.0, 1.0) << tf_1 << tf_2

    if args.output.endswith(".obj"):
        save_obj(args.output, a + b)
    elif args.output.endswith(".stl"):
        save_stl(args.output, a + b)
    else:
        raise ValueError(f"Unknown file extension: {args.output}")
    print(f"Saved test file to {args.output}.")


if __name__ == "__main__":
    main()
