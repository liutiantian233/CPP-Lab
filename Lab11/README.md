# The Problem

We are going to work on some dynamic memory with arrays. We are going to dynamically allocate an array by passing it to a function, then work with that array.

## Your Tasks

I want you to add the needed functions in the provided main. Some comments about them.

- `size_t fill_from_file(long *(&ary), string f_name)`: A pointer reference is passed, meaning that what the pointer can point to is allowed to change in the function. This is good, as we will allocate the memory in the function, and the pointer reference will point to that memory. Thus the pointer in the calling main program will also point to that memory. The size of array is determined by the contents of a file which you must open.
  - if the file does not exist, throw a runtime_error
  The format of the existing file is as follows:
  - every line has a single integer number
  - the first number in the file is the count of integers that follow
  - the remaining numbers are to be placed into to the passed array in the order in which they occur
    - they all fit in a long
  - you must allocate the memory **in the function** for that array as you cannot know the size required until you read the file
    - the pointer reference should point to that dynamically allocated memory
  - it returns the size of the dynamically allocated array
