#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <math.h>

extern const double PI;

typedef struct vec3_t {
  double x, y, z;
} Vec3;

double arctan(double dx, double dy);
double vec_dot(Vec3 v1, Vec3 v2);
Vec3 vec_cross(Vec3 v1, Vec3 v2);

#endif /* end of include guard: COMMON_H */
