add_library(array_deque STATIC array_deque.c array_deque.h)

target_include_directories(array_deque PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)
