#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static pthread_mutex_t mutex;
static int shared_counter = 0;

static void* thread_func(void* param) {
  for (int i = 0; i < 1000000; i++) {
    pthread_mutex_lock(&mutex);
    shared_counter++;
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

int main(void) {
  printf("Initial value of shared_counter: %d\n", shared_counter);

  int init_error = pthread_mutex_init(&mutex, NULL);
  if (init_error != 0) {
    printf("Couldn't initialize the mutex.\n");
    exit(EXIT_FAILURE);
  }

  pthread_t threads[2];
  pthread_create(&threads[0], NULL, thread_func, NULL);
  pthread_create(&threads[1], NULL, thread_func, NULL);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  printf("Final value of shared_counter: %d\n", shared_counter);
  if (shared_counter == 2000000) {
    printf("Everything as expected.\n");
  } else {
    printf("NOT THE EXPECTED VALUE!\n");
  }

  return 0;
}
