# The Problem

We are going to work on two things:

1. First time coding vectors 
2. Understanding how we can break our program out into different files and create one executable from those files

## Separate Compilation of Files

### Why?

Imagine that you write a really useful function. You would like to package the function up individually so you could use it in other programs. The hard way to accomplish that would be to have to copy that function into every new program where you might want to use it. A better idea would be to place that function in its own separate file, and then compile any new program and your trusty function into one executable. That would be lovely!

### How?

Remember this picture?

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab06/lab06-1.png)

g++ (the underlying compiler) does all of these steps rather invisibly. To take advantage of it we need multiple files.

## Header Files

If we are going to define a function in one file and use the function in a main file, we are going to have to find a way to inform the main file about the **types** of the function. That is, we have to tell the main file:

- the function **name**
- the **type** the function returns
- the **type** of the parameters the function uses
  - the **name** of each parameter is **unimportant**. It can be given, changed in the main function or just left out. All that matters is each parameter **type**

If we tell the main function this information, that is enough for the C++ compiler to check that the function is being used correctly in main, and by correctly I mean that main is using all the types correctly in calling the function, even though it does not yet have available the actual function code.

Providing this information is the job of a **header file**. Header files that users write typically end in **.h**, and are used to indicate the type information of a some C++ elements (of functions, or classes, or some other C++ thing). This header file is used by the compiler to make sure that, whoever is using this function, they are at least using the types correctly. Thus without the function itself, we can know that we followed the compiler rules and used the correct types.

# Programming Task 1

Make a new a new directory called **splitter**. We want to add three new files to the project: **splitter-main.cpp splitter-functions.cpp splitter- functions.h**

- Make a new file then save as **splitter-main.cpp**
- Now make the **splitter-functions.cpp** and the **splitter-functions.h** file.
- You should have three file tabs at the top now.

## Function split

The split function should take in a **string** and return a `vector<string>` of the individual elements in the string that are separated by the separator character. Thus

hello mom and dad ——> {hello, mom, and, dad}

- Open **splitter-functions.h** and store the function **declaration** of **split** there. The declaration should be:

`vector<string> split (const string &s, char separator=' ');`

- As discussed, default parameter values **go in the header file only**. The default does not occur in the definition if it occurred in the declaration.
- This header file should wrap all declarations using the **#ifndef, #define, #endif** as discussed above. Make up your own variable name.
- Open **splitter-functions.cpp** and write the **definition** of the function **split**. You **must** include the **splitter-functions.h** here using quotes as previously indicated.
- Make sure the definition matches the declaration in **splitter-functions.h**. The parameter names do not matter but the types do. Make sure the function signature match for the declaration and definition.

## Function print_vector

This function prints all the elements of `vector<string> v` with each element of the vector on a separate line. The `ostream out` provided as a **reference parameter** (it must be a reference). Note out and v are passed by reference.

- **print_vector**: Store the declaration in **splitter-functions.h** then place function definition in **print-vector** in **splitter-functions.cpp**. The declaration should look a lot like the below:

`void print_vector (ostream &out, const vector<string> &v);`

## Function main

Write the **main** function and place it in **splitter-main.cpp**.

- In **main.cpp** make sure you `#include "splitter-functions.h"` (note the quotes), making those functions available to main. Write a main function that
- The operation of main is as follows:
  - prompts for a string to be split
  - prompts for the single character to split the string with
  - splits the string using the **split** function which returns a vector
  - prints the vector using the **print_vector** function
- compile (not build) main to see that it follows the rules

## Assignment Notes

1. Couple ways to do the split function
   1. **getline**
      1. **getline** takes a delimiter character as a third argument. In combination with an input string stream you can use **getline** to split up the string and **push_back** each element onto the vector.
      2. example **getline(stream, line, delim)** gets the string from the stream **(istream, ifstream, istringstream, etc.)** up to the end of the line or the delim character.
      3. string methods **find** and **substr**. You can use the **find** method to find the delim character, extract the split element using **substr**, and **push_back** the element onto the vector.
   2. Default parameter value. The default parameter value needs to be set at **declaration time**, which means that the default value for a function parameter should be in the header file (the declaration). If it is in the declaration, it is not required to be in the definition, and by convention should not be.
