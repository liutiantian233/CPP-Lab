# Lab Assignment

John Napier was a Scottish mathematician who lived in the late 16th and early 17th centuries. He is known for a number of mathematical inventions, one of which is termed **location arithmetic**.

You job is to write functions that can convert back and forth between location and decimal representations, as well as some support functions for the process.

## Overview

Location arithmetic is a way to represent numbers as binary values, using a notation that is not positional, but representational. You can see a detailed description in [this link](https://en.wikipedia.org/wiki/Location_arithmetic) but here are the basics.

## The representation

Napier used letters to represent powers of two. In using letters, the position of the letter is not important, allowing for multiple representations of the same number. For example, in location arithmetic:

a = 1, b = 2, c = 4, d = 8, e = 16, f = 32 ... and thus: acf = 1 + 4 + 32 = caf or 37

For convenience, the letters are typically sorted but only to make reading easier. Napier allowed for redundant occurrences of letters, though he acknowledged that there is a normal form that had no repeats. He described this as the extended (repeated) vs. abbreviated (no repeats). To create the abbreviated form, any pair of letters can be reduced to a single occurrence of the next "higher letter". For example:

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab04/lab04-1.png)

## Addition

Addition is particularly easy. Take all the letters from the two values, put them into a single string, sort, reduce, convert!

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab04/lab04-2.png)

# Your Task

Write the following four functions and main program to do location arithmetic:

1. **long loc_to_dec(string loc)**: convert location arithmetic string to an integer.
2. **string abbreviate(string loc)**: take a location string and reduce it to its abbreviated form. We want you to experiment with string manipulation so **you cannot convert it to integer** first. You must do the abbreviation directly.
3. **string dec_to_loc(long dec)**: convert an integer to an **abbreviated** location string.
4. **long add_loc(string loc1, string loc2)**: take two location strings, add them, provided the integer result. For this function, **do it the way described above!!** that is:
   1. mix the strings
   2. sort them
   3. reduce the string (using your **abbreviate** function) convert 
   4. the result (using your **loc_to_dec** function)
5. Write a main function that shows off your work:
   1. prompt for two elements: a location string and a long.
   2. prints on a single line 4, space separated elements
      1. loc__to_dec on the input location string
      2. abbreviate on the input location string
      3. dec_to_long on the input long
      4. add_loc using the input location string twice (adding it to itself)

## Sorting

We haven't done sorting yet, but C++ makes it pretty easy. There's an example in the directory, but here is the gist. Sorting sorts the individual elements of a collection in sorted order from two points in the collection. Elements in strings are chars, so sorting from the beginning to the end of the string, character by character, is shown below. Note that sorting changes the string in place!

```c++
#include <string>
using std::string;
...
// sort string, char by char, in place, from begin() to end(). Note the parentheses!
string my_str = "aebcd";
sort(my_str.begin(), my_str.end());
cout << my_str;  // prints abcde
```

# Hints

1. You could define a constant for each letter of the alphabet, but what a pain. Better to note the following. The smallest character of a location string is **'a'**, which represents 2^0 power (i.e. 1). The difference between any letter and **'a'** is the power of 2 the letter represents. For example:
![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab04/lab04-3.png)
2. The function **dec_to_loc** is really nothing more than creating a "long string" and using **abbreviate** to clean it up. The **abbreviate** function is the key.
3. The function **add_loc** is nothing more than a concatenation of the two strings, a call to **abbreviate**, followed by a call to **loc_to_dec**.
4. Your functions will make use of:
   1. substr method
      1. substring takes two parameters: a position and a length. Length defaults to the end of the string (or if the value is beyond the length of the string, it defaults to the end.)
   2. **static_cast<_char_>**
      1. if you do addition/subtraction on a character, you need to cast it to a character for the "printable" version.
   3. push_back method
      1. you can push a character onto the end of the string using this method.
   4. indexing via the [ ] operator

## Feedback and suggestions

- E-mail：<liutia20@msu.edu>

---------

Thanks for reading this help document
