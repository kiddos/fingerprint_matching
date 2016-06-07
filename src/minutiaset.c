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

MinutiaRawSet minutiarawset_create_copy(MinutiaRawSet rawset) {
  MinutiaRawSet newset = {rawset.size, NULL};
  newset.set = calloc(rawset.size, sizeof(MinutiaeRaw));

  int i;
  for (i = 0 ; i < rawset.size ; ++i) {
    newset.set[i] = rawset.set[i];
  }
  return newset;
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
        /** printf("query: "); */
        /** minutiae_info(query.set[i]); */
        /** printf("reference: "); */
        /** minutiae_info(reference.set[j]); */
      }
    }
  }
  return match_count;
}

void minutiarawset_get_mean(MinutiaRawSet set, MinutiaeRaw *mean) {
  MinutiaeRaw center = {0, 0, 0};

  int i;
  for (i = 0 ; i < set.size ; ++i) {
    center.x += set.set[i].x;
    center.y += set.set[i].y;
  }

  center.x /= (double) set.size;
  center.y /= (double) set.size;

  MinutiaeRaw closest = set.set[0];
  double dist = vec_length(minutiaeraw_delta(center, closest));
  for (i = 1 ; i < set.size ; ++i) {
    double newdist = vec_length(minutiaeraw_delta(center, closest));
    if (newdist < dist) {
      dist = newdist;
      closest = set.set[i];
    }
  }

  *mean = closest;
}

void minutiarawset_get_2_closest(MinutiaRawSet set, MinutiaeRaw center,
                                 MinutiaeRaw *n1, MinutiaeRaw *n2) {
  MinutiaRawSet sorted = minutiarawset_create_copy(set);

  int i, j;
  for (i = 0 ; i < sorted.size ; ++i) {
    for (j = i + 1 ; j < sorted.size ; ++j) {
      const double dist1 = vec_length(minutiaeraw_delta(center, sorted.set[i]));
      const double dist2 = vec_length(minutiaeraw_delta(center, sorted.set[j]));
      if (dist1 > dist2) {
        const MinutiaeRaw temp = sorted.set[i];
        sorted.set[i] = sorted.set[j];
        sorted.set[j] = temp;
      }
    }
  }

  if (sorted.size >= 3) {
    *n1 = sorted.set[1];
    *n2 = sorted.set[2];
  } else {
    *n1 = minutiaeraw_create(0, 0, 0);
    *n2 = minutiaeraw_create(0, 0, 0);
  }

  minutiarawset_release(sorted);
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
