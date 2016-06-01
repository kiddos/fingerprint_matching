#ifndef LINE_H
#define LINE_H

#include "type.h"
#include "point.h"

typedef struct line_t {
  Point p1, p2;
} Line;

Line line_create(Point p1, Point p2);
double line_slope(Line l);
bool line_is_vertical(Line l);
bool line_intersect(Line l1, Line l2);

#endif /* end of include guard: LINE_H */
