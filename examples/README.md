# Examples

## simple

```stl
solid fast_trimesh STL file
facet normal 0 -1 0
outer loop
vertex -0.5 -0.5 -0.5
vertex 0.5 -0.5 -0.5
vertex 0.5 -0.5 0.5
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.5 -0.5 -0.5
vertex 0.5 0.5 -0.5
vertex 0.5 -0.5 -0.5
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.5 -0.5 -0.5
vertex -0.5 0.5 -0.5
vertex 0.5 0.5 -0.5
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex -0.5 -0.5 -0.5
vertex 0.5 -0.5 0.5
vertex -0.5 -0.5 0.5
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 -0.5 -0.5
vertex 0.5 0.5 -0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 -0.5 -0.5
vertex 0.5 0.5 0.5
vertex 0.5 -0.5 0.5
endloop
endfacet
facet normal 0 1 0
outer loop
vertex 0.5 0.5 -0.5
vertex -0.5 0.5 -0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal 0 1 -0
outer loop
vertex 0.5 0.5 -0.5
vertex -0.5 0.5 0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 0.5 -0.5
vertex -0.5 -0.5 -0.5
vertex -0.5 -0.5 0.5
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 0.5 -0.5
vertex -0.5 -0.5 0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 -0.5 0.5
vertex 0.5 -0.5 0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 -0.5 0.5
vertex 0.5 0.5 0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal 0 -0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex 0.5 0.5 -0.707107
vertex 0.5 -0.207107 0
endloop
endfacet
facet normal 0 0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex 0.5 1.20711 0
vertex 0.5 0.5 -0.707107
endloop
endfacet
facet normal 0 0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex -0.5 1.20711 0
vertex 0.5 1.20711 0
endloop
endfacet
facet normal 0 -0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex 0.5 -0.207107 0
vertex -0.5 -0.207107 0
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 0.5 -0.707107
vertex 0.5 1.20711 0
vertex 0.5 0.5 0.707107
endloop
endfacet
facet normal 1 0 -0
outer loop
vertex 0.5 0.5 -0.707107
vertex 0.5 0.5 0.707107
vertex 0.5 -0.207107 0
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 0.5 1.20711 0
vertex -0.5 1.20711 0
vertex -0.5 0.5 0.707107
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 0.5 1.20711 0
vertex -0.5 0.5 0.707107
vertex 0.5 0.5 0.707107
endloop
endfacet
facet normal -1 -0 0
outer loop
vertex -0.5 1.20711 0
vertex -0.5 0.5 -0.707107
vertex -0.5 -0.207107 0
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 1.20711 0
vertex -0.5 -0.207107 0
vertex -0.5 0.5 0.707107
endloop
endfacet
facet normal 0 -0.707107 0.707107
outer loop
vertex -0.5 -0.207107 0
vertex 0.5 -0.207107 0
vertex 0.5 0.5 0.707107
endloop
endfacet
facet normal 0 -0.707107 0.707107
outer loop
vertex -0.5 -0.207107 0
vertex 0.5 0.5 0.707107
vertex -0.5 0.5 0.707107
endloop
endfacet
endsolid fast_trimesh STL file
```

## cylinder

STL is too large to display in the README; see it [here](cylinder.stl) instead.

## torus

STL is too large to display in the README; see it [here](torus.stl) instead.

## intersection

```stl
solid fast_trimesh STL file
facet normal 0.471405 0.816497 0.333333
outer loop
vertex 0.942809 0 -0.333333
vertex -0.471405 0.816497 -0.333333
vertex 0 0 1
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 0.942809 0 -0.333333
vertex -0.471405 -0.816497 -0.333333
vertex -0.471405 0.816497 -0.333333
endloop
endfacet
facet normal -0.942809 0 0.333333
outer loop
vertex -0.471405 0.816497 -0.333333
vertex -0.471405 -0.816497 -0.333333
vertex 0 0 1
endloop
endfacet
facet normal 0.471405 -0.816497 0.333333
outer loop
vertex -0.471405 -0.816497 -0.333333
vertex 0.942809 0 -0.333333
vertex 0 0 1
endloop
endfacet
facet normal -0.244017 -0.910684 -0.333333
outer loop
vertex 1 -1 2
vertex -1.36603 -0.366025 2
vertex 9.27259e-08 2.2386e-07 0
endloop
endfacet
facet normal 3.97364e-08 -3.97364e-08 1
outer loop
vertex 1 -1 2
vertex 0.366026 1.36603 2
vertex -1.36603 -0.366025 2
endloop
endfacet
facet normal -0.666667 0.666667 -0.333333
outer loop
vertex -1.36603 -0.366025 2
vertex 0.366026 1.36603 2
vertex 9.27259e-08 2.2386e-07 0
endloop
endfacet
facet normal 0.910684 0.244017 -0.333333
outer loop
vertex 0.366026 1.36603 2
vertex 1 -1 2
vertex 9.27259e-08 2.2386e-07 0
endloop
endfacet
endsolid fast_trimesh STL file
```

## sphere

STL is too large to display in the README; see it [here](sphere.stl) instead.

## convex_hull

STL is too large to display in the README; see it [here](convex_hull.stl) instead.
