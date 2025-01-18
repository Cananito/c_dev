#include <stdbool.h>
#include <stddef.h>

struct String_r {
  char* chars;
  size_t length;
};

bool String_r_has_prefix(struct String_r string, struct String_r prefix);
bool String_r_has_suffix(struct String_r string, struct String_r suffix);
struct String_r_prepend(struct String_r string, struct String_r prepend);
struct String_r_append(struct String_r string, struct String_r append);
size_t String_r_find_substring(struct String_r string,
                               struct String_r substring);
