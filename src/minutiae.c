#include "minutiae.h"

double minutiae_matching_threshold_r(double r) {
  return 1 + 0.1 * r;
}

double minutiae_matching_threshold_phi(double phi) {
  return PI/30 + 0.01 * phi;
}

double minutiae_matching_threshold_theta(double theta) {
  return PI/30 + 0.01 * theta;
}

Vec3 minutiaeraw_delta(MinutiaeRaw mr1, MinutiaeRaw mr2) {
  Vec3 out = {mr1.x - mr2.x, mr1.y - mr2.y, 0};
  return out;
}

MinutiaeRaw minutiaeraw_create(double x, double y, double orientation) {
  MinutiaeRaw mr = {x, y, orientation};
  return mr;
}

Minutiae minutiae_create(MinutiaeRaw r, MinutiaeRaw p) {
  const Vec3 del = minutiaeraw_delta(p, r);
  Minutiae m = {
    sqrt(del.x*del.x + del.y*del.y),
    arctan(del.x, del.y),
    p.orientation - r.orientation
  };
  return m;
}

bool minutiae_is_matched(Minutiae q, Minutiae r) {
  if (fabs(q.r-r.r) <= minutiae_matching_threshold_r(q.r) &&
      fabs(q.phi-r.phi) <= minutiae_matching_threshold_phi(q.phi) &&
      fabs(q.r-r.r) <= minutiae_matching_threshold_theta(q.theta)) {
    return 1;
  } else {
    return 0;
  }
}

void minutiae_info(Minutiae m) {
#ifdef DEBUG
  printf("Minutiae: (%lf,%lf,%lf)\n", m.r, m.phi, m.theta);
#endif
}

void minutiaeraw_info(MinutiaeRaw m) {
#ifdef DEBUG
  printf("Minutiae Raw: (%lf,%lf,%lf)\n", m.x, m.y, m.orientation);
#endif
}
