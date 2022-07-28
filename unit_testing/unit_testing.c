#include <stdio.h>
#include <stdlib.h>

#include "unit_testing.h"

void assert_true(int condition_result, char* failure_message) {
  if (condition_result != 1) {
    // TODO: Check that failure_message isn't NULL.
    printf("%s\n", failure_message);
    exit(1);
  }
}
