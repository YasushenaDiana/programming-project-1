//Diana Yasushenaʼs Compiler: Apple Clang 21.0.0 (CLion, macOS), C++23
//Anhelina Svintsitskaʼs Compiler: Microsoft Visual C++ (MSVC), VS Code, Windows, C++23


#include <iostream>
#include <string>
#include <stdexcept>
#include "Input.h"
#include "Output.h"
#include "Stats.h"

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000000;

int main()
{
    try
    {
        int n = read_value("Enter board size n (1.." + to_string(MAX_N) + "): ", 1, MAX_N);
        int m = read_value("Enter number of picks m (1.." + to_string(MAX_M) + "): ", 1, MAX_M);
        cout << endl;
        show(n, m, compute_stats(n, m));
        experiment(n, MAX_M);
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}