#include <stdio.h>
#include <stdlib.h>

void StackPointers(void) {
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

}

void HeapPointers(void) {
  // Assign with derefence syntax, allocating with malloc.
  int a = 1;
  int* p1 = malloc(sizeof(int));
  *p1 = a;
  printf("a: %d, *p1: %d, p1[0]: %d, *(p1 + 0): %d\n", a, *p1, p1[0], *(p1 + 0));
  printf("---\n");
  free(p1);

  // Assign with subscript syntax, allocating with malloc.
  int b = 2;
  int* p2 = malloc(sizeof(int));
  p2[0] = b;
  printf("b: %d, *p2: %d, p2[0]: %d, *(p2 + 0): %d\n", b, *p2, p2[0], *(p2 + 0));
  printf("---\n");
  free(p2);

  // Assign with subscript syntax, allocating with calloc.
  int c = 3;
  int* p3 = calloc(1, sizeof(int));
  p3[0] = c;
  printf("c: %d, *p3: %d, p3[0]: %d, *(p3 + 0): %d\n", c, *p3, p3[0], *(p3 + 0));
  printf("---\n");
  free(p3);

  // Assign with pointer offset syntax, allocating with calloc.
  int d = 4;
  int* p4 = calloc(1, sizeof(int));
  *(p4 + 0) = d;
  printf("d: %d, *p4: %d, p4[0]: %d, *(p4 + 0): %d\n", d, *p4, p4[0], *(p4 + 0));
  printf("---\n");
  free(p3);

  // Note: calloc initializes each element (thus slower than malloc), plus no
  // need to multiply to determine total size.
}

int main(void) {
  StackPointers();
  HeapPointers();
  return 0;
}
