#include "array_deque.h"

#include <stdlib.h>

// TODO: Add NULL checks.

// TODO: Make all functions thread safe.

struct ArrayDeque_r {
  void const** storage;
  int storage_size;
  int count;
  int first_element_index;
  int last_element_index;
};

#pragma mark - Private Functions

static int AdjustedIndex(ArrayDeque_r const*array_deque, int index) {
  int adjusted_index = index + array_deque->first_element_index;
  int storage_size = array_deque->storage_size;
  if (adjusted_index >= storage_size) {
    adjusted_index = adjusted_index - storage_size;
  }
  return adjusted_index;
}

static void IncrementFirstElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->count == 0 &&
      array_deque->last_element_index == array_deque->first_element_index) {
    should_match_indices = 1;
  }

  int temp_index = array_deque->first_element_index + 1;
  if (temp_index == array_deque->storage_size) {
    // Need to circle back to the start of the buffer.
    array_deque->first_element_index = 0;
  } else {
    array_deque->first_element_index = temp_index;
  }

  if (should_match_indices) {
    array_deque->last_element_index = array_deque->first_element_index;
  }
}

static void DecrementFirstElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->count == 0 &&
      array_deque->last_element_index == array_deque->first_element_index) {
    should_match_indices = 1;
  }

  if (array_deque->first_element_index == 0) {
    // Need to circle back to the end of the buffer.
    array_deque->first_element_index = array_deque->storage_size - 1;
  } else {
    array_deque->first_element_index--;
  }

  if (should_match_indices) {
    array_deque->last_element_index = array_deque->first_element_index;
  }
}

static void IncrementLastElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->count == 0 &&
      array_deque->first_element_index == array_deque->last_element_index) {
    should_match_indices = 1;
  }

  int temp_index = array_deque->last_element_index + 1;
  if (temp_index == array_deque->storage_size) {
    // Need to circle back to start of the buffer.
    array_deque->last_element_index = 0;
  } else {
    array_deque->last_element_index = temp_index;
  }

  if (should_match_indices) {
    array_deque->first_element_index = array_deque->last_element_index;
  }
}

static void DecrementLastElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->count == 0 &&
      array_deque->first_element_index == array_deque->last_element_index) {
    should_match_indices = 1;
  }

  if (array_deque->last_element_index == 0) {
    // Need to circle back to the end of the buffer.
    array_deque->last_element_index = array_deque->storage_size - 1;
  } else {
    array_deque->last_element_index--;
  }

  if (should_match_indices) {
    array_deque->first_element_index = array_deque->last_element_index;
  }
}

#pragma mark - Public Functions

ArrayDeque_r* ArrayDeque_r_new(void) {
  ArrayDeque_r* array_deque = malloc(sizeof(ArrayDeque_r));
  int storage_size = 4;
  // TODO: Delay allocation until first enqueue?
  array_deque->storage = malloc(storage_size * sizeof(void const*));
  array_deque->storage_size = storage_size;
  array_deque->count = 0;
  array_deque->first_element_index = 0;
  array_deque->last_element_index = 0;
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
  return array_deque->storage[AdjustedIndex(array_deque, index)];
 }

void const* ArrayDeque_r_get_last(ArrayDeque_r const* array_deque) {
  if (array_deque->count == 0) {
    return (void const*)0;
  }
  return array_deque->storage[array_deque->last_element_index];
}

void ArrayDeque_r_prepend(ArrayDeque_r* array_deque, void const* element) {
  // TODO: Increase storage size if needed.
  DecrementFirstElementIndex(array_deque);
  array_deque->storage[array_deque->first_element_index] = element;
  array_deque->count++;
}

void ArrayDeque_r_append(ArrayDeque_r* array_deque, void const* element) {
  // TODO: Increase storage size if needed.
  if (array_deque->count != 0) {
    IncrementLastElementIndex(array_deque);
  }
  array_deque->storage[array_deque->last_element_index] = element;
  array_deque->count++;
}

void const* ArrayDeque_r_remove_first(ArrayDeque_r* array_deque) {
  if (array_deque->count == 0) {
    return (void const*)0;
  }
  void const* element = array_deque->storage[array_deque->first_element_index];
  array_deque->count--;
  IncrementFirstElementIndex(array_deque);
  // TODO: Decrease storage size if needed.
  return element;
}

void const* ArrayDeque_r_remove_last(ArrayDeque_r* array_deque) {
  if (array_deque->count == 0) {
    return (void const*)0;
  }
  void const* element = array_deque->storage[array_deque->last_element_index];
  array_deque->count--;
  DecrementLastElementIndex(array_deque);
  // TODO: Decrease storage size if needed.
  return element;
}
