#ifndef LAB13_SINGLELINK_H
#define LAB13_SINGLELINK_H

#include <iostream>
using std::ostream; using std::cout; using std::endl;

#include <utility>
using std::swap;

#include <stdexcept>
using std::out_of_range;

template <typename T>
struct Node {

public:
    Node * next_ = nullptr;
    T data_;

    Node() : data_(T()), next_(nullptr) {};
    explicit Node(T d) : data_(d), next_(nullptr) {};
};

template <typename T> ostream& operator << (ostream &os, const Node<T> &node) {
    os << node.data_;
    if (node.next_ != nullptr)
        os << "," << *node.next_;
    return os;
}

template <typename T>
class SingleLink {

private:
    Node<T> * head_ = nullptr;
    Node<T> * tail_ = nullptr;

public:
    SingleLink();
    explicit SingleLink(const T& dat);
    void append_back(const T&);
    
    friend ostream& operator << (ostream &out, SingleLink<T>& s) {
        // FIX HERE
        if (s.head() == nullptr)
            return out;
        return out << *s.head();
    }
    bool del(const T& value);
    Node<T>& operator [] (size_t index);

    // Rule of three stuff, if you get time. Look at 21.2
    ~SingleLink();
    SingleLink(const SingleLink<T>&);
    SingleLink<T>& operator = (SingleLink<T>);

    Node<T> * &head();
};

// YOUR STUFF HERE
template <typename T>
SingleLink<T>::SingleLink() {
    head_ = nullptr;
    tail_ = nullptr;
}

template <typename T>
SingleLink<T>::SingleLink(const T &dat) {
    head_ = new Node<T> (dat);
    tail_ = new Node<T> (dat);
}

template <typename T>
void SingleLink<T>::append_back(const T &dat) {
    if (head_ == nullptr) {
        head_ = new Node<T> (dat);
        tail_ = new Node<T> (dat);
    } else {
        tail_ = tail_->next_ = new Node<T> (dat);
    }
}

template <typename T>
Node<T>& SingleLink<T>::operator [] (size_t index) {}

template <typename T>
Node<T>* & SingleLink<T>::head() {
    return head_;
}

template <typename T>
SingleLink<T>& SingleLink<T>::operator = (SingleLink<T> other) {
    swap(head_, other.head_);
    swap(tail_, other.tail_);
    return *this;
}

template <typename T>
SingleLink<T>::~SingleLink() {
    for (auto * point = head_; point != nullptr;) {
        auto * next = point->next_;
        delete point;
        point = next;
    }
}

template <typename T>
SingleLink<T>::SingleLink(const SingleLink<T> &other) {
    if (other.head_ == nullptr)
        return;

    head_ = new Node<T> (*other.head_);
    auto * point = head_;
    for (auto * item = other.head_->next_; item != nullptr; item = item->next_) {
        point->next_ = new Node<T> (*item);
        point = point->next_;
    }
}

template <typename T>
bool SingleLink<T>::del(const T &value) {}

#endif //LAB13_SINGLELINK_H
