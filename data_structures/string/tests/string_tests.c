#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_r.h"

static void test_string_has_prefix(void) {
  char* string_chars = "Hello, world!";
  size_t string_length = strlen(string_chars);
  struct String_r string = { .chars = string_chars, .length = string_length };

  char* prefix_chars = "Hello";
  size_t prefix_length = strlen(prefix_chars);
  struct String_r prefix = { .chars = prefix_chars, .length = prefix_length };

  if (String_r_has_prefix(string, prefix) == true) {
    printf("Tests failed.\n");
    exit(1);
  }
}

int main() {
  printf("Starting tests.\n");
  test_string_has_prefix();
  printf("Tests succeeded!\n");
  return 0;
}
