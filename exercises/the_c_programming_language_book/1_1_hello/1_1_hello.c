// Exercise 1-1. Run the "hello, world" program on your system. Experiment with
// leaving out parts of the program, to see what error messages you get.

// On macOS, using clang:
// $ clang 1_1_hello.c
// $ ./a.out

// Include information about standard library.
#include <stdio.h>

// Define a function named `main` that receives no argument values.
main() {
  // Statements of `main` are enclosed in braces.

  // `main` calls library function `printf` to print this sequence of
  // characters; `\n` represents the newline character.
  printf("hello, world\n");
}
