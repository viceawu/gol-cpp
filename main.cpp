#include <iostream>
#include <vector>

#include "lib/Cell.h"

int get_index(const int& i, const int& j, const int& height, const int& length) {
    int corrected_i = ((i % height) + height) % height;
    int corrected_j = ((j % length) + length) % length;
    return i * length + j;
}

void step(std::vector<Cell>& scene, const int& height, const int& length) {

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

    return 0;
}
