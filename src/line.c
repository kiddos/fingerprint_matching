#include "line.h"

Line line_create(Point p1, Point p2) {
  Line l = {p1, p2};
  return l;
}

double line_slope(Line l) {
  const double dy = l.p2.y - l.p1.y;
  const double dx = l.p2.x - l.p1.x;
  return dy / dx;
}

bool line_is_vertical(Line l) {
  const double m = line_slope(l);
  if (m == 1.0/0.0 || m == -1.0/0.0) {
    return 1;
  }
  return 0;
}

bool line_intersect(Line l1, Line l2) {
  if (!line_is_vertical(l1) && !line_is_vertical(l2)) {
    const double m1 = line_slope(l1);
    const double m2 = line_slope(l2);
    if (m1 != m2) {
      if (point_within_range(l1.p1, l2.p1, l2.p2) ||
          point_within_range(l1.p2, l2.p1, l2.p2) ||
          point_within_range(l2.p1, l1.p1, l1.p2) ||
          point_within_range(l2.p2, l1.p1, l1.p2)) {
        return 1;
      }
    }
  }
  return 0;
}
