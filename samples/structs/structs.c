#include <stdio.h>

struct MyStruct {
  int value;
};
// Note: when not using typdef, each reference to the type must include the
// struct keyword.

void PassByValue(struct MyStruct pbv) {
  printf("pbv.value before: %d\n", pbv.value);
  pbv.value = 4;
  printf("pbv.value after: %d\n", pbv.value);
}

void PassByReference(struct MyStruct* pbr) {
  printf("pbr.value before: %d\n", pbr->value);
  pbr->value = 4;
  printf("pbr.value after: %d\n", pbr->value);
}

int main(void) {
  struct MyStruct a;

  printf("a.value before pass by value: %d\n", a.value);
  PassByValue(a);
  printf("a.value after pass by value: %d\n", a.value);

  printf("---\n");

  printf("a.value before pass by reference: %d\n", a.value);
  PassByReference(&a);
  printf("a.value after pass by reference: %d\n", a.value);

  return 0;
}
