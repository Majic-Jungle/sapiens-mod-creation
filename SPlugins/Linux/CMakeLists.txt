cmake_minimum_required(VERSION 3.5)

project(SPCommon VERSION 0.0.1)

add_library(SPCommon SHARED
    ../src/SPMath.c
    ../src/SPNoise.c
    ../src/SPRand.c
)

set(CMAKE_BUILD_TYPE Release)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../lib)
set (CMAKE_CXX_STANDARD 11)

include_directories(
    ../include
)