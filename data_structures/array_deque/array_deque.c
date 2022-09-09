#include "array_deque.h"

#include <stdlib.h>

// TODO: Add NULL checks.

// TODO: Make all functions thread safe.

struct ArrayDeque_r {
  void const** storage;
  int storage_size;
  int count;
  int first_element_index;
};

ArrayDeque_r* ArrayDeque_r_new(void) {
  ArrayDeque_r* array_deque = malloc(sizeof(ArrayDeque_r));
  int storage_size = 4;
  // TODO: Delay allocation until first enqueue?
  array_deque->storage = malloc(storage_size * sizeof(void const*));
  array_deque->storage_size = storage_size;
  array_deque->count = 0;
  array_deque->first_element_index = 0;
  return array_deque;
}

void ArrayDeque_r_free(ArrayDeque_r* array_deque) {
  free(array_deque->storage);
  free(array_deque);
}

int ArrayDeque_r_count(ArrayDeque_r const* array_deque) {
  return array_deque->count;
}

void const* ArrayDeque_r_get(ArrayDeque_r const* array_deque, int index) {
  // TODO: Do bounds check.
  if (array_deque->count == 0) {
    return (void const*)0;
  }
  // TODO: Adjust index.
  int adjustedIndex = index;
  return array_deque->storage[adjustedIndex];
 }

void const* ArrayDeque_r_get_last(ArrayDeque_r const* array_deque) {
  if (array_deque->count == 0) {
    return (void const*)0;
  }
  // TODO: Use correct index.
  return array_deque->storage[0];
}

void ArrayDeque_r_prepend(ArrayDeque_r* array_deque, void const* element) {
  int index = 0;
  int current_first_element_index = array_deque->first_element_index;
  if (current_first_element_index != 0) {
    index = current_first_element_index - 1;
  }
  // TODO: Adjust the index when current_first_element_index is 0.
  array_deque->storage[index] = element;
  array_deque->count++;
  array_deque->first_element_index = index;

  // TODO: Increase storage size if needed.
}

void ArrayDeque_r_append(ArrayDeque_r* array_deque, void const* element) {
  // TODO: Introduce last_element_index.
  array_deque->storage[array_deque->count] = element;
  array_deque->count++;

  // TODO: Increase storage size if needed.
}

void const* ArrayDeque_r_remove_first(ArrayDeque_r* array_deque) {
  if (array_deque->count == 0) {
    return (void const*)0;
  }

  void const* element = array_deque->storage[array_deque->first_element_index];
  array_deque->count--;
  array_deque->first_element_index++;
  // TODO: If count is 0, first_element_index = 0;

  // TODO: Decrease storage size if needed.

  return element;
}

void const* ArrayDeque_r_remove_last(ArrayDeque_r* array_deque) {
  if (array_deque->count == 0) {
    return (void const*)0;
  }

  // TODO: Introduce last_element_index.
  void const* element = array_deque->storage[array_deque->count - 1];
  array_deque->count--;

  // TODO: Decrease storage size if needed.

  return element;
}
