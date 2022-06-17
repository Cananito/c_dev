#include <stdio.h>

int main(void) {
  int x = 7;
  // Address of x.
  printf("&x: %p\n", &x);
  // Value of x.
  printf("x: %d\n", x);
  printf("---\n");

  int* y = &x;
  // Address of y.
  printf("&y: %p\n", &y);
  // Value of y -> the address of x.
  printf("y: %p\n", y);
  // Dereferencing y -> the value of x.
  printf("*y: %d\n", *y);
  printf("---\n");

  int** z = &y;
  // Address of z.
  printf("&z: %p\n", &z);
  // Value of z -> the address of y.
  printf("z: %p\n", z);
  // Dereferencing z -> the value of y -> the address of x.
  printf("*z: %p\n", *z);
  // Double dereferencing z -> the value of x.
  printf("**z: %d\n", **z);
  printf("---\n");

  return 0;
}
