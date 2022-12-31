Installation
============

.. Fast Trimesh is available on PyPI:

.. .. code-block:: console

..     pip install fast-trimesh

To install from source, first create a Conda environment:

.. code-block:: console

    conda create -n fast-trimesh python=3.10
    conda activate fast-trimesh

Next, clone and install the package:

.. code-block:: console

    git clone https://github.com/codekansas/fast-trimesh.git
    cd fast-trimesh
    make install-conda  # Installs Conda requirements
    make install        # Builds and installs package

Alternatively, if you have `cmake` and `pybind` available, you can install the package directly from Github using:

.. code-block:: console

    pip install git+https://github.com/codekansas/fast-trimesh.git
