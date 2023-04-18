// Exercise 1.2. Experiment to find out what happens when printf's argument
// string contains \c, where c is some character not listed above.

// On macOS, using clang:
// $ clang 1_2_hello_backslash_c.c
// $ ./a.out
// Outputs: hello, cworld

#include <stdio.h>

main() {
  // Generates compiler warning:
  // unknown escape sequence '\c' [-Wunknown-escape-sequence]
  printf("hello, \cworld\n");
}
