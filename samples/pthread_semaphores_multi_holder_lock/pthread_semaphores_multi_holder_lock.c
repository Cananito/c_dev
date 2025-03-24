#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static sem_t* semaphore;

static void* work(void* param) {
  int64_t id = (int64_t)param;

  int wait_error = sem_wait(semaphore);
  if (wait_error != 0) {
    printf("Failed to wait on the samaphore!\n");
    exit(EXIT_FAILURE);
  }

  printf("Work ID %lld started...\n", id);
  sleep(3);
  printf("Work ID %lld finished...\n", id);

  int post_error = sem_post(semaphore);
  if (post_error != 0) {
    printf("Failed to post on the samaphore!\n");
    exit(EXIT_FAILURE);
  }

  return NULL;
}

int main(void) {
  char* semaphore_name = "semaphore";
  // Maximum 3 holders of the semaphore at a time.
  semaphore = sem_open(semaphore_name, O_CREAT, 0, 3);
  if (semaphore == SEM_FAILED) {
    printf("Failed to open the samaphore!\n");
    exit(EXIT_FAILURE);
  }

  #define NUM_THREADS 7
  pthread_t threads[NUM_THREADS];
  for (size_t i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, work, (void*)(i + 1));
  }
  for (size_t i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  int close_error = sem_close(semaphore);
  if (close_error != 0) {
    printf("Failed to close the samaphore!\n");
    exit(EXIT_FAILURE);
  }
  int unlink_error = sem_unlink(semaphore_name);
  if (unlink_error != 0) {
    printf("Failed to unlink the samaphore!\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}
