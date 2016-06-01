#ifndef POLYGON_H
#define POLYGON_H

#include <stdlib.h>
#include "type.h"
#include "basicmath.h"
#include "point.h"
#include "line.h"

typedef struct polygon_t {
  int num_points;
  Point *points;
} Polygon;

Polygon polygon_create(int num_points, Point points[]);
double polygon_get_minx(Polygon poly);
double polygon_get_maxx(Polygon poly);
double polygon_get_miny(Polygon poly);
double polygon_get_maxy(Polygon poly);
int polygon_get_line_intersect_count(Polygon poly, Line l);
bool polygon_point_is_in(Polygon poly, Point point);
void Polygon_release(Polygon poly);

#endif /* end of include guard: POLYGON_H */
