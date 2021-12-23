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
1. Optionally, to enable debugging, `cmake -DCMAKE_BUILD_TYPE=Debug ..`.
1. `cmake --build .`. This will build the code.

## Run Instructions

1. Follow the [build instructions](#build-instructions).
1. Find the executable and run it. Example: `./data_structures/queue/tests/queue_tests`

## Debug Instructions

1. Follow the [build instructions](#build-instructions), including the optional step.
1. Find the executable and pass it to LLDB. Example: `lldb data_structures/queue/tests/queue_tests`

## Clean Instructions

1. From the `build` directory, run `cmake --build . --target clean`

## clangd Set-Up

1. Follow the [build instructions](#build-instructions).
1. `cd` into the root of this repository.
1. `ln -s build/compile_commands.json compile_commands.json`.
