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
