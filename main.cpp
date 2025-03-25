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

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return 3;
    }

    GLFWimage images[1]; 
    images[0].pixels = stbi_load("logo.png", &images[0].width, &images[0].height, 0, 4); //rgba channels
    if (images[0].pixels != NULL) glfwSetWindowIcon(window, 1, images);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.f, 0.f, 0.f, 0.f);

        glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    
        glPushMatrix();
        glTranslatef(1.f, 0.f, 0.f);
        glBegin(GL_QUADS);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-0.2f, -0.2f, 0.f);
        glVertex3f(0.2f, -0.2f, 0.f);
        glVertex3f(0.2f, 0.2f, 0.f);
        glVertex3f(-0.2f, 0.2f, 0.f);
        glEnd();
        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
