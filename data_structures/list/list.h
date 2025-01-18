#include <stddef.h>
#include <stdint.h>

struct Int32List_r {
  int32_t* items;
  size_t length;
  size_t capacity;
};
int32_t Int32List_r_get(struct Int32List_r list, size_t index);
