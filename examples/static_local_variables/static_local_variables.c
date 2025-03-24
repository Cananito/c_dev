#include <stdio.h>

static void IncrementAndPrintCounter(void) {
  static int counter = 0;
  counter++;
  printf("Counter: %d\n", counter);
}

int main(void) {
  IncrementAndPrintCounter();
  IncrementAndPrintCounter();
  IncrementAndPrintCounter();
  IncrementAndPrintCounter();
  IncrementAndPrintCounter();
  return 0;
}
