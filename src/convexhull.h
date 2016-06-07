#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "polygon.h"
#include "minutiaset.h"

typedef struct convexhull_t {
  Polygon poly;
  MinutiaRawSet set;
} ConvexHull;

#endif /* end of include guard: CONVEXHULL_H */
