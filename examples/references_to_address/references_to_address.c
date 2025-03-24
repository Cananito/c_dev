#include <stdio.h>
#include <stdlib.h>

static int IsUniquelyReferenced(void* p) {
  // TODO!
  return 0;
}

static int NumberOfReferences(void* p) {
  // TODO!
  return 0;
}

int main(void) {
  int *first = malloc(4);
  printf("1. IsUniquelyReferenced: %d\n", IsUniquelyReferenced(first));
  printf("1. NumberOfReferences: %d\n", NumberOfReferences(first));

  int *second = first;
  printf("2. IsUniquelyReferenced: %d\n", IsUniquelyReferenced(second));
  printf("2. NumberOfReferences: %d\n", NumberOfReferences(second));

  int *third = second;
  printf("3. IsUniquelyReferenced: %d\n", IsUniquelyReferenced(third));
  printf("3. NumberOfReferences: %d\n", NumberOfReferences(third));

  free(first);

  return 0;
}
