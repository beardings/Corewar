cmake_minimum_required(VERSION 3.7)
project(Corewar)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES vm/controller/main.c
        vm/includes/vm.h
        vm/controller/get_flags.c
        libft/libft/ft_strcmp.c
        libft/libft/ft_atoi.c
        libft/libft/ft_isdigit.c)

add_executable(Corewar ${SOURCE_FILES})