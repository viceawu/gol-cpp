cmake_minimum_required(VERSION 3.10.0)
project(GAME_OF_LIFE_CPP VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable("${CMAKE_PROJECT_NAME}" main.cpp)
target_sources("${CMAKE_PROJECT_NAME}" PRIVATE lib/Cell.cpp)
