#include <iostream>
#include <vector>

#include "lib/Cell.h"

void step(std::vector<Cell>& , const int& height, const int& length) {

}

int main(int, char**){
    // TODO: remove constatnts
    int height = 20;
    int length = 40;
    std::vector<Cell> scene(height * length);

    // testing code, will remove later...
    scene[1 * length + 2] = is_alive;
    scene[2 * length + 3] = is_alive;
    scene[3 * length + 1] = is_alive;
    scene[3 * length + 2] = is_alive;
    scene[3 * length + 3] = is_alive;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << scene[i * length + j];
        }
        std::cout << "\n";
    }

    return 0;
}
