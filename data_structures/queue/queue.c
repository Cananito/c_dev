#include "queue.h"

#include <stdlib.h>

// TODO: Add NULL checks.

// TODO: Make all functions thread safe.

struct Queue_r {
  // TODO: Change to an "ArrayList_r" or something for storage.
  void const** storage;
  int storage_size;
  int count;
  int first_element_index;
};

Queue_r* Queue_r_new(void) {
  Queue_r* q = malloc(sizeof(Queue_r));
  int storage_size = 4;
  // TODO: Delay allocation until first enqueue?
  q->storage = malloc(storage_size * sizeof(void*));
  q->storage_size = storage_size;
  q->count = 0;
  q->first_element_index = 0;
  return q;
}

void Queue_r_free(Queue_r* queue) {
  free(queue->storage);
  free(queue);
}

int Queue_r_count(Queue_r const* queue) {
  return queue->count;
}

void const* Queue_r_peek(Queue_r const* queue) {
  if (queue->count == 0) {
    return (void*)0;
  }
  return queue->storage[0];
}

void Queue_r_enqueue(Queue_r* queue, void const* element) {
  int current_count = queue->count;
  queue->storage[current_count] = element;
  queue->count++;

  // TODO: Increase storage size if needed.
}

void const* Queue_r_dequeue(Queue_r* queue) {
  if (queue->count == 0) {
    return (void*)0;
  }

  int first_element_index = queue->first_element_index;
  void const* element = queue->storage[first_element_index];
  queue->count--;
  queue->first_element_index++;

  // TODO: Decrease storage size if needed.

  return element;
}
