#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include <utility>
using std::pair;

#include <stdexcept>
using std::range_error;

#include <iostream>

#include "functions.h"

int main() {
    std::cout << collatz_next(4) << std::endl;
    std::cout << collatz_next(25) << std::endl;

    Collatz c = {16, {8, 4, 2, 1}};
    string s = Collatz_to_string(c);
    std::cout << s << std::endl;

    map<long, vector<long>> m = {{4, {2, 1}}};
    vector<long> v = collatz_sequence(m, 16);
    for (auto ver : v) {
        std::cout << ver << std::endl;
    }
}
