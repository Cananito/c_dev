#include <stdlib.h>

// TODO: Rename to something more general.

/** Declaration of the array deque type. */
typedef struct ArrayDeque_r ArrayDeque_r;

/** Allocates and returns a new empty array deque. */
extern ArrayDeque_r* ArrayDeque_r_create(void);

/** Frees the array deque. */
extern void ArrayDeque_r_destroy(ArrayDeque_r* array_deque);

/** Returns the number of items in the array deque. */
extern size_t ArrayDeque_r_count(ArrayDeque_r* array_deque);

/** Returns the item at a given index in the array deque, if it exists. */
extern void* ArrayDeque_r_get(ArrayDeque_r* array_deque, size_t index);

/** Returns the last item in the array deque, if it exists. */
extern void* ArrayDeque_r_get_last(ArrayDeque_r* array_deque);

/** Adds the passed-in item to the beginning of the array deque. */
extern void ArrayDeque_r_prepend(ArrayDeque_r* array_deque, void* item);

/** Adds the passed-in item to the end of the array deque. */
extern void ArrayDeque_r_append(ArrayDeque_r* array_deque, void* item);

/** Removes the first item from the array deque and returns it. */
extern void* ArrayDeque_r_remove_first(ArrayDeque_r* array_deque);

/** Removes the last item from the array deque and returns it. */
extern void* ArrayDeque_r_remove_last(ArrayDeque_r* array_deque);
