#include "common.h"

const double PI    = 3.14159265358979323846;
const double SQRT2 = 1.41421356237309504880;

double arctan(double dx, double dy) {
  double phi = 0;
  if (dx == 0) {
    if (dy > 0) {
      phi = PI/2;
    } else if(dy < 0) {
      phi = 3*PI/2;
    } else {
      phi = NAN;
    }
  } else if (dx > 0) {
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
