#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {
  double a[3] = {polygons->m[0][i+1] - polygons->m[0][i],
                 polygons->m[1][i+1] - polygons->m[1][i],
                 polygons->m[2][i+1] - polygons->m[2][i]};
  double b[3] = {polygons->m[0][i+2] - polygons->m[0][i],
                 polygons->m[1][i+2] - polygons->m[1][i],
                 polygons->m[2][i+2] - polygons->m[2][i]};
  double *normal = malloc(3*sizeof(double));
  normal[0] = a[1]*b[2] - a[2]*b[1];
  normal[1] = a[2]*b[0] - a[0]*b[2];
  normal[2]= a[0]*b[1] - a[1]*b[0];
  return normal;
}
