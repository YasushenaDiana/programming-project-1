#pragma once

#include <map>
#include <vector>
#include "Cell.h"

struct Stats
{
    double mean;
    double mean_picked;
    double median;
    int max_count;
    int min_count;
    double never_ratio;
};

int cells_count(int n);
double expected_never(int n, int m);
std::map<Cell, int> pick_cells(int n, int m);
std::vector<int> make_values(const std::map<Cell, int> &counts, int cells);
double find_median(const std::vector<int> &values);
<<<<<<< HEAD:stats.h
Stats compute_stats(int n, int m); 
=======
Stats compute_stats(int n, int m);
>>>>>>> c59d805f0293ffe752c717890766eeb3477a8813:Stats.h
