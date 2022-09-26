// TODO: Rename new and free to create and destroy.

/** Declaration of the queue type. */
typedef struct Queue_r Queue_r;

/** Allocates and returns a new empty queue. */
extern Queue_r* Queue_r_new(void);

/** Frees the queue. */
extern void Queue_r_free(Queue_r* queue);

/** Returns the number of elements in the queue. */
extern int Queue_r_count(Queue_r const* queue);

/** Returns the next element in the queue without dequeueing it. */
extern void const* Queue_r_peek(Queue_r const* queue);

/** Adds the passed-in element to the queue. */
extern void Queue_r_enqueue(Queue_r* queue, void const* element);

/** Removes the next element from the queue and returns it. */
extern void const* Queue_r_dequeue(Queue_r* queue);
