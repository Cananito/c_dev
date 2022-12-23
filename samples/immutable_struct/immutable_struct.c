#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Move things into their own files.

typedef struct Person Person;
struct Person {
  int8_t const age;
  char const* const name;
  // TODO: Convert these 2 into a List_r.
  int8_t const favoriteNumbers;
  size_t const favoriteNumbersCount;
};

static Person Person_Create(int8_t age, char* name, int8_t* favoriteNumbers, size_t favoriteNumbersCount) {
  // TODO: When is this supposed to be freed?
  //       Probably need a Destroy function that does it?
  int8_t* favoriteNumbersCopy = calloc(favoriteNumbersCount, sizeof(int8_t));
  for (size_t i = 0; i < favoriteNumbersCount; i++) {
    favoriteNumbersCopy[i] = favoriteNumbers[i];
  }
  return (Person){
    .age = age,
    .name = name,
    .favoriteNumbers = favoriteNumbersCopy,
    .favoriteNumbersCount = favoriteNumbersCount,
  };
}

static void Person_Destroy(Person* person) {
  // TODO: Copy favoriteNumbers in Update functions, use a destroyed bool pointer, or a List_r pointer?
  // free(person->favoriteNumbers);
}

static Person Person_UpdateAge(Person person, int8_t age) {
  return (Person){
    .age = age,
    .name = person.name,
    .favoriteNumbers = person.favoriteNumbers,
    .favoriteNumbersCount = person.favoriteNumbersCount,
  };
}

static void Person_Print(Person const* person) {
  printf("Person (%p) { .age = %d, .name = %s, .favoriteNumbers = ",
         &person,
         person->age,
         person->name);

  size_t favoriteNumbersCount = person->favoriteNumbersCount;
  if (favoriteNumbersCount == 0) {
    printf("[]");
  } else {
    printf("[");
    for (size_t i = 0; i < favoriteNumbersCount; i++) {
      printf(" ");
      printf("%d", person->favoriteNumbers[i]);
      if (i == favoriteNumbersCount - 1) {
        printf(" ");
      } else {
        printf(",");
      }
    }
    printf("]");
  }

  printf(" }\n");
}

int main () {
  int8_t* rogelioFavoriteNumbers = calloc(2, sizeof(int8_t));
  rogelioFavoriteNumbers[0] = 1;
  rogelioFavoriteNumbers[1] = 7;
  Person rogelio = Person_Create(33, "Rogelio", rogelioFavoriteNumbers, 2);
  free(rogelioFavoriteNumbers);
  Person_Print(&rogelio);

  Person olderRogelio = Person_UpdateAge(rogelio, 34);
  Person_Print(&olderRogelio);

  Person_Destroy(&rogelio);
  Person_Destroy(&olderRogelio);

  return 0;
}
