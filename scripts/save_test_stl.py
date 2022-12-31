import argparse
import math

from fast_trimesh.fast_trimesh.cpu.io import save_stl
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid
from fast_trimesh.fast_trimesh.cpu.trimesh import AffineTransformation


def main() -> None:
    """Save a test STL file."""

    parser = argparse.ArgumentParser(description="Save a test STL file.")
    parser.add_argument("output", type=str, help="Output file path.")
    args = parser.parse_args()

    tf = AffineTransformation(
        rotation=(math.pi / 4, 0.0, 0.0),
        translation=(0.0, 0.5, 0.5),
    )

    a = cuboid(1.0, 1.0, 1.0)
    b = cuboid(1.0, 1.0, 1.0) << tf

    save_stl(args.output, a + b)
    print(f"Saved test STL file to {args.output}.")


if __name__ == "__main__":
    main()
