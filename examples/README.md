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

```stl
solid fast_trimesh STL file
facet normal nan nan nan
outer loop
vertex 1 0 0
vertex 1 0 0
vertex 0.951057 0.309017 0
endloop
endfacet
facet normal 0.987688 0.156434 -0
outer loop
vertex 1 0 0
vertex 0.951057 0.309017 0
vertex 1 0 2
endloop
endfacet
facet normal 0.987688 -0.156434 0
outer loop
vertex 1 0 0
vertex 1 0 2
vertex 0.951057 -0.309017 2
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.951057 0.309017 0
vertex 1 0 0
vertex 0.809017 0.587785 0
endloop
endfacet
facet normal 0.891006 0.453991 -0
outer loop
vertex 0.951057 0.309017 0
vertex 0.809017 0.587785 0
vertex 0.951057 0.309017 2
endloop
endfacet
facet normal 0.987688 0.156434 -0
outer loop
vertex 0.951057 0.309017 0
vertex 0.951057 0.309017 2
vertex 1 0 2
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.809017 0.587785 0
vertex 1 0 0
vertex 0.587785 0.809017 0
endloop
endfacet
facet normal 0.707107 0.707107 -0
outer loop
vertex 0.809017 0.587785 0
vertex 0.587785 0.809017 0
vertex 0.809017 0.587785 2
endloop
endfacet
facet normal 0.891006 0.453991 -0
outer loop
vertex 0.809017 0.587785 0
vertex 0.809017 0.587785 2
vertex 0.951057 0.309017 2
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.587785 0.809017 0
vertex 1 0 0
vertex 0.309017 0.951057 0
endloop
endfacet
facet normal 0.453991 0.891006 -0
outer loop
vertex 0.587785 0.809017 0
vertex 0.309017 0.951057 0
vertex 0.587785 0.809017 2
endloop
endfacet
facet normal 0.707107 0.707107 -0
outer loop
vertex 0.587785 0.809017 0
vertex 0.587785 0.809017 2
vertex 0.809017 0.587785 2
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.309017 0.951057 0
vertex 1 0 0
vertex -4.37114e-08 1 0
endloop
endfacet
facet normal 0.156434 0.987688 -0
outer loop
vertex 0.309017 0.951057 0
vertex -4.37114e-08 1 0
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0.453991 0.891006 -0
outer loop
vertex 0.309017 0.951057 0
vertex 0.309017 0.951057 2
vertex 0.587785 0.809017 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -4.37114e-08 1 0
vertex 1 0 0
vertex -0.309017 0.951056 0
endloop
endfacet
facet normal -0.156435 0.987688 0
outer loop
vertex -4.37114e-08 1 0
vertex -0.309017 0.951056 0
vertex -4.37114e-08 1 2
endloop
endfacet
facet normal 0.156434 0.987688 -0
outer loop
vertex -4.37114e-08 1 0
vertex -4.37114e-08 1 2
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.309017 0.951056 0
vertex 1 0 0
vertex -0.587785 0.809017 0
endloop
endfacet
facet normal -0.453991 0.891007 0
outer loop
vertex -0.309017 0.951056 0
vertex -0.587785 0.809017 0
vertex -0.309017 0.951056 2
endloop
endfacet
facet normal -0.156435 0.987688 0
outer loop
vertex -0.309017 0.951056 0
vertex -0.309017 0.951056 2
vertex -4.37114e-08 1 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.587785 0.809017 0
vertex 1 0 0
vertex -0.809017 0.587785 0
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex -0.587785 0.809017 0
vertex -0.809017 0.587785 0
vertex -0.587785 0.809017 2
endloop
endfacet
facet normal -0.453991 0.891007 0
outer loop
vertex -0.587785 0.809017 0
vertex -0.587785 0.809017 2
vertex -0.309017 0.951056 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.809017 0.587785 0
vertex 1 0 0
vertex -0.951056 0.309017 0
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex -0.809017 0.587785 0
vertex -0.951056 0.309017 0
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex -0.809017 0.587785 0
vertex -0.809017 0.587785 2
vertex -0.587785 0.809017 2
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.951056 0.309017 0
vertex 1 0 0
vertex -1 -8.74228e-08 0
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex -0.951056 0.309017 0
vertex -1 -8.74228e-08 0
vertex -0.951056 0.309017 2
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex -0.951056 0.309017 0
vertex -0.951056 0.309017 2
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -1 -8.74228e-08 0
vertex 1 0 0
vertex -0.951057 -0.309017 0
endloop
endfacet
facet normal -0.987688 -0.156434 0
outer loop
vertex -1 -8.74228e-08 0
vertex -0.951057 -0.309017 0
vertex -1 -8.74228e-08 2
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex -1 -8.74228e-08 0
vertex -1 -8.74228e-08 2
vertex -0.951056 0.309017 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.951057 -0.309017 0
vertex 1 0 0
vertex -0.809017 -0.587785 0
endloop
endfacet
facet normal -0.891007 -0.453991 0
outer loop
vertex -0.951057 -0.309017 0
vertex -0.809017 -0.587785 0
vertex -0.951057 -0.309017 2
endloop
endfacet
facet normal -0.987688 -0.156434 0
outer loop
vertex -0.951057 -0.309017 0
vertex -0.951057 -0.309017 2
vertex -1 -8.74228e-08 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.809017 -0.587785 0
vertex 1 0 0
vertex -0.587785 -0.809017 0
endloop
endfacet
facet normal -0.707107 -0.707107 0
outer loop
vertex -0.809017 -0.587785 0
vertex -0.587785 -0.809017 0
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal -0.891007 -0.453991 0
outer loop
vertex -0.809017 -0.587785 0
vertex -0.809017 -0.587785 2
vertex -0.951057 -0.309017 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.587785 -0.809017 0
vertex 1 0 0
vertex -0.309017 -0.951056 0
endloop
endfacet
facet normal -0.45399 -0.891007 0
outer loop
vertex -0.587785 -0.809017 0
vertex -0.309017 -0.951056 0
vertex -0.587785 -0.809017 2
endloop
endfacet
facet normal -0.707107 -0.707107 0
outer loop
vertex -0.587785 -0.809017 0
vertex -0.587785 -0.809017 2
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.309017 -0.951056 0
vertex 1 0 0
vertex 1.19249e-08 -1 0
endloop
endfacet
facet normal -0.156435 -0.987688 0
outer loop
vertex -0.309017 -0.951056 0
vertex 1.19249e-08 -1 0
vertex -0.309017 -0.951056 2
endloop
endfacet
facet normal -0.45399 -0.891007 0
outer loop
vertex -0.309017 -0.951056 0
vertex -0.309017 -0.951056 2
vertex -0.587785 -0.809017 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 1.19249e-08 -1 0
vertex 1 0 0
vertex 0.309017 -0.951056 0
endloop
endfacet
facet normal 0.156435 -0.987688 0
outer loop
vertex 1.19249e-08 -1 0
vertex 0.309017 -0.951056 0
vertex 1.19249e-08 -1 2
endloop
endfacet
facet normal -0.156435 -0.987688 0
outer loop
vertex 1.19249e-08 -1 0
vertex 1.19249e-08 -1 2
vertex -0.309017 -0.951056 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.309017 -0.951056 0
vertex 1 0 0
vertex 0.587785 -0.809017 0
endloop
endfacet
facet normal 0.45399 -0.891006 0
outer loop
vertex 0.309017 -0.951056 0
vertex 0.587785 -0.809017 0
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal 0.156435 -0.987688 0
outer loop
vertex 0.309017 -0.951056 0
vertex 0.309017 -0.951056 2
vertex 1.19249e-08 -1 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.587785 -0.809017 0
vertex 1 0 0
vertex 0.809017 -0.587785 0
endloop
endfacet
facet normal 0.707107 -0.707107 0
outer loop
vertex 0.587785 -0.809017 0
vertex 0.809017 -0.587785 0
vertex 0.587785 -0.809017 2
endloop
endfacet
facet normal 0.45399 -0.891006 0
outer loop
vertex 0.587785 -0.809017 0
vertex 0.587785 -0.809017 2
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.809017 -0.587785 0
vertex 1 0 0
vertex 0.951057 -0.309017 0
endloop
endfacet
facet normal 0.891007 -0.453991 0
outer loop
vertex 0.809017 -0.587785 0
vertex 0.951057 -0.309017 0
vertex 0.809017 -0.587785 2
endloop
endfacet
facet normal 0.707107 -0.707107 0
outer loop
vertex 0.809017 -0.587785 0
vertex 0.809017 -0.587785 2
vertex 0.587785 -0.809017 2
endloop
endfacet
facet normal 0.987688 -0.156434 0
outer loop
vertex 0.951057 -0.309017 0
vertex 1 0 0
vertex 0.951057 -0.309017 2
endloop
endfacet
facet normal 0.891007 -0.453991 0
outer loop
vertex 0.951057 -0.309017 0
vertex 0.951057 -0.309017 2
vertex 0.809017 -0.587785 2
endloop
endfacet
facet normal nan nan nan
outer loop
vertex 1 0 2
vertex 0.951057 0.309017 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.951057 0.309017 2
vertex 0.809017 0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.809017 0.587785 2
vertex 0.587785 0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.587785 0.809017 2
vertex 0.309017 0.951057 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.309017 0.951057 2
vertex -4.37114e-08 1 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -4.37114e-08 1 2
vertex -0.309017 0.951056 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.309017 0.951056 2
vertex -0.587785 0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.587785 0.809017 2
vertex -0.809017 0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.809017 0.587785 2
vertex -0.951056 0.309017 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.951056 0.309017 2
vertex -1 -8.74228e-08 2
vertex 1 0 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex -1 -8.74228e-08 2
vertex -0.951057 -0.309017 2
vertex 1 0 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex -0.951057 -0.309017 2
vertex -0.809017 -0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex -0.809017 -0.587785 2
vertex -0.587785 -0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex -0.587785 -0.809017 2
vertex -0.309017 -0.951056 2
vertex 1 0 2
endloop
endfacet
facet normal -0 0 1
outer loop
vertex -0.309017 -0.951056 2
vertex 1.19249e-08 -1 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1.19249e-08 -1 2
vertex 0.309017 -0.951056 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.309017 -0.951056 2
vertex 0.587785 -0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.587785 -0.809017 2
vertex 0.809017 -0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 0.809017 -0.587785 2
vertex 0.951057 -0.309017 2
vertex 1 0 2
endloop
endfacet
endsolid fast_trimesh STL file
```

## torus

