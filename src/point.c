#include "point.h"

Point point_create(double x, double y) {
  Point p = {x, y};
  return p;
}

bool point_within_range(Point p, Point r1, Point r2) {
  const double minx = fmin(r1.x, r2.x);
  const double maxx = fmax(r1.x, r2.x);
  const double miny = fmin(r1.y, r2.y);
  const double maxy = fmax(r1.y, r2.y);

  if (p.x >= minx && p.x <= maxx && p.y >= miny && p.y <= maxy) {
    return 1;
  }
  return 0;
}
