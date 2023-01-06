"""Adds a section to the README with the contents of the STL."""

import argparse
from pathlib import Path


def main() -> None:
    """Main entry point for the script."""

    parser = argparse.ArgumentParser()
    parser.add_argument("path", help="The path to the STL file")
    args = parser.parse_args()

    with open(args.path, "r", encoding="utf-8") as f:
        lines = f.readlines()

    if len(lines) < 10_000:
        print("```stl")
        print("\n".join(line.strip() for line in lines))
        print("```")

    else:
        print(f"STL is too large to display in the README; see it [here]({args.path}) instead.")


if __name__ == "__main__":
    main()
