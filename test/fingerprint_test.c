#include "fingerprint.h"

bool test_matching_fingerprint(const char *const filepath) {
  bool success = 0;
  Fingerprint fp1 = fingerprint_load(filepath, &success);
  Fingerprint fp2 = fingerprint_load(filepath, &success);
  if (success) {
    const int matched_minutia = fingerprint_get_num_matched_minutia(fp1, fp2);
    const int num_minutia = fingerprint_get_num_minutia(fp1);
    printf("number of minutia matched: %d\n", num_minutia);
    printf("number of minutia matched: %d\n", matched_minutia);

    if (matched_minutia >= num_minutia*(num_minutia-2) &&
        matched_minutia <= num_minutia*num_minutia) {
      return 1;
    }
  }
  fingerprint_release(fp1);
  fingerprint_release(fp2);
  return 0;
}

bool test_none_matching_fingerprint(const char *const f1, const char *const f2) {
  bool success = 0;
  Fingerprint fp1 = fingerprint_load(f1, &success);
  Fingerprint fp2 = fingerprint_load(f2, &success);
  if (success) {
    const int matched_minutia = fingerprint_get_num_matched_minutia(fp1, fp2);
    const int num_minutia1 = fingerprint_get_num_minutia(fp1);
    const int num_minutia2 = fingerprint_get_num_minutia(fp2);
    printf("number of minutia for fp1: %d\n", num_minutia1);
    printf("number of minutia for fp2: %d\n", num_minutia2);
    printf("number of minutia matched: %d\n", matched_minutia);

    if (matched_minutia <= num_minutia1*(num_minutia2-2) ||
        matched_minutia >= num_minutia1*num_minutia2) {
      return 1;
    }
  }
  fingerprint_release(fp1);
  fingerprint_release(fp2);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    bool success = 0;
    Fingerprint fingerprint = fingerprint_load(argv[1], &success);
    if (success) {
      // test loading
      fingerprint_info(fingerprint);
      fingerprint_release(fingerprint);

      // test matching
      if (!test_matching_fingerprint(argv[1])) {
        printf("FAILED!! fail matching from same fingerprint\n");
        return -1;
      }

      if (!test_none_matching_fingerprint(argv[1], argv[2])) {
        printf("FAILED!! fail matching from different fingerprint\n");
        return -1;
      }
    }
  }
  return 0;
}
