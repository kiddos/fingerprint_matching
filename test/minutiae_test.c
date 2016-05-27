#include "minutiae.h"

int main(void) {
  MinutiaeRaw ref = {0, 0, 0};
  MinutiaeRaw mr1 = {10, 10, PI / 3};
  MinutiaeRaw mr2 = {-10, 10, PI / 3};
  MinutiaeRaw mr3 = {-10, -10, PI / 3};
  MinutiaeRaw mr4 = {10, -10, PI / 3};

  Minutiae m1 = minutiae_create(ref, mr1);
  Minutiae m2 = minutiae_create(ref, mr2);
  Minutiae m3 = minutiae_create(ref, mr3);
  Minutiae m4 = minutiae_create(ref, mr4);

  printf("PI/4 = %lf\n", PI/4);
  minutiae_info(m1);
  minutiae_info(m2);
  minutiae_info(m3);
  minutiae_info(m4);

  mr1 = minutiaeraw_create(1, sqrt(3), PI / 3);
  mr2 = minutiaeraw_create(-1, sqrt(3), PI / 3);
  mr3 = minutiaeraw_create(-1, -sqrt(3), PI / 3);
  mr4 = minutiaeraw_create(1, -sqrt(3), PI / 3);

  m1 = minutiae_create(ref, mr1);
  m2 = minutiae_create(ref, mr2);
  m3 = minutiae_create(ref, mr3);
  m4 = minutiae_create(ref, mr4);

  minutiae_info(m1);
  minutiae_info(m2);
  minutiae_info(m3);
  minutiae_info(m4);

  return 0;
}
