#include "string_r.h"

bool String_r_has_prefix(struct String_r string, struct String_r prefix) {
  return false;
}

bool String_r_has_suffix(struct String_r string, struct String_r suffix) {
  return false;
}

struct String_r String_r_prepend(struct String_r string,
                                 struct String_r prepend) {
  return (struct String_r){ .chars = string.chars, .length = string.length };
}

struct String_r String_r_append(struct String_r string,
                                struct String_r append) {
  return (struct String_r){ .chars = string.chars, .length = string.length };
}

size_t String_r_find_substring(struct String_r string,
                               struct String_r substring) {
  return 0;
}
