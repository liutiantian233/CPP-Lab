#ifndef LAB09_VECTOR_H
#define LAB09_VECTOR_H

#include <string>
using std::string;

struct MathVector {
    // data members, default public
    long x = 0;
    long y = 0;

    // two constructors
    // = default uses default values of data members (above).
    // no other work required. You are welcome!
    MathVector() = default;
    // you must write
    MathVector(long, long);

    // 4 function members you must write
    MathVector add(const MathVector&);
    MathVector multiply(long);
    long multiply(const MathVector&);
    double magnitude();
};

// a function! You must write
string vec_to_str(const MathVector&);

#endif //LAB09_VECTOR_H
