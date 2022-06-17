#include <stdio.h>
#include <string.h>

#include "queue.h"
#include "unit_testing.h"

_Pragma("clang assume_nonnull begin")

static void test_queue() {
  Queue_r* queue = Queue_r_new();
  assert_true(Queue_r_count(queue) == 0, "Queue not empty.");
  assert_true(Queue_r_peek(queue) == 0, "Queue peek didn't return nil.");
  assert_true(Queue_r_dequeue(queue) == 0, "Queue dequeue didn't return nil.");

  Queue_r_enqueue(queue, "a");
  assert_true(Queue_r_count(queue) == 1, "Queue count not 1.");
  assert_true(strcmp(Queue_r_peek(queue), "a") == 0, "Queue peek not \"a\".");

  assert_true(strcmp(Queue_r_dequeue(queue), "a") == 0,
              "Queue dequeue not \"a\".");
  assert_true(Queue_r_count(queue) == 0, "Queue not empty.");
  assert_true(Queue_r_peek(queue) == 0, "Queue peek didn't return nil.");
  assert_true(Queue_r_dequeue(queue) == 0, "Queue dequeue didn't return nil.");

  Queue_r_free(queue);
}

int main() {
  printf("Starting tests.\n");
  test_queue();
  printf("Tests succeeded!\n");
  return 0;
}

_Pragma("clang assume_nonnull end")
