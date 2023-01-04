# Examples

## simple

```stl
solid fast_trimesh STL file
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
facet normal 0 -1 0
outer loop
vertex -0.5 -0.5 -0.5
vertex 0.5 -0.5 -0.5
vertex 0.5 -0.5 0.5
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 -0.5 -0.5
vertex 0.5 0.5 0.5
vertex 0.5 -0.5 0.5
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 -0.5 -0.5
vertex 0.5 0.5 -0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal 0 1 -0
outer loop
vertex 0.5 0.5 -0.5
vertex -0.5 0.5 0.5
vertex 0.5 0.5 0.5
endloop
endfacet
facet normal 0 1 0
outer loop
vertex 0.5 0.5 -0.5
vertex -0.5 0.5 -0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 0.5 -0.5
vertex -0.5 -0.5 0.5
vertex -0.5 0.5 0.5
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 0.5 -0.5
vertex -0.5 -0.5 -0.5
vertex -0.5 -0.5 0.5
endloop
endfacet
facet normal 0 0 1
outer loop
vertex -0.5 -0.5 0.5
vertex 0.5 0.5 0.5
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
facet normal 0 -0.707107 -0.707107
outer loop
vertex -0.5 0.5 -0.707107
vertex 0.5 0.5 -0.707107
vertex 0.5 -0.207107 0
endloop
endfacet
facet normal 1 0 -0
outer loop
vertex 0.5 0.5 -0.707107
vertex 0.5 0.5 0.707107
vertex 0.5 -0.207107 0
endloop
endfacet
facet normal 1 0 0
outer loop
vertex 0.5 0.5 -0.707107
vertex 0.5 1.20711 0
vertex 0.5 0.5 0.707107
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 0.5 1.20711 0
vertex -0.5 0.5 0.707107
vertex 0.5 0.5 0.707107
endloop
endfacet
facet normal 0 0.707107 0.707107
outer loop
vertex 0.5 1.20711 0
vertex -0.5 1.20711 0
vertex -0.5 0.5 0.707107
endloop
endfacet
facet normal -1 0 0
outer loop
vertex -0.5 1.20711 0
vertex -0.5 -0.207107 0
vertex -0.5 0.5 0.707107
endloop
endfacet
facet normal -1 -0 0
outer loop
vertex -0.5 1.20711 0
vertex -0.5 0.5 -0.707107
vertex -0.5 -0.207107 0
endloop
endfacet
facet normal 0 -0.707107 0.707107
outer loop
vertex -0.5 -0.207107 0
vertex 0.5 0.5 0.707107
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
endsolid fast_trimesh STL file
```

## cylinder

