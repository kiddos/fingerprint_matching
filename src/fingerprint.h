#ifndef FINGERPRINT_H
#define FINGERPRINT_H

#include "minutiaset.h"
#include "type.h"
#include "secondaryfeatureset.h"

typedef struct fingerprint_t {
  int numset;
  int id;
  char *name;
  MinutiaRawSet rawset;
  MinutiaSet *mset;
  SecondaryFeatureSet sset;
} Fingerprint;

Fingerprint fingerprint_create_empty();
Fingerprint fingerprint_load(const char *const filepath, bool *success);
int fingerprint_get_num_matched_minutia(const Fingerprint query,
                                        const Fingerprint reference);
int fingerprint_get_num_matched_secondary_feature(const Fingerprint query,
                                                  const Fingerprint reference);
int fingerprint_get_n(const Fingerprint query, const Fingerprint reference);
int fingerprint_get_num_minutia(const Fingerprint fp);
SecondaryFeature fingerprint_get_center_secondary_feature(const Fingerprint fp);
bool fingerprint_match_secondary_feature(const Fingerprint fp1,
                                         const Fingerprint fp2);
void fingerprint_info(const Fingerprint fp);
void fingerprint_release(Fingerprint fp);

#endif /* end of include guard: FINGERPRINT_H */
