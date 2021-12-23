#include <stdio.h>
#include <stdlib.h>

#include "unit_testing.h"

_Pragma("clang assume_nonnull begin")

void assert_true(int condition_result, char *failure_message) {
  if (condition_result != 1) {
    printf("%s\n", failure_message);
    exit(1);
  }
}

_Pragma("clang assume_nonnull end")
