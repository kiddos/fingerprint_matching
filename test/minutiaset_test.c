#include "minutiaset.h"

int main(int argc, char *argv[]) {
  if (argc == 2) {
    MinutiaRawSet *set = minutiarawset_load(argv[1]);
    minutiarawset_info(set);
    minutiarawset_release(set);
  }
  return 0;
}