```stl
solid fast_trimesh STL file
facet normal 0 0 -1
outer loop
vertex 0.809017 0.587785 0
vertex 0.951057 0.309017 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.587785 0.809017 0
vertex 0.809017 0.587785 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.309017 0.951057 0
vertex 0.587785 0.809017 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -4.37114e-08 1 0
vertex 0.309017 0.951057 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.309017 0.951056 0
vertex -4.37114e-08 1 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.587785 0.809017 0
vertex -0.309017 0.951056 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.809017 0.587785 0
vertex -0.587785 0.809017 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.951056 0.309017 0
vertex -0.809017 0.587785 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -1 -8.74228e-08 0
vertex -0.951056 0.309017 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.951057 -0.309017 0
vertex -1 -8.74228e-08 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.809017 -0.587785 0
vertex -0.951057 -0.309017 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.587785 -0.809017 0
vertex -0.809017 -0.587785 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.309017 -0.951056 0
vertex -0.587785 -0.809017 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 1.19249e-08 -1 0
vertex -0.309017 -0.951056 0
vertex 1 0 0
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 0.309017 -0.951056 0
vertex 1.19249e-08 -1 0
vertex 1 0 0
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 0.587785 -0.809017 0
vertex 0.309017 -0.951056 0
vertex 1 0 0
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 0.809017 -0.587785 0
vertex 0.587785 -0.809017 0
vertex 1 0 0
endloop
endfacet
facet normal -0 0 -1
outer loop
vertex 0.951057 -0.309017 0
vertex 0.809017 -0.587785 0
vertex 1 0 0
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 0.951057 0.309017 2
vertex 0.809017 0.587785 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 0.809017 0.587785 2
vertex 0.587785 0.809017 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 0.587785 0.809017 2
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 0.309017 0.951057 2
vertex -4.37114e-08 1 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -4.37114e-08 1 2
vertex -0.309017 0.951056 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.309017 0.951056 2
vertex -0.587785 0.809017 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.587785 0.809017 2
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.809017 0.587785 2
vertex -0.951056 0.309017 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.951056 0.309017 2
vertex -1 -8.74228e-08 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -1 -8.74228e-08 2
vertex -0.951057 -0.309017 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.951057 -0.309017 2
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.809017 -0.587785 2
vertex -0.587785 -0.809017 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.587785 -0.809017 2
vertex -0.309017 -0.951056 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex -0.309017 -0.951056 2
vertex 1.19249e-08 -1 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 1.19249e-08 -1 2
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 0.309017 -0.951056 2
vertex 0.587785 -0.809017 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 0.587785 -0.809017 2
vertex 0.809017 -0.587785 2
endloop
endfacet
facet normal 0 0 1
outer loop
vertex 1 0 2
vertex 0.809017 -0.587785 2
vertex 0.951057 -0.309017 2
endloop
endfacet
facet normal 0.987688 0.156434 0
outer loop
vertex 1 0 0
vertex 0.951057 0.309017 0
vertex 0.951057 0.309017 2
endloop
endfacet
facet normal 0.987688 0.156434 -0
outer loop
vertex 1 0 0
vertex 0.951057 0.309017 2
vertex 1 0 2
endloop
endfacet
facet normal 0.891006 0.453991 0
outer loop
vertex 0.951057 0.309017 0
vertex 0.809017 0.587785 0
vertex 0.809017 0.587785 2
endloop
endfacet
facet normal 0.891006 0.453991 -0
outer loop
vertex 0.951057 0.309017 0
vertex 0.809017 0.587785 2
vertex 0.951057 0.309017 2
endloop
endfacet
facet normal -0.951057 -0.309017 0
outer loop
vertex 0.809017 0.587785 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.951057 -0.309017 0
outer loop
vertex 0.809017 0.587785 0
vertex 1 0 2
vertex 0.809017 0.587785 2
endloop
endfacet
facet normal 0.951057 0.309017 0
outer loop
vertex 1 0 0
vertex 0.809017 0.587785 0
vertex 0.809017 0.587785 2
endloop
endfacet
facet normal 0.951057 0.309017 -0
outer loop
vertex 1 0 0
vertex 0.809017 0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal 0.707107 0.707107 0
outer loop
vertex 0.809017 0.587785 0
vertex 0.587785 0.809017 0
vertex 0.587785 0.809017 2
endloop
endfacet
facet normal 0.707107 0.707107 -0
outer loop
vertex 0.809017 0.587785 0
vertex 0.587785 0.809017 2
vertex 0.809017 0.587785 2
endloop
endfacet
facet normal -0.891006 -0.45399 0
outer loop
vertex 0.587785 0.809017 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.891006 -0.45399 0
outer loop
vertex 0.587785 0.809017 0
vertex 1 0 2
vertex 0.587785 0.809017 2
endloop
endfacet
facet normal 0.891006 0.45399 0
outer loop
vertex 1 0 0
vertex 0.587785 0.809017 0
vertex 0.587785 0.809017 2
endloop
endfacet
facet normal 0.891006 0.45399 -0
outer loop
vertex 1 0 0
vertex 0.587785 0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal 0.453991 0.891006 0
outer loop
vertex 0.587785 0.809017 0
vertex 0.309017 0.951057 0
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0.453991 0.891006 -0
outer loop
vertex 0.587785 0.809017 0
vertex 0.309017 0.951057 2
vertex 0.587785 0.809017 2
endloop
endfacet
facet normal -0.809017 -0.587785 0
outer loop
vertex 0.309017 0.951057 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.809017 -0.587785 0
outer loop
vertex 0.309017 0.951057 0
vertex 1 0 2
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0.809017 0.587785 0
outer loop
vertex 1 0 0
vertex 0.309017 0.951057 0
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal 0.809017 0.587785 -0
outer loop
vertex 1 0 0
vertex 0.309017 0.951057 2
vertex 1 0 2
endloop
endfacet
facet normal 0.156434 0.987688 0
outer loop
vertex 0.309017 0.951057 0
vertex -4.37114e-08 1 0
vertex -4.37114e-08 1 2
endloop
endfacet
facet normal 0.156434 0.987688 -0
outer loop
vertex 0.309017 0.951057 0
vertex -4.37114e-08 1 2
vertex 0.309017 0.951057 2
endloop
endfacet
facet normal -0.707107 -0.707107 0
outer loop
vertex -4.37114e-08 1 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.707107 -0.707107 0
outer loop
vertex -4.37114e-08 1 0
vertex 1 0 2
vertex -4.37114e-08 1 2
endloop
endfacet
facet normal 0.707107 0.707107 0
outer loop
vertex 1 0 0
vertex -4.37114e-08 1 0
vertex -4.37114e-08 1 2
endloop
endfacet
facet normal 0.707107 0.707107 -0
outer loop
vertex 1 0 0
vertex -4.37114e-08 1 2
vertex 1 0 2
endloop
endfacet
facet normal -0.156435 0.987688 0
outer loop
vertex -4.37114e-08 1 0
vertex -0.309017 0.951056 0
vertex -0.309017 0.951056 2
endloop
endfacet
facet normal -0.156435 0.987688 0
outer loop
vertex -4.37114e-08 1 0
vertex -0.309017 0.951056 2
vertex -4.37114e-08 1 2
endloop
endfacet
facet normal -0.587785 -0.809017 0
outer loop
vertex -0.309017 0.951056 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.587785 -0.809017 0
outer loop
vertex -0.309017 0.951056 0
vertex 1 0 2
vertex -0.309017 0.951056 2
endloop
endfacet
facet normal 0.587785 0.809017 0
outer loop
vertex 1 0 0
vertex -0.309017 0.951056 0
vertex -0.309017 0.951056 2
endloop
endfacet
facet normal 0.587785 0.809017 -0
outer loop
vertex 1 0 0
vertex -0.309017 0.951056 2
vertex 1 0 2
endloop
endfacet
facet normal -0.453991 0.891007 0
outer loop
vertex -0.309017 0.951056 0
vertex -0.587785 0.809017 0
vertex -0.587785 0.809017 2
endloop
endfacet
facet normal -0.453991 0.891007 0
outer loop
vertex -0.309017 0.951056 0
vertex -0.587785 0.809017 2
vertex -0.309017 0.951056 2
endloop
endfacet
facet normal -0.453991 -0.891007 0
outer loop
vertex -0.587785 0.809017 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.453991 -0.891007 0
outer loop
vertex -0.587785 0.809017 0
vertex 1 0 2
vertex -0.587785 0.809017 2
endloop
endfacet
facet normal 0.453991 0.891007 0
outer loop
vertex 1 0 0
vertex -0.587785 0.809017 0
vertex -0.587785 0.809017 2
endloop
endfacet
facet normal 0.453991 0.891007 -0
outer loop
vertex 1 0 0
vertex -0.587785 0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex -0.587785 0.809017 0
vertex -0.809017 0.587785 0
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex -0.587785 0.809017 0
vertex -0.809017 0.587785 2
vertex -0.587785 0.809017 2
endloop
endfacet
facet normal -0.309017 -0.951056 0
outer loop
vertex -0.809017 0.587785 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.309017 -0.951056 0
outer loop
vertex -0.809017 0.587785 0
vertex 1 0 2
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal 0.309017 0.951056 0
outer loop
vertex 1 0 0
vertex -0.809017 0.587785 0
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal 0.309017 0.951056 -0
outer loop
vertex 1 0 0
vertex -0.809017 0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex -0.809017 0.587785 0
vertex -0.951056 0.309017 0
vertex -0.951056 0.309017 2
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex -0.809017 0.587785 0
vertex -0.951056 0.309017 2
vertex -0.809017 0.587785 2
endloop
endfacet
facet normal -0.156434 -0.987688 0
outer loop
vertex -0.951056 0.309017 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal -0.156434 -0.987688 0
outer loop
vertex -0.951056 0.309017 0
vertex 1 0 2
vertex -0.951056 0.309017 2
endloop
endfacet
facet normal 0.156434 0.987688 0
outer loop
vertex 1 0 0
vertex -0.951056 0.309017 0
vertex -0.951056 0.309017 2
endloop
endfacet
facet normal 0.156434 0.987688 -0
outer loop
vertex 1 0 0
vertex -0.951056 0.309017 2
vertex 1 0 2
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex -0.951056 0.309017 0
vertex -1 -8.74228e-08 0
vertex -1 -8.74228e-08 2
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex -0.951056 0.309017 0
vertex -1 -8.74228e-08 2
vertex -0.951056 0.309017 2
endloop
endfacet
facet normal 4.37114e-08 -1 0
outer loop
vertex -1 -8.74228e-08 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 4.37114e-08 -1 0
outer loop
vertex -1 -8.74228e-08 0
vertex 1 0 2
vertex -1 -8.74228e-08 2
endloop
endfacet
facet normal -4.37114e-08 1 0
outer loop
vertex 1 0 0
vertex -1 -8.74228e-08 0
vertex -1 -8.74228e-08 2
endloop
endfacet
facet normal -4.37114e-08 1 0
outer loop
vertex 1 0 0
vertex -1 -8.74228e-08 2
vertex 1 0 2
endloop
endfacet
facet normal -0.987688 -0.156434 0
outer loop
vertex -1 -8.74228e-08 0
vertex -0.951057 -0.309017 0
vertex -0.951057 -0.309017 2
endloop
endfacet
facet normal -0.987688 -0.156434 0
outer loop
vertex -1 -8.74228e-08 0
vertex -0.951057 -0.309017 2
vertex -1 -8.74228e-08 2
endloop
endfacet
facet normal 0.156434 -0.987688 0
outer loop
vertex -0.951057 -0.309017 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.156434 -0.987688 0
outer loop
vertex -0.951057 -0.309017 0
vertex 1 0 2
vertex -0.951057 -0.309017 2
endloop
endfacet
facet normal -0.156434 0.987688 0
outer loop
vertex 1 0 0
vertex -0.951057 -0.309017 0
vertex -0.951057 -0.309017 2
endloop
endfacet
facet normal -0.156434 0.987688 0
outer loop
vertex 1 0 0
vertex -0.951057 -0.309017 2
vertex 1 0 2
endloop
endfacet
facet normal -0.891007 -0.453991 0
outer loop
vertex -0.951057 -0.309017 0
vertex -0.809017 -0.587785 0
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal -0.891007 -0.453991 0
outer loop
vertex -0.951057 -0.309017 0
vertex -0.809017 -0.587785 2
vertex -0.951057 -0.309017 2
endloop
endfacet
facet normal 0.309017 -0.951057 0
outer loop
vertex -0.809017 -0.587785 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.309017 -0.951057 0
outer loop
vertex -0.809017 -0.587785 0
vertex 1 0 2
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal -0.309017 0.951057 0
outer loop
vertex 1 0 0
vertex -0.809017 -0.587785 0
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal -0.309017 0.951057 0
outer loop
vertex 1 0 0
vertex -0.809017 -0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal -0.707107 -0.707107 0
outer loop
vertex -0.809017 -0.587785 0
vertex -0.587785 -0.809017 0
vertex -0.587785 -0.809017 2
endloop
endfacet
facet normal -0.707107 -0.707107 0
outer loop
vertex -0.809017 -0.587785 0
vertex -0.587785 -0.809017 2
vertex -0.809017 -0.587785 2
endloop
endfacet
facet normal 0.453991 -0.891006 0
outer loop
vertex -0.587785 -0.809017 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.453991 -0.891006 0
outer loop
vertex -0.587785 -0.809017 0
vertex 1 0 2
vertex -0.587785 -0.809017 2
endloop
endfacet
facet normal -0.453991 0.891006 0
outer loop
vertex 1 0 0
vertex -0.587785 -0.809017 0
vertex -0.587785 -0.809017 2
endloop
endfacet
facet normal -0.453991 0.891006 0
outer loop
vertex 1 0 0
vertex -0.587785 -0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal -0.45399 -0.891007 0
outer loop
vertex -0.587785 -0.809017 0
vertex -0.309017 -0.951056 0
vertex -0.309017 -0.951056 2
endloop
endfacet
facet normal -0.45399 -0.891007 0
outer loop
vertex -0.587785 -0.809017 0
vertex -0.309017 -0.951056 2
vertex -0.587785 -0.809017 2
endloop
endfacet
facet normal 0.587785 -0.809017 0
outer loop
vertex -0.309017 -0.951056 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.587785 -0.809017 0
outer loop
vertex -0.309017 -0.951056 0
vertex 1 0 2
vertex -0.309017 -0.951056 2
endloop
endfacet
facet normal -0.587785 0.809017 0
outer loop
vertex 1 0 0
vertex -0.309017 -0.951056 0
vertex -0.309017 -0.951056 2
endloop
endfacet
facet normal -0.587785 0.809017 0
outer loop
vertex 1 0 0
vertex -0.309017 -0.951056 2
vertex 1 0 2
endloop
endfacet
facet normal -0.156435 -0.987688 0
outer loop
vertex -0.309017 -0.951056 0
vertex 1.19249e-08 -1 0
vertex 1.19249e-08 -1 2
endloop
endfacet
facet normal -0.156435 -0.987688 0
outer loop
vertex -0.309017 -0.951056 0
vertex 1.19249e-08 -1 2
vertex -0.309017 -0.951056 2
endloop
endfacet
facet normal 0.707107 -0.707107 0
outer loop
vertex 1.19249e-08 -1 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.707107 -0.707107 0
outer loop
vertex 1.19249e-08 -1 0
vertex 1 0 2
vertex 1.19249e-08 -1 2
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex 1 0 0
vertex 1.19249e-08 -1 0
vertex 1.19249e-08 -1 2
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex 1 0 0
vertex 1.19249e-08 -1 2
vertex 1 0 2
endloop
endfacet
facet normal 0.156435 -0.987688 0
outer loop
vertex 1.19249e-08 -1 0
vertex 0.309017 -0.951056 0
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal 0.156435 -0.987688 0
outer loop
vertex 1.19249e-08 -1 0
vertex 0.309017 -0.951056 2
vertex 1.19249e-08 -1 2
endloop
endfacet
facet normal 0.809017 -0.587785 0
outer loop
vertex 0.309017 -0.951056 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.809017 -0.587785 0
outer loop
vertex 0.309017 -0.951056 0
vertex 1 0 2
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal -0.809017 0.587785 0
outer loop
vertex 1 0 0
vertex 0.309017 -0.951056 0
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal -0.809017 0.587785 0
outer loop
vertex 1 0 0
vertex 0.309017 -0.951056 2
vertex 1 0 2
endloop
endfacet
facet normal 0.45399 -0.891006 0
outer loop
vertex 0.309017 -0.951056 0
vertex 0.587785 -0.809017 0
vertex 0.587785 -0.809017 2
endloop
endfacet
facet normal 0.45399 -0.891006 0
outer loop
vertex 0.309017 -0.951056 0
vertex 0.587785 -0.809017 2
vertex 0.309017 -0.951056 2
endloop
endfacet
facet normal 0.891006 -0.453991 0
outer loop
vertex 0.587785 -0.809017 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.891006 -0.453991 0
outer loop
vertex 0.587785 -0.809017 0
vertex 1 0 2
vertex 0.587785 -0.809017 2
endloop
endfacet
facet normal -0.891006 0.453991 0
outer loop
vertex 1 0 0
vertex 0.587785 -0.809017 0
vertex 0.587785 -0.809017 2
endloop
endfacet
facet normal -0.891006 0.453991 0
outer loop
vertex 1 0 0
vertex 0.587785 -0.809017 2
vertex 1 0 2
endloop
endfacet
facet normal 0.707107 -0.707107 0
outer loop
vertex 0.587785 -0.809017 0
vertex 0.809017 -0.587785 0
vertex 0.809017 -0.587785 2
endloop
endfacet
facet normal 0.707107 -0.707107 0
outer loop
vertex 0.587785 -0.809017 0
vertex 0.809017 -0.587785 2
vertex 0.587785 -0.809017 2
endloop
endfacet
facet normal 0.951056 -0.309017 0
outer loop
vertex 0.809017 -0.587785 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.951056 -0.309017 0
outer loop
vertex 0.809017 -0.587785 0
vertex 1 0 2
vertex 0.809017 -0.587785 2
endloop
endfacet
facet normal -0.951056 0.309017 0
outer loop
vertex 1 0 0
vertex 0.809017 -0.587785 0
vertex 0.809017 -0.587785 2
endloop
endfacet
facet normal -0.951056 0.309017 0
outer loop
vertex 1 0 0
vertex 0.809017 -0.587785 2
vertex 1 0 2
endloop
endfacet
facet normal 0.891007 -0.453991 0
outer loop
vertex 0.809017 -0.587785 0
vertex 0.951057 -0.309017 0
vertex 0.951057 -0.309017 2
endloop
endfacet
facet normal 0.891007 -0.453991 0
outer loop
vertex 0.809017 -0.587785 0
vertex 0.951057 -0.309017 2
vertex 0.809017 -0.587785 2
endloop
endfacet
facet normal 0.987688 -0.156434 0
outer loop
vertex 0.951057 -0.309017 0
vertex 1 0 0
vertex 1 0 2
endloop
endfacet
facet normal 0.987688 -0.156434 0
outer loop
vertex 0.951057 -0.309017 0
vertex 1 0 2
vertex 0.951057 -0.309017 2
endloop
endfacet
endsolid fast_trimesh STL file
```
