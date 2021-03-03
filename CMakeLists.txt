cmake_minimum_required(VERSION 3.17)
project(C)

set(CMAKE_C_STANDARD 99)

add_executable(main1 lab1/main_1.c)
add_executable(Test lab1/Test.c)
add_executable(main2 lab2/main.c lab2/stack.c)
add_executable(test1 test.c)
add_executable(main2.2 lab2/main2.c lab2/stack.c)