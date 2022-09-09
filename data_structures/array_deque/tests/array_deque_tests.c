#include <stdio.h>
#include <string.h>

#include "array_deque.h"
#include "unit_testing.h"

/*
static void test_array_deque() {
  ArrayDeque_r* array_deque = ArrayDeque_r_new();
  assert_true(ArrayDeque_r_count(array_deque) == 0, "ArrayDeque not empty.");
  assert_true(ArrayDeque_r_peek(array_deque) == 0, "ArrayDeque peek didn't return nil.");
  assert_true(ArrayDeque_r_dearray_deque(array_deque) == 0, "ArrayDeque dearray_deque didn't return nil.");

  ArrayDeque_r_enarray_deque(array_deque, "a");
  assert_true(ArrayDeque_r_count(array_deque) == 1, "ArrayDeque count not 1.");
  assert_true(strcmp(ArrayDeque_r_peek(array_deque), "a") == 0, "ArrayDeque peek not \"a\".");

  ArrayDeque_r_enarray_deque(array_deque, "b");
  assert_true(ArrayDeque_r_count(array_deque) == 2, "ArrayDeque count not 2.");
  assert_true(strcmp(ArrayDeque_r_peek(array_deque), "a") == 0, "ArrayDeque peek not \"a\".");

  assert_true(strcmp(ArrayDeque_r_dearray_deque(array_deque), "a") == 0,
              "ArrayDeque dearray_deque not \"a\".");
  assert_true(strcmp(ArrayDeque_r_dearray_deque(array_deque), "b") == 0,
              "ArrayDeque dearray_deque not \"b\".");

  assert_true(ArrayDeque_r_count(array_deque) == 0, "ArrayDeque not empty.");
  assert_true(ArrayDeque_r_peek(array_deque) == 0, "ArrayDeque peek didn't return nil.");
  assert_true(ArrayDeque_r_dearray_deque(array_deque) == 0, "ArrayDeque dearray_deque didn't return nil.");

  ArrayDeque_r_free(array_deque);
}
*/

static void test_add_and_remove_elements(void) {
  ArrayDeque_r *array_deque = ArrayDeque_r_new();
  assert_true(ArrayDeque_r_count(array_deque) == 0, "ArrayDeque not empty.");

  int one = 1;
  ArrayDeque_r_append(array_deque, &one);
  assert_true(ArrayDeque_r_count(array_deque) == 1, "ArrayDeque count not 1.");

  int two = 2;
  ArrayDeque_r_append(array_deque, &two);
  assert_true(ArrayDeque_r_count(array_deque) == 2, "ArrayDeque count not 2.");

  int zero = 0;
  ArrayDeque_r_prepend(array_deque, &zero);
  assert_true(ArrayDeque_r_count(array_deque) == 3, "ArrayDeque count not 3.");

  assert_true(ArrayDeque_r_get(array_deque, 0) != 0, "ArrayDequeue get at 0 is nil.");
  assert_true(ArrayDeque_r_get(array_deque, 1) != 0, "ArrayDequeue get at 1 is nil.");
  assert_true(ArrayDeque_r_get(array_deque, 2) != 0, "ArrayDequeue get at 2 is nil.");
  assert_true(*(int*)ArrayDeque_r_get(array_deque, 0) == 0,
              "ArrayDeque get at 0 not 0.");
  assert_true(*(int*)ArrayDeque_r_get(array_deque, 1) == 1,
              "ArrayDeque get at 1 not 1.");
  assert_true(*(int*)ArrayDeque_r_get(array_deque, 2) == 2,
              "ArrayDeque get at 2 not 2.");

  assert_true(*(int*)ArrayDeque_r_remove_first(array_deque) == 0,
              "ArrayDeque remove first not 0");
  assert_true(ArrayDeque_r_count(array_deque) == 2, "ArrayDeque count not 2.");

  assert_true(*(int*)ArrayDeque_r_remove_last(array_deque) == 2,
              "ArrayDeque remove first not 2");
  assert_true(ArrayDeque_r_count(array_deque) == 1, "ArrayDeque count not 1.");

  ArrayDeque_r_free(array_deque);
}

static void test_capacity_changes_and_get_last(void) {
  // TODO: Add test.
}

static void test_circular_prepending(void) {
  // TODO: Add test.
}

static void test_double_prepend_and_remove_last(void) {
  // TODO: Add test.
}

static void test_double_prepend_and_remove_first(void) {
  // TODO: Add test.
}

static void test_double_append_and_remove_first(void) {
  // TODO: Add test.
}

static void test_double_append_and_remove_last(void) {
  // TODO: Add test.
}

int main() {
  printf("Starting tests.\n");
  test_add_and_remove_elements();
  test_capacity_changes_and_get_last();
  test_circular_prepending();
  test_double_prepend_and_remove_last();
  test_double_prepend_and_remove_first();
  test_double_append_and_remove_first();
  test_double_append_and_remove_last();
  printf("Tests succeeded!\n");
  return 0;
}
