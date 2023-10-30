#include <stdio.h>

static int* UnstackedValue() {
  int x = 7;
  return &x;
}

int main(void) {
  int* p = UnstackedValue();

  // Prints a valid pointer.
  printf("p: %p\n", p);

  // Prints a garbage value.
  printf("*p: %d\n", *p);

  return 0;
}
