"""Adds a section to the README with the contents of the STL."""

import argparse
from pathlib import Path


def main() -> None:
    """Main entry point for the script."""

    parser = argparse.ArgumentParser()
    parser.add_argument("path", help="The path to the STL file")
    args = parser.parse_args()

    print(f"![{Path(args.path).stem}]({args.path})")


if __name__ == "__main__":
    main()
