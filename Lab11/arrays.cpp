#include <stdexcept>
using std::runtime_error;

#include <fstream>
using std::ifstream;

#include "arrays.h"

bool is_even(long l) {
    return l % 2 == 0;
}

void print_array(long ary[], size_t sz, ostream &out) {

    for (auto i = 0; i < sz; ++i) {
        out << ary[i];

        if (i == sz - 1)
            break;

        out << ", ";
    }
}

size_t fill_from_file(long *(&ary), string f_name) {

    int i = 0, index = 0;
    size_t sz = 0;
    string line;
    ifstream file(f_name);

    if (file.is_open()) {
        while (getline(file, line)) {

            if (i == 0) {
                sz = static_cast<size_t>(std::stol(line));
                ary = new long[sz];
                ++i;
            } else
                ary[index++] = std::stol(line);
        }
    } else
        throw runtime_error("Error");

    file.close();
    return sz;
}

size_t concatenate(long *(&ary1), size_t sz1, long ary2[], size_t sz2) {

    auto new_sz = sz1 + sz2;
    long *new_ary = new long[new_sz];
    auto i = 0;

    for (i = 0; i < sz1; ++i)
        new_ary[i] = ary1[i];

    for (auto j = 0; j < sz2; ++j)
        new_ary[i++] = ary2[j];

    delete [] ary1;
    ary1 = new_ary;
    return new_sz;
}

pair<long*, size_t> copy_evens(long ary[], size_t sz) {

    auto even_sz = 0, index = 0;

    for (auto i = 0; i < sz; ++i)
        if (is_even(ary[i]))
            ++even_sz;

    long *even_ary = new long[even_sz];

    for (auto i = 0; i < sz; ++i)
        if (is_even(ary[i]))
            even_ary[index++] = ary[i];

    pair<long*, size_t> p;
    p.first = even_ary;
    p.second = static_cast<size_t>(even_sz);
    return p;
}
