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
facet normal 0.987519 0.156408 0.0185121
outer loop
vertex 1 2 0
vertex 0.951057 2.30902 0
vertex 1 1.94474 0.466891
endloop
endfacet
facet normal 0.987519 -0.156408 -0.0185121
outer loop
vertex 1 2 0
vertex 1 1.94474 0.466891
vertex 0.951057 1.64426 0.394752
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.951057 2.30902 0
vertex 1 2 0
vertex 0.809017 2.58779 0
endloop
endfacet
facet normal 0.889723 0.453337 0.053656
outer loop
vertex 0.951057 2.30902 0
vertex 0.809017 2.58779 0
vertex 0.951057 2.24522 0.539029
endloop
endfacet
facet normal 0.987519 0.156408 0.0185121
outer loop
vertex 0.951057 2.30902 0
vertex 0.951057 2.24522 0.539029
vertex 1 1.94474 0.466891
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.809017 2.58779 0
vertex 1 2 0
vertex 0.587785 2.80902 0
endloop
endfacet
facet normal 0.704643 0.704643 0.0834001
outer loop
vertex 0.809017 2.58779 0
vertex 0.587785 2.80902 0
vertex 0.809017 2.51628 0.604106
endloop
endfacet
facet normal 0.889723 0.453336 0.053656
outer loop
vertex 0.809017 2.58779 0
vertex 0.809017 2.51628 0.604106
vertex 0.951057 2.24522 0.539029
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.587785 2.80902 0
vertex 1 2 0
vertex 0.309017 2.95106 0
endloop
endfacet
facet normal 0.451487 0.886093 0.104876
outer loop
vertex 0.587785 2.80902 0
vertex 0.309017 2.95106 0
vertex 0.587785 2.7314 0.655752
endloop
endfacet
facet normal 0.704643 0.704643 0.0834
outer loop
vertex 0.587785 2.80902 0
vertex 0.587785 2.7314 0.655752
vertex 0.809017 2.51628 0.604106
endloop
endfacet
facet normal -0 -0 -1
outer loop
vertex 0.309017 2.95106 0
vertex 1 2 0
vertex -4.37114e-08 3 0
endloop
endfacet
facet normal 0.155377 0.981008 0.11611
outer loop
vertex 0.309017 2.95106 0
vertex -4.37114e-08 3 0
vertex 0.309017 2.86952 0.68891
endloop
endfacet
facet normal 0.451487 0.886093 0.104876
outer loop
vertex 0.309017 2.95106 0
vertex 0.309017 2.86952 0.68891
vertex 0.587785 2.7314 0.655752
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -4.37114e-08 3 0
vertex 1 2 0
vertex -0.309017 2.95106 0
endloop
endfacet
facet normal -0.155376 0.981008 0.11611
outer loop
vertex -4.37114e-08 3 0
vertex -0.309017 2.95106 0
vertex -4.37114e-08 2.91711 0.700336
endloop
endfacet
facet normal 0.155377 0.981008 0.11611
outer loop
vertex -4.37114e-08 3 0
vertex -4.37114e-08 2.91711 0.700336
vertex 0.309017 2.86952 0.68891
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.309017 2.95106 0
vertex 1 2 0
vertex -0.587785 2.80902 0
endloop
endfacet
facet normal -0.451487 0.886093 0.104876
outer loop
vertex -0.309017 2.95106 0
vertex -0.587785 2.80902 0
vertex -0.309017 2.86952 0.68891
endloop
endfacet
facet normal -0.155377 0.981008 0.11611
outer loop
vertex -0.309017 2.95106 0
vertex -0.309017 2.86952 0.68891
vertex -4.37114e-08 2.91711 0.700336
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.587785 2.80902 0
vertex 1 2 0
vertex -0.809017 2.58779 0
endloop
endfacet
facet normal -0.704643 0.704644 0.0834001
outer loop
vertex -0.587785 2.80902 0
vertex -0.809017 2.58779 0
vertex -0.587785 2.7314 0.655752
endloop
endfacet
facet normal -0.451487 0.886093 0.104876
outer loop
vertex -0.587785 2.80902 0
vertex -0.587785 2.7314 0.655752
vertex -0.309017 2.86952 0.68891
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.809017 2.58779 0
vertex 1 2 0
vertex -0.951056 2.30902 0
endloop
endfacet
facet normal -0.889723 0.453336 0.0536559
outer loop
vertex -0.809017 2.58779 0
vertex -0.951056 2.30902 0
vertex -0.809017 2.51628 0.604106
endloop
endfacet
facet normal -0.704643 0.704643 0.0834001
outer loop
vertex -0.809017 2.58779 0
vertex -0.809017 2.51628 0.604106
vertex -0.587785 2.7314 0.655752
endloop
endfacet
facet normal 0 -0 -1
outer loop
vertex -0.951056 2.30902 0
vertex 1 2 0
vertex -1 2 0
endloop
endfacet
facet normal -0.987519 0.156408 0.0185121
outer loop
vertex -0.951056 2.30902 0
vertex -1 2 0
vertex -0.951056 2.24522 0.539029
endloop
endfacet
facet normal -0.889723 0.453336 0.053656
outer loop
vertex -0.951056 2.30902 0
vertex -0.951056 2.24522 0.539029
vertex -0.809017 2.51628 0.604106
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -1 2 0
vertex 1 2 0
vertex -0.951057 1.69098 0
endloop
endfacet
facet normal -0.987519 -0.156408 -0.0185121
outer loop
vertex -1 2 0
vertex -0.951057 1.69098 0
vertex -1 1.94474 0.466891
endloop
endfacet
facet normal -0.987519 0.156408 0.0185121
outer loop
vertex -1 2 0
vertex -1 1.94474 0.466891
vertex -0.951056 2.24522 0.539029
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.951057 1.69098 0
vertex 1 2 0
vertex -0.809017 1.41221 0
endloop
endfacet
facet normal -0.889723 -0.453337 -0.053656
outer loop
vertex -0.951057 1.69098 0
vertex -0.809017 1.41221 0
vertex -0.951057 1.64426 0.394752
endloop
endfacet
facet normal -0.987519 -0.156408 -0.0185121
outer loop
vertex -0.951057 1.69098 0
vertex -0.951057 1.64426 0.394752
vertex -1 1.94474 0.466891
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.809017 1.41221 0
vertex 1 2 0
vertex -0.587785 1.19098 0
endloop
endfacet
facet normal -0.704643 -0.704643 -0.0834
outer loop
vertex -0.809017 1.41221 0
vertex -0.587785 1.19098 0
vertex -0.809017 1.3732 0.329675
endloop
endfacet
facet normal -0.889723 -0.453337 -0.0536559
outer loop
vertex -0.809017 1.41221 0
vertex -0.809017 1.3732 0.329675
vertex -0.951057 1.64426 0.394752
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.587785 1.19098 0
vertex 1 2 0
vertex -0.309017 1.04894 0
endloop
endfacet
facet normal -0.451487 -0.886093 -0.104876
outer loop
vertex -0.587785 1.19098 0
vertex -0.309017 1.04894 0
vertex -0.587785 1.15808 0.278029
endloop
endfacet
facet normal -0.704643 -0.704643 -0.0834002
outer loop
vertex -0.587785 1.19098 0
vertex -0.587785 1.15808 0.278029
vertex -0.809017 1.3732 0.329675
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex -0.309017 1.04894 0
vertex 1 2 0
vertex 1.19249e-08 1 0
endloop
endfacet
facet normal -0.155376 -0.981008 -0.11611
outer loop
vertex -0.309017 1.04894 0
vertex 1.19249e-08 1 0
vertex -0.309017 1.01996 0.244871
endloop
endfacet
facet normal -0.451487 -0.886093 -0.104876
outer loop
vertex -0.309017 1.04894 0
vertex -0.309017 1.01996 0.244871
vertex -0.587785 1.15808 0.278029
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 1.19249e-08 1 0
vertex 1 2 0
vertex 0.309017 1.04894 0
endloop
endfacet
facet normal 0.155376 -0.981008 -0.11611
outer loop
vertex 1.19249e-08 1 0
vertex 0.309017 1.04894 0
vertex 1.19249e-08 0.97237 0.233445
endloop
endfacet
facet normal -0.155376 -0.981008 -0.11611
outer loop
vertex 1.19249e-08 1 0
vertex 1.19249e-08 0.97237 0.233445
vertex -0.309017 1.01996 0.244871
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.309017 1.04894 0
vertex 1 2 0
vertex 0.587785 1.19098 0
endloop
endfacet
facet normal 0.451487 -0.886093 -0.104876
outer loop
vertex 0.309017 1.04894 0
vertex 0.587785 1.19098 0
vertex 0.309017 1.01996 0.244871
endloop
endfacet
facet normal 0.155376 -0.981008 -0.11611
outer loop
vertex 0.309017 1.04894 0
vertex 0.309017 1.01996 0.244871
vertex 1.19249e-08 0.97237 0.233445
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.587785 1.19098 0
vertex 1 2 0
vertex 0.809017 1.41221 0
endloop
endfacet
facet normal 0.704643 -0.704643 -0.0834002
outer loop
vertex 0.587785 1.19098 0
vertex 0.809017 1.41221 0
vertex 0.587785 1.15808 0.278029
endloop
endfacet
facet normal 0.451487 -0.886093 -0.104876
outer loop
vertex 0.587785 1.19098 0
vertex 0.587785 1.15808 0.278029
vertex 0.309017 1.01996 0.244871
endloop
endfacet
facet normal 0 0 -1
outer loop
vertex 0.809017 1.41221 0
vertex 1 2 0
vertex 0.951057 1.69098 0
endloop
endfacet
facet normal 0.889723 -0.453337 -0.0536559
outer loop
vertex 0.809017 1.41221 0
vertex 0.951057 1.69098 0
vertex 0.809017 1.3732 0.329675
endloop
endfacet
facet normal 0.704644 -0.704643 -0.0834
outer loop
vertex 0.809017 1.41221 0
vertex 0.809017 1.3732 0.329675
vertex 0.587785 1.15808 0.278029
endloop
endfacet
facet normal 0.987519 -0.156408 -0.0185121
outer loop
vertex 0.951057 1.69098 0
vertex 1 2 0
vertex 0.951057 1.64426 0.394752
endloop
endfacet
facet normal 0.889723 -0.453337 -0.053656
outer loop
vertex 0.951057 1.69098 0
vertex 0.951057 1.64426 0.394752
vertex 0.809017 1.3732 0.329675
endloop
endfacet
facet normal 0.987519 0.147765 0.0545132
outer loop
vertex 1 1.94474 0.466891
vertex 0.951057 2.24522 0.539029
vertex 1 1.78201 0.907981
endloop
endfacet
facet normal 0.987519 -0.147764 -0.0545132
outer loop
vertex 1 1.94474 0.466891
vertex 1 1.78201 0.907981
vertex 0.951057 1.50668 0.76769
endloop
endfacet
facet normal 0.889723 0.428285 0.158003
outer loop
vertex 0.951057 2.24522 0.539029
vertex 0.809017 2.51628 0.604106
vertex 0.951057 2.05735 1.04827
endloop
endfacet
facet normal 0.987519 0.147765 0.0545132
outer loop
vertex 0.951057 2.24522 0.539029
vertex 0.951057 2.05735 1.04827
vertex 1 1.78201 0.907981
endloop
endfacet
facet normal 0.704643 0.665705 0.245591
outer loop
vertex 0.809017 2.51628 0.604106
vertex 0.587785 2.7314 0.655752
vertex 0.809017 2.30573 1.17483
endloop
endfacet
facet normal 0.889723 0.428285 0.158003
outer loop
vertex 0.809017 2.51628 0.604106
vertex 0.809017 2.30573 1.17483
vertex 0.951057 2.05735 1.04827
endloop
endfacet
facet normal 0.451487 0.837127 0.308833
outer loop
vertex 0.587785 2.7314 0.655752
vertex 0.309017 2.86952 0.68891
vertex 0.587785 2.50285 1.27527
endloop
endfacet
facet normal 0.704643 0.665705 0.245591
outer loop
vertex 0.587785 2.7314 0.655752
vertex 0.587785 2.50285 1.27527
vertex 0.809017 2.30573 1.17483
endloop
endfacet
facet normal 0.155376 0.926797 0.341914
outer loop
vertex 0.309017 2.86952 0.68891
vertex -4.37114e-08 2.91711 0.700336
vertex 0.309017 2.62941 1.33975
endloop
endfacet
facet normal 0.451487 0.837127 0.308833
outer loop
vertex 0.309017 2.86952 0.68891
vertex 0.309017 2.62941 1.33975
vertex 0.587785 2.50285 1.27527
endloop
endfacet
facet normal -0.155376 0.926797 0.341913
outer loop
vertex -4.37114e-08 2.91711 0.700336
vertex -0.309017 2.86952 0.68891
vertex -4.37114e-08 2.67302 1.36197
endloop
endfacet
facet normal 0.155377 0.926797 0.341913
outer loop
vertex -4.37114e-08 2.91711 0.700336
vertex -4.37114e-08 2.67302 1.36197
vertex 0.309017 2.62941 1.33975
endloop
endfacet
facet normal -0.451487 0.837127 0.308833
outer loop
vertex -0.309017 2.86952 0.68891
vertex -0.587785 2.7314 0.655752
vertex -0.309017 2.62941 1.33975
endloop
endfacet
facet normal -0.155377 0.926797 0.341914
outer loop
vertex -0.309017 2.86952 0.68891
vertex -0.309017 2.62941 1.33975
vertex -4.37114e-08 2.67302 1.36197
endloop
endfacet
facet normal -0.704643 0.665705 0.245591
outer loop
vertex -0.587785 2.7314 0.655752
vertex -0.809017 2.51628 0.604106
vertex -0.587785 2.50285 1.27527
endloop
endfacet
facet normal -0.451487 0.837127 0.308833
outer loop
vertex -0.587785 2.7314 0.655752
vertex -0.587785 2.50285 1.27527
vertex -0.309017 2.62941 1.33975
endloop
endfacet
facet normal -0.889723 0.428285 0.158003
outer loop
vertex -0.809017 2.51628 0.604106
vertex -0.951056 2.24522 0.539029
vertex -0.809017 2.30573 1.17483
endloop
endfacet
facet normal -0.704643 0.665705 0.245591
outer loop
vertex -0.809017 2.51628 0.604106
vertex -0.809017 2.30573 1.17483
vertex -0.587785 2.50285 1.27527
endloop
endfacet
facet normal -0.987519 0.147765 0.0545132
outer loop
vertex -0.951056 2.24522 0.539029
vertex -1 1.94474 0.466891
vertex -0.951056 2.05735 1.04827
endloop
endfacet
facet normal -0.889723 0.428285 0.158003
outer loop
vertex -0.951056 2.24522 0.539029
vertex -0.951056 2.05735 1.04827
vertex -0.809017 2.30573 1.17483
endloop
endfacet
facet normal -0.987519 -0.147765 -0.0545132
outer loop
vertex -1 1.94474 0.466891
vertex -0.951057 1.64426 0.394752
vertex -1 1.78201 0.907981
endloop
endfacet
facet normal -0.987519 0.147765 0.0545132
outer loop
vertex -1 1.94474 0.466891
vertex -1 1.78201 0.907981
vertex -0.951056 2.05735 1.04827
endloop
endfacet
facet normal -0.889723 -0.428285 -0.158003
outer loop
vertex -0.951057 1.64426 0.394752
vertex -0.809017 1.3732 0.329675
vertex -0.951057 1.50668 0.76769
endloop
endfacet
facet normal -0.987519 -0.147765 -0.0545132
outer loop
vertex -0.951057 1.64426 0.394752
vertex -0.951057 1.50668 0.76769
vertex -1 1.78201 0.907981
endloop
endfacet
facet normal -0.704643 -0.665705 -0.245591
outer loop
vertex -0.809017 1.3732 0.329675
vertex -0.587785 1.15808 0.278029
vertex -0.809017 1.25829 0.641132
endloop
endfacet
facet normal -0.889723 -0.428285 -0.158003
outer loop
vertex -0.809017 1.3732 0.329675
vertex -0.809017 1.25829 0.641132
vertex -0.951057 1.50668 0.76769
endloop
endfacet
facet normal -0.451487 -0.837127 -0.308833
outer loop
vertex -0.587785 1.15808 0.278029
vertex -0.309017 1.01996 0.244871
vertex -0.587785 1.06117 0.540695
endloop
endfacet
facet normal -0.704643 -0.665705 -0.245591
outer loop
vertex -0.587785 1.15808 0.278029
vertex -0.587785 1.06117 0.540695
vertex -0.809017 1.25829 0.641132
endloop
endfacet
facet normal -0.155376 -0.926797 -0.341913
outer loop
vertex -0.309017 1.01996 0.244871
vertex 1.19249e-08 0.97237 0.233445
vertex -0.309017 0.934616 0.47621
endloop
endfacet
facet normal -0.451487 -0.837128 -0.308833
outer loop
vertex -0.309017 1.01996 0.244871
vertex -0.309017 0.934616 0.47621
vertex -0.587785 1.06117 0.540695
endloop
endfacet
facet normal 0.155376 -0.926797 -0.341914
outer loop
vertex 1.19249e-08 0.97237 0.233445
vertex 0.309017 1.01996 0.244871
vertex 1.19249e-08 0.891007 0.453991
endloop
endfacet
facet normal -0.155377 -0.926797 -0.341913
outer loop
vertex 1.19249e-08 0.97237 0.233445
vertex 1.19249e-08 0.891007 0.453991
vertex -0.309017 0.934616 0.47621
endloop
endfacet
facet normal 0.451487 -0.837127 -0.308832
outer loop
vertex 0.309017 1.01996 0.244871
vertex 0.587785 1.15808 0.278029
vertex 0.309017 0.934616 0.47621
endloop
endfacet
facet normal 0.155377 -0.926797 -0.341913
outer loop
vertex 0.309017 1.01996 0.244871
vertex 0.309017 0.934616 0.47621
vertex 1.19249e-08 0.891007 0.453991
endloop
endfacet
facet normal 0.704643 -0.665704 -0.245591
outer loop
vertex 0.587785 1.15808 0.278029
vertex 0.809017 1.3732 0.329675
vertex 0.587785 1.06117 0.540695
endloop
endfacet
facet normal 0.451487 -0.837127 -0.308833
outer loop
vertex 0.587785 1.15808 0.278029
vertex 0.587785 1.06117 0.540695
vertex 0.309017 0.934616 0.47621
endloop
endfacet
facet normal 0.889723 -0.428285 -0.158003
outer loop
vertex 0.809017 1.3732 0.329675
vertex 0.951057 1.64426 0.394752
vertex 0.809017 1.25829 0.641132
endloop
endfacet
facet normal 0.704643 -0.665704 -0.245591
outer loop
vertex 0.809017 1.3732 0.329675
vertex 0.809017 1.25829 0.641132
vertex 0.587785 1.06117 0.540695
endloop
endfacet
facet normal 0.987519 -0.147764 -0.0545132
outer loop
vertex 0.951057 1.64426 0.394752
vertex 1 1.94474 0.466891
vertex 0.951057 1.50668 0.76769
endloop
endfacet
facet normal 0.889723 -0.428285 -0.158003
outer loop
vertex 0.951057 1.64426 0.394752
vertex 0.951057 1.50668 0.76769
vertex 0.809017 1.25829 0.641132
endloop
endfacet
facet normal 0.987519 0.130956 0.087502
outer loop
vertex 1 1.78201 0.907981
vertex 0.951057 2.05735 1.04827
vertex 1 1.52081 1.2989
endloop
endfacet
facet normal 0.987519 -0.130956 -0.087502
outer loop
vertex 1 1.78201 0.907981
vertex 1 1.52081 1.2989
vertex 0.951057 1.28583 1.09821
endloop
endfacet
facet normal 0.889723 0.379567 0.253618
outer loop
vertex 0.951057 2.05735 1.04827
vertex 0.809017 2.30573 1.17483
vertex 0.951057 1.75579 1.49959
endloop
endfacet
facet normal 0.987519 0.130956 0.087502
outer loop
vertex 0.951057 2.05735 1.04827
vertex 0.951057 1.75579 1.49959
vertex 1 1.52081 1.2989
endloop
endfacet
facet normal 0.704643 0.589979 0.394211
outer loop
vertex 0.809017 2.30573 1.17483
vertex 0.587785 2.50285 1.27527
vertex 0.809017 1.96777 1.68063
endloop
endfacet
facet normal 0.889723 0.379566 0.253618
outer loop
vertex 0.809017 2.30573 1.17483
vertex 0.809017 1.96777 1.68063
vertex 0.951057 1.75579 1.49959
endloop
endfacet
facet normal 0.451487 0.741902 0.495723
outer loop
vertex 0.587785 2.50285 1.27527
vertex 0.309017 2.62941 1.33975
vertex 0.587785 2.13599 1.82431
endloop
endfacet
facet normal 0.704643 0.589979 0.394211
outer loop
vertex 0.587785 2.50285 1.27527
vertex 0.587785 2.13599 1.82431
vertex 0.809017 1.96777 1.68063
endloop
endfacet
facet normal 0.155377 0.821372 0.548823
outer loop
vertex 0.309017 2.62941 1.33975
vertex -4.37114e-08 2.67302 1.36197
vertex 0.309017 2.244 1.91656
endloop
endfacet
facet normal 0.451487 0.741902 0.495723
outer loop
vertex 0.309017 2.62941 1.33975
vertex 0.309017 2.244 1.91656
vertex 0.587785 2.13599 1.82431
endloop
endfacet
facet normal -0.155377 0.821371 0.548823
outer loop
vertex -4.37114e-08 2.67302 1.36197
vertex -0.309017 2.62941 1.33975
vertex -4.37114e-08 2.28122 1.94834
endloop
endfacet
facet normal 0.155377 0.821371 0.548823
outer loop
vertex -4.37114e-08 2.67302 1.36197
vertex -4.37114e-08 2.28122 1.94834
vertex 0.309017 2.244 1.91656
endloop
endfacet
facet normal -0.451487 0.741902 0.495723
outer loop
vertex -0.309017 2.62941 1.33975
vertex -0.587785 2.50285 1.27527
vertex -0.309017 2.244 1.91656
endloop
endfacet
facet normal -0.155377 0.821372 0.548823
outer loop
vertex -0.309017 2.62941 1.33975
vertex -0.309017 2.244 1.91656
vertex -4.37114e-08 2.28122 1.94834
endloop
endfacet
facet normal -0.704643 0.589979 0.394211
outer loop
vertex -0.587785 2.50285 1.27527
vertex -0.809017 2.30573 1.17483
vertex -0.587785 2.13599 1.82431
endloop
endfacet
facet normal -0.451487 0.741902 0.495723
outer loop
vertex -0.587785 2.50285 1.27527
vertex -0.587785 2.13599 1.82431
vertex -0.309017 2.244 1.91656
endloop
endfacet
facet normal -0.889723 0.379566 0.253618
outer loop
vertex -0.809017 2.30573 1.17483
vertex -0.951056 2.05735 1.04827
vertex -0.809017 1.96777 1.68063
endloop
endfacet
facet normal -0.704643 0.589979 0.394211
outer loop
vertex -0.809017 2.30573 1.17483
vertex -0.809017 1.96777 1.68063
vertex -0.587785 2.13599 1.82431
endloop
endfacet
facet normal -0.987519 0.130956 0.087502
outer loop
vertex -0.951056 2.05735 1.04827
vertex -1 1.78201 0.907981
vertex -0.951056 1.75579 1.49959
endloop
endfacet
facet normal -0.889723 0.379566 0.253618
outer loop
vertex -0.951056 2.05735 1.04827
vertex -0.951056 1.75579 1.49959
vertex -0.809017 1.96777 1.68063
endloop
endfacet
facet normal -0.987519 -0.130956 -0.087502
outer loop
vertex -1 1.78201 0.907981
vertex -0.951057 1.50668 0.76769
vertex -1 1.52081 1.2989
endloop
endfacet
facet normal -0.987519 0.130956 0.087502
outer loop
vertex -1 1.78201 0.907981
vertex -1 1.52081 1.2989
vertex -0.951056 1.75579 1.49959
endloop
endfacet
facet normal -0.889723 -0.379566 -0.253618
outer loop
vertex -0.951057 1.50668 0.76769
vertex -0.809017 1.25829 0.641132
vertex -0.951057 1.28583 1.09821
endloop
endfacet
facet normal -0.987519 -0.130956 -0.087502
outer loop
vertex -0.951057 1.50668 0.76769
vertex -0.951057 1.28583 1.09821
vertex -1 1.52081 1.2989
endloop
endfacet
facet normal -0.704643 -0.589979 -0.394211
outer loop
vertex -0.809017 1.25829 0.641132
vertex -0.587785 1.06117 0.540695
vertex -0.809017 1.07386 0.91716
endloop
endfacet
facet normal -0.889723 -0.379567 -0.253618
outer loop
vertex -0.809017 1.25829 0.641132
vertex -0.809017 1.07386 0.91716
vertex -0.951057 1.28583 1.09821
endloop
endfacet
facet normal -0.451487 -0.741902 -0.495723
outer loop
vertex -0.587785 1.06117 0.540695
vertex -0.309017 0.934616 0.47621
vertex -0.587785 0.90563 0.773481
endloop
endfacet
facet normal -0.704643 -0.589979 -0.394211
outer loop
vertex -0.587785 1.06117 0.540695
vertex -0.587785 0.90563 0.773481
vertex -0.809017 1.07386 0.91716
endloop
endfacet
facet normal -0.155377 -0.821372 -0.548823
outer loop
vertex -0.309017 0.934616 0.47621
vertex 1.19249e-08 0.891007 0.453991
vertex -0.309017 0.797623 0.681234
endloop
endfacet
facet normal -0.451487 -0.741902 -0.495723
outer loop
vertex -0.309017 0.934616 0.47621
vertex -0.309017 0.797623 0.681234
vertex -0.587785 0.90563 0.773481
endloop
endfacet
facet normal 0.155377 -0.821372 -0.548823
outer loop
vertex 1.19249e-08 0.891007 0.453991
vertex 0.309017 0.934616 0.47621
vertex 1.19249e-08 0.760406 0.649448
endloop
endfacet
facet normal -0.155376 -0.821372 -0.548823
outer loop
vertex 1.19249e-08 0.891007 0.453991
vertex 1.19249e-08 0.760406 0.649448
vertex -0.309017 0.797623 0.681234
endloop
endfacet
facet normal 0.451487 -0.741902 -0.495723
outer loop
vertex 0.309017 0.934616 0.47621
vertex 0.587785 1.06117 0.540695
vertex 0.309017 0.797623 0.681234
endloop
endfacet
facet normal 0.155376 -0.821372 -0.548823
outer loop
vertex 0.309017 0.934616 0.47621
vertex 0.309017 0.797623 0.681234
vertex 1.19249e-08 0.760406 0.649448
endloop
endfacet
facet normal 0.704643 -0.589979 -0.394211
outer loop
vertex 0.587785 1.06117 0.540695
vertex 0.809017 1.25829 0.641132
vertex 0.587785 0.90563 0.773481
endloop
endfacet
facet normal 0.451487 -0.741902 -0.495723
outer loop
vertex 0.587785 1.06117 0.540695
vertex 0.587785 0.90563 0.773481
vertex 0.309017 0.797623 0.681234
endloop
endfacet
facet normal 0.889723 -0.379567 -0.253618
outer loop
vertex 0.809017 1.25829 0.641132
vertex 0.951057 1.50668 0.76769
vertex 0.809017 1.07386 0.91716
endloop
endfacet
facet normal 0.704643 -0.589979 -0.394211
outer loop
vertex 0.809017 1.25829 0.641132
vertex 0.809017 1.07386 0.91716
vertex 0.587785 0.90563 0.773481
endloop
endfacet
facet normal 0.987519 -0.130956 -0.0875019
outer loop
vertex 0.951057 1.50668 0.76769
vertex 1 1.78201 0.907981
vertex 0.951057 1.28583 1.09821
endloop
endfacet
facet normal 0.889723 -0.379567 -0.253618
outer loop
vertex 0.951057 1.50668 0.76769
vertex 0.951057 1.28583 1.09821
vertex 0.809017 1.07386 0.91716
endloop
endfacet
facet normal 0.987519 0.106911 0.115655
outer loop
vertex 1 1.52081 1.2989
vertex 0.951057 1.75579 1.49959
vertex 1 1.17557 1.61803
endloop
endfacet
facet normal 0.987519 -0.106911 -0.115655
outer loop
vertex 1 1.52081 1.2989
vertex 1 1.17557 1.61803
vertex 0.951057 0.993935 1.36803
endloop
endfacet
facet normal 0.889723 0.309873 0.335219
outer loop
vertex 0.951057 1.75579 1.49959
vertex 0.809017 1.96777 1.68063
vertex 0.951057 1.35721 1.86803
endloop
endfacet
facet normal 0.987519 0.106911 0.115655
outer loop
vertex 0.951057 1.75579 1.49959
vertex 0.951057 1.35721 1.86803
vertex 1 1.17557 1.61803
endloop
endfacet
facet normal 0.704643 0.481651 0.521047
outer loop
vertex 0.809017 1.96777 1.68063
vertex 0.587785 2.13599 1.82431
vertex 0.809017 1.52106 2.09356
endloop
endfacet
facet normal 0.889723 0.309873 0.335219
outer loop
vertex 0.809017 1.96777 1.68063
vertex 0.809017 1.52106 2.09356
vertex 0.951057 1.35721 1.86803
endloop
endfacet
facet normal 0.451487 0.605679 0.65522
outer loop
vertex 0.587785 2.13599 1.82431
vertex 0.309017 2.244 1.91656
vertex 0.587785 1.6511 2.27254
endloop
endfacet
facet normal 0.704643 0.481651 0.521047
outer loop
vertex 0.587785 2.13599 1.82431
vertex 0.587785 1.6511 2.27254
vertex 0.809017 1.52106 2.09356
endloop
endfacet
facet normal 0.155377 0.670557 0.725404
outer loop
vertex 0.309017 2.244 1.91656
vertex -4.37114e-08 2.28122 1.94834
vertex 0.309017 1.73459 2.38745
endloop
endfacet
facet normal 0.451487 0.605679 0.655219
outer loop
vertex 0.309017 2.244 1.91656
vertex 0.309017 1.73459 2.38745
vertex 0.587785 1.6511 2.27254
endloop
endfacet
facet normal -0.155377 0.670557 0.725404
outer loop
vertex -4.37114e-08 2.28122 1.94834
vertex -0.309017 2.244 1.91656
vertex -4.37114e-08 1.76336 2.42705
endloop
endfacet
facet normal 0.155376 0.670557 0.725404
outer loop
vertex -4.37114e-08 2.28122 1.94834
vertex -4.37114e-08 1.76336 2.42705
vertex 0.309017 1.73459 2.38745
endloop
endfacet
facet normal -0.451487 0.605679 0.655219
outer loop
vertex -0.309017 2.244 1.91656
vertex -0.587785 2.13599 1.82431
vertex -0.309017 1.73459 2.38745
endloop
endfacet
facet normal -0.155376 0.670557 0.725404
outer loop
vertex -0.309017 2.244 1.91656
vertex -0.309017 1.73459 2.38745
vertex -4.37114e-08 1.76336 2.42705
endloop
endfacet
facet normal -0.704643 0.481651 0.521047
outer loop
vertex -0.587785 2.13599 1.82431
vertex -0.809017 1.96777 1.68063
vertex -0.587785 1.6511 2.27254
endloop
endfacet
facet normal -0.451487 0.605679 0.655219
outer loop
vertex -0.587785 2.13599 1.82431
vertex -0.587785 1.6511 2.27254
vertex -0.309017 1.73459 2.38745
endloop
endfacet
facet normal -0.889723 0.309873 0.335218
outer loop
vertex -0.809017 1.96777 1.68063
vertex -0.951056 1.75579 1.49959
vertex -0.809017 1.52106 2.09356
endloop
endfacet
facet normal -0.704643 0.481651 0.521047
outer loop
vertex -0.809017 1.96777 1.68063
vertex -0.809017 1.52106 2.09356
vertex -0.587785 1.6511 2.27254
endloop
endfacet
facet normal -0.987519 0.106911 0.115655
outer loop
vertex -0.951056 1.75579 1.49959
vertex -1 1.52081 1.2989
vertex -0.951056 1.35721 1.86803
endloop
endfacet
facet normal -0.889723 0.309873 0.335218
outer loop
vertex -0.951056 1.75579 1.49959
vertex -0.951056 1.35721 1.86803
vertex -0.809017 1.52106 2.09356
endloop
endfacet
facet normal -0.987519 -0.106911 -0.115655
outer loop
vertex -1 1.52081 1.2989
vertex -0.951057 1.28583 1.09821
vertex -1 1.17557 1.61803
endloop
endfacet
facet normal -0.987519 0.106911 0.115655
outer loop
vertex -1 1.52081 1.2989
vertex -1 1.17557 1.61803
vertex -0.951056 1.35721 1.86803
endloop
endfacet
facet normal -0.889723 -0.309873 -0.335219
outer loop
vertex -0.951057 1.28583 1.09821
vertex -0.809017 1.07386 0.91716
vertex -0.951057 0.993935 1.36803
endloop
endfacet
facet normal -0.987519 -0.106911 -0.115655
outer loop
vertex -0.951057 1.28583 1.09821
vertex -0.951057 0.993935 1.36803
vertex -1 1.17557 1.61803
endloop
endfacet
facet normal -0.704643 -0.481651 -0.521047
outer loop
vertex -0.809017 1.07386 0.91716
vertex -0.587785 0.90563 0.773481
vertex -0.809017 0.830079 1.14251
endloop
endfacet
facet normal -0.889723 -0.309873 -0.335219
outer loop
vertex -0.809017 1.07386 0.91716
vertex -0.809017 0.830079 1.14251
vertex -0.951057 0.993935 1.36803
endloop
endfacet
facet normal -0.451487 -0.605679 -0.65522
outer loop
vertex -0.587785 0.90563 0.773481
vertex -0.309017 0.797623 0.681234
vertex -0.587785 0.700042 0.963525
endloop
endfacet
facet normal -0.704643 -0.481651 -0.521047
outer loop
vertex -0.587785 0.90563 0.773481
vertex -0.587785 0.700042 0.963525
vertex -0.809017 0.830079 1.14251
endloop
endfacet
facet normal -0.155376 -0.670557 -0.725404
outer loop
vertex -0.309017 0.797623 0.681234
vertex 1.19249e-08 0.760406 0.649448
vertex -0.309017 0.616554 0.848613
endloop
endfacet
facet normal -0.451487 -0.605679 -0.65522
outer loop
vertex -0.309017 0.797623 0.681234
vertex -0.309017 0.616554 0.848613
vertex -0.587785 0.700042 0.963525
endloop
endfacet
facet normal 0.155376 -0.670557 -0.725404
outer loop
vertex 1.19249e-08 0.760406 0.649448
vertex 0.309017 0.797623 0.681234
vertex 1.19249e-08 0.587785 0.809017
endloop
endfacet
facet normal -0.155377 -0.670557 -0.725404
outer loop
vertex 1.19249e-08 0.760406 0.649448
vertex 1.19249e-08 0.587785 0.809017
vertex -0.309017 0.616554 0.848613
endloop
endfacet
facet normal 0.451487 -0.605679 -0.65522
outer loop
vertex 0.309017 0.797623 0.681234
vertex 0.587785 0.90563 0.773481
vertex 0.309017 0.616554 0.848613
endloop
endfacet
facet normal 0.155376 -0.670557 -0.725404
outer loop
vertex 0.309017 0.797623 0.681234
vertex 0.309017 0.616554 0.848613
vertex 1.19249e-08 0.587785 0.809017
endloop
endfacet
facet normal 0.704643 -0.481651 -0.521047
outer loop
vertex 0.587785 0.90563 0.773481
vertex 0.809017 1.07386 0.91716
vertex 0.587785 0.700042 0.963525
endloop
endfacet
facet normal 0.451487 -0.605679 -0.65522
outer loop
vertex 0.587785 0.90563 0.773481
vertex 0.587785 0.700042 0.963525
vertex 0.309017 0.616554 0.848613
endloop
endfacet
facet normal 0.889723 -0.309873 -0.335219
outer loop
vertex 0.809017 1.07386 0.91716
vertex 0.951057 1.28583 1.09821
vertex 0.809017 0.830079 1.14251
endloop
endfacet
facet normal 0.704643 -0.481651 -0.521047
outer loop
vertex 0.809017 1.07386 0.91716
vertex 0.809017 0.830079 1.14251
vertex 0.587785 0.700042 0.963525
endloop
endfacet
facet normal 0.987519 -0.106911 -0.115655
outer loop
vertex 0.951057 1.28583 1.09821
vertex 1 1.52081 1.2989
vertex 0.951057 0.993935 1.36803
endloop
endfacet
facet normal 0.889723 -0.309873 -0.335219
outer loop
vertex 0.951057 1.28583 1.09821
vertex 0.951057 0.993935 1.36803
vertex 0.809017 0.830079 1.14251
endloop
endfacet
facet normal 0.987519 0.0769575 0.137418
outer loop
vertex 1 1.17557 1.61803
vertex 0.951057 1.35721 1.86803
vertex 1 0.765367 1.84776
endloop
endfacet
facet normal 0.987519 -0.0769575 -0.137418
outer loop
vertex 1 1.17557 1.61803
vertex 1 0.765367 1.84776
vertex 0.951057 0.647111 1.56226
endloop
endfacet
facet normal 0.889723 0.223056 0.398295
outer loop
vertex 0.951057 1.35721 1.86803
vertex 0.809017 1.52106 2.09356
vertex 0.951057 0.883623 2.13325
endloop
endfacet
facet normal 0.987519 0.0769575 0.137418
outer loop
vertex 0.951057 1.35721 1.86803
vertex 0.951057 0.883623 2.13325
vertex 1 0.765367 1.84776
endloop
endfacet
facet normal 0.704643 0.346707 0.61909
outer loop
vertex 0.809017 1.52106 2.09356
vertex 0.587785 1.6511 2.27254
vertex 0.809017 0.990303 2.3908
endloop
endfacet
facet normal 0.889723 0.223056 0.398295
outer loop
vertex 0.809017 1.52106 2.09356
vertex 0.809017 0.990303 2.3908
vertex 0.951057 0.883623 2.13325
endloop
endfacet
facet normal 0.451487 0.435986 0.778509
outer loop
vertex 0.587785 1.6511 2.27254
vertex 0.309017 1.73459 2.38745
vertex 0.587785 1.07496 2.59519
endloop
endfacet
facet normal 0.704643 0.346707 0.61909
outer loop
vertex 0.587785 1.6511 2.27254
vertex 0.587785 1.07496 2.59519
vertex 0.809017 0.990303 2.3908
endloop
endfacet
facet normal 0.155376 0.482687 0.8619
outer loop
vertex 0.309017 1.73459 2.38745
vertex -4.37114e-08 1.76336 2.42705
vertex 0.309017 1.12932 2.72642
endloop
endfacet
facet normal 0.451487 0.435986 0.778509
outer loop
vertex 0.309017 1.73459 2.38745
vertex 0.309017 1.12932 2.72642
vertex 0.587785 1.07496 2.59519
endloop
endfacet
facet normal -0.155376 0.482687 0.8619
outer loop
vertex -4.37114e-08 1.76336 2.42705
vertex -0.309017 1.73459 2.38745
vertex -4.37114e-08 1.14805 2.77164
endloop
endfacet
facet normal 0.155376 0.482687 0.8619
outer loop
vertex -4.37114e-08 1.76336 2.42705
vertex -4.37114e-08 1.14805 2.77164
vertex 0.309017 1.12932 2.72642
endloop
endfacet
facet normal -0.451487 0.435986 0.778509
outer loop
vertex -0.309017 1.73459 2.38745
vertex -0.587785 1.6511 2.27254
vertex -0.309017 1.12932 2.72642
endloop
endfacet
facet normal -0.155376 0.482687 0.8619
outer loop
vertex -0.309017 1.73459 2.38745
vertex -0.309017 1.12932 2.72642
vertex -4.37114e-08 1.14805 2.77164
endloop
endfacet
facet normal -0.704643 0.346707 0.61909
outer loop
vertex -0.587785 1.6511 2.27254
vertex -0.809017 1.52106 2.09356
vertex -0.587785 1.07496 2.59519
endloop
endfacet
facet normal -0.451487 0.435986 0.778509
outer loop
vertex -0.587785 1.6511 2.27254
vertex -0.587785 1.07496 2.59519
vertex -0.309017 1.12932 2.72642
endloop
endfacet
facet normal -0.889723 0.223056 0.398295
outer loop
vertex -0.809017 1.52106 2.09356
vertex -0.951056 1.35721 1.86803
vertex -0.809017 0.990303 2.3908
endloop
endfacet
facet normal -0.704643 0.346707 0.61909
outer loop
vertex -0.809017 1.52106 2.09356
vertex -0.809017 0.990303 2.3908
vertex -0.587785 1.07496 2.59519
endloop
endfacet
facet normal -0.987519 0.0769575 0.137418
outer loop
vertex -0.951056 1.35721 1.86803
vertex -1 1.17557 1.61803
vertex -0.951056 0.883623 2.13325
endloop
endfacet
facet normal -0.889723 0.223056 0.398295
outer loop
vertex -0.951056 1.35721 1.86803
vertex -0.951056 0.883623 2.13325
vertex -0.809017 0.990303 2.3908
endloop
endfacet
facet normal -0.987519 -0.0769575 -0.137418
outer loop
vertex -1 1.17557 1.61803
vertex -0.951057 0.993935 1.36803
vertex -1 0.765367 1.84776
endloop
endfacet
facet normal -0.987519 0.0769576 0.137418
outer loop
vertex -1 1.17557 1.61803
vertex -1 0.765367 1.84776
vertex -0.951056 0.883623 2.13325
endloop
endfacet
facet normal -0.889723 -0.223056 -0.398295
outer loop
vertex -0.951057 0.993935 1.36803
vertex -0.809017 0.830079 1.14251
vertex -0.951057 0.647111 1.56226
endloop
endfacet
facet normal -0.987519 -0.0769575 -0.137418
outer loop
vertex -0.951057 0.993935 1.36803
vertex -0.951057 0.647111 1.56226
vertex -1 0.765367 1.84776
endloop
endfacet
facet normal -0.704643 -0.346707 -0.61909
outer loop
vertex -0.809017 0.830079 1.14251
vertex -0.587785 0.700042 0.963525
vertex -0.809017 0.540431 1.30472
endloop
endfacet
facet normal -0.889723 -0.223056 -0.398295
outer loop
vertex -0.809017 0.830079 1.14251
vertex -0.809017 0.540431 1.30472
vertex -0.951057 0.647111 1.56226
endloop
endfacet
facet normal -0.451487 -0.435986 -0.778509
outer loop
vertex -0.587785 0.700042 0.963525
vertex -0.309017 0.616554 0.848613
vertex -0.587785 0.455769 1.10032
endloop
endfacet
facet normal -0.704643 -0.346707 -0.61909
outer loop
vertex -0.587785 0.700042 0.963525
vertex -0.587785 0.455769 1.10032
vertex -0.809017 0.540431 1.30472
endloop
endfacet
facet normal -0.155376 -0.482687 -0.8619
outer loop
vertex -0.309017 0.616554 0.848613
vertex 1.19249e-08 0.587785 0.809017
vertex -0.309017 0.401413 0.969097
endloop
endfacet
facet normal -0.451487 -0.435986 -0.778509
outer loop
vertex -0.309017 0.616554 0.848613
vertex -0.309017 0.401413 0.969097
vertex -0.587785 0.455769 1.10032
endloop
endfacet
facet normal 0.155376 -0.482687 -0.8619
outer loop
vertex 1.19249e-08 0.587785 0.809017
vertex 0.309017 0.616554 0.848613
vertex 1.19249e-08 0.382683 0.92388
endloop
endfacet
facet normal -0.155376 -0.482687 -0.8619
outer loop
vertex 1.19249e-08 0.587785 0.809017
vertex 1.19249e-08 0.382683 0.92388
vertex -0.309017 0.401413 0.969097
endloop
endfacet
facet normal 0.451487 -0.435986 -0.778509
outer loop
vertex 0.309017 0.616554 0.848613
vertex 0.587785 0.700042 0.963525
vertex 0.309017 0.401413 0.969097
endloop
endfacet
facet normal 0.155376 -0.482687 -0.8619
outer loop
vertex 0.309017 0.616554 0.848613
vertex 0.309017 0.401413 0.969097
vertex 1.19249e-08 0.382683 0.92388
endloop
endfacet
facet normal 0.704643 -0.346707 -0.61909
outer loop
vertex 0.587785 0.700042 0.963525
vertex 0.809017 0.830079 1.14251
vertex 0.587785 0.455769 1.10032
endloop
endfacet
facet normal 0.451487 -0.435986 -0.778509
outer loop
vertex 0.587785 0.700042 0.963525
vertex 0.587785 0.455769 1.10032
vertex 0.309017 0.401413 0.969097
endloop
endfacet
facet normal 0.889723 -0.223056 -0.398295
outer loop
vertex 0.809017 0.830079 1.14251
vertex 0.951057 0.993935 1.36803
vertex 0.809017 0.540431 1.30472
endloop
endfacet
facet normal 0.704643 -0.346707 -0.61909
outer loop
vertex 0.809017 0.830079 1.14251
vertex 0.809017 0.540431 1.30472
vertex 0.587785 0.455769 1.10032
endloop
endfacet
facet normal 0.987519 -0.0769575 -0.137418
outer loop
vertex 0.951057 0.993935 1.36803
vertex 1 1.17557 1.61803
vertex 0.951057 0.647111 1.56226
endloop
endfacet
facet normal 0.889723 -0.223056 -0.398295
outer loop
vertex 0.951057 0.993935 1.36803
vertex 0.951057 0.647111 1.56226
vertex 0.809017 0.540431 1.30472
endloop
endfacet
facet normal 0.987519 0.0427517 0.151586
outer loop
vertex 1 0.765367 1.84776
vertex 0.951057 0.883623 2.13325
vertex 1 0.312869 1.97538
endloop
endfacet
facet normal 0.987519 -0.0427517 -0.151586
outer loop
vertex 1 0.765367 1.84776
vertex 1 0.312869 1.97538
vertex 0.951057 0.264528 1.67016
endloop
endfacet
facet normal 0.889723 0.123913 0.439362
outer loop
vertex 0.951057 0.883623 2.13325
vertex 0.809017 0.990303 2.3908
vertex 0.951057 0.36121 2.28059
endloop
endfacet
facet normal 0.987519 0.0427517 0.151586
outer loop
vertex 0.951057 0.883623 2.13325
vertex 0.951057 0.36121 2.28059
vertex 1 0.312869 1.97538
endloop
endfacet
facet normal 0.704643 0.192604 0.682921
outer loop
vertex 0.809017 0.990303 2.3908
vertex 0.587785 1.07496 2.59519
vertex 0.809017 0.404819 2.55593
endloop
endfacet
facet normal 0.889723 0.123913 0.439361
outer loop
vertex 0.809017 0.990303 2.3908
vertex 0.809017 0.404819 2.55593
vertex 0.951057 0.36121 2.28059
endloop
endfacet
facet normal 0.451487 0.242201 0.858777
outer loop
vertex 0.587785 1.07496 2.59519
vertex 0.309017 1.12932 2.72642
vertex 0.587785 0.439427 2.77443
endloop
endfacet
facet normal 0.704643 0.192604 0.682921
outer loop
vertex 0.587785 1.07496 2.59519
vertex 0.587785 0.439427 2.77443
vertex 0.809017 0.404819 2.55593
endloop
endfacet
facet normal 0.155376 0.268144 0.950767
outer loop
vertex 0.309017 1.12932 2.72642
vertex -4.37114e-08 1.14805 2.77164
vertex 0.309017 0.461647 2.91472
endloop
endfacet
facet normal 0.451487 0.2422 0.858777
outer loop
vertex 0.309017 1.12932 2.72642
vertex 0.309017 0.461647 2.91472
vertex 0.587785 0.439427 2.77443
endloop
endfacet
facet normal -0.155376 0.268144 0.950766
outer loop
vertex -4.37114e-08 1.14805 2.77164
vertex -0.309017 1.12932 2.72642
vertex -4.37114e-08 0.469303 2.96307
endloop
endfacet
facet normal 0.155377 0.268144 0.950766
outer loop
vertex -4.37114e-08 1.14805 2.77164
vertex -4.37114e-08 0.469303 2.96307
vertex 0.309017 0.461647 2.91472
endloop
endfacet
facet normal -0.451487 0.2422 0.858777
outer loop
vertex -0.309017 1.12932 2.72642
vertex -0.587785 1.07496 2.59519
vertex -0.309017 0.461647 2.91472
endloop
endfacet
facet normal -0.155377 0.268144 0.950766
outer loop
vertex -0.309017 1.12932 2.72642
vertex -0.309017 0.461647 2.91472
vertex -4.37114e-08 0.469303 2.96307
endloop
endfacet
facet normal -0.704643 0.192604 0.682921
outer loop
vertex -0.587785 1.07496 2.59519
vertex -0.809017 0.990303 2.3908
vertex -0.587785 0.439427 2.77443
endloop
endfacet
facet normal -0.451487 0.242201 0.858777
outer loop
vertex -0.587785 1.07496 2.59519
vertex -0.587785 0.439427 2.77443
vertex -0.309017 0.461647 2.91472
endloop
endfacet
facet normal -0.889723 0.123913 0.439361
outer loop
vertex -0.809017 0.990303 2.3908
vertex -0.951056 0.883623 2.13325
vertex -0.809017 0.404819 2.55593
endloop
endfacet
facet normal -0.704643 0.192604 0.682921
outer loop
vertex -0.809017 0.990303 2.3908
vertex -0.809017 0.404819 2.55593
vertex -0.587785 0.439427 2.77443
endloop
endfacet
facet normal -0.987519 0.0427518 0.151586
outer loop
vertex -0.951056 0.883623 2.13325
vertex -1 0.765367 1.84776
vertex -0.951056 0.36121 2.28059
endloop
endfacet
facet normal -0.889723 0.123913 0.439361
outer loop
vertex -0.951056 0.883623 2.13325
vertex -0.951056 0.36121 2.28059
vertex -0.809017 0.404819 2.55593
endloop
endfacet
facet normal -0.987519 -0.0427517 -0.151586
outer loop
vertex -1 0.765367 1.84776
vertex -0.951057 0.647111 1.56226
vertex -1 0.312869 1.97538
endloop
endfacet
facet normal -0.987519 0.0427518 0.151586
outer loop
vertex -1 0.765367 1.84776
vertex -1 0.312869 1.97538
vertex -0.951056 0.36121 2.28059
endloop
endfacet
facet normal -0.889723 -0.123913 -0.439362
outer loop
vertex -0.951057 0.647111 1.56226
vertex -0.809017 0.540431 1.30472
vertex -0.951057 0.264528 1.67016
endloop
endfacet
facet normal -0.987519 -0.0427517 -0.151586
outer loop
vertex -0.951057 0.647111 1.56226
vertex -0.951057 0.264528 1.67016
vertex -1 0.312869 1.97538
endloop
endfacet
facet normal -0.704643 -0.192604 -0.682921
outer loop
vertex -0.809017 0.540431 1.30472
vertex -0.587785 0.455769 1.10032
vertex -0.809017 0.220919 1.39483
endloop
endfacet
facet normal -0.889723 -0.123913 -0.439362
outer loop
vertex -0.809017 0.540431 1.30472
vertex -0.809017 0.220919 1.39483
vertex -0.951057 0.264528 1.67016
endloop
endfacet
facet normal -0.451487 -0.2422 -0.858777
outer loop
vertex -0.587785 0.455769 1.10032
vertex -0.309017 0.401413 0.969097
vertex -0.587785 0.186311 1.17632
endloop
endfacet
facet normal -0.704643 -0.192604 -0.682921
outer loop
vertex -0.587785 0.455769 1.10032
vertex -0.587785 0.186311 1.17632
vertex -0.809017 0.220919 1.39483
endloop
endfacet
facet normal -0.155377 -0.268144 -0.950766
outer loop
vertex -0.309017 0.401413 0.969097
vertex 1.19249e-08 0.382683 0.92388
vertex -0.309017 0.164091 1.03603
endloop
endfacet
facet normal -0.451487 -0.242201 -0.858778
outer loop
vertex -0.309017 0.401413 0.969097
vertex -0.309017 0.164091 1.03603
vertex -0.587785 0.186311 1.17632
endloop
endfacet
facet normal 0.155376 -0.268144 -0.950766
outer loop
vertex 1.19249e-08 0.382683 0.92388
vertex 0.309017 0.401413 0.969097
vertex 1.19249e-08 0.156434 0.987688
endloop
endfacet
facet normal -0.155377 -0.268144 -0.950766
outer loop
vertex 1.19249e-08 0.382683 0.92388
vertex 1.19249e-08 0.156434 0.987688
vertex -0.309017 0.164091 1.03603
endloop
endfacet
facet normal 0.451487 -0.242201 -0.858777
outer loop
vertex 0.309017 0.401413 0.969097
vertex 0.587785 0.455769 1.10032
vertex 0.309017 0.164091 1.03603
endloop
endfacet
facet normal 0.155377 -0.268144 -0.950767
outer loop
vertex 0.309017 0.401413 0.969097
vertex 0.309017 0.164091 1.03603
vertex 1.19249e-08 0.156434 0.987688
endloop
endfacet
facet normal 0.704643 -0.192604 -0.682921
outer loop
vertex 0.587785 0.455769 1.10032
vertex 0.809017 0.540431 1.30472
vertex 0.587785 0.186311 1.17632
endloop
endfacet
facet normal 0.451487 -0.2422 -0.858778
outer loop
vertex 0.587785 0.455769 1.10032
vertex 0.587785 0.186311 1.17632
vertex 0.309017 0.164091 1.03603
endloop
endfacet
facet normal 0.889723 -0.123913 -0.439362
outer loop
vertex 0.809017 0.540431 1.30472
vertex 0.951057 0.647111 1.56226
vertex 0.809017 0.220919 1.39483
endloop
endfacet
facet normal 0.704643 -0.192604 -0.682921
outer loop
vertex 0.809017 0.540431 1.30472
vertex 0.809017 0.220919 1.39483
vertex 0.587785 0.186311 1.17632
endloop
endfacet
facet normal 0.987519 -0.0427517 -0.151586
outer loop
vertex 0.951057 0.647111 1.56226
vertex 1 0.765367 1.84776
vertex 0.951057 0.264528 1.67016
endloop
endfacet
facet normal 0.889723 -0.123913 -0.439362
outer loop
vertex 0.951057 0.647111 1.56226
vertex 0.951057 0.264528 1.67016
vertex 0.809017 0.220919 1.39483
endloop
endfacet
facet normal 0.987519 0.00618336 0.157378
outer loop
vertex 1 0.312869 1.97538
vertex 0.951057 0.36121 2.28059
vertex 1 -0.156918 1.99383
endloop
endfacet
facet normal 0.987519 -0.00618336 -0.157378
outer loop
vertex 1 0.312869 1.97538
vertex 1 -0.156918 1.99383
vertex 0.951057 -0.132673 1.68577
endloop
endfacet
facet normal 0.889723 0.0179221 0.456149
outer loop
vertex 0.951057 0.36121 2.28059
vertex 0.809017 0.404819 2.55593
vertex 0.951057 -0.181164 2.3019
endloop
endfacet
facet normal 0.987519 0.00618338 0.157378
outer loop
vertex 0.951057 0.36121 2.28059
vertex 0.951057 -0.181164 2.3019
vertex 1 -0.156918 1.99383
endloop
endfacet
facet normal 0.704643 0.0278572 0.709015
outer loop
vertex 0.809017 0.404819 2.55593
vertex 0.587785 0.439427 2.77443
vertex 0.809017 -0.203035 2.57981
endloop
endfacet
facet normal 0.889723 0.0179221 0.456149
outer loop
vertex 0.809017 0.404819 2.55593
vertex 0.809017 -0.203035 2.57981
vertex 0.951057 -0.181164 2.3019
endloop
endfacet
facet normal 0.451487 0.0350304 0.89159
outer loop
vertex 0.587785 0.439427 2.77443
vertex 0.309017 0.461647 2.91472
vertex 0.587785 -0.220393 2.80036
endloop
endfacet
facet normal 0.704643 0.0278571 0.709015
outer loop
vertex 0.587785 0.439427 2.77443
vertex 0.587785 -0.220393 2.80036
vertex 0.809017 -0.203035 2.57981
endloop
endfacet
facet normal 0.155377 0.038783 0.987094
outer loop
vertex 0.309017 0.461647 2.91472
vertex -4.37114e-08 0.469303 2.96307
vertex 0.309017 -0.231537 2.94196
endloop
endfacet
facet normal 0.451487 0.0350306 0.89159
outer loop
vertex 0.309017 0.461647 2.91472
vertex 0.309017 -0.231537 2.94196
vertex 0.587785 -0.220393 2.80036
endloop
endfacet
facet normal -0.155377 0.0387828 0.987094
outer loop
vertex -4.37114e-08 0.469303 2.96307
vertex -0.309017 0.461647 2.91472
vertex -4.37114e-08 -0.235378 2.99075
endloop
endfacet
facet normal 0.155376 0.0387828 0.987094
outer loop
vertex -4.37114e-08 0.469303 2.96307
vertex -4.37114e-08 -0.235378 2.99075
vertex 0.309017 -0.231537 2.94196
endloop
endfacet
facet normal -0.451487 0.0350306 0.89159
outer loop
vertex -0.309017 0.461647 2.91472
vertex -0.587785 0.439427 2.77443
vertex -0.309017 -0.231537 2.94196
endloop
endfacet
facet normal -0.155376 0.038783 0.987094
outer loop
vertex -0.309017 0.461647 2.91472
vertex -0.309017 -0.231537 2.94196
vertex -4.37114e-08 -0.235378 2.99075
endloop
endfacet
facet normal -0.704643 0.0278571 0.709015
outer loop
vertex -0.587785 0.439427 2.77443
vertex -0.809017 0.404819 2.55593
vertex -0.587785 -0.220393 2.80036
endloop
endfacet
facet normal -0.451487 0.0350304 0.89159
outer loop
vertex -0.587785 0.439427 2.77443
vertex -0.587785 -0.220393 2.80036
vertex -0.309017 -0.231537 2.94196
endloop
endfacet
facet normal -0.889723 0.0179221 0.456148
outer loop
vertex -0.809017 0.404819 2.55593
vertex -0.951056 0.36121 2.28059
vertex -0.809017 -0.203035 2.57981
endloop
endfacet
facet normal -0.704643 0.0278572 0.709015
outer loop
vertex -0.809017 0.404819 2.55593
vertex -0.809017 -0.203035 2.57981
vertex -0.587785 -0.220393 2.80036
endloop
endfacet
facet normal -0.987519 0.00618338 0.157378
outer loop
vertex -0.951056 0.36121 2.28059
vertex -1 0.312869 1.97538
vertex -0.951056 -0.181164 2.3019
endloop
endfacet
facet normal -0.889723 0.0179221 0.456148
outer loop
vertex -0.951056 0.36121 2.28059
vertex -0.951056 -0.181164 2.3019
vertex -0.809017 -0.203035 2.57981
endloop
endfacet
facet normal -0.987519 -0.00618336 -0.157378
outer loop
vertex -1 0.312869 1.97538
vertex -0.951057 0.264528 1.67016
vertex -1 -0.156918 1.99383
endloop
endfacet
facet normal -0.987519 0.00618336 0.157378
outer loop
vertex -1 0.312869 1.97538
vertex -1 -0.156918 1.99383
vertex -0.951056 -0.181164 2.3019
endloop
endfacet
facet normal -0.889723 -0.0179221 -0.456149
outer loop
vertex -0.951057 0.264528 1.67016
vertex -0.809017 0.220919 1.39483
vertex -0.951057 -0.132673 1.68577
endloop
endfacet
facet normal -0.987519 -0.00618338 -0.157378
outer loop
vertex -0.951057 0.264528 1.67016
vertex -0.951057 -0.132673 1.68577
vertex -1 -0.156918 1.99383
endloop
endfacet
facet normal -0.704643 -0.0278571 -0.709015
outer loop
vertex -0.809017 0.220919 1.39483
vertex -0.587785 0.186311 1.17632
vertex -0.809017 -0.110801 1.40786
endloop
endfacet
facet normal -0.889723 -0.0179221 -0.456149
outer loop
vertex -0.809017 0.220919 1.39483
vertex -0.809017 -0.110801 1.40786
vertex -0.951057 -0.132673 1.68577
endloop
endfacet
facet normal -0.451486 -0.0350307 -0.89159
outer loop
vertex -0.587785 0.186311 1.17632
vertex -0.309017 0.164091 1.03603
vertex -0.587785 -0.0934435 1.18731
endloop
endfacet
facet normal -0.704643 -0.0278573 -0.709015
outer loop
vertex -0.587785 0.186311 1.17632
vertex -0.587785 -0.0934435 1.18731
vertex -0.809017 -0.110801 1.40786
endloop
endfacet
facet normal -0.155377 -0.0387827 -0.987094
outer loop
vertex -0.309017 0.164091 1.03603
vertex 1.19249e-08 0.156434 0.987688
vertex -0.309017 -0.0822992 1.04571
endloop
endfacet
facet normal -0.451487 -0.0350304 -0.89159
outer loop
vertex -0.309017 0.164091 1.03603
vertex -0.309017 -0.0822992 1.04571
vertex -0.587785 -0.0934435 1.18731
endloop
endfacet
facet normal 0.155377 -0.0387828 -0.987094
outer loop
vertex 1.19249e-08 0.156434 0.987688
vertex 0.309017 0.164091 1.03603
vertex 1.19249e-08 -0.0784592 0.996917
endloop
endfacet
facet normal -0.155377 -0.0387828 -0.987094
outer loop
vertex 1.19249e-08 0.156434 0.987688
vertex 1.19249e-08 -0.0784592 0.996917
vertex -0.309017 -0.0822992 1.04571
endloop
endfacet
facet normal 0.451487 -0.0350304 -0.89159
outer loop
vertex 0.309017 0.164091 1.03603
vertex 0.587785 0.186311 1.17632
vertex 0.309017 -0.0822992 1.04571
endloop
endfacet
facet normal 0.155377 -0.0387827 -0.987094
outer loop
vertex 0.309017 0.164091 1.03603
vertex 0.309017 -0.0822992 1.04571
vertex 1.19249e-08 -0.0784592 0.996917
endloop
endfacet
facet normal 0.704643 -0.0278572 -0.709014
outer loop
vertex 0.587785 0.186311 1.17632
vertex 0.809017 0.220919 1.39483
vertex 0.587785 -0.0934435 1.18731
endloop
endfacet
facet normal 0.451487 -0.0350306 -0.89159
outer loop
vertex 0.587785 0.186311 1.17632
vertex 0.587785 -0.0934435 1.18731
vertex 0.309017 -0.0822992 1.04571
endloop
endfacet
facet normal 0.889723 -0.0179221 -0.456149
outer loop
vertex 0.809017 0.220919 1.39483
vertex 0.951057 0.264528 1.67016
vertex 0.809017 -0.110801 1.40786
endloop
endfacet
facet normal 0.704643 -0.0278571 -0.709015
outer loop
vertex 0.809017 0.220919 1.39483
vertex 0.809017 -0.110801 1.40786
vertex 0.587785 -0.0934435 1.18731
endloop
endfacet
facet normal 0.987519 -0.00618338 -0.157378
outer loop
vertex 0.951057 0.264528 1.67016
vertex 1 0.312869 1.97538
vertex 0.951057 -0.132673 1.68577
endloop
endfacet
facet normal 0.889723 -0.0179221 -0.456149
outer loop
vertex 0.951057 0.264528 1.67016
vertex 0.951057 -0.132673 1.68577
vertex 0.809017 -0.110801 1.40786
endloop
endfacet
facet normal 0.987519 -0.0307266 0.154473
outer loop
vertex 1 -0.156918 1.99383
vertex 0.951057 -0.181164 2.3019
vertex 1 -0.618034 1.90211
endloop
endfacet
facet normal 0.987519 0.0307266 -0.154473
outer loop
vertex 1 -0.156918 1.99383
vertex 1 -0.618034 1.90211
vertex 0.951057 -0.522543 1.60822
endloop
endfacet
facet normal 0.889723 -0.0890589 0.447729
outer loop
vertex 0.951057 -0.181164 2.3019
vertex 0.809017 -0.203035 2.57981
vertex 0.951057 -0.713526 2.19601
endloop
endfacet
facet normal 0.987519 -0.0307266 0.154473
outer loop
vertex 0.951057 -0.181164 2.3019
vertex 0.951057 -0.713526 2.19601
vertex 1 -0.618034 1.90211
endloop
endfacet
facet normal 0.704643 -0.138429 0.695928
outer loop
vertex 0.809017 -0.203035 2.57981
vertex 0.587785 -0.220393 2.80036
vertex 0.809017 -0.79967 2.46113
endloop
endfacet
facet normal 0.889723 -0.089059 0.447729
outer loop
vertex 0.809017 -0.203035 2.57981
vertex 0.809017 -0.79967 2.46113
vertex 0.951057 -0.713526 2.19601
endloop
endfacet
facet normal 0.451487 -0.174075 0.875133
outer loop
vertex 0.587785 -0.220393 2.80036
vertex 0.309017 -0.231537 2.94196
vertex 0.587785 -0.868034 2.67153
endloop
endfacet
facet normal 0.704643 -0.138429 0.695928
outer loop
vertex 0.587785 -0.220393 2.80036
vertex 0.587785 -0.868034 2.67153
vertex 0.809017 -0.79967 2.46113
endloop
endfacet
facet normal 0.155376 -0.192721 0.968874
outer loop
vertex 0.309017 -0.231537 2.94196
vertex -4.37114e-08 -0.235378 2.99075
vertex 0.309017 -0.911927 2.80662
endloop
endfacet
facet normal 0.451487 -0.174075 0.875133
outer loop
vertex 0.309017 -0.231537 2.94196
vertex 0.309017 -0.911927 2.80662
vertex 0.587785 -0.868034 2.67153
endloop
endfacet
facet normal -0.155376 -0.192721 0.968874
outer loop
vertex -4.37114e-08 -0.235378 2.99075
vertex -0.309017 -0.231537 2.94196
vertex -4.37114e-08 -0.927051 2.85317
endloop
endfacet
facet normal 0.155377 -0.192721 0.968874
outer loop
vertex -4.37114e-08 -0.235378 2.99075
vertex -4.37114e-08 -0.927051 2.85317
vertex 0.309017 -0.911927 2.80662
endloop
endfacet
facet normal -0.451487 -0.174075 0.875133
outer loop
vertex -0.309017 -0.231537 2.94196
vertex -0.587785 -0.220393 2.80036
vertex -0.309017 -0.911927 2.80662
endloop
endfacet
facet normal -0.155377 -0.192721 0.968874
outer loop
vertex -0.309017 -0.231537 2.94196
vertex -0.309017 -0.911927 2.80662
vertex -4.37114e-08 -0.927051 2.85317
endloop
endfacet
facet normal -0.704643 -0.138429 0.695928
outer loop
vertex -0.587785 -0.220393 2.80036
vertex -0.809017 -0.203035 2.57981
vertex -0.587785 -0.868034 2.67153
endloop
endfacet
facet normal -0.451487 -0.174075 0.875133
outer loop
vertex -0.587785 -0.220393 2.80036
vertex -0.587785 -0.868034 2.67153
vertex -0.309017 -0.911927 2.80662
endloop
endfacet
facet normal -0.889723 -0.0890589 0.447729
outer loop
vertex -0.809017 -0.203035 2.57981
vertex -0.951056 -0.181164 2.3019
vertex -0.809017 -0.79967 2.46113
endloop
endfacet
facet normal -0.704643 -0.138429 0.695928
outer loop
vertex -0.809017 -0.203035 2.57981
vertex -0.809017 -0.79967 2.46113
vertex -0.587785 -0.868034 2.67153
endloop
endfacet
facet normal -0.987519 -0.0307266 0.154473
outer loop
vertex -0.951056 -0.181164 2.3019
vertex -1 -0.156918 1.99383
vertex -0.951056 -0.713526 2.19601
endloop
endfacet
facet normal -0.889723 -0.0890588 0.447729
outer loop
vertex -0.951056 -0.181164 2.3019
vertex -0.951056 -0.713526 2.19601
vertex -0.809017 -0.79967 2.46113
endloop
endfacet
facet normal -0.987519 0.0307266 -0.154473
outer loop
vertex -1 -0.156918 1.99383
vertex -0.951057 -0.132673 1.68577
vertex -1 -0.618034 1.90211
endloop
endfacet
facet normal -0.987519 -0.0307266 0.154473
outer loop
vertex -1 -0.156918 1.99383
vertex -1 -0.618034 1.90211
vertex -0.951056 -0.713526 2.19601
endloop
endfacet
facet normal -0.889723 0.089059 -0.447729
outer loop
vertex -0.951057 -0.132673 1.68577
vertex -0.809017 -0.110801 1.40786
vertex -0.951057 -0.522543 1.60822
endloop
endfacet
facet normal -0.987519 0.0307266 -0.154473
outer loop
vertex -0.951057 -0.132673 1.68577
vertex -0.951057 -0.522543 1.60822
vertex -1 -0.618034 1.90211
endloop
endfacet
facet normal -0.704643 0.138429 -0.695928
outer loop
vertex -0.809017 -0.110801 1.40786
vertex -0.587785 -0.0934435 1.18731
vertex -0.809017 -0.436398 1.3431
endloop
endfacet
facet normal -0.889723 0.0890589 -0.447729
outer loop
vertex -0.809017 -0.110801 1.40786
vertex -0.809017 -0.436398 1.3431
vertex -0.951057 -0.522543 1.60822
endloop
endfacet
facet normal -0.451487 0.174075 -0.875133
outer loop
vertex -0.587785 -0.0934435 1.18731
vertex -0.309017 -0.0822992 1.04571
vertex -0.587785 -0.368034 1.13269
endloop
endfacet
facet normal -0.704643 0.138429 -0.695928
outer loop
vertex -0.587785 -0.0934435 1.18731
vertex -0.587785 -0.368034 1.13269
vertex -0.809017 -0.436398 1.3431
endloop
endfacet
facet normal -0.155377 0.192721 -0.968874
outer loop
vertex -0.309017 -0.0822992 1.04571
vertex 1.19249e-08 -0.0784592 0.996917
vertex -0.309017 -0.324141 0.997605
endloop
endfacet
facet normal -0.451487 0.174075 -0.875133
outer loop
vertex -0.309017 -0.0822992 1.04571
vertex -0.309017 -0.324141 0.997605
vertex -0.587785 -0.368034 1.13269
endloop
endfacet
facet normal 0.155376 0.192721 -0.968874
outer loop
vertex 1.19249e-08 -0.0784592 0.996917
vertex 0.309017 -0.0822992 1.04571
vertex 1.19249e-08 -0.309017 0.951056
endloop
endfacet
facet normal -0.155377 0.192721 -0.968874
outer loop
vertex 1.19249e-08 -0.0784592 0.996917
vertex 1.19249e-08 -0.309017 0.951056
vertex -0.309017 -0.324141 0.997605
endloop
endfacet
facet normal 0.451487 0.174075 -0.875133
outer loop
vertex 0.309017 -0.0822992 1.04571
vertex 0.587785 -0.0934435 1.18731
vertex 0.309017 -0.324141 0.997605
endloop
endfacet
facet normal 0.155376 0.192721 -0.968874
outer loop
vertex 0.309017 -0.0822992 1.04571
vertex 0.309017 -0.324141 0.997605
vertex 1.19249e-08 -0.309017 0.951056
endloop
endfacet
facet normal 0.704643 0.138429 -0.695928
outer loop
vertex 0.587785 -0.0934435 1.18731
vertex 0.809017 -0.110801 1.40786
vertex 0.587785 -0.368034 1.13269
endloop
endfacet
facet normal 0.451487 0.174075 -0.875133
outer loop
vertex 0.587785 -0.0934435 1.18731
vertex 0.587785 -0.368034 1.13269
vertex 0.309017 -0.324141 0.997605
endloop
endfacet
facet normal 0.889723 0.0890589 -0.447729
outer loop
vertex 0.809017 -0.110801 1.40786
vertex 0.951057 -0.132673 1.68577
vertex 0.809017 -0.436398 1.3431
endloop
endfacet
facet normal 0.704643 0.138429 -0.695928
outer loop
vertex 0.809017 -0.110801 1.40786
vertex 0.809017 -0.436398 1.3431
vertex 0.587785 -0.368034 1.13269
endloop
endfacet
facet normal 0.987519 0.0307266 -0.154473
outer loop
vertex 0.951057 -0.132673 1.68577
vertex 1 -0.156918 1.99383
vertex 0.951057 -0.522543 1.60822
endloop
endfacet
facet normal 0.889723 0.089059 -0.447729
outer loop
vertex 0.951057 -0.132673 1.68577
vertex 0.951057 -0.522543 1.60822
vertex 0.809017 -0.436398 1.3431
endloop
endfacet
facet normal 0.987519 -0.0659386 0.143032
outer loop
vertex 1 -0.618034 1.90211
vertex 0.951057 -0.713526 2.19601
vertex 1 -1.045 1.70528
endloop
endfacet
facet normal 0.987519 0.0659386 -0.143032
outer loop
vertex 1 -0.618034 1.90211
vertex 1 -1.045 1.70528
vertex 0.951057 -0.883536 1.4418
endloop
endfacet
facet normal 0.889723 -0.191118 0.414568
outer loop
vertex 0.951057 -0.713526 2.19601
vertex 0.809017 -0.79967 2.46113
vertex 0.951057 -1.20646 1.96876
endloop
endfacet
facet normal 0.987519 -0.0659386 0.143032
outer loop
vertex 0.951057 -0.713526 2.19601
vertex 0.951057 -1.20646 1.96876
vertex 1 -1.045 1.70528
endloop
endfacet
facet normal 0.704643 -0.297065 0.644384
outer loop
vertex 0.809017 -0.79967 2.46113
vertex 0.587785 -0.868034 2.67153
vertex 0.809017 -1.35211 2.20645
endloop
endfacet
facet normal 0.889723 -0.191118 0.414568
outer loop
vertex 0.809017 -0.79967 2.46113
vertex 0.809017 -1.35211 2.20645
vertex 0.951057 -1.20646 1.96876
endloop
endfacet
facet normal 0.451487 -0.373561 0.810316
outer loop
vertex 0.587785 -0.868034 2.67153
vertex 0.309017 -0.911927 2.80662
vertex 0.587785 -1.46771 2.39508
endloop
endfacet
facet normal 0.704643 -0.297065 0.644384
outer loop
vertex 0.587785 -0.868034 2.67153
vertex 0.587785 -1.46771 2.39508
vertex 0.809017 -1.35211 2.20645
endloop
endfacet
facet normal 0.155377 -0.413575 0.897114
outer loop
vertex 0.309017 -0.911927 2.80662
vertex -4.37114e-08 -0.927051 2.85317
vertex 0.309017 -1.54192 2.51619
endloop
endfacet
facet normal 0.451487 -0.373561 0.810316
outer loop
vertex 0.309017 -0.911927 2.80662
vertex 0.309017 -1.54192 2.51619
vertex 0.587785 -1.46771 2.39508
endloop
endfacet
facet normal -0.155377 -0.413575 0.897114
outer loop
vertex -4.37114e-08 -0.927051 2.85317
vertex -0.309017 -0.911927 2.80662
vertex -4.37114e-08 -1.5675 2.55792
endloop
endfacet
facet normal 0.155377 -0.413575 0.897114
outer loop
vertex -4.37114e-08 -0.927051 2.85317
vertex -4.37114e-08 -1.5675 2.55792
vertex 0.309017 -1.54192 2.51619
endloop
endfacet
facet normal -0.451487 -0.373561 0.810316
outer loop
vertex -0.309017 -0.911927 2.80662
vertex -0.587785 -0.868034 2.67153
vertex -0.309017 -1.54192 2.51619
endloop
endfacet
facet normal -0.155377 -0.413575 0.897114
outer loop
vertex -0.309017 -0.911927 2.80662
vertex -0.309017 -1.54192 2.51619
vertex -4.37114e-08 -1.5675 2.55792
endloop
endfacet
facet normal -0.704643 -0.297065 0.644384
outer loop
vertex -0.587785 -0.868034 2.67153
vertex -0.809017 -0.79967 2.46113
vertex -0.587785 -1.46771 2.39508
endloop
endfacet
facet normal -0.451487 -0.373561 0.810316
outer loop
vertex -0.587785 -0.868034 2.67153
vertex -0.587785 -1.46771 2.39508
vertex -0.309017 -1.54192 2.51619
endloop
endfacet
facet normal -0.889723 -0.191118 0.414568
outer loop
vertex -0.809017 -0.79967 2.46113
vertex -0.951056 -0.713526 2.19601
vertex -0.809017 -1.35211 2.20645
endloop
endfacet
facet normal -0.704643 -0.297065 0.644384
outer loop
vertex -0.809017 -0.79967 2.46113
vertex -0.809017 -1.35211 2.20645
vertex -0.587785 -1.46771 2.39508
endloop
endfacet
facet normal -0.987519 -0.0659387 0.143032
outer loop
vertex -0.951056 -0.713526 2.19601
vertex -1 -0.618034 1.90211
vertex -0.951056 -1.20646 1.96876
endloop
endfacet
facet normal -0.889723 -0.191118 0.414568
outer loop
vertex -0.951056 -0.713526 2.19601
vertex -0.951056 -1.20646 1.96876
vertex -0.809017 -1.35211 2.20645
endloop
endfacet
facet normal -0.987519 0.0659386 -0.143032
outer loop
vertex -1 -0.618034 1.90211
vertex -0.951057 -0.522543 1.60822
vertex -1 -1.045 1.70528
endloop
endfacet
facet normal -0.987519 -0.0659387 0.143032
outer loop
vertex -1 -0.618034 1.90211
vertex -1 -1.045 1.70528
vertex -0.951056 -1.20646 1.96876
endloop
endfacet
facet normal -0.889723 0.191118 -0.414568
outer loop
vertex -0.951057 -0.522543 1.60822
vertex -0.809017 -0.436398 1.3431
vertex -0.951057 -0.883536 1.4418
endloop
endfacet
facet normal -0.987519 0.0659386 -0.143032
outer loop
vertex -0.951057 -0.522543 1.60822
vertex -0.951057 -0.883536 1.4418
vertex -1 -1.045 1.70528
endloop
endfacet
facet normal -0.704643 0.297065 -0.644384
outer loop
vertex -0.809017 -0.436398 1.3431
vertex -0.587785 -0.368034 1.13269
vertex -0.809017 -0.73788 1.20411
endloop
endfacet
facet normal -0.889723 0.191118 -0.414568
outer loop
vertex -0.809017 -0.436398 1.3431
vertex -0.809017 -0.73788 1.20411
vertex -0.951057 -0.883536 1.4418
endloop
endfacet
facet normal -0.451487 0.373561 -0.810316
outer loop
vertex -0.587785 -0.368034 1.13269
vertex -0.309017 -0.324141 0.997605
vertex -0.587785 -0.622287 1.01548
endloop
endfacet
facet normal -0.704643 0.297065 -0.644384
outer loop
vertex -0.587785 -0.368034 1.13269
vertex -0.587785 -0.622287 1.01548
vertex -0.809017 -0.73788 1.20411
endloop
endfacet
facet normal -0.155377 0.413575 -0.897114
outer loop
vertex -0.309017 -0.324141 0.997605
vertex 1.19249e-08 -0.309017 0.951056
vertex -0.309017 -0.548071 0.894371
endloop
endfacet
facet normal -0.451487 0.373561 -0.810316
outer loop
vertex -0.309017 -0.324141 0.997605
vertex -0.309017 -0.548071 0.894371
vertex -0.587785 -0.622287 1.01548
endloop
endfacet
facet normal 0.155376 0.413575 -0.897114
outer loop
vertex 1.19249e-08 -0.309017 0.951056
vertex 0.309017 -0.324141 0.997605
vertex 1.19249e-08 -0.522498 0.85264
endloop
endfacet
facet normal -0.155376 0.413575 -0.897114
outer loop
vertex 1.19249e-08 -0.309017 0.951056
vertex 1.19249e-08 -0.522498 0.85264
vertex -0.309017 -0.548071 0.894371
endloop
endfacet
facet normal 0.451487 0.373561 -0.810316
outer loop
vertex 0.309017 -0.324141 0.997605
vertex 0.587785 -0.368034 1.13269
vertex 0.309017 -0.548071 0.894371
endloop
endfacet
facet normal 0.155376 0.413575 -0.897114
outer loop
vertex 0.309017 -0.324141 0.997605
vertex 0.309017 -0.548071 0.894371
vertex 1.19249e-08 -0.522498 0.85264
endloop
endfacet
facet normal 0.704643 0.297065 -0.644384
outer loop
vertex 0.587785 -0.368034 1.13269
vertex 0.809017 -0.436398 1.3431
vertex 0.587785 -0.622287 1.01548
endloop
endfacet
facet normal 0.451487 0.373561 -0.810316
outer loop
vertex 0.587785 -0.368034 1.13269
vertex 0.587785 -0.622287 1.01548
vertex 0.309017 -0.548071 0.894371
endloop
endfacet
facet normal 0.889723 0.191119 -0.414568
outer loop
vertex 0.809017 -0.436398 1.3431
vertex 0.951057 -0.522543 1.60822
vertex 0.809017 -0.73788 1.20411
endloop
endfacet
facet normal 0.704643 0.297065 -0.644383
outer loop
vertex 0.809017 -0.436398 1.3431
vertex 0.809017 -0.73788 1.20411
vertex 0.587785 -0.622287 1.01548
endloop
endfacet
facet normal 0.987519 0.0659386 -0.143032
outer loop
vertex 0.951057 -0.522543 1.60822
vertex 1 -0.618034 1.90211
vertex 0.951057 -0.883536 1.4418
endloop
endfacet
facet normal 0.889723 0.191118 -0.414568
outer loop
vertex 0.951057 -0.522543 1.60822
vertex 0.951057 -0.883536 1.4418
vertex 0.809017 -0.73788 1.20411
endloop
endfacet
facet normal 0.987519 -0.0975069 0.123687
outer loop
vertex 1 -1.045 1.70528
vertex 0.951057 -1.20646 1.96876
vertex 1 -1.41421 1.41421
endloop
endfacet
facet normal 0.987519 0.0975069 -0.123687
outer loop
vertex 1 -1.045 1.70528
vertex 1 -1.41421 1.41421
vertex 0.951057 -1.19571 1.19571
endloop
endfacet
facet normal 0.889723 -0.282617 0.358498
outer loop
vertex 0.951057 -1.20646 1.96876
vertex 0.809017 -1.35211 2.20645
vertex 0.951057 -1.63272 1.63272
endloop
endfacet
facet normal 0.987519 -0.0975069 0.123687
outer loop
vertex 0.951057 -1.20646 1.96876
vertex 0.951057 -1.63272 1.63272
vertex 1 -1.41421 1.41421
endloop
endfacet
facet normal 0.704643 -0.439285 0.557231
outer loop
vertex 0.809017 -1.35211 2.20645
vertex 0.587785 -1.46771 2.39508
vertex 0.809017 -1.82984 1.82984
endloop
endfacet
facet normal 0.889723 -0.282617 0.358498
outer loop
vertex 0.809017 -1.35211 2.20645
vertex 0.809017 -1.82984 1.82984
vertex 0.951057 -1.63272 1.63272
endloop
endfacet
facet normal 0.451487 -0.552404 0.700721
outer loop
vertex 0.587785 -1.46771 2.39508
vertex 0.309017 -1.54192 2.51619
vertex 0.587785 -1.98627 1.98627
endloop
endfacet
facet normal 0.704643 -0.439286 0.557231
outer loop
vertex 0.587785 -1.46771 2.39508
vertex 0.587785 -1.98627 1.98627
vertex 0.809017 -1.82984 1.82984
endloop
endfacet
facet normal 0.155377 -0.611575 0.77578
outer loop
vertex 0.309017 -1.54192 2.51619
vertex -4.37114e-08 -1.5675 2.55792
vertex 0.309017 -2.08671 2.08671
endloop
endfacet
facet normal 0.451487 -0.552403 0.700721
outer loop
vertex 0.309017 -1.54192 2.51619
vertex 0.309017 -2.08671 2.08671
vertex 0.587785 -1.98627 1.98627
endloop
endfacet
facet normal -0.155377 -0.611575 0.775779
outer loop
vertex -4.37114e-08 -1.5675 2.55792
vertex -0.309017 -1.54192 2.51619
vertex -4.37114e-08 -2.12132 2.12132
endloop
endfacet
facet normal 0.155376 -0.611575 0.775779
outer loop
vertex -4.37114e-08 -1.5675 2.55792
vertex -4.37114e-08 -2.12132 2.12132
vertex 0.309017 -2.08671 2.08671
endloop
endfacet
facet normal -0.451487 -0.552404 0.700721
outer loop
vertex -0.309017 -1.54192 2.51619
vertex -0.587785 -1.46771 2.39508
vertex -0.309017 -2.08671 2.08671
endloop
endfacet
facet normal -0.155376 -0.611575 0.77578
outer loop
vertex -0.309017 -1.54192 2.51619
vertex -0.309017 -2.08671 2.08671
vertex -4.37114e-08 -2.12132 2.12132
endloop
endfacet
facet normal -0.704643 -0.439286 0.557231
outer loop
vertex -0.587785 -1.46771 2.39508
vertex -0.809017 -1.35211 2.20645
vertex -0.587785 -1.98627 1.98627
endloop
endfacet
facet normal -0.451488 -0.552404 0.70072
outer loop
vertex -0.587785 -1.46771 2.39508
vertex -0.587785 -1.98627 1.98627
vertex -0.309017 -2.08671 2.08671
endloop
endfacet
facet normal -0.889723 -0.282617 0.358498
outer loop
vertex -0.809017 -1.35211 2.20645
vertex -0.951056 -1.20646 1.96876
vertex -0.809017 -1.82984 1.82984
endloop
endfacet
facet normal -0.704643 -0.439286 0.557231
outer loop
vertex -0.809017 -1.35211 2.20645
vertex -0.809017 -1.82984 1.82984
vertex -0.587785 -1.98627 1.98627
endloop
endfacet
facet normal -0.987519 -0.0975069 0.123687
outer loop
vertex -0.951056 -1.20646 1.96876
vertex -1 -1.045 1.70528
vertex -0.951056 -1.63272 1.63272
endloop
endfacet
facet normal -0.889723 -0.282617 0.358498
outer loop
vertex -0.951056 -1.20646 1.96876
vertex -0.951056 -1.63272 1.63272
vertex -0.809017 -1.82984 1.82984
endloop
endfacet
facet normal -0.987519 0.0975069 -0.123687
outer loop
vertex -1 -1.045 1.70528
vertex -0.951057 -0.883536 1.4418
vertex -1 -1.41421 1.41421
endloop
endfacet
facet normal -0.987519 -0.0975069 0.123687
outer loop
vertex -1 -1.045 1.70528
vertex -1 -1.41421 1.41421
vertex -0.951056 -1.63272 1.63272
endloop
endfacet
facet normal -0.889723 0.282617 -0.358498
outer loop
vertex -0.951057 -0.883536 1.4418
vertex -0.809017 -0.73788 1.20411
vertex -0.951057 -1.19571 1.19571
endloop
endfacet
facet normal -0.987519 0.0975069 -0.123687
outer loop
vertex -0.951057 -0.883536 1.4418
vertex -0.951057 -1.19571 1.19571
vertex -1 -1.41421 1.41421
endloop
endfacet
facet normal -0.704643 0.439285 -0.557231
outer loop
vertex -0.809017 -0.73788 1.20411
vertex -0.587785 -0.622287 1.01548
vertex -0.809017 -0.998587 0.998587
endloop
endfacet
facet normal -0.889723 0.282617 -0.358498
outer loop
vertex -0.809017 -0.73788 1.20411
vertex -0.809017 -0.998587 0.998587
vertex -0.951057 -1.19571 1.19571
endloop
endfacet
facet normal -0.451487 0.552404 -0.700721
outer loop
vertex -0.587785 -0.622287 1.01548
vertex -0.309017 -0.548071 0.894371
vertex -0.587785 -0.842152 0.842152
endloop
endfacet
facet normal -0.704643 0.439285 -0.557231
outer loop
vertex -0.587785 -0.622287 1.01548
vertex -0.587785 -0.842152 0.842152
vertex -0.809017 -0.998587 0.998587
endloop
endfacet
facet normal -0.155376 0.611575 -0.775779
outer loop
vertex -0.309017 -0.548071 0.894371
vertex 1.19249e-08 -0.522498 0.85264
vertex -0.309017 -0.741715 0.741715
endloop
endfacet
facet normal -0.451487 0.552404 -0.700721
outer loop
vertex -0.309017 -0.548071 0.894371
vertex -0.309017 -0.741715 0.741715
vertex -0.587785 -0.842152 0.842152
endloop
endfacet
facet normal 0.155376 0.611575 -0.775779
outer loop
vertex 1.19249e-08 -0.522498 0.85264
vertex 0.309017 -0.548071 0.894371
vertex 1.19249e-08 -0.707107 0.707107
endloop
endfacet
facet normal -0.155377 0.611575 -0.775779
outer loop
vertex 1.19249e-08 -0.522498 0.85264
vertex 1.19249e-08 -0.707107 0.707107
vertex -0.309017 -0.741715 0.741715
endloop
endfacet
facet normal 0.451487 0.552404 -0.700721
outer loop
vertex 0.309017 -0.548071 0.894371
vertex 0.587785 -0.622287 1.01548
vertex 0.309017 -0.741715 0.741715
endloop
endfacet
facet normal 0.155377 0.611575 -0.77578
outer loop
vertex 0.309017 -0.548071 0.894371
vertex 0.309017 -0.741715 0.741715
vertex 1.19249e-08 -0.707107 0.707107
endloop
endfacet
facet normal 0.704643 0.439285 -0.557231
outer loop
vertex 0.587785 -0.622287 1.01548
vertex 0.809017 -0.73788 1.20411
vertex 0.587785 -0.842152 0.842152
endloop
endfacet
facet normal 0.451487 0.552404 -0.700721
outer loop
vertex 0.587785 -0.622287 1.01548
vertex 0.587785 -0.842152 0.842152
vertex 0.309017 -0.741715 0.741715
endloop
endfacet
facet normal 0.889723 0.282617 -0.358498
outer loop
vertex 0.809017 -0.73788 1.20411
vertex 0.951057 -0.883536 1.4418
vertex 0.809017 -0.998587 0.998587
endloop
endfacet
facet normal 0.704643 0.439285 -0.557231
outer loop
vertex 0.809017 -0.73788 1.20411
vertex 0.809017 -0.998587 0.998587
vertex 0.587785 -0.842152 0.842152
endloop
endfacet
facet normal 0.987519 0.0975069 -0.123687
outer loop
vertex 0.951057 -0.883536 1.4418
vertex 1 -1.045 1.70528
vertex 0.951057 -1.19571 1.19571
endloop
endfacet
facet normal 0.889723 0.282617 -0.358498
outer loop
vertex 0.951057 -0.883536 1.4418
vertex 0.951057 -1.19571 1.19571
vertex 0.809017 -0.998587 0.998587
endloop
endfacet
facet normal 0.987519 -0.123687 0.0975069
outer loop
vertex 1 -1.41421 1.41421
vertex 0.951057 -1.63272 1.63272
vertex 1 -1.70528 1.045
endloop
endfacet
facet normal 0.987519 0.123687 -0.0975069
outer loop
vertex 1 -1.41421 1.41421
vertex 1 -1.70528 1.045
vertex 0.951057 -1.4418 0.883536
endloop
endfacet
facet normal 0.889723 -0.358498 0.282617
outer loop
vertex 0.951057 -1.63272 1.63272
vertex 0.809017 -1.82984 1.82984
vertex 0.951057 -1.96876 1.20646
endloop
endfacet
facet normal 0.987519 -0.123687 0.0975069
outer loop
vertex 0.951057 -1.63272 1.63272
vertex 0.951057 -1.96876 1.20646
vertex 1 -1.70528 1.045
endloop
endfacet
facet normal 0.704643 -0.557231 0.439286
outer loop
vertex 0.809017 -1.82984 1.82984
vertex 0.587785 -1.98627 1.98627
vertex 0.809017 -2.20645 1.35211
endloop
endfacet
facet normal 0.889723 -0.358498 0.282617
outer loop
vertex 0.809017 -1.82984 1.82984
vertex 0.809017 -2.20645 1.35211
vertex 0.951057 -1.96876 1.20646
endloop
endfacet
facet normal 0.451487 -0.70072 0.552404
outer loop
vertex 0.587785 -1.98627 1.98627
vertex 0.309017 -2.08671 2.08671
vertex 0.587785 -2.39508 1.46771
endloop
endfacet
facet normal 0.704643 -0.557231 0.439285
outer loop
vertex 0.587785 -1.98627 1.98627
vertex 0.587785 -2.39508 1.46771
vertex 0.809017 -2.20645 1.35211
endloop
endfacet
facet normal 0.155376 -0.77578 0.611575
outer loop
vertex 0.309017 -2.08671 2.08671
vertex -4.37114e-08 -2.12132 2.12132
vertex 0.309017 -2.51619 1.54192
endloop
endfacet
facet normal 0.451487 -0.700721 0.552404
outer loop
vertex 0.309017 -2.08671 2.08671
vertex 0.309017 -2.51619 1.54192
vertex 0.587785 -2.39508 1.46771
endloop
endfacet
facet normal -0.155376 -0.775779 0.611575
outer loop
vertex -4.37114e-08 -2.12132 2.12132
vertex -0.309017 -2.08671 2.08671
vertex -4.37114e-08 -2.55792 1.5675
endloop
endfacet
facet normal 0.155377 -0.775779 0.611575
outer loop
vertex -4.37114e-08 -2.12132 2.12132
vertex -4.37114e-08 -2.55792 1.5675
vertex 0.309017 -2.51619 1.54192
endloop
endfacet
facet normal -0.451488 -0.700721 0.552403
outer loop
vertex -0.309017 -2.08671 2.08671
vertex -0.587785 -1.98627 1.98627
vertex -0.309017 -2.51619 1.54192
endloop
endfacet
facet normal -0.155377 -0.77578 0.611575
outer loop
vertex -0.309017 -2.08671 2.08671
vertex -0.309017 -2.51619 1.54192
vertex -4.37114e-08 -2.55792 1.5675
endloop
endfacet
facet normal -0.704643 -0.557231 0.439286
outer loop
vertex -0.587785 -1.98627 1.98627
vertex -0.809017 -1.82984 1.82984
vertex -0.587785 -2.39508 1.46771
endloop
endfacet
facet normal -0.451487 -0.700721 0.552404
outer loop
vertex -0.587785 -1.98627 1.98627
vertex -0.587785 -2.39508 1.46771
vertex -0.309017 -2.51619 1.54192
endloop
endfacet
facet normal -0.889723 -0.358498 0.282617
outer loop
vertex -0.809017 -1.82984 1.82984
vertex -0.951056 -1.63272 1.63272
vertex -0.809017 -2.20645 1.35211
endloop
endfacet
facet normal -0.704643 -0.557231 0.439285
outer loop
vertex -0.809017 -1.82984 1.82984
vertex -0.809017 -2.20645 1.35211
vertex -0.587785 -2.39508 1.46771
endloop
endfacet
facet normal -0.987519 -0.123687 0.0975069
outer loop
vertex -0.951056 -1.63272 1.63272
vertex -1 -1.41421 1.41421
vertex -0.951056 -1.96876 1.20646
endloop
endfacet
facet normal -0.889723 -0.358498 0.282617
outer loop
vertex -0.951056 -1.63272 1.63272
vertex -0.951056 -1.96876 1.20646
vertex -0.809017 -2.20645 1.35211
endloop
endfacet
facet normal -0.987519 0.123687 -0.0975069
outer loop
vertex -1 -1.41421 1.41421
vertex -0.951057 -1.19571 1.19571
vertex -1 -1.70528 1.045
endloop
endfacet
facet normal -0.987519 -0.123687 0.0975069
outer loop
vertex -1 -1.41421 1.41421
vertex -1 -1.70528 1.045
vertex -0.951056 -1.96876 1.20646
endloop
endfacet
facet normal -0.889723 0.358498 -0.282617
outer loop
vertex -0.951057 -1.19571 1.19571
vertex -0.809017 -0.998587 0.998587
vertex -0.951057 -1.4418 0.883536
endloop
endfacet
facet normal -0.987519 0.123687 -0.0975069
outer loop
vertex -0.951057 -1.19571 1.19571
vertex -0.951057 -1.4418 0.883536
vertex -1 -1.70528 1.045
endloop
endfacet
facet normal -0.704643 0.557231 -0.439285
outer loop
vertex -0.809017 -0.998587 0.998587
vertex -0.587785 -0.842152 0.842152
vertex -0.809017 -1.20411 0.73788
endloop
endfacet
facet normal -0.889723 0.358498 -0.282617
outer loop
vertex -0.809017 -0.998587 0.998587
vertex -0.809017 -1.20411 0.73788
vertex -0.951057 -1.4418 0.883536
endloop
endfacet
facet normal -0.451487 0.700721 -0.552404
outer loop
vertex -0.587785 -0.842152 0.842152
vertex -0.309017 -0.741715 0.741715
vertex -0.587785 -1.01548 0.622287
endloop
endfacet
facet normal -0.704643 0.557231 -0.439285
outer loop
vertex -0.587785 -0.842152 0.842152
vertex -0.587785 -1.01548 0.622287
vertex -0.809017 -1.20411 0.73788
endloop
endfacet
facet normal -0.155377 0.775779 -0.611575
outer loop
vertex -0.309017 -0.741715 0.741715
vertex 1.19249e-08 -0.707107 0.707107
vertex -0.309017 -0.894371 0.548071
endloop
endfacet
facet normal -0.451487 0.700721 -0.552404
outer loop
vertex -0.309017 -0.741715 0.741715
vertex -0.309017 -0.894371 0.548071
vertex -0.587785 -1.01548 0.622287
endloop
endfacet
facet normal 0.155376 0.775779 -0.611575
outer loop
vertex 1.19249e-08 -0.707107 0.707107
vertex 0.309017 -0.741715 0.741715
vertex 1.19249e-08 -0.85264 0.522498
endloop
endfacet
facet normal -0.155376 0.775779 -0.611575
outer loop
vertex 1.19249e-08 -0.707107 0.707107
vertex 1.19249e-08 -0.85264 0.522498
vertex -0.309017 -0.894371 0.548071
endloop
endfacet
facet normal 0.451487 0.700721 -0.552404
outer loop
vertex 0.309017 -0.741715 0.741715
vertex 0.587785 -0.842152 0.842152
vertex 0.309017 -0.894371 0.548071
endloop
endfacet
facet normal 0.155376 0.77578 -0.611575
outer loop
vertex 0.309017 -0.741715 0.741715
vertex 0.309017 -0.894371 0.548071
vertex 1.19249e-08 -0.85264 0.522498
endloop
endfacet
facet normal 0.704643 0.557231 -0.439285
outer loop
vertex 0.587785 -0.842152 0.842152
vertex 0.809017 -0.998587 0.998587
vertex 0.587785 -1.01548 0.622287
endloop
endfacet
facet normal 0.451487 0.700721 -0.552404
outer loop
vertex 0.587785 -0.842152 0.842152
vertex 0.587785 -1.01548 0.622287
vertex 0.309017 -0.894371 0.548071
endloop
endfacet
facet normal 0.889723 0.358498 -0.282617
outer loop
vertex 0.809017 -0.998587 0.998587
vertex 0.951057 -1.19571 1.19571
vertex 0.809017 -1.20411 0.73788
endloop
endfacet
facet normal 0.704643 0.557231 -0.439285
outer loop
vertex 0.809017 -0.998587 0.998587
vertex 0.809017 -1.20411 0.73788
vertex 0.587785 -1.01548 0.622287
endloop
endfacet
facet normal 0.987519 0.123687 -0.0975069
outer loop
vertex 0.951057 -1.19571 1.19571
vertex 1 -1.41421 1.41421
vertex 0.951057 -1.4418 0.883536
endloop
endfacet
facet normal 0.889723 0.358498 -0.282617
outer loop
vertex 0.951057 -1.19571 1.19571
vertex 0.951057 -1.4418 0.883536
vertex 0.809017 -1.20411 0.73788
endloop
endfacet
facet normal 0.987519 -0.143032 0.0659386
outer loop
vertex 1 -1.70528 1.045
vertex 0.951057 -1.96876 1.20646
vertex 1 -1.90211 0.618034
endloop
endfacet
facet normal 0.987519 0.143032 -0.0659386
outer loop
vertex 1 -1.70528 1.045
vertex 1 -1.90211 0.618034
vertex 0.951057 -1.60822 0.522543
endloop
endfacet
facet normal 0.889723 -0.414568 0.191118
outer loop
vertex 0.951057 -1.96876 1.20646
vertex 0.809017 -2.20645 1.35211
vertex 0.951057 -2.19601 0.713526
endloop
endfacet
facet normal 0.987519 -0.143032 0.0659386
outer loop
vertex 0.951057 -1.96876 1.20646
vertex 0.951057 -2.19601 0.713526
vertex 1 -1.90211 0.618034
endloop
endfacet
facet normal 0.704643 -0.644384 0.297065
outer loop
vertex 0.809017 -2.20645 1.35211
vertex 0.587785 -2.39508 1.46771
vertex 0.809017 -2.46113 0.79967
endloop
endfacet
facet normal 0.889723 -0.414568 0.191118
outer loop
vertex 0.809017 -2.20645 1.35211
vertex 0.809017 -2.46113 0.79967
vertex 0.951057 -2.19601 0.713526
endloop
endfacet
facet normal 0.451487 -0.810316 0.373561
outer loop
vertex 0.587785 -2.39508 1.46771
vertex 0.309017 -2.51619 1.54192
vertex 0.587785 -2.67153 0.868034
endloop
endfacet
facet normal 0.704643 -0.644384 0.297065
outer loop
vertex 0.587785 -2.39508 1.46771
vertex 0.587785 -2.67153 0.868034
vertex 0.809017 -2.46113 0.79967
endloop
endfacet
facet normal 0.155377 -0.897114 0.413575
outer loop
vertex 0.309017 -2.51619 1.54192
vertex -4.37114e-08 -2.55792 1.5675
vertex 0.309017 -2.80662 0.911927
endloop
endfacet
facet normal 0.451487 -0.810316 0.373561
outer loop
vertex 0.309017 -2.51619 1.54192
vertex 0.309017 -2.80662 0.911927
vertex 0.587785 -2.67153 0.868034
endloop
endfacet
facet normal -0.155377 -0.897114 0.413575
outer loop
vertex -4.37114e-08 -2.55792 1.5675
vertex -0.309017 -2.51619 1.54192
vertex -4.37114e-08 -2.85317 0.927051
endloop
endfacet
facet normal 0.155377 -0.897114 0.413575
outer loop
vertex -4.37114e-08 -2.55792 1.5675
vertex -4.37114e-08 -2.85317 0.927051
vertex 0.309017 -2.80662 0.911927
endloop
endfacet
facet normal -0.451487 -0.810316 0.373561
outer loop
vertex -0.309017 -2.51619 1.54192
vertex -0.587785 -2.39508 1.46771
vertex -0.309017 -2.80662 0.911927
endloop
endfacet
facet normal -0.155377 -0.897114 0.413575
outer loop
vertex -0.309017 -2.51619 1.54192
vertex -0.309017 -2.80662 0.911927
vertex -4.37114e-08 -2.85317 0.927051
endloop
endfacet
facet normal -0.704643 -0.644384 0.297065
outer loop
vertex -0.587785 -2.39508 1.46771
vertex -0.809017 -2.20645 1.35211
vertex -0.587785 -2.67153 0.868034
endloop
endfacet
facet normal -0.451487 -0.810316 0.373561
outer loop
vertex -0.587785 -2.39508 1.46771
vertex -0.587785 -2.67153 0.868034
vertex -0.309017 -2.80662 0.911927
endloop
endfacet
facet normal -0.889723 -0.414568 0.191118
outer loop
vertex -0.809017 -2.20645 1.35211
vertex -0.951056 -1.96876 1.20646
vertex -0.809017 -2.46113 0.79967
endloop
endfacet
facet normal -0.704643 -0.644384 0.297065
outer loop
vertex -0.809017 -2.20645 1.35211
vertex -0.809017 -2.46113 0.79967
vertex -0.587785 -2.67153 0.868034
endloop
endfacet
facet normal -0.987519 -0.143032 0.0659387
outer loop
vertex -0.951056 -1.96876 1.20646
vertex -1 -1.70528 1.045
vertex -0.951056 -2.19601 0.713526
endloop
endfacet
facet normal -0.889723 -0.414568 0.191118
outer loop
vertex -0.951056 -1.96876 1.20646
vertex -0.951056 -2.19601 0.713526
vertex -0.809017 -2.46113 0.79967
endloop
endfacet
facet normal -0.987519 0.143032 -0.0659386
outer loop
vertex -1 -1.70528 1.045
vertex -0.951057 -1.4418 0.883536
vertex -1 -1.90211 0.618034
endloop
endfacet
facet normal -0.987519 -0.143032 0.0659387
outer loop
vertex -1 -1.70528 1.045
vertex -1 -1.90211 0.618034
vertex -0.951056 -2.19601 0.713526
endloop
endfacet
facet normal -0.889723 0.414568 -0.191118
outer loop
vertex -0.951057 -1.4418 0.883536
vertex -0.809017 -1.20411 0.73788
vertex -0.951057 -1.60822 0.522543
endloop
endfacet
facet normal -0.987519 0.143032 -0.0659386
outer loop
vertex -0.951057 -1.4418 0.883536
vertex -0.951057 -1.60822 0.522543
vertex -1 -1.90211 0.618034
endloop
endfacet
facet normal -0.704643 0.644384 -0.297065
outer loop
vertex -0.809017 -1.20411 0.73788
vertex -0.587785 -1.01548 0.622287
vertex -0.809017 -1.3431 0.436398
endloop
endfacet
facet normal -0.889723 0.414568 -0.191119
outer loop
vertex -0.809017 -1.20411 0.73788
vertex -0.809017 -1.3431 0.436398
vertex -0.951057 -1.60822 0.522543
endloop
endfacet
facet normal -0.451487 0.810316 -0.373561
outer loop
vertex -0.587785 -1.01548 0.622287
vertex -0.309017 -0.894371 0.548071
vertex -0.587785 -1.13269 0.368034
endloop
endfacet
facet normal -0.704643 0.644384 -0.297065
outer loop
vertex -0.587785 -1.01548 0.622287
vertex -0.587785 -1.13269 0.368034
vertex -0.809017 -1.3431 0.436398
endloop
endfacet
facet normal -0.155377 0.897114 -0.413575
outer loop
vertex -0.309017 -0.894371 0.548071
vertex 1.19249e-08 -0.85264 0.522498
vertex -0.309017 -0.997605 0.324141
endloop
endfacet
facet normal -0.451487 0.810316 -0.373561
outer loop
vertex -0.309017 -0.894371 0.548071
vertex -0.309017 -0.997605 0.324141
vertex -0.587785 -1.13269 0.368034
endloop
endfacet
facet normal 0.155376 0.897114 -0.413575
outer loop
vertex 1.19249e-08 -0.85264 0.522498
vertex 0.309017 -0.894371 0.548071
vertex 1.19249e-08 -0.951056 0.309017
endloop
endfacet
facet normal -0.155376 0.897114 -0.413575
outer loop
vertex 1.19249e-08 -0.85264 0.522498
vertex 1.19249e-08 -0.951056 0.309017
vertex -0.309017 -0.997605 0.324141
endloop
endfacet
facet normal 0.451487 0.810316 -0.373561
outer loop
vertex 0.309017 -0.894371 0.548071
vertex 0.587785 -1.01548 0.622287
vertex 0.309017 -0.997605 0.324141
endloop
endfacet
facet normal 0.155376 0.897114 -0.413575
outer loop
vertex 0.309017 -0.894371 0.548071
vertex 0.309017 -0.997605 0.324141
vertex 1.19249e-08 -0.951056 0.309017
endloop
endfacet
facet normal 0.704643 0.644383 -0.297065
outer loop
vertex 0.587785 -1.01548 0.622287
vertex 0.809017 -1.20411 0.73788
vertex 0.587785 -1.13269 0.368034
endloop
endfacet
facet normal 0.451487 0.810316 -0.373561
outer loop
vertex 0.587785 -1.01548 0.622287
vertex 0.587785 -1.13269 0.368034
vertex 0.309017 -0.997605 0.324141
endloop
endfacet
facet normal 0.889723 0.414568 -0.191119
outer loop
vertex 0.809017 -1.20411 0.73788
vertex 0.951057 -1.4418 0.883536
vertex 0.809017 -1.3431 0.436398
endloop
endfacet
facet normal 0.704643 0.644384 -0.297065
outer loop
vertex 0.809017 -1.20411 0.73788
vertex 0.809017 -1.3431 0.436398
vertex 0.587785 -1.13269 0.368034
endloop
endfacet
facet normal 0.987519 0.143032 -0.0659386
outer loop
vertex 0.951057 -1.4418 0.883536
vertex 1 -1.70528 1.045
vertex 0.951057 -1.60822 0.522543
endloop
endfacet
facet normal 0.889723 0.414568 -0.191119
outer loop
vertex 0.951057 -1.4418 0.883536
vertex 0.951057 -1.60822 0.522543
vertex 0.809017 -1.3431 0.436398
endloop
endfacet
facet normal 0.987519 -0.154473 0.0307266
outer loop
vertex 1 -1.90211 0.618034
vertex 0.951057 -2.19601 0.713526
vertex 1 -1.99383 0.156919
endloop
endfacet
facet normal 0.987519 0.154473 -0.0307266
outer loop
vertex 1 -1.90211 0.618034
vertex 1 -1.99383 0.156919
vertex 0.951057 -1.68577 0.132673
endloop
endfacet
facet normal 0.889723 -0.447729 0.0890589
outer loop
vertex 0.951057 -2.19601 0.713526
vertex 0.809017 -2.46113 0.79967
vertex 0.951057 -2.3019 0.181164
endloop
endfacet
facet normal 0.987519 -0.154473 0.0307266
outer loop
vertex 0.951057 -2.19601 0.713526
vertex 0.951057 -2.3019 0.181164
vertex 1 -1.99383 0.156919
endloop
endfacet
facet normal 0.704643 -0.695928 0.138429
outer loop
vertex 0.809017 -2.46113 0.79967
vertex 0.587785 -2.67153 0.868034
vertex 0.809017 -2.57981 0.203036
endloop
endfacet
facet normal 0.889723 -0.447729 0.089059
outer loop
vertex 0.809017 -2.46113 0.79967
vertex 0.809017 -2.57981 0.203036
vertex 0.951057 -2.3019 0.181164
endloop
endfacet
facet normal 0.451487 -0.875133 0.174075
outer loop
vertex 0.587785 -2.67153 0.868034
vertex 0.309017 -2.80662 0.911927
vertex 0.587785 -2.80036 0.220393
endloop
endfacet
facet normal 0.704643 -0.695928 0.138429
outer loop
vertex 0.587785 -2.67153 0.868034
vertex 0.587785 -2.80036 0.220393
vertex 0.809017 -2.57981 0.203036
endloop
endfacet
facet normal 0.155377 -0.968874 0.192721
outer loop
vertex 0.309017 -2.80662 0.911927
vertex -4.37114e-08 -2.85317 0.927051
vertex 0.309017 -2.94196 0.231538
endloop
endfacet
facet normal 0.451487 -0.875133 0.174075
outer loop
vertex 0.309017 -2.80662 0.911927
vertex 0.309017 -2.94196 0.231538
vertex 0.587785 -2.80036 0.220393
endloop
endfacet
facet normal -0.155377 -0.968874 0.192721
outer loop
vertex -4.37114e-08 -2.85317 0.927051
vertex -0.309017 -2.80662 0.911927
vertex -4.37114e-08 -2.99075 0.235378
endloop
endfacet
facet normal 0.155376 -0.968874 0.192721
outer loop
vertex -4.37114e-08 -2.85317 0.927051
vertex -4.37114e-08 -2.99075 0.235378
vertex 0.309017 -2.94196 0.231538
endloop
endfacet
facet normal -0.451487 -0.875133 0.174075
outer loop
vertex -0.309017 -2.80662 0.911927
vertex -0.587785 -2.67153 0.868034
vertex -0.309017 -2.94196 0.231538
endloop
endfacet
facet normal -0.155376 -0.968874 0.192721
outer loop
vertex -0.309017 -2.80662 0.911927
vertex -0.309017 -2.94196 0.231538
vertex -4.37114e-08 -2.99075 0.235378
endloop
endfacet
facet normal -0.704643 -0.695928 0.138429
outer loop
vertex -0.587785 -2.67153 0.868034
vertex -0.809017 -2.46113 0.79967
vertex -0.587785 -2.80036 0.220393
endloop
endfacet
facet normal -0.451487 -0.875133 0.174075
outer loop
vertex -0.587785 -2.67153 0.868034
vertex -0.587785 -2.80036 0.220393
vertex -0.309017 -2.94196 0.231538
endloop
endfacet
facet normal -0.889723 -0.447729 0.089059
outer loop
vertex -0.809017 -2.46113 0.79967
vertex -0.951056 -2.19601 0.713526
vertex -0.809017 -2.57981 0.203036
endloop
endfacet
facet normal -0.704643 -0.695928 0.138429
outer loop
vertex -0.809017 -2.46113 0.79967
vertex -0.809017 -2.57981 0.203036
vertex -0.587785 -2.80036 0.220393
endloop
endfacet
facet normal -0.987519 -0.154473 0.0307266
outer loop
vertex -0.951056 -2.19601 0.713526
vertex -1 -1.90211 0.618034
vertex -0.951056 -2.3019 0.181164
endloop
endfacet
facet normal -0.889723 -0.447729 0.0890588
outer loop
vertex -0.951056 -2.19601 0.713526
vertex -0.951056 -2.3019 0.181164
vertex -0.809017 -2.57981 0.203036
endloop
endfacet
facet normal -0.987519 0.154473 -0.0307266
outer loop
vertex -1 -1.90211 0.618034
vertex -0.951057 -1.60822 0.522543
vertex -1 -1.99383 0.156919
endloop
endfacet
facet normal -0.987519 -0.154473 0.0307266
outer loop
vertex -1 -1.90211 0.618034
vertex -1 -1.99383 0.156919
vertex -0.951056 -2.3019 0.181164
endloop
endfacet
facet normal -0.889723 0.447729 -0.089059
outer loop
vertex -0.951057 -1.60822 0.522543
vertex -0.809017 -1.3431 0.436398
vertex -0.951057 -1.68577 0.132673
endloop
endfacet
facet normal -0.987519 0.154473 -0.0307267
outer loop
vertex -0.951057 -1.60822 0.522543
vertex -0.951057 -1.68577 0.132673
vertex -1 -1.99383 0.156919
endloop
endfacet
facet normal -0.704643 0.695928 -0.138429
outer loop
vertex -0.809017 -1.3431 0.436398
vertex -0.587785 -1.13269 0.368034
vertex -0.809017 -1.40786 0.110801
endloop
endfacet
facet normal -0.889723 0.447729 -0.089059
outer loop
vertex -0.809017 -1.3431 0.436398
vertex -0.809017 -1.40786 0.110801
vertex -0.951057 -1.68577 0.132673
endloop
endfacet
facet normal -0.451487 0.875133 -0.174075
outer loop
vertex -0.587785 -1.13269 0.368034
vertex -0.309017 -0.997605 0.324141
vertex -0.587785 -1.18731 0.0934437
endloop
endfacet
facet normal -0.704643 0.695928 -0.138429
outer loop
vertex -0.587785 -1.13269 0.368034
vertex -0.587785 -1.18731 0.0934437
vertex -0.809017 -1.40786 0.110801
endloop
endfacet
facet normal -0.155377 0.968874 -0.192721
outer loop
vertex -0.309017 -0.997605 0.324141
vertex 1.19249e-08 -0.951056 0.309017
vertex -0.309017 -1.04571 0.0822994
endloop
endfacet
facet normal -0.451487 0.875133 -0.174075
outer loop
vertex -0.309017 -0.997605 0.324141
vertex -0.309017 -1.04571 0.0822994
vertex -0.587785 -1.18731 0.0934437
endloop
endfacet
facet normal 0.155376 0.968874 -0.192721
outer loop
vertex 1.19249e-08 -0.951056 0.309017
vertex 0.309017 -0.997605 0.324141
vertex 1.19249e-08 -0.996917 0.0784593
endloop
endfacet
facet normal -0.155376 0.968874 -0.192721
outer loop
vertex 1.19249e-08 -0.951056 0.309017
vertex 1.19249e-08 -0.996917 0.0784593
vertex -0.309017 -1.04571 0.0822994
endloop
endfacet
facet normal 0.451487 0.875133 -0.174075
outer loop
vertex 0.309017 -0.997605 0.324141
vertex 0.587785 -1.13269 0.368034
vertex 0.309017 -1.04571 0.0822994
endloop
endfacet
facet normal 0.155377 0.968874 -0.192721
outer loop
vertex 0.309017 -0.997605 0.324141
vertex 0.309017 -1.04571 0.0822994
vertex 1.19249e-08 -0.996917 0.0784593
endloop
endfacet
facet normal 0.704643 0.695928 -0.138429
outer loop
vertex 0.587785 -1.13269 0.368034
vertex 0.809017 -1.3431 0.436398
vertex 0.587785 -1.18731 0.0934437
endloop
endfacet
facet normal 0.451487 0.875133 -0.174075
outer loop
vertex 0.587785 -1.13269 0.368034
vertex 0.587785 -1.18731 0.0934437
vertex 0.309017 -1.04571 0.0822994
endloop
endfacet
facet normal 0.889723 0.447729 -0.089059
outer loop
vertex 0.809017 -1.3431 0.436398
vertex 0.951057 -1.60822 0.522543
vertex 0.809017 -1.40786 0.110801
endloop
endfacet
facet normal 0.704643 0.695928 -0.138429
outer loop
vertex 0.809017 -1.3431 0.436398
vertex 0.809017 -1.40786 0.110801
vertex 0.587785 -1.18731 0.0934437
endloop
endfacet
facet normal 0.987519 0.154473 -0.0307266
outer loop
vertex 0.951057 -1.60822 0.522543
vertex 1 -1.90211 0.618034
vertex 0.951057 -1.68577 0.132673
endloop
endfacet
facet normal 0.889723 0.447729 -0.089059
outer loop
vertex 0.951057 -1.60822 0.522543
vertex 0.951057 -1.68577 0.132673
vertex 0.809017 -1.40786 0.110801
endloop
endfacet
facet normal 0.987519 -0.157378 -0.00618339
outer loop
vertex 1 -1.99383 0.156919
vertex 0.951057 -2.3019 0.181164
vertex 1 -1.97538 -0.312869
endloop
endfacet
facet normal 0.987519 0.157378 0.00618339
outer loop
vertex 1 -1.99383 0.156919
vertex 1 -1.97538 -0.312869
vertex 0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal 0.889723 -0.456149 -0.0179221
outer loop
vertex 0.951057 -2.3019 0.181164
vertex 0.809017 -2.57981 0.203036
vertex 0.951057 -2.28059 -0.36121
endloop
endfacet
facet normal 0.987519 -0.157378 -0.00618337
outer loop
vertex 0.951057 -2.3019 0.181164
vertex 0.951057 -2.28059 -0.36121
vertex 1 -1.97538 -0.312869
endloop
endfacet
facet normal 0.704643 -0.709015 -0.0278575
outer loop
vertex 0.809017 -2.57981 0.203036
vertex 0.587785 -2.80036 0.220393
vertex 0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal 0.889723 -0.456149 -0.0179223
outer loop
vertex 0.809017 -2.57981 0.203036
vertex 0.809017 -2.55593 -0.404819
vertex 0.951057 -2.28059 -0.36121
endloop
endfacet
facet normal 0.451487 -0.89159 -0.0350307
outer loop
vertex 0.587785 -2.80036 0.220393
vertex 0.309017 -2.94196 0.231538
vertex 0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal 0.704643 -0.709015 -0.0278573
outer loop
vertex 0.587785 -2.80036 0.220393
vertex 0.587785 -2.77443 -0.439427
vertex 0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal 0.155376 -0.987094 -0.0387833
outer loop
vertex 0.309017 -2.94196 0.231538
vertex -4.37114e-08 -2.99075 0.235378
vertex 0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal 0.451487 -0.89159 -0.0350309
outer loop
vertex 0.309017 -2.94196 0.231538
vertex 0.309017 -2.91472 -0.461647
vertex 0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal -0.155376 -0.987094 -0.0387831
outer loop
vertex -4.37114e-08 -2.99075 0.235378
vertex -0.309017 -2.94196 0.231538
vertex -4.37114e-08 -2.96306 -0.469304
endloop
endfacet
facet normal 0.155377 -0.987094 -0.0387831
outer loop
vertex -4.37114e-08 -2.99075 0.235378
vertex -4.37114e-08 -2.96306 -0.469304
vertex 0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal -0.451487 -0.89159 -0.0350309
outer loop
vertex -0.309017 -2.94196 0.231538
vertex -0.587785 -2.80036 0.220393
vertex -0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal -0.155377 -0.987094 -0.0387833
outer loop
vertex -0.309017 -2.94196 0.231538
vertex -0.309017 -2.91472 -0.461647
vertex -4.37114e-08 -2.96306 -0.469304
endloop
endfacet
facet normal -0.704643 -0.709015 -0.0278573
outer loop
vertex -0.587785 -2.80036 0.220393
vertex -0.809017 -2.57981 0.203036
vertex -0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal -0.451487 -0.89159 -0.0350307
outer loop
vertex -0.587785 -2.80036 0.220393
vertex -0.587785 -2.77443 -0.439427
vertex -0.309017 -2.91472 -0.461647
endloop
endfacet
facet normal -0.889723 -0.456148 -0.0179223
outer loop
vertex -0.809017 -2.57981 0.203036
vertex -0.951056 -2.3019 0.181164
vertex -0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal -0.704643 -0.709015 -0.0278575
outer loop
vertex -0.809017 -2.57981 0.203036
vertex -0.809017 -2.55593 -0.404819
vertex -0.587785 -2.77443 -0.439427
endloop
endfacet
facet normal -0.987519 -0.157378 -0.00618338
outer loop
vertex -0.951056 -2.3019 0.181164
vertex -1 -1.99383 0.156919
vertex -0.951056 -2.28059 -0.36121
endloop
endfacet
facet normal -0.889723 -0.456149 -0.0179221
outer loop
vertex -0.951056 -2.3019 0.181164
vertex -0.951056 -2.28059 -0.36121
vertex -0.809017 -2.55593 -0.404819
endloop
endfacet
facet normal -0.987519 0.157378 0.0061834
outer loop
vertex -1 -1.99383 0.156919
vertex -0.951057 -1.68577 0.132673
vertex -1 -1.97538 -0.312869
endloop
endfacet
facet normal -0.987519 -0.157378 -0.0061834
outer loop
vertex -1 -1.99383 0.156919
vertex -1 -1.97538 -0.312869
vertex -0.951056 -2.28059 -0.36121
endloop
endfacet
facet normal -0.889723 0.456149 0.0179221
outer loop
vertex -0.951057 -1.68577 0.132673
vertex -0.809017 -1.40786 0.110801
vertex -0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal -0.987519 0.157378 0.00618338
outer loop
vertex -0.951057 -1.68577 0.132673
vertex -0.951057 -1.67016 -0.264528
vertex -1 -1.97538 -0.312869
endloop
endfacet
facet normal -0.704643 0.709015 0.0278574
outer loop
vertex -0.809017 -1.40786 0.110801
vertex -0.587785 -1.18731 0.0934437
vertex -0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal -0.889723 0.456149 0.0179222
outer loop
vertex -0.809017 -1.40786 0.110801
vertex -0.809017 -1.39483 -0.220919
vertex -0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal -0.451487 0.89159 0.0350306
outer loop
vertex -0.587785 -1.18731 0.0934437
vertex -0.309017 -1.04571 0.0822994
vertex -0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal -0.704643 0.709015 0.0278572
outer loop
vertex -0.587785 -1.18731 0.0934437
vertex -0.587785 -1.17632 -0.186311
vertex -0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal -0.155377 0.987094 0.0387832
outer loop
vertex -0.309017 -1.04571 0.0822994
vertex 1.19249e-08 -0.996917 0.0784593
vertex -0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal -0.451487 0.89159 0.0350308
outer loop
vertex -0.309017 -1.04571 0.0822994
vertex -0.309017 -1.03603 -0.164091
vertex -0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal 0.155377 0.987094 0.038783
outer loop
vertex 1.19249e-08 -0.996917 0.0784593
vertex 0.309017 -1.04571 0.0822994
vertex 1.19249e-08 -0.987688 -0.156435
endloop
endfacet
facet normal -0.155376 0.987094 0.038783
outer loop
vertex 1.19249e-08 -0.996917 0.0784593
vertex 1.19249e-08 -0.987688 -0.156435
vertex -0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal 0.451487 0.89159 0.0350308
outer loop
vertex 0.309017 -1.04571 0.0822994
vertex 0.587785 -1.18731 0.0934437
vertex 0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal 0.155376 0.987094 0.0387832
outer loop
vertex 0.309017 -1.04571 0.0822994
vertex 0.309017 -1.03603 -0.164091
vertex 1.19249e-08 -0.987688 -0.156435
endloop
endfacet
facet normal 0.704643 0.709015 0.0278572
outer loop
vertex 0.587785 -1.18731 0.0934437
vertex 0.809017 -1.40786 0.110801
vertex 0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal 0.451487 0.89159 0.0350306
outer loop
vertex 0.587785 -1.18731 0.0934437
vertex 0.587785 -1.17632 -0.186311
vertex 0.309017 -1.03603 -0.164091
endloop
endfacet
facet normal 0.889723 0.456149 0.0179222
outer loop
vertex 0.809017 -1.40786 0.110801
vertex 0.951057 -1.68577 0.132673
vertex 0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal 0.704643 0.709015 0.0278574
outer loop
vertex 0.809017 -1.40786 0.110801
vertex 0.809017 -1.39483 -0.220919
vertex 0.587785 -1.17632 -0.186311
endloop
endfacet
facet normal 0.987519 0.157378 0.00618338
outer loop
vertex 0.951057 -1.68577 0.132673
vertex 1 -1.99383 0.156919
vertex 0.951057 -1.67016 -0.264528
endloop
endfacet
facet normal 0.889723 0.456149 0.0179221
outer loop
vertex 0.951057 -1.68577 0.132673
vertex 0.951057 -1.67016 -0.264528
vertex 0.809017 -1.39483 -0.220919
endloop
endfacet
facet normal 0.987519 -0.151586 -0.0427517
outer loop
vertex 1 -1.97538 -0.312869
vertex 0.951057 -2.28059 -0.36121
vertex 1 -1.84776 -0.765367
endloop
endfacet
facet normal 0.987519 0.151586 0.0427517
outer loop
vertex 1 -1.97538 -0.312869
vertex 1 -1.84776 -0.765367
vertex 0.951057 -1.56226 -0.647111
endloop
endfacet
facet normal 0.889723 -0.439362 -0.123913
outer loop
vertex 0.951057 -2.28059 -0.36121
vertex 0.809017 -2.55593 -0.404819
vertex 0.951057 -2.13325 -0.883623
endloop
endfacet
facet normal 0.987519 -0.151586 -0.0427518
outer loop
vertex 0.951057 -2.28059 -0.36121
vertex 0.951057 -2.13325 -0.883623
vertex 1 -1.84776 -0.765367
endloop
endfacet
facet normal 0.704643 -0.682921 -0.192604
outer loop
vertex 0.809017 -2.55593 -0.404819
vertex 0.587785 -2.77443 -0.439427
vertex 0.809017 -2.3908 -0.990303
endloop
endfacet
facet normal 0.889723 -0.439362 -0.123913
outer loop
vertex 0.809017 -2.55593 -0.404819
vertex 0.809017 -2.3908 -0.990303
vertex 0.951057 -2.13325 -0.883623
endloop
endfacet
facet normal 0.451487 -0.858777 -0.2422
outer loop
vertex 0.587785 -2.77443 -0.439427
vertex 0.309017 -2.91472 -0.461647
vertex 0.587785 -2.59519 -1.07496
endloop
endfacet
facet normal 0.704643 -0.682921 -0.192604
outer loop
vertex 0.587785 -2.77443 -0.439427
vertex 0.587785 -2.59519 -1.07496
vertex 0.809017 -2.3908 -0.990303
endloop
endfacet
facet normal 0.155377 -0.950767 -0.268144
outer loop
vertex 0.309017 -2.91472 -0.461647
vertex -4.37114e-08 -2.96306 -0.469304
vertex 0.309017 -2.72642 -1.12932
endloop
endfacet
facet normal 0.451487 -0.858777 -0.2422
outer loop
vertex 0.309017 -2.91472 -0.461647
vertex 0.309017 -2.72642 -1.12932
vertex 0.587785 -2.59519 -1.07496
endloop
endfacet
facet normal -0.155377 -0.950766 -0.268144
outer loop
vertex -4.37114e-08 -2.96306 -0.469304
vertex -0.309017 -2.91472 -0.461647
vertex -4.37114e-08 -2.77164 -1.14805
endloop
endfacet
facet normal 0.155376 -0.950766 -0.268144
outer loop
vertex -4.37114e-08 -2.96306 -0.469304
vertex -4.37114e-08 -2.77164 -1.14805
vertex 0.309017 -2.72642 -1.12932
endloop
endfacet
facet normal -0.451487 -0.858777 -0.2422
outer loop
vertex -0.309017 -2.91472 -0.461647
vertex -0.587785 -2.77443 -0.439427
vertex -0.309017 -2.72642 -1.12932
endloop
endfacet
facet normal -0.155376 -0.950767 -0.268144
outer loop
vertex -0.309017 -2.91472 -0.461647
vertex -0.309017 -2.72642 -1.12932
vertex -4.37114e-08 -2.77164 -1.14805
endloop
endfacet
facet normal -0.704643 -0.682922 -0.192604
outer loop
vertex -0.587785 -2.77443 -0.439427
vertex -0.809017 -2.55593 -0.404819
vertex -0.587785 -2.59519 -1.07496
endloop
endfacet
facet normal -0.451487 -0.858777 -0.2422
outer loop
vertex -0.587785 -2.77443 -0.439427
vertex -0.587785 -2.59519 -1.07496
vertex -0.309017 -2.72642 -1.12932
endloop
endfacet
facet normal -0.889723 -0.439361 -0.123913
outer loop
vertex -0.809017 -2.55593 -0.404819
vertex -0.951056 -2.28059 -0.36121
vertex -0.809017 -2.3908 -0.990303
endloop
endfacet
facet normal -0.704643 -0.682922 -0.192604
outer loop
vertex -0.809017 -2.55593 -0.404819
vertex -0.809017 -2.3908 -0.990303
vertex -0.587785 -2.59519 -1.07496
endloop
endfacet
facet normal -0.987519 -0.151586 -0.0427518
outer loop
vertex -0.951056 -2.28059 -0.36121
vertex -1 -1.97538 -0.312869
vertex -0.951056 -2.13325 -0.883623
endloop
endfacet
facet normal -0.889723 -0.439361 -0.123913
outer loop
vertex -0.951056 -2.28059 -0.36121
vertex -0.951056 -2.13325 -0.883623
vertex -0.809017 -2.3908 -0.990303
endloop
endfacet
facet normal -0.987519 0.151586 0.0427517
outer loop
vertex -1 -1.97538 -0.312869
vertex -0.951057 -1.67016 -0.264528
vertex -1 -1.84776 -0.765367
endloop
endfacet
facet normal -0.987519 -0.151586 -0.0427518
outer loop
vertex -1 -1.97538 -0.312869
vertex -1 -1.84776 -0.765367
vertex -0.951056 -2.13325 -0.883623
endloop
endfacet
facet normal -0.889723 0.439361 0.123913
outer loop
vertex -0.951057 -1.67016 -0.264528
vertex -0.809017 -1.39483 -0.220919
vertex -0.951057 -1.56226 -0.647111
endloop
endfacet
facet normal -0.987519 0.151586 0.0427518
outer loop
vertex -0.951057 -1.67016 -0.264528
vertex -0.951057 -1.56226 -0.647111
vertex -1 -1.84776 -0.765367
endloop
endfacet
facet normal -0.704643 0.682922 0.192604
outer loop
vertex -0.809017 -1.39483 -0.220919
vertex -0.587785 -1.17632 -0.186311
vertex -0.809017 -1.30472 -0.540431
endloop
endfacet
facet normal -0.889723 0.439362 0.123913
outer loop
vertex -0.809017 -1.39483 -0.220919
vertex -0.809017 -1.30472 -0.540431
vertex -0.951057 -1.56226 -0.647111
endloop
endfacet
facet normal -0.451487 0.858777 0.2422
outer loop
vertex -0.587785 -1.17632 -0.186311
vertex -0.309017 -1.03603 -0.164091
vertex -0.587785 -1.10032 -0.455769
endloop
endfacet
facet normal -0.704643 0.682922 0.192604
outer loop
vertex -0.587785 -1.17632 -0.186311
vertex -0.587785 -1.10032 -0.455769
vertex -0.809017 -1.30472 -0.540431
endloop
endfacet
facet normal -0.155376 0.950767 0.268144
outer loop
vertex -0.309017 -1.03603 -0.164091
vertex 1.19249e-08 -0.987688 -0.156435
vertex -0.309017 -0.969097 -0.401413
endloop
endfacet
facet normal -0.451487 0.858777 0.2422
outer loop
vertex -0.309017 -1.03603 -0.164091
vertex -0.309017 -0.969097 -0.401413
vertex -0.587785 -1.10032 -0.455769
endloop
endfacet
facet normal 0.155376 0.950766 0.268144
outer loop
vertex 1.19249e-08 -0.987688 -0.156435
vertex 0.309017 -1.03603 -0.164091
vertex 1.19249e-08 -0.92388 -0.382683
endloop
endfacet
facet normal -0.155377 0.950767 0.268144
outer loop
vertex 1.19249e-08 -0.987688 -0.156435
vertex 1.19249e-08 -0.92388 -0.382683
vertex -0.309017 -0.969097 -0.401413
endloop
endfacet
facet normal 0.451487 0.858777 0.2422
outer loop
vertex 0.309017 -1.03603 -0.164091
vertex 0.587785 -1.17632 -0.186311
vertex 0.309017 -0.969097 -0.401413
endloop
endfacet
facet normal 0.155376 0.950767 0.268144
outer loop
vertex 0.309017 -1.03603 -0.164091
vertex 0.309017 -0.969097 -0.401413
vertex 1.19249e-08 -0.92388 -0.382683
endloop
endfacet
facet normal 0.704643 0.682921 0.192604
outer loop
vertex 0.587785 -1.17632 -0.186311
vertex 0.809017 -1.39483 -0.220919
vertex 0.587785 -1.10032 -0.455769
endloop
endfacet
facet normal 0.451487 0.858777 0.2422
outer loop
vertex 0.587785 -1.17632 -0.186311
vertex 0.587785 -1.10032 -0.455769
vertex 0.309017 -0.969097 -0.401413
endloop
endfacet
facet normal 0.889723 0.439362 0.123913
outer loop
vertex 0.809017 -1.39483 -0.220919
vertex 0.951057 -1.67016 -0.264528
vertex 0.809017 -1.30472 -0.540431
endloop
endfacet
facet normal 0.704643 0.682921 0.192604
outer loop
vertex 0.809017 -1.39483 -0.220919
vertex 0.809017 -1.30472 -0.540431
vertex 0.587785 -1.10032 -0.455769
endloop
endfacet
facet normal 0.987519 0.151586 0.0427517
outer loop
vertex 0.951057 -1.67016 -0.264528
vertex 1 -1.97538 -0.312869
vertex 0.951057 -1.56226 -0.647111
endloop
endfacet
facet normal 0.889723 0.439362 0.123913
outer loop
vertex 0.951057 -1.67016 -0.264528
vertex 0.951057 -1.56226 -0.647111
vertex 0.809017 -1.30472 -0.540431
endloop
endfacet
facet normal 0.987519 -0.137418 -0.0769575
outer loop
vertex 1 -1.84776 -0.765367
vertex 0.951057 -2.13325 -0.883623
vertex 1 -1.61803 -1.17557
endloop
endfacet
facet normal 0.987519 0.137418 0.0769575
outer loop
vertex 1 -1.84776 -0.765367
vertex 1 -1.61803 -1.17557
vertex 0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal 0.889723 -0.398295 -0.223056
outer loop
vertex 0.951057 -2.13325 -0.883623
vertex 0.809017 -2.3908 -0.990303
vertex 0.951057 -1.86803 -1.35721
endloop
endfacet
facet normal 0.987519 -0.137418 -0.0769574
outer loop
vertex 0.951057 -2.13325 -0.883623
vertex 0.951057 -1.86803 -1.35721
vertex 1 -1.61803 -1.17557
endloop
endfacet
facet normal 0.704643 -0.61909 -0.346707
outer loop
vertex 0.809017 -2.3908 -0.990303
vertex 0.587785 -2.59519 -1.07496
vertex 0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal 0.889723 -0.398295 -0.223056
outer loop
vertex 0.809017 -2.3908 -0.990303
vertex 0.809017 -2.09356 -1.52106
vertex 0.951057 -1.86803 -1.35721
endloop
endfacet
facet normal 0.451487 -0.778509 -0.435986
outer loop
vertex 0.587785 -2.59519 -1.07496
vertex 0.309017 -2.72642 -1.12932
vertex 0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal 0.704643 -0.61909 -0.346707
outer loop
vertex 0.587785 -2.59519 -1.07496
vertex 0.587785 -2.27254 -1.6511
vertex 0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal 0.155376 -0.8619 -0.482687
outer loop
vertex 0.309017 -2.72642 -1.12932
vertex -4.37114e-08 -2.77164 -1.14805
vertex 0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal 0.451487 -0.778509 -0.435986
outer loop
vertex 0.309017 -2.72642 -1.12932
vertex 0.309017 -2.38745 -1.73459
vertex 0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal -0.155376 -0.8619 -0.482687
outer loop
vertex -4.37114e-08 -2.77164 -1.14805
vertex -0.309017 -2.72642 -1.12932
vertex -4.37114e-08 -2.42705 -1.76336
endloop
endfacet
facet normal 0.155376 -0.8619 -0.482687
outer loop
vertex -4.37114e-08 -2.77164 -1.14805
vertex -4.37114e-08 -2.42705 -1.76336
vertex 0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal -0.451487 -0.778509 -0.435986
outer loop
vertex -0.309017 -2.72642 -1.12932
vertex -0.587785 -2.59519 -1.07496
vertex -0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal -0.155376 -0.8619 -0.482687
outer loop
vertex -0.309017 -2.72642 -1.12932
vertex -0.309017 -2.38745 -1.73459
vertex -4.37114e-08 -2.42705 -1.76336
endloop
endfacet
facet normal -0.704643 -0.61909 -0.346707
outer loop
vertex -0.587785 -2.59519 -1.07496
vertex -0.809017 -2.3908 -0.990303
vertex -0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal -0.451487 -0.778509 -0.435986
outer loop
vertex -0.587785 -2.59519 -1.07496
vertex -0.587785 -2.27254 -1.6511
vertex -0.309017 -2.38745 -1.73459
endloop
endfacet
facet normal -0.889723 -0.398295 -0.223056
outer loop
vertex -0.809017 -2.3908 -0.990303
vertex -0.951056 -2.13325 -0.883623
vertex -0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal -0.704643 -0.61909 -0.346707
outer loop
vertex -0.809017 -2.3908 -0.990303
vertex -0.809017 -2.09356 -1.52106
vertex -0.587785 -2.27254 -1.6511
endloop
endfacet
facet normal -0.987519 -0.137418 -0.0769575
outer loop
vertex -0.951056 -2.13325 -0.883623
vertex -1 -1.84776 -0.765367
vertex -0.951056 -1.86803 -1.35721
endloop
endfacet
facet normal -0.889723 -0.398295 -0.223056
outer loop
vertex -0.951056 -2.13325 -0.883623
vertex -0.951056 -1.86803 -1.35721
vertex -0.809017 -2.09356 -1.52106
endloop
endfacet
facet normal -0.987519 0.137418 0.0769575
outer loop
vertex -1 -1.84776 -0.765367
vertex -0.951057 -1.56226 -0.647111
vertex -1 -1.61803 -1.17557
endloop
endfacet
facet normal -0.987519 -0.137418 -0.0769575
outer loop
vertex -1 -1.84776 -0.765367
vertex -1 -1.61803 -1.17557
vertex -0.951056 -1.86803 -1.35721
endloop
endfacet
facet normal -0.889723 0.398295 0.223056
outer loop
vertex -0.951057 -1.56226 -0.647111
vertex -0.809017 -1.30472 -0.540431
vertex -0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal -0.987519 0.137418 0.0769575
outer loop
vertex -0.951057 -1.56226 -0.647111
vertex -0.951057 -1.36803 -0.993935
vertex -1 -1.61803 -1.17557
endloop
endfacet
facet normal -0.704643 0.61909 0.346707
outer loop
vertex -0.809017 -1.30472 -0.540431
vertex -0.587785 -1.10032 -0.455769
vertex -0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal -0.889723 0.398295 0.223056
outer loop
vertex -0.809017 -1.30472 -0.540431
vertex -0.809017 -1.14251 -0.830079
vertex -0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal -0.451487 0.778509 0.435986
outer loop
vertex -0.587785 -1.10032 -0.455769
vertex -0.309017 -0.969097 -0.401413
vertex -0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal -0.704643 0.61909 0.346707
outer loop
vertex -0.587785 -1.10032 -0.455769
vertex -0.587785 -0.963525 -0.700042
vertex -0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal -0.155376 0.8619 0.482687
outer loop
vertex -0.309017 -0.969097 -0.401413
vertex 1.19249e-08 -0.92388 -0.382683
vertex -0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal -0.451487 0.778509 0.435986
outer loop
vertex -0.309017 -0.969097 -0.401413
vertex -0.309017 -0.848613 -0.616554
vertex -0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal 0.155376 0.8619 0.482687
outer loop
vertex 1.19249e-08 -0.92388 -0.382683
vertex 0.309017 -0.969097 -0.401413
vertex 1.19249e-08 -0.809017 -0.587785
endloop
endfacet
facet normal -0.155376 0.8619 0.482687
outer loop
vertex 1.19249e-08 -0.92388 -0.382683
vertex 1.19249e-08 -0.809017 -0.587785
vertex -0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal 0.451487 0.778509 0.435986
outer loop
vertex 0.309017 -0.969097 -0.401413
vertex 0.587785 -1.10032 -0.455769
vertex 0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal 0.155376 0.8619 0.482687
outer loop
vertex 0.309017 -0.969097 -0.401413
vertex 0.309017 -0.848613 -0.616554
vertex 1.19249e-08 -0.809017 -0.587785
endloop
endfacet
facet normal 0.704643 0.61909 0.346707
outer loop
vertex 0.587785 -1.10032 -0.455769
vertex 0.809017 -1.30472 -0.540431
vertex 0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal 0.451487 0.778509 0.435986
outer loop
vertex 0.587785 -1.10032 -0.455769
vertex 0.587785 -0.963525 -0.700042
vertex 0.309017 -0.848613 -0.616554
endloop
endfacet
facet normal 0.889723 0.398295 0.223056
outer loop
vertex 0.809017 -1.30472 -0.540431
vertex 0.951057 -1.56226 -0.647111
vertex 0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal 0.704643 0.61909 0.346707
outer loop
vertex 0.809017 -1.30472 -0.540431
vertex 0.809017 -1.14251 -0.830079
vertex 0.587785 -0.963525 -0.700042
endloop
endfacet
facet normal 0.987519 0.137418 0.0769575
outer loop
vertex 0.951057 -1.56226 -0.647111
vertex 1 -1.84776 -0.765367
vertex 0.951057 -1.36803 -0.993935
endloop
endfacet
facet normal 0.889723 0.398295 0.223056
outer loop
vertex 0.951057 -1.56226 -0.647111
vertex 0.951057 -1.36803 -0.993935
vertex 0.809017 -1.14251 -0.830079
endloop
endfacet
facet normal 0.987519 -0.115655 -0.106911
outer loop
vertex 1 -1.61803 -1.17557
vertex 0.951057 -1.86803 -1.35721
vertex 1 -1.2989 -1.52081
endloop
endfacet
facet normal 0.987519 0.115655 0.106911
outer loop
vertex 1 -1.61803 -1.17557
vertex 1 -1.2989 -1.52081
vertex 0.951057 -1.09821 -1.28583
endloop
endfacet
facet normal 0.889723 -0.335219 -0.309873
outer loop
vertex 0.951057 -1.86803 -1.35721
vertex 0.809017 -2.09356 -1.52106
vertex 0.951057 -1.49959 -1.75579
endloop
endfacet
facet normal 0.987519 -0.115655 -0.106911
outer loop
vertex 0.951057 -1.86803 -1.35721
vertex 0.951057 -1.49959 -1.75579
vertex 1 -1.2989 -1.52081
endloop
endfacet
facet normal 0.704643 -0.521047 -0.481651
outer loop
vertex 0.809017 -2.09356 -1.52106
vertex 0.587785 -2.27254 -1.6511
vertex 0.809017 -1.68063 -1.96777
endloop
endfacet
facet normal 0.889723 -0.335219 -0.309873
outer loop
vertex 0.809017 -2.09356 -1.52106
vertex 0.809017 -1.68063 -1.96777
vertex 0.951057 -1.49959 -1.75579
endloop
endfacet
facet normal 0.451487 -0.65522 -0.605679
outer loop
vertex 0.587785 -2.27254 -1.6511
vertex 0.309017 -2.38745 -1.73459
vertex 0.587785 -1.82431 -2.13599
endloop
endfacet
facet normal 0.704643 -0.521047 -0.481651
outer loop
vertex 0.587785 -2.27254 -1.6511
vertex 0.587785 -1.82431 -2.13599
vertex 0.809017 -1.68063 -1.96777
endloop
endfacet
facet normal 0.155376 -0.725404 -0.670557
outer loop
vertex 0.309017 -2.38745 -1.73459
vertex -4.37114e-08 -2.42705 -1.76336
vertex 0.309017 -1.91656 -2.244
endloop
endfacet
facet normal 0.451487 -0.65522 -0.605679
outer loop
vertex 0.309017 -2.38745 -1.73459
vertex 0.309017 -1.91656 -2.244
vertex 0.587785 -1.82431 -2.13599
endloop
endfacet
facet normal -0.155376 -0.725404 -0.670557
outer loop
vertex -4.37114e-08 -2.42705 -1.76336
vertex -0.309017 -2.38745 -1.73459
vertex -4.37114e-08 -1.94834 -2.28122
endloop
endfacet
facet normal 0.155376 -0.725404 -0.670557
outer loop
vertex -4.37114e-08 -2.42705 -1.76336
vertex -4.37114e-08 -1.94834 -2.28122
vertex 0.309017 -1.91656 -2.244
endloop
endfacet
facet normal -0.451487 -0.655219 -0.605679
outer loop
vertex -0.309017 -2.38745 -1.73459
vertex -0.587785 -2.27254 -1.6511
vertex -0.309017 -1.91656 -2.244
endloop
endfacet
facet normal -0.155377 -0.725404 -0.670557
outer loop
vertex -0.309017 -2.38745 -1.73459
vertex -0.309017 -1.91656 -2.244
vertex -4.37114e-08 -1.94834 -2.28122
endloop
endfacet
facet normal -0.704643 -0.521047 -0.481651
outer loop
vertex -0.587785 -2.27254 -1.6511
vertex -0.809017 -2.09356 -1.52106
vertex -0.587785 -1.82431 -2.13599
endloop
endfacet
facet normal -0.451487 -0.65522 -0.605679
outer loop
vertex -0.587785 -2.27254 -1.6511
vertex -0.587785 -1.82431 -2.13599
vertex -0.309017 -1.91656 -2.244
endloop
endfacet
facet normal -0.889723 -0.335219 -0.309873
outer loop
vertex -0.809017 -2.09356 -1.52106
vertex -0.951056 -1.86803 -1.35721
vertex -0.809017 -1.68063 -1.96777
endloop
endfacet
facet normal -0.704643 -0.521047 -0.481651
outer loop
vertex -0.809017 -2.09356 -1.52106
vertex -0.809017 -1.68063 -1.96777
vertex -0.587785 -1.82431 -2.13599
endloop
endfacet
facet normal -0.987519 -0.115655 -0.106911
outer loop
vertex -0.951056 -1.86803 -1.35721
vertex -1 -1.61803 -1.17557
vertex -0.951056 -1.49959 -1.75579
endloop
endfacet
facet normal -0.889723 -0.335219 -0.309873
outer loop
vertex -0.951056 -1.86803 -1.35721
vertex -0.951056 -1.49959 -1.75579
vertex -0.809017 -1.68063 -1.96777
endloop
endfacet
facet normal -0.987519 0.115655 0.106911
outer loop
vertex -1 -1.61803 -1.17557
vertex -0.951057 -1.36803 -0.993935
vertex -1 -1.2989 -1.52081
endloop
endfacet
facet normal -0.987519 -0.115655 -0.106911
outer loop
vertex -1 -1.61803 -1.17557
vertex -1 -1.2989 -1.52081
vertex -0.951056 -1.49959 -1.75579
endloop
endfacet
facet normal -0.889723 0.335219 0.309873
outer loop
vertex -0.951057 -1.36803 -0.993935
vertex -0.809017 -1.14251 -0.830079
vertex -0.951057 -1.09821 -1.28583
endloop
endfacet
facet normal -0.987519 0.115655 0.106911
outer loop
vertex -0.951057 -1.36803 -0.993935
vertex -0.951057 -1.09821 -1.28583
vertex -1 -1.2989 -1.52081
endloop
endfacet
facet normal -0.704643 0.521047 0.481651
outer loop
vertex -0.809017 -1.14251 -0.830079
vertex -0.587785 -0.963525 -0.700042
vertex -0.809017 -0.91716 -1.07386
endloop
endfacet
facet normal -0.889723 0.335219 0.309873
outer loop
vertex -0.809017 -1.14251 -0.830079
vertex -0.809017 -0.91716 -1.07386
vertex -0.951057 -1.09821 -1.28583
endloop
endfacet
facet normal -0.451487 0.65522 0.605679
outer loop
vertex -0.587785 -0.963525 -0.700042
vertex -0.309017 -0.848613 -0.616554
vertex -0.587785 -0.773482 -0.90563
endloop
endfacet
facet normal -0.704643 0.521047 0.481651
outer loop
vertex -0.587785 -0.963525 -0.700042
vertex -0.587785 -0.773482 -0.90563
vertex -0.809017 -0.91716 -1.07386
endloop
endfacet
facet normal -0.155376 0.725404 0.670557
outer loop
vertex -0.309017 -0.848613 -0.616554
vertex 1.19249e-08 -0.809017 -0.587785
vertex -0.309017 -0.681235 -0.797623
endloop
endfacet
facet normal -0.451487 0.65522 0.605679
outer loop
vertex -0.309017 -0.848613 -0.616554
vertex -0.309017 -0.681235 -0.797623
vertex -0.587785 -0.773482 -0.90563
endloop
endfacet
facet normal 0.155376 0.725404 0.670557
outer loop
vertex 1.19249e-08 -0.809017 -0.587785
vertex 0.309017 -0.848613 -0.616554
vertex 1.19249e-08 -0.649448 -0.760406
endloop
endfacet
facet normal -0.155376 0.725404 0.670557
outer loop
vertex 1.19249e-08 -0.809017 -0.587785
vertex 1.19249e-08 -0.649448 -0.760406
vertex -0.309017 -0.681235 -0.797623
endloop
endfacet
facet normal 0.451487 0.65522 0.605679
outer loop
vertex 0.309017 -0.848613 -0.616554
vertex 0.587785 -0.963525 -0.700042
vertex 0.309017 -0.681235 -0.797623
endloop
endfacet
facet normal 0.155376 0.725404 0.670557
outer loop
vertex 0.309017 -0.848613 -0.616554
vertex 0.309017 -0.681235 -0.797623
vertex 1.19249e-08 -0.649448 -0.760406
endloop
endfacet
facet normal 0.704643 0.521047 0.481651
outer loop
vertex 0.587785 -0.963525 -0.700042
vertex 0.809017 -1.14251 -0.830079
vertex 0.587785 -0.773482 -0.90563
endloop
endfacet
facet normal 0.451487 0.65522 0.605679
outer loop
vertex 0.587785 -0.963525 -0.700042
vertex 0.587785 -0.773482 -0.90563
vertex 0.309017 -0.681235 -0.797623
endloop
endfacet
facet normal 0.889723 0.335219 0.309873
outer loop
vertex 0.809017 -1.14251 -0.830079
vertex 0.951057 -1.36803 -0.993935
vertex 0.809017 -0.91716 -1.07386
endloop
endfacet
facet normal 0.704643 0.521047 0.481651
outer loop
vertex 0.809017 -1.14251 -0.830079
vertex 0.809017 -0.91716 -1.07386
vertex 0.587785 -0.773482 -0.90563
endloop
endfacet
facet normal 0.987519 0.115655 0.106911
outer loop
vertex 0.951057 -1.36803 -0.993935
vertex 1 -1.61803 -1.17557
vertex 0.951057 -1.09821 -1.28583
endloop
endfacet
facet normal 0.889723 0.335219 0.309873
outer loop
vertex 0.951057 -1.36803 -0.993935
vertex 0.951057 -1.09821 -1.28583
vertex 0.809017 -0.91716 -1.07386
endloop
endfacet
facet normal 0.987519 -0.087502 -0.130956
outer loop
vertex 1 -1.2989 -1.52081
vertex 0.951057 -1.49959 -1.75579
vertex 1 -0.907981 -1.78201
endloop
endfacet
facet normal 0.987519 0.087502 0.130956
outer loop
vertex 1 -1.2989 -1.52081
vertex 1 -0.907981 -1.78201
vertex 0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal 0.889723 -0.253618 -0.379566
outer loop
vertex 0.951057 -1.49959 -1.75579
vertex 0.809017 -1.68063 -1.96777
vertex 0.951057 -1.04827 -2.05735
endloop
endfacet
facet normal 0.987519 -0.087502 -0.130956
outer loop
vertex 0.951057 -1.49959 -1.75579
vertex 0.951057 -1.04827 -2.05735
vertex 1 -0.907981 -1.78201
endloop
endfacet
facet normal 0.704643 -0.394212 -0.589979
outer loop
vertex 0.809017 -1.68063 -1.96777
vertex 0.587785 -1.82431 -2.13599
vertex 0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal 0.889723 -0.253618 -0.379566
outer loop
vertex 0.809017 -1.68063 -1.96777
vertex 0.809017 -1.17483 -2.30573
vertex 0.951057 -1.04827 -2.05735
endloop
endfacet
facet normal 0.451487 -0.495723 -0.741902
outer loop
vertex 0.587785 -1.82431 -2.13599
vertex 0.309017 -1.91656 -2.244
vertex 0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal 0.704643 -0.394212 -0.589979
outer loop
vertex 0.587785 -1.82431 -2.13599
vertex 0.587785 -1.27527 -2.50285
vertex 0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal 0.155376 -0.548823 -0.821371
outer loop
vertex 0.309017 -1.91656 -2.244
vertex -4.37114e-08 -1.94834 -2.28122
vertex 0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal 0.451487 -0.495723 -0.741902
outer loop
vertex 0.309017 -1.91656 -2.244
vertex 0.309017 -1.33975 -2.62941
vertex 0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal -0.155376 -0.548823 -0.821372
outer loop
vertex -4.37114e-08 -1.94834 -2.28122
vertex -0.309017 -1.91656 -2.244
vertex -4.37114e-08 -1.36197 -2.67302
endloop
endfacet
facet normal 0.155376 -0.548823 -0.821372
outer loop
vertex -4.37114e-08 -1.94834 -2.28122
vertex -4.37114e-08 -1.36197 -2.67302
vertex 0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal -0.451487 -0.495723 -0.741902
outer loop
vertex -0.309017 -1.91656 -2.244
vertex -0.587785 -1.82431 -2.13599
vertex -0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal -0.155376 -0.548823 -0.821371
outer loop
vertex -0.309017 -1.91656 -2.244
vertex -0.309017 -1.33975 -2.62941
vertex -4.37114e-08 -1.36197 -2.67302
endloop
endfacet
facet normal -0.704643 -0.394212 -0.589979
outer loop
vertex -0.587785 -1.82431 -2.13599
vertex -0.809017 -1.68063 -1.96777
vertex -0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal -0.451487 -0.495723 -0.741902
outer loop
vertex -0.587785 -1.82431 -2.13599
vertex -0.587785 -1.27527 -2.50285
vertex -0.309017 -1.33975 -2.62941
endloop
endfacet
facet normal -0.889723 -0.253618 -0.379566
outer loop
vertex -0.809017 -1.68063 -1.96777
vertex -0.951056 -1.49959 -1.75579
vertex -0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal -0.704643 -0.394212 -0.589979
outer loop
vertex -0.809017 -1.68063 -1.96777
vertex -0.809017 -1.17483 -2.30573
vertex -0.587785 -1.27527 -2.50285
endloop
endfacet
facet normal -0.987519 -0.087502 -0.130956
outer loop
vertex -0.951056 -1.49959 -1.75579
vertex -1 -1.2989 -1.52081
vertex -0.951056 -1.04827 -2.05735
endloop
endfacet
facet normal -0.889723 -0.253618 -0.379566
outer loop
vertex -0.951056 -1.49959 -1.75579
vertex -0.951056 -1.04827 -2.05735
vertex -0.809017 -1.17483 -2.30573
endloop
endfacet
facet normal -0.987519 0.087502 0.130956
outer loop
vertex -1 -1.2989 -1.52081
vertex -0.951057 -1.09821 -1.28583
vertex -1 -0.907981 -1.78201
endloop
endfacet
facet normal -0.987519 -0.0875021 -0.130956
outer loop
vertex -1 -1.2989 -1.52081
vertex -1 -0.907981 -1.78201
vertex -0.951056 -1.04827 -2.05735
endloop
endfacet
facet normal -0.889723 0.253618 0.379566
outer loop
vertex -0.951057 -1.09821 -1.28583
vertex -0.809017 -0.91716 -1.07386
vertex -0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal -0.987519 0.087502 0.130956
outer loop
vertex -0.951057 -1.09821 -1.28583
vertex -0.951057 -0.767691 -1.50668
vertex -1 -0.907981 -1.78201
endloop
endfacet
facet normal -0.704643 0.394212 0.589979
outer loop
vertex -0.809017 -0.91716 -1.07386
vertex -0.587785 -0.773482 -0.90563
vertex -0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal -0.889723 0.253619 0.379566
outer loop
vertex -0.809017 -0.91716 -1.07386
vertex -0.809017 -0.641132 -1.25829
vertex -0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal -0.451487 0.495723 0.741902
outer loop
vertex -0.587785 -0.773482 -0.90563
vertex -0.309017 -0.681235 -0.797623
vertex -0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal -0.704643 0.394212 0.589979
outer loop
vertex -0.587785 -0.773482 -0.90563
vertex -0.587785 -0.540695 -1.06117
vertex -0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal -0.155376 0.548823 0.821372
outer loop
vertex -0.309017 -0.681235 -0.797623
vertex 1.19249e-08 -0.649448 -0.760406
vertex -0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal -0.451487 0.495723 0.741902
outer loop
vertex -0.309017 -0.681235 -0.797623
vertex -0.309017 -0.476211 -0.934615
vertex -0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal 0.155376 0.548823 0.821371
outer loop
vertex 1.19249e-08 -0.649448 -0.760406
vertex 0.309017 -0.681235 -0.797623
vertex 1.19249e-08 -0.453991 -0.891006
endloop
endfacet
facet normal -0.155376 0.548823 0.821371
outer loop
vertex 1.19249e-08 -0.649448 -0.760406
vertex 1.19249e-08 -0.453991 -0.891006
vertex -0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal 0.451487 0.495723 0.741902
outer loop
vertex 0.309017 -0.681235 -0.797623
vertex 0.587785 -0.773482 -0.90563
vertex 0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal 0.155376 0.548823 0.821372
outer loop
vertex 0.309017 -0.681235 -0.797623
vertex 0.309017 -0.476211 -0.934615
vertex 1.19249e-08 -0.453991 -0.891006
endloop
endfacet
facet normal 0.704643 0.394212 0.589979
outer loop
vertex 0.587785 -0.773482 -0.90563
vertex 0.809017 -0.91716 -1.07386
vertex 0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal 0.451487 0.495723 0.741902
outer loop
vertex 0.587785 -0.773482 -0.90563
vertex 0.587785 -0.540695 -1.06117
vertex 0.309017 -0.476211 -0.934615
endloop
endfacet
facet normal 0.889723 0.253618 0.379567
outer loop
vertex 0.809017 -0.91716 -1.07386
vertex 0.951057 -1.09821 -1.28583
vertex 0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal 0.704643 0.394211 0.589979
outer loop
vertex 0.809017 -0.91716 -1.07386
vertex 0.809017 -0.641132 -1.25829
vertex 0.587785 -0.540695 -1.06117
endloop
endfacet
facet normal 0.987519 0.087502 0.130956
outer loop
vertex 0.951057 -1.09821 -1.28583
vertex 1 -1.2989 -1.52081
vertex 0.951057 -0.767691 -1.50668
endloop
endfacet
facet normal 0.889723 0.253618 0.379567
outer loop
vertex 0.951057 -1.09821 -1.28583
vertex 0.951057 -0.767691 -1.50668
vertex 0.809017 -0.641132 -1.25829
endloop
endfacet
facet normal 0.987519 -0.0545132 -0.147765
outer loop
vertex 1 -0.907981 -1.78201
vertex 0.951057 -1.04827 -2.05735
vertex 1 -0.466891 -1.94474
endloop
endfacet
facet normal 0.987519 0.0545132 0.147764
outer loop
vertex 1 -0.907981 -1.78201
vertex 1 -0.466891 -1.94474
vertex 0.951057 -0.394752 -1.64426
endloop
endfacet
facet normal 0.889723 -0.158003 -0.428285
outer loop
vertex 0.951057 -1.04827 -2.05735
vertex 0.809017 -1.17483 -2.30573
vertex 0.951057 -0.539029 -2.24522
endloop
endfacet
facet normal 0.987519 -0.0545132 -0.147765
outer loop
vertex 0.951057 -1.04827 -2.05735
vertex 0.951057 -0.539029 -2.24522
vertex 1 -0.466891 -1.94474
endloop
endfacet
facet normal 0.704643 -0.245591 -0.665705
outer loop
vertex 0.809017 -1.17483 -2.30573
vertex 0.587785 -1.27527 -2.50285
vertex 0.809017 -0.604107 -2.51628
endloop
endfacet
facet normal 0.889723 -0.158003 -0.428285
outer loop
vertex 0.809017 -1.17483 -2.30573
vertex 0.809017 -0.604107 -2.51628
vertex 0.951057 -0.539029 -2.24522
endloop
endfacet
facet normal 0.451487 -0.308833 -0.837127
outer loop
vertex 0.587785 -1.27527 -2.50285
vertex 0.309017 -1.33975 -2.62941
vertex 0.587785 -0.655752 -2.7314
endloop
endfacet
facet normal 0.704643 -0.245592 -0.665705
outer loop
vertex 0.587785 -1.27527 -2.50285
vertex 0.587785 -0.655752 -2.7314
vertex 0.809017 -0.604107 -2.51628
endloop
endfacet
facet normal 0.155376 -0.341914 -0.926797
outer loop
vertex 0.309017 -1.33975 -2.62941
vertex -4.37114e-08 -1.36197 -2.67302
vertex 0.309017 -0.688911 -2.86952
endloop
endfacet
facet normal 0.451487 -0.308833 -0.837127
outer loop
vertex 0.309017 -1.33975 -2.62941
vertex 0.309017 -0.688911 -2.86952
vertex 0.587785 -0.655752 -2.7314
endloop
endfacet
facet normal -0.155376 -0.341914 -0.926797
outer loop
vertex -4.37114e-08 -1.36197 -2.67302
vertex -0.309017 -1.33975 -2.62941
vertex -4.37114e-08 -0.700336 -2.91711
endloop
endfacet
facet normal 0.155376 -0.341914 -0.926797
outer loop
vertex -4.37114e-08 -1.36197 -2.67302
vertex -4.37114e-08 -0.700336 -2.91711
vertex 0.309017 -0.688911 -2.86952
endloop
endfacet
facet normal -0.451487 -0.308832 -0.837127
outer loop
vertex -0.309017 -1.33975 -2.62941
vertex -0.587785 -1.27527 -2.50285
vertex -0.309017 -0.688911 -2.86952
endloop
endfacet
facet normal -0.155376 -0.341914 -0.926797
outer loop
vertex -0.309017 -1.33975 -2.62941
vertex -0.309017 -0.688911 -2.86952
vertex -4.37114e-08 -0.700336 -2.91711
endloop
endfacet
facet normal -0.704643 -0.245592 -0.665705
outer loop
vertex -0.587785 -1.27527 -2.50285
vertex -0.809017 -1.17483 -2.30573
vertex -0.587785 -0.655752 -2.7314
endloop
endfacet
facet normal -0.451487 -0.308833 -0.837127
outer loop
vertex -0.587785 -1.27527 -2.50285
vertex -0.587785 -0.655752 -2.7314
vertex -0.309017 -0.688911 -2.86952
endloop
endfacet
facet normal -0.889723 -0.158003 -0.428285
outer loop
vertex -0.809017 -1.17483 -2.30573
vertex -0.951056 -1.04827 -2.05735
vertex -0.809017 -0.604107 -2.51628
endloop
endfacet
facet normal -0.704643 -0.245591 -0.665705
outer loop
vertex -0.809017 -1.17483 -2.30573
vertex -0.809017 -0.604107 -2.51628
vertex -0.587785 -0.655752 -2.7314
endloop
endfacet
facet normal -0.987519 -0.0545133 -0.147765
outer loop
vertex -0.951056 -1.04827 -2.05735
vertex -1 -0.907981 -1.78201
vertex -0.951056 -0.539029 -2.24522
endloop
endfacet
facet normal -0.889723 -0.158003 -0.428285
outer loop
vertex -0.951056 -1.04827 -2.05735
vertex -0.951056 -0.539029 -2.24522
vertex -0.809017 -0.604107 -2.51628
endloop
endfacet
facet normal -0.987519 0.0545132 0.147765
outer loop
vertex -1 -0.907981 -1.78201
vertex -0.951057 -0.767691 -1.50668
vertex -1 -0.466891 -1.94474
endloop
endfacet
facet normal -0.987519 -0.0545133 -0.147765
outer loop
vertex -1 -0.907981 -1.78201
vertex -1 -0.466891 -1.94474
vertex -0.951056 -0.539029 -2.24522
endloop
endfacet
facet normal -0.889723 0.158003 0.428285
outer loop
vertex -0.951057 -0.767691 -1.50668
vertex -0.809017 -0.641132 -1.25829
vertex -0.951057 -0.394752 -1.64426
endloop
endfacet
facet normal -0.987519 0.0545132 0.147765
outer loop
vertex -0.951057 -0.767691 -1.50668
vertex -0.951057 -0.394752 -1.64426
vertex -1 -0.466891 -1.94474
endloop
endfacet
facet normal -0.704643 0.245591 0.665705
outer loop
vertex -0.809017 -0.641132 -1.25829
vertex -0.587785 -0.540695 -1.06117
vertex -0.809017 -0.329675 -1.3732
endloop
endfacet
facet normal -0.889723 0.158003 0.428285
outer loop
vertex -0.809017 -0.641132 -1.25829
vertex -0.809017 -0.329675 -1.3732
vertex -0.951057 -0.394752 -1.64426
endloop
endfacet
facet normal -0.451487 0.308832 0.837127
outer loop
vertex -0.587785 -0.540695 -1.06117
vertex -0.309017 -0.476211 -0.934615
vertex -0.587785 -0.27803 -1.15808
endloop
endfacet
facet normal -0.704643 0.245591 0.665705
outer loop
vertex -0.587785 -0.540695 -1.06117
vertex -0.587785 -0.27803 -1.15808
vertex -0.809017 -0.329675 -1.3732
endloop
endfacet
facet normal -0.155376 0.341914 0.926797
outer loop
vertex -0.309017 -0.476211 -0.934615
vertex 1.19249e-08 -0.453991 -0.891006
vertex -0.309017 -0.244871 -1.01996
endloop
endfacet
facet normal -0.451487 0.308833 0.837127
outer loop
vertex -0.309017 -0.476211 -0.934615
vertex -0.309017 -0.244871 -1.01996
vertex -0.587785 -0.27803 -1.15808
endloop
endfacet
facet normal 0.155376 0.341914 0.926797
outer loop
vertex 1.19249e-08 -0.453991 -0.891006
vertex 0.309017 -0.476211 -0.934615
vertex 1.19249e-08 -0.233445 -0.97237
endloop
endfacet
facet normal -0.155376 0.341914 0.926797
outer loop
vertex 1.19249e-08 -0.453991 -0.891006
vertex 1.19249e-08 -0.233445 -0.97237
vertex -0.309017 -0.244871 -1.01996
endloop
endfacet
facet normal 0.451487 0.308833 0.837127
outer loop
vertex 0.309017 -0.476211 -0.934615
vertex 0.587785 -0.540695 -1.06117
vertex 0.309017 -0.244871 -1.01996
endloop
endfacet
facet normal 0.155376 0.341914 0.926797
outer loop
vertex 0.309017 -0.476211 -0.934615
vertex 0.309017 -0.244871 -1.01996
vertex 1.19249e-08 -0.233445 -0.97237
endloop
endfacet
facet normal 0.704643 0.245591 0.665705
outer loop
vertex 0.587785 -0.540695 -1.06117
vertex 0.809017 -0.641132 -1.25829
vertex 0.587785 -0.27803 -1.15808
endloop
endfacet
facet normal 0.451487 0.308832 0.837127
outer loop
vertex 0.587785 -0.540695 -1.06117
vertex 0.587785 -0.27803 -1.15808
vertex 0.309017 -0.244871 -1.01996
endloop
endfacet
facet normal 0.889723 0.158003 0.428285
outer loop
vertex 0.809017 -0.641132 -1.25829
vertex 0.951057 -0.767691 -1.50668
vertex 0.809017 -0.329675 -1.3732
endloop
endfacet
facet normal 0.704644 0.245592 0.665704
outer loop
vertex 0.809017 -0.641132 -1.25829
vertex 0.809017 -0.329675 -1.3732
vertex 0.587785 -0.27803 -1.15808
endloop
endfacet
facet normal 0.987519 0.0545132 0.147764
outer loop
vertex 0.951057 -0.767691 -1.50668
vertex 1 -0.907981 -1.78201
vertex 0.951057 -0.394752 -1.64426
endloop
endfacet
facet normal 0.889723 0.158003 0.428285
outer loop
vertex 0.951057 -0.767691 -1.50668
vertex 0.951057 -0.394752 -1.64426
vertex 0.809017 -0.329675 -1.3732
endloop
endfacet
facet normal 0.987519 -0.0185121 -0.156408
outer loop
vertex 1 -0.466891 -1.94474
vertex 0.951057 -0.539029 -2.24522
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 0.987519 0.0185121 0.156408
outer loop
vertex 1 -0.466891 -1.94474
vertex 1 2.38498e-08 -2
vertex 0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal 0.889723 -0.053656 -0.453336
outer loop
vertex 0.951057 -0.539029 -2.24522
vertex 0.809017 -0.604107 -2.51628
vertex 0.951057 2.75348e-08 -2.30902
endloop
endfacet
facet normal 0.987519 -0.0185121 -0.156408
outer loop
vertex 0.951057 -0.539029 -2.24522
vertex 0.951057 2.75348e-08 -2.30902
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 0.704643 -0.0834001 -0.704643
outer loop
vertex 0.809017 -0.604107 -2.51628
vertex 0.587785 -0.655752 -2.7314
vertex 0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal 0.889723 -0.0536559 -0.453337
outer loop
vertex 0.809017 -0.604107 -2.51628
vertex 0.809017 3.0859e-08 -2.58779
vertex 0.951057 2.75348e-08 -2.30902
endloop
endfacet
facet normal 0.451487 -0.104876 -0.886093
outer loop
vertex 0.587785 -0.655752 -2.7314
vertex 0.309017 -0.688911 -2.86952
vertex 0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal 0.704643 -0.0834 -0.704643
outer loop
vertex 0.587785 -0.655752 -2.7314
vertex 0.587785 3.34972e-08 -2.80902
vertex 0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal 0.155377 -0.11611 -0.981008
outer loop
vertex 0.309017 -0.688911 -2.86952
vertex -4.37114e-08 -0.700336 -2.91711
vertex 0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal 0.451487 -0.104876 -0.886093
outer loop
vertex 0.309017 -0.688911 -2.86952
vertex 0.309017 3.5191e-08 -2.95106
vertex 0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal -0.155377 -0.11611 -0.981008
outer loop
vertex -4.37114e-08 -0.700336 -2.91711
vertex -0.309017 -0.688911 -2.86952
vertex -4.37114e-08 3.57746e-08 -3
endloop
endfacet
facet normal 0.155377 -0.11611 -0.981008
outer loop
vertex -4.37114e-08 -0.700336 -2.91711
vertex -4.37114e-08 3.57746e-08 -3
vertex 0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal -0.451487 -0.104876 -0.886093
outer loop
vertex -0.309017 -0.688911 -2.86952
vertex -0.587785 -0.655752 -2.7314
vertex -0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal -0.155377 -0.11611 -0.981008
outer loop
vertex -0.309017 -0.688911 -2.86952
vertex -0.309017 3.5191e-08 -2.95106
vertex -4.37114e-08 3.57746e-08 -3
endloop
endfacet
facet normal -0.704643 -0.0834 -0.704643
outer loop
vertex -0.587785 -0.655752 -2.7314
vertex -0.809017 -0.604107 -2.51628
vertex -0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal -0.451487 -0.104876 -0.886093
outer loop
vertex -0.587785 -0.655752 -2.7314
vertex -0.587785 3.34972e-08 -2.80902
vertex -0.309017 3.5191e-08 -2.95106
endloop
endfacet
facet normal -0.889723 -0.0536559 -0.453336
outer loop
vertex -0.809017 -0.604107 -2.51628
vertex -0.951056 -0.539029 -2.24522
vertex -0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal -0.704643 -0.0834001 -0.704644
outer loop
vertex -0.809017 -0.604107 -2.51628
vertex -0.809017 3.0859e-08 -2.58779
vertex -0.587785 3.34972e-08 -2.80902
endloop
endfacet
facet normal -0.987519 -0.0185121 -0.156408
outer loop
vertex -0.951056 -0.539029 -2.24522
vertex -1 -0.466891 -1.94474
vertex -0.951056 2.75348e-08 -2.30902
endloop
endfacet
facet normal -0.889723 -0.0536559 -0.453336
outer loop
vertex -0.951056 -0.539029 -2.24522
vertex -0.951056 2.75348e-08 -2.30902
vertex -0.809017 3.0859e-08 -2.58779
endloop
endfacet
facet normal -0.987519 0.0185121 0.156408
outer loop
vertex -1 -0.466891 -1.94474
vertex -0.951057 -0.394752 -1.64426
vertex -1 2.38498e-08 -2
endloop
endfacet
facet normal -0.987519 -0.0185121 -0.156408
outer loop
vertex -1 -0.466891 -1.94474
vertex -1 2.38498e-08 -2
vertex -0.951056 2.75348e-08 -2.30902
endloop
endfacet
facet normal -0.889723 0.053656 0.453337
outer loop
vertex -0.951057 -0.394752 -1.64426
vertex -0.809017 -0.329675 -1.3732
vertex -0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal -0.987519 0.0185121 0.156408
outer loop
vertex -0.951057 -0.394752 -1.64426
vertex -0.951057 2.01648e-08 -1.69098
vertex -1 2.38498e-08 -2
endloop
endfacet
facet normal -0.704643 0.0834 0.704643
outer loop
vertex -0.809017 -0.329675 -1.3732
vertex -0.587785 -0.27803 -1.15808
vertex -0.809017 1.68405e-08 -1.41221
endloop
endfacet
facet normal -0.889723 0.0536559 0.453337
outer loop
vertex -0.809017 -0.329675 -1.3732
vertex -0.809017 1.68405e-08 -1.41221
vertex -0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal -0.451487 0.104876 0.886093
outer loop
vertex -0.587785 -0.27803 -1.15808
vertex -0.309017 -0.244871 -1.01996
vertex -0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal -0.704643 0.0834002 0.704643
outer loop
vertex -0.587785 -0.27803 -1.15808
vertex -0.587785 1.42023e-08 -1.19098
vertex -0.809017 1.68405e-08 -1.41221
endloop
endfacet
facet normal -0.155376 0.11611 0.981008
outer loop
vertex -0.309017 -0.244871 -1.01996
vertex 1.19249e-08 -0.233445 -0.97237
vertex -0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal -0.451487 0.104876 0.886093
outer loop
vertex -0.309017 -0.244871 -1.01996
vertex -0.309017 1.25085e-08 -1.04894
vertex -0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal 0.155376 0.11611 0.981008
outer loop
vertex 1.19249e-08 -0.233445 -0.97237
vertex 0.309017 -0.244871 -1.01996
vertex 1.19249e-08 1.19249e-08 -1
endloop
endfacet
facet normal -0.155376 0.11611 0.981008
outer loop
vertex 1.19249e-08 -0.233445 -0.97237
vertex 1.19249e-08 1.19249e-08 -1
vertex -0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal 0.451487 0.104876 0.886093
outer loop
vertex 0.309017 -0.244871 -1.01996
vertex 0.587785 -0.27803 -1.15808
vertex 0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal 0.155376 0.11611 0.981008
outer loop
vertex 0.309017 -0.244871 -1.01996
vertex 0.309017 1.25085e-08 -1.04894
vertex 1.19249e-08 1.19249e-08 -1
endloop
endfacet
facet normal 0.704644 0.0834001 0.704643
outer loop
vertex 0.587785 -0.27803 -1.15808
vertex 0.809017 -0.329675 -1.3732
vertex 0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal 0.451487 0.104876 0.886093
outer loop
vertex 0.587785 -0.27803 -1.15808
vertex 0.587785 1.42023e-08 -1.19098
vertex 0.309017 1.25085e-08 -1.04894
endloop
endfacet
facet normal 0.889723 0.0536559 0.453337
outer loop
vertex 0.809017 -0.329675 -1.3732
vertex 0.951057 -0.394752 -1.64426
vertex 0.809017 1.68405e-08 -1.41221
endloop
endfacet
facet normal 0.704643 0.0833999 0.704643
outer loop
vertex 0.809017 -0.329675 -1.3732
vertex 0.809017 1.68405e-08 -1.41221
vertex 0.587785 1.42023e-08 -1.19098
endloop
endfacet
facet normal 0.987519 0.0185121 0.156408
outer loop
vertex 0.951057 -0.394752 -1.64426
vertex 1 -0.466891 -1.94474
vertex 0.951057 2.01648e-08 -1.69098
endloop
endfacet
facet normal 0.889723 0.053656 0.453337
outer loop
vertex 0.951057 -0.394752 -1.64426
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
facet normal nan nan nan
outer loop
vertex 0.951057 2.01648e-08 -1.69098
vertex 1 2.38498e-08 -2
vertex 1 2.38498e-08 -2
endloop
endfacet
facet normal 0.975821 0.154555 -0.154555
outer loop
vertex -4 2 0
vertex -4.04894 2.30902 0
vertex -3.80423 2 1.23607
endloop
endfacet
facet normal 0.97582 -0.154555 -0.154555
outer loop
vertex -4 2 0
vertex -3.80423 2 1.23607
vertex -3.85077 1.69098 1.25119
endloop
endfacet
facet normal 0.882265 0.449536 -0.139737
outer loop
vertex -4.04894 2.30902 0
vertex -4.19098 2.58779 0
vertex -3.85077 2.30902 1.25119
endloop
endfacet
facet normal 0.97582 0.154555 -0.154555
outer loop
vertex -4.04894 2.30902 0
vertex -3.85077 2.30902 1.25119
vertex -3.80423 2 1.23607
endloop
endfacet
facet normal 0.702713 0.702714 -0.111299
outer loop
vertex -4.19098 2.58779 0
vertex -4.41221 2.80902 0
vertex -3.98586 2.58779 1.29508
endloop
endfacet
facet normal 0.882265 0.449535 -0.139737
outer loop
vertex -4.19098 2.58779 0
vertex -3.98586 2.58779 1.29508
vertex -3.85077 2.30902 1.25119
endloop
endfacet
facet normal 0.452822 0.888712 -0.0717199
outer loop
vertex -4.41221 2.80902 0
vertex -4.69098 2.95106 0
vertex -4.19627 2.80902 1.36345
endloop
endfacet
facet normal 0.702713 0.702714 -0.111299
outer loop
vertex -4.41221 2.80902 0
vertex -4.19627 2.80902 1.36345
vertex -3.98586 2.58779 1.29508
endloop
endfacet
facet normal 0.156386 0.987385 -0.0247692
outer loop
vertex -4.69098 2.95106 0
vertex -5 3 0
vertex -4.46139 2.95106 1.44959
endloop
endfacet
facet normal 0.452822 0.888712 -0.0717198
outer loop
vertex -4.69098 2.95106 0
vertex -4.46139 2.95106 1.44959
vertex -4.19627 2.80902 1.36345
endloop
endfacet
facet normal -0.156386 0.987385 0.0247692
outer loop
vertex -5 3 0
vertex -5.30902 2.95106 0
vertex -4.75528 3 1.54508
endloop
endfacet
facet normal 0.156386 0.987385 -0.0247692
outer loop
vertex -5 3 0
vertex -4.75528 3 1.54508
vertex -4.46139 2.95106 1.44959
endloop
endfacet
facet normal -0.452822 0.888712 0.0717198
outer loop
vertex -5.30902 2.95106 0
vertex -5.58779 2.80902 0
vertex -5.04918 2.95106 1.64058
endloop
endfacet
facet normal -0.156386 0.987385 0.0247692
outer loop
vertex -5.30902 2.95106 0
vertex -5.04918 2.95106 1.64058
vertex -4.75528 3 1.54508
endloop
endfacet
facet normal -0.702713 0.702714 0.111299
outer loop
vertex -5.58779 2.80902 0
vertex -5.80902 2.58779 0
vertex -5.3143 2.80902 1.72672
endloop
endfacet
facet normal -0.452822 0.888712 0.07172
outer loop
vertex -5.58779 2.80902 0
vertex -5.3143 2.80902 1.72672
vertex -5.04918 2.95106 1.64058
endloop
endfacet
facet normal -0.882265 0.449536 0.139737
outer loop
vertex -5.80902 2.58779 0
vertex -5.95106 2.30902 0
vertex -5.5247 2.58779 1.79509
endloop
endfacet
facet normal -0.702713 0.702714 0.111299
outer loop
vertex -5.80902 2.58779 0
vertex -5.5247 2.58779 1.79509
vertex -5.3143 2.80902 1.72672
endloop
endfacet
facet normal -0.97582 0.154555 0.154555
outer loop
vertex -5.95106 2.30902 0
vertex -6 2 0
vertex -5.65979 2.30902 1.83898
endloop
endfacet
facet normal -0.882265 0.449535 0.139737
outer loop
vertex -5.95106 2.30902 0
vertex -5.65979 2.30902 1.83898
vertex -5.5247 2.58779 1.79509
endloop
endfacet
facet normal -0.975821 -0.154555 0.154555
outer loop
vertex -6 2 0
vertex -5.95106 1.69098 0
vertex -5.70634 2 1.8541
endloop
endfacet
facet normal -0.97582 0.154556 0.154555
outer loop
vertex -6 2 0
vertex -5.70634 2 1.8541
vertex -5.65979 2.30902 1.83898
endloop
endfacet
facet normal -0.882265 -0.449535 0.139737
outer loop
vertex -5.95106 1.69098 0
vertex -5.80902 1.41221 0
vertex -5.65979 1.69098 1.83898
endloop
endfacet
facet normal -0.97582 -0.154556 0.154555
outer loop
vertex -5.95106 1.69098 0
vertex -5.65979 1.69098 1.83898
vertex -5.70634 2 1.8541
endloop
endfacet
facet normal -0.702713 -0.702714 0.111299
outer loop
vertex -5.80902 1.41221 0
vertex -5.58779 1.19098 0
vertex -5.5247 1.41221 1.79509
endloop
endfacet
facet normal -0.882265 -0.449535 0.139737
outer loop
vertex -5.80902 1.41221 0
vertex -5.5247 1.41221 1.79509
vertex -5.65979 1.69098 1.83898
endloop
endfacet
facet normal -0.452821 -0.888712 0.0717198
outer loop
vertex -5.58779 1.19098 0
vertex -5.30902 1.04894 0
vertex -5.3143 1.19098 1.72672
endloop
endfacet
facet normal -0.702713 -0.702714 0.111299
outer loop
vertex -5.58779 1.19098 0
vertex -5.3143 1.19098 1.72672
vertex -5.5247 1.41221 1.79509
endloop
endfacet
facet normal -0.156386 -0.987385 0.0247692
outer loop
vertex -5.30902 1.04894 0
vertex -5 1 0
vertex -5.04918 1.04894 1.64058
endloop
endfacet
facet normal -0.452822 -0.888712 0.0717198
outer loop
vertex -5.30902 1.04894 0
vertex -5.04918 1.04894 1.64058
vertex -5.3143 1.19098 1.72672
endloop
endfacet
facet normal 0.156386 -0.987385 -0.0247692
outer loop
vertex -5 1 0
vertex -4.69098 1.04894 0
vertex -4.75528 1 1.54508
endloop
endfacet
facet normal -0.156386 -0.987385 0.0247692
outer loop
vertex -5 1 0
vertex -4.75528 1 1.54508
vertex -5.04918 1.04894 1.64058
endloop
endfacet
facet normal 0.452821 -0.888712 -0.0717197
outer loop
vertex -4.69098 1.04894 0
vertex -4.41221 1.19098 0
vertex -4.46139 1.04894 1.44959
endloop
endfacet
facet normal 0.156386 -0.987385 -0.0247692
outer loop
vertex -4.69098 1.04894 0
vertex -4.46139 1.04894 1.44959
vertex -4.75528 1 1.54508
endloop
endfacet
facet normal 0.702713 -0.702713 -0.111299
outer loop
vertex -4.41221 1.19098 0
vertex -4.19098 1.41221 0
vertex -4.19627 1.19098 1.36345
endloop
endfacet
facet normal 0.452821 -0.888712 -0.0717198
outer loop
vertex -4.41221 1.19098 0
vertex -4.19627 1.19098 1.36345
vertex -4.46139 1.04894 1.44959
endloop
endfacet
facet normal 0.882265 -0.449536 -0.139737
outer loop
vertex -4.19098 1.41221 0
vertex -4.04894 1.69098 0
vertex -3.98586 1.41221 1.29508
endloop
endfacet
facet normal 0.702713 -0.702714 -0.111299
outer loop
vertex -4.19098 1.41221 0
vertex -3.98586 1.41221 1.29508
vertex -4.19627 1.19098 1.36345
endloop
endfacet
facet normal 0.97582 -0.154555 -0.154555
outer loop
vertex -4.04894 1.69098 0
vertex -4 2 0
vertex -3.85077 1.69098 1.25119
endloop
endfacet
facet normal 0.882265 -0.449535 -0.139737
outer loop
vertex -4.04894 1.69098 0
vertex -3.85077 1.69098 1.25119
vertex -3.98586 1.41221 1.29508
endloop
endfacet
facet normal 0.8803 0.154555 -0.448535
outer loop
vertex -3.80423 2 1.23607
vertex -3.85077 2.30902 1.25119
vertex -3.23607 2 2.35114
endloop
endfacet
facet normal 0.8803 -0.154555 -0.448536
outer loop
vertex -3.80423 2 1.23607
vertex -3.23607 2 2.35114
vertex -3.27566 1.69098 2.37991
endloop
endfacet
facet normal 0.795903 0.449535 -0.405533
outer loop
vertex -3.85077 2.30902 1.25119
vertex -3.98586 2.58779 1.29508
vertex -3.27566 2.30902 2.37991
endloop
endfacet
facet normal 0.8803 0.154555 -0.448536
outer loop
vertex -3.85077 2.30902 1.25119
vertex -3.27566 2.30902 2.37991
vertex -3.23607 2 2.35114
endloop
endfacet
facet normal 0.633927 0.702714 -0.323002
outer loop
vertex -3.98586 2.58779 1.29508
vertex -4.19627 2.80902 1.36345
vertex -3.39058 2.58779 2.4634
endloop
endfacet
facet normal 0.795903 0.449536 -0.405533
outer loop
vertex -3.98586 2.58779 1.29508
vertex -3.39058 2.58779 2.4634
vertex -3.27566 2.30902 2.37991
endloop
endfacet
facet normal 0.408496 0.888712 -0.208139
outer loop
vertex -4.19627 2.80902 1.36345
vertex -4.46139 2.95106 1.44959
vertex -3.56956 2.80902 2.59343
endloop
endfacet
facet normal 0.633927 0.702714 -0.323002
outer loop
vertex -4.19627 2.80902 1.36345
vertex -3.56956 2.80902 2.59343
vertex -3.39058 2.58779 2.4634
endloop
endfacet
facet normal 0.141078 0.987385 -0.071883
outer loop
vertex -4.46139 2.95106 1.44959
vertex -4.75528 3 1.54508
vertex -3.79508 2.95106 2.75729
endloop
endfacet
facet normal 0.408496 0.888712 -0.208139
outer loop
vertex -4.46139 2.95106 1.44959
vertex -3.79508 2.95106 2.75729
vertex -3.56956 2.80902 2.59343
endloop
endfacet
facet normal -0.141078 0.987385 0.071883
outer loop
vertex -4.75528 3 1.54508
vertex -5.04918 2.95106 1.64058
vertex -4.04508 3 2.93893
endloop
endfacet
facet normal 0.141078 0.987385 -0.071883
outer loop
vertex -4.75528 3 1.54508
vertex -4.04508 3 2.93893
vertex -3.79508 2.95106 2.75729
endloop
endfacet
facet normal -0.408497 0.888712 0.20814
outer loop
vertex -5.04918 2.95106 1.64058
vertex -5.3143 2.80902 1.72672
vertex -4.29508 2.95106 3.12056
endloop
endfacet
facet normal -0.141078 0.987385 0.071883
outer loop
vertex -5.04918 2.95106 1.64058
vertex -4.29508 2.95106 3.12056
vertex -4.04508 3 2.93893
endloop
endfacet
facet normal -0.633926 0.702714 0.323002
outer loop
vertex -5.3143 2.80902 1.72672
vertex -5.5247 2.58779 1.79509
vertex -4.52061 2.80902 3.28442
endloop
endfacet
facet normal -0.408496 0.888712 0.208139
outer loop
vertex -5.3143 2.80902 1.72672
vertex -4.52061 2.80902 3.28442
vertex -4.29508 2.95106 3.12056
endloop
endfacet
facet normal -0.795903 0.449535 0.405533
outer loop
vertex -5.5247 2.58779 1.79509
vertex -5.65979 2.30902 1.83898
vertex -4.69959 2.58779 3.41445
endloop
endfacet
facet normal -0.633927 0.702714 0.323002
outer loop
vertex -5.5247 2.58779 1.79509
vertex -4.69959 2.58779 3.41445
vertex -4.52061 2.80902 3.28442
endloop
endfacet
facet normal -0.8803 0.154556 0.448535
outer loop
vertex -5.65979 2.30902 1.83898
vertex -5.70634 2 1.8541
vertex -4.81451 2.30902 3.49794
endloop
endfacet
facet normal -0.795903 0.449536 0.405533
outer loop
vertex -5.65979 2.30902 1.83898
vertex -4.81451 2.30902 3.49794
vertex -4.69959 2.58779 3.41445
endloop
endfacet
facet normal -0.8803 -0.154556 0.448535
outer loop
vertex -5.70634 2 1.8541
vertex -5.65979 1.69098 1.83898
vertex -4.8541 2 3.52671
endloop
endfacet
facet normal -0.8803 0.154555 0.448536
outer loop
vertex -5.70634 2 1.8541
vertex -4.8541 2 3.52671
vertex -4.81451 2.30902 3.49794
endloop
endfacet
facet normal -0.795903 -0.449535 0.405533
outer loop
vertex -5.65979 1.69098 1.83898
vertex -5.5247 1.41221 1.79509
vertex -4.81451 1.69098 3.49794
endloop
endfacet
facet normal -0.8803 -0.154555 0.448535
outer loop
vertex -5.65979 1.69098 1.83898
vertex -4.81451 1.69098 3.49794
vertex -4.8541 2 3.52671
endloop
endfacet
facet normal -0.633926 -0.702714 0.323002
outer loop
vertex -5.5247 1.41221 1.79509
vertex -5.3143 1.19098 1.72672
vertex -4.69959 1.41221 3.41445
endloop
endfacet
facet normal -0.795902 -0.449536 0.405533
outer loop
vertex -5.5247 1.41221 1.79509
vertex -4.69959 1.41221 3.41445
vertex -4.81451 1.69098 3.49794
endloop
endfacet
facet normal -0.408496 -0.888712 0.208139
outer loop
vertex -5.3143 1.19098 1.72672
vertex -5.04918 1.04894 1.64058
vertex -4.52061 1.19098 3.28442
endloop
endfacet
facet normal -0.633927 -0.702714 0.323002
outer loop
vertex -5.3143 1.19098 1.72672
vertex -4.52061 1.19098 3.28442
vertex -4.69959 1.41221 3.41445
endloop
endfacet
facet normal -0.141078 -0.987385 0.071883
outer loop
vertex -5.04918 1.04894 1.64058
vertex -4.75528 1 1.54508
vertex -4.29508 1.04894 3.12056
endloop
endfacet
facet normal -0.408496 -0.888712 0.208139
outer loop
vertex -5.04918 1.04894 1.64058
vertex -4.29508 1.04894 3.12056
vertex -4.52061 1.19098 3.28442
endloop
endfacet
facet normal 0.141078 -0.987385 -0.071883
outer loop
vertex -4.75528 1 1.54508
vertex -4.46139 1.04894 1.44959
vertex -4.04508 1 2.93893
endloop
endfacet
facet normal -0.141078 -0.987385 0.071883
outer loop
vertex -4.75528 1 1.54508
vertex -4.04508 1 2.93893
vertex -4.29508 1.04894 3.12056
endloop
endfacet
facet normal 0.408496 -0.888712 -0.208139
outer loop
vertex -4.46139 1.04894 1.44959
vertex -4.19627 1.19098 1.36345
vertex -3.79508 1.04894 2.75729
endloop
endfacet
facet normal 0.141078 -0.987385 -0.071883
outer loop
vertex -4.46139 1.04894 1.44959
vertex -3.79508 1.04894 2.75729
vertex -4.04508 1 2.93893
endloop
endfacet
facet normal 0.633927 -0.702714 -0.323002
outer loop
vertex -4.19627 1.19098 1.36345
vertex -3.98586 1.41221 1.29508
vertex -3.56956 1.19098 2.59343
endloop
endfacet
facet normal 0.408496 -0.888712 -0.208139
outer loop
vertex -4.19627 1.19098 1.36345
vertex -3.56956 1.19098 2.59343
vertex -3.79508 1.04894 2.75729
endloop
endfacet
facet normal 0.795903 -0.449535 -0.405533
outer loop
vertex -3.98586 1.41221 1.29508
vertex -3.85077 1.69098 1.25119
vertex -3.39058 1.41221 2.4634
endloop
endfacet
facet normal 0.633927 -0.702714 -0.323002
outer loop
vertex -3.98586 1.41221 1.29508
vertex -3.39058 1.41221 2.4634
vertex -3.56956 1.19098 2.59343
endloop
endfacet
facet normal 0.8803 -0.154555 -0.448536
outer loop
vertex -3.85077 1.69098 1.25119
vertex -3.80423 2 1.23607
vertex -3.27566 1.69098 2.37991
endloop
endfacet
facet normal 0.795903 -0.449536 -0.405533
outer loop
vertex -3.85077 1.69098 1.25119
vertex -3.27566 1.69098 2.37991
vertex -3.39058 1.41221 2.4634
endloop
endfacet
facet normal 0.69861 0.154555 -0.69861
outer loop
vertex -3.23607 2 2.35114
vertex -3.27566 2.30902 2.37991
vertex -2.35114 2 3.23607
endloop
endfacet
facet normal 0.69861 -0.154555 -0.69861
outer loop
vertex -3.23607 2 2.35114
vertex -2.35114 2 3.23607
vertex -2.37991 1.69098 3.27566
endloop
endfacet
facet normal 0.631632 0.449535 -0.631632
outer loop
vertex -3.27566 2.30902 2.37991
vertex -3.39058 2.58779 2.4634
vertex -2.37991 2.30902 3.27566
endloop
endfacet
facet normal 0.69861 0.154555 -0.69861
outer loop
vertex -3.27566 2.30902 2.37991
vertex -2.37991 2.30902 3.27566
vertex -2.35114 2 3.23607
endloop
endfacet
facet normal 0.503087 0.702714 -0.503087
outer loop
vertex -3.39058 2.58779 2.4634
vertex -3.56956 2.80902 2.59343
vertex -2.4634 2.58779 3.39058
endloop
endfacet
facet normal 0.631632 0.449536 -0.631632
outer loop
vertex -3.39058 2.58779 2.4634
vertex -2.4634 2.58779 3.39058
vertex -2.37991 2.30902 3.27566
endloop
endfacet
facet normal 0.324185 0.888712 -0.324185
outer loop
vertex -3.56956 2.80902 2.59343
vertex -3.79508 2.95106 2.75729
vertex -2.59343 2.80902 3.56956
endloop
endfacet
facet normal 0.503087 0.702714 -0.503087
outer loop
vertex -3.56956 2.80902 2.59343
vertex -2.59343 2.80902 3.56956
vertex -2.4634 2.58779 3.39058
endloop
endfacet
facet normal 0.11196 0.987385 -0.11196
outer loop
vertex -3.79508 2.95106 2.75729
vertex -4.04508 3 2.93893
vertex -2.75729 2.95106 3.79508
endloop
endfacet
facet normal 0.324185 0.888712 -0.324185
outer loop
vertex -3.79508 2.95106 2.75729
vertex -2.75729 2.95106 3.79508
vertex -2.59343 2.80902 3.56956
endloop
endfacet
facet normal -0.11196 0.987385 0.11196
outer loop
vertex -4.04508 3 2.93893
vertex -4.29508 2.95106 3.12056
vertex -2.93893 3 4.04508
endloop
endfacet
facet normal 0.11196 0.987385 -0.11196
outer loop
vertex -4.04508 3 2.93893
vertex -2.93893 3 4.04508
vertex -2.75729 2.95106 3.79508
endloop
endfacet
facet normal -0.324185 0.888712 0.324185
outer loop
vertex -4.29508 2.95106 3.12056
vertex -4.52061 2.80902 3.28442
vertex -3.12056 2.95106 4.29508
endloop
endfacet
facet normal -0.11196 0.987385 0.11196
outer loop
vertex -4.29508 2.95106 3.12056
vertex -3.12056 2.95106 4.29508
vertex -2.93893 3 4.04508
endloop
endfacet
facet normal -0.503087 0.702714 0.503087
outer loop
vertex -4.52061 2.80902 3.28442
vertex -4.69959 2.58779 3.41445
vertex -3.28442 2.80902 4.52061
endloop
endfacet
facet normal -0.324185 0.888712 0.324185
outer loop
vertex -4.52061 2.80902 3.28442
vertex -3.28442 2.80902 4.52061
vertex -3.12056 2.95106 4.29508
endloop
endfacet
facet normal -0.631632 0.449536 0.631632
outer loop
vertex -4.69959 2.58779 3.41445
vertex -4.81451 2.30902 3.49794
vertex -3.41445 2.58779 4.69959
endloop
endfacet
facet normal -0.503087 0.702714 0.503087
outer loop
vertex -4.69959 2.58779 3.41445
vertex -3.41445 2.58779 4.69959
vertex -3.28442 2.80902 4.52061
endloop
endfacet
facet normal -0.69861 0.154555 0.69861
outer loop
vertex -4.81451 2.30902 3.49794
vertex -4.8541 2 3.52671
vertex -3.49794 2.30902 4.81451
endloop
endfacet
facet normal -0.631632 0.449536 0.631632
outer loop
vertex -4.81451 2.30902 3.49794
vertex -3.49794 2.30902 4.81451
vertex -3.41445 2.58779 4.69959
endloop
endfacet
facet normal -0.69861 -0.154555 0.69861
outer loop
vertex -4.8541 2 3.52671
vertex -4.81451 1.69098 3.49794
vertex -3.52671 2 4.8541
endloop
endfacet
facet normal -0.69861 0.154555 0.69861
outer loop
vertex -4.8541 2 3.52671
vertex -3.52671 2 4.8541
vertex -3.49794 2.30902 4.81451
endloop
endfacet
facet normal -0.631632 -0.449536 0.631632
outer loop
vertex -4.81451 1.69098 3.49794
vertex -4.69959 1.41221 3.41445
vertex -3.49794 1.69098 4.81451
endloop
endfacet
facet normal -0.69861 -0.154555 0.69861
outer loop
vertex -4.81451 1.69098 3.49794
vertex -3.49794 1.69098 4.81451
vertex -3.52671 2 4.8541
endloop
endfacet
facet normal -0.503087 -0.702714 0.503087
outer loop
vertex -4.69959 1.41221 3.41445
vertex -4.52061 1.19098 3.28442
vertex -3.41445 1.41221 4.69959
endloop
endfacet
facet normal -0.631632 -0.449536 0.631632
outer loop
vertex -4.69959 1.41221 3.41445
vertex -3.41445 1.41221 4.69959
vertex -3.49794 1.69098 4.81451
endloop
endfacet
facet normal -0.324184 -0.888712 0.324184
outer loop
vertex -4.52061 1.19098 3.28442
vertex -4.29508 1.04894 3.12056
vertex -3.28442 1.19098 4.52061
endloop
endfacet
facet normal -0.503087 -0.702714 0.503087
outer loop
vertex -4.52061 1.19098 3.28442
vertex -3.28442 1.19098 4.52061
vertex -3.41445 1.41221 4.69959
endloop
endfacet
facet normal -0.11196 -0.987385 0.11196
outer loop
vertex -4.29508 1.04894 3.12056
vertex -4.04508 1 2.93893
vertex -3.12056 1.04894 4.29508
endloop
endfacet
facet normal -0.324184 -0.888712 0.324184
outer loop
vertex -4.29508 1.04894 3.12056
vertex -3.12056 1.04894 4.29508
vertex -3.28442 1.19098 4.52061
endloop
endfacet
facet normal 0.11196 -0.987385 -0.11196
outer loop
vertex -4.04508 1 2.93893
vertex -3.79508 1.04894 2.75729
vertex -2.93893 1 4.04508
endloop
endfacet
facet normal -0.11196 -0.987385 0.11196
outer loop
vertex -4.04508 1 2.93893
vertex -2.93893 1 4.04508
vertex -3.12056 1.04894 4.29508
endloop
endfacet
facet normal 0.324184 -0.888712 -0.324184
outer loop
vertex -3.79508 1.04894 2.75729
vertex -3.56956 1.19098 2.59343
vertex -2.75729 1.04894 3.79508
endloop
endfacet
facet normal 0.11196 -0.987385 -0.11196
outer loop
vertex -3.79508 1.04894 2.75729
vertex -2.75729 1.04894 3.79508
vertex -2.93893 1 4.04508
endloop
endfacet
facet normal 0.503087 -0.702714 -0.503087
outer loop
vertex -3.56956 1.19098 2.59343
vertex -3.39058 1.41221 2.4634
vertex -2.59343 1.19098 3.56956
endloop
endfacet
facet normal 0.324184 -0.888712 -0.324184
outer loop
vertex -3.56956 1.19098 2.59343
vertex -2.59343 1.19098 3.56956
vertex -2.75729 1.04894 3.79508
endloop
endfacet
facet normal 0.631632 -0.449536 -0.631632
outer loop
vertex -3.39058 1.41221 2.4634
vertex -3.27566 1.69098 2.37991
vertex -2.4634 1.41221 3.39058
endloop
endfacet
facet normal 0.503087 -0.702714 -0.503087
outer loop
vertex -3.39058 1.41221 2.4634
vertex -2.4634 1.41221 3.39058
vertex -2.59343 1.19098 3.56956
endloop
endfacet
facet normal 0.69861 -0.154555 -0.69861
outer loop
vertex -3.27566 1.69098 2.37991
vertex -3.23607 2 2.35114
vertex -2.37991 1.69098 3.27566
endloop
endfacet
facet normal 0.631632 -0.449535 -0.631632
outer loop
vertex -3.27566 1.69098 2.37991
vertex -2.37991 1.69098 3.27566
vertex -2.4634 1.41221 3.39058
endloop
endfacet
facet normal 0.448535 0.154555 -0.8803
outer loop
vertex -2.35114 2 3.23607
vertex -2.37991 2.30902 3.27566
vertex -1.23607 2 3.80423
endloop
endfacet
facet normal 0.448535 -0.154555 -0.8803
outer loop
vertex -2.35114 2 3.23607
vertex -1.23607 2 3.80423
vertex -1.25119 1.69098 3.85077
endloop
endfacet
facet normal 0.405533 0.449536 -0.795903
outer loop
vertex -2.37991 2.30902 3.27566
vertex -2.4634 2.58779 3.39058
vertex -1.25119 2.30902 3.85077
endloop
endfacet
facet normal 0.448535 0.154555 -0.8803
outer loop
vertex -2.37991 2.30902 3.27566
vertex -1.25119 2.30902 3.85077
vertex -1.23607 2 3.80423
endloop
endfacet
facet normal 0.323002 0.702714 -0.633927
outer loop
vertex -2.4634 2.58779 3.39058
vertex -2.59343 2.80902 3.56956
vertex -1.29508 2.58779 3.98586
endloop
endfacet
facet normal 0.405533 0.449535 -0.795903
outer loop
vertex -2.4634 2.58779 3.39058
vertex -1.29508 2.58779 3.98586
vertex -1.25119 2.30902 3.85077
endloop
endfacet
facet normal 0.208139 0.888712 -0.408496
outer loop
vertex -2.59343 2.80902 3.56956
vertex -2.75729 2.95106 3.79508
vertex -1.36345 2.80902 4.19627
endloop
endfacet
facet normal 0.323002 0.702714 -0.633927
outer loop
vertex -2.59343 2.80902 3.56956
vertex -1.36345 2.80902 4.19627
vertex -1.29508 2.58779 3.98586
endloop
endfacet
facet normal 0.071883 0.987385 -0.141078
outer loop
vertex -2.75729 2.95106 3.79508
vertex -2.93893 3 4.04508
vertex -1.44959 2.95106 4.46139
endloop
endfacet
facet normal 0.208139 0.888712 -0.408496
outer loop
vertex -2.75729 2.95106 3.79508
vertex -1.44959 2.95106 4.46139
vertex -1.36345 2.80902 4.19627
endloop
endfacet
facet normal -0.071883 0.987385 0.141078
outer loop
vertex -2.93893 3 4.04508
vertex -3.12056 2.95106 4.29508
vertex -1.54508 3 4.75528
endloop
endfacet
facet normal 0.071883 0.987385 -0.141078
outer loop
vertex -2.93893 3 4.04508
vertex -1.54508 3 4.75528
vertex -1.44959 2.95106 4.46139
endloop
endfacet
facet normal -0.208139 0.888712 0.408496
outer loop
vertex -3.12056 2.95106 4.29508
vertex -3.28442 2.80902 4.52061
vertex -1.64058 2.95106 5.04918
endloop
endfacet
facet normal -0.071883 0.987385 0.141078
outer loop
vertex -3.12056 2.95106 4.29508
vertex -1.64058 2.95106 5.04918
vertex -1.54508 3 4.75528
endloop
endfacet
facet normal -0.323002 0.702714 0.633927
outer loop
vertex -3.28442 2.80902 4.52061
vertex -3.41445 2.58779 4.69959
vertex -1.72672 2.80902 5.3143
endloop
endfacet
facet normal -0.208139 0.888712 0.408497
outer loop
vertex -3.28442 2.80902 4.52061
vertex -1.72672 2.80902 5.3143
vertex -1.64058 2.95106 5.04918
endloop
endfacet
facet normal -0.405533 0.449536 0.795902
outer loop
vertex -3.41445 2.58779 4.69959
vertex -3.49794 2.30902 4.81451
vertex -1.79508 2.58779 5.5247
endloop
endfacet
facet normal -0.323002 0.702714 0.633926
outer loop
vertex -3.41445 2.58779 4.69959
vertex -1.79508 2.58779 5.5247
vertex -1.72672 2.80902 5.3143
endloop
endfacet
facet normal -0.448535 0.154555 0.8803
outer loop
vertex -3.49794 2.30902 4.81451
vertex -3.52671 2 4.8541
vertex -1.83898 2.30902 5.65979
endloop
endfacet
facet normal -0.405533 0.449535 0.795903
outer loop
vertex -3.49794 2.30902 4.81451
vertex -1.83898 2.30902 5.65979
vertex -1.79508 2.58779 5.5247
endloop
endfacet
facet normal -0.448536 -0.154555 0.8803
outer loop
vertex -3.52671 2 4.8541
vertex -3.49794 1.69098 4.81451
vertex -1.8541 2 5.70634
endloop
endfacet
facet normal -0.448535 0.154556 0.8803
outer loop
vertex -3.52671 2 4.8541
vertex -1.8541 2 5.70634
vertex -1.83898 2.30902 5.65979
endloop
endfacet
facet normal -0.405532 -0.449536 0.795903
outer loop
vertex -3.49794 1.69098 4.81451
vertex -3.41445 1.41221 4.69959
vertex -1.83898 1.69098 5.65979
endloop
endfacet
facet normal -0.448535 -0.154556 0.8803
outer loop
vertex -3.49794 1.69098 4.81451
vertex -1.83898 1.69098 5.65979
vertex -1.8541 2 5.70634
endloop
endfacet
facet normal -0.323002 -0.702714 0.633927
outer loop
vertex -3.41445 1.41221 4.69959
vertex -3.28442 1.19098 4.52061
vertex -1.79508 1.41221 5.5247
endloop
endfacet
facet normal -0.405533 -0.449535 0.795903
outer loop
vertex -3.41445 1.41221 4.69959
vertex -1.79508 1.41221 5.5247
vertex -1.83898 1.69098 5.65979
endloop
endfacet
facet normal -0.208139 -0.888712 0.408496
outer loop
vertex -3.28442 1.19098 4.52061
vertex -3.12056 1.04894 4.29508
vertex -1.72672 1.19098 5.3143
endloop
endfacet
facet normal -0.323002 -0.702714 0.633926
outer loop
vertex -3.28442 1.19098 4.52061
vertex -1.72672 1.19098 5.3143
vertex -1.79508 1.41221 5.5247
endloop
endfacet
facet normal -0.071883 -0.987385 0.141078
outer loop
vertex -3.12056 1.04894 4.29508
vertex -2.93893 1 4.04508
vertex -1.64058 1.04894 5.04918
endloop
endfacet
facet normal -0.208139 -0.888712 0.408496
outer loop
vertex -3.12056 1.04894 4.29508
vertex -1.64058 1.04894 5.04918
vertex -1.72672 1.19098 5.3143
endloop
endfacet
facet normal 0.071883 -0.987385 -0.141078
outer loop
vertex -2.93893 1 4.04508
vertex -2.75729 1.04894 3.79508
vertex -1.54508 1 4.75528
endloop
endfacet
facet normal -0.071883 -0.987385 0.141078
outer loop
vertex -2.93893 1 4.04508
vertex -1.54508 1 4.75528
vertex -1.64058 1.04894 5.04918
endloop
endfacet
facet normal 0.208139 -0.888712 -0.408496
outer loop
vertex -2.75729 1.04894 3.79508
vertex -2.59343 1.19098 3.56956
vertex -1.44959 1.04894 4.46139
endloop
endfacet
facet normal 0.071883 -0.987385 -0.141078
outer loop
vertex -2.75729 1.04894 3.79508
vertex -1.44959 1.04894 4.46139
vertex -1.54508 1 4.75528
endloop
endfacet
facet normal 0.323002 -0.702714 -0.633927
outer loop
vertex -2.59343 1.19098 3.56956
vertex -2.4634 1.41221 3.39058
vertex -1.36345 1.19098 4.19627
endloop
endfacet
facet normal 0.208139 -0.888712 -0.408496
outer loop
vertex -2.59343 1.19098 3.56956
vertex -1.36345 1.19098 4.19627
vertex -1.44959 1.04894 4.46139
endloop
endfacet
facet normal 0.405533 -0.449536 -0.795903
outer loop
vertex -2.4634 1.41221 3.39058
vertex -2.37991 1.69098 3.27566
vertex -1.29508 1.41221 3.98586
endloop
endfacet
facet normal 0.323002 -0.702714 -0.633927
outer loop
vertex -2.4634 1.41221 3.39058
vertex -1.29508 1.41221 3.98586
vertex -1.36345 1.19098 4.19627
endloop
endfacet
facet normal 0.448536 -0.154555 -0.8803
outer loop
vertex -2.37991 1.69098 3.27566
vertex -2.35114 2 3.23607
vertex -1.25119 1.69098 3.85077
endloop
endfacet
facet normal 0.405533 -0.449535 -0.795903
outer loop
vertex -2.37991 1.69098 3.27566
vertex -1.25119 1.69098 3.85077
vertex -1.29508 1.41221 3.98586
endloop
endfacet
facet normal 0.154555 0.154555 -0.97582
outer loop
vertex -1.23607 2 3.80423
vertex -1.25119 2.30902 3.85077
vertex 1.74846e-07 2 4
endloop
endfacet
facet normal 0.154555 -0.154555 -0.97582
outer loop
vertex -1.23607 2 3.80423
vertex 1.74846e-07 2 4
vertex 1.76985e-07 1.69098 4.04894
endloop
endfacet
facet normal 0.139737 0.449535 -0.882265
outer loop
vertex -1.25119 2.30902 3.85077
vertex -1.29508 2.58779 3.98586
vertex 1.76985e-07 2.30902 4.04894
endloop
endfacet
facet normal 0.154555 0.154555 -0.97582
outer loop
vertex -1.25119 2.30902 3.85077
vertex 1.76985e-07 2.30902 4.04894
vertex 1.74846e-07 2 4
endloop
endfacet
facet normal 0.111299 0.702714 -0.702713
outer loop
vertex -1.29508 2.58779 3.98586
vertex -1.36345 2.80902 4.19627
vertex 1.83194e-07 2.58779 4.19098
endloop
endfacet
facet normal 0.139737 0.449536 -0.882265
outer loop
vertex -1.29508 2.58779 3.98586
vertex 1.83194e-07 2.58779 4.19098
vertex 1.76985e-07 2.30902 4.04894
endloop
endfacet
facet normal 0.0717198 0.888712 -0.452822
outer loop
vertex -1.36345 2.80902 4.19627
vertex -1.44959 2.95106 4.46139
vertex 1.92864e-07 2.80902 4.41221
endloop
endfacet
facet normal 0.111299 0.702714 -0.702713
outer loop
vertex -1.36345 2.80902 4.19627
vertex 1.92864e-07 2.80902 4.41221
vertex 1.83194e-07 2.58779 4.19098
endloop
endfacet
facet normal 0.0247692 0.987385 -0.156386
outer loop
vertex -1.44959 2.95106 4.46139
vertex -1.54508 3 4.75528
vertex 2.05049e-07 2.95106 4.69098
endloop
endfacet
facet normal 0.0717198 0.888712 -0.452822
outer loop
vertex -1.44959 2.95106 4.46139
vertex 2.05049e-07 2.95106 4.69098
vertex 1.92864e-07 2.80902 4.41221
endloop
endfacet
facet normal -0.0247692 0.987385 0.156386
outer loop
vertex -1.54508 3 4.75528
vertex -1.64058 2.95106 5.04918
vertex 2.18557e-07 3 5
endloop
endfacet
facet normal 0.0247692 0.987385 -0.156386
outer loop
vertex -1.54508 3 4.75528
vertex 2.18557e-07 3 5
vertex 2.05049e-07 2.95106 4.69098
endloop
endfacet
facet normal -0.0717199 0.888712 0.452822
outer loop
vertex -1.64058 2.95106 5.04918
vertex -1.72672 2.80902 5.3143
vertex 2.32065e-07 2.95106 5.30902
endloop
endfacet
facet normal -0.0247692 0.987385 0.156386
outer loop
vertex -1.64058 2.95106 5.04918
vertex 2.32065e-07 2.95106 5.30902
vertex 2.18557e-07 3 5
endloop
endfacet
facet normal -0.111299 0.702714 0.702713
outer loop
vertex -1.72672 2.80902 5.3143
vertex -1.79508 2.58779 5.5247
vertex 2.4425e-07 2.80902 5.58779
endloop
endfacet
facet normal -0.0717199 0.888712 0.452822
outer loop
vertex -1.72672 2.80902 5.3143
vertex 2.4425e-07 2.80902 5.58779
vertex 2.32065e-07 2.95106 5.30902
endloop
endfacet
facet normal -0.139737 0.449535 0.882265
outer loop
vertex -1.79508 2.58779 5.5247
vertex -1.83898 2.30902 5.65979
vertex 2.5392e-07 2.58779 5.80902
endloop
endfacet
facet normal -0.111299 0.702714 0.702713
outer loop
vertex -1.79508 2.58779 5.5247
vertex 2.5392e-07 2.58779 5.80902
vertex 2.4425e-07 2.80902 5.58779
endloop
endfacet
facet normal -0.154555 0.154556 0.97582
outer loop
vertex -1.83898 2.30902 5.65979
vertex -1.8541 2 5.70634
vertex 2.60129e-07 2.30902 5.95106
endloop
endfacet
facet normal -0.139737 0.449536 0.882265
outer loop
vertex -1.83898 2.30902 5.65979
vertex 2.60129e-07 2.30902 5.95106
vertex 2.5392e-07 2.58779 5.80902
endloop
endfacet
facet normal -0.154555 -0.154556 0.97582
outer loop
vertex -1.8541 2 5.70634
vertex -1.83898 1.69098 5.65979
vertex 2.62268e-07 2 6
endloop
endfacet
facet normal -0.154555 0.154555 0.975821
outer loop
vertex -1.8541 2 5.70634
vertex 2.62268e-07 2 6
vertex 2.60129e-07 2.30902 5.95106
endloop
endfacet
facet normal -0.139737 -0.449534 0.882265
outer loop
vertex -1.83898 1.69098 5.65979
vertex -1.79508 1.41221 5.5247
vertex 2.60129e-07 1.69098 5.95106
endloop
endfacet
facet normal -0.154555 -0.154555 0.97582
outer loop
vertex -1.83898 1.69098 5.65979
vertex 2.60129e-07 1.69098 5.95106
vertex 2.62268e-07 2 6
endloop
endfacet
facet normal -0.111299 -0.702714 0.702713
outer loop
vertex -1.79508 1.41221 5.5247
vertex -1.72672 1.19098 5.3143
vertex 2.5392e-07 1.41221 5.80902
endloop
endfacet
facet normal -0.139737 -0.449535 0.882265
outer loop
vertex -1.79508 1.41221 5.5247
vertex 2.5392e-07 1.41221 5.80902
vertex 2.60129e-07 1.69098 5.95106
endloop
endfacet
facet normal -0.0717199 -0.888712 0.452821
outer loop
vertex -1.72672 1.19098 5.3143
vertex -1.64058 1.04894 5.04918
vertex 2.4425e-07 1.19098 5.58779
endloop
endfacet
facet normal -0.111299 -0.702714 0.702713
outer loop
vertex -1.72672 1.19098 5.3143
vertex 2.4425e-07 1.19098 5.58779
vertex 2.5392e-07 1.41221 5.80902
endloop
endfacet
facet normal -0.0247692 -0.987385 0.156386
outer loop
vertex -1.64058 1.04894 5.04918
vertex -1.54508 1 4.75528
vertex 2.32065e-07 1.04894 5.30902
endloop
endfacet
facet normal -0.0717197 -0.888712 0.452821
outer loop
vertex -1.64058 1.04894 5.04918
vertex 2.32065e-07 1.04894 5.30902
vertex 2.4425e-07 1.19098 5.58779
endloop
endfacet
facet normal 0.0247692 -0.987385 -0.156386
outer loop
vertex -1.54508 1 4.75528
vertex -1.44959 1.04894 4.46139
vertex 2.18557e-07 1 5
endloop
endfacet
facet normal -0.0247692 -0.987385 0.156386
outer loop
vertex -1.54508 1 4.75528
vertex 2.18557e-07 1 5
vertex 2.32065e-07 1.04894 5.30902
endloop
endfacet
facet normal 0.0717197 -0.888712 -0.452821
outer loop
vertex -1.44959 1.04894 4.46139
vertex -1.36345 1.19098 4.19627
vertex 2.05049e-07 1.04894 4.69098
endloop
endfacet
facet normal 0.0247692 -0.987385 -0.156387
outer loop
vertex -1.44959 1.04894 4.46139
vertex 2.05049e-07 1.04894 4.69098
vertex 2.18557e-07 1 5
endloop
endfacet
facet normal 0.111299 -0.702714 -0.702713
outer loop
vertex -1.36345 1.19098 4.19627
vertex -1.29508 1.41221 3.98586
vertex 1.92864e-07 1.19098 4.41221
endloop
endfacet
facet normal 0.0717198 -0.888712 -0.452821
outer loop
vertex -1.36345 1.19098 4.19627
vertex 1.92864e-07 1.19098 4.41221
vertex 2.05049e-07 1.04894 4.69098
endloop
endfacet
facet normal 0.139737 -0.449535 -0.882265
outer loop
vertex -1.29508 1.41221 3.98586
vertex -1.25119 1.69098 3.85077
vertex 1.83194e-07 1.41221 4.19098
endloop
endfacet
facet normal 0.111299 -0.702713 -0.702714
outer loop
vertex -1.29508 1.41221 3.98586
vertex 1.83194e-07 1.41221 4.19098
vertex 1.92864e-07 1.19098 4.41221
endloop
endfacet
facet normal 0.154555 -0.154555 -0.97582
outer loop
vertex -1.25119 1.69098 3.85077
vertex -1.23607 2 3.80423
vertex 1.76985e-07 1.69098 4.04894
endloop
endfacet
facet normal 0.139737 -0.449536 -0.882265
outer loop
vertex -1.25119 1.69098 3.85077
vertex 1.76985e-07 1.69098 4.04894
vertex 1.83194e-07 1.41221 4.19098
endloop
endfacet
facet normal -0.154555 0.154555 -0.97582
outer loop
vertex 1.74846e-07 2 4
vertex 1.76985e-07 2.30902 4.04894
vertex 1.23607 2 3.80423
endloop
endfacet
facet normal -0.154555 -0.154555 -0.97582
outer loop
vertex 1.74846e-07 2 4
vertex 1.23607 2 3.80423
vertex 1.25119 1.69098 3.85077
endloop
endfacet
facet normal -0.139737 0.449536 -0.882265
outer loop
vertex 1.76985e-07 2.30902 4.04894
vertex 1.83194e-07 2.58779 4.19098
vertex 1.25119 2.30902 3.85077
endloop
endfacet
facet normal -0.154555 0.154555 -0.97582
outer loop
vertex 1.76985e-07 2.30902 4.04894
vertex 1.25119 2.30902 3.85077
vertex 1.23607 2 3.80423
endloop
endfacet
facet normal -0.111299 0.702714 -0.702713
outer loop
vertex 1.83194e-07 2.58779 4.19098
vertex 1.92864e-07 2.80902 4.41221
vertex 1.29509 2.58779 3.98586
endloop
endfacet
facet normal -0.139737 0.449535 -0.882265
outer loop
vertex 1.83194e-07 2.58779 4.19098
vertex 1.29509 2.58779 3.98586
vertex 1.25119 2.30902 3.85077
endloop
endfacet
facet normal -0.07172 0.888712 -0.452822
outer loop
vertex 1.92864e-07 2.80902 4.41221
vertex 2.05049e-07 2.95106 4.69098
vertex 1.36345 2.80902 4.19627
endloop
endfacet
facet normal -0.111299 0.702714 -0.702713
outer loop
vertex 1.92864e-07 2.80902 4.41221
vertex 1.36345 2.80902 4.19627
vertex 1.29509 2.58779 3.98586
endloop
endfacet
facet normal -0.0247692 0.987385 -0.156386
outer loop
vertex 2.05049e-07 2.95106 4.69098
vertex 2.18557e-07 3 5
vertex 1.44959 2.95106 4.46139
endloop
endfacet
facet normal -0.07172 0.888712 -0.452822
outer loop
vertex 2.05049e-07 2.95106 4.69098
vertex 1.44959 2.95106 4.46139
vertex 1.36345 2.80902 4.19627
endloop
endfacet
facet normal 0.0247692 0.987385 0.156386
outer loop
vertex 2.18557e-07 3 5
vertex 2.32065e-07 2.95106 5.30902
vertex 1.54509 3 4.75528
endloop
endfacet
facet normal -0.0247692 0.987385 -0.156386
outer loop
vertex 2.18557e-07 3 5
vertex 1.54509 3 4.75528
vertex 1.44959 2.95106 4.46139
endloop
endfacet
facet normal 0.0717199 0.888712 0.452822
outer loop
vertex 2.32065e-07 2.95106 5.30902
vertex 2.4425e-07 2.80902 5.58779
vertex 1.64058 2.95106 5.04918
endloop
endfacet
facet normal 0.0247692 0.987385 0.156386
outer loop
vertex 2.32065e-07 2.95106 5.30902
vertex 1.64058 2.95106 5.04918
vertex 1.54509 3 4.75528
endloop
endfacet
facet normal 0.111299 0.702714 0.702713
outer loop
vertex 2.4425e-07 2.80902 5.58779
vertex 2.5392e-07 2.58779 5.80902
vertex 1.72672 2.80902 5.3143
endloop
endfacet
facet normal 0.0717199 0.888712 0.452822
outer loop
vertex 2.4425e-07 2.80902 5.58779
vertex 1.72672 2.80902 5.3143
vertex 1.64058 2.95106 5.04918
endloop
endfacet
facet normal 0.139737 0.449536 0.882265
outer loop
vertex 2.5392e-07 2.58779 5.80902
vertex 2.60129e-07 2.30902 5.95106
vertex 1.79509 2.58779 5.5247
endloop
endfacet
facet normal 0.111299 0.702714 0.702713
outer loop
vertex 2.5392e-07 2.58779 5.80902
vertex 1.79509 2.58779 5.5247
vertex 1.72672 2.80902 5.3143
endloop
endfacet
facet normal 0.154555 0.154555 0.97582
outer loop
vertex 2.60129e-07 2.30902 5.95106
vertex 2.62268e-07 2 6
vertex 1.83898 2.30902 5.65979
endloop
endfacet
facet normal 0.139737 0.449536 0.882265
outer loop
vertex 2.60129e-07 2.30902 5.95106
vertex 1.83898 2.30902 5.65979
vertex 1.79509 2.58779 5.5247
endloop
endfacet
facet normal 0.154555 -0.154555 0.97582
outer loop
vertex 2.62268e-07 2 6
vertex 2.60129e-07 1.69098 5.95106
vertex 1.8541 2 5.70634
endloop
endfacet
facet normal 0.154555 0.154554 0.975821
outer loop
vertex 2.62268e-07 2 6
vertex 1.8541 2 5.70634
vertex 1.83898 2.30902 5.65979
endloop
endfacet
facet normal 0.139737 -0.449535 0.882265
outer loop
vertex 2.60129e-07 1.69098 5.95106
vertex 2.5392e-07 1.41221 5.80902
vertex 1.83898 1.69098 5.65979
endloop
endfacet
facet normal 0.154555 -0.154554 0.97582
outer loop
vertex 2.60129e-07 1.69098 5.95106
vertex 1.83898 1.69098 5.65979
vertex 1.8541 2 5.70634
endloop
endfacet
facet normal 0.111299 -0.702714 0.702713
outer loop
vertex 2.5392e-07 1.41221 5.80902
vertex 2.4425e-07 1.19098 5.58779
vertex 1.79509 1.41221 5.5247
endloop
endfacet
facet normal 0.139737 -0.449536 0.882265
outer loop
vertex 2.5392e-07 1.41221 5.80902
vertex 1.79509 1.41221 5.5247
vertex 1.83898 1.69098 5.65979
endloop
endfacet
facet normal 0.0717198 -0.888712 0.452821
outer loop
vertex 2.4425e-07 1.19098 5.58779
vertex 2.32065e-07 1.04894 5.30902
vertex 1.72672 1.19098 5.3143
endloop
endfacet
facet normal 0.111299 -0.702713 0.702714
outer loop
vertex 2.4425e-07 1.19098 5.58779
vertex 1.72672 1.19098 5.3143
vertex 1.79509 1.41221 5.5247
endloop
endfacet
facet normal 0.0247692 -0.987385 0.156386
outer loop
vertex 2.32065e-07 1.04894 5.30902
vertex 2.18557e-07 1 5
vertex 1.64058 1.04894 5.04918
endloop
endfacet
facet normal 0.0717198 -0.888712 0.452821
outer loop
vertex 2.32065e-07 1.04894 5.30902
vertex 1.64058 1.04894 5.04918
vertex 1.72672 1.19098 5.3143
endloop
endfacet
facet normal -0.0247692 -0.987385 -0.156386
outer loop
vertex 2.18557e-07 1 5
vertex 2.05049e-07 1.04894 4.69098
vertex 1.54509 1 4.75528
endloop
endfacet
facet normal 0.0247692 -0.987385 0.156386
outer loop
vertex 2.18557e-07 1 5
vertex 1.54509 1 4.75528
vertex 1.64058 1.04894 5.04918
endloop
endfacet
facet normal -0.0717199 -0.888712 -0.452821
outer loop
vertex 2.05049e-07 1.04894 4.69098
vertex 1.92864e-07 1.19098 4.41221
vertex 1.44959 1.04894 4.46139
endloop
endfacet
facet normal -0.0247692 -0.987385 -0.156386
outer loop
vertex 2.05049e-07 1.04894 4.69098
vertex 1.44959 1.04894 4.46139
vertex 1.54509 1 4.75528
endloop
endfacet
facet normal -0.111299 -0.702713 -0.702713
outer loop
vertex 1.92864e-07 1.19098 4.41221
vertex 1.83194e-07 1.41221 4.19098
vertex 1.36345 1.19098 4.19627
endloop
endfacet
facet normal -0.0717199 -0.888712 -0.452821
outer loop
vertex 1.92864e-07 1.19098 4.41221
vertex 1.36345 1.19098 4.19627
vertex 1.44959 1.04894 4.46139
endloop
endfacet
facet normal -0.139737 -0.449536 -0.882265
outer loop
vertex 1.83194e-07 1.41221 4.19098
vertex 1.76985e-07 1.69098 4.04894
vertex 1.29509 1.41221 3.98586
endloop
endfacet
facet normal -0.111299 -0.702713 -0.702714
outer loop
vertex 1.83194e-07 1.41221 4.19098
vertex 1.29509 1.41221 3.98586
vertex 1.36345 1.19098 4.19627
endloop
endfacet
facet normal -0.154555 -0.154555 -0.97582
outer loop
vertex 1.76985e-07 1.69098 4.04894
vertex 1.74846e-07 2 4
vertex 1.25119 1.69098 3.85077
endloop
endfacet
facet normal -0.139737 -0.449535 -0.882265
outer loop
vertex 1.76985e-07 1.69098 4.04894
vertex 1.25119 1.69098 3.85077
vertex 1.29509 1.41221 3.98586
endloop
endfacet
facet normal -0.448535 0.154555 -0.8803
outer loop
vertex 1.23607 2 3.80423
vertex 1.25119 2.30902 3.85077
vertex 2.35114 2 3.23607
endloop
endfacet
facet normal -0.448535 -0.154555 -0.8803
outer loop
vertex 1.23607 2 3.80423
vertex 2.35114 2 3.23607
vertex 2.37991 1.69098 3.27566
endloop
endfacet
facet normal -0.405533 0.449535 -0.795903
outer loop
vertex 1.25119 2.30902 3.85077
vertex 1.29509 2.58779 3.98586
vertex 2.37991 2.30902 3.27566
endloop
endfacet
facet normal -0.448536 0.154555 -0.8803
outer loop
vertex 1.25119 2.30902 3.85077
vertex 2.37991 2.30902 3.27566
vertex 2.35114 2 3.23607
endloop
endfacet
facet normal -0.323002 0.702714 -0.633927
outer loop
vertex 1.29509 2.58779 3.98586
vertex 1.36345 2.80902 4.19627
vertex 2.4634 2.58779 3.39058
endloop
endfacet
facet normal -0.405533 0.449536 -0.795903
outer loop
vertex 1.29509 2.58779 3.98586
vertex 2.4634 2.58779 3.39058
vertex 2.37991 2.30902 3.27566
endloop
endfacet
facet normal -0.208139 0.888712 -0.408496
outer loop
vertex 1.36345 2.80902 4.19627
vertex 1.44959 2.95106 4.46139
vertex 2.59343 2.80902 3.56956
endloop
endfacet
facet normal -0.323002 0.702714 -0.633927
outer loop
vertex 1.36345 2.80902 4.19627
vertex 2.59343 2.80902 3.56956
vertex 2.4634 2.58779 3.39058
endloop
endfacet
facet normal -0.0718829 0.987385 -0.141078
outer loop
vertex 1.44959 2.95106 4.46139
vertex 1.54509 3 4.75528
vertex 2.75729 2.95106 3.79508
endloop
endfacet
facet normal -0.208139 0.888712 -0.408496
outer loop
vertex 1.44959 2.95106 4.46139
vertex 2.75729 2.95106 3.79508
vertex 2.59343 2.80902 3.56956
endloop
endfacet
facet normal 0.071883 0.987385 0.141078
outer loop
vertex 1.54509 3 4.75528
vertex 1.64058 2.95106 5.04918
vertex 2.93893 3 4.04508
endloop
endfacet
facet normal -0.071883 0.987385 -0.141078
outer loop
vertex 1.54509 3 4.75528
vertex 2.93893 3 4.04508
vertex 2.75729 2.95106 3.79508
endloop
endfacet
facet normal 0.208139 0.888712 0.408496
outer loop
vertex 1.64058 2.95106 5.04918
vertex 1.72672 2.80902 5.3143
vertex 3.12056 2.95106 4.29508
endloop
endfacet
facet normal 0.071883 0.987385 0.141078
outer loop
vertex 1.64058 2.95106 5.04918
vertex 3.12056 2.95106 4.29508
vertex 2.93893 3 4.04508
endloop
endfacet
facet normal 0.323002 0.702714 0.633927
outer loop
vertex 1.72672 2.80902 5.3143
vertex 1.79509 2.58779 5.5247
vertex 3.28442 2.80902 4.52061
endloop
endfacet
facet normal 0.208139 0.888712 0.408496
outer loop
vertex 1.72672 2.80902 5.3143
vertex 3.28442 2.80902 4.52061
vertex 3.12056 2.95106 4.29508
endloop
endfacet
facet normal 0.405533 0.449536 0.795902
outer loop
vertex 1.79509 2.58779 5.5247
vertex 1.83898 2.30902 5.65979
vertex 3.41445 2.58779 4.69959
endloop
endfacet
facet normal 0.323002 0.702714 0.633927
outer loop
vertex 1.79509 2.58779 5.5247
vertex 3.41445 2.58779 4.69959
vertex 3.28442 2.80902 4.52061
endloop
endfacet
facet normal 0.448535 0.154554 0.8803
outer loop
vertex 1.83898 2.30902 5.65979
vertex 1.8541 2 5.70634
vertex 3.49794 2.30902 4.81451
endloop
endfacet
facet normal 0.405532 0.449536 0.795902
outer loop
vertex 1.83898 2.30902 5.65979
vertex 3.49794 2.30902 4.81451
vertex 3.41445 2.58779 4.69959
endloop
endfacet
facet normal 0.448535 -0.154554 0.8803
outer loop
vertex 1.8541 2 5.70634
vertex 1.83898 1.69098 5.65979
vertex 3.52671 2 4.8541
endloop
endfacet
facet normal 0.448536 0.154555 0.8803
outer loop
vertex 1.8541 2 5.70634
vertex 3.52671 2 4.8541
vertex 3.49794 2.30902 4.81451
endloop
endfacet
facet normal 0.405533 -0.449536 0.795903
outer loop
vertex 1.83898 1.69098 5.65979
vertex 1.79509 1.41221 5.5247
vertex 3.49794 1.69098 4.81451
endloop
endfacet
facet normal 0.448535 -0.154555 0.8803
outer loop
vertex 1.83898 1.69098 5.65979
vertex 3.49794 1.69098 4.81451
vertex 3.52671 2 4.8541
endloop
endfacet
facet normal 0.323002 -0.702713 0.633927
outer loop
vertex 1.79509 1.41221 5.5247
vertex 1.72672 1.19098 5.3143
vertex 3.41445 1.41221 4.69959
endloop
endfacet
facet normal 0.405533 -0.449536 0.795902
outer loop
vertex 1.79509 1.41221 5.5247
vertex 3.41445 1.41221 4.69959
vertex 3.49794 1.69098 4.81451
endloop
endfacet
facet normal 0.208139 -0.888712 0.408496
outer loop
vertex 1.72672 1.19098 5.3143
vertex 1.64058 1.04894 5.04918
vertex 3.28442 1.19098 4.52061
endloop
endfacet
facet normal 0.323002 -0.702714 0.633927
outer loop
vertex 1.72672 1.19098 5.3143
vertex 3.28442 1.19098 4.52061
vertex 3.41445 1.41221 4.69959
endloop
endfacet
facet normal 0.071883 -0.987385 0.141078
outer loop
vertex 1.64058 1.04894 5.04918
vertex 1.54509 1 4.75528
vertex 3.12056 1.04894 4.29508
endloop
endfacet
facet normal 0.208139 -0.888712 0.408496
outer loop
vertex 1.64058 1.04894 5.04918
vertex 3.12056 1.04894 4.29508
vertex 3.28442 1.19098 4.52061
endloop
endfacet
facet normal -0.071883 -0.987385 -0.141078
outer loop
vertex 1.54509 1 4.75528
vertex 1.44959 1.04894 4.46139
vertex 2.93893 1 4.04508
endloop
endfacet
facet normal 0.071883 -0.987385 0.141078
outer loop
vertex 1.54509 1 4.75528
vertex 2.93893 1 4.04508
vertex 3.12056 1.04894 4.29508
endloop
endfacet
facet normal -0.208139 -0.888712 -0.408496
outer loop
vertex 1.44959 1.04894 4.46139
vertex 1.36345 1.19098 4.19627
vertex 2.75729 1.04894 3.79508
endloop
endfacet
facet normal -0.071883 -0.987385 -0.141078
outer loop
vertex 1.44959 1.04894 4.46139
vertex 2.75729 1.04894 3.79508
vertex 2.93893 1 4.04508
endloop
endfacet
facet normal -0.323002 -0.702713 -0.633927
outer loop
vertex 1.36345 1.19098 4.19627
vertex 1.29509 1.41221 3.98586
vertex 2.59343 1.19098 3.56956
endloop
endfacet
facet normal -0.208139 -0.888712 -0.408496
outer loop
vertex 1.36345 1.19098 4.19627
vertex 2.59343 1.19098 3.56956
vertex 2.75729 1.04894 3.79508
endloop
endfacet
facet normal -0.405533 -0.449535 -0.795903
outer loop
vertex 1.29509 1.41221 3.98586
vertex 1.25119 1.69098 3.85077
vertex 2.4634 1.41221 3.39058
endloop
endfacet
facet normal -0.323002 -0.702714 -0.633927
outer loop
vertex 1.29509 1.41221 3.98586
vertex 2.4634 1.41221 3.39058
vertex 2.59343 1.19098 3.56956
endloop
endfacet
facet normal -0.448536 -0.154555 -0.8803
outer loop
vertex 1.25119 1.69098 3.85077
vertex 1.23607 2 3.80423
vertex 2.37991 1.69098 3.27566
endloop
endfacet
facet normal -0.405533 -0.449536 -0.795903
outer loop
vertex 1.25119 1.69098 3.85077
vertex 2.37991 1.69098 3.27566
vertex 2.4634 1.41221 3.39058
endloop
endfacet
facet normal -0.69861 0.154555 -0.69861
outer loop
vertex 2.35114 2 3.23607
vertex 2.37991 2.30902 3.27566
vertex 3.23607 2 2.35114
endloop
endfacet
facet normal -0.69861 -0.154555 -0.69861
outer loop
vertex 2.35114 2 3.23607
vertex 3.23607 2 2.35114
vertex 3.27566 1.69098 2.37991
endloop
endfacet
facet normal -0.631632 0.449535 -0.631632
outer loop
vertex 2.37991 2.30902 3.27566
vertex 2.4634 2.58779 3.39058
vertex 3.27566 2.30902 2.37991
endloop
endfacet
facet normal -0.69861 0.154555 -0.69861
outer loop
vertex 2.37991 2.30902 3.27566
vertex 3.27566 2.30902 2.37991
vertex 3.23607 2 2.35114
endloop
endfacet
facet normal -0.503087 0.702714 -0.503087
outer loop
vertex 2.4634 2.58779 3.39058
vertex 2.59343 2.80902 3.56956
vertex 3.39058 2.58779 2.4634
endloop
endfacet
facet normal -0.631632 0.449535 -0.631632
outer loop
vertex 2.4634 2.58779 3.39058
vertex 3.39058 2.58779 2.4634
vertex 3.27566 2.30902 2.37991
endloop
endfacet
facet normal -0.324185 0.888712 -0.324185
outer loop
vertex 2.59343 2.80902 3.56956
vertex 2.75729 2.95106 3.79508
vertex 3.56956 2.80902 2.59343
endloop
endfacet
facet normal -0.503087 0.702714 -0.503087
outer loop
vertex 2.59343 2.80902 3.56956
vertex 3.56956 2.80902 2.59343
vertex 3.39058 2.58779 2.4634
endloop
endfacet
facet normal -0.11196 0.987385 -0.11196
outer loop
vertex 2.75729 2.95106 3.79508
vertex 2.93893 3 4.04508
vertex 3.79509 2.95106 2.75729
endloop
endfacet
facet normal -0.324185 0.888712 -0.324185
outer loop
vertex 2.75729 2.95106 3.79508
vertex 3.79509 2.95106 2.75729
vertex 3.56956 2.80902 2.59343
endloop
endfacet
facet normal 0.11196 0.987385 0.11196
outer loop
vertex 2.93893 3 4.04508
vertex 3.12056 2.95106 4.29508
vertex 4.04509 3 2.93893
endloop
endfacet
facet normal -0.11196 0.987385 -0.11196
outer loop
vertex 2.93893 3 4.04508
vertex 4.04509 3 2.93893
vertex 3.79509 2.95106 2.75729
endloop
endfacet
facet normal 0.324184 0.888712 0.324184
outer loop
vertex 3.12056 2.95106 4.29508
vertex 3.28442 2.80902 4.52061
vertex 4.29509 2.95106 3.12056
endloop
endfacet
facet normal 0.11196 0.987385 0.11196
outer loop
vertex 3.12056 2.95106 4.29508
vertex 4.29509 2.95106 3.12056
vertex 4.04509 3 2.93893
endloop
endfacet
facet normal 0.503087 0.702714 0.503087
outer loop
vertex 3.28442 2.80902 4.52061
vertex 3.41445 2.58779 4.69959
vertex 4.52061 2.80902 3.28442
endloop
endfacet
facet normal 0.324184 0.888712 0.324184
outer loop
vertex 3.28442 2.80902 4.52061
vertex 4.52061 2.80902 3.28442
vertex 4.29509 2.95106 3.12056
endloop
endfacet
facet normal 0.631631 0.449536 0.631632
outer loop
vertex 3.41445 2.58779 4.69959
vertex 3.49794 2.30902 4.81451
vertex 4.69959 2.58779 3.41445
endloop
endfacet
facet normal 0.503087 0.702714 0.503087
outer loop
vertex 3.41445 2.58779 4.69959
vertex 4.69959 2.58779 3.41445
vertex 4.52061 2.80902 3.28442
endloop
endfacet
facet normal 0.69861 0.154554 0.69861
outer loop
vertex 3.49794 2.30902 4.81451
vertex 3.52671 2 4.8541
vertex 4.81451 2.30902 3.49794
endloop
endfacet
facet normal 0.631632 0.449536 0.631632
outer loop
vertex 3.49794 2.30902 4.81451
vertex 4.81451 2.30902 3.49794
vertex 4.69959 2.58779 3.41445
endloop
endfacet
facet normal 0.69861 -0.154554 0.69861
outer loop
vertex 3.52671 2 4.8541
vertex 3.49794 1.69098 4.81451
vertex 4.8541 2 3.52671
endloop
endfacet
facet normal 0.69861 0.154554 0.69861
outer loop
vertex 3.52671 2 4.8541
vertex 4.8541 2 3.52671
vertex 4.81451 2.30902 3.49794
endloop
endfacet
facet normal 0.631632 -0.449536 0.631632
outer loop
vertex 3.49794 1.69098 4.81451
vertex 3.41445 1.41221 4.69959
vertex 4.81451 1.69098 3.49794
endloop
endfacet
facet normal 0.69861 -0.154554 0.69861
outer loop
vertex 3.49794 1.69098 4.81451
vertex 4.81451 1.69098 3.49794
vertex 4.8541 2 3.52671
endloop
endfacet
facet normal 0.503087 -0.702714 0.503087
outer loop
vertex 3.41445 1.41221 4.69959
vertex 3.28442 1.19098 4.52061
vertex 4.69959 1.41221 3.41445
endloop
endfacet
facet normal 0.631632 -0.449535 0.631632
outer loop
vertex 3.41445 1.41221 4.69959
vertex 4.69959 1.41221 3.41445
vertex 4.81451 1.69098 3.49794
endloop
endfacet
facet normal 0.324184 -0.888712 0.324184
outer loop
vertex 3.28442 1.19098 4.52061
vertex 3.12056 1.04894 4.29508
vertex 4.52061 1.19098 3.28442
endloop
endfacet
facet normal 0.503087 -0.702714 0.503087
outer loop
vertex 3.28442 1.19098 4.52061
vertex 4.52061 1.19098 3.28442
vertex 4.69959 1.41221 3.41445
endloop
endfacet
facet normal 0.11196 -0.987385 0.11196
outer loop
vertex 3.12056 1.04894 4.29508
vertex 2.93893 1 4.04508
vertex 4.29509 1.04894 3.12056
endloop
endfacet
facet normal 0.324184 -0.888712 0.324184
outer loop
vertex 3.12056 1.04894 4.29508
vertex 4.29509 1.04894 3.12056
vertex 4.52061 1.19098 3.28442
endloop
endfacet
facet normal -0.11196 -0.987385 -0.11196
outer loop
vertex 2.93893 1 4.04508
vertex 2.75729 1.04894 3.79508
vertex 4.04509 1 2.93893
endloop
endfacet
facet normal 0.11196 -0.987385 0.11196
outer loop
vertex 2.93893 1 4.04508
vertex 4.04509 1 2.93893
vertex 4.29509 1.04894 3.12056
endloop
endfacet
facet normal -0.324184 -0.888712 -0.324184
outer loop
vertex 2.75729 1.04894 3.79508
vertex 2.59343 1.19098 3.56956
vertex 3.79509 1.04894 2.75729
endloop
endfacet
facet normal -0.11196 -0.987385 -0.11196
outer loop
vertex 2.75729 1.04894 3.79508
vertex 3.79509 1.04894 2.75729
vertex 4.04509 1 2.93893
endloop
endfacet
facet normal -0.503087 -0.702714 -0.503087
outer loop
vertex 2.59343 1.19098 3.56956
vertex 2.4634 1.41221 3.39058
vertex 3.56956 1.19098 2.59343
endloop
endfacet
facet normal -0.324184 -0.888712 -0.324184
outer loop
vertex 2.59343 1.19098 3.56956
vertex 3.56956 1.19098 2.59343
vertex 3.79509 1.04894 2.75729
endloop
endfacet
facet normal -0.631632 -0.449535 -0.631632
outer loop
vertex 2.4634 1.41221 3.39058
vertex 2.37991 1.69098 3.27566
vertex 3.39058 1.41221 2.4634
endloop
endfacet
facet normal -0.503087 -0.702714 -0.503087
outer loop
vertex 2.4634 1.41221 3.39058
vertex 3.39058 1.41221 2.4634
vertex 3.56956 1.19098 2.59343
endloop
endfacet
facet normal -0.69861 -0.154555 -0.69861
outer loop
vertex 2.37991 1.69098 3.27566
vertex 2.35114 2 3.23607
vertex 3.27566 1.69098 2.37991
endloop
endfacet
facet normal -0.631632 -0.449535 -0.631632
outer loop
vertex 2.37991 1.69098 3.27566
vertex 3.27566 1.69098 2.37991
vertex 3.39058 1.41221 2.4634
endloop
endfacet
facet normal -0.8803 0.154555 -0.448535
outer loop
vertex 3.23607 2 2.35114
vertex 3.27566 2.30902 2.37991
vertex 3.80423 2 1.23607
endloop
endfacet
facet normal -0.8803 -0.154555 -0.448535
outer loop
vertex 3.23607 2 2.35114
vertex 3.80423 2 1.23607
vertex 3.85077 1.69098 1.25119
endloop
endfacet
facet normal -0.795903 0.449536 -0.405533
outer loop
vertex 3.27566 2.30902 2.37991
vertex 3.39058 2.58779 2.4634
vertex 3.85077 2.30902 1.25119
endloop
endfacet
facet normal -0.8803 0.154555 -0.448535
outer loop
vertex 3.27566 2.30902 2.37991
vertex 3.85077 2.30902 1.25119
vertex 3.80423 2 1.23607
endloop
endfacet
facet normal -0.633927 0.702714 -0.323002
outer loop
vertex 3.39058 2.58779 2.4634
vertex 3.56956 2.80902 2.59343
vertex 3.98586 2.58779 1.29509
endloop
endfacet
facet normal -0.795903 0.449535 -0.405533
outer loop
vertex 3.39058 2.58779 2.4634
vertex 3.98586 2.58779 1.29509
vertex 3.85077 2.30902 1.25119
endloop
endfacet
facet normal -0.408496 0.888712 -0.208139
outer loop
vertex 3.56956 2.80902 2.59343
vertex 3.79509 2.95106 2.75729
vertex 4.19627 2.80902 1.36345
endloop
endfacet
facet normal -0.633927 0.702714 -0.323002
outer loop
vertex 3.56956 2.80902 2.59343
vertex 4.19627 2.80902 1.36345
vertex 3.98586 2.58779 1.29509
endloop
endfacet
facet normal -0.141078 0.987385 -0.0718829
outer loop
vertex 3.79509 2.95106 2.75729
vertex 4.04509 3 2.93893
vertex 4.46139 2.95106 1.44959
endloop
endfacet
facet normal -0.408496 0.888712 -0.208139
outer loop
vertex 3.79509 2.95106 2.75729
vertex 4.46139 2.95106 1.44959
vertex 4.19627 2.80902 1.36345
endloop
endfacet
facet normal 0.141078 0.987385 0.071883
outer loop
vertex 4.04509 3 2.93893
vertex 4.29509 2.95106 3.12056
vertex 4.75528 3 1.54509
endloop
endfacet
facet normal -0.141078 0.987385 -0.0718829
outer loop
vertex 4.04509 3 2.93893
vertex 4.75528 3 1.54509
vertex 4.46139 2.95106 1.44959
endloop
endfacet
facet normal 0.408496 0.888712 0.208139
outer loop
vertex 4.29509 2.95106 3.12056
vertex 4.52061 2.80902 3.28442
vertex 5.04918 2.95106 1.64058
endloop
endfacet
facet normal 0.141078 0.987385 0.071883
outer loop
vertex 4.29509 2.95106 3.12056
vertex 5.04918 2.95106 1.64058
vertex 4.75528 3 1.54509
endloop
endfacet
facet normal 0.633927 0.702714 0.323002
outer loop
vertex 4.52061 2.80902 3.28442
vertex 4.69959 2.58779 3.41445
vertex 5.3143 2.80902 1.72672
endloop
endfacet
facet normal 0.408496 0.888712 0.208139
outer loop
vertex 4.52061 2.80902 3.28442
vertex 5.3143 2.80902 1.72672
vertex 5.04918 2.95106 1.64058
endloop
endfacet
facet normal 0.795903 0.449535 0.405533
outer loop
vertex 4.69959 2.58779 3.41445
vertex 4.81451 2.30902 3.49794
vertex 5.5247 2.58779 1.79509
endloop
endfacet
facet normal 0.633927 0.702714 0.323002
outer loop
vertex 4.69959 2.58779 3.41445
vertex 5.5247 2.58779 1.79509
vertex 5.3143 2.80902 1.72672
endloop
endfacet
facet normal 0.8803 0.154554 0.448535
outer loop
vertex 4.81451 2.30902 3.49794
vertex 4.8541 2 3.52671
vertex 5.65979 2.30902 1.83898
endloop
endfacet
facet normal 0.795902 0.449536 0.405533
outer loop
vertex 4.81451 2.30902 3.49794
vertex 5.65979 2.30902 1.83898
vertex 5.5247 2.58779 1.79509
endloop
endfacet
facet normal 0.8803 -0.154555 0.448535
outer loop
vertex 4.8541 2 3.52671
vertex 4.81451 1.69098 3.49794
vertex 5.70634 2 1.8541
endloop
endfacet
facet normal 0.8803 0.154554 0.448536
outer loop
vertex 4.8541 2 3.52671
vertex 5.70634 2 1.8541
vertex 5.65979 2.30902 1.83898
endloop
endfacet
facet normal 0.795903 -0.449535 0.405533
outer loop
vertex 4.81451 1.69098 3.49794
vertex 4.69959 1.41221 3.41445
vertex 5.65979 1.69098 1.83898
endloop
endfacet
facet normal 0.8803 -0.154555 0.448535
outer loop
vertex 4.81451 1.69098 3.49794
vertex 5.65979 1.69098 1.83898
vertex 5.70634 2 1.8541
endloop
endfacet
facet normal 0.633927 -0.702714 0.323002
outer loop
vertex 4.69959 1.41221 3.41445
vertex 4.52061 1.19098 3.28442
vertex 5.5247 1.41221 1.79509
endloop
endfacet
facet normal 0.795903 -0.449536 0.405532
outer loop
vertex 4.69959 1.41221 3.41445
vertex 5.5247 1.41221 1.79509
vertex 5.65979 1.69098 1.83898
endloop
endfacet
facet normal 0.408496 -0.888712 0.208139
outer loop
vertex 4.52061 1.19098 3.28442
vertex 4.29509 1.04894 3.12056
vertex 5.3143 1.19098 1.72672
endloop
endfacet
facet normal 0.633927 -0.702713 0.323002
outer loop
vertex 4.52061 1.19098 3.28442
vertex 5.3143 1.19098 1.72672
vertex 5.5247 1.41221 1.79509
endloop
endfacet
facet normal 0.141078 -0.987385 0.071883
outer loop
vertex 4.29509 1.04894 3.12056
vertex 4.04509 1 2.93893
vertex 5.04918 1.04894 1.64058
endloop
endfacet
facet normal 0.408496 -0.888712 0.208139
outer loop
vertex 4.29509 1.04894 3.12056
vertex 5.04918 1.04894 1.64058
vertex 5.3143 1.19098 1.72672
endloop
endfacet
facet normal -0.141078 -0.987385 -0.0718829
outer loop
vertex 4.04509 1 2.93893
vertex 3.79509 1.04894 2.75729
vertex 4.75528 1 1.54509
endloop
endfacet
facet normal 0.141078 -0.987385 0.0718829
outer loop
vertex 4.04509 1 2.93893
vertex 4.75528 1 1.54509
vertex 5.04918 1.04894 1.64058
endloop
endfacet
facet normal -0.408496 -0.888712 -0.208139
outer loop
vertex 3.79509 1.04894 2.75729
vertex 3.56956 1.19098 2.59343
vertex 4.46139 1.04894 1.44959
endloop
endfacet
facet normal -0.141078 -0.987385 -0.0718829
outer loop
vertex 3.79509 1.04894 2.75729
vertex 4.46139 1.04894 1.44959
vertex 4.75528 1 1.54509
endloop
endfacet
facet normal -0.633927 -0.702714 -0.323002
outer loop
vertex 3.56956 1.19098 2.59343
vertex 3.39058 1.41221 2.4634
vertex 4.19627 1.19098 1.36345
endloop
endfacet
facet normal -0.408496 -0.888712 -0.208139
outer loop
vertex 3.56956 1.19098 2.59343
vertex 4.19627 1.19098 1.36345
vertex 4.46139 1.04894 1.44959
endloop
endfacet
facet normal -0.795903 -0.449536 -0.405533
outer loop
vertex 3.39058 1.41221 2.4634
vertex 3.27566 1.69098 2.37991
vertex 3.98586 1.41221 1.29509
endloop
endfacet
facet normal -0.633927 -0.702713 -0.323002
outer loop
vertex 3.39058 1.41221 2.4634
vertex 3.98586 1.41221 1.29509
vertex 4.19627 1.19098 1.36345
endloop
endfacet
facet normal -0.8803 -0.154555 -0.448535
outer loop
vertex 3.27566 1.69098 2.37991
vertex 3.23607 2 2.35114
vertex 3.85077 1.69098 1.25119
endloop
endfacet
facet normal -0.795903 -0.449535 -0.405533
outer loop
vertex 3.27566 1.69098 2.37991
vertex 3.85077 1.69098 1.25119
vertex 3.98586 1.41221 1.29509
endloop
endfacet
facet normal -0.97582 0.154555 -0.154555
outer loop
vertex 3.80423 2 1.23607
vertex 3.85077 2.30902 1.25119
vertex 4 2 -3.49691e-07
endloop
endfacet
facet normal -0.97582 -0.154555 -0.154555
outer loop
vertex 3.80423 2 1.23607
vertex 4 2 -3.49691e-07
vertex 4.04894 1.69098 -3.5397e-07
endloop
endfacet
facet normal -0.882265 0.449535 -0.139737
outer loop
vertex 3.85077 2.30902 1.25119
vertex 3.98586 2.58779 1.29509
vertex 4.04894 2.30902 -3.5397e-07
endloop
endfacet
facet normal -0.97582 0.154555 -0.154555
outer loop
vertex 3.85077 2.30902 1.25119
vertex 4.04894 2.30902 -3.5397e-07
vertex 4 2 -3.49691e-07
endloop
endfacet
facet normal -0.702713 0.702714 -0.111299
outer loop
vertex 3.98586 2.58779 1.29509
vertex 4.19627 2.80902 1.36345
vertex 4.19098 2.58779 -3.66387e-07
endloop
endfacet
facet normal -0.882265 0.449536 -0.139737
outer loop
vertex 3.98586 2.58779 1.29509
vertex 4.19098 2.58779 -3.66387e-07
vertex 4.04894 2.30902 -3.5397e-07
endloop
endfacet
facet normal -0.452821 0.888712 -0.07172
outer loop
vertex 4.19627 2.80902 1.36345
vertex 4.46139 2.95106 1.44959
vertex 4.41221 2.80902 -3.85728e-07
endloop
endfacet
facet normal -0.702713 0.702714 -0.111299
outer loop
vertex 4.19627 2.80902 1.36345
vertex 4.41221 2.80902 -3.85728e-07
vertex 4.19098 2.58779 -3.66387e-07
endloop
endfacet
facet normal -0.156386 0.987385 -0.0247692
outer loop
vertex 4.46139 2.95106 1.44959
vertex 4.75528 3 1.54509
vertex 4.69098 2.95106 -4.10099e-07
endloop
endfacet
facet normal -0.452822 0.888712 -0.07172
outer loop
vertex 4.46139 2.95106 1.44959
vertex 4.69098 2.95106 -4.10099e-07
vertex 4.41221 2.80902 -3.85728e-07
endloop
endfacet
facet normal 0.156386 0.987385 0.0247692
outer loop
vertex 4.75528 3 1.54509
vertex 5.04918 2.95106 1.64058
vertex 5 3 -4.37114e-07
endloop
endfacet
facet normal -0.156387 0.987385 -0.0247692
outer loop
vertex 4.75528 3 1.54509
vertex 5 3 -4.37114e-07
vertex 4.69098 2.95106 -4.10099e-07
endloop
endfacet
facet normal 0.452822 0.888712 0.0717199
outer loop
vertex 5.04918 2.95106 1.64058
vertex 5.3143 2.80902 1.72672
vertex 5.30902 2.95106 -4.64129e-07
endloop
endfacet
facet normal 0.156387 0.987385 0.0247692
outer loop
vertex 5.04918 2.95106 1.64058
vertex 5.30902 2.95106 -4.64129e-07
vertex 5 3 -4.37114e-07
endloop
endfacet
facet normal 0.702713 0.702714 0.111299
outer loop
vertex 5.3143 2.80902 1.72672
vertex 5.5247 2.58779 1.79509
vertex 5.58779 2.80902 -4.885e-07
endloop
endfacet
facet normal 0.452822 0.888712 0.0717199
outer loop
vertex 5.3143 2.80902 1.72672
vertex 5.58779 2.80902 -4.885e-07
vertex 5.30902 2.95106 -4.64129e-07
endloop
endfacet
facet normal 0.882265 0.449536 0.139737
outer loop
vertex 5.5247 2.58779 1.79509
vertex 5.65979 2.30902 1.83898
vertex 5.80902 2.58779 -5.0784e-07
endloop
endfacet
facet normal 0.702713 0.702714 0.111299
outer loop
vertex 5.5247 2.58779 1.79509
vertex 5.80902 2.58779 -5.0784e-07
vertex 5.58779 2.80902 -4.885e-07
endloop
endfacet
facet normal 0.975821 0.154554 0.154555
outer loop
vertex 5.65979 2.30902 1.83898
vertex 5.70634 2 1.8541
vertex 5.95106 2.30902 -5.20258e-07
endloop
endfacet
facet normal 0.882265 0.449536 0.139737
outer loop
vertex 5.65979 2.30902 1.83898
vertex 5.95106 2.30902 -5.20258e-07
vertex 5.80902 2.58779 -5.0784e-07
endloop
endfacet
facet normal 0.975821 -0.154554 0.154555
outer loop
vertex 5.70634 2 1.8541
vertex 5.65979 1.69098 1.83898
vertex 6 2 -5.24537e-07
endloop
endfacet
facet normal 0.97582 0.154555 0.154555
outer loop
vertex 5.70634 2 1.8541
vertex 6 2 -5.24537e-07
vertex 5.95106 2.30902 -5.20258e-07
endloop
endfacet
facet normal 0.882265 -0.449536 0.139737
outer loop
vertex 5.65979 1.69098 1.83898
vertex 5.5247 1.41221 1.79509
vertex 5.95106 1.69098 -5.20258e-07
endloop
endfacet
facet normal 0.97582 -0.154555 0.154555
outer loop
vertex 5.65979 1.69098 1.83898
vertex 5.95106 1.69098 -5.20258e-07
vertex 6 2 -5.24537e-07
endloop
endfacet
facet normal 0.702714 -0.702713 0.111299
outer loop
vertex 5.5247 1.41221 1.79509
vertex 5.3143 1.19098 1.72672
vertex 5.80902 1.41221 -5.0784e-07
endloop
endfacet
facet normal 0.882265 -0.449536 0.139737
outer loop
vertex 5.5247 1.41221 1.79509
vertex 5.80902 1.41221 -5.0784e-07
vertex 5.95106 1.69098 -5.20258e-07
endloop
endfacet
facet normal 0.452821 -0.888712 0.0717198
outer loop
vertex 5.3143 1.19098 1.72672
vertex 5.04918 1.04894 1.64058
vertex 5.58779 1.19098 -4.885e-07
endloop
endfacet
facet normal 0.702713 -0.702714 0.111299
outer loop
vertex 5.3143 1.19098 1.72672
vertex 5.58779 1.19098 -4.885e-07
vertex 5.80902 1.41221 -5.0784e-07
endloop
endfacet
facet normal 0.156386 -0.987385 0.0247692
outer loop
vertex 5.04918 1.04894 1.64058
vertex 4.75528 1 1.54509
vertex 5.30902 1.04894 -4.64129e-07
endloop
endfacet
facet normal 0.452821 -0.888712 0.0717198
outer loop
vertex 5.04918 1.04894 1.64058
vertex 5.30902 1.04894 -4.64129e-07
vertex 5.58779 1.19098 -4.885e-07
endloop
endfacet
facet normal -0.156386 -0.987385 -0.0247692
outer loop
vertex 4.75528 1 1.54509
vertex 4.46139 1.04894 1.44959
vertex 5 1 -4.37114e-07
endloop
endfacet
facet normal 0.156386 -0.987385 0.0247692
outer loop
vertex 4.75528 1 1.54509
vertex 5 1 -4.37114e-07
vertex 5.30902 1.04894 -4.64129e-07
endloop
endfacet
facet normal -0.452821 -0.888712 -0.0717198
outer loop
vertex 4.46139 1.04894 1.44959
vertex 4.19627 1.19098 1.36345
vertex 4.69098 1.04894 -4.10099e-07
endloop
endfacet
facet normal -0.156387 -0.987385 -0.0247692
outer loop
vertex 4.46139 1.04894 1.44959
vertex 4.69098 1.04894 -4.10099e-07
vertex 5 1 -4.37114e-07
endloop
endfacet
facet normal -0.702714 -0.702713 -0.111299
outer loop
vertex 4.19627 1.19098 1.36345
vertex 3.98586 1.41221 1.29509
vertex 4.41221 1.19098 -3.85728e-07
endloop
endfacet
facet normal -0.452821 -0.888712 -0.0717199
outer loop
vertex 4.19627 1.19098 1.36345
vertex 4.41221 1.19098 -3.85728e-07
vertex 4.69098 1.04894 -4.10099e-07
endloop
endfacet
facet normal -0.882265 -0.449535 -0.139737
outer loop
vertex 3.98586 1.41221 1.29509
vertex 3.85077 1.69098 1.25119
vertex 4.19098 1.41221 -3.66387e-07
endloop
endfacet
facet normal -0.702714 -0.702714 -0.111299
outer loop
vertex 3.98586 1.41221 1.29509
vertex 4.19098 1.41221 -3.66387e-07
vertex 4.41221 1.19098 -3.85728e-07
endloop
endfacet
facet normal -0.97582 -0.154555 -0.154555
outer loop
vertex 3.85077 1.69098 1.25119
vertex 3.80423 2 1.23607
vertex 4.04894 1.69098 -3.5397e-07
endloop
endfacet
facet normal -0.882265 -0.449536 -0.139737
outer loop
vertex 3.85077 1.69098 1.25119
vertex 4.04894 1.69098 -3.5397e-07
vertex 4.19098 1.41221 -3.66387e-07
endloop
endfacet
facet normal -0.97582 0.154555 0.154555
outer loop
vertex 4 2 -3.49691e-07
vertex 4.04894 2.30902 -3.5397e-07
vertex 3.80423 2 -1.23607
endloop
endfacet
facet normal -0.97582 -0.154555 0.154555
outer loop
vertex 4 2 -3.49691e-07
vertex 3.80423 2 -1.23607
vertex 3.85077 1.69098 -1.25119
endloop
endfacet
facet normal -0.882265 0.449536 0.139737
outer loop
vertex 4.04894 2.30902 -3.5397e-07
vertex 4.19098 2.58779 -3.66387e-07
vertex 3.85077 2.30902 -1.25119
endloop
endfacet
facet normal -0.97582 0.154555 0.154555
outer loop
vertex 4.04894 2.30902 -3.5397e-07
vertex 3.85077 2.30902 -1.25119
vertex 3.80423 2 -1.23607
endloop
endfacet
facet normal -0.702713 0.702714 0.111299
outer loop
vertex 4.19098 2.58779 -3.66387e-07
vertex 4.41221 2.80902 -3.85728e-07
vertex 3.98586 2.58779 -1.29508
endloop
endfacet
facet normal -0.882265 0.449535 0.139737
outer loop
vertex 4.19098 2.58779 -3.66387e-07
vertex 3.98586 2.58779 -1.29508
vertex 3.85077 2.30902 -1.25119
endloop
endfacet
facet normal -0.452822 0.888712 0.0717199
outer loop
vertex 4.41221 2.80902 -3.85728e-07
vertex 4.69098 2.95106 -4.10099e-07
vertex 4.19627 2.80902 -1.36345
endloop
endfacet
facet normal -0.702713 0.702714 0.111299
outer loop
vertex 4.41221 2.80902 -3.85728e-07
vertex 4.19627 2.80902 -1.36345
vertex 3.98586 2.58779 -1.29508
endloop
endfacet
facet normal -0.156386 0.987385 0.0247692
outer loop
vertex 4.69098 2.95106 -4.10099e-07
vertex 5 3 -4.37114e-07
vertex 4.46139 2.95106 -1.44959
endloop
endfacet
facet normal -0.452821 0.888712 0.0717198
outer loop
vertex 4.69098 2.95106 -4.10099e-07
vertex 4.46139 2.95106 -1.44959
vertex 4.19627 2.80902 -1.36345
endloop
endfacet
facet normal 0.156386 0.987385 -0.0247692
outer loop
vertex 5 3 -4.37114e-07
vertex 5.30902 2.95106 -4.64129e-07
vertex 4.75528 3 -1.54508
endloop
endfacet
facet normal -0.156386 0.987385 0.0247692
outer loop
vertex 5 3 -4.37114e-07
vertex 4.75528 3 -1.54508
vertex 4.46139 2.95106 -1.44959
endloop
endfacet
facet normal 0.452822 0.888712 -0.0717198
outer loop
vertex 5.30902 2.95106 -4.64129e-07
vertex 5.58779 2.80902 -4.885e-07
vertex 5.04918 2.95106 -1.64058
endloop
endfacet
facet normal 0.156386 0.987385 -0.0247692
outer loop
vertex 5.30902 2.95106 -4.64129e-07
vertex 5.04918 2.95106 -1.64058
vertex 4.75528 3 -1.54508
endloop
endfacet
facet normal 0.702713 0.702714 -0.111299
outer loop
vertex 5.58779 2.80902 -4.885e-07
vertex 5.80902 2.58779 -5.0784e-07
vertex 5.3143 2.80902 -1.72672
endloop
endfacet
facet normal 0.452822 0.888712 -0.07172
outer loop
vertex 5.58779 2.80902 -4.885e-07
vertex 5.3143 2.80902 -1.72672
vertex 5.04918 2.95106 -1.64058
endloop
endfacet
facet normal 0.882265 0.449536 -0.139737
outer loop
vertex 5.80902 2.58779 -5.0784e-07
vertex 5.95106 2.30902 -5.20258e-07
vertex 5.5247 2.58779 -1.79508
endloop
endfacet
facet normal 0.702713 0.702714 -0.111299
outer loop
vertex 5.80902 2.58779 -5.0784e-07
vertex 5.5247 2.58779 -1.79508
vertex 5.3143 2.80902 -1.72672
endloop
endfacet
facet normal 0.97582 0.154555 -0.154555
outer loop
vertex 5.95106 2.30902 -5.20258e-07
vertex 6 2 -5.24537e-07
vertex 5.65979 2.30902 -1.83898
endloop
endfacet
facet normal 0.882265 0.449535 -0.139737
outer loop
vertex 5.95106 2.30902 -5.20258e-07
vertex 5.65979 2.30902 -1.83898
vertex 5.5247 2.58779 -1.79508
endloop
endfacet
facet normal 0.97582 -0.154555 -0.154555
outer loop
vertex 6 2 -5.24537e-07
vertex 5.95106 1.69098 -5.20258e-07
vertex 5.70634 2 -1.8541
endloop
endfacet
facet normal 0.97582 0.154556 -0.154555
outer loop
vertex 6 2 -5.24537e-07
vertex 5.70634 2 -1.8541
vertex 5.65979 2.30902 -1.83898
endloop
endfacet
facet normal 0.882265 -0.449536 -0.139737
outer loop
vertex 5.95106 1.69098 -5.20258e-07
vertex 5.80902 1.41221 -5.0784e-07
vertex 5.65979 1.69098 -1.83898
endloop
endfacet
facet normal 0.97582 -0.154556 -0.154555
outer loop
vertex 5.95106 1.69098 -5.20258e-07
vertex 5.65979 1.69098 -1.83898
vertex 5.70634 2 -1.8541
endloop
endfacet
facet normal 0.702713 -0.702714 -0.111299
outer loop
vertex 5.80902 1.41221 -5.0784e-07
vertex 5.58779 1.19098 -4.885e-07
vertex 5.5247 1.41221 -1.79508
endloop
endfacet
facet normal 0.882266 -0.449535 -0.139737
outer loop
vertex 5.80902 1.41221 -5.0784e-07
vertex 5.5247 1.41221 -1.79508
vertex 5.65979 1.69098 -1.83898
endloop
endfacet
facet normal 0.452821 -0.888712 -0.0717198
outer loop
vertex 5.58779 1.19098 -4.885e-07
vertex 5.30902 1.04894 -4.64129e-07
vertex 5.3143 1.19098 -1.72672
endloop
endfacet
facet normal 0.702713 -0.702714 -0.111299
outer loop
vertex 5.58779 1.19098 -4.885e-07
vertex 5.3143 1.19098 -1.72672
vertex 5.5247 1.41221 -1.79508
endloop
endfacet
facet normal 0.156386 -0.987385 -0.0247692
outer loop
vertex 5.30902 1.04894 -4.64129e-07
vertex 5 1 -4.37114e-07
vertex 5.04918 1.04894 -1.64058
endloop
endfacet
facet normal 0.452822 -0.888712 -0.0717198
outer loop
vertex 5.30902 1.04894 -4.64129e-07
vertex 5.04918 1.04894 -1.64058
vertex 5.3143 1.19098 -1.72672
endloop
endfacet
facet normal -0.156386 -0.987385 0.0247692
outer loop
vertex 5 1 -4.37114e-07
vertex 4.69098 1.04894 -4.10099e-07
vertex 4.75528 1 -1.54508
endloop
endfacet
facet normal 0.156386 -0.987385 -0.0247692
outer loop
vertex 5 1 -4.37114e-07
vertex 4.75528 1 -1.54508
vertex 5.04918 1.04894 -1.64058
endloop
endfacet
facet normal -0.452821 -0.888712 0.0717198
outer loop
vertex 4.69098 1.04894 -4.10099e-07
vertex 4.41221 1.19098 -3.85728e-07
vertex 4.46139 1.04894 -1.44959
endloop
endfacet
facet normal -0.156386 -0.987385 0.0247692
outer loop
vertex 4.69098 1.04894 -4.10099e-07
vertex 4.46139 1.04894 -1.44959
vertex 4.75528 1 -1.54508
endloop
endfacet
facet normal -0.702713 -0.702713 0.111299
outer loop
vertex 4.41221 1.19098 -3.85728e-07
vertex 4.19098 1.41221 -3.66387e-07
vertex 4.19627 1.19098 -1.36345
endloop
endfacet
facet normal -0.452821 -0.888712 0.0717198
outer loop
vertex 4.41221 1.19098 -3.85728e-07
vertex 4.19627 1.19098 -1.36345
vertex 4.46139 1.04894 -1.44959
endloop
endfacet
facet normal -0.882265 -0.449536 0.139737
outer loop
vertex 4.19098 1.41221 -3.66387e-07
vertex 4.04894 1.69098 -3.5397e-07
vertex 3.98586 1.41221 -1.29508
endloop
endfacet
facet normal -0.702713 -0.702714 0.111299
outer loop
vertex 4.19098 1.41221 -3.66387e-07
vertex 3.98586 1.41221 -1.29508
vertex 4.19627 1.19098 -1.36345
endloop
endfacet
facet normal -0.97582 -0.154555 0.154555
outer loop
vertex 4.04894 1.69098 -3.5397e-07
vertex 4 2 -3.49691e-07
vertex 3.85077 1.69098 -1.25119
endloop
endfacet
facet normal -0.882265 -0.449535 0.139737
outer loop
vertex 4.04894 1.69098 -3.5397e-07
vertex 3.85077 1.69098 -1.25119
vertex 3.98586 1.41221 -1.29508
endloop
endfacet
facet normal -0.8803 0.154555 0.448535
outer loop
vertex 3.80423 2 -1.23607
vertex 3.85077 2.30902 -1.25119
vertex 3.23607 2 -2.35114
endloop
endfacet
facet normal -0.8803 -0.154555 0.448535
outer loop
vertex 3.80423 2 -1.23607
vertex 3.23607 2 -2.35114
vertex 3.27566 1.69098 -2.37991
endloop
endfacet
facet normal -0.795903 0.449535 0.405533
outer loop
vertex 3.85077 2.30902 -1.25119
vertex 3.98586 2.58779 -1.29508
vertex 3.27566 2.30902 -2.37991
endloop
endfacet
facet normal -0.8803 0.154555 0.448536
outer loop
vertex 3.85077 2.30902 -1.25119
vertex 3.27566 2.30902 -2.37991
vertex 3.23607 2 -2.35114
endloop
endfacet
facet normal -0.633927 0.702714 0.323002
outer loop
vertex 3.98586 2.58779 -1.29508
vertex 4.19627 2.80902 -1.36345
vertex 3.39058 2.58779 -2.4634
endloop
endfacet
facet normal -0.795903 0.449536 0.405533
outer loop
vertex 3.98586 2.58779 -1.29508
vertex 3.39058 2.58779 -2.4634
vertex 3.27566 2.30902 -2.37991
endloop
endfacet
facet normal -0.408496 0.888712 0.208139
outer loop
vertex 4.19627 2.80902 -1.36345
vertex 4.46139 2.95106 -1.44959
vertex 3.56956 2.80902 -2.59344
endloop
endfacet
facet normal -0.633927 0.702714 0.323002
outer loop
vertex 4.19627 2.80902 -1.36345
vertex 3.56956 2.80902 -2.59344
vertex 3.39058 2.58779 -2.4634
endloop
endfacet
facet normal -0.141078 0.987385 0.071883
outer loop
vertex 4.46139 2.95106 -1.44959
vertex 4.75528 3 -1.54508
vertex 3.79508 2.95106 -2.75729
endloop
endfacet
facet normal -0.408496 0.888712 0.208139
outer loop
vertex 4.46139 2.95106 -1.44959
vertex 3.79508 2.95106 -2.75729
vertex 3.56956 2.80902 -2.59344
endloop
endfacet
facet normal 0.141078 0.987385 -0.071883
outer loop
vertex 4.75528 3 -1.54508
vertex 5.04918 2.95106 -1.64058
vertex 4.04508 3 -2.93893
endloop
endfacet
facet normal -0.141078 0.987385 0.0718829
outer loop
vertex 4.75528 3 -1.54508
vertex 4.04508 3 -2.93893
vertex 3.79508 2.95106 -2.75729
endloop
endfacet
facet normal 0.408497 0.888712 -0.208139
outer loop
vertex 5.04918 2.95106 -1.64058
vertex 5.3143 2.80902 -1.72672
vertex 4.29508 2.95106 -3.12056
endloop
endfacet
facet normal 0.141078 0.987385 -0.071883
outer loop
vertex 5.04918 2.95106 -1.64058
vertex 4.29508 2.95106 -3.12056
vertex 4.04508 3 -2.93893
endloop
endfacet
facet normal 0.633926 0.702714 -0.323002
outer loop
vertex 5.3143 2.80902 -1.72672
vertex 5.5247 2.58779 -1.79508
vertex 4.52061 2.80902 -3.28442
endloop
endfacet
facet normal 0.408497 0.888712 -0.208139
outer loop
vertex 5.3143 2.80902 -1.72672
vertex 4.52061 2.80902 -3.28442
vertex 4.29508 2.95106 -3.12056
endloop
endfacet
facet normal 0.795903 0.449535 -0.405533
outer loop
vertex 5.5247 2.58779 -1.79508
vertex 5.65979 2.30902 -1.83898
vertex 4.69959 2.58779 -3.41446
endloop
endfacet
facet normal 0.633926 0.702714 -0.323002
outer loop
vertex 5.5247 2.58779 -1.79508
vertex 4.69959 2.58779 -3.41446
vertex 4.52061 2.80902 -3.28442
endloop
endfacet
facet normal 0.8803 0.154556 -0.448535
outer loop
vertex 5.65979 2.30902 -1.83898
vertex 5.70634 2 -1.8541
vertex 4.81451 2.30902 -3.49794
endloop
endfacet
facet normal 0.795903 0.449535 -0.405533
outer loop
vertex 5.65979 2.30902 -1.83898
vertex 4.81451 2.30902 -3.49794
vertex 4.69959 2.58779 -3.41446
endloop
endfacet
facet normal 0.8803 -0.154556 -0.448535
outer loop
vertex 5.70634 2 -1.8541
vertex 5.65979 1.69098 -1.83898
vertex 4.8541 2 -3.52671
endloop
endfacet
facet normal 0.8803 0.154555 -0.448536
outer loop
vertex 5.70634 2 -1.8541
vertex 4.8541 2 -3.52671
vertex 4.81451 2.30902 -3.49794
endloop
endfacet
facet normal 0.795903 -0.449534 -0.405533
outer loop
vertex 5.65979 1.69098 -1.83898
vertex 5.5247 1.41221 -1.79508
vertex 4.81451 1.69098 -3.49794
endloop
endfacet
facet normal 0.8803 -0.154555 -0.448535
outer loop
vertex 5.65979 1.69098 -1.83898
vertex 4.81451 1.69098 -3.49794
vertex 4.8541 2 -3.52671
endloop
endfacet
facet normal 0.633926 -0.702714 -0.323002
outer loop
vertex 5.5247 1.41221 -1.79508
vertex 5.3143 1.19098 -1.72672
vertex 4.69959 1.41221 -3.41446
endloop
endfacet
facet normal 0.795903 -0.449535 -0.405533
outer loop
vertex 5.5247 1.41221 -1.79508
vertex 4.69959 1.41221 -3.41446
vertex 4.81451 1.69098 -3.49794
endloop
endfacet
facet normal 0.408496 -0.888712 -0.208139
outer loop
vertex 5.3143 1.19098 -1.72672
vertex 5.04918 1.04894 -1.64058
vertex 4.52061 1.19098 -3.28442
endloop
endfacet
facet normal 0.633926 -0.702714 -0.323002
outer loop
vertex 5.3143 1.19098 -1.72672
vertex 4.52061 1.19098 -3.28442
vertex 4.69959 1.41221 -3.41446
endloop
endfacet
facet normal 0.141078 -0.987385 -0.071883
outer loop
vertex 5.04918 1.04894 -1.64058
vertex 4.75528 1 -1.54508
vertex 4.29508 1.04894 -3.12056
endloop
endfacet
facet normal 0.408496 -0.888712 -0.208139
outer loop
vertex 5.04918 1.04894 -1.64058
vertex 4.29508 1.04894 -3.12056
vertex 4.52061 1.19098 -3.28442
endloop
endfacet
facet normal -0.141078 -0.987385 0.071883
outer loop
vertex 4.75528 1 -1.54508
vertex 4.46139 1.04894 -1.44959
vertex 4.04508 1 -2.93893
endloop
endfacet
facet normal 0.141078 -0.987385 -0.071883
outer loop
vertex 4.75528 1 -1.54508
vertex 4.04508 1 -2.93893
vertex 4.29508 1.04894 -3.12056
endloop
endfacet
facet normal -0.408496 -0.888712 0.208139
outer loop
vertex 4.46139 1.04894 -1.44959
vertex 4.19627 1.19098 -1.36345
vertex 3.79508 1.04894 -2.75729
endloop
endfacet
facet normal -0.141078 -0.987385 0.0718829
outer loop
vertex 4.46139 1.04894 -1.44959
vertex 3.79508 1.04894 -2.75729
vertex 4.04508 1 -2.93893
endloop
endfacet
facet normal -0.633927 -0.702714 0.323002
outer loop
vertex 4.19627 1.19098 -1.36345
vertex 3.98586 1.41221 -1.29508
vertex 3.56956 1.19098 -2.59344
endloop
endfacet
facet normal -0.408496 -0.888712 0.208139
outer loop
vertex 4.19627 1.19098 -1.36345
vertex 3.56956 1.19098 -2.59344
vertex 3.79508 1.04894 -2.75729
endloop
endfacet
facet normal -0.795903 -0.449535 0.405533
outer loop
vertex 3.98586 1.41221 -1.29508
vertex 3.85077 1.69098 -1.25119
vertex 3.39058 1.41221 -2.4634
endloop
endfacet
facet normal -0.633927 -0.702713 0.323002
outer loop
vertex 3.98586 1.41221 -1.29508
vertex 3.39058 1.41221 -2.4634
vertex 3.56956 1.19098 -2.59344
endloop
endfacet
facet normal -0.8803 -0.154555 0.448536
outer loop
vertex 3.85077 1.69098 -1.25119
vertex 3.80423 2 -1.23607
vertex 3.27566 1.69098 -2.37991
endloop
endfacet
facet normal -0.795903 -0.449536 0.405533
outer loop
vertex 3.85077 1.69098 -1.25119
vertex 3.27566 1.69098 -2.37991
vertex 3.39058 1.41221 -2.4634
endloop
endfacet
facet normal -0.69861 0.154555 0.698611
outer loop
vertex 3.23607 2 -2.35114
vertex 3.27566 2.30902 -2.37991
vertex 2.35114 2 -3.23607
endloop
endfacet
facet normal -0.69861 -0.154555 0.698611
outer loop
vertex 3.23607 2 -2.35114
vertex 2.35114 2 -3.23607
vertex 2.37991 1.69098 -3.27566
endloop
endfacet
facet normal -0.631632 0.449536 0.631632
outer loop
vertex 3.27566 2.30902 -2.37991
vertex 3.39058 2.58779 -2.4634
vertex 2.37991 2.30902 -3.27566
endloop
endfacet
facet normal -0.69861 0.154555 0.69861
outer loop
vertex 3.27566 2.30902 -2.37991
vertex 2.37991 2.30902 -3.27566
vertex 2.35114 2 -3.23607
endloop
endfacet
facet normal -0.503087 0.702714 0.503087
outer loop
vertex 3.39058 2.58779 -2.4634
vertex 3.56956 2.80902 -2.59344
vertex 2.4634 2.58779 -3.39058
endloop
endfacet
facet normal -0.631632 0.449536 0.631632
outer loop
vertex 3.39058 2.58779 -2.4634
vertex 2.4634 2.58779 -3.39058
vertex 2.37991 2.30902 -3.27566
endloop
endfacet
facet normal -0.324184 0.888712 0.324185
outer loop
vertex 3.56956 2.80902 -2.59344
vertex 3.79508 2.95106 -2.75729
vertex 2.59343 2.80902 -3.56956
endloop
endfacet
facet normal -0.503087 0.702714 0.503087
outer loop
vertex 3.56956 2.80902 -2.59344
vertex 2.59343 2.80902 -3.56956
vertex 2.4634 2.58779 -3.39058
endloop
endfacet
facet normal -0.11196 0.987385 0.11196
outer loop
vertex 3.79508 2.95106 -2.75729
vertex 4.04508 3 -2.93893
vertex 2.75729 2.95106 -3.79509
endloop
endfacet
facet normal -0.324184 0.888712 0.324184
outer loop
vertex 3.79508 2.95106 -2.75729
vertex 2.75729 2.95106 -3.79509
vertex 2.59343 2.80902 -3.56956
endloop
endfacet
facet normal 0.11196 0.987385 -0.11196
outer loop
vertex 4.04508 3 -2.93893
vertex 4.29508 2.95106 -3.12056
vertex 2.93893 3 -4.04509
endloop
endfacet
facet normal -0.11196 0.987385 0.11196
outer loop
vertex 4.04508 3 -2.93893
vertex 2.93893 3 -4.04509
vertex 2.75729 2.95106 -3.79509
endloop
endfacet
facet normal 0.324185 0.888712 -0.324185
outer loop
vertex 4.29508 2.95106 -3.12056
vertex 4.52061 2.80902 -3.28442
vertex 3.12056 2.95106 -4.29509
endloop
endfacet
facet normal 0.11196 0.987385 -0.11196
outer loop
vertex 4.29508 2.95106 -3.12056
vertex 3.12056 2.95106 -4.29509
vertex 2.93893 3 -4.04509
endloop
endfacet
facet normal 0.503087 0.702714 -0.503087
outer loop
vertex 4.52061 2.80902 -3.28442
vertex 4.69959 2.58779 -3.41446
vertex 3.28442 2.80902 -4.52061
endloop
endfacet
facet normal 0.324185 0.888712 -0.324185
outer loop
vertex 4.52061 2.80902 -3.28442
vertex 3.28442 2.80902 -4.52061
vertex 3.12056 2.95106 -4.29509
endloop
endfacet
facet normal 0.631632 0.449535 -0.631632
outer loop
vertex 4.69959 2.58779 -3.41446
vertex 4.81451 2.30902 -3.49794
vertex 3.41445 2.58779 -4.69959
endloop
endfacet
facet normal 0.503087 0.702714 -0.503087
outer loop
vertex 4.69959 2.58779 -3.41446
vertex 3.41445 2.58779 -4.69959
vertex 3.28442 2.80902 -4.52061
endloop
endfacet
facet normal 0.69861 0.154555 -0.698611
outer loop
vertex 4.81451 2.30902 -3.49794
vertex 4.8541 2 -3.52671
vertex 3.49794 2.30902 -4.81451
endloop
endfacet
facet normal 0.631632 0.449536 -0.631632
outer loop
vertex 4.81451 2.30902 -3.49794
vertex 3.49794 2.30902 -4.81451
vertex 3.41445 2.58779 -4.69959
endloop
endfacet
facet normal 0.69861 -0.154555 -0.698611
outer loop
vertex 4.8541 2 -3.52671
vertex 4.81451 1.69098 -3.49794
vertex 3.52671 2 -4.8541
endloop
endfacet
facet normal 0.69861 0.154555 -0.698611
outer loop
vertex 4.8541 2 -3.52671
vertex 3.52671 2 -4.8541
vertex 3.49794 2.30902 -4.81451
endloop
endfacet
facet normal 0.631632 -0.449535 -0.631632
outer loop
vertex 4.81451 1.69098 -3.49794
vertex 4.69959 1.41221 -3.41446
vertex 3.49794 1.69098 -4.81451
endloop
endfacet
facet normal 0.69861 -0.154555 -0.698611
outer loop
vertex 4.81451 1.69098 -3.49794
vertex 3.49794 1.69098 -4.81451
vertex 3.52671 2 -4.8541
endloop
endfacet
facet normal 0.503087 -0.702714 -0.503087
outer loop
vertex 4.69959 1.41221 -3.41446
vertex 4.52061 1.19098 -3.28442
vertex 3.41445 1.41221 -4.69959
endloop
endfacet
facet normal 0.631632 -0.449535 -0.631632
outer loop
vertex 4.69959 1.41221 -3.41446
vertex 3.41445 1.41221 -4.69959
vertex 3.49794 1.69098 -4.81451
endloop
endfacet
facet normal 0.324184 -0.888712 -0.324184
outer loop
vertex 4.52061 1.19098 -3.28442
vertex 4.29508 1.04894 -3.12056
vertex 3.28442 1.19098 -4.52061
endloop
endfacet
facet normal 0.503087 -0.702714 -0.503087
outer loop
vertex 4.52061 1.19098 -3.28442
vertex 3.28442 1.19098 -4.52061
vertex 3.41445 1.41221 -4.69959
endloop
endfacet
facet normal 0.11196 -0.987385 -0.11196
outer loop
vertex 4.29508 1.04894 -3.12056
vertex 4.04508 1 -2.93893
vertex 3.12056 1.04894 -4.29509
endloop
endfacet
facet normal 0.324184 -0.888712 -0.324184
outer loop
vertex 4.29508 1.04894 -3.12056
vertex 3.12056 1.04894 -4.29509
vertex 3.28442 1.19098 -4.52061
endloop
endfacet
facet normal -0.11196 -0.987385 0.11196
outer loop
vertex 4.04508 1 -2.93893
vertex 3.79508 1.04894 -2.75729
vertex 2.93893 1 -4.04509
endloop
endfacet
facet normal 0.11196 -0.987385 -0.11196
outer loop
vertex 4.04508 1 -2.93893
vertex 2.93893 1 -4.04509
vertex 3.12056 1.04894 -4.29509
endloop
endfacet
facet normal -0.324184 -0.888712 0.324184
outer loop
vertex 3.79508 1.04894 -2.75729
vertex 3.56956 1.19098 -2.59344
vertex 2.75729 1.04894 -3.79509
endloop
endfacet
facet normal -0.11196 -0.987385 0.11196
outer loop
vertex 3.79508 1.04894 -2.75729
vertex 2.75729 1.04894 -3.79509
vertex 2.93893 1 -4.04509
endloop
endfacet
facet normal -0.503087 -0.702713 0.503088
outer loop
vertex 3.56956 1.19098 -2.59344
vertex 3.39058 1.41221 -2.4634
vertex 2.59343 1.19098 -3.56956
endloop
endfacet
facet normal -0.324184 -0.888712 0.324184
outer loop
vertex 3.56956 1.19098 -2.59344
vertex 2.59343 1.19098 -3.56956
vertex 2.75729 1.04894 -3.79509
endloop
endfacet
facet normal -0.631632 -0.449536 0.631632
outer loop
vertex 3.39058 1.41221 -2.4634
vertex 3.27566 1.69098 -2.37991
vertex 2.4634 1.41221 -3.39058
endloop
endfacet
facet normal -0.503087 -0.702713 0.503088
outer loop
vertex 3.39058 1.41221 -2.4634
vertex 2.4634 1.41221 -3.39058
vertex 2.59343 1.19098 -3.56956
endloop
endfacet
facet normal -0.69861 -0.154555 0.69861
outer loop
vertex 3.27566 1.69098 -2.37991
vertex 3.23607 2 -2.35114
vertex 2.37991 1.69098 -3.27566
endloop
endfacet
facet normal -0.631632 -0.449535 0.631632
outer loop
vertex 3.27566 1.69098 -2.37991
vertex 2.37991 1.69098 -3.27566
vertex 2.4634 1.41221 -3.39058
endloop
endfacet
facet normal -0.448535 0.154555 0.8803
outer loop
vertex 2.35114 2 -3.23607
vertex 2.37991 2.30902 -3.27566
vertex 1.23607 2 -3.80423
endloop
endfacet
facet normal -0.448535 -0.154555 0.8803
outer loop
vertex 2.35114 2 -3.23607
vertex 1.23607 2 -3.80423
vertex 1.25119 1.69098 -3.85077
endloop
endfacet
facet normal -0.405533 0.449536 0.795903
outer loop
vertex 2.37991 2.30902 -3.27566
vertex 2.4634 2.58779 -3.39058
vertex 1.25119 2.30902 -3.85077
endloop
endfacet
facet normal -0.448536 0.154555 0.8803
outer loop
vertex 2.37991 2.30902 -3.27566
vertex 1.25119 2.30902 -3.85077
vertex 1.23607 2 -3.80423
endloop
endfacet
facet normal -0.323002 0.702714 0.633927
outer loop
vertex 2.4634 2.58779 -3.39058
vertex 2.59343 2.80902 -3.56956
vertex 1.29509 2.58779 -3.98586
endloop
endfacet
facet normal -0.405533 0.449535 0.795903
outer loop
vertex 2.4634 2.58779 -3.39058
vertex 1.29509 2.58779 -3.98586
vertex 1.25119 2.30902 -3.85077
endloop
endfacet
facet normal -0.208139 0.888712 0.408496
outer loop
vertex 2.59343 2.80902 -3.56956
vertex 2.75729 2.95106 -3.79509
vertex 1.36345 2.80902 -4.19627
endloop
endfacet
facet normal -0.323002 0.702714 0.633927
outer loop
vertex 2.59343 2.80902 -3.56956
vertex 1.36345 2.80902 -4.19627
vertex 1.29509 2.58779 -3.98586
endloop
endfacet
facet normal -0.071883 0.987385 0.141078
outer loop
vertex 2.75729 2.95106 -3.79509
vertex 2.93893 3 -4.04509
vertex 1.44959 2.95106 -4.46139
endloop
endfacet
facet normal -0.208139 0.888712 0.408496
outer loop
vertex 2.75729 2.95106 -3.79509
vertex 1.44959 2.95106 -4.46139
vertex 1.36345 2.80902 -4.19627
endloop
endfacet
facet normal 0.0718829 0.987385 -0.141078
outer loop
vertex 2.93893 3 -4.04509
vertex 3.12056 2.95106 -4.29509
vertex 1.54509 3 -4.75528
endloop
endfacet
facet normal -0.071883 0.987385 0.141078
outer loop
vertex 2.93893 3 -4.04509
vertex 1.54509 3 -4.75528
vertex 1.44959 2.95106 -4.46139
endloop
endfacet
facet normal 0.208139 0.888712 -0.408496
outer loop
vertex 3.12056 2.95106 -4.29509
vertex 3.28442 2.80902 -4.52061
vertex 1.64058 2.95106 -5.04918
endloop
endfacet
facet normal 0.0718829 0.987385 -0.141078
outer loop
vertex 3.12056 2.95106 -4.29509
vertex 1.64058 2.95106 -5.04918
vertex 1.54509 3 -4.75528
endloop
endfacet
facet normal 0.323002 0.702714 -0.633927
outer loop
vertex 3.28442 2.80902 -4.52061
vertex 3.41445 2.58779 -4.69959
vertex 1.72672 2.80902 -5.3143
endloop
endfacet
facet normal 0.208139 0.888712 -0.408496
outer loop
vertex 3.28442 2.80902 -4.52061
vertex 1.72672 2.80902 -5.3143
vertex 1.64058 2.95106 -5.04918
endloop
endfacet
facet normal 0.405533 0.449535 -0.795903
outer loop
vertex 3.41445 2.58779 -4.69959
vertex 3.49794 2.30902 -4.81451
vertex 1.79509 2.58779 -5.5247
endloop
endfacet
facet normal 0.323002 0.702714 -0.633927
outer loop
vertex 3.41445 2.58779 -4.69959
vertex 1.79509 2.58779 -5.5247
vertex 1.72672 2.80902 -5.3143
endloop
endfacet
facet normal 0.448535 0.154555 -0.8803
outer loop
vertex 3.49794 2.30902 -4.81451
vertex 3.52671 2 -4.8541
vertex 1.83898 2.30902 -5.65979
endloop
endfacet
facet normal 0.405533 0.449536 -0.795902
outer loop
vertex 3.49794 2.30902 -4.81451
vertex 1.83898 2.30902 -5.65979
vertex 1.79509 2.58779 -5.5247
endloop
endfacet
facet normal 0.448535 -0.154555 -0.8803
outer loop
vertex 3.52671 2 -4.8541
vertex 3.49794 1.69098 -4.81451
vertex 1.8541 2 -5.70634
endloop
endfacet
facet normal 0.448535 0.154555 -0.8803
outer loop
vertex 3.52671 2 -4.8541
vertex 1.8541 2 -5.70634
vertex 1.83898 2.30902 -5.65979
endloop
endfacet
facet normal 0.405533 -0.449535 -0.795903
outer loop
vertex 3.49794 1.69098 -4.81451
vertex 3.41445 1.41221 -4.69959
vertex 1.83898 1.69098 -5.65979
endloop
endfacet
facet normal 0.448536 -0.154555 -0.8803
outer loop
vertex 3.49794 1.69098 -4.81451
vertex 1.83898 1.69098 -5.65979
vertex 1.8541 2 -5.70634
endloop
endfacet
facet normal 0.323002 -0.702714 -0.633927
outer loop
vertex 3.41445 1.41221 -4.69959
vertex 3.28442 1.19098 -4.52061
vertex 1.79509 1.41221 -5.5247
endloop
endfacet
facet normal 0.405533 -0.449536 -0.795903
outer loop
vertex 3.41445 1.41221 -4.69959
vertex 1.79509 1.41221 -5.5247
vertex 1.83898 1.69098 -5.65979
endloop
endfacet
facet normal 0.208139 -0.888712 -0.408496
outer loop
vertex 3.28442 1.19098 -4.52061
vertex 3.12056 1.04894 -4.29509
vertex 1.72672 1.19098 -5.3143
endloop
endfacet
facet normal 0.323002 -0.702713 -0.633927
outer loop
vertex 3.28442 1.19098 -4.52061
vertex 1.72672 1.19098 -5.3143
vertex 1.79509 1.41221 -5.5247
endloop
endfacet
facet normal 0.0718829 -0.987385 -0.141078
outer loop
vertex 3.12056 1.04894 -4.29509
vertex 2.93893 1 -4.04509
vertex 1.64058 1.04894 -5.04918
endloop
endfacet
facet normal 0.208139 -0.888712 -0.408496
outer loop
vertex 3.12056 1.04894 -4.29509
vertex 1.64058 1.04894 -5.04918
vertex 1.72672 1.19098 -5.3143
endloop
endfacet
facet normal -0.071883 -0.987385 0.141078
outer loop
vertex 2.93893 1 -4.04509
vertex 2.75729 1.04894 -3.79509
vertex 1.54509 1 -4.75528
endloop
endfacet
facet normal 0.071883 -0.987385 -0.141078
outer loop
vertex 2.93893 1 -4.04509
vertex 1.54509 1 -4.75528
vertex 1.64058 1.04894 -5.04918
endloop
endfacet
facet normal -0.208139 -0.888712 0.408496
outer loop
vertex 2.75729 1.04894 -3.79509
vertex 2.59343 1.19098 -3.56956
vertex 1.44959 1.04894 -4.46139
endloop
endfacet
facet normal -0.0718829 -0.987385 0.141078
outer loop
vertex 2.75729 1.04894 -3.79509
vertex 1.44959 1.04894 -4.46139
vertex 1.54509 1 -4.75528
endloop
endfacet
facet normal -0.323002 -0.702713 0.633927
outer loop
vertex 2.59343 1.19098 -3.56956
vertex 2.4634 1.41221 -3.39058
vertex 1.36345 1.19098 -4.19627
endloop
endfacet
facet normal -0.208139 -0.888712 0.408496
outer loop
vertex 2.59343 1.19098 -3.56956
vertex 1.36345 1.19098 -4.19627
vertex 1.44959 1.04894 -4.46139
endloop
endfacet
facet normal -0.405533 -0.449536 0.795903
outer loop
vertex 2.4634 1.41221 -3.39058
vertex 2.37991 1.69098 -3.27566
vertex 1.29509 1.41221 -3.98586
endloop
endfacet
facet normal -0.323002 -0.702713 0.633927
outer loop
vertex 2.4634 1.41221 -3.39058
vertex 1.29509 1.41221 -3.98586
vertex 1.36345 1.19098 -4.19627
endloop
endfacet
facet normal -0.448536 -0.154555 0.8803
outer loop
vertex 2.37991 1.69098 -3.27566
vertex 2.35114 2 -3.23607
vertex 1.25119 1.69098 -3.85077
endloop
endfacet
facet normal -0.405533 -0.449535 0.795903
outer loop
vertex 2.37991 1.69098 -3.27566
vertex 1.25119 1.69098 -3.85077
vertex 1.29509 1.41221 -3.98586
endloop
endfacet
facet normal -0.154555 0.154555 0.97582
outer loop
vertex 1.23607 2 -3.80423
vertex 1.25119 2.30902 -3.85077
vertex -4.76995e-08 2 -4
endloop
endfacet
facet normal -0.154555 -0.154555 0.97582
outer loop
vertex 1.23607 2 -3.80423
vertex -4.76995e-08 2 -4
vertex -4.82832e-08 1.69098 -4.04894
endloop
endfacet
facet normal -0.139737 0.449535 0.882265
outer loop
vertex 1.25119 2.30902 -3.85077
vertex 1.29509 2.58779 -3.98586
vertex -4.82832e-08 2.30902 -4.04894
endloop
endfacet
facet normal -0.154555 0.154555 0.97582
outer loop
vertex 1.25119 2.30902 -3.85077
vertex -4.82832e-08 2.30902 -4.04894
vertex -4.76995e-08 2 -4
endloop
endfacet
facet normal -0.111299 0.702714 0.702713
outer loop
vertex 1.29509 2.58779 -3.98586
vertex 1.36345 2.80902 -4.19627
vertex -4.9977e-08 2.58779 -4.19098
endloop
endfacet
facet normal -0.139737 0.449536 0.882265
outer loop
vertex 1.29509 2.58779 -3.98586
vertex -4.9977e-08 2.58779 -4.19098
vertex -4.82832e-08 2.30902 -4.04894
endloop
endfacet
facet normal -0.07172 0.888712 0.452821
outer loop
vertex 1.36345 2.80902 -4.19627
vertex 1.44959 2.95106 -4.46139
vertex -5.26151e-08 2.80902 -4.41221
endloop
endfacet
facet normal -0.111299 0.702714 0.702713
outer loop
vertex 1.36345 2.80902 -4.19627
vertex -5.26151e-08 2.80902 -4.41221
vertex -4.9977e-08 2.58779 -4.19098
endloop
endfacet
facet normal -0.0247692 0.987385 0.156386
outer loop
vertex 1.44959 2.95106 -4.46139
vertex 1.54509 3 -4.75528
vertex -5.59394e-08 2.95106 -4.69098
endloop
endfacet
facet normal -0.07172 0.888712 0.452822
outer loop
vertex 1.44959 2.95106 -4.46139
vertex -5.59394e-08 2.95106 -4.69098
vertex -5.26151e-08 2.80902 -4.41221
endloop
endfacet
facet normal 0.0247692 0.987385 -0.156386
outer loop
vertex 1.54509 3 -4.75528
vertex 1.64058 2.95106 -5.04918
vertex -5.96244e-08 3 -5
endloop
endfacet
facet normal -0.0247692 0.987385 0.156386
outer loop
vertex 1.54509 3 -4.75528
vertex -5.96244e-08 3 -5
vertex -5.59394e-08 2.95106 -4.69098
endloop
endfacet
facet normal 0.0717199 0.888712 -0.452822
outer loop
vertex 1.64058 2.95106 -5.04918
vertex 1.72672 2.80902 -5.3143
vertex -6.33094e-08 2.95106 -5.30902
endloop
endfacet
facet normal 0.0247692 0.987385 -0.156387
outer loop
vertex 1.64058 2.95106 -5.04918
vertex -6.33094e-08 2.95106 -5.30902
vertex -5.96244e-08 3 -5
endloop
endfacet
facet normal 0.111299 0.702714 -0.702713
outer loop
vertex 1.72672 2.80902 -5.3143
vertex 1.79509 2.58779 -5.5247
vertex -6.66337e-08 2.80902 -5.58779
endloop
endfacet
facet normal 0.0717199 0.888712 -0.452822
outer loop
vertex 1.72672 2.80902 -5.3143
vertex -6.66337e-08 2.80902 -5.58779
vertex -6.33094e-08 2.95106 -5.30902
endloop
endfacet
facet normal 0.139737 0.449536 -0.882265
outer loop
vertex 1.79509 2.58779 -5.5247
vertex 1.83898 2.30902 -5.65979
vertex -6.92718e-08 2.58779 -5.80902
endloop
endfacet
facet normal 0.111299 0.702714 -0.702713
outer loop
vertex 1.79509 2.58779 -5.5247
vertex -6.92718e-08 2.58779 -5.80902
vertex -6.66337e-08 2.80902 -5.58779
endloop
endfacet
facet normal 0.154555 0.154554 -0.975821
outer loop
vertex 1.83898 2.30902 -5.65979
vertex 1.8541 2 -5.70634
vertex -7.09656e-08 2.30902 -5.95106
endloop
endfacet
facet normal 0.139737 0.449536 -0.882265
outer loop
vertex 1.83898 2.30902 -5.65979
vertex -7.09656e-08 2.30902 -5.95106
vertex -6.92718e-08 2.58779 -5.80902
endloop
endfacet
facet normal 0.154555 -0.154555 -0.975821
outer loop
vertex 1.8541 2 -5.70634
vertex 1.83898 1.69098 -5.65979
vertex -7.15493e-08 2 -6
endloop
endfacet
facet normal 0.154555 0.154555 -0.97582
outer loop
vertex 1.8541 2 -5.70634
vertex -7.15493e-08 2 -6
vertex -7.09656e-08 2.30902 -5.95106
endloop
endfacet
facet normal 0.139737 -0.449536 -0.882265
outer loop
vertex 1.83898 1.69098 -5.65979
vertex 1.79509 1.41221 -5.5247
vertex -7.09656e-08 1.69098 -5.95106
endloop
endfacet
facet normal 0.154555 -0.154555 -0.97582
outer loop
vertex 1.83898 1.69098 -5.65979
vertex -7.09656e-08 1.69098 -5.95106
vertex -7.15493e-08 2 -6
endloop
endfacet
facet normal 0.111299 -0.702713 -0.702714
outer loop
vertex 1.79509 1.41221 -5.5247
vertex 1.72672 1.19098 -5.3143
vertex -6.92718e-08 1.41221 -5.80902
endloop
endfacet
facet normal 0.139737 -0.449536 -0.882265
outer loop
vertex 1.79509 1.41221 -5.5247
vertex -6.92718e-08 1.41221 -5.80902
vertex -7.09656e-08 1.69098 -5.95106
endloop
endfacet
facet normal 0.0717198 -0.888712 -0.452821
outer loop
vertex 1.72672 1.19098 -5.3143
vertex 1.64058 1.04894 -5.04918
vertex -6.66337e-08 1.19098 -5.58779
endloop
endfacet
facet normal 0.111299 -0.702714 -0.702713
outer loop
vertex 1.72672 1.19098 -5.3143
vertex -6.66337e-08 1.19098 -5.58779
vertex -6.92718e-08 1.41221 -5.80902
endloop
endfacet
facet normal 0.0247692 -0.987385 -0.156386
outer loop
vertex 1.64058 1.04894 -5.04918
vertex 1.54509 1 -4.75528
vertex -6.33094e-08 1.04894 -5.30902
endloop
endfacet
facet normal 0.0717198 -0.888712 -0.452821
outer loop
vertex 1.64058 1.04894 -5.04918
vertex -6.33094e-08 1.04894 -5.30902
vertex -6.66337e-08 1.19098 -5.58779
endloop
endfacet
facet normal -0.0247692 -0.987385 0.156386
outer loop
vertex 1.54509 1 -4.75528
vertex 1.44959 1.04894 -4.46139
vertex -5.96244e-08 1 -5
endloop
endfacet
facet normal 0.0247692 -0.987385 -0.156386
outer loop
vertex 1.54509 1 -4.75528
vertex -5.96244e-08 1 -5
vertex -6.33094e-08 1.04894 -5.30902
endloop
endfacet
facet normal -0.0717198 -0.888712 0.452821
outer loop
vertex 1.44959 1.04894 -4.46139
vertex 1.36345 1.19098 -4.19627
vertex -5.59394e-08 1.04894 -4.69098
endloop
endfacet
facet normal -0.0247692 -0.987385 0.156387
outer loop
vertex 1.44959 1.04894 -4.46139
vertex -5.59394e-08 1.04894 -4.69098
vertex -5.96244e-08 1 -5
endloop
endfacet
facet normal -0.111299 -0.702713 0.702714
outer loop
vertex 1.36345 1.19098 -4.19627
vertex 1.29509 1.41221 -3.98586
vertex -5.26151e-08 1.19098 -4.41221
endloop
endfacet
facet normal -0.0717199 -0.888712 0.452821
outer loop
vertex 1.36345 1.19098 -4.19627
vertex -5.26151e-08 1.19098 -4.41221
vertex -5.59394e-08 1.04894 -4.69098
endloop
endfacet
facet normal -0.139737 -0.449535 0.882265
outer loop
vertex 1.29509 1.41221 -3.98586
vertex 1.25119 1.69098 -3.85077
vertex -4.9977e-08 1.41221 -4.19098
endloop
endfacet
facet normal -0.111299 -0.702714 0.702714
outer loop
vertex 1.29509 1.41221 -3.98586
vertex -4.9977e-08 1.41221 -4.19098
vertex -5.26151e-08 1.19098 -4.41221
endloop
endfacet
facet normal -0.154555 -0.154555 0.97582
outer loop
vertex 1.25119 1.69098 -3.85077
vertex 1.23607 2 -3.80423
vertex -4.82832e-08 1.69098 -4.04894
endloop
endfacet
facet normal -0.139737 -0.449536 0.882265
outer loop
vertex 1.25119 1.69098 -3.85077
vertex -4.82832e-08 1.69098 -4.04894
vertex -4.9977e-08 1.41221 -4.19098
endloop
endfacet
facet normal 0.154555 0.154555 0.97582
outer loop
vertex -4.76995e-08 2 -4
vertex -4.82832e-08 2.30902 -4.04894
vertex -1.23607 2 -3.80423
endloop
endfacet
facet normal 0.154555 -0.154555 0.97582
outer loop
vertex -4.76995e-08 2 -4
vertex -1.23607 2 -3.80423
vertex -1.25119 1.69098 -3.85077
endloop
endfacet
facet normal 0.139737 0.449536 0.882265
outer loop
vertex -4.82832e-08 2.30902 -4.04894
vertex -4.9977e-08 2.58779 -4.19098
vertex -1.25119 2.30902 -3.85077
endloop
endfacet
facet normal 0.154555 0.154555 0.97582
outer loop
vertex -4.82832e-08 2.30902 -4.04894
vertex -1.25119 2.30902 -3.85077
vertex -1.23607 2 -3.80423
endloop
endfacet
facet normal 0.111299 0.702714 0.702713
outer loop
vertex -4.9977e-08 2.58779 -4.19098
vertex -5.26151e-08 2.80902 -4.41221
vertex -1.29509 2.58779 -3.98586
endloop
endfacet
facet normal 0.139737 0.449535 0.882265
outer loop
vertex -4.9977e-08 2.58779 -4.19098
vertex -1.29509 2.58779 -3.98586
vertex -1.25119 2.30902 -3.85077
endloop
endfacet
facet normal 0.07172 0.888712 0.452822
outer loop
vertex -5.26151e-08 2.80902 -4.41221
vertex -5.59394e-08 2.95106 -4.69098
vertex -1.36345 2.80902 -4.19627
endloop
endfacet
facet normal 0.111299 0.702714 0.702713
outer loop
vertex -5.26151e-08 2.80902 -4.41221
vertex -1.36345 2.80902 -4.19627
vertex -1.29509 2.58779 -3.98586
endloop
endfacet
facet normal 0.0247692 0.987385 0.156386
outer loop
vertex -5.59394e-08 2.95106 -4.69098
vertex -5.96244e-08 3 -5
vertex -1.44959 2.95106 -4.46139
endloop
endfacet
facet normal 0.0717199 0.888712 0.452822
outer loop
vertex -5.59394e-08 2.95106 -4.69098
vertex -1.44959 2.95106 -4.46139
vertex -1.36345 2.80902 -4.19627
endloop
endfacet
facet normal -0.0247692 0.987385 -0.156386
outer loop
vertex -5.96244e-08 3 -5
vertex -6.33094e-08 2.95106 -5.30902
vertex -1.54509 3 -4.75528
endloop
endfacet
facet normal 0.0247692 0.987385 0.156386
outer loop
vertex -5.96244e-08 3 -5
vertex -1.54509 3 -4.75528
vertex -1.44959 2.95106 -4.46139
endloop
endfacet
facet normal -0.0717199 0.888712 -0.452822
outer loop
vertex -6.33094e-08 2.95106 -5.30902
vertex -6.66337e-08 2.80902 -5.58779
vertex -1.64058 2.95106 -5.04918
endloop
endfacet
facet normal -0.0247692 0.987385 -0.156386
outer loop
vertex -6.33094e-08 2.95106 -5.30902
vertex -1.64058 2.95106 -5.04918
vertex -1.54509 3 -4.75528
endloop
endfacet
facet normal -0.111299 0.702714 -0.702713
outer loop
vertex -6.66337e-08 2.80902 -5.58779
vertex -6.92718e-08 2.58779 -5.80902
vertex -1.72672 2.80902 -5.3143
endloop
endfacet
facet normal -0.0717198 0.888712 -0.452821
outer loop
vertex -6.66337e-08 2.80902 -5.58779
vertex -1.72672 2.80902 -5.3143
vertex -1.64058 2.95106 -5.04918
endloop
endfacet
facet normal -0.139737 0.449536 -0.882265
outer loop
vertex -6.92718e-08 2.58779 -5.80902
vertex -7.09656e-08 2.30902 -5.95106
vertex -1.79509 2.58779 -5.5247
endloop
endfacet
facet normal -0.111299 0.702714 -0.702713
outer loop
vertex -6.92718e-08 2.58779 -5.80902
vertex -1.79509 2.58779 -5.5247
vertex -1.72672 2.80902 -5.3143
endloop
endfacet
facet normal -0.154555 0.154555 -0.97582
outer loop
vertex -7.09656e-08 2.30902 -5.95106
vertex -7.15493e-08 2 -6
vertex -1.83898 2.30902 -5.65979
endloop
endfacet
facet normal -0.139737 0.449536 -0.882265
outer loop
vertex -7.09656e-08 2.30902 -5.95106
vertex -1.83898 2.30902 -5.65979
vertex -1.79509 2.58779 -5.5247
endloop
endfacet
facet normal -0.154555 -0.154555 -0.97582
outer loop
vertex -7.15493e-08 2 -6
vertex -7.09656e-08 1.69098 -5.95106
vertex -1.8541 2 -5.70634
endloop
endfacet
facet normal -0.154555 0.154554 -0.975821
outer loop
vertex -7.15493e-08 2 -6
vertex -1.8541 2 -5.70634
vertex -1.83898 2.30902 -5.65979
endloop
endfacet
facet normal -0.139737 -0.449535 -0.882265
outer loop
vertex -7.09656e-08 1.69098 -5.95106
vertex -6.92718e-08 1.41221 -5.80902
vertex -1.83898 1.69098 -5.65979
endloop
endfacet
facet normal -0.154555 -0.154554 -0.975821
outer loop
vertex -7.09656e-08 1.69098 -5.95106
vertex -1.83898 1.69098 -5.65979
vertex -1.8541 2 -5.70634
endloop
endfacet
facet normal -0.111299 -0.702714 -0.702713
outer loop
vertex -6.92718e-08 1.41221 -5.80902
vertex -6.66337e-08 1.19098 -5.58779
vertex -1.79509 1.41221 -5.5247
endloop
endfacet
facet normal -0.139737 -0.449536 -0.882265
outer loop
vertex -6.92718e-08 1.41221 -5.80902
vertex -1.79509 1.41221 -5.5247
vertex -1.83898 1.69098 -5.65979
endloop
endfacet
facet normal -0.0717198 -0.888712 -0.452821
outer loop
vertex -6.66337e-08 1.19098 -5.58779
vertex -6.33094e-08 1.04894 -5.30902
vertex -1.72672 1.19098 -5.3143
endloop
endfacet
facet normal -0.111299 -0.702713 -0.702714
outer loop
vertex -6.66337e-08 1.19098 -5.58779
vertex -1.72672 1.19098 -5.3143
vertex -1.79509 1.41221 -5.5247
endloop
endfacet
facet normal -0.0247692 -0.987385 -0.156386
outer loop
vertex -6.33094e-08 1.04894 -5.30902
vertex -5.96244e-08 1 -5
vertex -1.64058 1.04894 -5.04918
endloop
endfacet
facet normal -0.0717198 -0.888712 -0.452821
outer loop
vertex -6.33094e-08 1.04894 -5.30902
vertex -1.64058 1.04894 -5.04918
vertex -1.72672 1.19098 -5.3143
endloop
endfacet
facet normal 0.0247692 -0.987385 0.156386
outer loop
vertex -5.96244e-08 1 -5
vertex -5.59394e-08 1.04894 -4.69098
vertex -1.54509 1 -4.75528
endloop
endfacet
facet normal -0.0247692 -0.987385 -0.156386
outer loop
vertex -5.96244e-08 1 -5
vertex -1.54509 1 -4.75528
vertex -1.64058 1.04894 -5.04918
endloop
endfacet
facet normal 0.0717199 -0.888712 0.452821
outer loop
vertex -5.59394e-08 1.04894 -4.69098
vertex -5.26151e-08 1.19098 -4.41221
vertex -1.44959 1.04894 -4.46139
endloop
endfacet
facet normal 0.0247692 -0.987385 0.156386
outer loop
vertex -5.59394e-08 1.04894 -4.69098
vertex -1.44959 1.04894 -4.46139
vertex -1.54509 1 -4.75528
endloop
endfacet
facet normal 0.111299 -0.702713 0.702713
outer loop
vertex -5.26151e-08 1.19098 -4.41221
vertex -4.9977e-08 1.41221 -4.19098
vertex -1.36345 1.19098 -4.19627
endloop
endfacet
facet normal 0.0717199 -0.888712 0.452821
outer loop
vertex -5.26151e-08 1.19098 -4.41221
vertex -1.36345 1.19098 -4.19627
vertex -1.44959 1.04894 -4.46139
endloop
endfacet
facet normal 0.139737 -0.449536 0.882265
outer loop
vertex -4.9977e-08 1.41221 -4.19098
vertex -4.82832e-08 1.69098 -4.04894
vertex -1.29509 1.41221 -3.98586
endloop
endfacet
facet normal 0.111299 -0.702713 0.702714
outer loop
vertex -4.9977e-08 1.41221 -4.19098
vertex -1.29509 1.41221 -3.98586
vertex -1.36345 1.19098 -4.19627
endloop
endfacet
facet normal 0.154555 -0.154555 0.97582
outer loop
vertex -4.82832e-08 1.69098 -4.04894
vertex -4.76995e-08 2 -4
vertex -1.25119 1.69098 -3.85077
endloop
endfacet
facet normal 0.139737 -0.449535 0.882265
outer loop
vertex -4.82832e-08 1.69098 -4.04894
vertex -1.25119 1.69098 -3.85077
vertex -1.29509 1.41221 -3.98586
endloop
endfacet
facet normal 0.448535 0.154555 0.8803
outer loop
vertex -1.23607 2 -3.80423
vertex -1.25119 2.30902 -3.85077
vertex -2.35114 2 -3.23607
endloop
endfacet
facet normal 0.448535 -0.154555 0.8803
outer loop
vertex -1.23607 2 -3.80423
vertex -2.35114 2 -3.23607
vertex -2.37991 1.69098 -3.27566
endloop
endfacet
facet normal 0.405533 0.449535 0.795903
outer loop
vertex -1.25119 2.30902 -3.85077
vertex -1.29509 2.58779 -3.98586
vertex -2.37991 2.30902 -3.27566
endloop
endfacet
facet normal 0.448536 0.154555 0.8803
outer loop
vertex -1.25119 2.30902 -3.85077
vertex -2.37991 2.30902 -3.27566
vertex -2.35114 2 -3.23607
endloop
endfacet
facet normal 0.323002 0.702714 0.633927
outer loop
vertex -1.29509 2.58779 -3.98586
vertex -1.36345 2.80902 -4.19627
vertex -2.4634 2.58779 -3.39058
endloop
endfacet
facet normal 0.405533 0.449536 0.795903
outer loop
vertex -1.29509 2.58779 -3.98586
vertex -2.4634 2.58779 -3.39058
vertex -2.37991 2.30902 -3.27566
endloop
endfacet
facet normal 0.208139 0.888712 0.408496
outer loop
vertex -1.36345 2.80902 -4.19627
vertex -1.44959 2.95106 -4.46139
vertex -2.59343 2.80902 -3.56956
endloop
endfacet
facet normal 0.323002 0.702714 0.633927
outer loop
vertex -1.36345 2.80902 -4.19627
vertex -2.59343 2.80902 -3.56956
vertex -2.4634 2.58779 -3.39058
endloop
endfacet
facet normal 0.0718829 0.987385 0.141078
outer loop
vertex -1.44959 2.95106 -4.46139
vertex -1.54509 3 -4.75528
vertex -2.75729 2.95106 -3.79509
endloop
endfacet
facet normal 0.208139 0.888712 0.408496
outer loop
vertex -1.44959 2.95106 -4.46139
vertex -2.75729 2.95106 -3.79509
vertex -2.59343 2.80902 -3.56956
endloop
endfacet
facet normal -0.071883 0.987385 -0.141078
outer loop
vertex -1.54509 3 -4.75528
vertex -1.64058 2.95106 -5.04918
vertex -2.93893 3 -4.04509
endloop
endfacet
facet normal 0.071883 0.987385 0.141078
outer loop
vertex -1.54509 3 -4.75528
vertex -2.93893 3 -4.04509
vertex -2.75729 2.95106 -3.79509
endloop
endfacet
facet normal -0.208139 0.888712 -0.408496
outer loop
vertex -1.64058 2.95106 -5.04918
vertex -1.72672 2.80902 -5.3143
vertex -3.12056 2.95106 -4.29509
endloop
endfacet
facet normal -0.0718829 0.987385 -0.141078
outer loop
vertex -1.64058 2.95106 -5.04918
vertex -3.12056 2.95106 -4.29509
vertex -2.93893 3 -4.04509
endloop
endfacet
facet normal -0.323002 0.702714 -0.633927
outer loop
vertex -1.72672 2.80902 -5.3143
vertex -1.79509 2.58779 -5.5247
vertex -3.28442 2.80902 -4.52061
endloop
endfacet
facet normal -0.208139 0.888712 -0.408496
outer loop
vertex -1.72672 2.80902 -5.3143
vertex -3.28442 2.80902 -4.52061
vertex -3.12056 2.95106 -4.29509
endloop
endfacet
facet normal -0.405533 0.449536 -0.795903
outer loop
vertex -1.79509 2.58779 -5.5247
vertex -1.83898 2.30902 -5.65979
vertex -3.41445 2.58779 -4.69959
endloop
endfacet
facet normal -0.323002 0.702714 -0.633927
outer loop
vertex -1.79509 2.58779 -5.5247
vertex -3.41445 2.58779 -4.69959
vertex -3.28442 2.80902 -4.52061
endloop
endfacet
facet normal -0.448535 0.154554 -0.8803
outer loop
vertex -1.83898 2.30902 -5.65979
vertex -1.8541 2 -5.70634
vertex -3.49794 2.30902 -4.81451
endloop
endfacet
facet normal -0.405533 0.449535 -0.795903
outer loop
vertex -1.83898 2.30902 -5.65979
vertex -3.49794 2.30902 -4.81451
vertex -3.41445 2.58779 -4.69959
endloop
endfacet
facet normal -0.448535 -0.154555 -0.8803
outer loop
vertex -1.8541 2 -5.70634
vertex -1.83898 1.69098 -5.65979
vertex -3.52671 2 -4.8541
endloop
endfacet
facet normal -0.448535 0.154555 -0.8803
outer loop
vertex -1.8541 2 -5.70634
vertex -3.52671 2 -4.8541
vertex -3.49794 2.30902 -4.81451
endloop
endfacet
facet normal -0.405533 -0.449536 -0.795903
outer loop
vertex -1.83898 1.69098 -5.65979
vertex -1.79509 1.41221 -5.5247
vertex -3.49794 1.69098 -4.81451
endloop
endfacet
facet normal -0.448536 -0.154555 -0.8803
outer loop
vertex -1.83898 1.69098 -5.65979
vertex -3.49794 1.69098 -4.81451
vertex -3.52671 2 -4.8541
endloop
endfacet
facet normal -0.323002 -0.702713 -0.633927
outer loop
vertex -1.79509 1.41221 -5.5247
vertex -1.72672 1.19098 -5.3143
vertex -3.41445 1.41221 -4.69959
endloop
endfacet
facet normal -0.405533 -0.449535 -0.795903
outer loop
vertex -1.79509 1.41221 -5.5247
vertex -3.41445 1.41221 -4.69959
vertex -3.49794 1.69098 -4.81451
endloop
endfacet
facet normal -0.208139 -0.888712 -0.408496
outer loop
vertex -1.72672 1.19098 -5.3143
vertex -1.64058 1.04894 -5.04918
vertex -3.28442 1.19098 -4.52061
endloop
endfacet
facet normal -0.323002 -0.702714 -0.633927
outer loop
vertex -1.72672 1.19098 -5.3143
vertex -3.28442 1.19098 -4.52061
vertex -3.41445 1.41221 -4.69959
endloop
endfacet
facet normal -0.071883 -0.987385 -0.141078
outer loop
vertex -1.64058 1.04894 -5.04918
vertex -1.54509 1 -4.75528
vertex -3.12056 1.04894 -4.29509
endloop
endfacet
facet normal -0.208139 -0.888712 -0.408496
outer loop
vertex -1.64058 1.04894 -5.04918
vertex -3.12056 1.04894 -4.29509
vertex -3.28442 1.19098 -4.52061
endloop
endfacet
facet normal 0.071883 -0.987385 0.141078
outer loop
vertex -1.54509 1 -4.75528
vertex -1.44959 1.04894 -4.46139
vertex -2.93893 1 -4.04509
endloop
endfacet
facet normal -0.0718829 -0.987385 -0.141078
outer loop
vertex -1.54509 1 -4.75528
vertex -2.93893 1 -4.04509
vertex -3.12056 1.04894 -4.29509
endloop
endfacet
facet normal 0.208139 -0.888712 0.408496
outer loop
vertex -1.44959 1.04894 -4.46139
vertex -1.36345 1.19098 -4.19627
vertex -2.75729 1.04894 -3.79509
endloop
endfacet
facet normal 0.071883 -0.987385 0.141078
outer loop
vertex -1.44959 1.04894 -4.46139
vertex -2.75729 1.04894 -3.79509
vertex -2.93893 1 -4.04509
endloop
endfacet
facet normal 0.323002 -0.702713 0.633927
outer loop
vertex -1.36345 1.19098 -4.19627
vertex -1.29509 1.41221 -3.98586
vertex -2.59343 1.19098 -3.56956
endloop
endfacet
facet normal 0.208139 -0.888712 0.408496
outer loop
vertex -1.36345 1.19098 -4.19627
vertex -2.59343 1.19098 -3.56956
vertex -2.75729 1.04894 -3.79509
endloop
endfacet
facet normal 0.405533 -0.449535 0.795903
outer loop
vertex -1.29509 1.41221 -3.98586
vertex -1.25119 1.69098 -3.85077
vertex -2.4634 1.41221 -3.39058
endloop
endfacet
facet normal 0.323002 -0.702713 0.633927
outer loop
vertex -1.29509 1.41221 -3.98586
vertex -2.4634 1.41221 -3.39058
vertex -2.59343 1.19098 -3.56956
endloop
endfacet
facet normal 0.448536 -0.154555 0.8803
outer loop
vertex -1.25119 1.69098 -3.85077
vertex -1.23607 2 -3.80423
vertex -2.37991 1.69098 -3.27566
endloop
endfacet
facet normal 0.405533 -0.449536 0.795903
outer loop
vertex -1.25119 1.69098 -3.85077
vertex -2.37991 1.69098 -3.27566
vertex -2.4634 1.41221 -3.39058
endloop
endfacet
facet normal 0.69861 0.154555 0.69861
outer loop
vertex -2.35114 2 -3.23607
vertex -2.37991 2.30902 -3.27566
vertex -3.23607 2 -2.35114
endloop
endfacet
facet normal 0.69861 -0.154555 0.69861
outer loop
vertex -2.35114 2 -3.23607
vertex -3.23607 2 -2.35114
vertex -3.27566 1.69098 -2.37991
endloop
endfacet
facet normal 0.631632 0.449535 0.631632
outer loop
vertex -2.37991 2.30902 -3.27566
vertex -2.4634 2.58779 -3.39058
vertex -3.27566 2.30902 -2.37991
endloop
endfacet
facet normal 0.69861 0.154555 0.69861
outer loop
vertex -2.37991 2.30902 -3.27566
vertex -3.27566 2.30902 -2.37991
vertex -3.23607 2 -2.35114
endloop
endfacet
facet normal 0.503087 0.702714 0.503087
outer loop
vertex -2.4634 2.58779 -3.39058
vertex -2.59343 2.80902 -3.56956
vertex -3.39058 2.58779 -2.4634
endloop
endfacet
facet normal 0.631632 0.449536 0.631632
outer loop
vertex -2.4634 2.58779 -3.39058
vertex -3.39058 2.58779 -2.4634
vertex -3.27566 2.30902 -2.37991
endloop
endfacet
facet normal 0.324184 0.888712 0.324184
outer loop
vertex -2.59343 2.80902 -3.56956
vertex -2.75729 2.95106 -3.79509
vertex -3.56956 2.80902 -2.59344
endloop
endfacet
facet normal 0.503087 0.702714 0.503087
outer loop
vertex -2.59343 2.80902 -3.56956
vertex -3.56956 2.80902 -2.59344
vertex -3.39058 2.58779 -2.4634
endloop
endfacet
facet normal 0.11196 0.987385 0.11196
outer loop
vertex -2.75729 2.95106 -3.79509
vertex -2.93893 3 -4.04509
vertex -3.79508 2.95106 -2.75729
endloop
endfacet
facet normal 0.324185 0.888712 0.324185
outer loop
vertex -2.75729 2.95106 -3.79509
vertex -3.79508 2.95106 -2.75729
vertex -3.56956 2.80902 -2.59344
endloop
endfacet
facet normal -0.11196 0.987385 -0.11196
outer loop
vertex -2.93893 3 -4.04509
vertex -3.12056 2.95106 -4.29509
vertex -4.04508 3 -2.93893
endloop
endfacet
facet normal 0.11196 0.987385 0.11196
outer loop
vertex -2.93893 3 -4.04509
vertex -4.04508 3 -2.93893
vertex -3.79508 2.95106 -2.75729
endloop
endfacet
facet normal -0.324185 0.888712 -0.324185
outer loop
vertex -3.12056 2.95106 -4.29509
vertex -3.28442 2.80902 -4.52061
vertex -4.29508 2.95106 -3.12056
endloop
endfacet
facet normal -0.11196 0.987385 -0.11196
outer loop
vertex -3.12056 2.95106 -4.29509
vertex -4.29508 2.95106 -3.12056
vertex -4.04508 3 -2.93893
endloop
endfacet
facet normal -0.503087 0.702714 -0.503087
outer loop
vertex -3.28442 2.80902 -4.52061
vertex -3.41445 2.58779 -4.69959
vertex -4.52061 2.80902 -3.28442
endloop
endfacet
facet normal -0.324185 0.888712 -0.324185
outer loop
vertex -3.28442 2.80902 -4.52061
vertex -4.52061 2.80902 -3.28442
vertex -4.29508 2.95106 -3.12056
endloop
endfacet
facet normal -0.631632 0.449536 -0.631632
outer loop
vertex -3.41445 2.58779 -4.69959
vertex -3.49794 2.30902 -4.81451
vertex -4.69959 2.58779 -3.41445
endloop
endfacet
facet normal -0.503087 0.702714 -0.503087
outer loop
vertex -3.41445 2.58779 -4.69959
vertex -4.69959 2.58779 -3.41445
vertex -4.52061 2.80902 -3.28442
endloop
endfacet
facet normal -0.69861 0.154555 -0.69861
outer loop
vertex -3.49794 2.30902 -4.81451
vertex -3.52671 2 -4.8541
vertex -4.81451 2.30902 -3.49794
endloop
endfacet
facet normal -0.631632 0.449535 -0.631632
outer loop
vertex -3.49794 2.30902 -4.81451
vertex -4.81451 2.30902 -3.49794
vertex -4.69959 2.58779 -3.41445
endloop
endfacet
facet normal -0.69861 -0.154555 -0.69861
outer loop
vertex -3.52671 2 -4.8541
vertex -3.49794 1.69098 -4.81451
vertex -4.8541 2 -3.52671
endloop
endfacet
facet normal -0.69861 0.154555 -0.69861
outer loop
vertex -3.52671 2 -4.8541
vertex -4.8541 2 -3.52671
vertex -4.81451 2.30902 -3.49794
endloop
endfacet
facet normal -0.631632 -0.449535 -0.631632
outer loop
vertex -3.49794 1.69098 -4.81451
vertex -3.41445 1.41221 -4.69959
vertex -4.81451 1.69098 -3.49794
endloop
endfacet
facet normal -0.69861 -0.154555 -0.69861
outer loop
vertex -3.49794 1.69098 -4.81451
vertex -4.81451 1.69098 -3.49794
vertex -4.8541 2 -3.52671
endloop
endfacet
facet normal -0.503087 -0.702714 -0.503087
outer loop
vertex -3.41445 1.41221 -4.69959
vertex -3.28442 1.19098 -4.52061
vertex -4.69959 1.41221 -3.41445
endloop
endfacet
facet normal -0.631632 -0.449535 -0.631632
outer loop
vertex -3.41445 1.41221 -4.69959
vertex -4.69959 1.41221 -3.41445
vertex -4.81451 1.69098 -3.49794
endloop
endfacet
facet normal -0.324184 -0.888712 -0.324184
outer loop
vertex -3.28442 1.19098 -4.52061
vertex -3.12056 1.04894 -4.29509
vertex -4.52061 1.19098 -3.28442
endloop
endfacet
facet normal -0.503087 -0.702714 -0.503087
outer loop
vertex -3.28442 1.19098 -4.52061
vertex -4.52061 1.19098 -3.28442
vertex -4.69959 1.41221 -3.41445
endloop
endfacet
facet normal -0.11196 -0.987385 -0.11196
outer loop
vertex -3.12056 1.04894 -4.29509
vertex -2.93893 1 -4.04509
vertex -4.29508 1.04894 -3.12056
endloop
endfacet
facet normal -0.324184 -0.888712 -0.324184
outer loop
vertex -3.12056 1.04894 -4.29509
vertex -4.29508 1.04894 -3.12056
vertex -4.52061 1.19098 -3.28442
endloop
endfacet
facet normal 0.11196 -0.987385 0.11196
outer loop
vertex -2.93893 1 -4.04509
vertex -2.75729 1.04894 -3.79509
vertex -4.04508 1 -2.93893
endloop
endfacet
facet normal -0.11196 -0.987385 -0.11196
outer loop
vertex -2.93893 1 -4.04509
vertex -4.04508 1 -2.93893
vertex -4.29508 1.04894 -3.12056
endloop
endfacet
facet normal 0.324184 -0.888712 0.324184
outer loop
vertex -2.75729 1.04894 -3.79509
vertex -2.59343 1.19098 -3.56956
vertex -3.79508 1.04894 -2.75729
endloop
endfacet
facet normal 0.11196 -0.987385 0.11196
outer loop
vertex -2.75729 1.04894 -3.79509
vertex -3.79508 1.04894 -2.75729
vertex -4.04508 1 -2.93893
endloop
endfacet
facet normal 0.503087 -0.702713 0.503087
outer loop
vertex -2.59343 1.19098 -3.56956
vertex -2.4634 1.41221 -3.39058
vertex -3.56956 1.19098 -2.59344
endloop
endfacet
facet normal 0.324184 -0.888712 0.324184
outer loop
vertex -2.59343 1.19098 -3.56956
vertex -3.56956 1.19098 -2.59344
vertex -3.79508 1.04894 -2.75729
endloop
endfacet
facet normal 0.631632 -0.449535 0.631632
outer loop
vertex -2.4634 1.41221 -3.39058
vertex -2.37991 1.69098 -3.27566
vertex -3.39058 1.41221 -2.4634
endloop
endfacet
facet normal 0.503087 -0.702713 0.503088
outer loop
vertex -2.4634 1.41221 -3.39058
vertex -3.39058 1.41221 -2.4634
vertex -3.56956 1.19098 -2.59344
endloop
endfacet
facet normal 0.69861 -0.154555 0.69861
outer loop
vertex -2.37991 1.69098 -3.27566
vertex -2.35114 2 -3.23607
vertex -3.27566 1.69098 -2.37991
endloop
endfacet
facet normal 0.631632 -0.449536 0.631632
outer loop
vertex -2.37991 1.69098 -3.27566
vertex -3.27566 1.69098 -2.37991
vertex -3.39058 1.41221 -2.4634
endloop
endfacet
facet normal 0.8803 0.154555 0.448536
outer loop
vertex -3.23607 2 -2.35114
vertex -3.27566 2.30902 -2.37991
vertex -3.80423 2 -1.23607
endloop
endfacet
facet normal 0.8803 -0.154555 0.448535
outer loop
vertex -3.23607 2 -2.35114
vertex -3.80423 2 -1.23607
vertex -3.85077 1.69098 -1.25119
endloop
endfacet
facet normal 0.795902 0.449536 0.405533
outer loop
vertex -3.27566 2.30902 -2.37991
vertex -3.39058 2.58779 -2.4634
vertex -3.85077 2.30902 -1.25119
endloop
endfacet
facet normal 0.8803 0.154555 0.448536
outer loop
vertex -3.27566 2.30902 -2.37991
vertex -3.85077 2.30902 -1.25119
vertex -3.80423 2 -1.23607
endloop
endfacet
facet normal 0.633927 0.702714 0.323002
outer loop
vertex -3.39058 2.58779 -2.4634
vertex -3.56956 2.80902 -2.59344
vertex -3.98586 2.58779 -1.29508
endloop
endfacet
facet normal 0.795903 0.449535 0.405533
outer loop
vertex -3.39058 2.58779 -2.4634
vertex -3.98586 2.58779 -1.29508
vertex -3.85077 2.30902 -1.25119
endloop
endfacet
facet normal 0.408496 0.888712 0.208139
outer loop
vertex -3.56956 2.80902 -2.59344
vertex -3.79508 2.95106 -2.75729
vertex -4.19627 2.80902 -1.36345
endloop
endfacet
facet normal 0.633927 0.702714 0.323002
outer loop
vertex -3.56956 2.80902 -2.59344
vertex -4.19627 2.80902 -1.36345
vertex -3.98586 2.58779 -1.29508
endloop
endfacet
facet normal 0.141078 0.987385 0.0718829
outer loop
vertex -3.79508 2.95106 -2.75729
vertex -4.04508 3 -2.93893
vertex -4.46139 2.95106 -1.44959
endloop
endfacet
facet normal 0.408496 0.888712 0.208139
outer loop
vertex -3.79508 2.95106 -2.75729
vertex -4.46139 2.95106 -1.44959
vertex -4.19627 2.80902 -1.36345
endloop
endfacet
facet normal -0.141078 0.987385 -0.071883
outer loop
vertex -4.04508 3 -2.93893
vertex -4.29508 2.95106 -3.12056
vertex -4.75528 3 -1.54508
endloop
endfacet
facet normal 0.141078 0.987385 0.071883
outer loop
vertex -4.04508 3 -2.93893
vertex -4.75528 3 -1.54508
vertex -4.46139 2.95106 -1.44959
endloop
endfacet
facet normal -0.408497 0.888712 -0.20814
outer loop
vertex -4.29508 2.95106 -3.12056
vertex -4.52061 2.80902 -3.28442
vertex -5.04918 2.95106 -1.64058
endloop
endfacet
facet normal -0.141078 0.987385 -0.071883
outer loop
vertex -4.29508 2.95106 -3.12056
vertex -5.04918 2.95106 -1.64058
vertex -4.75528 3 -1.54508
endloop
endfacet
facet normal -0.633926 0.702715 -0.323002
outer loop
vertex -4.52061 2.80902 -3.28442
vertex -4.69959 2.58779 -3.41445
vertex -5.3143 2.80902 -1.72672
endloop
endfacet
facet normal -0.408497 0.888712 -0.208139
outer loop
vertex -4.52061 2.80902 -3.28442
vertex -5.3143 2.80902 -1.72672
vertex -5.04918 2.95106 -1.64058
endloop
endfacet
facet normal -0.795903 0.449535 -0.405533
outer loop
vertex -4.69959 2.58779 -3.41445
vertex -4.81451 2.30902 -3.49794
vertex -5.5247 2.58779 -1.79508
endloop
endfacet
facet normal -0.633926 0.702714 -0.323002
outer loop
vertex -4.69959 2.58779 -3.41445
vertex -5.5247 2.58779 -1.79508
vertex -5.3143 2.80902 -1.72672
endloop
endfacet
facet normal -0.8803 0.154555 -0.448535
outer loop
vertex -4.81451 2.30902 -3.49794
vertex -4.8541 2 -3.52671
vertex -5.65979 2.30902 -1.83898
endloop
endfacet
facet normal -0.795903 0.449535 -0.405533
outer loop
vertex -4.81451 2.30902 -3.49794
vertex -5.65979 2.30902 -1.83898
vertex -5.5247 2.58779 -1.79508
endloop
endfacet
facet normal -0.8803 -0.154555 -0.448536
outer loop
vertex -4.8541 2 -3.52671
vertex -4.81451 1.69098 -3.49794
vertex -5.70634 2 -1.8541
endloop
endfacet
facet normal -0.8803 0.154556 -0.448536
outer loop
vertex -4.8541 2 -3.52671
vertex -5.70634 2 -1.8541
vertex -5.65979 2.30902 -1.83898
endloop
endfacet
facet normal -0.795903 -0.449535 -0.405533
outer loop
vertex -4.81451 1.69098 -3.49794
vertex -4.69959 1.41221 -3.41445
vertex -5.65979 1.69098 -1.83898
endloop
endfacet
facet normal -0.8803 -0.154556 -0.448535
outer loop
vertex -4.81451 1.69098 -3.49794
vertex -5.65979 1.69098 -1.83898
vertex -5.70634 2 -1.8541
endloop
endfacet
facet normal -0.633926 -0.702714 -0.323002
outer loop
vertex -4.69959 1.41221 -3.41445
vertex -4.52061 1.19098 -3.28442
vertex -5.5247 1.41221 -1.79508
endloop
endfacet
facet normal -0.795903 -0.449535 -0.405533
outer loop
vertex -4.69959 1.41221 -3.41445
vertex -5.5247 1.41221 -1.79508
vertex -5.65979 1.69098 -1.83898
endloop
endfacet
facet normal -0.408496 -0.888712 -0.208139
outer loop
vertex -4.52061 1.19098 -3.28442
vertex -4.29508 1.04894 -3.12056
vertex -5.3143 1.19098 -1.72672
endloop
endfacet
facet normal -0.633926 -0.702714 -0.323002
outer loop
vertex -4.52061 1.19098 -3.28442
vertex -5.3143 1.19098 -1.72672
vertex -5.5247 1.41221 -1.79508
endloop
endfacet
facet normal -0.141078 -0.987385 -0.071883
outer loop
vertex -4.29508 1.04894 -3.12056
vertex -4.04508 1 -2.93893
vertex -5.04918 1.04894 -1.64058
endloop
endfacet
facet normal -0.408496 -0.888712 -0.208139
outer loop
vertex -4.29508 1.04894 -3.12056
vertex -5.04918 1.04894 -1.64058
vertex -5.3143 1.19098 -1.72672
endloop
endfacet
facet normal 0.141078 -0.987385 0.0718829
outer loop
vertex -4.04508 1 -2.93893
vertex -3.79508 1.04894 -2.75729
vertex -4.75528 1 -1.54508
endloop
endfacet
facet normal -0.141078 -0.987385 -0.071883
outer loop
vertex -4.04508 1 -2.93893
vertex -4.75528 1 -1.54508
vertex -5.04918 1.04894 -1.64058
endloop
endfacet
facet normal 0.408496 -0.888712 0.208139
outer loop
vertex -3.79508 1.04894 -2.75729
vertex -3.56956 1.19098 -2.59344
vertex -4.46139 1.04894 -1.44959
endloop
endfacet
facet normal 0.141078 -0.987385 0.071883
outer loop
vertex -3.79508 1.04894 -2.75729
vertex -4.46139 1.04894 -1.44959
vertex -4.75528 1 -1.54508
endloop
endfacet
facet normal 0.633927 -0.702713 0.323002
outer loop
vertex -3.56956 1.19098 -2.59344
vertex -3.39058 1.41221 -2.4634
vertex -4.19627 1.19098 -1.36345
endloop
endfacet
facet normal 0.408496 -0.888712 0.208139
outer loop
vertex -3.56956 1.19098 -2.59344
vertex -4.19627 1.19098 -1.36345
vertex -4.46139 1.04894 -1.44959
endloop
endfacet
facet normal 0.795903 -0.449536 0.405533
outer loop
vertex -3.39058 1.41221 -2.4634
vertex -3.27566 1.69098 -2.37991
vertex -3.98586 1.41221 -1.29508
endloop
endfacet
facet normal 0.633927 -0.702714 0.323002
outer loop
vertex -3.39058 1.41221 -2.4634
vertex -3.98586 1.41221 -1.29508
vertex -4.19627 1.19098 -1.36345
endloop
endfacet
facet normal 0.8803 -0.154555 0.448536
outer loop
vertex -3.27566 1.69098 -2.37991
vertex -3.23607 2 -2.35114
vertex -3.85077 1.69098 -1.25119
endloop
endfacet
facet normal 0.795903 -0.449535 0.405533
outer loop
vertex -3.27566 1.69098 -2.37991
vertex -3.85077 1.69098 -1.25119
vertex -3.98586 1.41221 -1.29508
endloop
endfacet
facet normal 0.97582 0.154555 0.154555
outer loop
vertex -3.80423 2 -1.23607
vertex -3.85077 2.30902 -1.25119
vertex -4 2 6.99382e-07
endloop
endfacet
facet normal 0.975821 -0.154555 0.154555
outer loop
vertex -3.80423 2 -1.23607
vertex -4 2 6.99382e-07
vertex -4.04894 1.69098 7.0794e-07
endloop
endfacet
facet normal 0.882265 0.449535 0.139737
outer loop
vertex -3.85077 2.30902 -1.25119
vertex -3.98586 2.58779 -1.29508
vertex -4.04894 2.30902 7.0794e-07
endloop
endfacet
facet normal 0.97582 0.154555 0.154555
outer loop
vertex -3.85077 2.30902 -1.25119
vertex -4.04894 2.30902 7.0794e-07
vertex -4 2 6.99382e-07
endloop
endfacet
facet normal 0.702713 0.702714 0.111299
outer loop
vertex -3.98586 2.58779 -1.29508
vertex -4.19627 2.80902 -1.36345
vertex -4.19098 2.58779 7.32775e-07
endloop
endfacet
facet normal 0.882265 0.449536 0.139737
outer loop
vertex -3.98586 2.58779 -1.29508
vertex -4.19098 2.58779 7.32775e-07
vertex -4.04894 2.30902 7.0794e-07
endloop
endfacet
facet normal 0.452822 0.888712 0.0717198
outer loop
vertex -4.19627 2.80902 -1.36345
vertex -4.46139 2.95106 -1.44959
vertex -4.41221 2.80902 7.71456e-07
endloop
endfacet
facet normal 0.702713 0.702714 0.111299
outer loop
vertex -4.19627 2.80902 -1.36345
vertex -4.41221 2.80902 7.71456e-07
vertex -4.19098 2.58779 7.32775e-07
endloop
endfacet
facet normal 0.156386 0.987385 0.0247691
outer loop
vertex -4.46139 2.95106 -1.44959
vertex -4.75528 3 -1.54508
vertex -4.69098 2.95106 8.20197e-07
endloop
endfacet
facet normal 0.452822 0.888712 0.0717198
outer loop
vertex -4.46139 2.95106 -1.44959
vertex -4.69098 2.95106 8.20197e-07
vertex -4.41221 2.80902 7.71456e-07
endloop
endfacet
facet normal -0.156386 0.987385 -0.0247691
outer loop
vertex -4.75528 3 -1.54508
vertex -5.04918 2.95106 -1.64058
vertex -5 3 8.74228e-07
endloop
endfacet
facet normal 0.156386 0.987385 0.0247691
outer loop
vertex -4.75528 3 -1.54508
vertex -5 3 8.74228e-07
vertex -4.69098 2.95106 8.20197e-07
endloop
endfacet
facet normal -0.452822 0.888712 -0.0717199
outer loop
vertex -5.04918 2.95106 -1.64058
vertex -5.3143 2.80902 -1.72672
vertex -5.30902 2.95106 9.28258e-07
endloop
endfacet
facet normal -0.156387 0.987385 -0.0247691
outer loop
vertex -5.04918 2.95106 -1.64058
vertex -5.30902 2.95106 9.28258e-07
vertex -5 3 8.74228e-07
endloop
endfacet
facet normal -0.702713 0.702714 -0.111299
outer loop
vertex -5.3143 2.80902 -1.72672
vertex -5.5247 2.58779 -1.79508
vertex -5.58779 2.80902 9.76999e-07
endloop
endfacet
facet normal -0.452822 0.888712 -0.0717199
outer loop
vertex -5.3143 2.80902 -1.72672
vertex -5.58779 2.80902 9.76999e-07
vertex -5.30902 2.95106 9.28258e-07
endloop
endfacet
facet normal -0.882265 0.449535 -0.139737
outer loop
vertex -5.5247 2.58779 -1.79508
vertex -5.65979 2.30902 -1.83898
vertex -5.80902 2.58779 1.01568e-06
endloop
endfacet
facet normal -0.702713 0.702714 -0.111299
outer loop
vertex -5.5247 2.58779 -1.79508
vertex -5.80902 2.58779 1.01568e-06
vertex -5.58779 2.80902 9.76999e-07
endloop
endfacet
facet normal -0.97582 0.154556 -0.154555
outer loop
vertex -5.65979 2.30902 -1.83898
vertex -5.70634 2 -1.8541
vertex -5.95106 2.30902 1.04052e-06
endloop
endfacet
facet normal -0.882265 0.449536 -0.139737
outer loop
vertex -5.65979 2.30902 -1.83898
vertex -5.95106 2.30902 1.04052e-06
vertex -5.80902 2.58779 1.01568e-06
endloop
endfacet
facet normal -0.97582 -0.154556 -0.154555
outer loop
vertex -5.70634 2 -1.8541
vertex -5.65979 1.69098 -1.83898
vertex -6 2 1.04907e-06
endloop
endfacet
facet normal -0.975821 0.154555 -0.154555
outer loop
vertex -5.70634 2 -1.8541
vertex -6 2 1.04907e-06
vertex -5.95106 2.30902 1.04052e-06
endloop
endfacet
facet normal -0.882265 -0.449534 -0.139737
outer loop
vertex -5.65979 1.69098 -1.83898
vertex -5.5247 1.41221 -1.79508
vertex -5.95106 1.69098 1.04052e-06
endloop
endfacet
facet normal -0.97582 -0.154555 -0.154555
outer loop
vertex -5.65979 1.69098 -1.83898
vertex -5.95106 1.69098 1.04052e-06
vertex -6 2 1.04907e-06
endloop
endfacet
facet normal -0.702713 -0.702714 -0.111299
outer loop
vertex -5.5247 1.41221 -1.79508
vertex -5.3143 1.19098 -1.72672
vertex -5.80902 1.41221 1.01568e-06
endloop
endfacet
facet normal -0.882265 -0.449535 -0.139737
outer loop
vertex -5.5247 1.41221 -1.79508
vertex -5.80902 1.41221 1.01568e-06
vertex -5.95106 1.69098 1.04052e-06
endloop
endfacet
facet normal -0.452822 -0.888712 -0.0717198
outer loop
vertex -5.3143 1.19098 -1.72672
vertex -5.04918 1.04894 -1.64058
vertex -5.58779 1.19098 9.76999e-07
endloop
endfacet
facet normal -0.702713 -0.702714 -0.111299
outer loop
vertex -5.3143 1.19098 -1.72672
vertex -5.58779 1.19098 9.76999e-07
vertex -5.80902 1.41221 1.01568e-06
endloop
endfacet
facet normal -0.156386 -0.987385 -0.0247691
outer loop
vertex -5.04918 1.04894 -1.64058
vertex -4.75528 1 -1.54508
vertex -5.30902 1.04894 9.28258e-07
endloop
endfacet
facet normal -0.452821 -0.888712 -0.0717197
outer loop
vertex -5.04918 1.04894 -1.64058
vertex -5.30902 1.04894 9.28258e-07
vertex -5.58779 1.19098 9.76999e-07
endloop
endfacet
facet normal 0.156386 -0.987385 0.0247691
outer loop
vertex -4.75528 1 -1.54508
vertex -4.46139 1.04894 -1.44959
vertex -5 1 8.74228e-07
endloop
endfacet
facet normal -0.156387 -0.987385 -0.0247691
outer loop
vertex -4.75528 1 -1.54508
vertex -5 1 8.74228e-07
vertex -5.30902 1.04894 9.28258e-07
endloop
endfacet
facet normal 0.452821 -0.888712 0.0717197
outer loop
vertex -4.46139 1.04894 -1.44959
vertex -4.19627 1.19098 -1.36345
vertex -4.69098 1.04894 8.20197e-07
endloop
endfacet
facet normal 0.156386 -0.987385 0.0247691
outer loop
vertex -4.46139 1.04894 -1.44959
vertex -4.69098 1.04894 8.20197e-07
vertex -5 1 8.74228e-07
endloop
endfacet
facet normal 0.702713 -0.702714 0.111299
outer loop
vertex -4.19627 1.19098 -1.36345
vertex -3.98586 1.41221 -1.29508
vertex -4.41221 1.19098 7.71456e-07
endloop
endfacet
facet normal 0.452821 -0.888712 0.0717198
outer loop
vertex -4.19627 1.19098 -1.36345
vertex -4.41221 1.19098 7.71456e-07
vertex -4.69098 1.04894 8.20197e-07
endloop
endfacet
facet normal 0.882265 -0.449535 0.139737
outer loop
vertex -3.98586 1.41221 -1.29508
vertex -3.85077 1.69098 -1.25119
vertex -4.19098 1.41221 7.32775e-07
endloop
endfacet
facet normal 0.702714 -0.702714 0.111299
outer loop
vertex -3.98586 1.41221 -1.29508
vertex -4.19098 1.41221 7.32775e-07
vertex -4.41221 1.19098 7.71456e-07
endloop
endfacet
facet normal 0.97582 -0.154555 0.154555
outer loop
vertex -3.85077 1.69098 -1.25119
vertex -3.80423 2 -1.23607
vertex -4.04894 1.69098 7.0794e-07
endloop
endfacet
facet normal 0.882265 -0.449536 0.139737
outer loop
vertex -3.85077 1.69098 -1.25119
vertex -4.04894 1.69098 7.0794e-07
vertex -4.19098 1.41221 7.32775e-07
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex -4 2 6.99382e-07
vertex -4 2 0
vertex -4.04894 1.69098 0
endloop
endfacet
facet normal -0.987688 -0.156435 -0
outer loop
vertex -4 2 6.99382e-07
vertex -4.04894 2.30902 7.0794e-07
vertex -4 2 0
endloop
endfacet
facet normal -0.987688 -0.156435 -0
outer loop
vertex -4.04894 2.30902 7.0794e-07
vertex -4.04894 2.30902 0
vertex -4 2 0
endloop
endfacet
facet normal -0.891007 -0.45399 -0
outer loop
vertex -4.04894 2.30902 7.0794e-07
vertex -4.19098 2.58779 7.32775e-07
vertex -4.04894 2.30902 0
endloop
endfacet
facet normal -0.891007 -0.45399 -0
outer loop
vertex -4.19098 2.58779 7.32775e-07
vertex -4.19098 2.58779 0
vertex -4.04894 2.30902 0
endloop
endfacet
facet normal -0.707106 -0.707107 -0
outer loop
vertex -4.19098 2.58779 7.32775e-07
vertex -4.41221 2.80902 7.71456e-07
vertex -4.19098 2.58779 0
endloop
endfacet
facet normal -0.707106 -0.707107 -0
outer loop
vertex -4.41221 2.80902 7.71456e-07
vertex -4.41221 2.80902 0
vertex -4.19098 2.58779 0
endloop
endfacet
facet normal -0.453991 -0.891006 -0
outer loop
vertex -4.41221 2.80902 7.71456e-07
vertex -4.69098 2.95106 8.20197e-07
vertex -4.41221 2.80902 0
endloop
endfacet
facet normal -0.453991 -0.891006 -0
outer loop
vertex -4.69098 2.95106 8.20197e-07
vertex -4.69098 2.95106 0
vertex -4.41221 2.80902 0
endloop
endfacet
facet normal -0.156434 -0.987688 -0
outer loop
vertex -4.69098 2.95106 8.20197e-07
vertex -5 3 8.74228e-07
vertex -4.69098 2.95106 0
endloop
endfacet
facet normal -0.156434 -0.987688 -0
outer loop
vertex -5 3 8.74228e-07
vertex -5 3 0
vertex -4.69098 2.95106 0
endloop
endfacet
facet normal 0.156434 -0.987688 0
outer loop
vertex -5 3 8.74228e-07
vertex -5.30902 2.95106 9.28258e-07
vertex -5 3 0
endloop
endfacet
facet normal 0.156434 -0.987688 0
outer loop
vertex -5.30902 2.95106 9.28258e-07
vertex -5.30902 2.95106 0
vertex -5 3 0
endloop
endfacet
facet normal 0.453991 -0.891006 0
outer loop
vertex -5.30902 2.95106 9.28258e-07
vertex -5.58779 2.80902 9.76999e-07
vertex -5.30902 2.95106 0
endloop
endfacet
facet normal 0.453991 -0.891006 0
outer loop
vertex -5.58779 2.80902 9.76999e-07
vertex -5.58779 2.80902 0
vertex -5.30902 2.95106 0
endloop
endfacet
facet normal 0.707106 -0.707107 0
outer loop
vertex -5.58779 2.80902 9.76999e-07
vertex -5.80902 2.58779 1.01568e-06
vertex -5.58779 2.80902 0
endloop
endfacet
facet normal 0.707106 -0.707107 0
outer loop
vertex -5.80902 2.58779 1.01568e-06
vertex -5.80902 2.58779 0
vertex -5.58779 2.80902 0
endloop
endfacet
facet normal 0.891007 -0.45399 0
outer loop
vertex -5.80902 2.58779 1.01568e-06
vertex -5.95106 2.30902 1.04052e-06
vertex -5.80902 2.58779 0
endloop
endfacet
facet normal 0.891007 -0.45399 0
outer loop
vertex -5.95106 2.30902 1.04052e-06
vertex -5.95106 2.30902 0
vertex -5.80902 2.58779 0
endloop
endfacet
facet normal 0.987688 -0.156435 0
outer loop
vertex -5.95106 2.30902 1.04052e-06
vertex -6 2 1.04907e-06
vertex -5.95106 2.30902 0
endloop
endfacet
facet normal 0.987688 -0.156435 0
outer loop
vertex -6 2 1.04907e-06
vertex -6 2 0
vertex -5.95106 2.30902 0
endloop
endfacet
facet normal 0.987688 0.156435 0
outer loop
vertex -6 2 1.04907e-06
vertex -5.95106 1.69098 1.04052e-06
vertex -6 2 0
endloop
endfacet
facet normal 0.987688 0.156435 0
outer loop
vertex -5.95106 1.69098 1.04052e-06
vertex -5.95106 1.69098 0
vertex -6 2 0
endloop
endfacet
facet normal 0.891007 0.45399 0
outer loop
vertex -5.95106 1.69098 1.04052e-06
vertex -5.80902 1.41221 1.01568e-06
vertex -5.95106 1.69098 0
endloop
endfacet
facet normal 0.891007 0.45399 0
outer loop
vertex -5.80902 1.41221 1.01568e-06
vertex -5.80902 1.41221 0
vertex -5.95106 1.69098 0
endloop
endfacet
facet normal 0.707107 0.707107 0
outer loop
vertex -5.80902 1.41221 1.01568e-06
vertex -5.58779 1.19098 9.76999e-07
vertex -5.80902 1.41221 0
endloop
endfacet
facet normal 0.707107 0.707107 0
outer loop
vertex -5.58779 1.19098 9.76999e-07
vertex -5.58779 1.19098 0
vertex -5.80902 1.41221 0
endloop
endfacet
facet normal 0.45399 0.891007 0
outer loop
vertex -5.58779 1.19098 9.76999e-07
vertex -5.30902 1.04894 9.28258e-07
vertex -5.58779 1.19098 0
endloop
endfacet
facet normal 0.45399 0.891007 0
outer loop
vertex -5.30902 1.04894 9.28258e-07
vertex -5.30902 1.04894 0
vertex -5.58779 1.19098 0
endloop
endfacet
facet normal 0.156434 0.987688 0
outer loop
vertex -5.30902 1.04894 9.28258e-07
vertex -5 1 8.74228e-07
vertex -5.30902 1.04894 0
endloop
endfacet
facet normal 0.156434 0.987688 0
outer loop
vertex -5 1 8.74228e-07
vertex -5 1 0
vertex -5.30902 1.04894 0
endloop
endfacet
facet normal -0.156434 0.987688 0
outer loop
vertex -5 1 8.74228e-07
vertex -4.69098 1.04894 8.20197e-07
vertex -5 1 0
endloop
endfacet
facet normal -0.156434 0.987688 0
outer loop
vertex -4.69098 1.04894 8.20197e-07
vertex -4.69098 1.04894 0
vertex -5 1 0
endloop
endfacet
facet normal -0.45399 0.891007 0
outer loop
vertex -4.69098 1.04894 8.20197e-07
vertex -4.41221 1.19098 7.71456e-07
vertex -4.69098 1.04894 0
endloop
endfacet
facet normal -0.45399 0.891007 0
outer loop
vertex -4.41221 1.19098 7.71456e-07
vertex -4.41221 1.19098 0
vertex -4.69098 1.04894 0
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex -4.41221 1.19098 7.71456e-07
vertex -4.19098 1.41221 7.32775e-07
vertex -4.41221 1.19098 0
endloop
endfacet
facet normal -0.707107 0.707107 0
outer loop
vertex -4.19098 1.41221 7.32775e-07
vertex -4.19098 1.41221 0
vertex -4.41221 1.19098 0
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex -4.19098 1.41221 7.32775e-07
vertex -4.04894 1.69098 7.0794e-07
vertex -4.19098 1.41221 0
endloop
endfacet
facet normal -0.891007 0.45399 0
outer loop
vertex -4.04894 1.69098 7.0794e-07
vertex -4.04894 1.69098 0
vertex -4.19098 1.41221 0
endloop
endfacet
facet normal -0.987688 0.156435 0
outer loop
vertex -4.04894 1.69098 7.0794e-07
vertex -4 2 6.99382e-07
vertex -4.04894 1.69098 0
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
