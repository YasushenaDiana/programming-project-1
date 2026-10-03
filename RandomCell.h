#pragma once

#include <random>
#include "Cell.h"

int valid_size(int n);

class RandomCell
{
    std::mt19937 engine;
    std::uniform_int_distribution<int> dist;

public:
    RandomCell(int n);
    Cell operator()();
};