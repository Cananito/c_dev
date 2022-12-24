#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Person Person;
struct Person {
  int8_t age;
  char const* name;
  int8_t favoriteNumbers[3];
  size_t favoriteNumbersCount;
};

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
  Person rogelio = { .age = 33, .name = "Rogelio", .favoriteNumbers = { 1, 7 }, .favoriteNumbersCount = 2, };

  printf(">>> Before copy:\n");
  Person_Print(&rogelio);
  printf("No older Rogelio yet\n");

  Person olderRogelio = rogelio;
  olderRogelio.age = 34;
  olderRogelio.name = "older Rogelio";
  olderRogelio.favoriteNumbers[2] = 3;
  olderRogelio.favoriteNumbersCount = 3;

  printf(">>> After copy:\n");
  Person_Print(&rogelio);
  Person_Print(&olderRogelio);

  return 0;
}
