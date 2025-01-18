#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void test_int32_list(void) {
  int items[5] = { 1, 2, 3, 4, 5 };
  struct Int32List_r list = { .items = items, .length = 5, .capacity = 0 };
  // TODO: Use assert_true from unit_test.h instead!!!
  if (Int32List_r_get(list, 0) != 1) {
    printf("Tests failed.\n");
    exit(1);
  }
  int32_t r = Int32List_r_get(list, 7);
  printf(">>> %d\n", r);
}

int main() {
  printf("Starting tests.\n");
  test_int32_list();
  printf("Tests succeeded!\n");
  return 0;
}
