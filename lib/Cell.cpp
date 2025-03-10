#include "Cell.h"

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    switch(cell) {
        case is_dead:
            os << "░░";
            break;
        case is_alive:
            os << "▓▓";
            break;
        default:
            os.setstate(std::ios_base::failbit);
            break;
    }
    return os;
}
