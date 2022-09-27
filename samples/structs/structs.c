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
  // NOTE: Sizes based on 64-bit CPU.

  struct PaddedStruct { // Total: 24 bytes.
    char first; // 1 byte.
    // 3 bytes padding.
    double second; // 8 bytes.
    float third; // 4 bytes.
    // 4 bytes padding.
  } ps = { .first = 'a', .second = 1.1, .third = 1.1 };
  printf("Size of ps: %lu\n", sizeof(ps));
  printf("Address of ps: %p\n", &ps);
  printf("Address of ps.first: %p\n", &(ps.first));
  printf("Address of ps.second: %p\n", &(ps.second));
  printf("Address of ps.third: %p\n", &(ps.third));
  printf("Value of ps.first: %c\n", ps.first);
  printf("Value of ps.second: %lf\n", ps.second);
  printf("Value of ps.third: %f\n", ps.third);

  struct NoPaddingStruct { // Total: 8 bytes.
    char first; // 1 byte.
    char second; // 1 byte.
    char third; // 1 byte.
    char fourth; // 1 byte.
    float fifth; // 4 bytes.
  } nps = { .first = 'a', .second = 'b', .third = 'c', .fourth = 'd', .fifth = 1.1 };
  printf("Size of nps: %lu\n", sizeof(nps));
  printf("Address of nps: %p\n", &nps);
  printf("Address of nps.first: %p\n", &(nps.first));
  printf("Address of nps.second: %p\n", &(nps.second));
  printf("Address of nps.third: %p\n", &(nps.third));
  printf("Address of nps.fourth: %p\n", &(nps.fourth));
  printf("Address of nps.fifth: %p\n", &(nps.fifth));
  printf("Value of nps.first: %c\n", nps.first);
  printf("Value of nps.second: %c\n", nps.second);
  printf("Value of nps.third: %c\n", nps.third);
  printf("Value of nps.fourth: %c\n", nps.fourth);
  printf("Value of nps.fifth: %f\n", nps.fifth);
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
