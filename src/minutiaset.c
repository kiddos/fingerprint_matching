#include "minutiaset.h"

bool startwith(char *str, char *key) {
  if (strlen(str) < strlen(key))
    return 0;
  unsigned long i;
  for (i = 0 ; i < strlen(key) ; ++i) {
    if (str[i] != key[i]) return 0;
  }
  return 1;
}

MinutiaRawSet *minutiarawset_load(const char* const filepath) {
  FILE *file = fopen(filepath, "r");
  if (file) {
    MinutiaRawSet *set = (MinutiaRawSet *) malloc(sizeof(MinutiaRawSet));
    char buffer[2048];

    set->size = -1;
    while (fgets(buffer, 2048, file) != NULL) {
      if (!startwith(buffer, "--")) {
        if (set->size < 0) {
          set->size = atoi(buffer);
        } else {
          // TODO need to implement reading orientation
          int num = 0, x = 0, y = 0;
          sscanf(buffer, "p%d = (%d,%d)\n", &num, &x, &y);
          set->set[num-1] = minutiaeraw_create(x, y, 0);
        }
      }
    }

    fclose(file);
    return set;
  } else {
#ifdef DEBUG
    printf("ERROR: Fail to open %s", filepath);
#endif
    return NULL;
  }
}

MinutiaSet *minutiaset_create(MinutiaRawSet *rawset, int refindex) {
  MinutiaSet *set = (MinutiaSet *) malloc(sizeof(MinutiaSet));
  set->size = rawset->size;
  set->set = (Minutiae *) calloc(set->size, sizeof(Minutiae));
  MinutiaeRaw ref = rawset->set[refindex];
  int i;
  for (i = 0 ; i < set->size ; ++i) {
    set->set[i] = minutiae_create(ref, rawset->set[i]);
  }
  return set;
}

int minutiaset_compute_num_matched(MinutiaSet *q, MinutiaSet *r) {
  int match_count = 0;
  int i, j;
  for (i = 0 ; i < q->size ; ++i) {
    for (j = 0 ; j < r->size ; ++j) {
      if (minutiae_is_matched(r->set[j], q->set[i])) {
        match_count ++;
      }
    }
  }
  return match_count;
}

void minutiarawset_release(MinutiaRawSet *set) {
  if (set) {
    if (set->set) free(set->set);
    free(set);
  }
}

void minutiaset_release(MinutiaSet *set) {
  if (set) {
    if (set->set) free(set->set);
    free(set);
  }
}
