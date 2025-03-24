#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void* calculate(void* param) {
  int64_t result = (int64_t)param;
  sleep(1);
  result += 3;
  return (void*)result;
}

int main(void) {
  printf("Offloading calculation to another thread...\n");
  pthread_t thread;
  int create_error = pthread_create(&thread, NULL, calculate, (void*)7);
  if (create_error != 0) {
    printf("Couldn't create the thread. Exiting.\n");
    exit(EXIT_FAILURE);
  }

  printf("Waiting for calculation to finish...\n");
  void* result = 0;
  int join_error = pthread_join(thread, &result);
  if (create_error != 0) {
    printf("Couldn't join the thread. Exiting.\n");
    exit(EXIT_FAILURE);
  }
  printf("Calculation result: %lld\n", (int64_t)result);

  return 0;
}
