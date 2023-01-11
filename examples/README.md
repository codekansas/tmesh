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

```stl
solid fast_trimesh STL file
facet normal nan nan nan
outer loop
vertex 0.309017 -0.951056 0
vertex 0.309017 -0.951056 0
vertex 4.80902 2.41221 0
endloop
endfacet
facet normal 0.598663 -0.801001 0
outer loop
vertex 0.309017 -0.951056 0
vertex 4.80902 2.41221 0
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal -0.309017 -0.951057 0
outer loop
vertex 0.309017 -0.951056 0
vertex 0.309017 -0.951056 1
vertex -0.809017 -0.587785 1
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 4.80902 2.41221 0
vertex 0.309017 -0.951056 0
vertex 5 3 0
endloop
endfacet
facet normal 0.951057 -0.309017 0
outer loop
vertex 4.80902 2.41221 0
vertex 5 3 0
vertex 4.80902 2.41221 1
endloop
endfacet
facet normal 0.598663 -0.801001 0
outer loop
vertex 4.80902 2.41221 0
vertex 4.80902 2.41221 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 5 3 0
vertex 0.309017 -0.951056 0
vertex 4.80902 3.58779 0
endloop
endfacet
facet normal 0.951057 0.309017 -0
outer loop
vertex 5 3 0
vertex 4.80902 3.58779 0
vertex 5 3 1
endloop
endfacet
facet normal 0.951057 -0.309017 0
outer loop
vertex 5 3 0
vertex 5 3 1
vertex 4.80902 2.41221 1
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 4.80902 3.58779 0
vertex 0.309017 -0.951056 0
vertex 4.30902 3.95106 0
endloop
endfacet
facet normal 0.587785 0.809017 -0
outer loop
vertex 4.80902 3.58779 0
vertex 4.30902 3.95106 0
vertex 4.80902 3.58779 1
endloop
endfacet
facet normal 0.951057 0.309017 -0
outer loop
vertex 4.80902 3.58779 0
vertex 4.80902 3.58779 1
vertex 5 3 1
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 4.30902 3.95106 0
vertex 0.309017 -0.951056 0
vertex 0.5 4.86603 0
endloop
endfacet
facet normal 0.233567 0.972341 -0
outer loop
vertex 4.30902 3.95106 0
vertex 0.5 4.86603 0
vertex 4.30902 3.95106 1
endloop
endfacet
facet normal 0.587785 0.809017 -0
outer loop
vertex 4.30902 3.95106 0
vertex 4.30902 3.95106 1
vertex 4.80902 3.58779 1
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 0.5 4.86603 0
vertex 0.309017 -0.951056 0
vertex -0.5 4.86603 0
endloop
endfacet
facet normal 0 1 -0
outer loop
vertex 0.5 4.86603 0
vertex -0.5 4.86603 0
vertex 0.5 4.86603 1
endloop
endfacet
facet normal 0.233567 0.972341 -0
outer loop
vertex 0.5 4.86603 0
vertex 0.5 4.86603 1
vertex 4.30902 3.95106 1
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.5 4.86603 0
vertex 0.309017 -0.951056 0
vertex -1 4 0
endloop
endfacet
facet normal -0.866025 0.5 0
outer loop
vertex -0.5 4.86603 0
vertex -1 4 0
vertex -0.5 4.86603 1
endloop
endfacet
facet normal 0 1 0
outer loop
vertex -0.5 4.86603 0
vertex -0.5 4.86603 1
vertex 0.5 4.86603 1
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -1 4 0
vertex 0.309017 -0.951056 0
vertex -0.809017 -0.587785 0
endloop
endfacet
facet normal -0.999135 -0.0415926 0
outer loop
vertex -1 4 0
vertex -0.809017 -0.587785 0
vertex -1 4 1
endloop
endfacet
facet normal -0.866025 0.5 0
outer loop
vertex -1 4 0
vertex -1 4 1
vertex -0.5 4.86603 1
endloop
endfacet
facet normal -0.309017 -0.951057 0
outer loop
vertex -0.809017 -0.587785 0
vertex 0.309017 -0.951056 0
vertex -0.809017 -0.587785 1
endloop
endfacet
facet normal -0.999135 -0.0415926 0
outer loop
vertex -0.809017 -0.587785 0
vertex -0.809017 -0.587785 1
vertex -1 4 1
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 0.309017 -0.951056 1
vertex 4.80902 2.41221 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal 0 -0 1
outer loop
vertex 4.80902 2.41221 1
vertex 5 3 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 5 3 1
vertex 4.80902 3.58779 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 4.80902 3.58779 1
vertex 4.30902 3.95106 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 4.30902 3.95106 1
vertex 0.5 4.86603 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.5 4.86603 1
vertex -0.5 4.86603 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 4.86603 1
vertex -1 4 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -1 4 1
vertex -0.809017 -0.587785 1
vertex 0.309017 -0.951056 1
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 1 0 0
vertex 1 0 0
vertex 0.309017 0.951057 0
endloop
endfacet
facet normal 0.809017 0.587785 -0
outer loop
vertex 1 0 0
vertex 0.309017 0.951057 0
vertex 1 0 2
endloop
endfacet
facet normal 0.809017 -0.587785 0
outer loop
vertex 1 0 0
vertex 1 0 2
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex 0.309017 0.951057 0
vertex 1 0 0
vertex -0.809017 0.587785 0
endloop
endfacet
facet normal -0.309017 0.951056 0
outer loop
vertex 0.309017 0.951057 0
vertex -0.809017 0.587785 0
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0.809017 0.587785 -0
outer loop
vertex 0.309017 0.951057 0
vertex 0.309017 0.951057 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.809017 0.587785 0
vertex 1 0 0
vertex -0.809017 -0.587785 0
endloop
endfacet
facet normal -1 -1.01405e-07 0
outer loop
vertex -0.809017 0.587785 0
vertex -0.809017 -0.587785 0
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal -0.309017 0.951056 0
outer loop
vertex -0.809017 0.587785 0
vertex -0.809017 0.587785 2
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.809017 -0.587785 0
vertex 1 0 0
vertex 0.309017 -0.951056 0
endloop
endfacet
facet normal -0.309017 -0.951057 0
outer loop
vertex -0.809017 -0.587785 0
vertex 0.309017 -0.951056 0
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal -1 -1.01405e-07 0
outer loop
vertex -0.809017 -0.587785 0
vertex -0.809017 -0.587785 2
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal 0.809017 -0.587785 0
outer loop
vertex 0.309017 -0.951056 0
vertex 1 0 0
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal -0.309017 -0.951057 0
outer loop
vertex 0.309017 -0.951056 0
vertex 0.309017 -0.951056 2
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 1 0 2
vertex 0.309017 0.951057 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.309017 0.951057 2
vertex -0.809017 0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.809017 0.587785 2
vertex -0.809017 -0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex -0.809017 -0.587785 2
vertex 0.309017 -0.951056 2
vertex 1 0 2
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 1 4 0
vertex 1 4 0
vertex 0.5 4.86603 0
endloop
endfacet
facet normal 0.866025 0.5 -0
outer loop
vertex 1 4 0
vertex 0.5 4.86603 0
vertex 1 4 2
endloop
endfacet
facet normal 0.866025 -0.5 0
outer loop
vertex 1 4 0
vertex 1 4 2
vertex 0.5 3.13397 2
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.5 4.86603 0
vertex 1 4 0
vertex -0.5 4.86603 0
endloop
endfacet
facet normal 0 1 -0
outer loop
vertex 0.5 4.86603 0
vertex -0.5 4.86603 0
vertex 0.5 4.86603 2
endloop
endfacet
facet normal 0.866025 0.5 -0
outer loop
vertex 0.5 4.86603 0
vertex 0.5 4.86603 2
vertex 1 4 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.5 4.86603 0
vertex 1 4 0
vertex -1 4 0
endloop
endfacet
facet normal -0.866025 0.5 0
outer loop
vertex -0.5 4.86603 0
vertex -1 4 0
vertex -0.5 4.86603 2
endloop
endfacet
facet normal 0 1 0
outer loop
vertex -0.5 4.86603 0
vertex -0.5 4.86603 2
vertex 0.5 4.86603 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -1 4 0
vertex 1 4 0
vertex -0.5 3.13397 0
endloop
endfacet
facet normal -0.866025 -0.5 0
outer loop
vertex -1 4 0
vertex -0.5 3.13397 0
vertex -1 4 2
endloop
endfacet
facet normal -0.866025 0.5 0
outer loop
vertex -1 4 0
vertex -1 4 2
vertex -0.5 4.86603 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.5 3.13397 0
vertex 1 4 0
vertex 0.5 3.13397 0
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex -0.5 3.13397 0
vertex 0.5 3.13397 0
vertex -0.5 3.13397 2
endloop
endfacet
facet normal -0.866025 -0.5 0
outer loop
vertex -0.5 3.13397 0
vertex -0.5 3.13397 2
vertex -1 4 2
endloop
endfacet
facet normal 0.866025 -0.5 0
outer loop
vertex 0.5 3.13397 0
vertex 1 4 0
vertex 0.5 3.13397 2
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex 0.5 3.13397 0
vertex 0.5 3.13397 2
vertex -0.5 3.13397 2
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 1 4 2
vertex 0.5 4.86603 2
vertex 1 4 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.5 4.86603 2
vertex -0.5 4.86603 2
vertex 1 4 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 4.86603 2
vertex -1 4 2
vertex 1 4 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex -1 4 2
vertex -0.5 3.13397 2
vertex 1 4 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 3.13397 2
vertex 0.5 3.13397 2
vertex 1 4 2
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 5 3 0
vertex 5 3 0
vertex 4.80902 3.58779 0
endloop
endfacet
facet normal 0.951057 0.309017 -0
outer loop
vertex 5 3 0
vertex 4.80902 3.58779 0
vertex 5 3 2
endloop
endfacet
facet normal 0.951057 -0.309017 0
outer loop
vertex 5 3 0
vertex 5 3 2
vertex 4.80902 2.41221 2
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 4.80902 3.58779 0
vertex 5 3 0
vertex 4.30902 3.95106 0
endloop
endfacet
facet normal 0.587785 0.809017 -0
outer loop
vertex 4.80902 3.58779 0
vertex 4.30902 3.95106 0
vertex 4.80902 3.58779 2
endloop
endfacet
facet normal 0.951057 0.309017 -0
outer loop
vertex 4.80902 3.58779 0
vertex 4.80902 3.58779 2
vertex 5 3 2
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 4.30902 3.95106 0
vertex 5 3 0
vertex 3.69098 3.95106 0
endloop
endfacet
facet normal 0 1 -0
outer loop
vertex 4.30902 3.95106 0
vertex 3.69098 3.95106 0
vertex 4.30902 3.95106 2
endloop
endfacet
facet normal 0.587785 0.809017 -0
outer loop
vertex 4.30902 3.95106 0
vertex 4.30902 3.95106 2
vertex 4.80902 3.58779 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex 3.69098 3.95106 0
vertex 5 3 0
vertex 3.19098 3.58779 0
endloop
endfacet
facet normal -0.587785 0.809017 0
outer loop
vertex 3.69098 3.95106 0
vertex 3.19098 3.58779 0
vertex 3.69098 3.95106 2
endloop
endfacet
facet normal 0 1 0
outer loop
vertex 3.69098 3.95106 0
vertex 3.69098 3.95106 2
vertex 4.30902 3.95106 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex 3.19098 3.58779 0
vertex 5 3 0
vertex 3 3 0
endloop
endfacet
facet normal -0.951057 0.309017 0
outer loop
vertex 3.19098 3.58779 0
vertex 3 3 0
vertex 3.19098 3.58779 2
endloop
endfacet
facet normal -0.587785 0.809017 0
outer loop
vertex 3.19098 3.58779 0
vertex 3.19098 3.58779 2
vertex 3.69098 3.95106 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 3 3 0
vertex 5 3 0
vertex 3.19098 2.41221 0
endloop
endfacet
facet normal -0.951057 -0.309017 0
outer loop
vertex 3 3 0
vertex 3.19098 2.41221 0
vertex 3 3 2
endloop
endfacet
facet normal -0.951057 0.309017 0
outer loop
vertex 3 3 0
vertex 3 3 2
vertex 3.19098 3.58779 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 3.19098 2.41221 0
vertex 5 3 0
vertex 3.69098 2.04894 0
endloop
endfacet
facet normal -0.587785 -0.809017 0
outer loop
vertex 3.19098 2.41221 0
vertex 3.69098 2.04894 0
vertex 3.19098 2.41221 2
endloop
endfacet
facet normal -0.951057 -0.309017 0
outer loop
vertex 3.19098 2.41221 0
vertex 3.19098 2.41221 2
vertex 3 3 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 3.69098 2.04894 0
vertex 5 3 0
vertex 4.30902 2.04894 0
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex 3.69098 2.04894 0
vertex 4.30902 2.04894 0
vertex 3.69098 2.04894 2
endloop
endfacet
facet normal -0.587785 -0.809017 0
outer loop
vertex 3.69098 2.04894 0
vertex 3.69098 2.04894 2
vertex 3.19098 2.41221 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 4.30902 2.04894 0
vertex 5 3 0
vertex 4.80902 2.41221 0
endloop
endfacet
facet normal 0.587785 -0.809017 0
outer loop
vertex 4.30902 2.04894 0
vertex 4.80902 2.41221 0
vertex 4.30902 2.04894 2
endloop
endfacet
facet normal 0 -1 0
outer loop
vertex 4.30902 2.04894 0
vertex 4.30902 2.04894 2
vertex 3.69098 2.04894 2
endloop
endfacet
facet normal 0.951057 -0.309017 0
outer loop
vertex 4.80902 2.41221 0
vertex 5 3 0
vertex 4.80902 2.41221 2
endloop
endfacet
facet normal 0.587785 -0.809017 0
outer loop
vertex 4.80902 2.41221 0
vertex 4.80902 2.41221 2
vertex 4.30902 2.04894 2
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 5 3 2
vertex 4.80902 3.58779 2
vertex 5 3 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 4.80902 3.58779 2
vertex 4.30902 3.95106 2
vertex 5 3 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 4.30902 3.95106 2
vertex 3.69098 3.95106 2
vertex 5 3 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 3.69098 3.95106 2
vertex 3.19098 3.58779 2
vertex 5 3 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 3.19098 3.58779 2
vertex 3 3 2
vertex 5 3 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex 3 3 2
vertex 3.19098 2.41221 2
vertex 5 3 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex 3.19098 2.41221 2
vertex 3.69098 2.04894 2
vertex 5 3 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 3.69098 2.04894 2
vertex 4.30902 2.04894 2
vertex 5 3 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 4.30902 2.04894 2
vertex 4.80902 2.41221 2
vertex 5 3 2
endloop
endfacet
endsolid fast_trimesh STL file
```
