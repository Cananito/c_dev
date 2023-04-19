// Exercise 1.3. Modify the temperature conversion program to print a heading
// above the table.

// On macOS, using clang:
// $ clang 1_3_fahr_to_celsius_with_table_header.c
// $ ./a.out

#include <stdio.h>

main() {
  int const lower = 0;
  int const upper = 300;
  int const step = 20;
  float fahr = lower;
  printf("Fahrenheit Celsius\n");
  while (fahr <= upper ) {
    float const celsius = (fahr - 32.0) * (5.0 / 9.0) ;
    printf("%10.0f %7.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
