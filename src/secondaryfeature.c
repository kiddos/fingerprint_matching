#include "secondaryfeature.h"

double secondaryfeature_matching_threshold_r(double r) {
  return 1 + 0.1 * r;
}

double secondaryfeature_matching_threshold_phi(double phi) {
  return PI/30 + 0.1 + phi;
}

double secondaryfeature_matching_threshold_delta(double delta) {
  return PI/30 + 0.1 + delta;
}

SecondaryFeature secondaryfeature_create(MinutiaeRaw m, MinutiaeRaw n0,
                                         MinutiaeRaw n1) {
  Vec3 mn0 = minutiaeraw_delta(n0, m);
  Vec3 mn1 = minutiaeraw_delta(n1, m);

  if (vec_cross(mn0, mn1).z < 0) {
    mn1 = minutiaeraw_delta(n0, m);
    mn0 = minutiaeraw_delta(n1, m);
  }

  const double r0 = sqrt(mn0.x*mn0.x + mn0.y*mn0.y);
  const double r1 = sqrt(mn1.x*mn1.x + mn1.y*mn1.y);
  SecondaryFeature feature = {
    r0, r1,
    arctan(mn0.x, mn0.y),
    arctan(mn1.x, mn1.y),
    acos(vec_dot(mn0, mn1) / r0 / r1)
  };

  return feature;
}
