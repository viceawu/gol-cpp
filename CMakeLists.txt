cmake_minimum_required(VERSION 3.10.0)
project(gof-cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Game Of Life CPP
add_executable("${CMAKE_PROJECT_NAME}" main.cpp)
target_sources("${CMAKE_PROJECT_NAME}" PRIVATE lib/Cell.cpp)

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE SFML::Graphics)