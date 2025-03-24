#include <stdio.h>

static int sum(int a, int b) {
  return a + b;
}

static int substract(int a, int b) {
  return a - b;
}

static void WithAddressOfOperator(void) {
  printf("--- WithAddressOfOperator\n");

  int (*math_func)(int, int);
  int result;

  math_func = &sum;
  result = (*math_func)(1, 1);
  printf("Sum: %d\n", result);

  math_func = &substract;
  result = (*math_func)(2, 1);
  printf("Substract: %d\n", result);
}

static void WithoutAddressOfOperator(void) {
  printf("--- WithoutAddressOfOperator\n");

  int (*math_func)(int, int);
  int result;

  math_func = sum;
  result = math_func(1, 1);
  printf("Sum: %d\n", result);

  math_func = substract;
  result = math_func(2, 1);
  printf("Substract: %d\n", result);
}

struct MyStruct {
  int (*math_func)(int, int);
};
static void ViaStruct(void) {
  printf("--- ViaStruct\n");

  struct MyStruct ms = { .math_func = sum };
  int result = ms.math_func(1, 1);
  printf("Sum: %d\n", result);

  ms.math_func = substract;
  result = ms.math_func(2, 1);
  printf("Substract: %d\n", result);
}

int main(void) {
  WithAddressOfOperator();
  WithoutAddressOfOperator();
  ViaStruct();
  return 0;
}
