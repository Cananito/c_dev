#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

static pthread_cond_t cond;
static pthread_mutex_t mutex;
static int8_t progress = 0;

static void* prep_work(void* param) {
  int64_t progress_increments = (int64_t)param;
  printf("Prepping at %llu progress increments.\n", progress_increments);
  for (int i = 0; i < 10; i++) {
    sleep(1);
    pthread_mutex_lock(&mutex);
    progress += progress_increments;
    if (progress > 100) {
      progress = 100;
    }
    if (progress == 100) {
      pthread_cond_signal(&cond);
      pthread_mutex_unlock(&mutex);
      return NULL;
    }
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

static void* cook_work(void* param) {
  printf("Cook waiting for prep...\n");
  pthread_cond_wait(&cond, &mutex);
  printf("Prep progress: %hhd/100. Cooking now!\n", progress);
  sleep(1);
  printf("Cooking done.\n");
  return NULL;
}

int main(void) {
  pthread_mutex_init(&mutex, NULL);

  pthread_cond_init(&cond, NULL);

  pthread_t prep_a_thread;
  pthread_create(&prep_a_thread, NULL, prep_work, (void*)20);

  pthread_t prep_b_thread;
  pthread_create(&prep_b_thread, NULL, prep_work, (void*)15);

  pthread_t cook_thread;
  pthread_create(&cook_thread, NULL, cook_work, NULL);

  pthread_join(cook_thread, NULL);

  pthread_cond_destroy(&cond);

  pthread_mutex_destroy(&mutex);

  return 0;
}
