"""Base code for collecting all the examples into a single file."""

import importlib
import os
from pathlib import Path

from tmesh import Tetrahedron3D, Trimesh2D, Trimesh3D

ItemType = Trimesh2D | Trimesh3D | Tetrahedron3D


class __Registry:
    def __init__(self) -> None:
        self.registry: dict[str, ItemType] = {}

    def add_item(self, name: str, item: ItemType) -> None:
        if name in self.registry:
            raise ValueError(f"Item {name} already exists.")
        self.registry[name] = item


# Global registry singleton.
Registry = __Registry()


def import_all() -> None:
    """Manually imports all the Python files in this directory.

    This function also checks that at least one item was added to the
    registry for each example.
    """

    path = Path(__file__).parent
    files = [f for f in os.listdir(path) if f.endswith(".py")]

    num_registry_items = 0
    for file in files:
        importlib.import_module(f"examples.{file[:-3]}")

        # Checks that some items were added to the global registry.
        if len(Registry.registry) == num_registry_items:
            raise ValueError(f"Module {file} did not add any items to the global registry.")
        num_registry_items = len(Registry.registry)


def write_html_file(output_path: str | Path) -> None:
    """Writes a single static HTML file for rendering each example.

    Args:
        output_path: Path to the output HTML file.
    """

    # Writes a dummy HTML file for now.
    with open(output_path, "w", encoding="utf-8") as f:
        f.write("<html>")
        f.write("<head>")
        f.write("<title>Examples</title>")
        f.write("</head>")
        f.write("<body>")
        f.write("<h1>Examples</h1>")
        f.write("</body>")
        f.write("</html>")
