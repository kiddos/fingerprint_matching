#ifndef MINUTIAE_H
#define MINUTIAE_H

#include "common.h"
#include "type.h"

typedef struct minutiaeraw_t {
  double x, y, orientation;
} MinutiaeRaw;

typedef struct minutiae_t {
  double r, phi, theta;
} Minutiae;

double minutiae_matching_threshold_r(double r);
double minutiae_matching_threshold_phi(double phi);
double minutiae_matching_threshold_theta(double theta);
Vec3 minutiaeraw_delta(MinutiaeRaw mr1, MinutiaeRaw mr2);
MinutiaeRaw minutiaeraw_create(double x, double y, double orientation);
Minutiae minutiae_create(MinutiaeRaw r, MinutiaeRaw p);
bool minutiae_is_matched(Minutiae query, Minutiae refererence);
void minutiaeraw_info(MinutiaeRaw m);
void minutiae_info(Minutiae m);

#endif /* end of include guard: MINUTIAE_H */
