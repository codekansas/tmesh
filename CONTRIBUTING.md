# Contributing

## How to contribute

1. Fork the repository on GitHub
2. Create a named feature branch (like `add_component_x`)
3. Write your change
4. Write tests for your change (if applicable)
5. Run the tests, ensuring they all pass
6. Submit a Pull Request using GitHub

## Reporting issues

We use GitHub Issues for tracking issues with this repository. Please ensure your description is clear and has sufficient instructions to be able to reproduce the issue.

## License

By contributing your code, you agree to license your contribution under the terms of the MIT license.

## Editor Settings

Before submitting a pull request, run formatting:

```bash
make format
```

If using VSCode, it's helpful to have the following `settings.json` file:

```jsonc
"cmake.configureSettings": {
  "CMAKE_PREFIX_PATH": [
    $(pybind_cmake_dir),  // Update this
  ],
  "PYTHON_EXECUTABLE": "${env:CONDA_PREFIX}/bin/python",  // Update this
},
"cmake.environment": {
  "CONDA_PREFIX": "${env:CONDA_PREFIX}",  // Update this
}
```

where:

```bash
pybind_cmake_dir=$(python -c 'import pybind11; print(pybind11.get_cmake_dir())')
```

This will find the appropriate PyBind11 libraries for your editor.
