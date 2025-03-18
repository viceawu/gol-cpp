#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

static void glfwError(int id, const char* description) {
    std::cout << description << std::endl;
}

int main(int, char**){
    glfwSetErrorCallback(&glfwError);
    if (!glfwInit()) return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "I FUCKING MADE A WINDOW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return 1;
    }

    while (true) {}

    glfwTerminate();
    return 0;
}
