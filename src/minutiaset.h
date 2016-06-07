#ifndef MINUTIASET_H
#define MINUTIASET_H

#include <stdio.h>
#include <stdlib.h>
#include "minutiae.h"

typedef struct minutiarawset_t {
  int size;
  MinutiaeRaw *set;
} MinutiaRawSet;

typedef struct minutiaset_t {
  int size;
  Minutiae *set;
} MinutiaSet;

MinutiaRawSet minutiarawset_create_empty();
MinutiaRawSet minutiarawset_create_copy(MinutiaRawSet rawset);
MinutiaRawSet minutiarawset_load(const char *const filepath, bool *success);
MinutiaSet minutiaset_create_empty();
MinutiaSet minutiaset_create(MinutiaRawSet rawset, int refindex);
int minutiaset_compute_num_matched(MinutiaSet query, MinutiaSet reference);
void minutiarawset_get_mean(MinutiaRawSet set, MinutiaeRaw *mean);
void minutiarawset_get_2_closest(MinutiaRawSet set, MinutiaeRaw center,
                                 MinutiaeRaw *n1, MinutiaeRaw *n2);
void minutiarawset_info(MinutiaRawSet rawset);
void minutiaset_info(MinutiaSet set);
void minutiarawset_release(MinutiaRawSet set);
void minutiaset_release(MinutiaSet set);

#endif /* end of include guard: MINUTIASET_H */
