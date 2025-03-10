#ifndef CELL_H
#define CELL_H

#include <ostream>

enum Cell {
    is_dead = 0,
    is_alive = 1
};

std::ostream& operator<<(std::ostream& os, const Cell& cell);

#endif