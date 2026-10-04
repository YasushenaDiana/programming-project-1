#include "Output.h"
#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int WIDTH = 12;
const int PRECISION = 4;
const vector<double> RATIOS = {0.25, 0.5, 1.0, 2.0, 5.0, 10.0};

string fixed_text(double value)
{
    return format("{:.{}f}", value, PRECISION);
}

string column(double value)
{
    return format("{:{}.{}f}", value, WIDTH, PRECISION);
}

string whole(int value)
{
    return format("{:{}}", value, WIDTH);
}

string title(const string &text)
{
    return format("{:>{}}", text, WIDTH);
}

void show(int n, int m, const Stats &s)
{
    double ratio = static_cast<double>(m) / cells_count(n);
    cout << "Board: " << n << " x " << n << ", picks: " << m << endl;
    cout << "Ratio m / n^2: " << fixed_text(ratio) << endl;
    cout << "Average multiplicity (all cells): " << fixed_text(s.mean) << endl;
    cout << "Average multiplicity (picked cells only): " << fixed_text(s.mean_picked) << endl;
    cout << "Median multiplicity: " << fixed_text(s.median) << endl;
    cout << "Max multiplicity: " << s.max_count << endl;
    cout << "Min multiplicity: " << s.min_count << endl;
    cout << "Never picked cells: " << fixed_text(s.never_ratio)
         << " (expected " << fixed_text(expected_never(n, m)) << ")" << endl;
    cout << endl;
}

void experiment(int n, int max_m)
{
    int cells = cells_count(n);
    cout << "Experiment for n = " << n << endl;
    cout << title("m/n^2") << title("mean") << title("median")
         << title("mean picked") << title("max")
         << title("never") << title("exp never") << endl;
    for (double ratio : RATIOS)
    {
        int m = static_cast<int>(llround(ratio * cells));
        if (m < 1 || m > max_m)
            continue;
        Stats s = compute_stats(n, m);
        cout << column(ratio) << column(s.mean) << column(s.median)
             << column(s.mean_picked) << whole(s.max_count)
             << column(s.never_ratio) << column(expected_never(n, m)) << endl;
    }
}