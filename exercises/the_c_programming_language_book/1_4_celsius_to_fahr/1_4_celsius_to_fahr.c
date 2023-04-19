// Exercise 1.4. Write a program to print the corresponding Celsius to
// Fahrenheit table.

// On macOS, using clang:
// $ clang 1_4_celsius_to_fahr.c
// $ ./a.out

#include <stdio.h>

main() {
  int const lower = 0;
  int const upper = 300;
  int const step = 20;
  float celsius = lower;
  printf("Celsius Fahrenheit\n");
  while (celsius <= upper ) {
    float const fahr = (celsius * (9.0 / 5.0)) + 32.0;
    printf("%7.0f %10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
