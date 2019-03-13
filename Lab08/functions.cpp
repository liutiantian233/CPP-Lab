#include "functions.h"

#include <vector>
using std::vector;

#include <string>
using std::string; using std::to_string;

#include <map>
using std::map;

#include <utility>
using std::pair;

#include <stdexcept>
using std::range_error;

#include <iostream>

long collatz_next(long n) {
    if (n <= 0)
        throw range_error("Range Error");
    if (n == 1)
        return n;
    if (n % 2 == 0)
        return n / 2;
    return 3 * n + 1;
}

string Collatz_to_string(const Collatz &p) {
    string str = to_string(p.first) + ": ";
    auto v = p.second;
    str += to_string(v[0]);
    for (auto i = 1; i < v.size(); ++i)
        str += "," + to_string(v[i]);
    return str;
}

string sequence_in_map_to_string(map<long, vector<long>> &m, long number) {
    auto key = m.find(number);
    if (key != m.end())
        return Collatz_to_string(*key);
    return "";
}

vector<long> collatz_sequence(map<long, vector<long>> &m, long number) {
    vector<long> v;
    if (number == 1)
        v.push_back(number);
    while (number != 1) {
        if (m.find(number) == m.end()) {
            number = collatz_next(number);
            v.push_back(number);
            continue;
        }
        vector<long> vec = m.find(number)->second;
        for (long i : vec)
            v.push_back(i);
        break;
    }
    return v;
}

void collatz_range(map<long, vector<long>> &m, long low, long high) {
    for (auto num = low; num <= high; ++num) {
        vector<long> v = collatz_sequence(m, num);
        m[num] = v;
    }
}
