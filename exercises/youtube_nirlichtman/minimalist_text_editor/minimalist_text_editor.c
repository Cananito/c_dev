// https://www.youtube.com/watch?v=gnvDPCXktWQ
// https://gist.github.com/nir9/6398b692acbcd44a66141004b2882009

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_buffer_with_line_numbers_prefixed(char* buffer) {
  size_t current_line_number = 1;
  printf("%zu - ", current_line_number);
  current_line_number++;

  char* current = buffer;
  char current_char = *current;
  while (current_char != '\0') {
    putchar(current_char);

    char next_char = *(current + 1);
    if (next_char == '\0') {
      break;
    }

    if (current_char == '\n') {
      printf("%zu - ", current_line_number);
      current_line_number++;
    }

    current = current + 1;
    current_char = *current;
  }
}

void edit_line(char* buffer, size_t line_number) {
  if (line_number != 0) {
    // Adjust line number to be 0 indexed.
    line_number = line_number - 1;
  }

  // Go to beginning of specified line number.
  for (int i = 0; i < line_number; i++) {
    buffer = strchr(buffer, '\n') + 1;
  }

  // Remember contents of the end of the specified line number onwards.
  char* end_of_input_line = strchr(buffer, '\n');
  char saved_content[1024] = { 0 }; // TODO: Allocate dynamically to req size.
  strcpy(saved_content, end_of_input_line);

  // Put user input into beginning of specified line number.
  printf("> ");
  scanf("%s", buffer);

  // Concatenate remembered location to end of user input.
  strcpy(buffer + strlen(buffer), saved_content);
}

int main(int argc, char** argv) {
  char* file_path = argv[1];
  if (file_path == NULL) {
    printf("ERROR: Need to specify a file to edit!\n");
    exit(EXIT_FAILURE);
  }

  FILE* readable_file = fopen(file_path, "r");
  char buffer[1024] = { 0 }; // TODO: Allocate dynamically to required size.
  fread(buffer, 1024, 1, readable_file);
  fclose(readable_file);

  print_buffer_with_line_numbers_prefixed(buffer);

  int line_to_edit = 0;
  printf("> Which line do you want to edit? ");
  scanf("%d", &line_to_edit);
  edit_line(buffer, line_to_edit);

  FILE* writtable_file = fopen(file_path, "w");
  fwrite(buffer, strlen(buffer), 1, writtable_file);
  fclose(writtable_file);

  return 1;
}
