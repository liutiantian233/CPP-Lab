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
