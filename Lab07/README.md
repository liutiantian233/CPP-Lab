# The Problem

We are going to work on 2D vectors.

## 2D vector as a matrix

You remember matrices, do not you? We are going to do some simple manipulation of a matrix, namely: adding two matrices and multiplying a matrix by a scalar. You watched the 2D vector video, right? RIGHT???

## Matrix

A **matrix** is a 2-dimensional (rows and columns) data structure. It has a shape indicated by the number of rows and the number of columns. Though I suppose a matrix could have uneven sized rows, this does not usually happen in practice so a matrix is always rectangular, potentially square (based on its shape).

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab07/lab07-1.png)

## Matrix operations

We will perform two operations on our matrices, yielding a new matrix as a result.

The first is **scalar multiplication**. Regardless of the size or shape, if the matrix is not empty we multiply the scalar value by every entry in the matrix, yielding a new matrix. We do this for every entry in the matrix.

The second is **addition**. The shape of the two matrices **must be the same** for addition to go forward. If the shapes are the same and they are both not empty, we add the same row/col element of each argument matrix into the same row/col element of a new matrix, yielding the new matrix. We do this for every element in the two matrices.

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab07/lab07-2.png)

# Requirements

We will use a `vector<vector<long>>` as the underlying representation of our matrix. This means that the top level vector has, as elements, another vector.

In `functions.h` we provide two using definitions to make things a little easier, to wit:

`using matrix_row = vector<long>;`

`using matrix = vector<matrix_row>;`

This is really a big win! We need only say that the type of vector in a `matrix_row` is a `long` and then, if we are careful, can easily change the type of our entire code set by just changing that one template.

## Function Declarations

The functions are clearly described in the functions.h file provided, read them there.

## Printing

I think printing the 2D matrix is actually kind of hard. Here are some tips to help out:

In the include file `iomanip` is an io manipulator `setw`. It sets the width for an output element:

- Unlike every other manipulator, it requires you to run it each time you use it.
- If you say something like `cout << setw(5) << 123` then 5 spaces are reserved for output, 3 of which are occupied by 123 and two of which are just blank spaces (the default, you can change that with **setfill**)
- Two other manipulators are **left** and **right** for left or right justification respectively. Thus
  - `cout << right << setw(5) << 123` prints 2 spaces and 123
  - `cout << left << setw(5) << 123` prints 123 and 2 spaces
- If you use an `ostringstream` (and you should) then any `endl` in the stringstream counts as a character in the stream.
- My code used:
  - `ostringstream` to capture the output and then convert to a string
  - `setw` to set the width, where the default is 3
  - `right` to get the elements right justified so they look better

## Other Hints

1. Write a function, test a function, write the next function, test that function, etc. This is the way you figure things out, one by one.
2. You can make a temporary row (of type `matrix_row`) and `push_back` values on to that. You can then `push_back` the row onto a matrix (of type `matrix`). You can reuse the row in the your loop, but remember to `clear()` it first.

# The Problem

We are going to work on 2D vectors.

## 2D vector as a matrix

You remember matrices, do not you? We are going to do some simple manipulation of a matrix, namely: adding two matrices and multiplying a matrix by a scalar. You watched the 2D vector video, right? RIGHT???

## Matrix

A **matrix** is a 2-dimensional (rows and columns) data structure. It has a shape indicated by the number of rows and the number of columns. Though I suppose a matrix could have uneven sized rows, this does not usually happen in practice so a matrix is always rectangular, potentially square (based on its shape).

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab07/lab07-1.png)

## Matrix operations

We will perform two operations on our matrices, yielding a new matrix as a result.

The first is **scalar multiplication**. Regardless of the size or shape, if the matrix is not empty we multiply the scalar value by every entry in the matrix, yielding a new matrix. We do this for every entry in the matrix.

The second is **addition**. The shape of the two matrices **must be the same** for addition to go forward. If the shapes are the same and they are both not empty, we add the same row/col element of each argument matrix into the same row/col element of a new matrix, yielding the new matrix. We do this for every element in the two matrices.

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab07/lab07-2.png)

# Requirements

We will use a `vector<vector<long>>` as the underlying representation of our matrix. This means that the top level vector has, as elements, another vector.

In `functions.h` we provide two using definitions to make things a little easier, to wit:

`using matrix_row = vector<long>;`

`using matrix = vector<matrix_row>;`

This is really a big win! We need only say that the type of vector in a `matrix_row` is a `long` and then, if we are careful, can easily change the type of our entire code set by just changing that one template.

## Function Declarations

The functions are clearly described in the functions.h file provided, read them there.

## Printing

I think printing the 2D matrix is actually kind of hard. Here are some tips to help out:

In the include file `iomanip` is an io manipulator `setw`. It sets the width for an output element:

- Unlike every other manipulator, it requires you to run it each time you use it.
- If you say something like `cout << setw(5) << 123` then 5 spaces are reserved for output, 3 of which are occupied by 123 and two of which are just blank spaces (the default, you can change that with **setfill**)
- Two other manipulators are **left** and **right** for left or right justification respectively. Thus
  - `cout << right << setw(5) << 123` prints 2 spaces and 123
  - `cout << left << setw(5) << 123` prints 123 and 2 spaces
- If you use an `ostringstream` (and you should) then any `endl` in the stringstream counts as a character in the stream.
- My code used:
  - `ostringstream` to capture the output and then convert to a string
  - `setw` to set the width, where the default is 3
  - `right` to get the elements right justified so they look better

## Other Hints

1. Write a function, test a function, write the next function, test that function, etc. This is the way you figure things out, one by one.
2. You can make a temporary row (of type `matrix_row`) and `push_back` values on to that. You can then `push_back` the row onto a matrix (of type `matrix`). You can reuse the row in the your loop, but remember to `clear()` it first.

# Feedback and suggestions

- E-mail：<liutia20@msu.edu>

---------

Thanks for reading this help document
