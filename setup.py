"""Setup script for fast-trimesh.

This setup script uses CMake to build the extension. It is based on the
example from the PyBind11 documentation:

https://github.com/pybind/cmake_example/blob/master/setup.py

Usage:
    pip install .  # Install the package
    python setup.py build_ext  # Build the extension
    python setup.py build_ext --inplace  # Build the extension inplace
"""

import os
import re
import subprocess
import sys
from pathlib import Path

from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext

PLAT_TO_CMAKE = {
    "win32": "Win32",
    "win-amd64": "x64",
    "win-arm32": "ARM",
    "win-arm64": "ARM64",
}


class CMakeExtension(Extension):
    """CMake extension.

    This is a subclass of setuptools.Extension that allows specifying the
    location of the CMakeLists.txt file.

    Usage:
        setup(
            name="my_package",
            ext_modules=[CMakeExtension("my_package")],
            cmdclass={"build_ext": CMakeBuild},
        )
    """

    def __init__(self, name: str, sourcedir: str = "") -> None:
        super().__init__(name, sources=[])

        self.sourcedir = os.fspath(Path(sourcedir).resolve() / name)


class CMakeBuild(build_ext):
    """CMake build extension.

    This is a subclass of setuptools.command.build_ext.build_ext that runs
    cmake to build the extension.

    Usage:
        setup(
            name="my_package",
            ext_modules=[CMakeExtension("my_package")],
            cmdclass={"build_ext": CMakeBuild},
        )
    """

    def initialize_options(self) -> None:
        super().initialize_options()

        self.package = "fast_trimesh"

    def build_extension(self, ext: CMakeExtension) -> None:
        ext_fullpath = Path.cwd() / self.get_ext_fullpath(ext.name)  # type: ignore[no-untyped-call]
        extdir = ext_fullpath.parent.resolve()
        debug = int(os.environ.get("DEBUG", 0)) if self.debug is None else self.debug
        cfg = "Debug" if debug else "Release"
        cmake_generator = os.environ.get("CMAKE_GENERATOR", "")
        cmake_args = [
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extdir}{os.sep}",
            f"-DPYTHON_EXECUTABLE={sys.executable}",
            f"-DCMAKE_BUILD_TYPE={cfg}",  # not used on MSVC, but no harm
        ]
        build_args = []
        if "CMAKE_ARGS" in os.environ:
            cmake_args += [item for item in os.environ["CMAKE_ARGS"].split(" ") if item]

        if self.compiler.compiler_type != "msvc":
            if not cmake_generator or cmake_generator == "Ninja":
                try:
                    # pylint: disable-next=import-outside-toplevel
                    import ninja  # noqa: F401

                    ninja_executable_path = Path(ninja.BIN_DIR) / "ninja"
                    cmake_args += [
                        "-GNinja",
                        f"-DCMAKE_MAKE_PROGRAM:FILEPATH={ninja_executable_path}",
                    ]
                except ImportError:
                    pass

        else:
            single_config = any(x in cmake_generator for x in ("NMake", "Ninja"))
            contains_arch = any(x in cmake_generator for x in ("ARM", "Win64"))
            if not single_config and not contains_arch:
                cmake_args += ["-A", PLAT_TO_CMAKE[self.plat_name]]
            if not single_config:
                cmake_args += [f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{cfg.upper()}={extdir}"]
                build_args += ["--config", cfg]

        if sys.platform.startswith("darwin"):
            archs = re.findall(r"-arch (\S+)", os.environ.get("ARCHFLAGS", ""))
            if archs:
                cmake_args += [f"-DCMAKE_OSX_ARCHITECTURES={';'.join(archs)}"]

        if "CMAKE_BUILD_PARALLEL_LEVEL" not in os.environ:
            if hasattr(self, "parallel") and self.parallel:
                build_args += [f"-j{self.parallel}"]

        build_temp = Path(self.build_temp) / ext.name
        if not build_temp.exists():
            build_temp.mkdir(parents=True)

        def show_and_run(cmd: list[str]) -> None:
            print(" ".join(cmd))
            subprocess.run(cmd, cwd=build_temp, check=True)

        show_and_run(["cmake", ext.sourcedir] + cmake_args)
        show_and_run(["cmake", "--build", "."] + build_args)

    def run(self) -> None:
        super().run()

        def gen_stubs(ext: Extension) -> None:
            cmd = ["stubgen", "-p", f"{ext.name}.{ext.name}", "-o", "."]
            print(" ".join(cmd))
            subprocess.run(cmd, check=True)

        for ext in self.extensions:
            gen_stubs(ext)


# The information here can also be placed in setup.cfg - better separation of
# logic and declaration, and simpler if you include description/version in a file.
setup(
    name="fast-trimesh",
    version="0.0.1",
    author="Ben Bolte",
    author_email="ben@bolte.cc",
    description="A fast trimesh implementation",
    long_description="",
    ext_modules=[CMakeExtension("fast_trimesh")],
    cmdclass={"build_ext": CMakeBuild},
    zip_safe=False,
    extras_require={"test": ["pytest>=6.0"]},
    python_requires=">=3.7",
)
