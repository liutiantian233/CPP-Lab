#include <stdexcept>
using std::runtime_error;

#include "functions.h"

CircBuf::CircBuf(size_t sz) {
    sz_ = sz;
    cnt_ = 0;
    for (int i = 0; i < sz_; ++i)
        buf_.push_back(0);
    head_ = 0;
    tail_ = 0;
}

CircBuf::CircBuf(initializer_list<long> list, size_t sz) {
    if (sz < list.size())
        throw runtime_error("Error");
    sz_ = sz;
    cnt_ = list.size();
    buf_ = list;
    for (auto i = cnt_; i < sz_; ++i)
        buf_.push_back(0);
    head_ = 0;
    tail_ = cnt_ % sz_;
}

long CircBuf::front() const {
    if (empty())
        throw runtime_error("Error");
    return buf_[head_];
}

long CircBuf::back() const {
    if (empty())
        throw runtime_error("Error");
    if (tail_ == 0)
        return buf_[buf_.size() - 1];
    return buf_[tail_ - 1];
}

bool CircBuf::empty() const {
    return cnt_ == 0;
}

bool CircBuf::full() const {
    return cnt_ == sz_;
}

void CircBuf::add(long value) {
    if (full())
        throw runtime_error("Error");
    buf_[tail_] = value;
    tail_ = (tail_ + 1) % sz_;
    cnt_ = cnt_ + 1;
}

void CircBuf::remove() {
    if (empty())
        throw runtime_error("Error");
    head_ = (head_ + 1) % sz_;
    cnt_ = cnt_ - 1;
}

ostream&operator << (ostream &out, const CircBuf &cb) {
    if (cb.empty()) {
        out << "CircBuf empty";
        return out;
    }
    out << "Front:" << cb.front() << ", ";
    out << "Back:" << cb.back() << ", ";
    out << "Cnt:" << cb.cnt_ << ", ";
    out << "Sz:" << cb.sz_ << "\n";
    for (int i = 0; i < cb.sz_; ++i) {
        out << cb.buf_[i];
        if (i == cb.sz_ - 1)
            break;
        out << ", ";
    }
    return out;
}
