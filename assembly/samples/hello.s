.global start
.intel_syntax noprefix

// Run instructions on Intel macOS:
//   1. Assemble:
//     $ as hello.s -o hello.o
//   2. Link:
//     $ clang -o hello hello.o -nostdlib -static
//   3. Run:
//     $ ./hello

// System call registers:
// https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

// System call rax codes:
// https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master

start:
  mov rax, 0x2000004 // write() syscall code
  mov rdi, 1 // file descriptor param
  lea rsi, hello_world[rip] // buffer param
  mov rdx, 15 // count param
  syscall

  mov rax, 0x2000001 // exit() syscall code
  mov rdi, 69 // exit code param
  syscall

hello_world:
  .asciz "Hello, world!\n"

