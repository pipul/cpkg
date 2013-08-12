cmake_minimum_required(VERSION 2.6)
aux_source_directory(. DIR_SRCS)
add_executable(test ${DIR_SRCS})
set(CMAKE_C_FLAGS "-O0 -g")
