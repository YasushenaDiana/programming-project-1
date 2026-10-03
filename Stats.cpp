#include "Stats.h"
#include "RandomCell.h"
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>

using namespace std;

const int TWO = 2;

int cells_count(int n)
{
    return n * n;
}

double expected_never(int n, int m)
{
    double miss = 1.0 - 1.0 / cells_count(n);
    return pow(miss, m);
}

map<Cell, int> pick_cells(int n, int m)
{
    RandomCell next(n);
    map<Cell, int> counts;
    for (int i = 0; i < m; ++i)
        ++counts[next()];
    return counts;
}

vector<int> make_values(const map<Cell, int> &counts, int cells)
{
    vector<int> values;
    for_each(counts.begin(), counts.end(),
             [&values](const pair<const Cell, int> &p)
             { values.push_back(p.second); });
    int never = cells - static_cast<int>(counts.size());
    values.insert(values.end(), static_cast<size_t>(never), 0);
    sort(values.begin(), values.end(), greater<int>());
    return values;
}

double find_median(const vector<int> &values)
{
    size_t size = values.size();
    if (size % TWO == 0)
        return (values[size / TWO - 1] + values[size / TWO]) / static_cast<double>(TWO);
    return values[size / TWO];
}

Stats compute_stats(int n, int m)
{
    int cells = cells_count(n);
    map<Cell, int> counts = pick_cells(n, m);
    vector<int> values = make_values(counts, cells);
    int picked = static_cast<int>(counts.size());
    int sum = accumulate(values.begin(), values.end(), 0, plus<int>());

    Stats s;
    s.mean = static_cast<double>(sum) / cells;
    s.mean_picked = static_cast<double>(sum) / picked;
    s.median = find_median(values);
    s.max_count = values.front();
    s.min_count = values.back();
    s.never_ratio = static_cast<double>(cells - picked) / cells;
    return s;
}