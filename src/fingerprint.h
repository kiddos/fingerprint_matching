#ifndef FINGERPRINT_H
#define FINGERPRINT_H

#include "minutiaset.h"
#include "type.h"
#include "secondaryfeature.h"

typedef struct fingerprint_t {
  int numset;
  int id;
  char *name;
  MinutiaRawSet rawset;
  MinutiaSet *set;
} Fingerprint;

Fingerprint fingerprint_create_empty();
Fingerprint fingerprint_load(const char *const filepath, bool *success);
int fingerprint_get_num_matched_minutia(Fingerprint query, Fingerprint reference);
int fingerprint_get_num_minutia(Fingerprint fp);
SecondaryFeature fingerprint_get_center_secondary_feature(Fingerprint fp);
bool fingerprint_match_secondary_feature(Fingerprint fp1, Fingerprint fp2);
void fingerprint_info(Fingerprint fp);
void fingerprint_release(Fingerprint fp);

#endif /* end of include guard: FINGERPRINT_H */
