#ifndef LAB12_VECTOR_H
#define LAB12_VECTOR_H

#include <algorithm>
using std::copy;

#include <stdexcept>
using std::range_error;

#include <initializer_list>
using std::initializer_list;

namespace student {

    template <typename T>
    class vector {

    private:
        T * data_ = nullptr;
        size_t capacity_;
        size_t size_ = 0;

    public:
        explicit vector(size_t capacity = 10);
        vector(initializer_list<T> list);
        vector(vector<T>&);
        vector<T>& operator = (vector<T>);
        ~vector();

        size_t capacity();
        size_t size();
        void push_back(T);

        T& operator [] (size_t);
        T& front();
        T& back();

        void clear();
        T pop_back();
    };

    template <typename T>
    vector<T>::vector(size_t capacity) {
        capacity_ = capacity;
        size_ = 0;
        data_ = new T [capacity]{};
    }

    template <typename T>
    vector<T>::vector(initializer_list<T> list) {
        capacity_ = list.size();
        size_ = list.size();
        data_ = new T [capacity_]{};
        copy(list.begin(), list.end(), data_);
    }

    template <typename T>
    vector<T>::~vector() {
        delete [] data_;
    }

    template <typename T>
    size_t vector<T>::capacity() {
        return capacity_;
    }

    template <typename T>
    size_t vector<T>::size() {
        return size_;
    }

    template <typename T>
    void vector<T>::push_back(T value) {
        if (size_ == capacity_) {
            capacity_ *= 2;
            T * new_data = new T [capacity_]{};

            copy(data_, data_ + size_, new_data);
            std::swap(data_, new_data);
            delete [] new_data;
        }
        data_[size_] = value;
        size_ += 1;
    }

    template <typename T>
    T& vector<T>::operator [] (size_t value) {
        if (value < size_ and value >= 0)
            return data_[value];
        throw range_error("Range Error");
    }

    template <typename T>
    vector<T>::vector(student::vector<T> &vector) {
        capacity_ = vector.capacity_;
        size_ = vector.size_;

        T * new_array = new T [capacity_]{};
        copy(vector.data_, vector.data_ + size_, new_array);

        std::swap(data_, new_array);
        delete [] new_array;
    }

    template <typename T>
    vector<T>& vector<T>::operator = (student::vector<T> vector) {
        std::swap(capacity_, vector.capacity_);
        std::swap(size_, vector.size_);
        std::swap(data_, vector.data_);
        return *this;
    }

    template <typename T>
    T& vector<T>::front() {
        if (size_ == 0)
            throw range_error("Range Error");
        return data_[0];
    }

    template <typename T>
    T& vector<T>::back() {
        if (size_ == 0)
            throw range_error("Range Error");
        return data_[size_ - 1];
    }

    template <typename T>
    void vector<T>::clear() {
        capacity_ = 0;
        size_ = 0;
        delete [] data_;
        data_ = nullptr;
    }

    template <typename T>
    T vector<T>::pop_back() {
        T end;
        end = data_[size_ - 1];
        T * new_array = new T [capacity_]{};

        copy(data_, data_ + size_ - 1, new_array);
        size_ -= 1;
        delete [] new_array;

        if (size_ == capacity_ / 2) {
            T * new_data = new T [capacity_ / 2]{};
            copy(data_, data_ + size_, new_data);
            delete [] new_data;
        }
        return end;
    }
}

#endif //LAB12_VECTOR_H
