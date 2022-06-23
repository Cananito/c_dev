_Pragma("clang assume_nonnull begin")

// TODO: Figure out immutability.

/** Declaration of the queue type. */
typedef struct Queue_r Queue_r;

/** Allocates and returns a new empty queue. */
extern Queue_r* Queue_r_new(void);

/** Frees the queue. */
extern void Queue_r_free(Queue_r* queue);

/** Returns the number of elements in the queue. */
extern int Queue_r_count(Queue_r* queue);

/** Returns the next element in the queue without dequeueing it. */
extern void* _Nullable Queue_r_peek(Queue_r* queue);

/** Adds the passed-in element to the queue. */
extern void Queue_r_enqueue(Queue_r* queue, void* element);

/** Removes the next element from the queue and returns it. */
extern void* _Nullable Queue_r_dequeue(Queue_r* queue);

_Pragma("clang assume_nonnull end")
