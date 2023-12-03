#include "array_deque.h"

#include <stdlib.h>

// TODO: Add NULL checks.

// TODO: Make all functions thread safe.

struct ArrayDeque_r {
  void** items_buffer;
  size_t items_buffer_size;
  size_t items_count;
  size_t first_item_index;
  size_t last_item_index;
};

#pragma mark - Private Functions

static size_t AdjustedIndex(ArrayDeque_r* array_deque, size_t index) {
  size_t adjusted_index = index + array_deque->first_item_index;
  size_t items_buffer_size = array_deque->items_buffer_size;
  if (adjusted_index >= items_buffer_size) {
    adjusted_index = adjusted_index - items_buffer_size;
  }
  return adjusted_index;
}

static void IncrementFirstElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->items_count == 0 &&
      array_deque->last_item_index == array_deque->first_item_index) {
    should_match_indices = 1;
  }

  size_t temp_index = array_deque->first_item_index + 1;
  if (temp_index == array_deque->items_buffer_size) {
    // Need to circle back to the start of the buffer.
    array_deque->first_item_index = 0;
  } else {
    array_deque->first_item_index = temp_index;
  }

  if (should_match_indices) {
    array_deque->last_item_index = array_deque->first_item_index;
  }
}

static void DecrementFirstElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->items_count == 0 &&
      array_deque->last_item_index == array_deque->first_item_index) {
    should_match_indices = 1;
  }

  if (array_deque->first_item_index == 0) {
    // Need to circle back to the end of the buffer.
    array_deque->first_item_index = array_deque->items_buffer_size - 1;
  } else {
    array_deque->first_item_index--;
  }

  if (should_match_indices) {
    array_deque->last_item_index = array_deque->first_item_index;
  }
}

static void IncrementLastElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->items_count == 0 &&
      array_deque->first_item_index == array_deque->last_item_index) {
    should_match_indices = 1;
  }

  size_t temp_index = array_deque->last_item_index + 1;
  if (temp_index == array_deque->items_buffer_size) {
    // Need to circle back to start of the buffer.
    array_deque->last_item_index = 0;
  } else {
    array_deque->last_item_index = temp_index;
  }

  if (should_match_indices) {
    array_deque->first_item_index = array_deque->last_item_index;
  }
}

static void DecrementLastElementIndex(ArrayDeque_r *array_deque) {
  int should_match_indices = 0;
  if (array_deque->items_count == 0 &&
      array_deque->first_item_index == array_deque->last_item_index) {
    should_match_indices = 1;
  }

  if (array_deque->last_item_index == 0) {
    // Need to circle back to the end of the buffer.
    array_deque->last_item_index = array_deque->items_buffer_size - 1;
  } else {
    array_deque->last_item_index--;
  }

  if (should_match_indices) {
    array_deque->first_item_index = array_deque->last_item_index;
  }
}

#pragma mark - Public Functions

ArrayDeque_r* ArrayDeque_r_create(void) {
  const size_t items_buffer_size = 4;
  // TODO: Delay allocation until first enqueue?
  ArrayDeque_r* array_deque = malloc(sizeof(ArrayDeque_r));
  // TODO: Request item size instead of void* size.
  array_deque->items_buffer = malloc(items_buffer_size * sizeof(void*));
  array_deque->items_buffer_size = items_buffer_size;
  array_deque->items_count = 0;
  array_deque->first_item_index = 0;
  array_deque->last_item_index = 0;
  return array_deque;
}

void ArrayDeque_r_destroy(ArrayDeque_r* array_deque) {
  free(array_deque->items_buffer);
  free(array_deque);
}

size_t ArrayDeque_r_count(ArrayDeque_r* array_deque) {
  return array_deque->items_count;
}

void* ArrayDeque_r_get(ArrayDeque_r* array_deque, size_t index) {
  // TODO: Do bounds check.
  if (array_deque->items_count == 0) {
    return (void*)0;
  }
  return array_deque->items_buffer[AdjustedIndex(array_deque, index)];
 }

void* ArrayDeque_r_get_last(ArrayDeque_r* array_deque) {
  if (array_deque->items_count == 0) {
    return (void*)0;
  }
  return array_deque->items_buffer[array_deque->last_item_index];
}

void ArrayDeque_r_prepend(ArrayDeque_r* array_deque, void* item) {
  // TODO: Increase items_buffer size if needed.
  DecrementFirstElementIndex(array_deque);
  array_deque->items_buffer[array_deque->first_item_index] = item;
  array_deque->items_count++;
}

void ArrayDeque_r_append(ArrayDeque_r* array_deque, void* item) {
  // TODO: Increase items_buffer size if needed.
  if (array_deque->items_count != 0) {
    IncrementLastElementIndex(array_deque);
  }
  array_deque->items_buffer[array_deque->last_item_index] = item;
  array_deque->items_count++;
}

void* ArrayDeque_r_remove_first(ArrayDeque_r* array_deque) {
  if (array_deque->items_count == 0) {
    return (void*)0;
  }
  void* item = array_deque->items_buffer[array_deque->first_item_index];
  array_deque->items_count--;
  IncrementFirstElementIndex(array_deque);
  // TODO: Decrease items_buffer size if needed.
  return item;
}

void* ArrayDeque_r_remove_last(ArrayDeque_r* array_deque) {
  if (array_deque->items_count == 0) {
    return (void*)0;
  }
  void* item = array_deque->items_buffer[array_deque->last_item_index];
  array_deque->items_count--;
  DecrementLastElementIndex(array_deque);
  // TODO: Decrease items_buffer size if needed.
  return item;
}
