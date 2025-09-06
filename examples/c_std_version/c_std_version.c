#include <stdio.h>

int main(void) {
// To get a list of all possible -std values, compile with a bogus value like:
// gcc -std=c7 c_std_version.c

#ifdef __STDC__
  printf("ANSI C / ISO C\n");
#else
  printf("K&R C\n");
#endif // __STDC__

#ifdef __STDC_VERSION__
  long c_std_version = __STDC_VERSION__;
  if (c_std_version == 199901L) {
    // Compile with: gcc -std=c99 c_std_version.c
    printf("C99\n");
  } else if (c_std_version == 201112L) {
    // Compile with: gcc -std=c11 c_std_version.c
    printf("C11\n");
  } else if (c_std_version == 201710L) {
    // Compile with: gcc -std=c17 c_std_version.c
    printf("C17\n");
  } else if (c_std_version == 202311L) {
    // Compile with: gcc -std=c23 c_std_version.c
    printf("C23\n");
  } else {
    printf("Unknown C standard's version.\n");
  }
  printf("__STDC_VERSION__ defined as %li\n", c_std_version);
#else
  // Compile with: gcc -std=c89 c_std_version.c
  printf("__STDC_VERSION__ not defined, can't know the C standard's version.\n");
#endif // __STDC_VERSION__

  return 0;
}
