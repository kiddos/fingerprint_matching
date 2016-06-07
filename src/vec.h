#ifndef VEC_H
#define VEC_H

#include <math.h>

typedef struct vec3_t {
  double x, y, z;
} Vec3;

Vec3 vec_create(double x, double y, double z);
Vec3 vec_cross(Vec3 v1, Vec3 v2);
double vec_dot(Vec3 v1, Vec3 v2);
double vec_length(Vec3 v);

#endif /* end of include guard: VEC_H */
