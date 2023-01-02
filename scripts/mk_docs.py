"""Script which automatically writes the documentation for the project."""

import argparse
import io
import json
from types import ModuleType
from typing import Any

import yaml

from fast_trimesh import fast_trimesh


def get_docs_for_level(mod: ModuleType, level: int) -> dict[str, Any]:
    """Recursively gets documentation for a module and its submodules.

    Args:
        mod: The module to get documentation for.
        level: The level of the module in the package hierarchy.

    Returns:
        A dictionary containing the documentation for the module and its
        submodules.
    """

    docs: dict[str, Any] = {
        "name": mod.__name__,
        "doc": mod.__doc__,
        "submodules": {},
    }

    for key in dir(mod):
        if key.startswith("_"):
            continue

        value = getattr(mod, key)

        # Checks if the value is a submodule of the module.
        if isinstance(value, ModuleType):
            docs["submodules"][key] = get_docs_for_level(value, level + 1)

        # Checks if the value is a class.
        elif isinstance(value, type):
            docs[key] = {
                "name": value.__name__,
                "methods": {},
            }
            if value.__doc__:
                docs[key]["doc"] = value.__doc__.strip()

            for method_name in dir(value):
                if method_name.startswith("_"):
                    continue

                method = getattr(value, method_name)

                if callable(method):
                    docs[key]["methods"][method_name] = {
                        "name": method.__name__,
                    }
                    if method.__doc__:
                        docs[key]["methods"][method_name]["doc"] = method.__doc__.strip()

        # Checks if the value is a function.
        elif callable(value):
            docs[key] = {
                "name": value.__name__,
            }
            if value.__doc__:
                docs[key]["doc"] = value.__doc__.strip()

        # Checks if the value is a constant.
        else:
            docs[key] = {
                "name": key,
                "value": value,
            }

    return docs


def write_markdown_file(file_ptr: io.TextIOBase, docs: dict[str, Any], level: int) -> None:
    """Recursively writes documentation to a Markdown file.

    Args:
        file_ptr: The file pointer to write to.
        docs: The documentation to write.
        level: The level of the module in the package hierarchy.
    """

    file_ptr.write(f"{'#' * (level + 1)} {docs['name']}\n\n")
    if "doc" in docs:
        file_ptr.write(f"{docs['doc']}\n\n")

    for key, value in docs["submodules"].items():
        write_markdown_file(file_ptr, value, level + 1)

    for key, value in docs.items():
        if key in ("name", "doc", "submodules"):
            continue

        file_ptr.write(f"**{value['name']}**\n\n")
        if "doc" in value:
            file_ptr.write(f"```python\n{value['doc']}\n```\n\n")

        if "methods" in value:
            for _, method in value["methods"].items():
                file_ptr.write(f"{'#' * (level + 3)} {method['name']}\n\n")
                file_ptr.write(f"```python\n{method['doc']}\n```\n\n")


def write_html_file(file_ptr: io.TextIOBase, docs: dict[str, Any], level: int) -> None:
    """Recursively writes documentation to an HTML file.

    Args:
        file_ptr: The file pointer to write to.
        docs: The documentation to write.
        level: The level of the module in the package hierarchy.
    """

    file_ptr.write(f"<h{level + 1}> {docs['name']}</h{level + 1}>\n")
    if "doc" in docs:
        file_ptr.write(f"<p>{docs['doc']}</p>\n")

    for key, value in docs["submodules"].items():
        write_html_file(file_ptr, value, level + 1)

    for key, value in docs.items():
        if key in ("name", "doc", "submodules"):
            continue

        file_ptr.write(f"<h{level + 2}> {value['name']}</h{level + 2}>\n")
        if "doc" in value:
            doc = value["doc"]
            doc = doc.replace("\n", "<br>")
            file_ptr.write(f"<pre><code>{doc}</code></pre>\n")

        if "methods" in value:
            for _, method in value["methods"].items():
                file_ptr.write(f"<h{level + 4}> {method['name']}</h{level + 4}>\n")
                file_ptr.write(f"<pre><code>{method['doc']}</code></pre>\n")