```stl
solid fast_trimesh STL file
facet normal 0.986993 0.156324 0.0375301
outer loop
vertex 1 2 0
vertex 0.951057 2.30902 0
vertex 1 1.78201 0.907981
endloop
endfacet
facet normal 0.986993 -0.156324 -0.0375301
outer loop
vertex 1 2 0
vertex 1 1.78201 0.907981
vertex 0.951057 1.50668 0.76769
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.951057 2.30902 0
vertex 1 2 0
vertex 0.809017 2.58779 0
endloop
endfacet
facet normal 0.885761 0.451318 0.108352
outer loop
vertex 0.951057 2.30902 0
vertex 0.809017 2.58779 0
vertex 0.951057 2.05735 1.04827
endloop
endfacet
facet normal 0.986993 0.156324 0.0375301
outer loop
vertex 0.951057 2.30902 0
vertex 0.951057 2.05735 1.04827
vertex 1 1.78201 0.907981
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.809017 2.58779 0
vertex 1 2 0
vertex 0.587785 2.80902 0
endloop
endfacet
facet normal 0.697133 0.697133 0.167367
outer loop
vertex 0.809017 2.58779 0
vertex 0.587785 2.80902 0
vertex 0.809017 2.30573 1.17483
endloop
endfacet
facet normal 0.885761 0.451318 0.108352
outer loop
vertex 0.809017 2.58779 0
vertex 0.809017 2.30573 1.17483
vertex 0.951057 2.05735 1.04827
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.587785 2.80902 0
vertex 1 2 0
vertex 0.309017 2.95106 0
endloop
endfacet
facet normal 0.443947 0.871295 0.209179
outer loop
vertex 0.587785 2.80902 0
vertex 0.309017 2.95106 0
vertex 0.587785 2.50285 1.27527
endloop
endfacet
facet normal 0.697133 0.697133 0.167367
outer loop
vertex 0.587785 2.80902 0
vertex 0.587785 2.50285 1.27527
vertex 0.809017 2.30573 1.17483
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.309017 2.95106 0
vertex 1 2 0
vertex -4.37114e-08 3 0
endloop
endfacet
facet normal 0.152214 0.961039 0.230725
outer loop
vertex 0.309017 2.95106 0
vertex -4.37114e-08 3 0
vertex 0.309017 2.62941 1.33975
endloop
endfacet
facet normal 0.443947 0.871295 0.209179
outer loop
vertex 0.309017 2.95106 0
vertex 0.309017 2.62941 1.33975
vertex 0.587785 2.50285 1.27527
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -4.37114e-08 3 0
vertex 1 2 0
vertex -0.309017 2.95106 0
endloop
endfacet
facet normal -0.152214 0.961039 0.230725
outer loop
vertex -4.37114e-08 3 0
vertex -0.309017 2.95106 0
vertex -4.37114e-08 2.67302 1.36197
endloop
endfacet
facet normal 0.152214 0.961039 0.230725
outer loop
vertex -4.37114e-08 3 0
vertex -4.37114e-08 2.67302 1.36197
vertex 0.309017 2.62941 1.33975
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.309017 2.95106 0
vertex 1 2 0
vertex -0.587785 2.80902 0
endloop
endfacet
facet normal -0.443947 0.871295 0.209179
outer loop
vertex -0.309017 2.95106 0
vertex -0.587785 2.80902 0
vertex -0.309017 2.62941 1.33975
endloop
endfacet
facet normal -0.152214 0.961039 0.230725
outer loop
vertex -0.309017 2.95106 0
vertex -0.309017 2.62941 1.33975
vertex -4.37114e-08 2.67302 1.36197
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.587785 2.80902 0
vertex 1 2 0
vertex -0.809017 2.58779 0
endloop
endfacet
facet normal -0.697133 0.697133 0.167367
outer loop
vertex -0.587785 2.80902 0
vertex -0.809017 2.58779 0
vertex -0.587785 2.50285 1.27527
endloop
endfacet
facet normal -0.443947 0.871295 0.209179
outer loop
vertex -0.587785 2.80902 0
vertex -0.587785 2.50285 1.27527
vertex -0.309017 2.62941 1.33975
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.809017 2.58779 0
vertex 1 2 0
vertex -0.951056 2.30902 0
endloop
endfacet
facet normal -0.885761 0.451317 0.108352
outer loop
vertex -0.809017 2.58779 0
vertex -0.951056 2.30902 0
vertex -0.809017 2.30573 1.17483
endloop
endfacet
facet normal -0.697133 0.697133 0.167367
outer loop
vertex -0.809017 2.58779 0
vertex -0.809017 2.30573 1.17483
vertex -0.587785 2.50285 1.27527
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.951056 2.30902 0
vertex 1 2 0
vertex -1 2 0
endloop
endfacet
facet normal -0.986992 0.156324 0.0375301
outer loop
vertex -0.951056 2.30902 0
vertex -1 2 0
vertex -0.951056 2.05735 1.04827
endloop
endfacet
facet normal -0.885761 0.451318 0.108352
outer loop
vertex -0.951056 2.30902 0
vertex -0.951056 2.05735 1.04827
vertex -0.809017 2.30573 1.17483
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -1 2 0
vertex 1 2 0
vertex -0.951057 1.69098 0
endloop
endfacet
facet normal -0.986992 -0.156324 -0.0375301
outer loop
vertex -1 2 0
vertex -0.951057 1.69098 0
vertex -1 1.78201 0.907981
endloop
endfacet
facet normal -0.986993 0.156324 0.0375301
outer loop
vertex -1 2 0
vertex -1 1.78201 0.907981
vertex -0.951056 2.05735 1.04827
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.951057 1.69098 0
vertex 1 2 0
vertex -0.809017 1.41221 0
endloop
endfacet
facet normal -0.885761 -0.451318 -0.108352
outer loop
vertex -0.951057 1.69098 0
vertex -0.809017 1.41221 0
vertex -0.951057 1.50668 0.76769
endloop
endfacet
facet normal -0.986992 -0.156324 -0.0375301
outer loop
vertex -0.951057 1.69098 0
vertex -0.951057 1.50668 0.76769
vertex -1 1.78201 0.907981
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.809017 1.41221 0
vertex 1 2 0
vertex -0.587785 1.19098 0
endloop
endfacet
facet normal -0.697133 -0.697133 -0.167367
outer loop
vertex -0.809017 1.41221 0
vertex -0.587785 1.19098 0
vertex -0.809017 1.25829 0.641132
endloop
endfacet
facet normal -0.885761 -0.451318 -0.108352
outer loop
vertex -0.809017 1.41221 0
vertex -0.809017 1.25829 0.641132
vertex -0.951057 1.50668 0.76769
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.587785 1.19098 0
vertex 1 2 0
vertex -0.309017 1.04894 0
endloop
endfacet
facet normal -0.443947 -0.871295 -0.20918
outer loop
vertex -0.587785 1.19098 0
vertex -0.309017 1.04894 0
vertex -0.587785 1.06117 0.540695
endloop
endfacet
facet normal -0.697133 -0.697133 -0.167367
outer loop
vertex -0.587785 1.19098 0
vertex -0.587785 1.06117 0.540695
vertex -0.809017 1.25829 0.641132
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.309017 1.04894 0
vertex 1 2 0
vertex 1.19249e-08 1 0
endloop
endfacet
facet normal -0.152214 -0.96104 -0.230725
outer loop
vertex -0.309017 1.04894 0
vertex 1.19249e-08 1 0
vertex -0.309017 0.934616 0.47621
endloop
endfacet
facet normal -0.443947 -0.871295 -0.209179
outer loop
vertex -0.309017 1.04894 0
vertex -0.309017 0.934616 0.47621
vertex -0.587785 1.06117 0.540695
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 1.19249e-08 1 0
vertex 1 2 0
vertex 0.309017 1.04894 0
endloop
endfacet
facet normal 0.152214 -0.961039 -0.230725
outer loop
vertex 1.19249e-08 1 0
vertex 0.309017 1.04894 0
vertex 1.19249e-08 0.891007 0.453991
endloop
endfacet
facet normal -0.152214 -0.961039 -0.230725
outer loop
vertex 1.19249e-08 1 0
vertex 1.19249e-08 0.891007 0.453991
vertex -0.309017 0.934616 0.47621
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.309017 1.04894 0
vertex 1 2 0
vertex 0.587785 1.19098 0
endloop
endfacet
facet normal 0.443947 -0.871295 -0.209179
outer loop
vertex 0.309017 1.04894 0
vertex 0.587785 1.19098 0
vertex 0.309017 0.934616 0.47621
endloop
endfacet
facet normal 0.152214 -0.961039 -0.230725
outer loop
vertex 0.309017 1.04894 0
vertex 0.309017 0.934616 0.47621
vertex 1.19249e-08 0.891007 0.453991
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.587785 1.19098 0
vertex 1 2 0
vertex 0.809017 1.41221 0
endloop
endfacet
facet normal 0.697133 -0.697133 -0.167367
outer loop
vertex 0.587785 1.19098 0
vertex 0.809017 1.41221 0
vertex 0.587785 1.06117 0.540695
endloop
endfacet
facet normal 0.443947 -0.871295 -0.20918
outer loop
vertex 0.587785 1.19098 0
vertex 0.587785 1.06117 0.540695
vertex 0.309017 0.934616 0.47621
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.809017 1.41221 0
vertex 1 2 0
vertex 0.951057 1.69098 0
endloop
endfacet
facet normal 0.885761 -0.451318 -0.108352
outer loop
vertex 0.809017 1.41221 0
vertex 0.951057 1.69098 0
vertex 0.809017 1.25829 0.641132
endloop
endfacet
facet normal 0.697133 -0.697133 -0.167367
outer loop
vertex 0.809017 1.41221 0
vertex 0.809017 1.25829 0.641132
vertex 0.587785 1.06117 0.540695
endloop
endfacet
facet normal 0.986993 -0.156324 -0.0375301
outer loop
vertex 0.951057 1.69098 0
vertex 1 2 0
vertex 0.951057 1.50668 0.76769
endloop
endfacet
facet normal 0.885761 -0.451318 -0.108352
outer loop
vertex 0.951057 1.69098 0
vertex 0.951057 1.50668 0.76769
vertex 0.809017 1.25829 0.641132
endloop
endfacet
facet normal 0.986993 0.122248 0.104409
outer loop
vertex 1 1.78201 0.907981
vertex 0.951057 2.05735 1.04827
vertex 1 1.17557 1.61803
endloop
endfacet
facet normal 0.986993 -0.122248 -0.104409
outer loop
vertex 1 1.78201 0.907981
vertex 1 1.17557 1.61803
vertex 0.951057 0.993935 1.36803
endloop
endfacet
facet normal 0.885761 0.352936 0.301436
outer loop
vertex 0.951057 2.05735 1.04827
vertex 0.809017 2.30573 1.17483
vertex 0.951057 1.35721 1.86803
endloop
endfacet
facet normal 0.986993 0.122248 0.104409
outer loop
vertex 0.951057 2.05735 1.04827
vertex 0.951057 1.35721 1.86803
vertex 1 1.17557 1.61803
endloop
endfacet
facet normal 0.697133 0.545167 0.465617
outer loop
vertex 0.809017 2.30573 1.17483
vertex 0.587785 2.50285 1.27527
vertex 0.809017 1.52106 2.09356
endloop
endfacet
facet normal 0.885761 0.352936 0.301436
outer loop
vertex 0.809017 2.30573 1.17483
vertex 0.809017 1.52106 2.09356
vertex 0.951057 1.35721 1.86803
endloop
endfacet
facet normal 0.443947 0.681364 0.58194
outer loop
vertex 0.587785 2.50285 1.27527
vertex 0.309017 2.62941 1.33975
vertex 0.587785 1.6511 2.27254
endloop
endfacet
facet normal 0.697133 0.545167 0.465617
outer loop
vertex 0.587785 2.50285 1.27527
vertex 0.587785 1.6511 2.27254
vertex 0.809017 1.52106 2.09356
endloop
endfacet
facet normal 0.152214 0.751545 0.64188
outer loop
vertex 0.309017 2.62941 1.33975
vertex -4.37114e-08 2.67302 1.36197
vertex 0.309017 1.73459 2.38745
endloop
endfacet
facet normal 0.443947 0.681364 0.58194
outer loop
vertex 0.309017 2.62941 1.33975
vertex 0.309017 1.73459 2.38745
vertex 0.587785 1.6511 2.27254
endloop
endfacet
facet normal -0.152214 0.751545 0.64188
outer loop
vertex -4.37114e-08 2.67302 1.36197
vertex -0.309017 2.62941 1.33975
vertex -4.37114e-08 1.76336 2.42705
endloop
endfacet
facet normal 0.152214 0.751545 0.64188
outer loop
vertex -4.37114e-08 2.67302 1.36197
vertex -4.37114e-08 1.76336 2.42705
vertex 0.309017 1.73459 2.38745
endloop
endfacet
facet normal -0.443947 0.681364 0.58194
outer loop
vertex -0.309017 2.62941 1.33975
vertex -0.587785 2.50285 1.27527
vertex -0.309017 1.73459 2.38745
endloop
endfacet
facet normal -0.152214 0.751545 0.64188
outer loop
vertex -0.309017 2.62941 1.33975
vertex -0.309017 1.73459 2.38745
vertex -4.37114e-08 1.76336 2.42705
endloop
endfacet
facet normal -0.697133 0.545167 0.465617
outer loop
vertex -0.587785 2.50285 1.27527
vertex -0.809017 2.30573 1.17483
vertex -0.587785 1.6511 2.27254
endloop
endfacet
facet normal -0.443947 0.681364 0.58194
outer loop
vertex -0.587785 2.50285 1.27527
vertex -0.587785 1.6511 2.27254
vertex -0.309017 1.73459 2.38745
endloop
endfacet
facet normal -0.885761 0.352936 0.301436
outer loop
vertex -0.809017 2.30573 1.17483
vertex -0.951056 2.05735 1.04827
vertex -0.809017 1.52106 2.09356
endloop
endfacet
facet normal -0.697132 0.545167 0.465617
outer loop
vertex -0.809017 2.30573 1.17483
vertex -0.809017 1.52106 2.09356
vertex -0.587785 1.6511 2.27254
endloop
endfacet
facet normal -0.986993 0.122248 0.104409
outer loop
vertex -0.951056 2.05735 1.04827
vertex -1 1.78201 0.907981
vertex -0.951056 1.35721 1.86803
endloop
endfacet
facet normal -0.885761 0.352936 0.301436
outer loop
vertex -0.951056 2.05735 1.04827
vertex -0.951056 1.35721 1.86803
vertex -0.809017 1.52106 2.09356
endloop
endfacet
facet normal -0.986992 -0.122248 -0.104409
outer loop
vertex -1 1.78201 0.907981
vertex -0.951057 1.50668 0.76769
vertex -1 1.17557 1.61803
endloop
endfacet
facet normal -0.986992 0.122248 0.104409
outer loop
vertex -1 1.78201 0.907981
vertex -1 1.17557 1.61803
vertex -0.951056 1.35721 1.86803
endloop
endfacet
facet normal -0.885761 -0.352936 -0.301436
outer loop
vertex -0.951057 1.50668 0.76769
vertex -0.809017 1.25829 0.641132
vertex -0.951057 0.993935 1.36803
endloop
endfacet
facet normal -0.986993 -0.122248 -0.104409
outer loop
vertex -0.951057 1.50668 0.76769
vertex -0.951057 0.993935 1.36803
vertex -1 1.17557 1.61803
endloop
endfacet
facet normal -0.697133 -0.545167 -0.465617
outer loop
vertex -0.809017 1.25829 0.641132
vertex -0.587785 1.06117 0.540695
vertex -0.809017 0.830079 1.14251
endloop
endfacet
facet normal -0.885761 -0.352936 -0.301436
outer loop
vertex -0.809017 1.25829 0.641132
vertex -0.809017 0.830079 1.14251
vertex -0.951057 0.993935 1.36803
endloop
endfacet
facet normal -0.443947 -0.681364 -0.58194
outer loop
vertex -0.587785 1.06117 0.540695
vertex -0.309017 0.934616 0.47621
vertex -0.587785 0.700042 0.963525
endloop
endfacet
facet normal -0.697133 -0.545167 -0.465617
outer loop
vertex -0.587785 1.06117 0.540695
vertex -0.587785 0.700042 0.963525
vertex -0.809017 0.830079 1.14251
endloop
endfacet
facet normal -0.152214 -0.751545 -0.64188
outer loop
vertex -0.309017 0.934616 0.47621
vertex 1.19249e-08 0.891007 0.453991
vertex -0.309017 0.616554 0.848613
endloop
endfacet
facet normal -0.443947 -0.681364 -0.58194
outer loop
vertex -0.309017 0.934616 0.47621
vertex -0.309017 0.616554 0.848613
vertex -0.587785 0.700042 0.963525
endloop
endfacet
facet normal 0.152214 -0.751545 -0.64188
outer loop
vertex 1.19249e-08 0.891007 0.453991
vertex 0.309017 0.934616 0.47621
vertex 1.19249e-08 0.587785 0.809017
endloop
endfacet
facet normal -0.152214 -0.751545 -0.64188
outer loop
vertex 1.19249e-08 0.891007 0.453991
vertex 1.19249e-08 0.587785 0.809017
vertex -0.309017 0.616554 0.848613
endloop
endfacet
facet normal 0.443947 -0.681364 -0.58194
outer loop
vertex 0.309017 0.934616 0.47621
vertex 0.587785 1.06117 0.540695
vertex 0.309017 0.616554 0.848613
endloop
endfacet
facet normal 0.152214 -0.751545 -0.64188
outer loop
vertex 0.309017 0.934616 0.47621
vertex 0.309017 0.616554 0.848613
vertex 1.19249e-08 0.587785 0.809017
endloop
endfacet
facet normal 0.697133 -0.545167 -0.465616
outer loop
vertex 0.587785 1.06117 0.540695
vertex 0.809017 1.25829 0.641132
vertex 0.587785 0.700042 0.963525
endloop
endfacet
facet normal 0.443947 -0.681364 -0.58194
outer loop
vertex 0.587785 1.06117 0.540695
vertex 0.587785 0.700042 0.963525
vertex 0.309017 0.616554 0.848613
endloop
endfacet
facet normal 0.885761 -0.352936 -0.301436
outer loop
vertex 0.809017 1.25829 0.641132
vertex 0.951057 1.50668 0.76769
vertex 0.809017 0.830079 1.14251
endloop
endfacet
facet normal 0.697133 -0.545167 -0.465616
outer loop
vertex 0.809017 1.25829 0.641132
vertex 0.809017 0.830079 1.14251
vertex 0.587785 0.700042 0.963525
endloop
endfacet
facet normal 0.986993 -0.122248 -0.104409
outer loop
vertex 0.951057 1.50668 0.76769
vertex 1 1.78201 0.907981
vertex 0.951057 0.993935 1.36803
endloop
endfacet
facet normal 0.885761 -0.352936 -0.301436
outer loop
vertex 0.951057 1.50668 0.76769
vertex 0.951057 0.993935 1.36803
vertex 0.809017 0.830079 1.14251
endloop
endfacet
facet normal 0.986993 0.0615226 0.148529
outer loop
vertex 1 1.17557 1.61803
vertex 0.951057 1.35721 1.86803
vertex 1 0.312869 1.97538
endloop
endfacet
facet normal 0.986993 -0.0615226 -0.148529
outer loop
vertex 1 1.17557 1.61803
vertex 1 0.312869 1.97538
vertex 0.951057 0.264528 1.67016
endloop
endfacet
facet normal 0.885761 0.177619 0.428811
outer loop
vertex 0.951057 1.35721 1.86803
vertex 0.809017 1.52106 2.09356
vertex 0.951057 0.36121 2.28059
endloop
endfacet
facet normal 0.986992 0.0615226 0.148529
outer loop
vertex 0.951057 1.35721 1.86803
vertex 0.951057 0.36121 2.28059
vertex 1 0.312869 1.97538
endloop
endfacet
facet normal 0.697133 0.274362 0.662368
outer loop
vertex 0.809017 1.52106 2.09356
vertex 0.587785 1.6511 2.27254
vertex 0.809017 0.404819 2.55593
endloop
endfacet
facet normal 0.885761 0.177619 0.428811
outer loop
vertex 0.809017 1.52106 2.09356
vertex 0.809017 0.404819 2.55593
vertex 0.951057 0.36121 2.28059
endloop
endfacet
facet normal 0.443947 0.342905 0.827845
outer loop
vertex 0.587785 1.6511 2.27254
vertex 0.309017 1.73459 2.38745
vertex 0.587785 0.439427 2.77443
endloop
endfacet
facet normal 0.697133 0.274362 0.662368
outer loop
vertex 0.587785 1.6511 2.27254
vertex 0.587785 0.439427 2.77443
vertex 0.809017 0.404819 2.55593
endloop
endfacet
facet normal 0.152214 0.378224 0.913114
outer loop
vertex 0.309017 1.73459 2.38745
vertex -4.37114e-08 1.76336 2.42705
vertex 0.309017 0.461647 2.91472
endloop
endfacet
facet normal 0.443947 0.342905 0.827845
outer loop
vertex 0.309017 1.73459 2.38745
vertex 0.309017 0.461647 2.91472
vertex 0.587785 0.439427 2.77443
endloop
endfacet
facet normal -0.152214 0.378224 0.913114
outer loop
vertex -4.37114e-08 1.76336 2.42705
vertex -0.309017 1.73459 2.38745
vertex -4.37114e-08 0.469303 2.96307
endloop
endfacet
facet normal 0.152214 0.378224 0.913114
outer loop
vertex -4.37114e-08 1.76336 2.42705
vertex -4.37114e-08 0.469303 2.96307
vertex 0.309017 0.461647 2.91472
endloop
endfacet
facet normal -0.443947 0.342905 0.827845
outer loop
vertex -0.309017 1.73459 2.38745
vertex -0.587785 1.6511 2.27254
vertex -0.309017 0.461647 2.91472
endloop
endfacet
facet normal -0.152214 0.378224 0.913114
outer loop
vertex -0.309017 1.73459 2.38745
vertex -0.309017 0.461647 2.91472
vertex -4.37114e-08 0.469303 2.96307
endloop
endfacet
facet normal -0.697132 0.274362 0.662368
outer loop
vertex -0.587785 1.6511 2.27254
vertex -0.809017 1.52106 2.09356
vertex -0.587785 0.439427 2.77443
endloop
endfacet
facet normal -0.443947 0.342905 0.827845
outer loop
vertex -0.587785 1.6511 2.27254
vertex -0.587785 0.439427 2.77443
vertex -0.309017 0.461647 2.91472
endloop
endfacet
facet normal -0.885761 0.177619 0.428811
outer loop
vertex -0.809017 1.52106 2.09356
vertex -0.951056 1.35721 1.86803
vertex -0.809017 0.404819 2.55593
endloop
endfacet
facet normal -0.697133 0.274362 0.662368
outer loop
vertex -0.809017 1.52106 2.09356
vertex -0.809017 0.404819 2.55593
vertex -0.587785 0.439427 2.77443
endloop
endfacet
facet normal -0.986993 0.0615226 0.148529
outer loop
vertex -0.951056 1.35721 1.86803
vertex -1 1.17557 1.61803
vertex -0.951056 0.36121 2.28059
endloop
endfacet
facet normal -0.885761 0.177619 0.428811
outer loop
vertex -0.951056 1.35721 1.86803
vertex -0.951056 0.36121 2.28059
vertex -0.809017 0.404819 2.55593
endloop
endfacet
facet normal -0.986993 -0.0615226 -0.148529
outer loop
vertex -1 1.17557 1.61803
vertex -0.951057 0.993935 1.36803
vertex -1 0.312869 1.97538
endloop
endfacet
facet normal -0.986993 0.0615226 0.148529
outer loop
vertex -1 1.17557 1.61803
vertex -1 0.312869 1.97538
vertex -0.951056 0.36121 2.28059
endloop
endfacet
facet normal -0.885761 -0.177619 -0.428811
outer loop
vertex -0.951057 0.993935 1.36803
vertex -0.809017 0.830079 1.14251
vertex -0.951057 0.264528 1.67016
endloop
endfacet
facet normal -0.986992 -0.0615226 -0.148529
outer loop
vertex -0.951057 0.993935 1.36803
vertex -0.951057 0.264528 1.67016
vertex -1 0.312869 1.97538
endloop
endfacet
facet normal -0.697133 -0.274362 -0.662368
outer loop
vertex -0.809017 0.830079 1.14251
vertex -0.587785 0.700042 0.963525
vertex -0.809017 0.220919 1.39483
endloop
endfacet
facet normal -0.885761 -0.177619 -0.428811
outer loop
vertex -0.809017 0.830079 1.14251
vertex -0.809017 0.220919 1.39483
vertex -0.951057 0.264528 1.67016
endloop
endfacet
facet normal -0.443947 -0.342905 -0.827845
outer loop
vertex -0.587785 0.700042 0.963525
vertex -0.309017 0.616554 0.848613
vertex -0.587785 0.186311 1.17632
endloop
endfacet
facet normal -0.697133 -0.274362 -0.662368
outer loop
vertex -0.587785 0.700042 0.963525
vertex -0.587785 0.186311 1.17632
vertex -0.809017 0.220919 1.39483
endloop
endfacet
facet normal -0.152214 -0.378224 -0.913114
outer loop
vertex -0.309017 0.616554 0.848613
vertex 1.19249e-08 0.587785 0.809017
vertex -0.309017 0.164091 1.03603
endloop
endfacet
facet normal -0.443947 -0.342905 -0.827845
outer loop
vertex -0.309017 0.616554 0.848613
vertex -0.309017 0.164091 1.03603
vertex -0.587785 0.186311 1.17632
endloop
endfacet
facet normal 0.152214 -0.378224 -0.913114
outer loop
vertex 1.19249e-08 0.587785 0.809017
vertex 0.309017 0.616554 0.848613
vertex 1.19249e-08 0.156434 0.987688
endloop
endfacet
facet normal -0.152214 -0.378224 -0.913114
outer loop
vertex 1.19249e-08 0.587785 0.809017
vertex 1.19249e-08 0.156434 0.987688
vertex -0.309017 0.164091 1.03603
endloop
endfacet
facet normal 0.443947 -0.342905 -0.827845
outer loop
vertex 0.309017 0.616554 0.848613
vertex 0.587785 0.700042 0.963525
vertex 0.309017 0.164091 1.03603
endloop
endfacet
facet normal 0.152214 -0.378224 -0.913114
outer loop
vertex 0.309017 0.616554 0.848613
vertex 0.309017 0.164091 1.03603
vertex 1.19249e-08 0.156434 0.987688
endloop
endfacet
facet normal 0.697133 -0.274362 -0.662368
outer loop
vertex 0.587785 0.700042 0.963525
vertex 0.809017 0.830079 1.14251
vertex 0.587785 0.186311 1.17632
endloop
endfacet
facet normal 0.443947 -0.342905 -0.827845
outer loop
vertex 0.587785 0.700042 0.963525
vertex 0.587785 0.186311 1.17632
vertex 0.309017 0.164091 1.03603
endloop
endfacet
facet normal 0.885761 -0.17762 -0.428811
outer loop
vertex 0.809017 0.830079 1.14251
vertex 0.951057 0.993935 1.36803
vertex 0.809017 0.220919 1.39483
endloop
endfacet
facet normal 0.697133 -0.274362 -0.662368
outer loop
vertex 0.809017 0.830079 1.14251
vertex 0.809017 0.220919 1.39483
vertex 0.587785 0.186311 1.17632
endloop
endfacet
facet normal 0.986993 -0.0615226 -0.148529
outer loop
vertex 0.951057 0.993935 1.36803
vertex 1 1.17557 1.61803
vertex 0.951057 0.264528 1.67016
endloop
endfacet
facet normal 0.885761 -0.17762 -0.428811
outer loop
vertex 0.951057 0.993935 1.36803
vertex 0.951057 0.264528 1.67016
vertex 0.809017 0.220919 1.39483
endloop
endfacet
facet normal 0.986993 -0.0126136 0.160271
outer loop
vertex 1 0.312869 1.97538
vertex 0.951057 0.36121 2.28059
vertex 1 -0.618034 1.90211
endloop
endfacet
facet normal 0.986993 0.0126136 -0.160271
outer loop
vertex 1 0.312869 1.97538
vertex 1 -0.618034 1.90211
vertex 0.951057 -0.522543 1.60822
endloop
endfacet
facet normal 0.885761 -0.0364162 0.462711
outer loop
vertex 0.951057 0.36121 2.28059
vertex 0.809017 0.404819 2.55593
vertex 0.951057 -0.713526 2.19601
endloop
endfacet
facet normal 0.986993 -0.0126136 0.160271
outer loop
vertex 0.951057 0.36121 2.28059
vertex 0.951057 -0.713526 2.19601
vertex 1 -0.618034 1.90211
endloop
endfacet
facet normal 0.697133 -0.0562507 0.714732
outer loop
vertex 0.809017 0.404819 2.55593
vertex 0.587785 0.439427 2.77443
vertex 0.809017 -0.79967 2.46113
endloop
endfacet
facet normal 0.885761 -0.0364162 0.462711
outer loop
vertex 0.809017 0.404819 2.55593
vertex 0.809017 -0.79967 2.46113
vertex 0.951057 -0.713526 2.19601
endloop
endfacet
facet normal 0.443947 -0.0703036 0.893291
outer loop
vertex 0.587785 0.439427 2.77443
vertex 0.309017 0.461647 2.91472
vertex 0.587785 -0.868034 2.67153
endloop
endfacet
facet normal 0.697133 -0.0562507 0.714732
outer loop
vertex 0.587785 0.439427 2.77443
vertex 0.587785 -0.868034 2.67153
vertex 0.809017 -0.79967 2.46113
endloop
endfacet
facet normal 0.152214 -0.077545 0.985301
outer loop
vertex 0.309017 0.461647 2.91472
vertex -4.37114e-08 0.469303 2.96307
vertex 0.309017 -0.911927 2.80662
endloop
endfacet
facet normal 0.443947 -0.0703036 0.893291
outer loop
vertex 0.309017 0.461647 2.91472
vertex 0.309017 -0.911927 2.80662
vertex 0.587785 -0.868034 2.67153
endloop
endfacet
facet normal -0.152214 -0.077545 0.985301
outer loop
vertex -4.37114e-08 0.469303 2.96307
vertex -0.309017 0.461647 2.91472
vertex -4.37114e-08 -0.927051 2.85317
endloop
endfacet
facet normal 0.152214 -0.077545 0.985301
outer loop
vertex -4.37114e-08 0.469303 2.96307
vertex -4.37114e-08 -0.927051 2.85317
vertex 0.309017 -0.911927 2.80662
endloop
endfacet
facet normal -0.443947 -0.0703036 0.893291
outer loop
vertex -0.309017 0.461647 2.91472
vertex -0.587785 0.439427 2.77443
vertex -0.309017 -0.911927 2.80662
endloop
endfacet
facet normal -0.152214 -0.077545 0.985301
outer loop
vertex -0.309017 0.461647 2.91472
vertex -0.309017 -0.911927 2.80662
vertex -4.37114e-08 -0.927051 2.85317
endloop
endfacet
facet normal -0.697133 -0.0562507 0.714732
outer loop
vertex -0.587785 0.439427 2.77443
vertex -0.809017 0.404819 2.55593
vertex -0.587785 -0.868034 2.67153
endloop
endfacet
facet normal -0.443947 -0.0703036 0.893291
outer loop
vertex -0.587785 0.439427 2.77443
vertex -0.587785 -0.868034 2.67153
vertex -0.309017 -0.911927 2.80662
endloop
endfacet
facet normal -0.885761 -0.0364162 0.462711
outer loop
vertex -0.809017 0.404819 2.55593
vertex -0.951056 0.36121 2.28059
vertex -0.809017 -0.79967 2.46113
endloop
endfacet
facet normal -0.697133 -0.0562507 0.714732
outer loop
vertex -0.809017 0.404819 2.55593
vertex -0.809017 -0.79967 2.46113
vertex -0.587785 -0.868034 2.67153
endloop
endfacet
facet normal -0.986992 -0.0126136 0.160271
outer loop
vertex -0.951056 0.36121 2.28059
vertex -1 0.312869 1.97538
vertex -0.951056 -0.713526 2.19601
endloop
endfacet
facet normal -0.885761 -0.0364161 0.462711
outer loop
vertex -0.951056 0.36121 2.28059
vertex -0.951056 -0.713526 2.19601
vertex -0.809017 -0.79967 2.46113
endloop
endfacet
facet normal -0.986992 0.0126136 -0.160271
outer loop
vertex -1 0.312869 1.97538
vertex -0.951057 0.264528 1.67016
vertex -1 -0.618034 1.90211
endloop
endfacet
facet normal -0.986992 -0.0126136 0.160271
outer loop
vertex -1 0.312869 1.97538
vertex -1 -0.618034 1.90211
vertex -0.951056 -0.713526 2.19601
endloop
endfacet
facet normal -0.885761 0.0364162 -0.462711
outer loop
vertex -0.951057 0.264528 1.67016
vertex -0.809017 0.220919 1.39483
vertex -0.951057 -0.522543 1.60822
endloop
endfacet
facet normal -0.986992 0.0126136 -0.160271
outer loop
vertex -0.951057 0.264528 1.67016
vertex -0.951057 -0.522543 1.60822
vertex -1 -0.618034 1.90211
endloop
endfacet
facet normal -0.697133 0.0562507 -0.714732
outer loop
vertex -0.809017 0.220919 1.39483
vertex -0.587785 0.186311 1.17632
vertex -0.809017 -0.436398 1.3431
endloop
endfacet
facet normal -0.885761 0.0364162 -0.462711
outer loop
vertex -0.809017 0.220919 1.39483
vertex -0.809017 -0.436398 1.3431
vertex -0.951057 -0.522543 1.60822
endloop
endfacet
facet normal -0.443947 0.0703035 -0.893291
outer loop
vertex -0.587785 0.186311 1.17632
vertex -0.309017 0.164091 1.03603
vertex -0.587785 -0.368034 1.13269
endloop
endfacet
facet normal -0.697133 0.0562506 -0.714732
outer loop
vertex -0.587785 0.186311 1.17632
vertex -0.587785 -0.368034 1.13269
vertex -0.809017 -0.436398 1.3431
endloop
endfacet
facet normal -0.152214 0.077545 -0.985301
outer loop
vertex -0.309017 0.164091 1.03603
vertex 1.19249e-08 0.156434 0.987688
vertex -0.309017 -0.324141 0.997605
endloop
endfacet
facet normal -0.443947 0.0703036 -0.893291
outer loop
vertex -0.309017 0.164091 1.03603
vertex -0.309017 -0.324141 0.997605
vertex -0.587785 -0.368034 1.13269
endloop
endfacet
facet normal 0.152214 0.077545 -0.985301
outer loop
vertex 1.19249e-08 0.156434 0.987688
vertex 0.309017 0.164091 1.03603
vertex 1.19249e-08 -0.309017 0.951056
endloop
endfacet
facet normal -0.152214 0.077545 -0.985301
outer loop
vertex 1.19249e-08 0.156434 0.987688
vertex 1.19249e-08 -0.309017 0.951056
vertex -0.309017 -0.324141 0.997605
endloop
endfacet
facet normal 0.443947 0.0703036 -0.893291
outer loop
vertex 0.309017 0.164091 1.03603
vertex 0.587785 0.186311 1.17632
vertex 0.309017 -0.324141 0.997605
endloop
endfacet
facet normal 0.152214 0.077545 -0.985301
outer loop
vertex 0.309017 0.164091 1.03603
vertex 0.309017 -0.324141 0.997605
vertex 1.19249e-08 -0.309017 0.951056
endloop
endfacet
facet normal 0.697133 0.0562506 -0.714732
outer loop
vertex 0.587785 0.186311 1.17632
vertex 0.809017 0.220919 1.39483
vertex 0.587785 -0.368034 1.13269
endloop
endfacet
facet normal 0.443947 0.0703035 -0.893291
outer loop
vertex 0.587785 0.186311 1.17632
vertex 0.587785 -0.368034 1.13269
vertex 0.309017 -0.324141 0.997605
endloop
endfacet
facet normal 0.885761 0.0364162 -0.462711
outer loop
vertex 0.809017 0.220919 1.39483
vertex 0.951057 0.264528 1.67016
vertex 0.809017 -0.436398 1.3431
endloop
endfacet
facet normal 0.697133 0.0562507 -0.714732
outer loop
vertex 0.809017 0.220919 1.39483
vertex 0.809017 -0.436398 1.3431
vertex 0.587785 -0.368034 1.13269
endloop
endfacet
facet normal 0.986993 0.0126136 -0.160271
outer loop
vertex 0.951057 0.264528 1.67016
vertex 1 0.312869 1.97538
vertex 0.951057 -0.522543 1.60822
endloop
endfacet
facet normal 0.885761 0.0364162 -0.462711
outer loop
vertex 0.951057 0.264528 1.67016
vertex 0.951057 -0.522543 1.60822
vertex 0.809017 -0.436398 1.3431
endloop
endfacet
facet normal 0.986993 -0.0840001 0.137076
outer loop
vertex 1 -0.618034 1.90211
vertex 0.951057 -0.713526 2.19601
vertex 1 -1.41421 1.41421
endloop
endfacet
facet normal 0.986993 0.0840001 -0.137076
outer loop
vertex 1 -0.618034 1.90211
vertex 1 -1.41421 1.41421
vertex 0.951057 -1.19571 1.19571
endloop
endfacet
facet normal 0.885761 -0.242514 0.395746
outer loop
vertex 0.951057 -0.713526 2.19601
vertex 0.809017 -0.79967 2.46113
vertex 0.951057 -1.63272 1.63272
endloop
endfacet
facet normal 0.986993 -0.0840001 0.137076
outer loop
vertex 0.951057 -0.713526 2.19601
vertex 0.951057 -1.63272 1.63272
vertex 1 -1.41421 1.41421
endloop
endfacet
facet normal 0.697133 -0.374601 0.611294
outer loop
vertex 0.809017 -0.79967 2.46113
vertex 0.587785 -0.868034 2.67153
vertex 0.809017 -1.82984 1.82984
endloop
endfacet
facet normal 0.885761 -0.242514 0.395746
outer loop
vertex 0.809017 -0.79967 2.46113
vertex 0.809017 -1.82984 1.82984
vertex 0.951057 -1.63272 1.63272
endloop
endfacet
facet normal 0.443947 -0.468187 0.764011
outer loop
vertex 0.587785 -0.868034 2.67153
vertex 0.309017 -0.911927 2.80662
vertex 0.587785 -1.98627 1.98627
endloop
endfacet
facet normal 0.697133 -0.374601 0.611294
outer loop
vertex 0.587785 -0.868034 2.67153
vertex 0.587785 -1.98627 1.98627
vertex 0.809017 -1.82984 1.82984
endloop
endfacet
facet normal 0.152214 -0.51641 0.842705
outer loop
vertex 0.309017 -0.911927 2.80662
vertex -4.37114e-08 -0.927051 2.85317
vertex 0.309017 -2.08671 2.08671
endloop
endfacet
facet normal 0.443947 -0.468186 0.764011
outer loop
vertex 0.309017 -0.911927 2.80662
vertex 0.309017 -2.08671 2.08671
vertex 0.587785 -1.98627 1.98627
endloop
endfacet
facet normal -0.152214 -0.51641 0.842705
outer loop
vertex -4.37114e-08 -0.927051 2.85317
vertex -0.309017 -0.911927 2.80662
vertex -4.37114e-08 -2.12132 2.12132
endloop
endfacet
facet normal 0.152213 -0.51641 0.842705
outer loop
vertex -4.37114e-08 -0.927051 2.85317
vertex -4.37114e-08 -2.12132 2.12132
vertex 0.309017 -2.08671 2.08671
endloop
endfacet
facet normal -0.443947 -0.468186 0.764011
outer loop
vertex -0.309017 -0.911927 2.80662
vertex -0.587785 -0.868034 2.67153
vertex -0.309017 -2.08671 2.08671
endloop
endfacet
facet normal -0.152213 -0.51641 0.842705
outer loop
vertex -0.309017 -0.911927 2.80662
vertex -0.309017 -2.08671 2.08671
vertex -4.37114e-08 -2.12132 2.12132
endloop
endfacet
facet normal -0.697133 -0.374601 0.611294
outer loop
vertex -0.587785 -0.868034 2.67153
vertex -0.809017 -0.79967 2.46113
vertex -0.587785 -1.98627 1.98627
endloop
endfacet
facet normal -0.443948 -0.468186 0.764011
outer loop
vertex -0.587785 -0.868034 2.67153
vertex -0.587785 -1.98627 1.98627
vertex -0.309017 -2.08671 2.08671
endloop
endfacet
facet normal -0.885761 -0.242513 0.395746
outer loop
vertex -0.809017 -0.79967 2.46113
vertex -0.951056 -0.713526 2.19601
vertex -0.809017 -1.82984 1.82984
endloop
endfacet
facet normal -0.697133 -0.374601 0.611294
outer loop
vertex -0.809017 -0.79967 2.46113
vertex -0.809017 -1.82984 1.82984
vertex -0.587785 -1.98627 1.98627
endloop
endfacet
facet normal -0.986993 -0.0840002 0.137076
outer loop
vertex -0.951056 -0.713526 2.19601
vertex -1 -0.618034 1.90211
vertex -0.951056 -1.63272 1.63272
endloop
endfacet
facet normal -0.885761 -0.242513 0.395746
outer loop
vertex -0.951056 -0.713526 2.19601
vertex -0.951056 -1.63272 1.63272
vertex -0.809017 -1.82984 1.82984
endloop
endfacet
facet normal -0.986993 0.0840001 -0.137076
outer loop
vertex -1 -0.618034 1.90211
vertex -0.951057 -0.522543 1.60822
vertex -1 -1.41421 1.41421
endloop
endfacet
facet normal -0.986993 -0.0840002 0.137076
outer loop
vertex -1 -0.618034 1.90211
vertex -1 -1.41421 1.41421
vertex -0.951056 -1.63272 1.63272
endloop
endfacet
facet normal -0.885761 0.242514 -0.395746
outer loop
vertex -0.951057 -0.522543 1.60822
vertex -0.809017 -0.436398 1.3431
vertex -0.951057 -1.19571 1.19571
endloop
endfacet
facet normal -0.986992 0.0840001 -0.137076
outer loop
vertex -0.951057 -0.522543 1.60822
vertex -0.951057 -1.19571 1.19571
vertex -1 -1.41421 1.41421
endloop
endfacet
facet normal -0.697133 0.374601 -0.611294
outer loop
vertex -0.809017 -0.436398 1.3431
vertex -0.587785 -0.368034 1.13269
vertex -0.809017 -0.998587 0.998587
endloop
endfacet
facet normal -0.885761 0.242514 -0.395746
outer loop
vertex -0.809017 -0.436398 1.3431
vertex -0.809017 -0.998587 0.998587
vertex -0.951057 -1.19571 1.19571
endloop
endfacet
facet normal -0.443947 0.468187 -0.764011
outer loop
vertex -0.587785 -0.368034 1.13269
vertex -0.309017 -0.324141 0.997605
vertex -0.587785 -0.842152 0.842152
endloop
endfacet
facet normal -0.697133 0.374601 -0.611294
outer loop
vertex -0.587785 -0.368034 1.13269
vertex -0.587785 -0.842152 0.842152
vertex -0.809017 -0.998587 0.998587
endloop
endfacet
facet normal -0.152214 0.51641 -0.842705
outer loop
vertex -0.309017 -0.324141 0.997605
vertex 1.19249e-08 -0.309017 0.951056
vertex -0.309017 -0.741715 0.741715
endloop
endfacet
facet normal -0.443947 0.468187 -0.764011
outer loop
vertex -0.309017 -0.324141 0.997605
vertex -0.309017 -0.741715 0.741715
vertex -0.587785 -0.842152 0.842152
endloop
endfacet
facet normal 0.152214 0.51641 -0.842705
outer loop
vertex 1.19249e-08 -0.309017 0.951056
vertex 0.309017 -0.324141 0.997605
vertex 1.19249e-08 -0.707107 0.707107
endloop
endfacet
facet normal -0.152214 0.51641 -0.842705
outer loop
vertex 1.19249e-08 -0.309017 0.951056
vertex 1.19249e-08 -0.707107 0.707107
vertex -0.309017 -0.741715 0.741715
endloop
endfacet
facet normal 0.443947 0.468186 -0.764011
outer loop
vertex 0.309017 -0.324141 0.997605
vertex 0.587785 -0.368034 1.13269
vertex 0.309017 -0.741715 0.741715
endloop
endfacet
facet normal 0.152214 0.51641 -0.842705
outer loop
vertex 0.309017 -0.324141 0.997605
vertex 0.309017 -0.741715 0.741715
vertex 1.19249e-08 -0.707107 0.707107
endloop
endfacet
facet normal 0.697133 0.374601 -0.611293
outer loop
vertex 0.587785 -0.368034 1.13269
vertex 0.809017 -0.436398 1.3431
vertex 0.587785 -0.842152 0.842152
endloop
endfacet
facet normal 0.443947 0.468187 -0.764011
outer loop
vertex 0.587785 -0.368034 1.13269
vertex 0.587785 -0.842152 0.842152
vertex 0.309017 -0.741715 0.741715
endloop
endfacet
facet normal 0.885761 0.242514 -0.395746
outer loop
vertex 0.809017 -0.436398 1.3431
vertex 0.951057 -0.522543 1.60822
vertex 0.809017 -0.998587 0.998587
endloop
endfacet
facet normal 0.697133 0.374601 -0.611293
outer loop
vertex 0.809017 -0.436398 1.3431
vertex 0.809017 -0.998587 0.998587
vertex 0.587785 -0.842152 0.842152
endloop
endfacet
facet normal 0.986992 0.0840001 -0.137076
outer loop
vertex 0.951057 -0.522543 1.60822
vertex 1 -0.618034 1.90211
vertex 0.951057 -1.19571 1.19571
endloop
endfacet
facet normal 0.885761 0.242514 -0.395746
outer loop
vertex 0.951057 -0.522543 1.60822
vertex 0.951057 -1.19571 1.19571
vertex 0.809017 -0.998587 0.998587
endloop
endfacet
facet normal 0.986993 -0.137076 0.0840001
outer loop
vertex 1 -1.41421 1.41421
vertex 0.951057 -1.63272 1.63272
vertex 1 -1.90211 0.618034
endloop
endfacet
facet normal 0.986993 0.137076 -0.0840001
outer loop
vertex 1 -1.41421 1.41421
vertex 1 -1.90211 0.618034
vertex 0.951057 -1.60822 0.522543
endloop
endfacet
facet normal 0.885761 -0.395746 0.242514
outer loop
vertex 0.951057 -1.63272 1.63272
vertex 0.809017 -1.82984 1.82984
vertex 0.951057 -2.19601 0.713526
endloop
endfacet
facet normal 0.986993 -0.137076 0.0840001
outer loop
vertex 0.951057 -1.63272 1.63272
vertex 0.951057 -2.19601 0.713526
vertex 1 -1.90211 0.618034
endloop
endfacet
facet normal 0.697133 -0.611294 0.374601
outer loop
vertex 0.809017 -1.82984 1.82984
vertex 0.587785 -1.98627 1.98627
vertex 0.809017 -2.46113 0.79967
endloop
endfacet
facet normal 0.885761 -0.395746 0.242514
outer loop
vertex 0.809017 -1.82984 1.82984
vertex 0.809017 -2.46113 0.79967
vertex 0.951057 -2.19601 0.713526
endloop
endfacet
facet normal 0.443948 -0.764011 0.468186
outer loop
vertex 0.587785 -1.98627 1.98627
vertex 0.309017 -2.08671 2.08671
vertex 0.587785 -2.67153 0.868034
endloop
endfacet
facet normal 0.697133 -0.611294 0.374601
outer loop
vertex 0.587785 -1.98627 1.98627
vertex 0.587785 -2.67153 0.868034
vertex 0.809017 -2.46113 0.79967
endloop
endfacet
facet normal 0.152213 -0.842705 0.51641
outer loop
vertex 0.309017 -2.08671 2.08671
vertex -4.37114e-08 -2.12132 2.12132
vertex 0.309017 -2.80662 0.911927
endloop
endfacet
facet normal 0.443947 -0.764011 0.468186
outer loop
vertex 0.309017 -2.08671 2.08671
vertex 0.309017 -2.80662 0.911927
vertex 0.587785 -2.67153 0.868034
endloop
endfacet
facet normal -0.152213 -0.842705 0.51641
outer loop
vertex -4.37114e-08 -2.12132 2.12132
vertex -0.309017 -2.08671 2.08671
vertex -4.37114e-08 -2.85317 0.927051
endloop
endfacet
facet normal 0.152214 -0.842705 0.51641
outer loop
vertex -4.37114e-08 -2.12132 2.12132
vertex -4.37114e-08 -2.85317 0.927051
vertex 0.309017 -2.80662 0.911927
endloop
endfacet
facet normal -0.443948 -0.764011 0.468186
outer loop
vertex -0.309017 -2.08671 2.08671
vertex -0.587785 -1.98627 1.98627
vertex -0.309017 -2.80662 0.911927
endloop
endfacet
facet normal -0.152214 -0.842705 0.51641
outer loop
vertex -0.309017 -2.08671 2.08671
vertex -0.309017 -2.80662 0.911927
vertex -4.37114e-08 -2.85317 0.927051
endloop
endfacet
facet normal -0.697132 -0.611294 0.374601
outer loop
vertex -0.587785 -1.98627 1.98627
vertex -0.809017 -1.82984 1.82984
vertex -0.587785 -2.67153 0.868034
endloop
endfacet
facet normal -0.443947 -0.764011 0.468187
outer loop
vertex -0.587785 -1.98627 1.98627
vertex -0.587785 -2.67153 0.868034
vertex -0.309017 -2.80662 0.911927
endloop
endfacet
facet normal -0.885761 -0.395746 0.242513
outer loop
vertex -0.809017 -1.82984 1.82984
vertex -0.951056 -1.63272 1.63272
vertex -0.809017 -2.46113 0.79967
endloop
endfacet
facet normal -0.697133 -0.611294 0.374601
outer loop
vertex -0.809017 -1.82984 1.82984
vertex -0.809017 -2.46113 0.79967
vertex -0.587785 -2.67153 0.868034
endloop
endfacet
facet normal -0.986993 -0.137076 0.0840002
outer loop
vertex -0.951056 -1.63272 1.63272
vertex -1 -1.41421 1.41421
vertex -0.951056 -2.19601 0.713526
endloop
endfacet
facet normal -0.885761 -0.395746 0.242513
outer loop
vertex -0.951056 -1.63272 1.63272
vertex -0.951056 -2.19601 0.713526
vertex -0.809017 -2.46113 0.79967
endloop
endfacet
facet normal -0.986993 0.137076 -0.0840001
outer loop
vertex -1 -1.41421 1.41421
vertex -0.951057 -1.19571 1.19571
vertex -1 -1.90211 0.618034
endloop
endfacet
facet normal -0.986993 -0.137076 0.0840002
outer loop
vertex -1 -1.41421 1.41421
vertex -1 -1.90211 0.618034
vertex -0.951056 -2.19601 0.713526
endloop
endfacet
facet normal -0.885761 0.395746 -0.242514
outer loop
vertex -0.951057 -1.19571 1.19571
vertex -0.809017 -0.998587 0.998587
vertex -0.951057 -1.60822 0.522543
endloop
endfacet
facet normal -0.986993 0.137076 -0.0840001
outer loop
vertex -0.951057 -1.19571 1.19571
vertex -0.951057 -1.60822 0.522543
vertex -1 -1.90211 0.618034
endloop
endfacet
facet normal -0.697133 0.611294 -0.374601
outer loop
vertex -0.809017 -0.998587 0.998587
vertex -0.587785 -0.842152 0.842152
vertex -0.809017 -1.3431 0.436398
endloop
endfacet
facet normal -0.885761 0.395746 -0.242514
outer loop
vertex -0.809017 -0.998587 0.998587
vertex -0.809017 -1.3431 0.436398
vertex -0.951057 -1.60822 0.522543
endloop
endfacet
facet normal -0.443947 0.764011 -0.468187
outer loop
vertex -0.587785 -0.842152 0.842152
vertex -0.309017 -0.741715 0.741715
vertex -0.587785 -1.13269 0.368034
endloop
endfacet
facet normal -0.697133 0.611294 -0.374601
outer loop
vertex -0.587785 -0.842152 0.842152
vertex -0.587785 -1.13269 0.368034
vertex -0.809017 -1.3431 0.436398
endloop
endfacet
facet normal -0.152214 0.842705 -0.51641
outer loop
vertex -0.309017 -0.741715 0.741715
vertex 1.19249e-08 -0.707107 0.707107
vertex -0.309017 -0.997605 0.324141
endloop
endfacet
facet normal -0.443947 0.764011 -0.468186
outer loop
vertex -0.309017 -0.741715 0.741715
vertex -0.309017 -0.997605 0.324141
vertex -0.587785 -1.13269 0.368034
endloop
endfacet
facet normal 0.152214 0.842705 -0.51641
outer loop
vertex 1.19249e-08 -0.707107 0.707107
vertex 0.309017 -0.741715 0.741715
vertex 1.19249e-08 -0.951056 0.309017
endloop
endfacet
facet normal -0.152214 0.842705 -0.51641
outer loop
vertex 1.19249e-08 -0.707107 0.707107
vertex 1.19249e-08 -0.951056 0.309017
vertex -0.309017 -0.997605 0.324141
endloop
endfacet
facet normal 0.443947 0.764011 -0.468186
outer loop
vertex 0.309017 -0.741715 0.741715
vertex 0.587785 -0.842152 0.842152
vertex 0.309017 -0.997605 0.324141
endloop
endfacet
facet normal 0.152214 0.842705 -0.51641
outer loop
vertex 0.309017 -0.741715 0.741715
vertex 0.309017 -0.997605 0.324141
vertex 1.19249e-08 -0.951056 0.309017
endloop
endfacet
facet normal 0.697133 0.611293 -0.374601
outer loop
vertex 0.587785 -0.842152 0.842152
vertex 0.809017 -0.998587 0.998587
vertex 0.587785 -1.13269 0.368034
endloop
endfacet
facet normal 0.443947 0.764011 -0.468187
outer loop
vertex 0.587785 -0.842152 0.842152
vertex 0.587785 -1.13269 0.368034
vertex 0.309017 -0.997605 0.324141
endloop
endfacet
facet normal 0.885761 0.395746 -0.242514
outer loop
vertex 0.809017 -0.998587 0.998587
vertex 0.951057 -1.19571 1.19571
vertex 0.809017 -1.3431 0.436398
endloop
endfacet
facet normal 0.697133 0.611293 -0.374601
outer loop
vertex 0.809017 -0.998587 0.998587
vertex 0.809017 -1.3431 0.436398
vertex 0.587785 -1.13269 0.368034
endloop
endfacet
facet normal 0.986992 0.137076 -0.0840001
outer loop
vertex 0.951057 -1.19571 1.19571
vertex 1 -1.41421 1.41421
vertex 0.951057 -1.60822 0.522543
endloop
endfacet
facet normal 0.885761 0.395746 -0.242514
outer loop
vertex 0.951057 -1.19571 1.19571
vertex 0.951057 -1.60822 0.522543
vertex 0.809017 -1.3431 0.436398
endloop
endfacet
facet normal 0.986992 -0.160271 0.0126136
outer loop
vertex 1 -1.90211 0.618034
vertex 0.951057 -2.19601 0.713526
vertex 1 -1.97538 -0.312869
endloop
endfacet
facet normal 0.986993 0.160271 -0.0126136
outer loop
vertex 1 -1.90211 0.618034
vertex 1 -1.97538 -0.312869
vertex 0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal 0.885761 -0.462711 0.0364162
outer loop
vertex 0.951057 -2.19601 0.713526
vertex 0.809017 -2.46113 0.79967
vertex 0.951057 -2.28059 -0.36121
endloop
endfacet
facet normal 0.986993 -0.160271 0.0126136
outer loop
vertex 0.951057 -2.19601 0.713526
vertex 0.951057 -2.28059 -0.36121
vertex 1 -1.97538 -0.312869
endloop
endfacet
facet normal 0.697133 -0.714732 0.0562506
outer loop
vertex 0.809017 -2.46113 0.79967
vertex 0.587785 -2.67153 0.868034
vertex 0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal 0.885761 -0.462711 0.0364161
outer loop
vertex 0.809017 -2.46113 0.79967
vertex 0.809017 -2.55593 -0.404819
vertex 0.951057 -2.28059 -0.36121
endloop
endfacet
facet normal 0.443947 -0.893291 0.0703034
outer loop
vertex 0.587785 -2.67153 0.868034
vertex 0.309017 -2.80662 0.911927
vertex 0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal 0.697133 -0.714732 0.0562505
outer loop
vertex 0.587785 -2.67153 0.868034
vertex 0.587785 -2.77443 -0.439427
vertex 0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal 0.152214 -0.985301 0.0775448
outer loop
vertex 0.309017 -2.80662 0.911927
vertex -4.37114e-08 -2.85317 0.927051
vertex 0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal 0.443947 -0.893291 0.0703035
outer loop
vertex 0.309017 -2.80662 0.911927
vertex 0.309017 -2.91472 -0.461647
vertex 0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal -0.152214 -0.985301 0.0775448
outer loop
vertex -4.37114e-08 -2.85317 0.927051
vertex -0.309017 -2.80662 0.911927
vertex -4.37114e-08 -2.96306 -0.469304
endloop
endfacet
facet normal 0.152214 -0.985301 0.0775448
outer loop
vertex -4.37114e-08 -2.85317 0.927051
vertex -4.37114e-08 -2.96306 -0.469304
vertex 0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal -0.443947 -0.893291 0.0703035
outer loop
vertex -0.309017 -2.80662 0.911927
vertex -0.587785 -2.67153 0.868034
vertex -0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal -0.152214 -0.985301 0.0775448
outer loop
vertex -0.309017 -2.80662 0.911927
vertex -0.309017 -2.91472 -0.461647
vertex -4.37114e-08 -2.96306 -0.469304
endloop
endfacet
facet normal -0.697133 -0.714732 0.0562506
outer loop
vertex -0.587785 -2.67153 0.868034
vertex -0.809017 -2.46113 0.79967
vertex -0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal -0.443947 -0.893291 0.0703034
outer loop
vertex -0.587785 -2.67153 0.868034
vertex -0.587785 -2.77443 -0.439427
vertex -0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal -0.885761 -0.462711 0.0364161
outer loop
vertex -0.809017 -2.46113 0.79967
vertex -0.951056 -2.19601 0.713526
vertex -0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal -0.697133 -0.714732 0.0562506
outer loop
vertex -0.809017 -2.46113 0.79967
vertex -0.809017 -2.55593 -0.404819
vertex -0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal -0.986993 -0.160271 0.0126136
outer loop
vertex -0.951056 -2.19601 0.713526
vertex -1 -1.90211 0.618034
vertex -0.951056 -2.28059 -0.36121
endloop
endfacet
facet normal -0.885761 -0.462711 0.0364162
outer loop
vertex -0.951056 -2.19601 0.713526
vertex -0.951056 -2.28059 -0.36121
vertex -0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal -0.986993 0.160271 -0.0126136
outer loop
vertex -1 -1.90211 0.618034
vertex -0.951057 -1.60822 0.522543
vertex -1 -1.97538 -0.312869
endloop
endfacet
facet normal -0.986993 -0.160271 0.0126136
outer loop
vertex -1 -1.90211 0.618034
vertex -1 -1.97538 -0.312869
vertex -0.951056 -2.28059 -0.36121
endloop
endfacet
facet normal -0.885761 0.462711 -0.0364162
outer loop
vertex -0.951057 -1.60822 0.522543
vertex -0.809017 -1.3431 0.436398
vertex -0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal -0.986992 0.160271 -0.0126136
outer loop
vertex -0.951057 -1.60822 0.522543
vertex -0.951057 -1.67016 -0.264528
vertex -1 -1.97538 -0.312869
endloop
endfacet
facet normal -0.697133 0.714732 -0.0562505
outer loop
vertex -0.809017 -1.3431 0.436398
vertex -0.587785 -1.13269 0.368034
vertex -0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal -0.885761 0.462711 -0.0364161
outer loop
vertex -0.809017 -1.3431 0.436398
vertex -0.809017 -1.39483 -0.220919
vertex -0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal -0.443947 0.893291 -0.0703035
outer loop
vertex -0.587785 -1.13269 0.368034
vertex -0.309017 -0.997605 0.324141
vertex -0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal -0.697133 0.714732 -0.0562506
outer loop
vertex -0.587785 -1.13269 0.368034
vertex -0.587785 -1.17632 -0.186311
vertex -0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal -0.152214 0.985301 -0.0775447
outer loop
vertex -0.309017 -0.997605 0.324141
vertex 1.19249e-08 -0.951056 0.309017
vertex -0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal -0.443947 0.893291 -0.0703034
outer loop
vertex -0.309017 -0.997605 0.324141
vertex -0.309017 -1.03603 -0.164091
vertex -0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal 0.152214 0.985301 -0.0775448
outer loop
vertex 1.19249e-08 -0.951056 0.309017
vertex 0.309017 -0.997605 0.324141
vertex 1.19249e-08 -0.987688 -0.156435
endloop
endfacet
facet normal -0.152214 0.985301 -0.0775448
outer loop
vertex 1.19249e-08 -0.951056 0.309017
vertex 1.19249e-08 -0.987688 -0.156435
vertex -0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal 0.443947 0.893291 -0.0703034
outer loop
vertex 0.309017 -0.997605 0.324141
vertex 0.587785 -1.13269 0.368034
vertex 0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal 0.152214 0.985301 -0.0775447
outer loop
vertex 0.309017 -0.997605 0.324141
vertex 0.309017 -1.03603 -0.164091
vertex 1.19249e-08 -0.987688 -0.156435
endloop
endfacet
facet normal 0.697133 0.714732 -0.0562506
outer loop
vertex 0.587785 -1.13269 0.368034
vertex 0.809017 -1.3431 0.436398
vertex 0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal 0.443947 0.893291 -0.0703035
outer loop
vertex 0.587785 -1.13269 0.368034
vertex 0.587785 -1.17632 -0.186311
vertex 0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal 0.885761 0.462711 -0.0364161
outer loop
vertex 0.809017 -1.3431 0.436398
vertex 0.951057 -1.60822 0.522543
vertex 0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal 0.697133 0.714732 -0.0562505
outer loop
vertex 0.809017 -1.3431 0.436398
vertex 0.809017 -1.39483 -0.220919
vertex 0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal 0.986993 0.160271 -0.0126136
outer loop
vertex 0.951057 -1.60822 0.522543
vertex 1 -1.90211 0.618034
vertex 0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal 0.885761 0.462711 -0.0364162
outer loop
vertex 0.951057 -1.60822 0.522543
vertex 0.951057 -1.67016 -0.264528
vertex 0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal 0.986993 -0.148529 -0.0615226
outer loop
vertex 1 -1.97538 -0.312869
vertex 0.951057 -2.28059 -0.36121
vertex 1 -1.61803 -1.17557
endloop
endfacet
facet normal 0.986993 0.148529 0.0615226
outer loop
vertex 1 -1.97538 -0.312869
vertex 1 -1.61803 -1.17557
vertex 0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal 0.885761 -0.428811 -0.17762
outer loop
vertex 0.951057 -2.28059 -0.36121
vertex 0.809017 -2.55593 -0.404819
vertex 0.951057 -1.86803 -1.35721
endloop
endfacet
facet normal 0.986993 -0.148529 -0.0615226
outer loop
vertex 0.951057 -2.28059 -0.36121
vertex 0.951057 -1.86803 -1.35721
vertex 1 -1.61803 -1.17557
endloop
endfacet
facet normal 0.697133 -0.662368 -0.274362
outer loop
vertex 0.809017 -2.55593 -0.404819
vertex 0.587785 -2.77443 -0.439427
vertex 0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal 0.885761 -0.428811 -0.177619
outer loop
vertex 0.809017 -2.55593 -0.404819
vertex 0.809017 -2.09356 -1.52106
vertex 0.951057 -1.86803 -1.35721
endloop
endfacet
facet normal 0.443947 -0.827845 -0.342905
outer loop
vertex 0.587785 -2.77443 -0.439427
vertex 0.309017 -2.91472 -0.461647
vertex 0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal 0.697133 -0.662368 -0.274362
outer loop
vertex 0.587785 -2.77443 -0.439427
vertex 0.587785 -2.27254 -1.6511
vertex 0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal 0.152214 -0.913114 -0.378224
outer loop
vertex 0.309017 -2.91472 -0.461647
vertex -4.37114e-08 -2.96306 -0.469304
vertex 0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal 0.443947 -0.827845 -0.342905
outer loop
vertex 0.309017 -2.91472 -0.461647
vertex 0.309017 -2.38745 -1.73459
vertex 0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal -0.152214 -0.913114 -0.378224
outer loop
vertex -4.37114e-08 -2.96306 -0.469304
vertex -0.309017 -2.91472 -0.461647
vertex -4.37114e-08 -2.42705 -1.76336
endloop
endfacet
facet normal 0.152214 -0.913114 -0.378224
outer loop
vertex -4.37114e-08 -2.96306 -0.469304
vertex -4.37114e-08 -2.42705 -1.76336
vertex 0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal -0.443947 -0.827845 -0.342905
outer loop
vertex -0.309017 -2.91472 -0.461647
vertex -0.587785 -2.77443 -0.439427
vertex -0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal -0.152214 -0.913114 -0.378224
outer loop
vertex -0.309017 -2.91472 -0.461647
vertex -0.309017 -2.38745 -1.73459
vertex -4.37114e-08 -2.42705 -1.76336
endloop
endfacet
facet normal -0.697132 -0.662368 -0.274362
outer loop
vertex -0.587785 -2.77443 -0.439427
vertex -0.809017 -2.55593 -0.404819
vertex -0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal -0.443947 -0.827845 -0.342905
outer loop
vertex -0.587785 -2.77443 -0.439427
vertex -0.587785 -2.27254 -1.6511
vertex -0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal -0.885761 -0.428811 -0.177619
outer loop
vertex -0.809017 -2.55593 -0.404819
vertex -0.951056 -2.28059 -0.36121
vertex -0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal -0.697133 -0.662368 -0.274362
outer loop
vertex -0.809017 -2.55593 -0.404819
vertex -0.809017 -2.09356 -1.52106
vertex -0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal -0.986993 -0.148529 -0.0615226
outer loop
vertex -0.951056 -2.28059 -0.36121
vertex -1 -1.97538 -0.312869
vertex -0.951056 -1.86803 -1.35721
endloop
endfacet
facet normal -0.885761 -0.428811 -0.177619
outer loop
vertex -0.951056 -2.28059 -0.36121
vertex -0.951056 -1.86803 -1.35721
vertex -0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal -0.986993 0.148529 0.0615226
outer loop
vertex -1 -1.97538 -0.312869
vertex -0.951057 -1.67016 -0.264528
vertex -1 -1.61803 -1.17557
endloop
endfacet
facet normal -0.986993 -0.148529 -0.0615226
outer loop
vertex -1 -1.97538 -0.312869
vertex -1 -1.61803 -1.17557
vertex -0.951056 -1.86803 -1.35721
endloop
endfacet
facet normal -0.885761 0.428811 0.177619
outer loop
vertex -0.951057 -1.67016 -0.264528
vertex -0.809017 -1.39483 -0.220919
vertex -0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal -0.986993 0.148529 0.0615226
outer loop
vertex -0.951057 -1.67016 -0.264528
vertex -0.951057 -1.36803 -0.993935
vertex -1 -1.61803 -1.17557
endloop
endfacet
facet normal -0.697133 0.662368 0.274362
outer loop
vertex -0.809017 -1.39483 -0.220919
vertex -0.587785 -1.17632 -0.186311
vertex -0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal -0.885761 0.428811 0.177619
outer loop
vertex -0.809017 -1.39483 -0.220919
vertex -0.809017 -1.14251 -0.830079
vertex -0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal -0.443947 0.827845 0.342905
outer loop
vertex -0.587785 -1.17632 -0.186311
vertex -0.309017 -1.03603 -0.164091
vertex -0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal -0.697133 0.662368 0.274362
outer loop
vertex -0.587785 -1.17632 -0.186311
vertex -0.587785 -0.963525 -0.700042
vertex -0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal -0.152214 0.913114 0.378224
outer loop
vertex -0.309017 -1.03603 -0.164091
vertex 1.19249e-08 -0.987688 -0.156435
vertex -0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal -0.443947 0.827845 0.342905
outer loop
vertex -0.309017 -1.03603 -0.164091
vertex -0.309017 -0.848613 -0.616554
vertex -0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal 0.152214 0.913114 0.378224
outer loop
vertex 1.19249e-08 -0.987688 -0.156435
vertex 0.309017 -1.03603 -0.164091
vertex 1.19249e-08 -0.809017 -0.587785
endloop
endfacet
facet normal -0.152214 0.913114 0.378224
outer loop
vertex 1.19249e-08 -0.987688 -0.156435
vertex 1.19249e-08 -0.809017 -0.587785
vertex -0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal 0.443947 0.827845 0.342905
outer loop
vertex 0.309017 -1.03603 -0.164091
vertex 0.587785 -1.17632 -0.186311
vertex 0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal 0.152214 0.913114 0.378224
outer loop
vertex 0.309017 -1.03603 -0.164091
vertex 0.309017 -0.848613 -0.616554
vertex 1.19249e-08 -0.809017 -0.587785
endloop
endfacet
facet normal 0.697133 0.662368 0.274362
outer loop
vertex 0.587785 -1.17632 -0.186311
vertex 0.809017 -1.39483 -0.220919
vertex 0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal 0.443947 0.827845 0.342905
outer loop
vertex 0.587785 -1.17632 -0.186311
vertex 0.587785 -0.963525 -0.700042
vertex 0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal 0.885761 0.428811 0.177619
outer loop
vertex 0.809017 -1.39483 -0.220919
vertex 0.951057 -1.67016 -0.264528
vertex 0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal 0.697133 0.662368 0.274362
outer loop
vertex 0.809017 -1.39483 -0.220919
vertex 0.809017 -1.14251 -0.830079
vertex 0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal 0.986992 0.148529 0.0615226
outer loop
vertex 0.951057 -1.67016 -0.264528
vertex 1 -1.97538 -0.312869
vertex 0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal 0.885761 0.428811 0.17762
outer loop
vertex 0.951057 -1.67016 -0.264528
vertex 0.951057 -1.36803 -0.993935
vertex 0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal 0.986992 -0.104409 -0.122248
outer loop
vertex 1 -1.61803 -1.17557
vertex 0.951057 -1.86803 -1.35721
vertex 1 -0.907981 -1.78201
endloop
endfacet
facet normal 0.986993 0.104409 0.122248
outer loop
vertex 1 -1.61803 -1.17557
vertex 1 -0.907981 -1.78201
vertex 0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal 0.885761 -0.301436 -0.352936
outer loop
vertex 0.951057 -1.86803 -1.35721
vertex 0.809017 -2.09356 -1.52106
vertex 0.951057 -1.04827 -2.05735
endloop
endfacet
facet normal 0.986992 -0.104409 -0.122248
outer loop
vertex 0.951057 -1.86803 -1.35721
vertex 0.951057 -1.04827 -2.05735
vertex 1 -0.907981 -1.78201
endloop
endfacet
facet normal 0.697133 -0.465617 -0.545167
outer loop
vertex 0.809017 -2.09356 -1.52106
vertex 0.587785 -2.27254 -1.6511
vertex 0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal 0.885761 -0.301436 -0.352936
outer loop
vertex 0.809017 -2.09356 -1.52106
vertex 0.809017 -1.17483 -2.30573
vertex 0.951057 -1.04827 -2.05735
endloop
endfacet
facet normal 0.443947 -0.58194 -0.681364
outer loop
vertex 0.587785 -2.27254 -1.6511
vertex 0.309017 -2.38745 -1.73459
vertex 0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal 0.697133 -0.465617 -0.545167
outer loop
vertex 0.587785 -2.27254 -1.6511
vertex 0.587785 -1.27527 -2.50285
vertex 0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal 0.152214 -0.64188 -0.751545
outer loop
vertex 0.309017 -2.38745 -1.73459
vertex -4.37114e-08 -2.42705 -1.76336
vertex 0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal 0.443947 -0.58194 -0.681364
outer loop
vertex 0.309017 -2.38745 -1.73459
vertex 0.309017 -1.33975 -2.62941
vertex 0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal -0.152214 -0.64188 -0.751545
outer loop
vertex -4.37114e-08 -2.42705 -1.76336
vertex -0.309017 -2.38745 -1.73459
vertex -4.37114e-08 -1.36197 -2.67302
endloop
endfacet
facet normal 0.152214 -0.641881 -0.751545
outer loop
vertex -4.37114e-08 -2.42705 -1.76336
vertex -4.37114e-08 -1.36197 -2.67302
vertex 0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal -0.443947 -0.58194 -0.681364
outer loop
vertex -0.309017 -2.38745 -1.73459
vertex -0.587785 -2.27254 -1.6511
vertex -0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal -0.152214 -0.64188 -0.751545
outer loop
vertex -0.309017 -2.38745 -1.73459
vertex -0.309017 -1.33975 -2.62941
vertex -4.37114e-08 -1.36197 -2.67302
endloop
endfacet
facet normal -0.697133 -0.465617 -0.545167
outer loop
vertex -0.587785 -2.27254 -1.6511
vertex -0.809017 -2.09356 -1.52106
vertex -0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal -0.443948 -0.58194 -0.681364
outer loop
vertex -0.587785 -2.27254 -1.6511
vertex -0.587785 -1.27527 -2.50285
vertex -0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal -0.885761 -0.301436 -0.352936
outer loop
vertex -0.809017 -2.09356 -1.52106
vertex -0.951056 -1.86803 -1.35721
vertex -0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal -0.697132 -0.465617 -0.545167
outer loop
vertex -0.809017 -2.09356 -1.52106
vertex -0.809017 -1.17483 -2.30573
vertex -0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal -0.986993 -0.104409 -0.122248
outer loop
vertex -0.951056 -1.86803 -1.35721
vertex -1 -1.61803 -1.17557
vertex -0.951056 -1.04827 -2.05735
endloop
endfacet
facet normal -0.885761 -0.301436 -0.352936
outer loop
vertex -0.951056 -1.86803 -1.35721
vertex -0.951056 -1.04827 -2.05735
vertex -0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal -0.986992 0.104409 0.122248
outer loop
vertex -1 -1.61803 -1.17557
vertex -0.951057 -1.36803 -0.993935
vertex -1 -0.907981 -1.78201
endloop
endfacet
facet normal -0.986992 -0.104409 -0.122248
outer loop
vertex -1 -1.61803 -1.17557
vertex -1 -0.907981 -1.78201
vertex -0.951056 -1.04827 -2.05735
endloop
endfacet
facet normal -0.885761 0.301436 0.352936
outer loop
vertex -0.951057 -1.36803 -0.993935
vertex -0.809017 -1.14251 -0.830079
vertex -0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal -0.986993 0.104409 0.122248
outer loop
vertex -0.951057 -1.36803 -0.993935
vertex -0.951057 -0.767691 -1.50668
vertex -1 -0.907981 -1.78201
endloop
endfacet
facet normal -0.697133 0.465617 0.545167
outer loop
vertex -0.809017 -1.14251 -0.830079
vertex -0.587785 -0.963525 -0.700042
vertex -0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal -0.885761 0.301436 0.352936
outer loop
vertex -0.809017 -1.14251 -0.830079
vertex -0.809017 -0.641132 -1.25829
vertex -0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal -0.443947 0.58194 0.681364
outer loop
vertex -0.587785 -0.963525 -0.700042
vertex -0.309017 -0.848613 -0.616554
vertex -0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal -0.697133 0.465617 0.545167
outer loop
vertex -0.587785 -0.963525 -0.700042
vertex -0.587785 -0.540695 -1.06117
vertex -0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal -0.152214 0.64188 0.751545
outer loop
vertex -0.309017 -0.848613 -0.616554
vertex 1.19249e-08 -0.809017 -0.587785
vertex -0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal -0.443947 0.58194 0.681364
outer loop
vertex -0.309017 -0.848613 -0.616554
vertex -0.309017 -0.476211 -0.934615
vertex -0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal 0.152214 0.64188 0.751545
outer loop
vertex 1.19249e-08 -0.809017 -0.587785
vertex 0.309017 -0.848613 -0.616554
vertex 1.19249e-08 -0.453991 -0.891006
endloop
endfacet
facet normal -0.152214 0.64188 0.751545
outer loop
vertex 1.19249e-08 -0.809017 -0.587785
vertex 1.19249e-08 -0.453991 -0.891006
vertex -0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal 0.443947 0.58194 0.681364
outer loop
vertex 0.309017 -0.848613 -0.616554
vertex 0.587785 -0.963525 -0.700042
vertex 0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal 0.152214 0.64188 0.751545
outer loop
vertex 0.309017 -0.848613 -0.616554
vertex 0.309017 -0.476211 -0.934615
vertex 1.19249e-08 -0.453991 -0.891006
endloop
endfacet
facet normal 0.697133 0.465617 0.545167
outer loop
vertex 0.587785 -0.963525 -0.700042
vertex 0.809017 -1.14251 -0.830079
vertex 0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal 0.443947 0.58194 0.681364
outer loop
vertex 0.587785 -0.963525 -0.700042
vertex 0.587785 -0.540695 -1.06117
vertex 0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal 0.885761 0.301436 0.352936
outer loop
vertex 0.809017 -1.14251 -0.830079
vertex 0.951057 -1.36803 -0.993935
vertex 0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal 0.697133 0.465617 0.545167
outer loop
vertex 0.809017 -1.14251 -0.830079
vertex 0.809017 -0.641132 -1.25829
vertex 0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal 0.986993 0.104409 0.122248
outer loop
vertex 0.951057 -1.36803 -0.993935
vertex 1 -1.61803 -1.17557
vertex 0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal 0.885761 0.301436 0.352936
outer loop
vertex 0.951057 -1.36803 -0.993935
vertex 0.951057 -0.767691 -1.50668
vertex 0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal 0.986993 -0.0375301 -0.156324
outer loop
vertex 1 -0.907981 -1.78201
vertex 0.951057 -1.04827 -2.05735
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 0.986993 0.0375301 0.156324
outer loop
vertex 1 -0.907981 -1.78201
vertex 1 2.38498e-08 -2
vertex 0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal 0.885761 -0.108352 -0.451318
outer loop
vertex 0.951057 -1.04827 -2.05735
vertex 0.809017 -1.17483 -2.30573
vertex 0.951057 2.75348e-08 -2.30902
endloop
endfacet
facet normal 0.986992 -0.0375301 -0.156324
outer loop
vertex 0.951057 -1.04827 -2.05735
vertex 0.951057 2.75348e-08 -2.30902
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 0.697133 -0.167367 -0.697133
outer loop
vertex 0.809017 -1.17483 -2.30573
vertex 0.587785 -1.27527 -2.50285
vertex 0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal 0.885761 -0.108352 -0.451318
outer loop
vertex 0.809017 -1.17483 -2.30573
vertex 0.809017 3.0859e-08 -2.58779
vertex 0.951057 2.75348e-08 -2.30902
endloop
endfacet
facet normal 0.443947 -0.209179 -0.871295
outer loop
vertex 0.587785 -1.27527 -2.50285
vertex 0.309017 -1.33975 -2.62941
vertex 0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal 0.697133 -0.167367 -0.697133
outer loop
vertex 0.587785 -1.27527 -2.50285
vertex 0.587785 3.34972e-08 -2.80902
vertex 0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal 0.152214 -0.230725 -0.96104
outer loop
vertex 0.309017 -1.33975 -2.62941
vertex -4.37114e-08 -1.36197 -2.67302
vertex 0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal 0.443947 -0.209179 -0.871295
outer loop
vertex 0.309017 -1.33975 -2.62941
vertex 0.309017 3.5191e-08 -2.95106
vertex 0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal -0.152214 -0.230725 -0.961039
outer loop
vertex -4.37114e-08 -1.36197 -2.67302
vertex -0.309017 -1.33975 -2.62941
vertex -4.37114e-08 3.57746e-08 -3
endloop
endfacet
facet normal 0.152214 -0.230725 -0.961039
outer loop
vertex -4.37114e-08 -1.36197 -2.67302
vertex -4.37114e-08 3.57746e-08 -3
vertex 0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal -0.443948 -0.209179 -0.871295
outer loop
vertex -0.309017 -1.33975 -2.62941
vertex -0.587785 -1.27527 -2.50285
vertex -0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal -0.152214 -0.230725 -0.961039
outer loop
vertex -0.309017 -1.33975 -2.62941
vertex -0.309017 3.5191e-08 -2.95106
vertex -4.37114e-08 3.57746e-08 -3
endloop
endfacet
facet normal -0.697132 -0.167367 -0.697133
outer loop
vertex -0.587785 -1.27527 -2.50285
vertex -0.809017 -1.17483 -2.30573
vertex -0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal -0.443947 -0.209179 -0.871295
outer loop
vertex -0.587785 -1.27527 -2.50285
vertex -0.587785 3.34972e-08 -2.80902
vertex -0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal -0.885761 -0.108352 -0.451317
outer loop
vertex -0.809017 -1.17483 -2.30573
vertex -0.951056 -1.04827 -2.05735
vertex -0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal -0.697133 -0.167367 -0.697133
outer loop
vertex -0.809017 -1.17483 -2.30573
vertex -0.809017 3.0859e-08 -2.58779
vertex -0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal -0.986993 -0.0375302 -0.156324
outer loop
vertex -0.951056 -1.04827 -2.05735
vertex -1 -0.907981 -1.78201
vertex -0.951056 2.75348e-08 -2.30902
endloop
endfacet
facet normal -0.885761 -0.108352 -0.451317
outer loop
vertex -0.951056 -1.04827 -2.05735
vertex -0.951056 2.75348e-08 -2.30902
vertex -0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal -0.986993 0.0375301 0.156324
outer loop
vertex -1 -0.907981 -1.78201
vertex -0.951057 -0.767691 -1.50668
vertex -1 2.38498e-08 -2
endloop
endfacet
facet normal -0.986992 -0.0375302 -0.156324
outer loop
vertex -1 -0.907981 -1.78201
vertex -1 2.38498e-08 -2
vertex -0.951056 2.75348e-08 -2.30902
endloop
endfacet
facet normal -0.885761 0.108352 0.451318
outer loop
vertex -0.951057 -0.767691 -1.50668
vertex -0.809017 -0.641132 -1.25829
vertex -0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal -0.986993 0.0375302 0.156324
outer loop
vertex -0.951057 -0.767691 -1.50668
vertex -0.951057 2.01648e-08 -1.69098
vertex -1 2.38498e-08 -2
endloop
endfacet
facet normal -0.697133 0.167367 0.697133
outer loop
vertex -0.809017 -0.641132 -1.25829
vertex -0.587785 -0.540695 -1.06117
vertex -0.809017 1.68405e-08 -1.41221
endloop
endfacet
facet normal -0.885761 0.108352 0.451318
outer loop
vertex -0.809017 -0.641132 -1.25829
vertex -0.809017 1.68405e-08 -1.41221
vertex -0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal -0.443947 0.209179 0.871295
outer loop
vertex -0.587785 -0.540695 -1.06117
vertex -0.309017 -0.476211 -0.934615
vertex -0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal -0.697133 0.167367 0.697133
outer loop
vertex -0.587785 -0.540695 -1.06117
vertex -0.587785 1.42023e-08 -1.19098
vertex -0.809017 1.68405e-08 -1.41221
endloop
endfacet
facet normal -0.152214 0.230725 0.961039
outer loop
vertex -0.309017 -0.476211 -0.934615
vertex 1.19249e-08 -0.453991 -0.891006
vertex -0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal -0.443947 0.20918 0.871295
outer loop
vertex -0.309017 -0.476211 -0.934615
vertex -0.309017 1.25085e-08 -1.04894
vertex -0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal 0.152214 0.230725 0.96104
outer loop
vertex 1.19249e-08 -0.453991 -0.891006
vertex 0.309017 -0.476211 -0.934615
vertex 1.19249e-08 1.19249e-08 -1
endloop
endfacet
facet normal -0.152214 0.230725 0.961039
outer loop
vertex 1.19249e-08 -0.453991 -0.891006
vertex 1.19249e-08 1.19249e-08 -1
vertex -0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal 0.443947 0.20918 0.871295
outer loop
vertex 0.309017 -0.476211 -0.934615
vertex 0.587785 -0.540695 -1.06117
vertex 0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal 0.152214 0.230725 0.961039
outer loop
vertex 0.309017 -0.476211 -0.934615
vertex 0.309017 1.25085e-08 -1.04894
vertex 1.19249e-08 1.19249e-08 -1
endloop
endfacet
facet normal 0.697133 0.167367 0.697133
outer loop
vertex 0.587785 -0.540695 -1.06117
vertex 0.809017 -0.641132 -1.25829
vertex 0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal 0.443947 0.209179 0.871295
outer loop
vertex 0.587785 -0.540695 -1.06117
vertex 0.587785 1.42023e-08 -1.19098
vertex 0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal 0.885761 0.108352 0.451318
outer loop
vertex 0.809017 -0.641132 -1.25829
vertex 0.951057 -0.767691 -1.50668
vertex 0.809017 1.68405e-08 -1.41221
endloop
endfacet
facet normal 0.697133 0.167367 0.697133
outer loop
vertex 0.809017 -0.641132 -1.25829
vertex 0.809017 1.68405e-08 -1.41221
vertex 0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal 0.986993 0.0375301 0.156324
outer loop
vertex 0.951057 -0.767691 -1.50668
vertex 1 -0.907981 -1.78201
vertex 0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal 0.885761 0.108352 0.451318
outer loop
vertex 0.951057 -0.767691 -1.50668
vertex 0.951057 2.01648e-08 -1.69098
vertex 0.809017 1.68405e-08 -1.41221
endloop
endfacet
facet normal 1.10109e-14 1 1.19249e-08
outer loop
vertex 0.951057 2.75348e-08 -2.30902
vertex 0.809017 3.0859e-08 -2.58779
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -1.2647e-14 1 1.19249e-08
outer loop
vertex 0.809017 3.0859e-08 -2.58779
vertex 0.587785 3.34972e-08 -2.80902
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 7.97873e-15 1 1.19249e-08
outer loop
vertex 0.587785 3.34972e-08 -2.80902
vertex 0.309017 3.5191e-08 -2.95106
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -8.32432e-15 1 1.19249e-08
outer loop
vertex 0.309017 3.5191e-08 -2.95106
vertex -4.37114e-08 3.57746e-08 -3
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 6.04797e-15 1 1.19249e-08
outer loop
vertex -4.37114e-08 3.57746e-08 -3
vertex -0.309017 3.5191e-08 -2.95106
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -2.95366e-15 1 1.19249e-08
outer loop
vertex -0.309017 3.5191e-08 -2.95106
vertex -0.587785 3.34972e-08 -2.80902
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 2.09378e-15 1 1.19249e-08
outer loop
vertex -0.587785 3.34972e-08 -2.80902
vertex -0.809017 3.0859e-08 -2.58779
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -7.5553e-16 1 1.19249e-08
outer loop
vertex -0.809017 3.0859e-08 -2.58779
vertex -0.951056 2.75348e-08 -2.30902
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -1.79638e-16 1 1.19249e-08
outer loop
vertex -0.951056 2.75348e-08 -2.30902
vertex -1 2.38498e-08 -2
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -1.774e-16 1 1.19249e-08
outer loop
vertex -1 2.38498e-08 -2
vertex -0.951057 2.01648e-08 -1.69098
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -1.88882e-16 1 1.19249e-08
outer loop
vertex -0.951057 2.01648e-08 -1.69098
vertex -0.809017 1.68405e-08 -1.41221
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 8.37511e-16 1 1.19249e-08
outer loop
vertex -0.809017 1.68405e-08 -1.41221
vertex -0.587785 1.42023e-08 -1.19098
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -2.46139e-16 1 1.19249e-08
outer loop
vertex -0.587785 1.42023e-08 -1.19098
vertex -0.309017 1.25085e-08 -1.04894
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 1.08553e-15 1 1.19249e-08
outer loop
vertex -0.309017 1.25085e-08 -1.04894
vertex 1.19249e-08 1.19249e-08 -1
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -1.49411e-15 1 1.19249e-08
outer loop
vertex 1.19249e-08 1.19249e-08 -1
vertex 0.309017 1.25085e-08 -1.04894
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 0 1 1.19249e-08
outer loop
vertex 0.309017 1.25085e-08 -1.04894
vertex 0.587785 1.42023e-08 -1.19098
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 7.58822e-15 1 1.19249e-08
outer loop
vertex 0.587785 1.42023e-08 -1.19098
vertex 0.809017 1.68405e-08 -1.41221
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal -1.46812e-14 1 1.19249e-08
outer loop
vertex 0.809017 1.68405e-08 -1.41221
vertex 0.951057 2.01648e-08 -1.69098
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 0.940447 0.148952 -0.30557
outer loop
vertex 11 2 0
vertex 8.89919 2 -6.46564
vertex 10.9511 2.30902 0
endloop
endfacet
facet normal 0.940447 -0.148954 -0.30557
outer loop
vertex 11 2 0
vertex 8.85959 1.69098 -6.43687
vertex 8.89919 2 -6.46564
endloop
endfacet
facet normal 0.940447 0.148953 -0.30557
outer loop
vertex 10.9511 2.30902 0
vertex 8.89919 2 -6.46564
vertex 8.85959 2.30902 -6.43687
endloop
endfacet
facet normal 0.855862 0.436083 -0.278086
outer loop
vertex 10.9511 2.30902 0
vertex 8.85959 2.30902 -6.43687
vertex 10.809 2.58779 0
endloop
endfacet
facet normal 0.855862 0.436083 -0.278086
outer loop
vertex 10.809 2.58779 0
vertex 8.85959 2.30902 -6.43687
vertex 8.74468 2.58779 -6.35338
endloop
endfacet
facet normal 0.689152 0.689151 -0.223919
outer loop
vertex 10.809 2.58779 0
vertex 8.74468 2.58779 -6.35338
vertex 10.5878 2.80902 0
endloop
endfacet
facet normal 0.689153 0.689151 -0.223919
outer loop
vertex 10.5878 2.80902 0
vertex 8.74468 2.58779 -6.35338
vertex 8.5657 2.80902 -6.22334
endloop
endfacet
facet normal 0.44913 0.881468 -0.145931
outer loop
vertex 10.5878 2.80902 0
vertex 8.5657 2.80902 -6.22334
vertex 10.309 2.95106 0
endloop
endfacet
facet normal 0.44913 0.881468 -0.145931
outer loop
vertex 10.309 2.95106 0
vertex 8.5657 2.80902 -6.22334
vertex 8.34017 2.95106 -6.05949
endloop
endfacet
facet normal 0.156233 0.986415 -0.0507631
outer loop
vertex 10.309 2.95106 0
vertex 8.34017 2.95106 -6.05949
vertex 10 3 0
endloop
endfacet
facet normal 0.156233 0.986415 -0.0507631
outer loop
vertex 10 3 0
vertex 8.34017 2.95106 -6.05949
vertex 8.09017 3 -5.87785
endloop
endfacet
facet normal -0.156233 0.986415 0.0507631
outer loop
vertex 10 3 0
vertex 8.09017 3 -5.87785
vertex 9.69098 2.95106 0
endloop
endfacet
facet normal -0.156233 0.986415 0.0507631
outer loop
vertex 9.69098 2.95106 0
vertex 8.09017 3 -5.87785
vertex 7.84017 2.95106 -5.69622
endloop
endfacet
facet normal -0.449131 0.881468 0.145932
outer loop
vertex 9.69098 2.95106 0
vertex 7.84017 2.95106 -5.69622
vertex 9.41222 2.80902 0
endloop
endfacet
facet normal -0.449131 0.881468 0.145932
outer loop
vertex 9.41222 2.80902 0
vertex 7.84017 2.95106 -5.69622
vertex 7.61464 2.80902 -5.53236
endloop
endfacet
facet normal -0.689151 0.689153 0.223919
outer loop
vertex 9.41222 2.80902 0
vertex 7.61464 2.80902 -5.53236
vertex 9.19098 2.58779 0
endloop
endfacet
facet normal -0.689151 0.689153 0.223919
outer loop
vertex 9.19098 2.58779 0
vertex 7.61464 2.80902 -5.53236
vertex 7.43566 2.58779 -5.40232
endloop
endfacet
facet normal -0.855862 0.436083 0.278086
outer loop
vertex 9.19098 2.58779 0
vertex 7.43566 2.58779 -5.40232
vertex 9.04894 2.30902 0
endloop
endfacet
facet normal -0.855862 0.436083 0.278086
outer loop
vertex 9.04894 2.30902 0
vertex 7.43566 2.58779 -5.40232
vertex 7.32075 2.30902 -5.31884
endloop
endfacet
facet normal -0.940447 0.148952 0.30557
outer loop
vertex 9.04894 2.30902 0
vertex 7.32075 2.30902 -5.31884
vertex 9 2 0
endloop
endfacet
facet normal -0.940447 0.148952 0.30557
outer loop
vertex 9 2 0
vertex 7.32075 2.30902 -5.31884
vertex 7.28115 2 -5.29007
endloop
endfacet
facet normal -0.940447 -0.148952 0.30557
outer loop
vertex 9 2 0
vertex 7.28115 2 -5.29007
vertex 9.04894 1.69098 0
endloop
endfacet
facet normal -0.940447 -0.148952 0.30557
outer loop
vertex 9.04894 1.69098 0
vertex 7.28115 2 -5.29007
vertex 7.32075 1.69098 -5.31884
endloop
endfacet
facet normal -0.855862 -0.436083 0.278086
outer loop
vertex 9.04894 1.69098 0
vertex 7.32075 1.69098 -5.31884
vertex 9.19098 1.41221 0
endloop
endfacet
facet normal -0.855862 -0.436083 0.278086
outer loop
vertex 9.19098 1.41221 0
vertex 7.32075 1.69098 -5.31884
vertex 7.43566 1.41221 -5.40232
endloop
endfacet
facet normal -0.689151 -0.689153 0.223919
outer loop
vertex 9.19098 1.41221 0
vertex 7.43566 1.41221 -5.40232
vertex 9.41222 1.19098 0
endloop
endfacet
facet normal -0.689151 -0.689153 0.223919
outer loop
vertex 9.41222 1.19098 0
vertex 7.43566 1.41221 -5.40232
vertex 7.61464 1.19098 -5.53236
endloop
endfacet
facet normal -0.449131 -0.881468 0.145931
outer loop
vertex 9.41222 1.19098 0
vertex 7.61464 1.19098 -5.53236
vertex 9.69098 1.04894 0
endloop
endfacet
facet normal -0.449131 -0.881468 0.145931
outer loop
vertex 9.69098 1.04894 0
vertex 7.61464 1.19098 -5.53236
vertex 7.84017 1.04894 -5.69622
endloop
endfacet
facet normal -0.156233 -0.986415 0.0507631
outer loop
vertex 9.69098 1.04894 0
vertex 7.84017 1.04894 -5.69622
vertex 10 1 0
endloop
endfacet
facet normal -0.156233 -0.986415 0.0507631
outer loop
vertex 10 1 0
vertex 7.84017 1.04894 -5.69622
vertex 8.09017 1 -5.87785
endloop
endfacet
facet normal 0.156233 -0.986415 -0.0507631
outer loop
vertex 10 1 0
vertex 8.09017 1 -5.87785
vertex 10.309 1.04894 0
endloop
endfacet
facet normal 0.156233 -0.986415 -0.0507631
outer loop
vertex 10.309 1.04894 0
vertex 8.09017 1 -5.87785
vertex 8.34017 1.04894 -6.05949
endloop
endfacet
facet normal 0.449131 -0.881468 -0.145931
outer loop
vertex 10.309 1.04894 0
vertex 8.34017 1.04894 -6.05949
vertex 10.5878 1.19098 0
endloop
endfacet
facet normal 0.449131 -0.881468 -0.145931
outer loop
vertex 10.5878 1.19098 0
vertex 8.34017 1.04894 -6.05949
vertex 8.5657 1.19098 -6.22334
endloop
endfacet
facet normal 0.689151 -0.689153 -0.223919
outer loop
vertex 10.5878 1.19098 0
vertex 8.5657 1.19098 -6.22334
vertex 10.809 1.41221 0
endloop
endfacet
facet normal 0.689151 -0.689152 -0.223919
outer loop
vertex 10.809 1.41221 0
vertex 8.5657 1.19098 -6.22334
vertex 8.74468 1.41221 -6.35338
endloop
endfacet
facet normal 0.855862 -0.436083 -0.278086
outer loop
vertex 10.809 1.41221 0
vertex 8.74468 1.41221 -6.35338
vertex 10.9511 1.69098 0
endloop
endfacet
facet normal 0.855862 -0.436083 -0.278086
outer loop
vertex 10.9511 1.69098 0
vertex 8.74468 1.41221 -6.35338
vertex 8.85959 1.69098 -6.43687
endloop
endfacet
facet normal 0.940447 -0.148952 -0.30557
outer loop
vertex 10.9511 1.69098 0
vertex 8.85959 1.69098 -6.43687
vertex 11 2 0
endloop
endfacet
facet normal 0.581228 0.148953 -0.799992
outer loop
vertex 8.89919 2 -6.46564
vertex 3.39919 2 -10.4616
vertex 8.85959 2.30902 -6.43687
endloop
endfacet
facet normal 0.581228 -0.148952 -0.799992
outer loop
vertex 8.89919 2 -6.46564
vertex 3.38406 1.69098 -10.4151
vertex 3.39919 2 -10.4616
endloop
endfacet
facet normal 0.581228 0.148952 -0.799992
outer loop
vertex 8.85959 2.30902 -6.43687
vertex 3.39919 2 -10.4616
vertex 3.38406 2.30902 -10.4151
endloop
endfacet
facet normal 0.528952 0.436083 -0.72804
outer loop
vertex 8.85959 2.30902 -6.43687
vertex 3.38406 2.30902 -10.4151
vertex 8.74468 2.58779 -6.35338
endloop
endfacet
facet normal 0.528952 0.436083 -0.728039
outer loop
vertex 8.74468 2.58779 -6.35338
vertex 3.38406 2.30902 -10.4151
vertex 3.34017 2.58779 -10.28
endloop
endfacet
facet normal 0.42592 0.689151 -0.586228
outer loop
vertex 8.74468 2.58779 -6.35338
vertex 3.34017 2.58779 -10.28
vertex 8.5657 2.80902 -6.22334
endloop
endfacet
facet normal 0.42592 0.689151 -0.586228
outer loop
vertex 8.5657 2.80902 -6.22334
vertex 3.34017 2.58779 -10.28
vertex 3.27181 2.80902 -10.0696
endloop
endfacet
facet normal 0.277578 0.881468 -0.382053
outer loop
vertex 8.5657 2.80902 -6.22334
vertex 3.27181 2.80902 -10.0696
vertex 8.34017 2.95106 -6.05949
endloop
endfacet
facet normal 0.277578 0.881468 -0.382053
outer loop
vertex 8.34017 2.95106 -6.05949
vertex 3.27181 2.80902 -10.0696
vertex 3.18566 2.95106 -9.80446
endloop
endfacet
facet normal 0.0965572 0.986415 -0.1329
outer loop
vertex 8.34017 2.95106 -6.05949
vertex 3.18566 2.95106 -9.80446
vertex 8.09017 3 -5.87785
endloop
endfacet
facet normal 0.0965572 0.986415 -0.1329
outer loop
vertex 8.09017 3 -5.87785
vertex 3.18566 2.95106 -9.80446
vertex 3.09017 3 -9.51057
endloop
endfacet
facet normal -0.0965572 0.986415 0.1329
outer loop
vertex 8.09017 3 -5.87785
vertex 3.09017 3 -9.51057
vertex 7.84017 2.95106 -5.69622
endloop
endfacet
facet normal -0.0965572 0.986415 0.1329
outer loop
vertex 7.84017 2.95106 -5.69622
vertex 3.09017 3 -9.51057
vertex 2.99468 2.95106 -9.21667
endloop
endfacet
facet normal -0.277578 0.881468 0.382054
outer loop
vertex 7.84017 2.95106 -5.69622
vertex 2.99468 2.95106 -9.21667
vertex 7.61464 2.80902 -5.53236
endloop
endfacet
facet normal -0.277578 0.881468 0.382053
outer loop
vertex 7.61464 2.80902 -5.53236
vertex 2.99468 2.95106 -9.21667
vertex 2.90853 2.80902 -8.95155
endloop
endfacet
facet normal -0.425919 0.689152 0.586227
outer loop
vertex 7.61464 2.80902 -5.53236
vertex 2.90853 2.80902 -8.95155
vertex 7.43566 2.58779 -5.40232
endloop
endfacet
facet normal -0.425919 0.689152 0.586227
outer loop
vertex 7.43566 2.58779 -5.40232
vertex 2.90853 2.80902 -8.95155
vertex 2.84017 2.58779 -8.74114
endloop
endfacet
facet normal -0.528952 0.436083 0.72804
outer loop
vertex 7.43566 2.58779 -5.40232
vertex 2.84017 2.58779 -8.74114
vertex 7.32075 2.30902 -5.31884
endloop
endfacet
facet normal -0.528952 0.436082 0.72804
outer loop
vertex 7.32075 2.30902 -5.31884
vertex 2.84017 2.58779 -8.74114
vertex 2.79628 2.30902 -8.60606
endloop
endfacet
facet normal -0.581228 0.148952 0.799992
outer loop
vertex 7.32075 2.30902 -5.31884
vertex 2.79628 2.30902 -8.60606
vertex 7.28115 2 -5.29007
endloop
endfacet
facet normal -0.581228 0.148951 0.799992
outer loop
vertex 7.28115 2 -5.29007
vertex 2.79628 2.30902 -8.60606
vertex 2.78115 2 -8.55951
endloop
endfacet
facet normal -0.581228 -0.148952 0.799992
outer loop
vertex 7.28115 2 -5.29007
vertex 2.78115 2 -8.55951
vertex 7.32075 1.69098 -5.31884
endloop
endfacet
facet normal -0.581228 -0.148952 0.799992
outer loop
vertex 7.32075 1.69098 -5.31884
vertex 2.78115 2 -8.55951
vertex 2.79628 1.69098 -8.60606
endloop
endfacet
facet normal -0.528952 -0.436083 0.72804
outer loop
vertex 7.32075 1.69098 -5.31884
vertex 2.79628 1.69098 -8.60606
vertex 7.43566 1.41221 -5.40232
endloop
endfacet
facet normal -0.528952 -0.436082 0.72804
outer loop
vertex 7.43566 1.41221 -5.40232
vertex 2.79628 1.69098 -8.60606
vertex 2.84017 1.41221 -8.74114
endloop
endfacet
facet normal -0.425919 -0.689152 0.586227
outer loop
vertex 7.43566 1.41221 -5.40232
vertex 2.84017 1.41221 -8.74114
vertex 7.61464 1.19098 -5.53236
endloop
endfacet
facet normal -0.425919 -0.689152 0.586227
outer loop
vertex 7.61464 1.19098 -5.53236
vertex 2.84017 1.41221 -8.74114
vertex 2.90853 1.19098 -8.95155
endloop
endfacet
facet normal -0.277578 -0.881468 0.382053
outer loop
vertex 7.61464 1.19098 -5.53236
vertex 2.90853 1.19098 -8.95155
vertex 7.84017 1.04894 -5.69622
endloop
endfacet
facet normal -0.277578 -0.881468 0.382053
outer loop
vertex 7.84017 1.04894 -5.69622
vertex 2.90853 1.19098 -8.95155
vertex 2.99468 1.04894 -9.21667
endloop
endfacet
facet normal -0.0965572 -0.986415 0.1329
outer loop
vertex 7.84017 1.04894 -5.69622
vertex 2.99468 1.04894 -9.21667
vertex 8.09017 1 -5.87785
endloop
endfacet
facet normal -0.0965572 -0.986415 0.1329
outer loop
vertex 8.09017 1 -5.87785
vertex 2.99468 1.04894 -9.21667
vertex 3.09017 1 -9.51057
endloop
endfacet
facet normal 0.0965572 -0.986415 -0.1329
outer loop
vertex 8.09017 1 -5.87785
vertex 3.09017 1 -9.51057
vertex 8.34017 1.04894 -6.05949
endloop
endfacet
facet normal 0.0965572 -0.986415 -0.1329
outer loop
vertex 8.34017 1.04894 -6.05949
vertex 3.09017 1 -9.51057
vertex 3.18566 1.04894 -9.80446
endloop
endfacet
facet normal 0.277578 -0.881468 -0.382053
outer loop
vertex 8.34017 1.04894 -6.05949
vertex 3.18566 1.04894 -9.80446
vertex 8.5657 1.19098 -6.22334
endloop
endfacet
facet normal 0.277578 -0.881468 -0.382054
outer loop
vertex 8.5657 1.19098 -6.22334
vertex 3.18566 1.04894 -9.80446
vertex 3.27181 1.19098 -10.0696
endloop
endfacet
facet normal 0.425919 -0.689152 -0.586227
outer loop
vertex 8.5657 1.19098 -6.22334
vertex 3.27181 1.19098 -10.0696
vertex 8.74468 1.41221 -6.35338
endloop
endfacet
facet normal 0.425919 -0.689152 -0.586227
outer loop
vertex 8.74468 1.41221 -6.35338
vertex 3.27181 1.19098 -10.0696
vertex 3.34017 1.41221 -10.28
endloop
endfacet
facet normal 0.528952 -0.436083 -0.728039
outer loop
vertex 8.74468 1.41221 -6.35338
vertex 3.34017 1.41221 -10.28
vertex 8.85959 1.69098 -6.43687
endloop
endfacet
facet normal 0.528952 -0.436084 -0.728039
outer loop
vertex 8.85959 1.69098 -6.43687
vertex 3.34017 1.41221 -10.28
vertex 3.38406 1.69098 -10.4151
endloop
endfacet
facet normal 0.581228 -0.148953 -0.799992
outer loop
vertex 8.85959 1.69098 -6.43687
vertex 3.38406 1.69098 -10.4151
vertex 8.89919 2 -6.46564
endloop
endfacet
facet normal -1.38715e-07 0.148952 -0.988845
outer loop
vertex 3.39919 2 -10.4616
vertex -3.39919 2 -10.4616
vertex 3.38406 2.30902 -10.4151
endloop
endfacet
facet normal -1.38715e-07 -0.148952 -0.988845
outer loop
vertex 3.39919 2 -10.4616
vertex -3.38406 1.69098 -10.4151
vertex -3.39919 2 -10.4616
endloop
endfacet
facet normal -1.39335e-07 0.148952 -0.988844
outer loop
vertex 3.38406 2.30902 -10.4151
vertex -3.39919 2 -10.4616
vertex -3.38406 2.30902 -10.4151
endloop
endfacet
facet normal -1.26803e-07 0.436084 -0.899906
outer loop
vertex 3.38406 2.30902 -10.4151
vertex -3.38406 2.30902 -10.4151
vertex 3.34017 2.58779 -10.28
endloop
endfacet
facet normal -1.28469e-07 0.436084 -0.899906
outer loop
vertex 3.34017 2.58779 -10.28
vertex -3.38406 2.30902 -10.4151
vertex -3.34017 2.58779 -10.28
endloop
endfacet
facet normal -1.03445e-07 0.689151 -0.724618
outer loop
vertex 3.34017 2.58779 -10.28
vertex -3.34017 2.58779 -10.28
vertex 3.27181 2.80902 -10.0696
endloop
endfacet
facet normal -1.05607e-07 0.689151 -0.724618
outer loop
vertex 3.27181 2.80902 -10.0696
vertex -3.34017 2.58779 -10.28
vertex -3.27181 2.80902 -10.0696
endloop
endfacet
facet normal -6.88254e-08 0.881468 -0.472244
outer loop
vertex 3.27181 2.80902 -10.0696
vertex -3.27181 2.80902 -10.0696
vertex 3.18566 2.95106 -9.80446
endloop
endfacet
facet normal -7.06865e-08 0.881468 -0.472244
outer loop
vertex 3.18566 2.95106 -9.80446
vertex -3.27181 2.80902 -10.0696
vertex -3.18566 2.95106 -9.80446
endloop
endfacet
facet normal -2.45887e-08 0.986415 -0.164273
outer loop
vertex 3.18566 2.95106 -9.80446
vertex -3.18566 2.95106 -9.80446
vertex 3.09017 3 -9.51057
endloop
endfacet
facet normal -2.53486e-08 0.986415 -0.164273
outer loop
vertex 3.09017 3 -9.51057
vertex -3.18566 2.95106 -9.80446
vertex -3.09017 3 -9.51056
endloop
endfacet
facet normal 2.53486e-08 0.986415 0.164273
outer loop
vertex 3.09017 3 -9.51057
vertex -3.09017 3 -9.51056
vertex 2.99468 2.95106 -9.21667
endloop
endfacet
facet normal 2.61569e-08 0.986415 0.164273
outer loop
vertex 2.99468 2.95106 -9.21667
vertex -3.09017 3 -9.51056
vertex -2.99468 2.95106 -9.21667
endloop
endfacet
facet normal 7.51945e-08 0.881468 0.472244
outer loop
vertex 2.99468 2.95106 -9.21667
vertex -2.99468 2.95106 -9.21667
vertex 2.90853 2.80902 -8.95155
endloop
endfacet
facet normal 0 0.881467 0.472245
outer loop
vertex 2.90853 2.80902 -8.95155
vertex -2.99468 2.95106 -9.21667
vertex -2.90853 2.80902 -8.95155
endloop
endfacet
facet normal 0 0.689153 0.724616
outer loop
vertex 2.90853 2.80902 -8.95155
vertex -2.90853 2.80902 -8.95155
vertex 2.84017 2.58779 -8.74114
endloop
endfacet
facet normal 0 0.689153 0.724616
outer loop
vertex 2.84017 2.58779 -8.74114
vertex -2.90853 2.80902 -8.95155
vertex -2.84017 2.58779 -8.74114
endloop
endfacet
facet normal 0 0.436082 0.899907
outer loop
vertex 2.84017 2.58779 -8.74114
vertex -2.84017 2.58779 -8.74114
vertex 2.79628 2.30902 -8.60606
endloop
endfacet
facet normal 1.53457e-07 0.436084 0.899906
outer loop
vertex 2.79628 2.30902 -8.60606
vertex -2.84017 2.58779 -8.74114
vertex -2.79628 2.30902 -8.60606
endloop
endfacet
facet normal 1.68623e-07 0.148952 0.988844
outer loop
vertex 2.79628 2.30902 -8.60606
vertex -2.79628 2.30902 -8.60606
vertex 2.78115 2 -8.55951
endloop
endfacet
facet normal 1.6954e-07 0.148952 0.988844
outer loop
vertex 2.78115 2 -8.55951
vertex -2.79628 2.30902 -8.60606
vertex -2.78115 2 -8.55951
endloop
endfacet
facet normal 1.6954e-07 -0.148952 0.988844
outer loop
vertex 2.78115 2 -8.55951
vertex -2.78115 2 -8.55951
vertex 2.79628 1.69098 -8.60606
endloop
endfacet
facet normal 1.68623e-07 -0.148952 0.988845
outer loop
vertex 2.79628 1.69098 -8.60606
vertex -2.78115 2 -8.55951
vertex -2.79628 1.69098 -8.60606
endloop
endfacet
facet normal 1.53457e-07 -0.436082 0.899907
outer loop
vertex 2.79628 1.69098 -8.60606
vertex -2.79628 1.69098 -8.60606
vertex 2.84017 1.41221 -8.74114
endloop
endfacet
facet normal 0 -0.436084 0.899906
outer loop
vertex 2.84017 1.41221 -8.74114
vertex -2.79628 1.69098 -8.60606
vertex -2.84017 1.41221 -8.74114
endloop
endfacet
facet normal 0 -0.689153 0.724616
outer loop
vertex 2.84017 1.41221 -8.74114
vertex -2.84017 1.41221 -8.74114
vertex 2.90853 1.19098 -8.95155
endloop
endfacet
facet normal 0 -0.689153 0.724616
outer loop
vertex 2.90853 1.19098 -8.95155
vertex -2.84017 1.41221 -8.74114
vertex -2.90853 1.19098 -8.95155
endloop
endfacet
facet normal 0 -0.881468 0.472243
outer loop
vertex 2.90853 1.19098 -8.95155
vertex -2.90853 1.19098 -8.95155
vertex 2.99468 1.04894 -9.21667
endloop
endfacet
facet normal 7.51946e-08 -0.881468 0.472244
outer loop
vertex 2.99468 1.04894 -9.21667
vertex -2.90853 1.19098 -8.95155
vertex -2.99468 1.04894 -9.21667
endloop
endfacet
facet normal 2.61569e-08 -0.986415 0.164273
outer loop
vertex 2.99468 1.04894 -9.21667
vertex -2.99468 1.04894 -9.21667
vertex 3.09017 1 -9.51057
endloop
endfacet
facet normal 2.53486e-08 -0.986415 0.164273
outer loop
vertex 3.09017 1 -9.51057
vertex -2.99468 1.04894 -9.21667
vertex -3.09017 1 -9.51056
endloop
endfacet
facet normal -2.53486e-08 -0.986415 -0.164273
outer loop
vertex 3.09017 1 -9.51057
vertex -3.09017 1 -9.51056
vertex 3.18566 1.04894 -9.80446
endloop
endfacet
facet normal -2.45887e-08 -0.986415 -0.164273
outer loop
vertex 3.18566 1.04894 -9.80446
vertex -3.09017 1 -9.51056
vertex -3.18566 1.04894 -9.80446
endloop
endfacet
facet normal -7.06866e-08 -0.881468 -0.472244
outer loop
vertex 3.18566 1.04894 -9.80446
vertex -3.18566 1.04894 -9.80446
vertex 3.27181 1.19098 -10.0696
endloop
endfacet
facet normal -6.88255e-08 -0.881468 -0.472244
outer loop
vertex 3.27181 1.19098 -10.0696
vertex -3.18566 1.04894 -9.80446
vertex -3.27181 1.19098 -10.0696
endloop
endfacet
facet normal -1.05607e-07 -0.689152 -0.724616
outer loop
vertex 3.27181 1.19098 -10.0696
vertex -3.27181 1.19098 -10.0696
vertex 3.34017 1.41221 -10.28
endloop
endfacet
facet normal -1.03445e-07 -0.689152 -0.724616
outer loop
vertex 3.34017 1.41221 -10.28
vertex -3.27181 1.19098 -10.0696
vertex -3.34017 1.41221 -10.28
endloop
endfacet
facet normal -1.28469e-07 -0.436084 -0.899906
outer loop
vertex 3.34017 1.41221 -10.28
vertex -3.34017 1.41221 -10.28
vertex 3.38406 1.69098 -10.4151
endloop
endfacet
facet normal -1.26803e-07 -0.436084 -0.899906
outer loop
vertex 3.38406 1.69098 -10.4151
vertex -3.34017 1.41221 -10.28
vertex -3.38406 1.69098 -10.4151
endloop
endfacet
facet normal -1.39335e-07 -0.148952 -0.988844
outer loop
vertex 3.38406 1.69098 -10.4151
vertex -3.38406 1.69098 -10.4151
vertex 3.39919 2 -10.4616
endloop
endfacet
facet normal -0.581228 0.148952 -0.799992
outer loop
vertex -3.39919 2 -10.4616
vertex -8.89919 2 -6.46564
vertex -3.38406 2.30902 -10.4151
endloop
endfacet
facet normal -0.581228 -0.148954 -0.799992
outer loop
vertex -3.39919 2 -10.4616
vertex -8.85959 1.69098 -6.43687
vertex -8.89919 2 -6.46564
endloop
endfacet
facet normal -0.581228 0.148954 -0.799992
outer loop
vertex -3.38406 2.30902 -10.4151
vertex -8.89919 2 -6.46564
vertex -8.85959 2.30902 -6.43687
endloop
endfacet
facet normal -0.528951 0.436084 -0.728039
outer loop
vertex -3.38406 2.30902 -10.4151
vertex -8.85959 2.30902 -6.43687
vertex -3.34017 2.58779 -10.28
endloop
endfacet
facet normal -0.528952 0.436083 -0.72804
outer loop
vertex -3.34017 2.58779 -10.28
vertex -8.85959 2.30902 -6.43687
vertex -8.74468 2.58779 -6.35338
endloop
endfacet
facet normal -0.42592 0.689151 -0.586228
outer loop
vertex -3.34017 2.58779 -10.28
vertex -8.74468 2.58779 -6.35338
vertex -3.27181 2.80902 -10.0696
endloop
endfacet
facet normal -0.425919 0.689152 -0.586228
outer loop
vertex -3.27181 2.80902 -10.0696
vertex -8.74468 2.58779 -6.35338
vertex -8.5657 2.80902 -6.22334
endloop
endfacet
facet normal -0.277578 0.881468 -0.382053
outer loop
vertex -3.27181 2.80902 -10.0696
vertex -8.5657 2.80902 -6.22334
vertex -3.18566 2.95106 -9.80446
endloop
endfacet
facet normal -0.277577 0.881468 -0.382052
outer loop
vertex -3.18566 2.95106 -9.80446
vertex -8.5657 2.80902 -6.22334
vertex -8.34017 2.95106 -6.05949
endloop
endfacet
facet normal -0.0965572 0.986415 -0.1329
outer loop
vertex -3.18566 2.95106 -9.80446
vertex -8.34017 2.95106 -6.05949
vertex -3.09017 3 -9.51056
endloop
endfacet
facet normal -0.0965572 0.986415 -0.1329
outer loop
vertex -3.09017 3 -9.51056
vertex -8.34017 2.95106 -6.05949
vertex -8.09017 3 -5.87785
endloop
endfacet
facet normal 0.0965571 0.986415 0.1329
outer loop
vertex -3.09017 3 -9.51056
vertex -8.09017 3 -5.87785
vertex -2.99468 2.95106 -9.21667
endloop
endfacet
facet normal 0.096557 0.986415 0.132899
outer loop
vertex -2.99468 2.95106 -9.21667
vertex -8.09017 3 -5.87785
vertex -7.84017 2.95106 -5.69622
endloop
endfacet
facet normal 0.277579 0.881467 0.382054
outer loop
vertex -2.99468 2.95106 -9.21667
vertex -7.84017 2.95106 -5.69622
vertex -2.90853 2.80902 -8.95155
endloop
endfacet
facet normal 0.277578 0.881468 0.382054
outer loop
vertex -2.90853 2.80902 -8.95155
vertex -7.84017 2.95106 -5.69622
vertex -7.61464 2.80902 -5.53236
endloop
endfacet
facet normal 0.425919 0.689153 0.586227
outer loop
vertex -2.90853 2.80902 -8.95155
vertex -7.61464 2.80902 -5.53236
vertex -2.84017 2.58779 -8.74114
endloop
endfacet
facet normal 0.425919 0.689153 0.586227
outer loop
vertex -2.84017 2.58779 -8.74114
vertex -7.61464 2.80902 -5.53236
vertex -7.43566 2.58779 -5.40232
endloop
endfacet
facet normal 0.528952 0.436084 0.728039
outer loop
vertex -2.84017 2.58779 -8.74114
vertex -7.43566 2.58779 -5.40232
vertex -2.79628 2.30902 -8.60606
endloop
endfacet
facet normal 0.528952 0.436084 0.728039
outer loop
vertex -2.79628 2.30902 -8.60606
vertex -7.43566 2.58779 -5.40232
vertex -7.32075 2.30902 -5.31883
endloop
endfacet
facet normal 0.581228 0.148952 0.799992
outer loop
vertex -2.79628 2.30902 -8.60606
vertex -7.32075 2.30902 -5.31883
vertex -2.78115 2 -8.55951
endloop
endfacet
facet normal 0.581228 0.148951 0.799992
outer loop
vertex -2.78115 2 -8.55951
vertex -7.32075 2.30902 -5.31883
vertex -7.28115 2 -5.29007
endloop
endfacet
facet normal 0.581228 -0.148952 0.799992
outer loop
vertex -2.78115 2 -8.55951
vertex -7.28115 2 -5.29007
vertex -2.79628 1.69098 -8.60606
endloop
endfacet
facet normal 0.581228 -0.148952 0.799992
outer loop
vertex -2.79628 1.69098 -8.60606
vertex -7.28115 2 -5.29007
vertex -7.32075 1.69098 -5.31883
endloop
endfacet
facet normal 0.528952 -0.436083 0.728039
outer loop
vertex -2.79628 1.69098 -8.60606
vertex -7.32075 1.69098 -5.31883
vertex -2.84017 1.41221 -8.74114
endloop
endfacet
facet normal 0.528952 -0.436083 0.728039
outer loop
vertex -2.84017 1.41221 -8.74114
vertex -7.32075 1.69098 -5.31883
vertex -7.43566 1.41221 -5.40232
endloop
endfacet
facet normal 0.425919 -0.689153 0.586227
outer loop
vertex -2.84017 1.41221 -8.74114
vertex -7.43566 1.41221 -5.40232
vertex -2.90853 1.19098 -8.95155
endloop
endfacet
facet normal 0.425919 -0.689152 0.586227
outer loop
vertex -2.90853 1.19098 -8.95155
vertex -7.43566 1.41221 -5.40232
vertex -7.61464 1.19098 -5.53236
endloop
endfacet
facet normal 0.277578 -0.881468 0.382054
outer loop
vertex -2.90853 1.19098 -8.95155
vertex -7.61464 1.19098 -5.53236
vertex -2.99468 1.04894 -9.21667
endloop
endfacet
facet normal 0.277578 -0.881468 0.382053
outer loop
vertex -2.99468 1.04894 -9.21667
vertex -7.61464 1.19098 -5.53236
vertex -7.84017 1.04894 -5.69622
endloop
endfacet
facet normal 0.0965572 -0.986415 0.1329
outer loop
vertex -2.99468 1.04894 -9.21667
vertex -7.84017 1.04894 -5.69622
vertex -3.09017 1 -9.51056
endloop
endfacet
facet normal 0.0965571 -0.986415 0.132899
outer loop
vertex -3.09017 1 -9.51056
vertex -7.84017 1.04894 -5.69622
vertex -8.09017 1 -5.87785
endloop
endfacet
facet normal -0.0965572 -0.986415 -0.1329
outer loop
vertex -3.09017 1 -9.51056
vertex -8.09017 1 -5.87785
vertex -3.18566 1.04894 -9.80446
endloop
endfacet
facet normal -0.0965573 -0.986415 -0.1329
outer loop
vertex -3.18566 1.04894 -9.80446
vertex -8.09017 1 -5.87785
vertex -8.34017 1.04894 -6.05949
endloop
endfacet
facet normal -0.277578 -0.881468 -0.382054
outer loop
vertex -3.18566 1.04894 -9.80446
vertex -8.34017 1.04894 -6.05949
vertex -3.27181 1.19098 -10.0696
endloop
endfacet
facet normal -0.277578 -0.881468 -0.382053
outer loop
vertex -3.27181 1.19098 -10.0696
vertex -8.34017 1.04894 -6.05949
vertex -8.5657 1.19098 -6.22334
endloop
endfacet
facet normal -0.425919 -0.689152 -0.586227
outer loop
vertex -3.27181 1.19098 -10.0696
vertex -8.5657 1.19098 -6.22334
vertex -3.34017 1.41221 -10.28
endloop
endfacet
facet normal -0.425919 -0.689153 -0.586227
outer loop
vertex -3.34017 1.41221 -10.28
vertex -8.5657 1.19098 -6.22334
vertex -8.74468 1.41221 -6.35338
endloop
endfacet
facet normal -0.528951 -0.436084 -0.728039
outer loop
vertex -3.34017 1.41221 -10.28
vertex -8.74468 1.41221 -6.35338
vertex -3.38406 1.69098 -10.4151
endloop
endfacet
facet normal -0.528952 -0.436082 -0.72804
outer loop
vertex -3.38406 1.69098 -10.4151
vertex -8.74468 1.41221 -6.35338
vertex -8.85959 1.69098 -6.43687
endloop
endfacet
facet normal -0.581228 -0.148952 -0.799992
outer loop
vertex -3.38406 1.69098 -10.4151
vertex -8.85959 1.69098 -6.43687
vertex -3.39919 2 -10.4616
endloop
endfacet
facet normal -0.940447 0.148954 -0.305569
outer loop
vertex -8.89919 2 -6.46564
vertex -11 2 9.61651e-07
vertex -8.85959 2.30902 -6.43687
endloop
endfacet
facet normal -0.940447 -0.148952 -0.30557
outer loop
vertex -8.89919 2 -6.46564
vertex -10.9511 1.69098 9.57372e-07
vertex -11 2 9.61651e-07
endloop
endfacet
facet normal -0.940447 0.148952 -0.30557
outer loop
vertex -8.85959 2.30902 -6.43687
vertex -11 2 9.61651e-07
vertex -10.9511 2.30902 9.57372e-07
endloop
endfacet
facet normal -0.855862 0.436082 -0.278086
outer loop
vertex -8.85959 2.30902 -6.43687
vertex -10.9511 2.30902 9.57372e-07
vertex -8.74468 2.58779 -6.35338
endloop
endfacet
facet normal -0.855862 0.436083 -0.278086
outer loop
vertex -8.74468 2.58779 -6.35338
vertex -10.9511 2.30902 9.57372e-07
vertex -10.809 2.58779 9.44954e-07
endloop
endfacet
facet normal -0.689152 0.689151 -0.223919
outer loop
vertex -8.74468 2.58779 -6.35338
vertex -10.809 2.58779 9.44954e-07
vertex -8.5657 2.80902 -6.22334
endloop
endfacet
facet normal -0.689152 0.689151 -0.223919
outer loop
vertex -8.5657 2.80902 -6.22334
vertex -10.809 2.58779 9.44954e-07
vertex -10.5878 2.80902 9.25614e-07
endloop
endfacet
facet normal -0.44913 0.881468 -0.145931
outer loop
vertex -8.5657 2.80902 -6.22334
vertex -10.5878 2.80902 9.25614e-07
vertex -8.34017 2.95106 -6.05949
endloop
endfacet
facet normal -0.44913 0.881468 -0.145931
outer loop
vertex -8.34017 2.95106 -6.05949
vertex -10.5878 2.80902 9.25614e-07
vertex -10.309 2.95106 9.01243e-07
endloop
endfacet
facet normal -0.156233 0.986415 -0.0507631
outer loop
vertex -8.34017 2.95106 -6.05949
vertex -10.309 2.95106 9.01243e-07
vertex -8.09017 3 -5.87785
endloop
endfacet
facet normal -0.156233 0.986415 -0.0507631
outer loop
vertex -8.09017 3 -5.87785
vertex -10.309 2.95106 9.01243e-07
vertex -10 3 8.74228e-07
endloop
endfacet
facet normal 0.156233 0.986415 0.050763
outer loop
vertex -8.09017 3 -5.87785
vertex -10 3 8.74228e-07
vertex -7.84017 2.95106 -5.69622
endloop
endfacet
facet normal 0.156233 0.986415 0.0507631
outer loop
vertex -7.84017 2.95106 -5.69622
vertex -10 3 8.74228e-07
vertex -9.69098 2.95106 8.47213e-07
endloop
endfacet
facet normal 0.449131 0.881468 0.145932
outer loop
vertex -7.84017 2.95106 -5.69622
vertex -9.69098 2.95106 8.47213e-07
vertex -7.61464 2.80902 -5.53236
endloop
endfacet
facet normal 0.449131 0.881468 0.145932
outer loop
vertex -7.61464 2.80902 -5.53236
vertex -9.69098 2.95106 8.47213e-07
vertex -9.41222 2.80902 8.22842e-07
endloop
endfacet
facet normal 0.689151 0.689153 0.223919
outer loop
vertex -7.61464 2.80902 -5.53236
vertex -9.41222 2.80902 8.22842e-07
vertex -7.43566 2.58779 -5.40232
endloop
endfacet
facet normal 0.689151 0.689153 0.223919
outer loop
vertex -7.43566 2.58779 -5.40232
vertex -9.41222 2.80902 8.22842e-07
vertex -9.19098 2.58779 8.03501e-07
endloop
endfacet
facet normal 0.855862 0.436083 0.278086
outer loop
vertex -7.43566 2.58779 -5.40232
vertex -9.19098 2.58779 8.03501e-07
vertex -7.32075 2.30902 -5.31883
endloop
endfacet
facet normal 0.855862 0.436083 0.278086
outer loop
vertex -7.32075 2.30902 -5.31883
vertex -9.19098 2.58779 8.03501e-07
vertex -9.04894 2.30902 7.91084e-07
endloop
endfacet
facet normal 0.940447 0.148952 0.30557
outer loop
vertex -7.32075 2.30902 -5.31883
vertex -9.04894 2.30902 7.91084e-07
vertex -7.28115 2 -5.29007
endloop
endfacet
facet normal 0.940447 0.148952 0.30557
outer loop
vertex -7.28115 2 -5.29007
vertex -9.04894 2.30902 7.91084e-07
vertex -9 2 7.86805e-07
endloop
endfacet
facet normal 0.940447 -0.148952 0.30557
outer loop
vertex -7.28115 2 -5.29007
vertex -9 2 7.86805e-07
vertex -7.32075 1.69098 -5.31883
endloop
endfacet
facet normal 0.940447 -0.148952 0.30557
outer loop
vertex -7.32075 1.69098 -5.31883
vertex -9 2 7.86805e-07
vertex -9.04894 1.69098 7.91084e-07
endloop
endfacet
facet normal 0.855862 -0.436082 0.278086
outer loop
vertex -7.32075 1.69098 -5.31883
vertex -9.04894 1.69098 7.91084e-07
vertex -7.43566 1.41221 -5.40232
endloop
endfacet
facet normal 0.855862 -0.436083 0.278086
outer loop
vertex -7.43566 1.41221 -5.40232
vertex -9.04894 1.69098 7.91084e-07
vertex -9.19098 1.41221 8.03501e-07
endloop
endfacet
facet normal 0.689151 -0.689153 0.223919
outer loop
vertex -7.43566 1.41221 -5.40232
vertex -9.19098 1.41221 8.03501e-07
vertex -7.61464 1.19098 -5.53236
endloop
endfacet
facet normal 0.689151 -0.689153 0.223919
outer loop
vertex -7.61464 1.19098 -5.53236
vertex -9.19098 1.41221 8.03501e-07
vertex -9.41222 1.19098 8.22842e-07
endloop
endfacet
facet normal 0.449131 -0.881468 0.145931
outer loop
vertex -7.61464 1.19098 -5.53236
vertex -9.41222 1.19098 8.22842e-07
vertex -7.84017 1.04894 -5.69622
endloop
endfacet
facet normal 0.449131 -0.881468 0.145931
outer loop
vertex -7.84017 1.04894 -5.69622
vertex -9.41222 1.19098 8.22842e-07
vertex -9.69098 1.04894 8.47213e-07
endloop
endfacet
facet normal 0.156233 -0.986415 0.050763
outer loop
vertex -7.84017 1.04894 -5.69622
vertex -9.69098 1.04894 8.47213e-07
vertex -8.09017 1 -5.87785
endloop
endfacet
facet normal 0.156233 -0.986415 0.0507631
outer loop
vertex -8.09017 1 -5.87785
vertex -9.69098 1.04894 8.47213e-07
vertex -10 1 8.74228e-07
endloop
endfacet
facet normal -0.156233 -0.986415 -0.0507631
outer loop
vertex -8.09017 1 -5.87785
vertex -10 1 8.74228e-07
vertex -8.34017 1.04894 -6.05949
endloop
endfacet
facet normal -0.156233 -0.986415 -0.0507631
outer loop
vertex -8.34017 1.04894 -6.05949
vertex -10 1 8.74228e-07
vertex -10.309 1.04894 9.01243e-07
endloop
endfacet
facet normal -0.449131 -0.881468 -0.145931
outer loop
vertex -8.34017 1.04894 -6.05949
vertex -10.309 1.04894 9.01243e-07
vertex -8.5657 1.19098 -6.22334
endloop
endfacet
facet normal -0.449131 -0.881468 -0.145931
outer loop
vertex -8.5657 1.19098 -6.22334
vertex -10.309 1.04894 9.01243e-07
vertex -10.5878 1.19098 9.25614e-07
endloop
endfacet
facet normal -0.689151 -0.689153 -0.223919
outer loop
vertex -8.5657 1.19098 -6.22334
vertex -10.5878 1.19098 9.25614e-07
vertex -8.74468 1.41221 -6.35338
endloop
endfacet
facet normal -0.689151 -0.689153 -0.223919
outer loop
vertex -8.74468 1.41221 -6.35338
vertex -10.5878 1.19098 9.25614e-07
vertex -10.809 1.41221 9.44954e-07
endloop
endfacet
facet normal -0.855862 -0.436082 -0.278086
outer loop
vertex -8.74468 1.41221 -6.35338
vertex -10.809 1.41221 9.44954e-07
vertex -8.85959 1.69098 -6.43687
endloop
endfacet
facet normal -0.855862 -0.436083 -0.278086
outer loop
vertex -8.85959 1.69098 -6.43687
vertex -10.809 1.41221 9.44954e-07
vertex -10.9511 1.69098 9.57372e-07
endloop
endfacet
facet normal -0.940447 -0.148954 -0.30557
outer loop
vertex -8.85959 1.69098 -6.43687
vertex -10.9511 1.69098 9.57372e-07
vertex -8.89919 2 -6.46564
endloop
endfacet
facet normal -0.940447 0.148952 0.30557
outer loop
vertex -11 2 9.61651e-07
vertex -8.89919 2 6.46564
vertex -10.9511 2.30902 9.57372e-07
endloop
endfacet
facet normal -0.940447 -0.148951 0.30557
outer loop
vertex -11 2 9.61651e-07
vertex -8.85959 1.69098 6.43687
vertex -8.89919 2 6.46564
endloop
endfacet
facet normal -0.940447 0.148951 0.30557
outer loop
vertex -10.9511 2.30902 9.57372e-07
vertex -8.89919 2 6.46564
vertex -8.85959 2.30902 6.43687
endloop
endfacet
facet normal -0.855862 0.436083 0.278086
outer loop
vertex -10.9511 2.30902 9.57372e-07
vertex -8.85959 2.30902 6.43687
vertex -10.809 2.58779 9.44954e-07
endloop
endfacet
facet normal -0.855862 0.436082 0.278086
outer loop
vertex -10.809 2.58779 9.44954e-07
vertex -8.85959 2.30902 6.43687
vertex -8.74468 2.58779 6.35338
endloop
endfacet
facet normal -0.689152 0.689151 0.223919
outer loop
vertex -10.809 2.58779 9.44954e-07
vertex -8.74468 2.58779 6.35338
vertex -10.5878 2.80902 9.25614e-07
endloop
endfacet
facet normal -0.689151 0.689153 0.223919
outer loop
vertex -10.5878 2.80902 9.25614e-07
vertex -8.74468 2.58779 6.35338
vertex -8.5657 2.80902 6.22335
endloop
endfacet
facet normal -0.44913 0.881468 0.145931
outer loop
vertex -10.5878 2.80902 9.25614e-07
vertex -8.5657 2.80902 6.22335
vertex -10.309 2.95106 9.01243e-07
endloop
endfacet
facet normal -0.449131 0.881468 0.145932
outer loop
vertex -10.309 2.95106 9.01243e-07
vertex -8.5657 2.80902 6.22335
vertex -8.34017 2.95106 6.05949
endloop
endfacet
facet normal -0.156233 0.986415 0.0507631
outer loop
vertex -10.309 2.95106 9.01243e-07
vertex -8.34017 2.95106 6.05949
vertex -10 3 8.74228e-07
endloop
endfacet
facet normal -0.156233 0.986415 0.0507631
outer loop
vertex -10 3 8.74228e-07
vertex -8.34017 2.95106 6.05949
vertex -8.09017 3 5.87785
endloop
endfacet
facet normal 0.156233 0.986415 -0.0507631
outer loop
vertex -10 3 8.74228e-07
vertex -8.09017 3 5.87785
vertex -9.69098 2.95106 8.47213e-07
endloop
endfacet
facet normal 0.156233 0.986415 -0.0507631
outer loop
vertex -9.69098 2.95106 8.47213e-07
vertex -8.09017 3 5.87785
vertex -7.84017 2.95106 5.69622
endloop
endfacet
facet normal 0.449131 0.881468 -0.145932
outer loop
vertex -9.69098 2.95106 8.47213e-07
vertex -7.84017 2.95106 5.69622
vertex -9.41222 2.80902 8.22842e-07
endloop
endfacet
facet normal 0.449131 0.881468 -0.145932
outer loop
vertex -9.41222 2.80902 8.22842e-07
vertex -7.84017 2.95106 5.69622
vertex -7.61464 2.80902 5.53236
endloop
endfacet
facet normal 0.689151 0.689153 -0.223919
outer loop
vertex -9.41222 2.80902 8.22842e-07
vertex -7.61464 2.80902 5.53236
vertex -9.19098 2.58779 8.03501e-07
endloop
endfacet
facet normal 0.689151 0.689153 -0.223919
outer loop
vertex -9.19098 2.58779 8.03501e-07
vertex -7.61464 2.80902 5.53236
vertex -7.43566 2.58779 5.40233
endloop
endfacet
facet normal 0.855862 0.436083 -0.278086
outer loop
vertex -9.19098 2.58779 8.03501e-07
vertex -7.43566 2.58779 5.40233
vertex -9.04894 2.30902 7.91084e-07
endloop
endfacet
facet normal 0.855862 0.436082 -0.278087
outer loop
vertex -9.04894 2.30902 7.91084e-07
vertex -7.43566 2.58779 5.40233
vertex -7.32075 2.30902 5.31884
endloop
endfacet
facet normal 0.940447 0.148952 -0.30557
outer loop
vertex -9.04894 2.30902 7.91084e-07
vertex -7.32075 2.30902 5.31884
vertex -9 2 7.86805e-07
endloop
endfacet
facet normal 0.940447 0.148952 -0.30557
outer loop
vertex -9 2 7.86805e-07
vertex -7.32075 2.30902 5.31884
vertex -7.28115 2 5.29007
endloop
endfacet
facet normal 0.940447 -0.148952 -0.30557
outer loop
vertex -9 2 7.86805e-07
vertex -7.28115 2 5.29007
vertex -9.04894 1.69098 7.91084e-07
endloop
endfacet
facet normal 0.940447 -0.148952 -0.30557
outer loop
vertex -9.04894 1.69098 7.91084e-07
vertex -7.28115 2 5.29007
vertex -7.32075 1.69098 5.31884
endloop
endfacet
facet normal 0.855862 -0.436083 -0.278086
outer loop
vertex -9.04894 1.69098 7.91084e-07
vertex -7.32075 1.69098 5.31884
vertex -9.19098 1.41221 8.03501e-07
endloop
endfacet
facet normal 0.855862 -0.436082 -0.278087
outer loop
vertex -9.19098 1.41221 8.03501e-07
vertex -7.32075 1.69098 5.31884
vertex -7.43566 1.41221 5.40233
endloop
endfacet
facet normal 0.689151 -0.689153 -0.223919
outer loop
vertex -9.19098 1.41221 8.03501e-07
vertex -7.43566 1.41221 5.40233
vertex -9.41222 1.19098 8.22842e-07
endloop
endfacet
facet normal 0.689151 -0.689153 -0.223919
outer loop
vertex -9.41222 1.19098 8.22842e-07
vertex -7.43566 1.41221 5.40233
vertex -7.61464 1.19098 5.53236
endloop
endfacet
facet normal 0.449131 -0.881468 -0.145931
outer loop
vertex -9.41222 1.19098 8.22842e-07
vertex -7.61464 1.19098 5.53236
vertex -9.69098 1.04894 8.47213e-07
endloop
endfacet
facet normal 0.449131 -0.881468 -0.145931
outer loop
vertex -9.69098 1.04894 8.47213e-07
vertex -7.61464 1.19098 5.53236
vertex -7.84017 1.04894 5.69622
endloop
endfacet
facet normal 0.156233 -0.986415 -0.0507631
outer loop
vertex -9.69098 1.04894 8.47213e-07
vertex -7.84017 1.04894 5.69622
vertex -10 1 8.74228e-07
endloop
endfacet
facet normal 0.156233 -0.986415 -0.0507631
outer loop
vertex -10 1 8.74228e-07
vertex -7.84017 1.04894 5.69622
vertex -8.09017 1 5.87785
endloop
endfacet
facet normal -0.156233 -0.986415 0.0507631
outer loop
vertex -10 1 8.74228e-07
vertex -8.09017 1 5.87785
vertex -10.309 1.04894 9.01243e-07
endloop
endfacet
facet normal -0.156233 -0.986415 0.0507631
outer loop
vertex -10.309 1.04894 9.01243e-07
vertex -8.09017 1 5.87785
vertex -8.34017 1.04894 6.05949
endloop
endfacet
facet normal -0.449131 -0.881468 0.145931
outer loop
vertex -10.309 1.04894 9.01243e-07
vertex -8.34017 1.04894 6.05949
vertex -10.5878 1.19098 9.25614e-07
endloop
endfacet
facet normal -0.449131 -0.881468 0.145931
outer loop
vertex -10.5878 1.19098 9.25614e-07
vertex -8.34017 1.04894 6.05949
vertex -8.5657 1.19098 6.22334
endloop
endfacet
facet normal -0.689151 -0.689153 0.223919
outer loop
vertex -10.5878 1.19098 9.25614e-07
vertex -8.5657 1.19098 6.22334
vertex -10.809 1.41221 9.44954e-07
endloop
endfacet
facet normal -0.689151 -0.689153 0.223919
outer loop
vertex -10.809 1.41221 9.44954e-07
vertex -8.5657 1.19098 6.22334
vertex -8.74468 1.41221 6.35338
endloop
endfacet
facet normal -0.855862 -0.436083 0.278086
outer loop
vertex -10.809 1.41221 9.44954e-07
vertex -8.74468 1.41221 6.35338
vertex -10.9511 1.69098 9.57372e-07
endloop
endfacet
facet normal -0.855862 -0.436082 0.278087
outer loop
vertex -10.9511 1.69098 9.57372e-07
vertex -8.74468 1.41221 6.35338
vertex -8.85959 1.69098 6.43687
endloop
endfacet
facet normal -0.940447 -0.148952 0.30557
outer loop
vertex -10.9511 1.69098 9.57372e-07
vertex -8.85959 1.69098 6.43687
vertex -11 2 9.61651e-07
endloop
endfacet
facet normal -0.581228 0.148952 0.799992
outer loop
vertex -8.89919 2 6.46564
vertex -3.39919 2 10.4616
vertex -8.85959 2.30902 6.43687
endloop
endfacet
facet normal -0.581228 -0.148951 0.799992
outer loop
vertex -8.89919 2 6.46564
vertex -3.38406 1.69098 10.4151
vertex -3.39919 2 10.4616
endloop
endfacet
facet normal -0.581228 0.148951 0.799992
outer loop
vertex -8.85959 2.30902 6.43687
vertex -3.39919 2 10.4616
vertex -3.38406 2.30902 10.4151
endloop
endfacet
facet normal -0.528952 0.436082 0.72804
outer loop
vertex -8.85959 2.30902 6.43687
vertex -3.38406 2.30902 10.4151
vertex -8.74468 2.58779 6.35338
endloop
endfacet
facet normal -0.528951 0.436084 0.728039
outer loop
vertex -8.74468 2.58779 6.35338
vertex -3.38406 2.30902 10.4151
vertex -3.34017 2.58779 10.28
endloop
endfacet
facet normal -0.425919 0.689152 0.586227
outer loop
vertex -8.74468 2.58779 6.35338
vertex -3.34017 2.58779 10.28
vertex -8.5657 2.80902 6.22335
endloop
endfacet
facet normal -0.42592 0.689151 0.586228
outer loop
vertex -8.5657 2.80902 6.22335
vertex -3.34017 2.58779 10.28
vertex -3.27181 2.80902 10.0696
endloop
endfacet
facet normal -0.277578 0.881468 0.382053
outer loop
vertex -8.5657 2.80902 6.22335
vertex -3.27181 2.80902 10.0696
vertex -8.34017 2.95106 6.05949
endloop
endfacet
facet normal -0.277578 0.881468 0.382053
outer loop
vertex -8.34017 2.95106 6.05949
vertex -3.27181 2.80902 10.0696
vertex -3.18566 2.95106 9.80446
endloop
endfacet
facet normal -0.0965572 0.986415 0.1329
outer loop
vertex -8.34017 2.95106 6.05949
vertex -3.18566 2.95106 9.80446
vertex -8.09017 3 5.87785
endloop
endfacet
facet normal -0.0965571 0.986415 0.132899
outer loop
vertex -8.09017 3 5.87785
vertex -3.18566 2.95106 9.80446
vertex -3.09017 3 9.51056
endloop
endfacet
facet normal 0.0965572 0.986415 -0.1329
outer loop
vertex -8.09017 3 5.87785
vertex -3.09017 3 9.51056
vertex -7.84017 2.95106 5.69622
endloop
endfacet
facet normal 0.096557 0.986415 -0.132899
outer loop
vertex -7.84017 2.95106 5.69622
vertex -3.09017 3 9.51056
vertex -2.99468 2.95106 9.21667
endloop
endfacet
facet normal 0.277578 0.881468 -0.382054
outer loop
vertex -7.84017 2.95106 5.69622
vertex -2.99468 2.95106 9.21667
vertex -7.61464 2.80902 5.53236
endloop
endfacet
facet normal 0.277579 0.881467 -0.382055
outer loop
vertex -7.61464 2.80902 5.53236
vertex -2.99468 2.95106 9.21667
vertex -2.90854 2.80902 8.95155
endloop
endfacet
facet normal 0.425918 0.689153 -0.586226
outer loop
vertex -7.61464 2.80902 5.53236
vertex -2.90854 2.80902 8.95155
vertex -7.43566 2.58779 5.40233
endloop
endfacet
facet normal 0.425919 0.689153 -0.586227
outer loop
vertex -7.43566 2.58779 5.40233
vertex -2.90854 2.80902 8.95155
vertex -2.84017 2.58779 8.74114
endloop
endfacet
facet normal 0.528952 0.436082 -0.72804
outer loop
vertex -7.43566 2.58779 5.40233
vertex -2.84017 2.58779 8.74114
vertex -7.32075 2.30902 5.31884
endloop
endfacet
facet normal 0.528951 0.436084 -0.728039
outer loop
vertex -7.32075 2.30902 5.31884
vertex -2.84017 2.58779 8.74114
vertex -2.79628 2.30902 8.60606
endloop
endfacet
facet normal 0.581228 0.148953 -0.799992
outer loop
vertex -7.32075 2.30902 5.31884
vertex -2.79628 2.30902 8.60606
vertex -7.28115 2 5.29007
endloop
endfacet
facet normal 0.581228 0.148951 -0.799992
outer loop
vertex -7.28115 2 5.29007
vertex -2.79628 2.30902 8.60606
vertex -2.78115 2 8.55951
endloop
endfacet
facet normal 0.581228 -0.148953 -0.799992
outer loop
vertex -7.28115 2 5.29007
vertex -2.78115 2 8.55951
vertex -7.32075 1.69098 5.31884
endloop
endfacet
facet normal 0.581228 -0.148952 -0.799992
outer loop
vertex -7.32075 1.69098 5.31884
vertex -2.78115 2 8.55951
vertex -2.79628 1.69098 8.60606
endloop
endfacet
facet normal 0.528952 -0.436082 -0.72804
outer loop
vertex -7.32075 1.69098 5.31884
vertex -2.79628 1.69098 8.60606
vertex -7.43566 1.41221 5.40233
endloop
endfacet
facet normal 0.528952 -0.436083 -0.72804
outer loop
vertex -7.43566 1.41221 5.40233
vertex -2.79628 1.69098 8.60606
vertex -2.84017 1.41221 8.74114
endloop
endfacet
facet normal 0.425919 -0.689153 -0.586227
outer loop
vertex -7.43566 1.41221 5.40233
vertex -2.84017 1.41221 8.74114
vertex -7.61464 1.19098 5.53236
endloop
endfacet
facet normal 0.425919 -0.689153 -0.586227
outer loop
vertex -7.61464 1.19098 5.53236
vertex -2.84017 1.41221 8.74114
vertex -2.90854 1.19098 8.95155
endloop
endfacet
facet normal 0.277578 -0.881468 -0.382053
outer loop
vertex -7.61464 1.19098 5.53236
vertex -2.90854 1.19098 8.95155
vertex -7.84017 1.04894 5.69622
endloop
endfacet
facet normal 0.277579 -0.881467 -0.382054
outer loop
vertex -7.84017 1.04894 5.69622
vertex -2.90854 1.19098 8.95155
vertex -2.99468 1.04894 9.21667
endloop
endfacet
facet normal 0.0965572 -0.986415 -0.1329
outer loop
vertex -7.84017 1.04894 5.69622
vertex -2.99468 1.04894 9.21667
vertex -8.09017 1 5.87785
endloop
endfacet
facet normal 0.0965572 -0.986415 -0.1329
outer loop
vertex -8.09017 1 5.87785
vertex -2.99468 1.04894 9.21667
vertex -3.09017 1 9.51056
endloop
endfacet
facet normal -0.0965572 -0.986415 0.1329
outer loop
vertex -8.09017 1 5.87785
vertex -3.09017 1 9.51056
vertex -8.34017 1.04894 6.05949
endloop
endfacet
facet normal -0.0965571 -0.986415 0.1329
outer loop
vertex -8.34017 1.04894 6.05949
vertex -3.09017 1 9.51056
vertex -3.18566 1.04894 9.80446
endloop
endfacet
facet normal -0.277578 -0.881468 0.382053
outer loop
vertex -8.34017 1.04894 6.05949
vertex -3.18566 1.04894 9.80446
vertex -8.5657 1.19098 6.22334
endloop
endfacet
facet normal -0.277578 -0.881468 0.382054
outer loop
vertex -8.5657 1.19098 6.22334
vertex -3.18566 1.04894 9.80446
vertex -3.27181 1.19098 10.0696
endloop
endfacet
facet normal -0.425919 -0.689153 0.586227
outer loop
vertex -8.5657 1.19098 6.22334
vertex -3.27181 1.19098 10.0696
vertex -8.74468 1.41221 6.35338
endloop
endfacet
facet normal -0.425919 -0.689152 0.586227
outer loop
vertex -8.74468 1.41221 6.35338
vertex -3.27181 1.19098 10.0696
vertex -3.34017 1.41221 10.28
endloop
endfacet
facet normal -0.528952 -0.436082 0.72804
outer loop
vertex -8.74468 1.41221 6.35338
vertex -3.34017 1.41221 10.28
vertex -8.85959 1.69098 6.43687
endloop
endfacet
facet normal -0.528951 -0.436085 0.728039
outer loop
vertex -8.85959 1.69098 6.43687
vertex -3.34017 1.41221 10.28
vertex -3.38406 1.69098 10.4151
endloop
endfacet
facet normal -0.581228 -0.148952 0.799992
outer loop
vertex -8.85959 1.69098 6.43687
vertex -3.38406 1.69098 10.4151
vertex -8.89919 2 6.46564
endloop
endfacet
facet normal -0 0.148952 0.988845
outer loop
vertex -3.39919 2 10.4616
vertex 3.39919 2 10.4616
vertex -3.38406 2.30902 10.4151
endloop
endfacet
facet normal 0 -0.148952 0.988845
outer loop
vertex -3.39919 2 10.4616
vertex 3.38406 1.69098 10.4151
vertex 3.39919 2 10.4616
endloop
endfacet
facet normal -0 0.148952 0.988844
outer loop
vertex -3.38406 2.30902 10.4151
vertex 3.39919 2 10.4616
vertex 3.38406 2.30902 10.4151
endloop
endfacet
facet normal -0 0.436084 0.899906
outer loop
vertex -3.38406 2.30902 10.4151
vertex 3.38406 2.30902 10.4151
vertex -3.34017 2.58779 10.28
endloop
endfacet
facet normal -0 0.436084 0.899906
outer loop
vertex -3.34017 2.58779 10.28
vertex 3.38406 2.30902 10.4151
vertex 3.34017 2.58779 10.28
endloop
endfacet
facet normal -0 0.689151 0.724618
outer loop
vertex -3.34017 2.58779 10.28
vertex 3.34017 2.58779 10.28
vertex -3.27181 2.80902 10.0696
endloop
endfacet
facet normal -0 0.689151 0.724618
outer loop
vertex -3.27181 2.80902 10.0696
vertex 3.34017 2.58779 10.28
vertex 3.27181 2.80902 10.0696
endloop
endfacet
facet normal -0 0.881468 0.472244
outer loop
vertex -3.27181 2.80902 10.0696
vertex 3.27181 2.80902 10.0696
vertex -3.18566 2.95106 9.80446
endloop
endfacet
facet normal -0 0.881468 0.472244
outer loop
vertex -3.18566 2.95106 9.80446
vertex 3.27181 2.80902 10.0696
vertex 3.18566 2.95106 9.80446
endloop
endfacet
facet normal -0 0.986415 0.164273
outer loop
vertex -3.18566 2.95106 9.80446
vertex 3.18566 2.95106 9.80446
vertex -3.09017 3 9.51056
endloop
endfacet
facet normal -0 0.986415 0.164273
outer loop
vertex -3.09017 3 9.51056
vertex 3.18566 2.95106 9.80446
vertex 3.09017 3 9.51056
endloop
endfacet
facet normal 0 0.986415 -0.164273
outer loop
vertex -3.09017 3 9.51056
vertex 3.09017 3 9.51056
vertex -2.99468 2.95106 9.21667
endloop
endfacet
facet normal 0 0.986415 -0.164273
outer loop
vertex -2.99468 2.95106 9.21667
vertex 3.09017 3 9.51056
vertex 2.99468 2.95106 9.21667
endloop
endfacet
facet normal 0 0.881467 -0.472245
outer loop
vertex -2.99468 2.95106 9.21667
vertex 2.99468 2.95106 9.21667
vertex -2.90854 2.80902 8.95155
endloop
endfacet
facet normal 0 0.881467 -0.472245
outer loop
vertex -2.90854 2.80902 8.95155
vertex 2.99468 2.95106 9.21667
vertex 2.90854 2.80902 8.95155
endloop
endfacet
facet normal 0 0.689153 -0.724616
outer loop
vertex -2.90854 2.80902 8.95155
vertex 2.90854 2.80902 8.95155
vertex -2.84017 2.58779 8.74114
endloop
endfacet
facet normal 0 0.689153 -0.724616
outer loop
vertex -2.84017 2.58779 8.74114
vertex 2.90854 2.80902 8.95155
vertex 2.84017 2.58779 8.74114
endloop
endfacet
facet normal 0 0.436084 -0.899906
outer loop
vertex -2.84017 2.58779 8.74114
vertex 2.84017 2.58779 8.74114
vertex -2.79628 2.30902 8.60606
endloop
endfacet
facet normal 0 0.436084 -0.899906
outer loop
vertex -2.79628 2.30902 8.60606
vertex 2.84017 2.58779 8.74114
vertex 2.79628 2.30902 8.60606
endloop
endfacet
facet normal 0 0.148952 -0.988844
outer loop
vertex -2.79628 2.30902 8.60606
vertex 2.79628 2.30902 8.60606
vertex -2.78115 2 8.55951
endloop
endfacet
facet normal 0 0.148952 -0.988845
outer loop
vertex -2.78115 2 8.55951
vertex 2.79628 2.30902 8.60606
vertex 2.78115 2 8.55951
endloop
endfacet
facet normal 0 -0.148952 -0.988844
outer loop
vertex -2.78115 2 8.55951
vertex 2.78115 2 8.55951
vertex -2.79628 1.69098 8.60606
endloop
endfacet
facet normal 0 -0.148952 -0.988844
outer loop
vertex -2.79628 1.69098 8.60606
vertex 2.78115 2 8.55951
vertex 2.79628 1.69098 8.60606
endloop
endfacet
facet normal 0 -0.436084 -0.899906
outer loop
vertex -2.79628 1.69098 8.60606
vertex 2.79628 1.69098 8.60606
vertex -2.84017 1.41221 8.74114
endloop
endfacet
facet normal 0 -0.436084 -0.899906
outer loop
vertex -2.84017 1.41221 8.74114
vertex 2.79628 1.69098 8.60606
vertex 2.84017 1.41221 8.74114
endloop
endfacet
facet normal 0 -0.689152 -0.724616
outer loop
vertex -2.84017 1.41221 8.74114
vertex 2.84017 1.41221 8.74114
vertex -2.90854 1.19098 8.95155
endloop
endfacet
facet normal 0 -0.689152 -0.724616
outer loop
vertex -2.90854 1.19098 8.95155
vertex 2.84017 1.41221 8.74114
vertex 2.90854 1.19098 8.95155
endloop
endfacet
facet normal 0 -0.881468 -0.472245
outer loop
vertex -2.90854 1.19098 8.95155
vertex 2.90854 1.19098 8.95155
vertex -2.99468 1.04894 9.21667
endloop
endfacet
facet normal 0 -0.881468 -0.472244
outer loop
vertex -2.99468 1.04894 9.21667
vertex 2.90854 1.19098 8.95155
vertex 2.99468 1.04894 9.21667
endloop
endfacet
facet normal 0 -0.986415 -0.164273
outer loop
vertex -2.99468 1.04894 9.21667
vertex 2.99468 1.04894 9.21667
vertex -3.09017 1 9.51056
endloop
endfacet
facet normal 0 -0.986415 -0.164273
outer loop
vertex -3.09017 1 9.51056
vertex 2.99468 1.04894 9.21667
vertex 3.09017 1 9.51056
endloop
endfacet
facet normal 0 -0.986415 0.164273
outer loop
vertex -3.09017 1 9.51056
vertex 3.09017 1 9.51056
vertex -3.18566 1.04894 9.80446
endloop
endfacet
facet normal 0 -0.986415 0.164273
outer loop
vertex -3.18566 1.04894 9.80446
vertex 3.09017 1 9.51056
vertex 3.18566 1.04894 9.80446
endloop
endfacet
facet normal 0 -0.881468 0.472244
outer loop
vertex -3.18566 1.04894 9.80446
vertex 3.18566 1.04894 9.80446
vertex -3.27181 1.19098 10.0696
endloop
endfacet
facet normal 0 -0.881468 0.472244
outer loop
vertex -3.27181 1.19098 10.0696
vertex 3.18566 1.04894 9.80446
vertex 3.27181 1.19098 10.0696
endloop
endfacet
facet normal 0 -0.689152 0.724616
outer loop
vertex -3.27181 1.19098 10.0696
vertex 3.27181 1.19098 10.0696
vertex -3.34017 1.41221 10.28
endloop
endfacet
facet normal 0 -0.689152 0.724617
outer loop
vertex -3.34017 1.41221 10.28
vertex 3.27181 1.19098 10.0696
vertex 3.34017 1.41221 10.28
endloop
endfacet
facet normal 0 -0.436084 0.899906
outer loop
vertex -3.34017 1.41221 10.28
vertex 3.34017 1.41221 10.28
vertex -3.38406 1.69098 10.4151
endloop
endfacet
facet normal 0 -0.436084 0.899906
outer loop
vertex -3.38406 1.69098 10.4151
vertex 3.34017 1.41221 10.28
vertex 3.38406 1.69098 10.4151
endloop
endfacet
facet normal 0 -0.148952 0.988844
outer loop
vertex -3.38406 1.69098 10.4151
vertex 3.38406 1.69098 10.4151
vertex -3.39919 2 10.4616
endloop
endfacet
facet normal 0.581228 0.148952 0.799992
outer loop
vertex 3.39919 2 10.4616
vertex 8.89919 2 6.46564
vertex 3.38406 2.30902 10.4151
endloop
endfacet
facet normal 0.581228 -0.148951 0.799992
outer loop
vertex 3.39919 2 10.4616
vertex 8.85959 1.69098 6.43687
vertex 8.89919 2 6.46564
endloop
endfacet
facet normal 0.581228 0.148951 0.799992
outer loop
vertex 3.38406 2.30902 10.4151
vertex 8.89919 2 6.46564
vertex 8.85959 2.30902 6.43687
endloop
endfacet
facet normal 0.528951 0.436084 0.728039
outer loop
vertex 3.38406 2.30902 10.4151
vertex 8.85959 2.30902 6.43687
vertex 3.34017 2.58779 10.28
endloop
endfacet
facet normal 0.528952 0.436083 0.72804
outer loop
vertex 3.34017 2.58779 10.28
vertex 8.85959 2.30902 6.43687
vertex 8.74468 2.58779 6.35338
endloop
endfacet
facet normal 0.42592 0.689151 0.586228
outer loop
vertex 3.34017 2.58779 10.28
vertex 8.74468 2.58779 6.35338
vertex 3.27181 2.80902 10.0696
endloop
endfacet
facet normal 0.425919 0.689153 0.586227
outer loop
vertex 3.27181 2.80902 10.0696
vertex 8.74468 2.58779 6.35338
vertex 8.5657 2.80902 6.22334
endloop
endfacet
facet normal 0.277578 0.881468 0.382053
outer loop
vertex 3.27181 2.80902 10.0696
vertex 8.5657 2.80902 6.22334
vertex 3.18566 2.95106 9.80446
endloop
endfacet
facet normal 0.277578 0.881468 0.382053
outer loop
vertex 3.18566 2.95106 9.80446
vertex 8.5657 2.80902 6.22334
vertex 8.34017 2.95106 6.05949
endloop
endfacet
facet normal 0.0965572 0.986415 0.1329
outer loop
vertex 3.18566 2.95106 9.80446
vertex 8.34017 2.95106 6.05949
vertex 3.09017 3 9.51056
endloop
endfacet
facet normal 0.0965572 0.986415 0.1329
outer loop
vertex 3.09017 3 9.51056
vertex 8.34017 2.95106 6.05949
vertex 8.09017 3 5.87785
endloop
endfacet
facet normal -0.0965572 0.986415 -0.1329
outer loop
vertex 3.09017 3 9.51056
vertex 8.09017 3 5.87785
vertex 2.99468 2.95106 9.21667
endloop
endfacet
facet normal -0.096557 0.986415 -0.132899
outer loop
vertex 2.99468 2.95106 9.21667
vertex 8.09017 3 5.87785
vertex 7.84017 2.95106 5.69622
endloop
endfacet
facet normal -0.277579 0.881467 -0.382054
outer loop
vertex 2.99468 2.95106 9.21667
vertex 7.84017 2.95106 5.69622
vertex 2.90854 2.80902 8.95155
endloop
endfacet
facet normal -0.277579 0.881467 -0.382054
outer loop
vertex 2.90854 2.80902 8.95155
vertex 7.84017 2.95106 5.69622
vertex 7.61464 2.80902 5.53236
endloop
endfacet
facet normal -0.425919 0.689153 -0.586227
outer loop
vertex 2.90854 2.80902 8.95155
vertex 7.61464 2.80902 5.53236
vertex 2.84017 2.58779 8.74114
endloop
endfacet
facet normal -0.425919 0.689153 -0.586226
outer loop
vertex 2.84017 2.58779 8.74114
vertex 7.61464 2.80902 5.53236
vertex 7.43566 2.58779 5.40232
endloop
endfacet
facet normal -0.528952 0.436084 -0.728039
outer loop
vertex 2.84017 2.58779 8.74114
vertex 7.43566 2.58779 5.40232
vertex 2.79628 2.30902 8.60606
endloop
endfacet
facet normal -0.528952 0.436082 -0.72804
outer loop
vertex 2.79628 2.30902 8.60606
vertex 7.43566 2.58779 5.40232
vertex 7.32075 2.30902 5.31884
endloop
endfacet
facet normal -0.581228 0.148952 -0.799992
outer loop
vertex 2.79628 2.30902 8.60606
vertex 7.32075 2.30902 5.31884
vertex 2.78115 2 8.55951
endloop
endfacet
facet normal -0.581228 0.148953 -0.799992
outer loop
vertex 2.78115 2 8.55951
vertex 7.32075 2.30902 5.31884
vertex 7.28115 2 5.29007
endloop
endfacet
facet normal -0.581228 -0.148952 -0.799992
outer loop
vertex 2.78115 2 8.55951
vertex 7.28115 2 5.29007
vertex 2.79628 1.69098 8.60606
endloop
endfacet
facet normal -0.581228 -0.148953 -0.799992
outer loop
vertex 2.79628 1.69098 8.60606
vertex 7.28115 2 5.29007
vertex 7.32075 1.69098 5.31884
endloop
endfacet
facet normal -0.528951 -0.436084 -0.728039
outer loop
vertex 2.79628 1.69098 8.60606
vertex 7.32075 1.69098 5.31884
vertex 2.84017 1.41221 8.74114
endloop
endfacet
facet normal -0.528952 -0.436082 -0.72804
outer loop
vertex 2.84017 1.41221 8.74114
vertex 7.32075 1.69098 5.31884
vertex 7.43566 1.41221 5.40232
endloop
endfacet
facet normal -0.425919 -0.689153 -0.586227
outer loop
vertex 2.84017 1.41221 8.74114
vertex 7.43566 1.41221 5.40232
vertex 2.90854 1.19098 8.95155
endloop
endfacet
facet normal -0.425919 -0.689153 -0.586227
outer loop
vertex 2.90854 1.19098 8.95155
vertex 7.43566 1.41221 5.40232
vertex 7.61464 1.19098 5.53236
endloop
endfacet
facet normal -0.277578 -0.881468 -0.382054
outer loop
vertex 2.90854 1.19098 8.95155
vertex 7.61464 1.19098 5.53236
vertex 2.99468 1.04894 9.21667
endloop
endfacet
facet normal -0.277578 -0.881468 -0.382054
outer loop
vertex 2.99468 1.04894 9.21667
vertex 7.61464 1.19098 5.53236
vertex 7.84017 1.04894 5.69622
endloop
endfacet
facet normal -0.0965572 -0.986415 -0.1329
outer loop
vertex 2.99468 1.04894 9.21667
vertex 7.84017 1.04894 5.69622
vertex 3.09017 1 9.51056
endloop
endfacet
facet normal -0.0965571 -0.986415 -0.132899
outer loop
vertex 3.09017 1 9.51056
vertex 7.84017 1.04894 5.69622
vertex 8.09017 1 5.87785
endloop
endfacet
facet normal 0.0965572 -0.986415 0.1329
outer loop
vertex 3.09017 1 9.51056
vertex 8.09017 1 5.87785
vertex 3.18566 1.04894 9.80446
endloop
endfacet
facet normal 0.0965572 -0.986415 0.1329
outer loop
vertex 3.18566 1.04894 9.80446
vertex 8.09017 1 5.87785
vertex 8.34017 1.04894 6.05949
endloop
endfacet
facet normal 0.277578 -0.881468 0.382054
outer loop
vertex 3.18566 1.04894 9.80446
vertex 8.34017 1.04894 6.05949
vertex 3.27181 1.19098 10.0696
endloop
endfacet
facet normal 0.277578 -0.881468 0.382054
outer loop
vertex 3.27181 1.19098 10.0696
vertex 8.34017 1.04894 6.05949
vertex 8.5657 1.19098 6.22334
endloop
endfacet
facet normal 0.425919 -0.689152 0.586227
outer loop
vertex 3.27181 1.19098 10.0696
vertex 8.5657 1.19098 6.22334
vertex 3.34017 1.41221 10.28
endloop
endfacet
facet normal 0.425919 -0.689153 0.586227
outer loop
vertex 3.34017 1.41221 10.28
vertex 8.5657 1.19098 6.22334
vertex 8.74468 1.41221 6.35338
endloop
endfacet
facet normal 0.528951 -0.436084 0.728039
outer loop
vertex 3.34017 1.41221 10.28
vertex 8.74468 1.41221 6.35338
vertex 3.38406 1.69098 10.4151
endloop
endfacet
facet normal 0.528952 -0.436082 0.72804
outer loop
vertex 3.38406 1.69098 10.4151
vertex 8.74468 1.41221 6.35338
vertex 8.85959 1.69098 6.43687
endloop
endfacet
facet normal 0.581228 -0.148952 0.799992
outer loop
vertex 3.38406 1.69098 10.4151
vertex 8.85959 1.69098 6.43687
vertex 3.39919 2 10.4616
endloop
endfacet
facet normal 0.940447 0.14895 0.30557
outer loop
vertex 8.89919 2 6.46564
vertex 11 2 -1.9233e-06
vertex 8.85959 2.30902 6.43687
endloop
endfacet
facet normal 0.940447 -0.148952 0.30557
outer loop
vertex 8.89919 2 6.46564
vertex 10.9511 1.69098 -1.91474e-06
vertex 11 2 -1.9233e-06
endloop
endfacet
facet normal 0.940447 0.148952 0.30557
outer loop
vertex 8.85959 2.30902 6.43687
vertex 11 2 -1.9233e-06
vertex 10.9511 2.30902 -1.91474e-06
endloop
endfacet
facet normal 0.855862 0.436082 0.278086
outer loop
vertex 8.85959 2.30902 6.43687
vertex 10.9511 2.30902 -1.91474e-06
vertex 8.74468 2.58779 6.35338
endloop
endfacet
facet normal 0.855862 0.436082 0.278086
outer loop
vertex 8.74468 2.58779 6.35338
vertex 10.9511 2.30902 -1.91474e-06
vertex 10.809 2.58779 -1.88991e-06
endloop
endfacet
facet normal 0.689151 0.689153 0.223919
outer loop
vertex 8.74468 2.58779 6.35338
vertex 10.809 2.58779 -1.88991e-06
vertex 8.5657 2.80902 6.22334
endloop
endfacet
facet normal 0.689152 0.689151 0.223919
outer loop
vertex 8.5657 2.80902 6.22334
vertex 10.809 2.58779 -1.88991e-06
vertex 10.5878 2.80902 -1.85123e-06
endloop
endfacet
facet normal 0.449131 0.881468 0.145932
outer loop
vertex 8.5657 2.80902 6.22334
vertex 10.5878 2.80902 -1.85123e-06
vertex 8.34017 2.95106 6.05949
endloop
endfacet
facet normal 0.44913 0.881468 0.145931
outer loop
vertex 8.34017 2.95106 6.05949
vertex 10.5878 2.80902 -1.85123e-06
vertex 10.309 2.95106 -1.80249e-06
endloop
endfacet
facet normal 0.156233 0.986415 0.0507631
outer loop
vertex 8.34017 2.95106 6.05949
vertex 10.309 2.95106 -1.80249e-06
vertex 8.09017 3 5.87785
endloop
endfacet
facet normal 0.156233 0.986415 0.0507631
outer loop
vertex 8.09017 3 5.87785
vertex 10.309 2.95106 -1.80249e-06
vertex 10 3 -1.74846e-06
endloop
endfacet
facet normal -0.156233 0.986415 -0.050763
outer loop
vertex 8.09017 3 5.87785
vertex 10 3 -1.74846e-06
vertex 7.84017 2.95106 5.69622
endloop
endfacet
facet normal -0.156233 0.986415 -0.0507631
outer loop
vertex 7.84017 2.95106 5.69622
vertex 10 3 -1.74846e-06
vertex 9.69098 2.95106 -1.69443e-06
endloop
endfacet
facet normal -0.449131 0.881467 -0.145932
outer loop
vertex 7.84017 2.95106 5.69622
vertex 9.69098 2.95106 -1.69443e-06
vertex 7.61464 2.80902 5.53236
endloop
endfacet
facet normal -0.449131 0.881468 -0.145932
outer loop
vertex 7.61464 2.80902 5.53236
vertex 9.69098 2.95106 -1.69443e-06
vertex 9.41222 2.80902 -1.64568e-06
endloop
endfacet
facet normal -0.689151 0.689153 -0.223919
outer loop
vertex 7.61464 2.80902 5.53236
vertex 9.41222 2.80902 -1.64568e-06
vertex 7.43566 2.58779 5.40232
endloop
endfacet
facet normal -0.68915 0.689153 -0.223919
outer loop
vertex 7.43566 2.58779 5.40232
vertex 9.41222 2.80902 -1.64568e-06
vertex 9.19098 2.58779 -1.607e-06
endloop
endfacet
facet normal -0.855862 0.436082 -0.278086
outer loop
vertex 7.43566 2.58779 5.40232
vertex 9.19098 2.58779 -1.607e-06
vertex 7.32075 2.30902 5.31884
endloop
endfacet
facet normal -0.855862 0.436083 -0.278086
outer loop
vertex 7.32075 2.30902 5.31884
vertex 9.19098 2.58779 -1.607e-06
vertex 9.04894 2.30902 -1.58217e-06
endloop
endfacet
facet normal -0.940447 0.148952 -0.30557
outer loop
vertex 7.32075 2.30902 5.31884
vertex 9.04894 2.30902 -1.58217e-06
vertex 7.28115 2 5.29007
endloop
endfacet
facet normal -0.940447 0.148952 -0.30557
outer loop
vertex 7.28115 2 5.29007
vertex 9.04894 2.30902 -1.58217e-06
vertex 9 2 -1.57361e-06
endloop
endfacet
facet normal -0.940447 -0.148952 -0.30557
outer loop
vertex 7.28115 2 5.29007
vertex 9 2 -1.57361e-06
vertex 7.32075 1.69098 5.31884
endloop
endfacet
facet normal -0.940447 -0.148952 -0.30557
outer loop
vertex 7.32075 1.69098 5.31884
vertex 9 2 -1.57361e-06
vertex 9.04894 1.69098 -1.58217e-06
endloop
endfacet
facet normal -0.855862 -0.436082 -0.278086
outer loop
vertex 7.32075 1.69098 5.31884
vertex 9.04894 1.69098 -1.58217e-06
vertex 7.43566 1.41221 5.40232
endloop
endfacet
facet normal -0.855862 -0.436083 -0.278086
outer loop
vertex 7.43566 1.41221 5.40232
vertex 9.04894 1.69098 -1.58217e-06
vertex 9.19098 1.41221 -1.607e-06
endloop
endfacet
facet normal -0.689151 -0.689153 -0.223919
outer loop
vertex 7.43566 1.41221 5.40232
vertex 9.19098 1.41221 -1.607e-06
vertex 7.61464 1.19098 5.53236
endloop
endfacet
facet normal -0.689151 -0.689153 -0.223919
outer loop
vertex 7.61464 1.19098 5.53236
vertex 9.19098 1.41221 -1.607e-06
vertex 9.41222 1.19098 -1.64568e-06
endloop
endfacet
facet normal -0.449131 -0.881468 -0.145931
outer loop
vertex 7.61464 1.19098 5.53236
vertex 9.41222 1.19098 -1.64568e-06
vertex 7.84017 1.04894 5.69622
endloop
endfacet
facet normal -0.449131 -0.881468 -0.145931
outer loop
vertex 7.84017 1.04894 5.69622
vertex 9.41222 1.19098 -1.64568e-06
vertex 9.69098 1.04894 -1.69443e-06
endloop
endfacet
facet normal -0.156233 -0.986415 -0.050763
outer loop
vertex 7.84017 1.04894 5.69622
vertex 9.69098 1.04894 -1.69443e-06
vertex 8.09017 1 5.87785
endloop
endfacet
facet normal -0.156233 -0.986415 -0.0507631
outer loop
vertex 8.09017 1 5.87785
vertex 9.69098 1.04894 -1.69443e-06
vertex 10 1 -1.74846e-06
endloop
endfacet
facet normal 0.156233 -0.986415 0.0507631
outer loop
vertex 8.09017 1 5.87785
vertex 10 1 -1.74846e-06
vertex 8.34017 1.04894 6.05949
endloop
endfacet
facet normal 0.156233 -0.986415 0.0507631
outer loop
vertex 8.34017 1.04894 6.05949
vertex 10 1 -1.74846e-06
vertex 10.309 1.04894 -1.80249e-06
endloop
endfacet
facet normal 0.449131 -0.881468 0.145931
outer loop
vertex 8.34017 1.04894 6.05949
vertex 10.309 1.04894 -1.80249e-06
vertex 8.5657 1.19098 6.22334
endloop
endfacet
facet normal 0.449131 -0.881468 0.145931
outer loop
vertex 8.5657 1.19098 6.22334
vertex 10.309 1.04894 -1.80249e-06
vertex 10.5878 1.19098 -1.85123e-06
endloop
endfacet
facet normal 0.689151 -0.689153 0.223919
outer loop
vertex 8.5657 1.19098 6.22334
vertex 10.5878 1.19098 -1.85123e-06
vertex 8.74468 1.41221 6.35338
endloop
endfacet
facet normal 0.689151 -0.689153 0.223919
outer loop
vertex 8.74468 1.41221 6.35338
vertex 10.5878 1.19098 -1.85123e-06
vertex 10.809 1.41221 -1.88991e-06
endloop
endfacet
facet normal 0.855862 -0.436082 0.278086
outer loop
vertex 8.74468 1.41221 6.35338
vertex 10.809 1.41221 -1.88991e-06
vertex 8.85959 1.69098 6.43687
endloop
endfacet
facet normal 0.855862 -0.436083 0.278086
outer loop
vertex 8.85959 1.69098 6.43687
vertex 10.809 1.41221 -1.88991e-06
vertex 10.9511 1.69098 -1.91474e-06
endloop
endfacet
facet normal 0.940447 -0.14895 0.30557
outer loop
vertex 8.85959 1.69098 6.43687
vertex 10.9511 1.69098 -1.91474e-06
vertex 8.89919 2 6.46564
endloop
endfacet
facet normal -0.987688 -0.156435 0
outer loop
vertex 11 2 -1.9233e-06
vertex 11 2 0
vertex 10.9511 2.30902 -1.91474e-06
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex 11 2 -1.9233e-06
vertex 10.9511 1.69098 0
vertex 11 2 0
endloop
endfacet
facet normal -0.987688 -0.156435 0
outer loop
vertex 10.9511 2.30902 -1.91474e-06
vertex 11 2 0
vertex 10.9511 2.30902 0
endloop
endfacet
facet normal -0.891007 -0.45399 0
outer loop
vertex 10.9511 2.30902 -1.91474e-06
vertex 10.9511 2.30902 0
vertex 10.809 2.58779 -1.88991e-06
endloop
endfacet
facet normal -0.891007 -0.45399 0
outer loop
vertex 10.809 2.58779 -1.88991e-06
vertex 10.9511 2.30902 0
vertex 10.809 2.58779 0
endloop
endfacet
facet normal -0.707107 -0.707106 0
outer loop
vertex 10.809 2.58779 -1.88991e-06
vertex 10.809 2.58779 0
vertex 10.5878 2.80902 -1.85123e-06
endloop
endfacet
facet normal -0.707107 -0.707106 0
outer loop
vertex 10.5878 2.80902 -1.85123e-06
vertex 10.809 2.58779 0
vertex 10.5878 2.80902 0
endloop
endfacet
facet normal -0.45399 -0.891007 0
outer loop
vertex 10.5878 2.80902 -1.85123e-06
vertex 10.5878 2.80902 0
vertex 10.309 2.95106 -1.80249e-06
endloop
endfacet
facet normal -0.45399 -0.891007 0
outer loop
vertex 10.309 2.95106 -1.80249e-06
vertex 10.5878 2.80902 0
vertex 10.309 2.95106 0
endloop
endfacet
facet normal -0.156434 -0.987688 0
outer loop
vertex 10.309 2.95106 -1.80249e-06
vertex 10.309 2.95106 0
vertex 10 3 -1.74846e-06
endloop
endfacet
facet normal -0.156434 -0.987688 0
outer loop
vertex 10 3 -1.74846e-06
vertex 10.309 2.95106 0
vertex 10 3 0
endloop
endfacet
facet normal 0.156434 -0.987688 0
outer loop
vertex 10 3 -1.74846e-06
vertex 10 3 0
vertex 9.69098 2.95106 -1.69443e-06
endloop
endfacet
facet normal 0.156434 -0.987688 0
outer loop
vertex 9.69098 2.95106 -1.69443e-06
vertex 10 3 0
vertex 9.69098 2.95106 0
endloop
endfacet
facet normal 0.453991 -0.891006 0
outer loop
vertex 9.69098 2.95106 -1.69443e-06
vertex 9.69098 2.95106 0
vertex 9.41222 2.80902 -1.64568e-06
endloop
endfacet
facet normal 0.453991 -0.891006 0
outer loop
vertex 9.41222 2.80902 -1.64568e-06
vertex 9.69098 2.95106 0
vertex 9.41222 2.80902 0
endloop
endfacet
facet normal 0.707106 -0.707108 0
outer loop
vertex 9.41222 2.80902 -1.64568e-06
vertex 9.41222 2.80902 0
vertex 9.19098 2.58779 -1.607e-06
endloop
endfacet
facet normal 0.707106 -0.707108 0
outer loop
vertex 9.19098 2.58779 -1.607e-06
vertex 9.41222 2.80902 0
vertex 9.19098 2.58779 0
endloop
endfacet
facet normal 0.891007 -0.45399 0
outer loop
vertex 9.19098 2.58779 -1.607e-06
vertex 9.19098 2.58779 0
vertex 9.04894 2.30902 -1.58217e-06
endloop
endfacet
facet normal 0.891007 -0.45399 0
outer loop
vertex 9.04894 2.30902 -1.58217e-06
vertex 9.19098 2.58779 0
vertex 9.04894 2.30902 0
endloop
endfacet
facet normal 0.987688 -0.156435 0
outer loop
vertex 9.04894 2.30902 -1.58217e-06
vertex 9.04894 2.30902 0
vertex 9 2 -1.57361e-06
endloop
endfacet
facet normal 0.987688 -0.156435 0
outer loop
vertex 9 2 -1.57361e-06
vertex 9.04894 2.30902 0
vertex 9 2 0
endloop
endfacet
facet normal 0.987688 0.156435 -0
outer loop
vertex 9 2 -1.57361e-06
vertex 9 2 0
vertex 9.04894 1.69098 -1.58217e-06
endloop
endfacet
facet normal 0.987688 0.156435 -0
outer loop
vertex 9.04894 1.69098 -1.58217e-06
vertex 9 2 0
vertex 9.04894 1.69098 0
endloop
endfacet
facet normal 0.891007 0.45399 -0
outer loop
vertex 9.04894 1.69098 -1.58217e-06
vertex 9.04894 1.69098 0
vertex 9.19098 1.41221 -1.607e-06
endloop
endfacet
facet normal 0.891007 0.45399 -0
outer loop
vertex 9.19098 1.41221 -1.607e-06
vertex 9.04894 1.69098 0
vertex 9.19098 1.41221 0
endloop
endfacet
facet normal 0.707106 0.707108 -0
outer loop
vertex 9.19098 1.41221 -1.607e-06
vertex 9.19098 1.41221 0
vertex 9.41222 1.19098 -1.64568e-06
endloop
endfacet
facet normal 0.707106 0.707108 -0
outer loop
vertex 9.41222 1.19098 -1.64568e-06
vertex 9.19098 1.41221 0
vertex 9.41222 1.19098 0
endloop
endfacet
facet normal 0.453991 0.891006 -0
outer loop
vertex 9.41222 1.19098 -1.64568e-06
vertex 9.41222 1.19098 0
vertex 9.69098 1.04894 -1.69443e-06
endloop
endfacet
facet normal 0.453991 0.891006 -0
outer loop
vertex 9.69098 1.04894 -1.69443e-06
vertex 9.41222 1.19098 0
vertex 9.69098 1.04894 0
endloop
endfacet
facet normal 0.156434 0.987688 -0
outer loop
vertex 9.69098 1.04894 -1.69443e-06
vertex 9.69098 1.04894 0
vertex 10 1 -1.74846e-06
endloop
endfacet
facet normal 0.156434 0.987688 -0
outer loop
vertex 10 1 -1.74846e-06
vertex 9.69098 1.04894 0
vertex 10 1 0
endloop
endfacet
facet normal -0.156434 0.987688 0
outer loop
vertex 10 1 -1.74846e-06
vertex 10 1 0
vertex 10.309 1.04894 -1.80249e-06
endloop
endfacet
facet normal -0.156434 0.987688 0
outer loop
vertex 10.309 1.04894 -1.80249e-06
vertex 10 1 0
vertex 10.309 1.04894 0
endloop
endfacet
facet normal -0.453991 0.891006 0
outer loop
vertex 10.309 1.04894 -1.80249e-06
vertex 10.309 1.04894 0
vertex 10.5878 1.19098 -1.85123e-06
endloop
endfacet
facet normal -0.453991 0.891006 0
outer loop
vertex 10.5878 1.19098 -1.85123e-06
vertex 10.309 1.04894 0
vertex 10.5878 1.19098 0
endloop
endfacet
facet normal -0.707106 0.707108 0
outer loop
vertex 10.5878 1.19098 -1.85123e-06
vertex 10.5878 1.19098 0
vertex 10.809 1.41221 -1.88991e-06
endloop
endfacet
facet normal -0.707106 0.707108 0
outer loop
vertex 10.809 1.41221 -1.88991e-06
vertex 10.5878 1.19098 0
vertex 10.809 1.41221 0
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex 10.809 1.41221 -1.88991e-06
vertex 10.809 1.41221 0
vertex 10.9511 1.69098 -1.91474e-06
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex 10.9511 1.69098 -1.91474e-06
vertex 10.809 1.41221 0
vertex 10.9511 1.69098 0
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex 10.9511 1.69098 -1.91474e-06
vertex 10.9511 1.69098 0
vertex 11 2 -1.9233e-06
endloop
endfacet
endsolid fast_trimesh STL file
```

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
facet normal 0.471405 -0.816497 -0.333333
outer loop
vertex 1.41421 8.74228e-08 2
vertex -0.707107 -1.22474 2
vertex 0 2.62268e-07 0
endloop
endfacet
facet normal -2.80979e-08 -4.8667e-08 1
outer loop
vertex 1.41421 8.74228e-08 2
vertex -0.707107 1.22475 2
vertex -0.707107 -1.22474 2
endloop
endfacet
facet normal -0.942809 1.62223e-08 -0.333333
outer loop
vertex -0.707107 -1.22474 2
vertex -0.707107 1.22475 2
vertex 0 2.62268e-07 0
endloop
endfacet
facet normal 0.471405 0.816497 -0.333333
outer loop
vertex -0.707107 1.22475 2
vertex 1.41421 8.74228e-08 2
vertex 0 2.62268e-07 0
endloop
endfacet
endsolid fast_trimesh STL file
```

## sphere

STL is too large to display in the README; see it [here](sphere.stl) instead.
