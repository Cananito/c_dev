#include "queue.h"

#include <stdlib.h>

// TODO: Add NULL checks.

// TODO: Make all functions thread safe.

struct Queue_r {
  // TODO: Change to an "ArrayList_r" or something for storage?
  void** items_buffer;
  size_t items_buffer_size;
  size_t items_count;
  size_t first_item_index;
};

#pragma mark - Public Functions

Queue_r* Queue_r_create(void) {
  const size_t items_buffer_size = 4;
  // TODO: Delay allocation until first enqueue?
  Queue_r *q = malloc(sizeof(Queue_r));
  // TODO: Request item size instead of void* size.
  q->items_buffer = malloc(items_buffer_size * sizeof(void*));
  q->items_buffer_size = items_buffer_size;
  q->items_count = 0;
  q->first_item_index = 0;
  return q;
}

void Queue_r_destroy(Queue_r* queue) {
  free(queue->items_buffer);
  free(queue);
}

size_t Queue_r_count(Queue_r const* queue) {
  return queue->items_count;
}

void* Queue_r_peek(Queue_r const* queue) {
  if (queue->items_count == 0) {
    return (void*)0;
  }
  return queue->items_buffer[0];
}

void Queue_r_enqueue(Queue_r* queue, void* item) {
  size_t current_count = queue->items_count;
  queue->items_buffer[current_count] = item;
  queue->items_count++;

  // TODO: Increase storage size if needed.
}

void* Queue_r_dequeue(Queue_r* queue) {
  if (queue->items_count == 0) {
    return (void*)0;
  }

  size_t first_item_index = queue->first_item_index;
  void* item = queue->items_buffer[first_item_index];
  queue->items_count--;
  queue->first_item_index++;

  // TODO: Decrease storage size if needed.

  return item;
}
