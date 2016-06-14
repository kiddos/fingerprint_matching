#include "secondaryfeatureset.h"

SecondaryFeatureSet secondaryfeatureset_create_empty() {
  SecondaryFeatureSet set = {0, NULL};
  return set;
}

SecondaryFeatureSet secondaryfeatureset_create(const MinutiaRawSet set) {
  if (set.size == 0) {
    return secondaryfeatureset_create_empty();
  } else {
    SecondaryFeatureSet featureset = {set.size, NULL};
    featureset.set = calloc(set.size, sizeof(SecondaryFeature));

    int i;
    for (i = 0 ; i < set.size ; ++i) {
      MinutiaeRaw center = set.set[i];
      MinutiaeRaw n1, n2;
      minutiarawset_get_2_closest(set, center, &n1, &n2);
      featureset.set[i] = secondaryfeature_create(center, n1, n2);
    }
    return featureset;
  }
}

int secondaryfeatureset_get_num_matched(const SecondaryFeatureSet s1,
                                        const SecondaryFeatureSet s2) {
  int count = 0;

  int i, j;
  for (i = 0 ; i < s1.size ; ++i) {
    for (j = 0 ; j < s2.size ; ++j) {
      if (secondaryfeature_is_matched(s1.set[i], s2.set[j]))
        count ++;
    }
  }
  return count;
}

void secondaryfeatureset_release(SecondaryFeatureSet set) {
  if (set.set) {
    free(set.set);
  }
}
