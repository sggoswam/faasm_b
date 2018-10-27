#ifndef FAASM_RANDOM_H
#define FAASM_RANDOM_H

#include <random>

namespace faasm {
    int randomInteger(int iStart, int iEnd) {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(iStart, iEnd);

        int random_integer = uni(rng);

        return random_integer;
    }
}

#endif
