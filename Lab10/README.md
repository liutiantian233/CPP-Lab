# The Problem

We are going to work on making our own classes with private data members and special accessors. We are going to build a `CircularBuffer` class, a common data structure with well known accessors.

## Some Background

Our `CircularBuffer` will be a data structure that stores `long`. A `CircularBuffer` is a fixed size FIFO (First In, First Out) data structure. It is essentially a line (a queue). First thing added (the Head position in the diagram) is the first thing read. The next thing added is at the Tail position. It is the last thing added, the last thing that will be read. The underlying data structure for this approach has a fixed size data structure. It can become empty, it can become full. It does not grow or shrink in size over the course of the run of the program.

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab10/Lab10-1.png)

Things you can do with your `CircularBuffer`:

- you can add to the `CircularBuffer`. An element is added at the Tail position. The write position is then advanced (clockwise in the diagram)
- you can remove an element. The element at the Head position is removed. The Head position is then advanced (clockwise in the diagram)
- you can test if it is full
- you can test if it is empty
- you can report the front element
- you can report the back element

## Your Tasks

We are going to make a `CircBuf` class with these characteristics and test it.

# The Class

The `CircBuf` class will have an underlying data member `buf_` of type `vector<long>` of **fixed size**. This is a **private** data member, which will represent the underlying data array. `buf_` is private, you cannot access it from a main program using the class.

## Data Members

- `int sz_`: the maximum size of the fixed size buffer
- `int cnt_`: the number of active elements in the buffer
- `size_t head_`: an index to the element that will be read by `front()`
- `size_t tail_`: an index to where the **next element** will be written, where `add()` will put the next element
- `buf_`: a `vector<long>`, the data being stored

## Function Members

- `CircBuf`: constructor, one argument, the **fixed size** buffer of `long`
  - takes a default of 10, thus allowing for a default constructor.
- `CircBuf` constructor:
  - two args: an `initialization_list<long>` and a buffer size
    - if the parameter size is smaller than initialization list, throw a `runtime_error`
  - if successful, initializes the underlying vector to the provided parameter size and copies the values of the `initializer_list` into that vector
- `long front() const`: member function, no parameters
  - if `CircBuf` is not empty, returns the long indexed by `head_`
  - if the `CircBuf` is empty, throws a `runtime_error`
