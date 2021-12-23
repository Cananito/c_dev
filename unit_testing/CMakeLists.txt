add_library(unit_testing STATIC unit_testing.c unit_testing.h)

target_include_directories(unit_testing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
