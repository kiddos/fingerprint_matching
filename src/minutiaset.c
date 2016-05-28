#include "minutiaset.h"

MinutiaRawSet minutiarawset_create_empty() {
  MinutiaRawSet set = {0, NULL};
  return set;
}

static bool startwith(char *str, char *key) {
  if (strlen(str) < strlen(key))
    return 0;
  unsigned long i;
  for (i = 0 ; i < strlen(key) ; ++i) {
    if (str[i] != key[i]) return 0;
  }
  return 1;
}

MinutiaRawSet minutiarawset_load(const char* const filepath, bool *success) {
  MinutiaRawSet set;
  FILE *file = fopen(filepath, "r");

  if (file) {
    char buffer[2048] = {'\0'};

    set.size = -1;
    while (fgets(buffer, 2048, file) != NULL) {
      /** printf("%s", buffer); */
      if (!startwith(buffer, "--")) {
        if (set.size < 0) {
          set.size = atoi(buffer);
          set.set = calloc(set.size, sizeof(MinutiaeRaw));
        } else if (strlen(buffer) >= 3){
          // TODO need to implement reading orientation
          int num = 0, x = 0, y = 0;
          sscanf(buffer, "p%d = (%d,%d)\n", &num, &x, &y);
          set.set[num-1] = minutiaeraw_create(x, y, 0);
        }
      }
      memset(buffer, '\0', 2048);
    }

    if (file)
      fclose(file);
    *success = 1;
    return set;
  } else {
#ifdef DEBUG
    printf("ERROR: Fail to open %s", filepath);
#endif
    *success = 0;
    return minutiarawset_create_empty();
  }
}

MinutiaSet minutiaset_create_empty() {
  MinutiaSet set = {0, NULL};
  return set;
}

MinutiaSet minutiaset_create(MinutiaRawSet rawset, int refindex) {
  MinutiaSet set;
  set.size = rawset.size;
  set.set = (Minutiae *) calloc(set.size, sizeof(Minutiae));
  MinutiaeRaw ref = rawset.set[refindex];
  int i;
  for (i = 0 ; i < set.size ; ++i) {
    set.set[i] = minutiae_create(ref, rawset.set[i]);
  }
  return set;
}

int minutiaset_compute_num_matched(MinutiaSet query, MinutiaSet reference) {
  int match_count = 0;
  int i, j;
  for (i = 0 ; i < query.size ; ++i) {
    for (j = 0 ; j < reference.size ; ++j) {
      if (minutiae_is_matched(query.set[i], reference.set[j])) {
        match_count ++;
        printf("query: ");
        minutiae_info(query.set[i]);
        printf("reference: ");
        minutiae_info(reference.set[j]);
      }
    }
  }
  return match_count;
}

void minutiarawset_info(MinutiaRawSet rawset) {
  int i;
  for (i = 0 ; i < rawset.size ; ++i) {
    minutiaeraw_info(rawset.set[i]);
  }
}

void minutiaset_info(MinutiaSet set) {
  int i;
  for (i = 0 ; i < set.size ; ++i) {
    minutiae_info(set.set[i]);
  }
}

void minutiarawset_release(MinutiaRawSet set) {
  if (set.set) free(set.set);
}

void minutiaset_release(MinutiaSet set) {
  if (set.set) free(set.set);
}
