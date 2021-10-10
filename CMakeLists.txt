cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS -lm)

add_executable(fibonacci HW_1/fibonacci.c)
add_executable(power HW_1/power.c)
add_executable(array_sign HW_1/array_sign.c)
add_executable(primes HW_1/primes.c)
add_executable(count_substrings HW_1/count_substrings.c)
add_executable(palindrome HW_1/palindrome.c)

add_executable(bitwise HW_2/bitwise.c)
