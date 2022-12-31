import argparse

from fast_trimesh.fast_trimesh.cpu.io import save_stl
from fast_trimesh.fast_trimesh.cpu.shapes import cuboid


def main() -> None:
    """Save a test STL file."""

    parser = argparse.ArgumentParser(description="Save a test STL file.")
    parser.add_argument("output", type=str, help="Output file path.")
    args = parser.parse_args()

    save_stl(args.output, cuboid(1.0, 1.0, 1.0))
    print(f"Saved test STL file to {args.output}.")


if __name__ == "__main__":
    main()
