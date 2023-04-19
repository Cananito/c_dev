// Exercise 1.5. Modify the temperature conversion program to print the table in
// reverse order, that is, from 300 degrees to 0.

// On macOS, using clang:
// $ clang 1_5_fahr_to_celsius_for_loop_reverse.c
// $ ./a.out

#include <stdio.h>

main() {
  for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%3d %6.1f\n", fahr, (fahr - 32) * (5.0 / 9.0));
  }
}
