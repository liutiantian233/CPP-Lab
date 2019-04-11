# The Problem

We are going to work on making our own container class with dynamic memory. We are going to build our own version of a vector that is templated, as it should be.

## Namespaces

We have talked a lot about namespaces but really haven't used them ourselves. It turns out we can easily define our own namespaces to separate code that we have defined from code in the standard library. We are going to do that here, define a namespace called `student` in which we will place a class `vector`. Though `vector` has the same name as in the STL, because we store it in our own namespace we can change just a single line of code to use our namespace student version of vector or the STL version.

## Making a namespace

Turns out it is rather easy to make a namespace. You can enclose all the code you want to define in a namespace in brackets lead by a declaration of the namespace. For example:

```c++
namespace student {
    template <typename T>
    class vector {}
}
```

Everything in curly brackets is now part of the `student` namespace. You can add things to the student namespace by simply adding other namespace student elements in the code. To use your new namespace (with your new vector class), you would use:

```c++
student::vector
```

instead of

```c++
std::vector
```

# Task 1

- Create a `lab12_vector.h` file
  - because we are creating a templated class, everything goes in the header. We won't have a `vector.cpp`.
- In `lab12_vector.h` create a namespace `student` as described above.
- In namespace `student`, create a templated `vector` class with the following private features:
  - a pointer `data_` of template type which points to dynamically allocated memory
  - a `size_t capacity_`, default 10, which is the capacity of the vector. Remember, capacity is how many elements it could hold before having to grow.
  - a `size_t size_`, default 0, the number of elements actually in the vector.

## 4 methods

- a 1-arg constructor with argument `size_t capacity_`. It will do the following:
  - set `capacity_` to the argument (or 10 if no argument using the default)
  - set `size_` to 0
  - set `data_` to point to a dynamically allocated memory element of template type, and the size of that array will be the `capacity_` value (default 10)
- a 1-arg constructor with an `initializer_list`. It will do the following:
  - set `capacity_` and `size_` to `initializer_list.size()`
  - set `data_` to point to a dynamically allocated memory element of template type, the size of which is the `initializer_list.size()`
  - copy the values from the `initializer_list` to `data_`
    - remember, the `initializer_list` should be of the template type
- a method `size_t capacity()`
  - returns the `capacity_` value
- a method `size_t size()`
  - returns the `size_` value

# Task 2

Create two important methods

- `void push_back(templatetype value);`
- `templatetype& operator [] (size_t value);`

## `push_back`

Takes a single parameter of template type and adds it to the end of the vector.

Remember the special functionality of `push_back`. It adds the provided parameter to the end of the vector. The parameter should be of template type. The end of the vector is the next open space. If `push_back` of the parameter does not exceed `capacity_`, just add it to the end and update `size_`.

However, the next `push_back` might exceed the size of your memory. That's fine, remember a vector is never full (well, unless your machine runs out of memory). The `capacity_` of `vector` indicates how many elements it **can hold** before the memory pointed to by `data_` needs to grow. `size_` indicates how many it **actually**, presently holds. If a `push_back` exceeds `capacity_`, (if `size_` equals or exceeds `capacity_` by adding this new parameter) you must do the following:

- Create a new memory allocation that is **twice the size** of present `capacity_`
  - call the new pointer `new_data`
- copy all the elements in `data_` into `new_data`
- swap `data_` and `new_data` (now `data_` points to the larger memory)
- delete `new_data` (which now points to the old memory)
- update `capacity_`
- `push_back` the new element onto vector
- update `size_` by 1

## `operator []`

This is the operator that allows us to work with individual elements in our vector. `operator []` receives a single `size_t` argument which is the **index** in the original call and returns a **reference** to the element. It needs to be a reference so that what is returned is an lvalue (a location) so that an operation like `v[2] = 0;` will compile. The code should do one of two things:

- if the `index` requested is within the vector, return a reference to the element at that location
- if it is not, throw a `range_error` (requires `#include <stdexcept>`) with an appropriate message. Look at the last lab.

# Task 3

If you got this far, here is some more fun stuff. First the easy ones. Write the following two functions:

- a `front()` method that returns a **reference** to the front element of the vector
- a `back()` method that returns a **reference** to the back element of the vector
  - what should these do if the vector is empty? We have choices but let's throw another `range_error` in this case.

Then the harder ones. If you do dynamic memory, you should make your own copy constructor and `operator =`. So write the next three functions:

- `vector(vector<T>&);`
- `vector<T>& operator = (vector<T> const &);`
- `~vector();`

The copy constructor should:

- copy both `capacity_` and `size_` from `v` to the newly created instance
- in the new created instance
  - allocate the new required memory
  - copy the elements from the argument vector to the newly created instance

The `operator =` should basically do the same thing

- think of using the copy and swap idiom discussed in the videos and in the slides

Then `~vector()`, the destructor to `delete` memory when the created element goes out of scope or is otherwise destroyed.

# Task 4

Finally, if you are still here, let's make

- a `clear()` method which removes all the data
  - resets `size_` to 0 and `capacity_` to 10
  - deletes the existing array memory (if there is any)
- a `pop_back` method. FYI one would only do the following on a system with limited memory, but it is still good practice:
  - it returns a template type, the last element of the vector
  - removes the last element of the vector. The vector `size_` is now one less
  - if after the removal the vector reaches 1/2 capacity (the `size_` is half of the `capacity_`), do what we did with `push_back` but in reverse
    - make a `new_data` pointer of **half capacity**
    - copy the `data_` to the `new_data`
    - clean up as previously

## Feedback and suggestions

- E-mail：<liutia20@msu.edu>

---------

Thanks for reading this help document
