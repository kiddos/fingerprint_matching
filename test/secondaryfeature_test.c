#include "secondaryfeature.h"

int main(void) {
  MinutiaeRaw ref = {0, 0, 0};
  MinutiaeRaw mr1 = {10, 10, PI / 3};
  MinutiaeRaw mr2 = {-10, 10, PI / 3};
  /** MinutiaeRaw mr3 = {-10, -10, PI / 3}; */
  /** MinutiaeRaw mr4 = {10, -10, PI / 3}; */

  SecondaryFeature feature = secondaryfeature_create(ref, mr1, mr2);
  secondaryfeature_info(feature);
  return 0;
}
