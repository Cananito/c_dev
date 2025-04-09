#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if !defined(_POSIX_SPIN_LOCKS) || _POSIX_SPIN_LOCKS < 0
/**
 * Sadly spin locks are an optional part of the POSIX standard, and macOS is
 * missing it. The following is a basic, not optimal, and not fully compliant
 * backport taken from the Gnulib repository:
 * https://github.com/coreutils/gnulib/blob/0f9fb17a13956721aa0ab8553f13a1f736492abd/lib/pthread-spin.c#L165-L212
 *
 * EBUSY taken from:
 * https://sites.uclouvain.be/SystInfo/usr/include/asm-generic/errno-base.h.html
 */
#define EBUSY 16 /* Device or resource busy */
typedef unsigned int pthread_spinlock_t;
int pthread_spin_init(pthread_spinlock_t* lock, int pshared) {
  *(volatile unsigned int*)lock = 0;
  __sync_synchronize();
  return 0;
}
int pthread_spin_destroy(pthread_spinlock_t* lock) {
  return 0;
}
int pthread_spin_lock(pthread_spinlock_t* lock) {
  // Wait until lock becomes 0, then replace it with 1.
  while (__sync_val_compare_and_swap(lock, 0, 1) != 0) {
  }
  return 0;
}
int pthread_spin_trylock(pthread_spinlock_t* lock) {
  if (__sync_val_compare_and_swap(lock, 0, 1) != 0) {
    return EBUSY;
  }
  return 0;
}
int pthread_spin_unlock(pthread_spinlock_t* lock) {
  // If lock is 1, then replace it with 0.
  if (__sync_val_compare_and_swap(lock, 1, 0) != 1) {
    printf("Failed to unlock spinlock, aborting.\n");
    abort();
  }
  return 0;
}
#endif // _POSIX_SPIN_LOCKS



static pthread_spinlock_t spinlock;
static int shared_counter = 0;

static void* thread_func(void* param) {
  for (int i = 0; i < 1000000; i++) {
    pthread_spin_lock(&spinlock);
    shared_counter++;
    pthread_spin_unlock(&spinlock);
  }
  return NULL;
}

int main(void) {
  printf("Initial value of shared_counter: %d\n", shared_counter);

  int init_error = pthread_spin_init(&spinlock, 0);
  if (init_error != 0) {
    printf("Couldn't initialize the spinlock.\n");
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

  int destroy_error = pthread_spin_destroy(&spinlock);
  if (destroy_error != 0) {
    printf("Couldn't initialize the spinlock.\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}
