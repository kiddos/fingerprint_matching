#ifndef POINT_H
#define POINT_H

#include <math.h>
#include "type.h"

typedef struct point_t {
  double x, y;
} Point;

Point point_create(double x, double y);
bool point_within_range(Point p, Point r1, Point r2);

#endif /* end of include guard: POINT_H */
