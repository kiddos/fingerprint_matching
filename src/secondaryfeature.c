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

bool secondaryfeature_is_matched(SecondaryFeature f1, SecondaryFeature f2) {
  return (fabs(f1.r0-f2.r0) <= secondaryfeature_matching_threshold_r(f1.r0) &&
      fabs(f1.r1-f2.r1) <= secondaryfeature_matching_threshold_r(f1.r1) &&
      fabs(f1.phi0-f2.phi0) <= secondaryfeature_matching_threshold_phi(f1.phi0) &&
      fabs(f1.phi1-f2.phi1) <= secondaryfeature_matching_threshold_phi(f1.phi1) &&
      fabs(f1.delta-f2.delta) <= secondaryfeature_matching_threshold_delta(f1.delta));
}

void secondaryfeature_info(SecondaryFeature feature) {
  printf("feature: (%lf,%lf,%lf,%lf,%lf)\n",
      feature.r0, feature.r1, feature.phi0, feature.phi1, feature.delta);
}
