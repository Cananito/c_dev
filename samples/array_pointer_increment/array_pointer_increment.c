#include <stdio.h>

int main(void) {
  int array[5] = { 1, 2, 3, 4, 5, };

  // Note: Casting to size_t to print address in decimal instead of hex.

  // Address of 1st element.
  printf("Address of array:     %lu\n", (size_t)(array));
  // Increases by 4 bytes, int's size.
  printf("Address of array + 1: %lu\n", (size_t)(array + 1));
  // Get value by dereferencing, same as array[1]. Gives us 2.
  printf("Value of *(array + 1): %d\n", *(array + 1));
  
  // Address of array as a whole.
  printf("Address of &array:     %lu\n", (size_t)(&array));
  // Increases by 20 bytes: 5 elements times int's size.
  printf("Address of &array + 1: %lu\n", (size_t)(&array + 1));
  // Get value by dereferencing. Gives us garbage.
  printf("Value of **(&array + 1): %d\n", **(&array + 1));

  // Explanation: Doing pointer arithmetic on an array works on individual
  // elements (like an int* in this case), whereas doing it using the address-of
  // operator works on the entire set of elements.

  // The same applies with nested arrays:

  int matrix[3][5] = {
    { 1, 2, 3, 4, 5, },
    { 6, 7, 8, 9, 10, },
    { 11, 12, 13, 14, 15 },
  };

  // Address of 1st element of 2nd row.
  printf("Address of matrix[1]:     %lu\n", (size_t)(matrix[1]));
  // Increases by 4 bytes, int's size.
  printf("Address of matrix[1] + 1: %lu\n", (size_t)(matrix[1] + 1));
  // Get value by dereferencing, same as matrix[1][1]. Gives us 7.
  printf("Value of *(matrix[1] + 1): %d\n", *(matrix[1] + 1));
  
  // Address of 2nd row as a whole.
  printf("Address of &array[1]:     %lu\n", (size_t)(&matrix[1]));
  // Increases by 20 bytes: 5 elements times int's size.
  printf("Address of &array[1] + 1: %lu\n", (size_t)(&matrix[1] + 1));
  // Get value by dereferencing. Gives us 11.
  printf("Value of **(&matrix[1] + 1): %d\n", **(&matrix[1] + 1));

  return 0;
}
