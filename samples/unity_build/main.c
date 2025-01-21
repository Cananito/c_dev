// A unity build is when you compile multiple source files in a single
// compilation unit. This is achieved by including .c files instead of .h ones.
// https://en.wikipedia.org/wiki/Unity_build

// On macOS, using clang:
// $ clang a.c b.c main.c -o main
// $ ./main

#include <stdio.h>
#include "a.c"
#include "b.c"

int main(void) {
  printf("A: %d\n", A());
  printf("B: %d\n", B());
  return 0;
}
