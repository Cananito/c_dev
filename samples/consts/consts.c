#include <stdio.h>

static void Const(void) {
  printf("---Const---\n");
  const int a = 1; // Same as `int const`.
  // a = 2; // Can't re-assign a.
  printf(" a: %d\n", a);
  printf("---\n");
}

static void PointerToVariable(void) {
  printf("---Pointer to variable---\n");

  int a = 1;
  int b = 2;

  int* p = &a;
  printf("*p: %d\n", *p);

  p = &b;
  printf("*p: %d\n", *p);
  printf(" b: %d\n", b);

  *p = 3;
  printf("*p: %d\n", *p);
  printf(" b: %d\n", b);

  printf("---\n");
}

static void PointerToConstant(void) {
  printf("---Pointer to constant---\n");

  int a = 1;
  int b = 2;

  int const* icp = &a; // Same as `const int*`.
  printf("*icp: %d\n", *icp);

  icp = &b;
  printf("*icp: %d\n", *icp);

  // *icp = 3; // Can't change the value of what it points to.

  printf("---\n");
}

static void ConstantPointerToVariable(void) {
  printf("---Constant pointer to variable---\n");

  int a = 1;
  int b = 2;

  int* const ipc = &a;
  printf("*ipc: %d\n", *ipc);

  // ipc = &b; // Can't re-assign ipc.

  printf(" a: %d\n", a);
  *ipc = 3;
  printf("*ipc: %d\n", *ipc);
  printf(" a: %d\n", a);

  printf("---\n");
}

static void ConstantPointerToConstant(void) {
  printf("---Constant pointer to constant---\n");

  int a = 1;
  int b = 2;

  int const* const cipc = &a; // Same as `const int* const`.
  printf("*cipc: %d\n", *cipc);

  // cipc = &b; // Can't re-assign cipc.

  // *cipc = 3; // Can't change the value of what it points to.

  printf("---\n");
}

static void ConstantPointerToConstantPointerToConstant(void) {
  printf("---Constant pointer to constant pointer to constant---\n");

  int a = 1;
  int const* p1 = &a;

  int const* const* const pp = &p1; // Same as `?`.
  printf("*pp: %p\n", *pp);
  printf("**pp: %d\n", **pp);

  int b = 2;
  int const* p2 = &a;
  // pp = &p2; // Can't re-assign pp.
  // *pp = &b; // Can't do.
  // **pp = 3; // Can't do.

  printf("---\n");
}

static void PointerToVariableDeclaredAsConst(void) {
  printf("---Pointer to variable declared as const---\n");
  const int a = 1;
  int* p = &a; // Compiler warning (-Wincompatible-pointer-types-discards-qualifiers).
  printf("*p: %d\n", *p);
  printf(" a: %d\n", a);
  *p = 2; // Shady!
  printf("*p: %d\n", *p); // 2 (changes)
  printf(" a: %d\n", a); // 1 (doesn't change)
  // Clang behavior. Unclear whether all compilers behave the same way.
  printf("---\n");
}

int main(void) {
  Const();

  PointerToVariable();
  PointerToConstant();
  ConstantPointerToVariable();
  ConstantPointerToConstant();
  ConstantPointerToConstantPointerToConstant();

  PointerToVariableDeclaredAsConst();

  return 0;
}
