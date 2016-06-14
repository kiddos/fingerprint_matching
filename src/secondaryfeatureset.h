#ifndef SECONDARYFEATURESET_H
#define SECONDARYFEATURESET_H

#include "secondaryfeature.h"
#include "minutiaset.h"

typedef struct secondaryfeatureset_t {
  int size;
  SecondaryFeature *set;
} SecondaryFeatureSet;

SecondaryFeatureSet secondaryfeatureset_create_empty();
SecondaryFeatureSet secondaryfeatureset_create(const MinutiaRawSet set);
int secondaryfeatureset_get_num_matched(const SecondaryFeatureSet s1,
                                        const SecondaryFeatureSet s2);
void secondaryfeatureset_release(SecondaryFeatureSet set);

#endif /* end of include guard: SECONDARYFEATURESET_H */
