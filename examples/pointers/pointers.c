#include <stdio.h>
#include <stdlib.h>

static void StackPointers(void) {
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

static void HeapPointers(void) {
  // Assign with derefence syntax, allocating with malloc.
  int a = 1;
  int* p1 = malloc(sizeof(int));
  *p1 = a;
  printf("a: %d, *p1: %d, p1[0]: %d, *(p1 + 0): %d, 0[p1]: %d\n", a, *p1, p1[0], *(p1 + 0), 0[p1]);
  printf("---\n");
  free(p1);

  // Assign with subscript syntax, allocating with malloc.
  int b = 2;
  int* p2 = malloc(sizeof(int));
  p2[0] = b;
  printf("b: %d, *p2: %d, p2[0]: %d, *(p2 + 0): %d, 0[p2]: %d\n", b, *p2, p2[0], *(p2 + 0), 0[p2]);
  printf("---\n");
  free(p2);

  // Assign with subscript syntax, allocating with calloc.
  int c = 3;
  int* p3 = calloc(1, sizeof(int));
  p3[0] = c;
  printf("c: %d, *p3: %d, p3[0]: %d, *(p3 + 0): %d, 0[p3]: %d\n", c, *p3, p3[0], *(p3 + 0), 0[p3]);
  printf("---\n");
  free(p3);

  // Assign with pointer offset syntax, allocating with calloc.
  int d = 4;
  int* p4 = calloc(1, sizeof(int));
  *(p4 + 0) = d;
  printf("d: %d, *p4: %d, p4[0]: %d, *(p4 + 0): %d, 0[p4]: %d\n", d, *p4, p4[0], *(p4 + 0), 0[p4]);
  printf("---\n");
  free(p3);

  // Note: calloc initializes each element (thus slower than malloc), plus no
  // need to multiply to determine total size.
}

static void HeapDoublePointers(void) {
  int a = 1;
  int** pp = malloc(sizeof(int));
  *pp = &a; // Point to the address of a.
  printf("**pp: %d\n", **pp);
  printf("   a: %d\n", a);
  **pp = 2; // Change the value of a.
  printf("**pp: %d\n", **pp);
  printf("   a: %d\n", a);
  printf("---\n");
  free(pp);
}

static void PointerArithmeticVsArraySyntax(void) {
  printf("---PointerArithmaticVsArraySyntax---\n");
  struct Person {
    int age;
    int level;
  };

  struct Person people_array[3];
  struct Person* people_pointer = people_array;
  struct Person* ppc = people_pointer;

  // Populate using array syntax.
  for (int i = 0; i < 3; i++) {
    people_array[i].age = i;
    people_array[i].level = i;
  }

  // Print using all syntaxes for access.
  ppc = people_pointer;
  for (int i = 0; i < 3; i++) {
    struct Person pa = people_array[i];
    printf("  pa.age: %d,   pa.level: %d\n", pa.age, pa.level);
    struct Person pp = *(people_pointer + i);
    printf("  pp.age: %d,   pp.level: %d\n", pp.age, pp.level);
    printf("ppc->age: %d, ppc->level: %d\n", ppc->age, ppc->level);
    ppc++;
  }
  printf("--\n");

  // Populate using pointer arithmetic syntax and dereferencing with *.
  for (int i = 0; i < 3; i++) {
    (*(people_pointer + i)).age = i * 2;
    (*(people_pointer + i)).level = i * 2;
  }

  // Print using all syntaxes for access.
  ppc = people_pointer;
  for (int i = 0; i < 3; i++) {
    struct Person pa = people_array[i];
    printf("  pa.age: %d,   pa.level: %d\n", pa.age, pa.level);
    struct Person pp = *(people_pointer + i);
    printf("  pp.age: %d,   pp.level: %d\n", pp.age, pp.level);
    printf("ppc->age: %d, ppc->level: %d\n", ppc->age, ppc->level);
    ppc++;
  }
  printf("--\n");

  // Populate using pointer arithmetic syntax and dereferencing with ->.
  for (int i = 0; i < 3; i++) {
    (people_pointer + i)->age = i * 3;
    (people_pointer + i)->level = i * 3;
  }

  // Print using all syntaxes for access.
  ppc = people_pointer;
  for (int i = 0; i < 3; i++) {
    struct Person pa = people_array[i];
    printf("  pa.age: %d,   pa.level: %d\n", pa.age, pa.level);
    struct Person pp = *(people_pointer + i);
    printf("  pp.age: %d,   pp.level: %d\n", pp.age, pp.level);
    printf("ppc->age: %d, ppc->level: %d\n", ppc->age, ppc->level);
    ppc++;
  }
  printf("--\n");

  printf("---\n");
}

int main(void) {
  StackPointers();
  HeapPointers();
  HeapDoublePointers();
  PointerArithmeticVsArraySyntax();
  return 0;
}
