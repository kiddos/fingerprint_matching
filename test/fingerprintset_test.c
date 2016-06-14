#include "fingerprintset.h"
#include "similarity.h"

void test_find_best_match(FingerprintSet query, FingerprintSet reference) {
  SimilarityScore evaluator = similarityscore_create(TRADITIONAL);

  int i, count = 0;
  for (i = 0 ; i < query.numprint ; ++i) {
    double best_score = 0;
    const int best = fingerprintset_find_best_match(query.fingerprints[i],
                                                    reference,
                                                    evaluator, &best_score);
    printf("best match for query (I) %s is %s in reference (R)\n",
          query.fingerprints[i].name, reference.fingerprints[best].name);
    if (strcmp(query.fingerprints[i].name,
               reference.fingerprints[best].name) == 0) {
      ++ count;
    }
  }
  printf("correct count: %d\n", count);
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    FingerprintSet query = fingerprintset_load_from_list(argv[1]);
    FingerprintSet reference = fingerprintset_load_from_list(argv[2]);
    test_find_best_match(query, reference);
    fingerprintset_release(query);
    fingerprintset_release(reference);
  } else {
    const char *const QUERY = "query.txt";
    const char *const REFERENCE = "reference.txt";

    FingerprintSet query = fingerprintset_load_from_list(QUERY);
    FingerprintSet reference = fingerprintset_load_from_list(REFERENCE);
    test_find_best_match(query, reference);
    fingerprintset_release(query);
    fingerprintset_release(reference);
  }
  return 0;
}
