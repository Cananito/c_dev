#include <pthread.h>
#include <stdio.h>

#if !defined(_POSIX_BARRIERS) || _POSIX_BARRIERS < 0
/**
 * Sadly barriers are an optional part of the POSIX standard, and macOS is
 * missing it. The following is a basic, not optimal, and not fully compliant
 * backport taken from the following blog with a few tweaks:
 * https://blog.albertarmea.com/post/47089939939/using-pthreadbarrier-on-mac-os-x
 */
typedef struct {
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int count;
  int trip_count;
} pthread_barrier_t;
typedef struct {
} pthread_barrierattr_t;
int pthread_barrier_init(pthread_barrier_t* barrier,
                         pthread_barrierattr_t* attr,
                         unsigned int count) {
  if (count == 0) {
    return -1;
  }
  if (pthread_mutex_init(&barrier->mutex, 0) < 0) {
    return -1;
  }
  if (pthread_cond_init(&barrier->cond, 0) < 0) {
    pthread_mutex_destroy(&barrier->mutex);
    return -1;
  }
  barrier->trip_count = count;
  barrier->count = 0;
  return 0;
}
int pthread_barrier_destroy(pthread_barrier_t* barrier) {
  pthread_cond_destroy(&barrier->cond);
  pthread_mutex_destroy(&barrier->mutex);
  return 0;
}
int pthread_barrier_wait(pthread_barrier_t * barrier) {
  pthread_mutex_lock(&barrier->mutex);
  ++(barrier->count);
  if (barrier->count >= barrier->trip_count) {
    barrier->count = 0;
    pthread_cond_broadcast(&barrier->cond);
    pthread_mutex_unlock(&barrier->mutex);
    return 1;
  } else {
    pthread_cond_wait(&barrier->cond, &(barrier->mutex));
    pthread_mutex_unlock(&barrier->mutex);
    return 0;
  }
}
#endif // _POSIX_BARRIERS



static pthread_barrier_t barrier;

static void* thread_func(void* param) {
  size_t multiplier = (size_t)param;

  printf("thread_func with param %lu: Ready\n", multiplier);
  pthread_barrier_wait(&barrier);

  printf("thread_func with param %lu: GO!!!!!!!!!!!!\n", multiplier);
  size_t iterations = 100000 * multiplier;
  size_t dummy_counter = 0;
  for (size_t i = 0; i < iterations; i++) {
    dummy_counter++;
  }
  printf("thread_func with param %lu: Finished!\n", multiplier);

  pthread_barrier_wait(&barrier);

  printf("thread_func with param %lu: Exiting.\n", multiplier);
  return NULL;
}

int main(void) {
  pthread_barrier_init(&barrier, NULL, 4);

  printf("main: Creating 3 threads...\n");
  pthread_t thread1;
  pthread_create(&thread1, NULL, thread_func, (void*)1);
  pthread_t thread2;
  pthread_create(&thread2, NULL, thread_func, (void*)2);
  pthread_t thread3;
  pthread_create(&thread3, NULL, thread_func, (void*)3);

  printf("main: Waiting for threads to be ready...\n");
  pthread_barrier_wait(&barrier);

  printf("main: Waiting for threads to finish...\n");
  pthread_barrier_wait(&barrier);

  printf("main: Waiting for all threads to exit...\n");
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);

  printf("main: DONE DONE DONE\n");
  pthread_barrier_destroy(&barrier);

  return 0;
}
