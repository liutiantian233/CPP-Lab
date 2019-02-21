#ifndef LAB06_FUNCTIONS_H
#define LAB06_FUNCTIONS_H

#include <iostream>

#include <vector>
#include <string>

using namespace std;

vector<string> split(const string &s, char separator = ' ');

vector<long> vector_ops(const vector<long> &v1, const vector<long> &v2, char op);

void print_vector(ostream &out, const vector<string> &v);

void print_vector(ostream &out, const vector<long> &v);

#endif //LAB06_FUNCTIONS_H