def main() -> None:
    """Script entry point.

    Raises:
        ValueError: If the output file type is invalid.
    """

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("output", help="The output file to write to.")
    args = parser.parse_args()

    docs = get_docs_for_level(fast_trimesh, 0)

    if args.output.endswith(".json"):
        with open(args.output, "w", encoding="utf-8") as file_ptr:
            json.dump(docs, file_ptr, indent=4)

    elif args.output.endswith(".yaml"):
        with open(args.output, "w", encoding="utf-8") as file_ptr:
            yaml.dump(docs, file_ptr)

    elif args.output.endswith(".md"):
        with open(args.output, "w", encoding="utf-8") as file_ptr:
            write_markdown_file(file_ptr, docs, 0)

    elif args.output.endswith(".html"):
        with open(args.output, "w", encoding="utf-8") as file_ptr:
            file_ptr.write("<!DOCTYPE html>\n")
            file_ptr.write("<html>\n")
            file_ptr.write("<head>\n")
            file_ptr.write('<meta charset="utf-8">\n')

            # Bootstrap CSS.
            bootstrap_css = "https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css"
            bootstrap_sha = "sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z"
            parts = {"href": bootstrap_css, "integrity": bootstrap_sha, "crossorigin": "anonymous"}
            file_ptr.write(f'<link rel="stylesheet" {" ".join(f"{key}={value}" for key, value in parts.items())}>\n')

            # Miscellaneous styles.
            file_ptr.write('<style type="text/css">\n')
            file_ptr.write("code { white-space: normal; }\n")
            file_ptr.write("</style>\n")

            file_ptr.write("</head>\n")
            file_ptr.write("<body>\n")
            file_ptr.write('<div class="container">\n')

            # Page header.
            file_ptr.write('<div class="page-header">\n')
            file_ptr.write('<h1 class="display-4">Fast Trimesh</h1>\n')
            file_ptr.write("</div>\n")

            # Alert box.
            file_ptr.write('<div class="alert alert-info" role="alert">\n')
            file_ptr.write("This documentation was generated using the <code>mk_docs.py</code> script.\n")
            file_ptr.write("</div>\n")

            # Writes welcome statement.
            file_ptr.write("<h2>Welcome!</h2>\n")
            file_ptr.write("<p>Fast Trimesh is a Python package for working with triangular meshes.</p>\n")

            # Writes installation instructions.
            file_ptr.write("<h2>Installation</h2>\n")
            # file_ptr.write("<p>Install using <code>pip</code>:</p>\n")
            # file_ptr.write("<pre><code>pip install fast-trimesh</code></pre>\n")

            file_ptr.write("<h3>Install from source</h3>\n")
            file_ptr.write("<ol>\n")
            file_ptr.write("<li>Clone the repository:</li>\n")
            file_ptr.write("<pre><code>git clone https://github.com/codekansas/fast-trimesh.git</code></pre>\n")
            file_ptr.write("<li>Install the package:</li>\n")
            file_ptr.write("<pre><code>cd fast-trimesh</code></pre>\n")
            file_ptr.write("<pre><code>make install-conda</code></pre>\n")
            file_ptr.write("<pre><code>make install</code></pre>\n")
            file_ptr.write("</ol>\n")

            file_ptr.write("<h3>Install from Github using Pip</h3>\n")
            file_ptr.write("<pre><code>pip install git+https://github.com/codekansas/fast-trimesh.git</code></pre>\n")

            # Writes the documentation.
            write_html_file(file_ptr, docs, 0)

            file_ptr.write("</div>\n")
            file_ptr.write("</body>\n")
            file_ptr.write("</html>\n")

    else:
        raise ValueError(f"Invalid output file type: {args.output}")


if __name__ == "__main__":
    main()
