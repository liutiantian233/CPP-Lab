#ifndef LAB13_SINGLELINK_H
#define LAB13_SINGLELINK_H

#include <iostream>
using std::ostream; using std::cout; using std::endl;

template <typename T>
struct Node {

public:
    Node * next_;
    T data_;

    Node() : data_(T()), next_(nullptr) {};
    Node(T d) : data_(d), next_(nullptr) {};
};

template <typename T>
class SingleLink {

private:
    Node<T> * head_;
    Node<T> * tail_;

public:
    SingleLink();
    SingleLink(T dat);
    void append_back(T);
    friend ostream& operator << (ostream &out, SingleLink<T>& s) {
        // FIX HERE
    }
    bool del(T val);
    Node<T>& SingleLink<T>::operator[](size_t index);

    // Rule of three stuff, if you get time. Look at 21.2
    ~SingleLink();
    SingleLink(const SingleLink&);
    SingleLink& operator = (SingleLink);
};

// YOUR STUFF HERE

#endif //LAB13_SINGLELINK_H
