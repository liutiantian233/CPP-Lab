#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

// note you need algorithm and sort
#include <algorithm>
using std::sort;

/*
sort individual characters of a string
*/

int main() {
  string my_str = "aebcd";
  cout << "String was:" << my_str;
  sort(my_str.begin(), my_str.end());
  cout << ", and sorted is:" << my_str <<endl;
}
