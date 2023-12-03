#include <stdlib.h>

/** Declaration of the queue type. */
typedef struct Queue_r Queue_r;

/** Initializes and returns a new empty queue. */
extern Queue_r* Queue_r_create(void);

/** Uninitializes the gven queue. */
extern void Queue_r_destroy(Queue_r* queue);

/** Returns the number of items in the queue. */
extern size_t Queue_r_count(Queue_r* queue);

/** Returns the next item in the queue without dequeueing it. */
extern void* Queue_r_peek(Queue_r* queue);

/** Adds the passed-in item to the queue. */
extern void Queue_r_enqueue(Queue_r* queue, void* item);

/** Removes the next item from the queue and returns it. */
extern void* Queue_r_dequeue(Queue_r* queue);
