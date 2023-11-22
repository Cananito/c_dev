# computer_science

Collection of computer science libraries and executables written in C.

## Requirements

* Clang.

## Build Instructions

1. `cd` into the root of this repository.
1. `make -f <path to Makefile> build` to build whatever test or program.

## Run Instructions

1. `cd` into the root of this repository.
1. `make -f <path to Makefile>` to run whatever test or program.

## Debug Instructions

1. Follow the [build instructions](#build-instructions).
1. Find the executable in the `build` directory and pass it to LLDB. Example: `lldb build/queue_tests`

## Clean Instructions

1. `make -f <path to Makefile> clean` to clean whatever test or program.

## clangd Set-Up

TODO
