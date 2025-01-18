#include "list.h"

#include <signal.h>
#include <stdint.h>

int32_t Int32List_r_get(struct Int32List_r list, size_t index) {
  if (index >= 0 && index < list.length) {
    return list.items[index];
  }
  raise(SIGTRAP);
  return 0;
}
