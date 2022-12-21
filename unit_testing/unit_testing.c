#include <stdio.h>
#include <stdlib.h>

#include "unit_testing.h"

void assert_true(bool condition_result, char* failure_message) {
  if (condition_result == false) {
    printf("%s\n", failure_message);
    printf("Tests failed.\n");
    exit(1);
  }
}
