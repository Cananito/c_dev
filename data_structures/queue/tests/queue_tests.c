#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

_Pragma("clang assume_nonnull begin")

// TODO: Move to a testing library.
static void assert_true(int condition_result, char *failure_message) {
  if (condition_result != 1) {
    printf("%s\n", failure_message);
    exit(1);
  }
}

static void test_queue() {
  Queue_r *queue = Queue_r_new();
  assert_true(Queue_r_count(queue) == 0, "Queue not empty.");

  Queue_r_enqueue(queue, "a");
  assert_true(Queue_r_count(queue) == 1, "Queue count not 1.");
  assert_true(strcmp(Queue_r_peek(queue), "a") == 0, "Queue peek not \"a\".");

  assert_true(strcmp(Queue_r_dequeue(queue), "a") == 0, "Queue dequeue not \"a\".");
  assert_true(Queue_r_count(queue) == 0, "Queue not empty.");

  Queue_r_free(queue);
}

int main() {
  printf("Starting tests.\n");
  test_queue();
  printf("Tests succeeded!\n");
  return 0;
}

_Pragma("clang assume_nonnull end")
