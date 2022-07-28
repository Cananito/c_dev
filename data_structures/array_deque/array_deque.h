// TODO: Rename to something more general.

// TODO: Figure out immutability.

/** Declaration of the array deque type. */
typedef struct ArrayDeque_r ArrayDeque_r;

/** Allocates and returns a new empty array deque. */
extern ArrayDeque_r* ArrayDeque_r_new(void);

/** Frees the array deque. */
extern void ArrayDeque_r_free(ArrayDeque_r* array_deque);

/** Returns the number of elements in the array deque. */
extern int ArrayDeque_r_count(ArrayDeque_r* array_deque);

/** Returns the element at a given index in the array deque, if it exists. */
extern void* ArrayDeque_r_get(ArrayDeque_r* array_deque, int index);

/** Returns the last element in the array deque, if it exists. */
extern void* ArrayDeque_r_get_last(ArrayDeque_r* array_deque);

/** Adds the passed-in element to the beginning of the array deque. */
extern void ArrayDeque_r_prepend(ArrayDeque_r* array_deque, void* element);

/** Adds the passed-in element to the end of the array deque. */
extern void ArrayDeque_r_append(ArrayDeque_r* array_deque, void* element);

/** Removes the first element from the array deque and returns it. */
extern void* ArrayDeque_r_remove_first(ArrayDeque_r* array_deque);

/** Removes the last element from the array deque and returns it. */
extern void* ArrayDeque_r_remove_last(ArrayDeque_r* array_deque);
