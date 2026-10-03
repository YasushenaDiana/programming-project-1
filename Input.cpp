#include "Input.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

bool parse_number(const string &line, int &x)
{
    istringstream stream(line);
    return (stream >> x) && (stream >> ws).eof();
}

int read_value(const string &text, int low, int high)
{
    string line;
    int x;
    while (true)
    {
        cout << text;
        if (!getline(cin, line))
            throw runtime_error("Input ended unexpectedly");
        if (parse_number(line, x) && x >= low && x <= high)
            return x;
        cout << "Invalid input, try again" << endl;
    }
}