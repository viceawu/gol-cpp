cmake_minimum_required(VERSION 3.10.0)
project(gof-cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# GLFW
add_subdirectory(ext/glfw)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)

# glad
add_library(glad STATIC ext/glad/src/glad.c)

target_include_directories(glad PRIVATE ext/glad/include)

# Game Of Life CPP
add_executable("${CMAKE_PROJECT_NAME}" main.cpp)
target_sources("${CMAKE_PROJECT_NAME}" PRIVATE lib/Cell.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ext/glad/include)
# target_include_directories(${PROJECT_NAME} PRIVATE ext/stb/include)

configure_file(${CMAKE_SOURCE_DIR}/logo.png ${CMAKE_CURRENT_BINARY_DIR}/logo.png COPYONLY)

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glfw glad ${CMAKE_DL_LIBS})
