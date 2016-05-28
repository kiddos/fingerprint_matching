#include "minutiaset.h"

bool test_matching_set(const char *const filepath) {
  bool success = 0;
  MinutiaRawSet original = minutiarawset_load(filepath, &success);

  if (success) {
    MinutiaSet query = minutiaset_create(original, 0);
    MinutiaSet reference = minutiaset_create(original, 0);
    const int number_of_matched = minutiaset_compute_num_matched(query, reference);

    printf("number of matched minutia: %d\n", number_of_matched);
    // should exclude the origin point
    if (number_of_matched >= original.size-1) {
      return 1;
    }
  }
  return 0;
}

bool test_none_matching_set(const char *const fp1, const char *const fp2) {
  bool success = 0;
  MinutiaRawSet o1 = minutiarawset_load(fp1, &success);
  MinutiaRawSet o2 = minutiarawset_load(fp2, &success);

  if (success) {
    MinutiaSet query = minutiaset_create(o1, 0);
    MinutiaSet reference = minutiaset_create(o2, 0);
    const int number_of_matched = minutiaset_compute_num_matched(query, reference);

    printf("number of matched minutia: %d\n", number_of_matched);
    // should exclude the origin point
    if (number_of_matched < o2.size-1) {
      return 1;
    }

    minutiaset_release(query);
    minutiaset_release(reference);
  }
  minutiarawset_release(o1);
  minutiarawset_release(o2);
  return 0;
}
int main(int argc, char *argv[]) {
  if (argc == 3) {
    bool success = 0;
    MinutiaRawSet set = minutiarawset_load(argv[1], &success);
    if (success) {
      // test loading
      minutiarawset_info(set);
      minutiarawset_release(set);

      // test matching
      if (!test_matching_set(argv[1])) {
        printf("FAILED!! fail matching from same fingerprint\n");
        return -1;
      }

      if (!test_none_matching_set(argv[1], argv[2])) {
        printf("FAILED!! fail matching from different fingerprint\n");
        return -1;
      }
    }
  }
  return 0;
}
