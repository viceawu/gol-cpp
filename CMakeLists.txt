cmake_minimum_required(VERSION 3.10.0)
project(game_of_life VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
project(GAME_OF_LIFE_CPP)

add_executable(game_of_life main.cpp)
target_sources(game_of_life PRIVATE lib/Cell.cpp)
