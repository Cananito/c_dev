#include <stdio.h>
#include <stdlib.h>

static int* ArrayOfLocalInts() {
  int a = 1;
  int b = 2;
  int c = 3;
  int* result = calloc(3, sizeof(int));
  result[0] = a;
  result[1] = b;
  result[2] = c;
  return result;
}

static int** ArrayOfPointersToLocalInts() {
  int a = 1;
  int b = 2;
  int c = 3;
  int** result = calloc(3, sizeof(int*));
  result[0] = &a;
  result[1] = &b;
  result[2] = &c;
  return result;
}

int main() {
  int* aoli = ArrayOfLocalInts();
  printf("Array of local ints:\n");
  printf("0: %i\n", aoli[0]);
  printf("1: %i\n", aoli[1]);
  printf("2: %i\n", aoli[2]);
  printf("All good!\n");
  free(aoli);

  printf("---\n");

  int** aoptli = ArrayOfPointersToLocalInts();
  printf("Array of pointers to local ints:\n");
  printf("0: %i\n", *aoptli[0]);
  printf("1: %i\n", *aoptli[1]);
  printf("2: %i\n", *aoptli[2]);
  printf("All garbage!\n");
  free(aoptli);

  return 0;
}
