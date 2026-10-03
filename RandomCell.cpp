#include "RandomCell.h"
#include <stdexcept>

using namespace std;

int valid_size(int n)
{
    if (n <= 0)
        throw invalid_argument("Board size must be positive");
    return n;
}

RandomCell::RandomCell(int n) : dist(0, valid_size(n) - 1)
{
    random_device r;
    seed_seq seeds{r(), r(), r(), r()};
    engine.seed(seeds);
}

Cell RandomCell::operator()()
{
    Cell c;
    c.row = dist(engine);
    c.col = dist(engine);
    return c;
}