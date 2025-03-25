#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "ext/stb/include/stb_image.h"

static void glfwError(int id, const char* description) {
    std::cout << description << std::endl;
}

int main(int, char**){
    glfwSetErrorCallback(&glfwError);
    if (!glfwInit()) return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Game of Life", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return 2;
    }

    GLFWimage images[1]; 
    images[0].pixels = stbi_load("logo.png", &images[0].width, &images[0].height, 0, 4); //rgba channels
    if (images[0].pixels != NULL) glfwSetWindowIcon(window, 1, images);

    while (!glfwWindowShouldClose(window)) {
        // render(window);
    
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
