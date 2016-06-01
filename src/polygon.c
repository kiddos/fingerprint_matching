#include "polygon.h"

Polygon polygon_create(int num_points, Point points[]) {
  Polygon poly = {num_points, NULL};
  if (num_points >= 3) {
    poly.points = calloc(num_points, sizeof(Point));

    int i;
    for (i = 0 ; i < num_points ; ++i) {
      poly.points[i] = points[i];
    }
  }
  return poly;
}

double polygon_get_minx(Polygon poly) {
  int i;
  double minx = poly.points[0].x;
  for (i = 1 ; i < poly.num_points ; ++i) {
    if (poly.points[i].x < minx) {
      minx = poly.points[i].x;
    }
  }
  return minx;
}

double polygon_get_maxx(Polygon poly) {
  int i;
  double maxx = poly.points[0].x;
  for (i = 1 ; i < poly.num_points ; ++i) {
    if (poly.points[i].x > maxx) {
      maxx = poly.points[i].x;
    }
  }
  return maxx;
}

double polygon_get_miny(Polygon poly) {
  int i;
  double miny = poly.points[0].y;
  for (i = 1 ; i < poly.num_points ; ++i) {
    if (poly.points[i].y > miny) {
      miny = poly.points[i].x;
    }
  }
  return miny;
}

double polygon_get_maxy(Polygon poly) {
  int i;
  double maxy = poly.points[0].y;
  for (i = 1 ; i < poly.num_points ; ++i) {
    if (poly.points[i].y > maxy) {
      maxy = poly.points[i].x;
    }
  }
  return maxy;
}

int polygon_get_line_intersect_count(Polygon poly, Line l) {
  // construct edges
  Line *edges = calloc(poly.num_points, sizeof(Line));

  int i;
  for (i = 0 ; i < poly.num_points ; ++i) {
    if (i != poly.num_points -1)
      edges[i] = line_create(poly.points[i], poly.points[i+1]);
    else
      edges[i] = line_create(poly.points[i], poly.points[0]);
  }

  int count = 0;
  for (i = 0 ; i < poly.num_points ; ++i) {
    if (line_intersect(edges[i], l)) ++ count;
  }

  free(edges);

  return count;
}

bool polygon_point_is_in(Polygon poly, Point point) {
  const double size = (polygon_get_maxx(poly) - polygon_get_minx(poly)) *
      (polygon_get_maxy(poly) - polygon_get_miny(poly));
  const double ray_length = size * size;

  double theta = 2 * PI * ((rand() % 10000) / 10000);
  Point p2 = {point.x + ray_length * cos(theta),
              point.y + ray_length * sin(theta)};
  Line ray = line_create(point, p2);
  int count = polygon_get_line_intersect_count(poly, ray);
  while (count == 0) {
    theta = 2 * PI * ((rand() % 10000) / 10000);
    p2 = point_create(point.x + ray_length * cos(theta),
                      point.y + ray_length * sin(theta));
    ray = line_create(point, p2);
    count = polygon_get_line_intersect_count(poly, ray);
  }

  if (count % 2 == 1)
    return 1;
  return 0;
}

void polygon_release(Polygon poly) {
  if (poly.points) {
    free(poly.points);
  }
}
