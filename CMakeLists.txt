cmake_minimum_required(VERSION 3.19.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# https://clang.llvm.org/docs/DiagnosticsReference.html
set(CMAKE_C_FLAGS "\
-Wall \
-Wextra \
-Werror \
-Wmissing-prototypes \
-Wnullable-to-nonnull-conversion \
")

project(computer_science)

add_subdirectory(data_structures)
