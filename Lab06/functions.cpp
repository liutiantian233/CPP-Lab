#include "functions.h"

#include <iostream>
#include <vector>

using std::vector;
using std::string;

vector<string> split(const string &s, char separator) {
    string str = s;
    vector<string> vec;
    auto index = str.find(separator);
    while (index != string::npos) {
        vec.push_back(str.substr(0, index));
        str = str.substr(index + 1);
        index = str.find(separator);
    }
    vec.push_back(str);
    return vec;
}

vector<long> vector_ops(const vector<long> &v1, const vector<long> &v2, char op) {
    vector<long> vec;
    int i = 0;
    if (v1.size() < v2.size()) {
        if (op == '+') {
            for (i = 0; i < v1.size(); ++i)
                vec.push_back(v1[i] + v2[i]);
            while (i < v2.size()) {
                vec.push_back(v2[i]);
                ++i;
            }
            return vec;
        }
        else
            if (op == '-') {
                for (i = 0; i < v1.size(); ++i)
                    vec.push_back(v2[i] - v1[i]);
                while (i < v2.size()) {
                    vec.push_back(v2[i]);
                    ++i;
                }
                return vec;
            }
            else
                return vec;
    }
    return vector_ops(v2, v1, op);
}

void print_vector(ostream &out, const vector<string> &v) {
    for (const auto &i : v)
        out << i << endl;
}

void print_vector(ostream &out, const vector<long> &v) {
    for (const auto &i : v)
        out << i << endl;
}
