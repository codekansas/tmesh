"""Base code for collecting all the examples into a single file."""

import importlib
import logging
import os
from pathlib import Path

from tmesh import Tetramesh3D, Trimesh2D, Trimesh3D, save_stl, save_svg

logger = logging.getLogger(__name__)

ItemType = Trimesh2D | Trimesh3D | Tetramesh3D


def write_item(name: str, item: ItemType, root: Path) -> Path:
    if isinstance(item, Trimesh2D):
        path = root / f"{name}.svg"
        save_svg(str(path), item)
        return path

    if isinstance(item, (Trimesh3D, Tetramesh3D)):
        path = root / f"{name}.stl"
        save_stl(str(path), item)
        return path

    raise NotImplementedError(type(item))


class __Registry:
    def __init__(self) -> None:
        self.registry: dict[str, dict[str | None, ItemType]] = {}
        self.key: str | None = None

    def set_key(self, key: str) -> None:
        self.key = key

    def add_item(self, name: str, item: ItemType) -> None:
        if self.key not in self.registry:
            self.registry[self.key] = {}
        if name in self.registry[self.key]:
            raise ValueError(f"Item {name} already exists in registry for {self.key}.")
        self.registry[self.key][name] = item


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
        try:
            fkey = file[:-3]
            if fkey == "base":
                continue
            Registry.set_key(fkey)
            importlib.import_module(f"examples.{fkey}")

            # Checks that some items were added to the global registry.
            if len(Registry.registry) == num_registry_items:
                raise ValueError(f"Module {file} did not add any items to the global registry.")
            num_registry_items = len(Registry.registry)

        except Exception:
            logger.exception("Caught exception while importing %s", file)


def write_examples(output_path: str | Path) -> None:
    """Writes a single static HTML file for rendering each example.

    Args:
        output_path: Path to the root output directory for HTML files.
    """

    # Initializes logging.
    logger.addHandler(logging.StreamHandler())

    # Imports all examples.
    import_all()

    output_path = Path(output_path)

    # Makes the output directory if it doesn't exist.
    output_path.mkdir(parents=True, exist_ok=True)

    # Writes each item in the registry.
    for key, items in Registry.registry.items():
        key_path = output_path / key / "index.html"
        key_path.parent.mkdir(exist_ok=True)
        with open(key_path, "w", encoding="utf-8") as f:
            f.write("<html>")
            f.write("<head>")
            f.write(f"<title>{key}</title>")
            f.write("</head>")
            f.write("<body>")
            f.write(f"<h1>{key}</h1>")
            f.write("<ul>")
            for name, item in items.items():
                item_path = write_item(name, item, key_path.parent).relative_to(output_path)
                f.write("<li>")
                f.write(f"<a href='/{item_path}'>{item_path.name}</a>")
                f.write("</li>")
            f.write("</ul>")
            f.write("</body>")
            f.write("</html>")

    # Writes the main index file.
    with open(output_path / "index.html", "w", encoding="utf-8") as f:
        f.write("<html>")
        f.write("<head>")
        f.write("<title>Examples</title>")
        f.write("</head>")
        f.write("<body>")
        f.write("<h1>Examples</h1>")
        f.write("<ul>")
        for key in sorted(Registry.registry.keys()):
            f.write("<li>")
            f.write(f"<a href='/{key}'>{key}</a>")
            f.write("</li>")
        f.write("</ul>")
        f.write("</body>")
        f.write("</html>")
