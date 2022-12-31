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
    - [ ] Check for manifoldness (no dangling edges, no non-manifold edges, no non-manifold faces)
    - [ ] Represent curved edges and faces
  - [x] Affine transformations
  - [ ] Shapes
    - [x] Cuboid
    - [ ] Sphere
    - [ ] Cylinder
  - [ ] Extrude
    - [ ] Linear extrude
    - [ ] Radial extrude
  - [ ] Add mesh operations
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
