#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Flexible Array Members | C Programming Tutorial
// https://www.youtube.com/watch?v=1h27lYe15iI

// https://en.wikipedia.org/wiki/Flexible_array_member

struct Employee {
  int id;
  int salary;
  char name[];
};

// Compiler error to have a struct with a flexible array as its only memeber:
// struct Data {
//   int array[];
// };

int main(void) {
  printf("sizeof(struct Employee): %zu\n", sizeof(struct Employee));
  printf("sizeof(int): %zu\n", sizeof(int));
  // Size of the struct is int + int (8), ignoring the flexible array.

  // If we had char* instead of the flexible array, the struct would be bigger.

  // Prior to being a language feature, people would do:
  // char name[1];
  // or
  // char name[0];

  // With that said, the size of the struct doesn't matter since the idea is to
  // heap allocate a struct big enough to accomodate the size of the array.

  // Employee with name "John\0" (5 bytes).
  struct Employee *e1 = malloc(sizeof(struct Employee) + 5);
  e1->id = 123;
  e1->salary = 150000;
  strcpy(e1->name, "John");
  printf("sizeof(e1): %zu\n", sizeof(e1));
  printf("e1->id: %d\n", e1->id);
  printf("e1->salary: %d\n", e1->salary);
  printf("e1->name: %s\n", e1->name);
  // Compiler error if we try to print the size of the flexible array.
  // printf("sizeof(e1->name): %zu\n", sizeof(e1->name));
  free(e1);

  // Compiler error if we try to stack allocate the struct and set the flexible
  // array.
  // struct Employee e2 = { .id = 456, .salary = 123456, .name = "Johanna" };
  struct Employee e2 = { .id = 456, .salary = 123456 };
  printf("sizeof(e2): %zu\n", sizeof(e2));
  printf("e2->id: %d\n", e2.id);
  printf("e2->salary: %d\n", e2.salary);
  // e2.name is garbage here:
  printf("e2->name: %s\n", e2.name);

  return 0;
}
