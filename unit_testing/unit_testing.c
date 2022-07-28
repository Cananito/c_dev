#include <stdio.h>
#include <stdlib.h>

#include "unit_testing.h"

void assert_true(int condition_result, char* failure_message) {
  if (condition_result != 1) {
    if (failure_message == NULL) {
      printf("Assert failed! Specify `failure_message` for better diagnostics."
             "\n");
    } else {
      printf("%s\n", failure_message);
    }
    exit(1);
  }
}
