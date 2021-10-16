#cmake_minimum_required (VERSION 2.8)
project(helloworld)
#include_directories(include) 
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
set(SRCS ${DIR_SRCS})
message(${DIR_SRCS})
add_executable(helloworld ${SRCS})

