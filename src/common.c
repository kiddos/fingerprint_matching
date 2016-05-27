#include "common.h"

const double PI = 3.14159265358979323846;

double arctan(double dx, double dy) {
  double phi = 0;
  if (dx >= 0) {
    if (dy >= 0) {
      phi = atan(dy/dx);
    } else {
      phi = 2*PI + atan(dy/dx);
    }
  } else {
    phi = PI + atan(dy/dx);
  }
  return phi;
}

double vec_dot(Vec3 v1, Vec3 v2) {
  return v1.x*v2.x + v1.y+v2.y + v1.z*v2.z;
}

Vec3 vec_cross(Vec3 v1, Vec3 v2) {
  Vec3 out;
  out.x = v1.y*v2.z - v1.z*v2.y;
  out.y = v1.z*v2.x - v1.x*v2.z;
  out.z = v1.x*v2.y - v1.y*v2.x;
  return out;
}
