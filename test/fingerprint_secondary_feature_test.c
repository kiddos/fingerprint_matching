#include <stdio.h>
#include "fingerprintset.h"
#include "similarity.h"

void test_matching_with_secondary_feature(FingerprintSet query,
                                          FingerprintSet reference) {
  int i, j;
  for (i = 0 ; i < query.numprint ; ++i) {
    Fingerprint q = query.fingerprints[i];
    const char *qname = q.name;
    for (j = 0 ; j < reference.numprint ; ++j) {
      Fingerprint r = reference.fingerprints[j];
      const char *rname = r.name;

      if (strcmp(qname, rname) == 0) {
        printf("query %s matching with reference %s using Secondary Feature: ",
              qname, rname);
        if (fingerprint_match_secondary_feature(q, r)) {
          printf("success!!\n");
        } else {
          printf("failed!!\n");
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    FingerprintSet query = fingerprintset_load_from_list(argv[1]);
    FingerprintSet reference = fingerprintset_load_from_list(argv[2]);

    test_matching_with_secondary_feature(query, reference);

    fingerprintset_release(query);
    fingerprintset_release(reference);
  } else {
    const char *const QUERY = "query.txt";
    const char *const REFERENCE = "reference.txt";

    FingerprintSet query = fingerprintset_load_from_list(QUERY);
    FingerprintSet reference = fingerprintset_load_from_list(REFERENCE);

    test_matching_with_secondary_feature(query, reference);

    fingerprintset_release(query);
    fingerprintset_release(reference);
  }
  return 0;
}
