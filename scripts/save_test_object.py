"""Save a test object to a file."""

import argparse
import math

from tmesh import Affine3D, cuboid, save_obj, save_stl


def main() -> None:
    """Main entry point for the CLI.

    Raises:
        ValueError: If the output file extension is not supported.
    """

    parser = argparse.ArgumentParser(description="Save a test object to a file.")
    parser.add_argument("output", type=str, help="Output file path. Extension should be one of [obj, stl].")
    args = parser.parse_args()

    rot = Affine3D(rot=(math.pi / 4, 0.0, 0.0))
    trans = Affine3D(trans=(0.0, 0.5, 0.5))

    mesh_a = cuboid(1.0, 1.0, 1.0)
    mesh_b = cuboid(1.0, 1.0, 1.0) << rot @ trans
    mesh_union = mesh_a | mesh_b

    if args.output.endswith(".obj"):
        save_obj(args.output, mesh_union)
    elif args.output.endswith(".stl"):
        save_stl(args.output, mesh_union)
    else:
        raise ValueError(f"Unknown file extension: {args.output}")
    print(f"Saved test file to {args.output}.")


if __name__ == "__main__":
    main()
