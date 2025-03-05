#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static const int InitialBufferCapacity = 4;


struct Int32List_r {
  int32_t* items;
  size_t length;
  size_t capacity;
};
int32_t Int32List_r_get(struct Int32List_r list, size_t index) {
  if (index >= 0 && index < list.length) {
    return list.items[index];
  }
  raise(SIGTRAP);
  return 0;
}


struct IntArray_r {
  int* items;
  size_t count;
  size_t capacity;
};
void IntArray_r_init(struct IntArray_r* int_array) {
  int_array->items = malloc(InitialBufferCapacity * sizeof(int));
  int_array->count = 0;
  int_array->capacity = InitialBufferCapacity;
}
void IntArray_r_append(struct IntArray_r* int_array, int item) {
  size_t current_capacity = int_array->capacity;
  if (int_array->count >= current_capacity) {
    size_t new_capacity = current_capacity == 0 ?
                          InitialBufferCapacity : current_capacity * 2;
    int_array->items = realloc(int_array->items, new_capacity * sizeof(int));
    int_array->capacity = new_capacity;
  }
  int_array->items[int_array->count] = item;
  int_array->count++;
}
void IntArray_r_free_items(struct IntArray_r* int_array) {
  free(int_array->items);
}
void IntArray_r_print(struct IntArray_r* int_array) {
  if (int_array->count == 0) {
    printf("[ ]\n");
    return;
  }
  printf("[ ");
  for (size_t i = 0; i < int_array->count; i++) {
    printf("%d, ", int_array->items[i]);
  }
  printf("]\n");
}


struct FloatArray {
  float* items;
  size_t count;
  size_t capacity;
};
void FloatArray_r_init(struct FloatArray* float_array) {
  float_array->items = malloc(InitialBufferCapacity * sizeof(int));
  float_array->count = 0;
  float_array->capacity = InitialBufferCapacity;
}
void FloatArray_r_append(struct FloatArray* float_array, float item) {
  size_t current_capacity = float_array->capacity;
  if (float_array->count >= current_capacity) {
    size_t new_capacity = current_capacity == 0 ?
                          InitialBufferCapacity : current_capacity * 2;
    float_array->items = realloc(float_array->items,
                                 new_capacity * sizeof(float));
    float_array->capacity = new_capacity;
  }
  float_array->items[float_array->count] = item;
  float_array->count++;
}
void FloatArray_r_free_items(struct FloatArray* float_array) {
  free(float_array->items);
}
void FloatArray_r_print(struct FloatArray* float_array) {
  if (float_array->count == 0) {
    printf("[ ]\n");
    return;
  }
  printf("[ ");
  for (size_t i = 0; i < float_array->count; i++) {
    printf("%f, ", float_array->items[i]);
  }
  printf("]\n");
}


int main(void) {
  int i32l_items[5] = { 1, 2, 3, 4, 5 };
  struct Int32List_r i32l = { .items = i32l_items, .length = 5, .capacity = 0 };
  printf("Int32List_r_get 3: %d\n", Int32List_r_get(i32l, 3));
  //printf("Int32List_r_get 7: %d\n", Int32List_r_get(i32l, 7));

  struct IntArray_r ia;
  IntArray_r_init(&ia);
  IntArray_r_append(&ia, 7);
  IntArray_r_append(&ia, 8);
  IntArray_r_append(&ia, 9);
  IntArray_r_print(&ia);
  IntArray_r_free_items(&ia);

  struct FloatArray fa;
  FloatArray_r_init(&fa);
  FloatArray_r_append(&fa, 3.0);
  FloatArray_r_append(&fa, 4.0);
  FloatArray_r_append(&fa, 5.0);
  FloatArray_r_print(&fa);
  FloatArray_r_free_items(&fa);

  return 0;
}
