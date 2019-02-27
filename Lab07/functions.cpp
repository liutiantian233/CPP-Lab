#include "functions.h"

#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <iostream>
using std::endl;

using matrix_row = vector<long>;

using matrix = vector<matrix_row>;

string matrix_to_str(const matrix &m, size_t width) {
    ostringstream oss;
    for (const auto &row : m) {
        for (auto col : row)
            oss << setw(static_cast<int>(width)) << col;
        oss << endl;
    }
    string str = oss.str();
    return str.substr(0, str.size() - 1);
}

bool same_size(matrix &m1, matrix &m2) {
    if (m1.size() != m2.size())
        return false;
    for (int row = 0; row < m1.size(); ++row) {
        matrix_row row1 = m1[row];
        matrix_row row2 = m2[row];
        if (row1.size() != row2.size())
            return false;
    }
    return true;
}

matrix add(matrix &m1, matrix &m2) {
    matrix mx;
    if (same_size(m1, m2)) {
        for (int row = 0; row < m1.size(); ++row) {
            matrix_row row1 = m1[row];
            matrix_row row2 = m2[row];
            matrix_row col;
            for (int c = 0; c < row1.size(); ++c)
                col.push_back(row1[c] + row2[c]);
            mx.push_back(col);
        }
    }
    return mx;
}

matrix scalar_multiply(matrix &m, long val) {
    matrix mx;
    for (const auto &row : m) {
        matrix_row col;
        for (auto c : row)
            col.push_back(val * c);
        mx.push_back(col);
    }
    return mx;
}
