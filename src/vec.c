#include "vec.h"

Vec3 vec_create(double x, double y, double z) {
  Vec3 vec = {x, y, z};
  return vec;
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
