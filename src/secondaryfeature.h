#ifndef SECONDARYFEATURE_H
#define SECONDARYFEATURE_H

#include <stdio.h>
#include "type.h"
#include "minutiae.h"

typedef struct secondaryfeature_t {
  double r0, r1, phi0, phi1, delta;
} SecondaryFeature;

double secondaryfeature_matching_threshold_r(double r);
double secondaryfeature_matching_threshold_phi(double phi);
double secondaryfeature_matching_threshold_delta(double delta);
SecondaryFeature secondaryfeature_create(MinutiaeRaw m, MinutiaeRaw n0,
                                         MinutiaeRaw n1);
bool secondaryfeature_is_matched(SecondaryFeature f1, SecondaryFeature f2);
void secondaryfeature_info(SecondaryFeature feature);

#endif /* end of include guard: SECONDARYFEATURE_H */
