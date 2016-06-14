#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "polygon.h"
#include "minutiaset.h"

// solve convexhull directly relate the minutia
typedef struct convexhull_t {
  Polygon shape;
  MinutiaRawSet refset;
} ConvexHull;

ConvexHull convexhull_create(const MinutiaRawSet set);
bool convexhull_is_minutiaeraw_in(const ConvexHull convexhull,
                                  const MinutiaeRaw p);

#endif /* end of include guard: CONVEXHULL_H */
