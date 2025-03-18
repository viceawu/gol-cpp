#include <iostream>
#include <vector>

// GLAD
#include <glad/glad.h>

// GLFW (include after glad)
#include <GLFW/glfw3.h>

#include "lib/Cell.h"

// TODO move this shit elsewere :: incapsulate into scene!

int get_index(const int& i, const int& j, const int& height, const int& length) {
    // field is considered cyclical on the edges
    int corrected_i = ((i % height) + height) % height;
    int corrected_j = ((j % length) + length) % length;
    return i * length + j;
}

int count_neighbours(std::vector<Cell>& scene, const int& i, const int& j, const int& height, const int& length) {
    int count = 0;

    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;

            count += scene[get_index(i + di, j + dj, height, length)];
        }
    }

    return count;
}

void step(std::vector<Cell>& scene, const int& height, const int& length) {
    // std::vector<int> scene_copy(scene);

    // Iterate over all of the cells, count neighbours and update accordingly
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << scene[i * length + j];
        }
        std::cout << "\n";
    }
}

int main(int, char**){
    // TODO: remove constatnts
    int height = 20;
    int length = 40;
    std::vector<Cell> scene(height * length);

    // testing code, will remove later...
    scene[get_index(1, 2, height, length)] = is_alive;
    scene[get_index(2, 3, height, length)] = is_alive;
    scene[get_index(3, 1, height, length)] = is_alive;
    scene[get_index(3, 2, height, length)] = is_alive;
    scene[get_index(3, 3, height, length)] = is_alive;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << scene[i * length + j];
        }
        std::cout << "\n";
    }

    std::cout << count_neighbours(scene, 1, 2, height, length) << "\n";

    GLFWwindow* window = glfwCreateWindow(640, 480, "LearnOpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    return 0;
}
