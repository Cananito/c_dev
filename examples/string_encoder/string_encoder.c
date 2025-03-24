#include <stdio.h>
#include <string.h>

const char* message = "Hello, World!";

#define HISTOGRAM_CAPACITY 256
size_t histogram[HISTOGRAM_CAPACITY] = {0};

#define TABLE_CAPACITY 256
char table[TABLE_CAPACITY] = {0};
size_t table_size = 0;

#define TIMC_CAP 64
size_t table_index_of_message_char[TIMC_CAP] = {0};
size_t timc_size = 0;

void encode(void) {
  size_t message_size = strlen(message);
  for (size_t i = 0; i < message_size; i++) {
    size_t character_index = message[i];
    histogram[character_index]++;
  }

  for (size_t i = 0; i < HISTOGRAM_CAPACITY; i++) {
    if (histogram[i] > 0) {
      table[table_size] = (char)i;
      table_size++;
    }
  }
  table[table_size] = '\0';
  table_size++;

  for (size_t i = 0; i < message_size; i++) {
    for (size_t j = 0; j < table_size; j++) {
      if (message[i] == table[j]) {
        table_index_of_message_char[timc_size] = j;
        timc_size++;
      }
    }
  }

  printf("Message: \"%s\"\n", message);
  printf("Table:   \"%s\"\n", table);
  printf("TIMC:    { ");
  for (size_t i = 0; i < timc_size; i++) {
    printf("%zu, ", table_index_of_message_char[i]);
  }
  printf("}\n");
}

void decode() {
  printf("Decoded message: ");
  for (size_t i = 0; i < timc_size; i++) {
    putchar(table[table_index_of_message_char[i]]);
  }
  printf("\n");
}

int main(void) {
  encode();
  printf("---\n");
  decode();
  return 0;
}
