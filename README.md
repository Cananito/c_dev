# computer_science

Collection of computer science libraries and executables written in C.

## Requirements

* A C compiler.
* CMake.

## Build Instructions

1. `cd` into the root of this repository.
1. If there's no `build` directory, `mkdir build`.
1. `cd build`.
1. `cmake ..`. This will populate the build directory with a Makefile and compile_commands.json.
1. Optionally to enable debugging, `cmake -DCMAKE_BUILD_TYPE=Debug ..`.
1. `cmake --build .`. This will build the code.

## Running Instructions

1. Follow build instructions.
1. Find the executable and run it. Example: `./data_structures/queue/tests/queue_tests`

## Clean Instructions

1. `cd build`.
1. Run `cmake --build . --target clean`

## Debugging Instructions

1. Follow build instructions.
1. Find the executable and pass it to LLDB. Example: `lldb data_structures/queue/tests/queue_tests`

## clangd Set-Up

This requires populating the build directory with CMake first (see `Build Instructions`).

1. `cd` into the root of this repository.
1. `ln -s build/compile_commands.json compile_commands.json`.
