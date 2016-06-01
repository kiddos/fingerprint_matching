#include "fingerprintset.h"

FingerprintSet fingerprintset_create_empty() {
  FingerprintSet set = {0, NULL};
  return set;
}

static void trim_nextline(char buffer[2048]) {
  size_t i;
  for (i = 0 ; i < strlen(buffer) ; ++i) {
    if (buffer[i] == '\r' || buffer[i] == '\n') {
      buffer[i] = '\0';
    }
  }
}

FingerprintSet fingerprintset_load(const char *list[], int num) {
  FingerprintSet set = {num, NULL};
  set.fingerprints = calloc(num, sizeof(Fingerprint));

  int i;
  for (i = 0 ; i < num ; ++i) {
    if (list[i] != NULL) {
      bool success = 0;
      set.fingerprints[i] = fingerprint_load(list[i], &success);
      if (!success) {
#ifdef DEBUG
        printf("WARNING!! '%s' may not be loaded.", list[i]);
#endif
      }
    }
    else {
      set.fingerprints[i] = fingerprint_create_empty();
    }
  }
  return set;
}

FingerprintSet fingerprintset_load_from_list(const char * const listpath) {
  char buffer[2048] = {'\0'};
  FILE *file = fopen(listpath, "r");

  if (file) {
    FingerprintSet set = {0, NULL};

    while (fgets(buffer, 2048, file) != NULL) {
      set.numprint ++;
      memset(buffer, '\0', 2048);
    }
    set.fingerprints = calloc(set.numprint, sizeof(Fingerprint));

    int i = 0;
    rewind(file);
    while (fgets(buffer, 2048, file) != NULL) {
      trim_nextline(buffer);

      bool success = 0;
      set.fingerprints[i] = fingerprint_load(buffer, &success);
      if (!success) {
#ifdef DEBUG
        printf("WARNING!! '%s' may not be loaded.", buffer);
#endif
      }
      ++i;
      memset(buffer, '\0', 2048);
    }

    fclose(file);

    return set;
  }
  return fingerprintset_create_empty();
}

int fingerprintset_find_best_match(Fingerprint query,
                                   FingerprintSet referenceset,
                                   SimilarityScore sc, double *score) {
  const int sizei = fingerprint_get_num_minutia(query);
  int sizer = fingerprint_get_num_minutia(referenceset.fingerprints[0]);
  int n = fingerprint_get_num_matched_minutia(query, referenceset.fingerprints[0]);

  /** TODO Compute OI, OR savg*/
  int oi = 0, or = 0;
  double savg = 0;
  SimilarityScoreInput input =
      similarityscore_input_create(n, sizei, sizer, oi, or, savg);

  int maxindex = 0;
  double maxval = sc.compute_score(input);
  /** printf("n = %d, sizei = %d, sizer = %d, Oi = %d, Or = %d, savg = %lf\n", */
  /**       n, sizei, sizer, oi, or, savg); */
  /** printf("score for %s(I) %s(R): %lf\n", query.name, */
  /**       referenceset.fingerprints[0].name, maxval); */

  int i;
  for (i = 1 ; i < referenceset.numprint ; ++i) {
    sizer = fingerprint_get_num_minutia(referenceset.fingerprints[i]);
    n = fingerprint_get_num_matched_minutia(query, referenceset.fingerprints[i]);
    input = similarityscore_input_create(n, sizei, sizer, oi, or, savg);

    double val = sc.compute_score(input);
    /** printf("n = %d, sizei = %d, sizer = %d, Oi = %d, Or = %d, savg = %lf\n", */
    /**       n, sizei, sizer, oi, or, savg); */
    /** printf("score for %s(I) %s(R): %lf\n", query.name, */
    /**       referenceset.fingerprints[i].name, val); */
    if (val > maxval) {
      maxval = val;
      maxindex = i;
    }
  }

  *score = maxval;
  return maxindex;
}

void fingerprintset_release(FingerprintSet set) {
  if (set.fingerprints) {
    int i;
    for (i = 0 ; i < set.numprint ; ++i) {
      fingerprint_release(set.fingerprints[i]);
    }
  }
}
