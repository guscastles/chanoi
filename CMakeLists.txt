cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(hanoi LANGUAGES C)
list(APPEND flags "-Wall" "-g")

include_directories(
    ~/.local/include
    include
)
link_directories(~/.local/lib)
add_library(hanoi_func
    STATIC
        src/hanoi_func.c
)

target_link_libraries(hanoi_func list)
add_executable(hanoi src/hanoi.c)
target_compile_options(hanoi
    PRIVATE
        ${flags}
)
target_compile_options(hanoi_func
    PRIVATE
        ${flags}
)
target_link_libraries(hanoi hanoi_func)

add_library(test_hanoi
    STATIC
        test/test_hanoi.c
)
target_link_libraries(test_hanoi hanoi_func)
add_executable(unittest test/unittest.c)
target_link_libraries(unittest test_hanoi cunit)

enable_testing()
add_test(
    NAME unittest
    COMMAND $<TARGET_FILE:unittest>
)
