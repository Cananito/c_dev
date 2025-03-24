#include <stdio.h>
#include <stdlib.h>

static void DoublePointerHeterogeneousStorage(void) {
  void** storage = malloc(2 * sizeof(void*));
  int a = 7;
  storage[0] = &a;
  storage[1] = "abc";
  printf("storage[0]: %d\n", *(int*)storage[0]);
  printf("storage[1]: %s\n", (char*)storage[1]);
  free(storage);
  printf("---\n");
}

static void SinglePointerHeterogeneousStorage(void) {
  void* storage = malloc(2 * sizeof(void));
  int a = 7;
  ((int*)storage)[0] = a;
  ((char**)storage)[1] = "abc";
  printf("storage[0]: %d\n", ((int*)storage)[0]);
  printf("storage[1]: %s\n", ((char**)storage)[1]);
  free(storage);
  printf("---\n");
}

static void StackVoidPointer(void) {
  int a = 7;
  void* p = &a;
  printf("*(int*)p: %d\n", *(int*)p);
  printf("((int*)p)[0]: %d\n", ((int*)p)[0]);
  printf("---\n");
}

static void HeapVoidPointer(void) {
  int a = 7;
  void* p = malloc(sizeof(void*));
  *(int*)p = a;
  // Alternative: ((int*)p)[0] = a;
  // Alternative: *((int*)p + 0) = a;
  printf("*(int*)p: %d\n", *(int*)p);
  printf("((int*)p)[0]: %d\n", ((int*)p)[0]);
  free(p);
  printf("---\n");
}

int main(void) {
  DoublePointerHeterogeneousStorage();
  SinglePointerHeterogeneousStorage();
  StackVoidPointer();
  HeapVoidPointer();
  return 0;
}
