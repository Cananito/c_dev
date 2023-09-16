#include <stdio.h>
#include "bread.h"

// On macOS, using clang:
// $ clang -o toasty -I bread/ main.c
// $ ./toasty

int main(void) {
  struct Bread bread = {
    .slices = 3,
  };
  printf("TOASTY!!!!!!!!!!\n");
  printf("Slices: %d\n", bread.slices);
  return 0;
}
