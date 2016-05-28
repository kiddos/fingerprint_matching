#ifndef FINGERPRINTSET
#define FINGERPRINTSET

#include "fingerprint.h"
#include "similarity.h"

typedef struct fingerprintset_t {
  int numprint;
  Fingerprint *fingerprints;
} FingerprintSet;

FingerprintSet fingerprintset_create_empty();
FingerprintSet fingerprintset_load(const char *list[], int num);
FingerprintSet fingerprintset_load_from_list(const char *const listpath);
int fingerprintset_find_best_match(Fingerprint query,
                                   FingerprintSet reference,
                                   SimilarityScore sc, double *score);
void fingerprintset_release(FingerprintSet set);

#endif /* end of include guard: FINGERPRINTSET */
