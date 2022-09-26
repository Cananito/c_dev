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
  pbr->value = 4; // Same as `(*pbr).value`.
  printf("pbr.value after: %d\n", pbr->value);
}

void DemonstrateMemoryLayout(void) {
  struct Something {
    char first;
    float second;
    double third;
  } s = { .first = 'a', .second = 11111.11111, .third = 11111111111111.11111111111111 };
  // TODO: Not the values I was expecting. Figure out why.
  printf("Address of s: %p\n", &s);
  printf("Address of s.first: %p\n", &(s.first));
  printf("Address of s.second: %p\n", &(s.second));
  printf("Address of s.third: %p\n", &(s.third));
  printf("Value of s.first: %c\n", s.first);
  printf("Value of s.second: %f\n", s.second);
  printf("Value of s.third: %lf\n", s.third);
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

  printf("---\n");
  DemonstrateMemoryLayout();

  return 0;
}
