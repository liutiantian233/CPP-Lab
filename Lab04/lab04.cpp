#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

// note you need algorithm and sort
#include <algorithm>
using std::sort;

#include <cmath>

long loc_to_dec(string loc) {
    auto dec = 0;
    auto exp = 0;
    for (char c : loc) {
        exp = c - 'a';
        dec += pow(2, exp);
    }
    return dec;
}

string abbreviate(string loc) {
    for (unsigned i = 0; i < loc.size(); ++i) {
        while (loc[i] == loc[i + 1]) {
            loc.replace(i, 2, 1, char(loc[i] + 1));
            sort(loc.begin(), loc.end());
        }
    }
    return loc;
}

string dec_to_loc(long dec) {
    string str;
    for (int i = 0; i < dec; ++i)
        str.push_back('a');
    return abbreviate(str);
}

long add_loc(string loc1, string loc2) {
    string loc = loc1 + loc2;
    sort(loc.begin(), loc.end());
    loc = abbreviate(loc);
    return loc_to_dec(loc);
}

int main() {
    string loc;
    long num;
    cin >> loc >> num;
    cout << loc_to_dec(loc) << " ";
    cout << abbreviate(loc) << " ";
    cout << dec_to_loc(num) << " ";
    cout << add_loc(abbreviate(loc), abbreviate(loc)) << endl;
}
