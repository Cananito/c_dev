#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "zlib.h"

static void read_file(unsigned char* const file_content,
                      char const* const file_path,
                      size_t buffer_size) {
  FILE* file = fopen(file_path, "r");
  if (file == NULL) {
    printf("Failed to open file_path: %s.\n", file_path);
    exit(EXIT_FAILURE);
  }
  fread(file_content, sizeof(char), buffer_size, file);
  if (feof(file) == 0) {
    printf("Couldn't read to end of file for file_path: %s.\n", file_path);
    fclose(file);
    exit(EXIT_FAILURE);
  }
  if (ferror(file) != 0) {
    printf("Read error for file_path: %s.\n", file_path);
    fclose(file);
    exit(EXIT_FAILURE);
  }
  fclose(file);
}

static void r_compress(unsigned char* compressed_content,
                       unsigned char* decompressed_content) {
  int deflate_ret;
  z_stream strm;
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;

  deflate_ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
  if (deflate_ret != Z_OK) {
    printf("Failed to compress.\n");
    exit(EXIT_FAILURE);
  }

  strm.avail_in = 1024;
  strm.next_in = decompressed_content;
  strm.avail_out = 1024;
  strm.next_out = compressed_content;
  deflate_ret = deflate(&strm, Z_FINISH);
  deflateEnd(&strm);
}

static void r_decompress(unsigned char* decompressed_content,
                         unsigned char* compressed_content) {
  int inflate_ret;
  z_stream strm;
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  strm.avail_in = 0;
  strm.next_in = Z_NULL;

  inflate_ret = inflateInit(&strm);
  if (inflate_ret != Z_OK) {
    printf("Failed to decompress.\n");
    exit(EXIT_FAILURE);
  }

  strm.avail_in = 1024;
  strm.next_in = compressed_content;
  strm.avail_out = 1024;
  strm.next_out = decompressed_content;
  inflate_ret = inflate(&strm, Z_NO_FLUSH);
  inflateEnd(&strm);
  if (inflate_ret == Z_NEED_DICT ||
      inflate_ret == Z_DATA_ERROR ||
      inflate_ret == Z_MEM_ERROR) {
    printf("Failed to decompress.\n");
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {
  // Disable output buffering
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);

  unsigned char test_file_decompressed_content[1024] = { 0 };
  unsigned char test_file_compressed_content[1024] = { 0 };
  read_file(test_file_compressed_content,
            "/Users/rogeliogudino/Downloads/lala.txt",
            1024);
  printf("File content compressed:\n%s\n", test_file_compressed_content);

  r_decompress(test_file_decompressed_content, test_file_compressed_content);
  printf("File content decompressed:\n%s\n", test_file_decompressed_content);

  /*
  if (argc < 2) {
    fprintf(stderr, "Usage: ./your_program.sh <command> [<args>]\n");
    return 1;
  }

  const char *command = argv[1];

  if (strcmp(command, "init") == 0) {
    if (mkdir(".git", 0755) == -1 ||
        mkdir(".git/objects", 0755) == -1 ||
        mkdir(".git/refs", 0755) == -1) {
      fprintf(stderr, "Failed to create directories: %s\n", strerror(errno));
      return 1;
    }

    FILE *headFile = fopen(".git/HEAD", "w");
    if (headFile == NULL) {
      fprintf(stderr, "Failed to create .git/HEAD file: %s\n", strerror(errno));
      return 1;
    }
    fprintf(headFile, "ref: refs/heads/main\n");
    fclose(headFile);

    printf("Initialized git directory\n");
  } else {
    fprintf(stderr, "Unknown command %s\n", command);
    return 1;
  }
  */

  return 0;
}
