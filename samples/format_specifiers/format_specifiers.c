#include <stdio.h>

static void Characters(void) {
  char a_char = 'a';
  printf("%%c: %c (char)\n", a_char);
}

static void Strings(void) {
  char* a_string = "Hello";
  printf("%%s: %s (char*)\n", a_string);
  printf("%%.*s: %.*s (char*, only first 4 characters)\n", 4, a_string);
}

static void Integers(void) {
  int an_int = 1;
  unsigned int an_unsigned_int = 2;
  short a_short = 3;
  unsigned short an_unsigned_short = 4;
  long a_long = 5;
  unsigned long an_unsigned_long = 6;
  long long a_long_long = 7;
  unsigned long long an_unsigned_long_long = 8;
  int an_int_to_represent_differently = 123;

  printf("%%d: %d (int)\n", an_int);
  printf("%%i: %i (unsigned int)\n", an_unsigned_int);
  printf("%%u: %u (unsigned int)\n", an_unsigned_int);
  printf("%%hi: %hi (short)\n", a_short);
  printf("%%hu: %hu (unsigned short)\n", an_unsigned_short);
  printf("%%ld: %ld (long)\n", a_long);
  printf("%%li: %li (long)\n", a_long);
  printf("%%lu: %lu (unsigned long)\n", an_unsigned_long);
  printf("%%lli: %lli (long long)\n", a_long_long);
  printf("%%lld: %lld (long long)\n", a_long_long);
  printf("%%llu: %llu (unsigned long long)\n", an_unsigned_long_long);

  printf("%%o: %o (int, octal representation)\n", an_int_to_represent_differently);
  printf("%%x: %x (int, hexadecimal representation)\n", an_int_to_represent_differently);
  printf("%%X: %X (int, hexadecimal representation)\n", an_int_to_represent_differently);
}

static void Floats(void) {
  float a_float = 3.14;
  double a_double = 6.28;
  long double a_long_double = 12.56;

  printf("%%f: %f (float)\n", a_float);
  printf("%%e: %e (float, scientific notation)\n", a_float);
  printf("%%E: %E (float, scientific notation)\n", a_float);
  printf("%%g: %g (float, simplified scientific notation)\n", a_float);
  printf("%%G: %G (float, simplified scientific notation)\n", a_float);
  printf("%%lf: %lf (double)\n", a_double);
  printf("%%Lf: %Lf (long double)\n", a_long_double);
}

static void Pointers(void) {
  int an_int = 1;
  int* a_pointer = &an_int;
  printf("%%p: %p (pointer)\n", a_pointer);
}

static void Misc(void) {
  printf("%%%%: %% (escape the %% character)\n");

  int n;
  printf("%%n: %n (capture length up to specifier)\n", &n);
  printf("n: %d\n", n);
}

int main(void) {
  Characters();
  Strings();
  Integers();
  Floats();
  Pointers();
  Misc();
  return 0;
}
