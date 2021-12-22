add_library(queue STATIC queue.c queue.h)
target_include_directories(queue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(tests)
