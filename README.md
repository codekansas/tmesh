# Fast Trimesh

Fast boolean operators for triangular meshes.

## Description

This repo has my implementations of boolean operations on 3D meshes (union, intersection, difference).

## Checklist

- [x] Simple geometric utility functions
- [ ] Serialization
  - [x] STL
  - [x] OBJ
  - [ ] PLY
- [ ] CPU
  - [ ] Mesh data structure
    - [x] Represent vertices and faces
    - [x] Check for manifoldness (no dangling edges, no non-manifold edges, no non-manifold faces)
    - [ ] Represent curved edges and faces (e.g. NURBS, big refactor)
  - [x] Affine transformations
  - [ ] Shapes
    - [x] Cuboid
    - [ ] Sphere
    - [ ] Cylinder
  - [ ] Extrude
    - [ ] Linear extrude
    - [ ] Radial extrude
  - [ ] Add mesh operations
    - [ ] 2D
      - [ ] Implement boundary volume hierarchy data structure for polygons
      - [ ] Intersection
      - [ ] Complement
    - [ ] 3D
      - [ ] Implement boundary volume hierarchy data structure
      - [ ] Intersection
      - [ ] Complement
- [ ] CUDA
  - [ ] Mesh data structure
  - [ ] Add mesh operations
    - [ ] Intersection
    - [ ] Complement
- [ ] Benchmarks
  - [ ] CPU
  - [ ] CUDA
- [ ] Documentation
  - [ ] Add to PyPi
  - [ ] Automatically build Sphinx docs
