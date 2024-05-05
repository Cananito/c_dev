#include <stdio.h>
#include <stdlib.h>

// TODO: Create non-init arrays with stack allocated items buffer.
// (How to handle append and/or capacity increase?)

static const int InitialBufferCapacity = 4;

typedef struct {
  int* items;
  size_t count;
  size_t capacity;
} IntArray;

static void IntArray_r_init(IntArray* int_array) {
  int_array->items = malloc(InitialBufferCapacity * sizeof(int));
  int_array->count = 0;
  int_array->capacity = InitialBufferCapacity;
}

static void IntArray_r_append(IntArray* int_array, int item) {
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

static void IntArray_r_free_items(IntArray* int_array) {
  free(int_array->items);
}

static void IntArray_r_print(IntArray* int_array) {
  if (int_array->count == 0) {
    printf("[ ]\n");
    return;
  }
  printf("[ ");
  for (int i = 0; i < int_array->count; i++) {
    printf("%d, ", int_array->items[i]);
  }
  printf("]\n");
}


typedef struct {
  float* items;
  size_t count;
  size_t capacity;
} FloatArray;

static void FloatArray_r_init(FloatArray* float_array) {
  float_array->items = malloc(InitialBufferCapacity * sizeof(int));
  float_array->count = 0;
  float_array->capacity = InitialBufferCapacity;
}

static void FloatArray_r_append(FloatArray* float_array, float item) {
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

static void FloatArray_r_free_items(FloatArray* float_array) {
  free(float_array->items);
}

static void FloatArray_r_print(FloatArray* float_array) {
  if (float_array->count == 0) {
    printf("[ ]\n");
    return;
  }
  printf("[ ");
  for (int i = 0; i < float_array->count; i++) {
    printf("%f, ", float_array->items[i]);
  }
  printf("]\n");
}


int main(void) {
  IntArray ia;
  IntArray_r_init(&ia);
  IntArray_r_append(&ia, 7);
  IntArray_r_append(&ia, 8);
  IntArray_r_append(&ia, 9);
  IntArray_r_print(&ia);
  IntArray_r_free_items(&ia);

  FloatArray fa;
  FloatArray_r_init(&fa);
  FloatArray_r_append(&fa, 3.0);
  FloatArray_r_append(&fa, 4.0);
  FloatArray_r_append(&fa, 5.0);
  FloatArray_r_print(&fa);
  FloatArray_r_free_items(&fa);

  return 0;
}
