#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a;
  int b;
} AnotherStruct;

typedef struct {
  int const* int_array;
  int int_array_count;
  AnotherStruct another_struct;
} MyStruct;

void MyStruct_print(MyStruct ms) {
  printf("MyStruct: {\n");
  printf("  int_array: [ ");
  for (int i = 0; i < ms.int_array_count; i++) {
    printf("%d, ", ms.int_array[i]);
  }
  printf("]\n");
  printf("  int_array_count: %d\n", ms.int_array_count);
  printf("  another_struct: {\n");
  printf("    int a: %d\n", ms.another_struct.a);
  printf("    int b: %d\n", ms.another_struct.b);
  printf("  }\n");
  printf("}\n");
}

int main(void) {
  int arr[] = { 1, 2, 3 };
  MyStruct ms = {
    .int_array = arr,
    .int_array_count = 3,
    .another_struct = {
      .a = 4,
      .b = 5,
    },
  };
  MyStruct_print(ms);
  return 1;
}
