cmake_minimum_required(VERSION 3.5)

project(SPVanilla VERSION 0.0.1)

add_library(SPVanilla SHARED
    ../src/SPBiome.c
    ../src/SPHeight.c
    ../src/SPParticles.c
    ../src/SPRainfall.c
)

set(CMAKE_BUILD_TYPE Release)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set (CMAKE_CXX_STANDARD 11)

include_directories(
    ../../../include
)