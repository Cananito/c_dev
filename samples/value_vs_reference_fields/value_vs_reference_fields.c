#include <stdio.h>
#include <stdlib.h>

struct MyStruct {
  int myInt;
  int* myIntPointer;
};

static void PrintAndMutateFieldsOfCopyOfStruct(struct MyStruct ms) {
  printf("--- PrintAndMutateFieldsOfCopyOfStruct ---\n");
  printf("Struct address: %p\n", &ms);
  printf("Struct's myInt address: %p\n", &(ms.myInt));
  printf("Struct's myInt value: %i\n", ms.myInt);
  ms.myInt = 2;
  printf("Struct's myInt value: %i\n", ms.myInt);
  printf("Struct's myIntPointer address: %p\n", &(ms.myIntPointer));
  printf("Struct's myIntPointer value address: %p\n", &(*(ms.myIntPointer)));
  printf("Struct's myIntPointer value: %i\n", *(ms.myIntPointer));
  ms.myIntPointer[0] = 3;
  printf("Struct's myIntPointer value: %i\n", *(ms.myIntPointer));
}

static void PrintFieldsOfCopyOfStruct(struct MyStruct ms) {
  printf("--- PrintFieldsOfCopyOfStruct ---\n");
  printf("Struct address: %p\n", &ms);
  printf("Struct's myInt address: %p\n", &(ms.myInt));
  printf("Struct's myInt value: %i\n", ms.myInt);
  printf("Struct's myIntPointer address: %p\n", &(ms.myIntPointer));
  printf("Struct's myIntPointer value address: %p\n", &(*(ms.myIntPointer)));
  printf("Struct's myIntPointer value: %i\n", *(ms.myIntPointer));
}

int main() {
  int* p = calloc(1, sizeof(int));
  p[0] = 2;

  struct MyStruct ms = { .myInt = 1, .myIntPointer = p };
  printf("--- main ---\n");
  printf("Struct address: %p\n", &ms);
  printf("Struct's myInt address: %p\n", &(ms.myInt));
  printf("Struct's myInt value: %i\n", ms.myInt);
  printf("Struct's myIntPointer address: %p\n", &(ms.myIntPointer));
  printf("Struct's myIntPointer value address: %p\n", &(*(ms.myIntPointer)));
  printf("Struct's myIntPointer value: %i\n", *(ms.myIntPointer));

  PrintAndMutateFieldsOfCopyOfStruct(ms);
  printf("--- main, again ---\n");
  printf("Struct's myInt value: %i\n", ms.myInt);
  printf("Struct's myIntPointer value: %i\n", *(ms.myIntPointer));

  free(p);
  PrintFieldsOfCopyOfStruct(ms); // myIntPointer value is garbage.

  return 0;
}
