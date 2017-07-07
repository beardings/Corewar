cmake_minimum_required(VERSION 3.7)
project(Corewar)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c)
add_executable(Corewar ${SOURCE_FILES})