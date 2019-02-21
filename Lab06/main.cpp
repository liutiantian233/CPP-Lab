#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;

using std::string;
using std::vector;

#include "functions.h"

int main() {
    string str;
    char separator;
    cout << "Enter String" << endl;
    getline(cin, str);
    cout << "Enter Separator" << endl;
    cin >> separator;
    vector<string> vec = split(str, separator);
    print_vector(cout, vec);

    vector<long> v1 = {1,2,3};
    vector<long> v2= {4,5};
    vector<long> v3;

    v3 = vector_ops(v1,v2,'+');
    print_vector(cout, v3);
    v3 = vector_ops(v1, v2, '-');
    print_vector(cout, v3);
    v3 = vector_ops(v1,v2,'?');
    print_vector(cout, v3);
}
