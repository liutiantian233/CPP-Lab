# The Problem

You remember the Collatz sequence, do not ya? [Here is a little reminder in case you did not.](https://en.wikipedia.org/wiki/Collatz_conjecture) One of the problems is that, by doing the calculation over from the beginning for every number, you waste a lot of time redoing work that already has been done. Look at the first 6 sequences:

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab08/Lab08-1.png)

Subsequences, whose value we already know, are recalculated. For example, the entire sequence of 3 is already known, but we recalculate the entire sequence when starting from 6.

# Memoization

Memoization (note the spelling, no r) is a simple optimization technique used in algorithms where [repeat calculations](https://en.wikipedia.org/wiki/Memoization) occur. The idea is simple. We remember a sequence when we first calculate it. Subsequently, for any value we calculate we check first to see if we already know the remaining sequence. If so, we stop the calculation and just copy the known sequence in.

For this lab, we will use a map to memorize Collatz sequences. Pay attention to this technique, it comes up in many guises and is very useful!

# Programming Task

**`Data structure, map of long to vector<long>`**

The data structure you will use for the lab is a map that has:

- as a **key**, a `long` representing the first number in the Collatz sequence.
- as a **value**, a `vector<long>` representing the resulting Collatz sequence if you started at the key number.

The declaration of such a map would look like:

- `map<long, vector<long>> collatz_map;`

Maps store their elements as an STL **pair**. When you iterate through a map you iterate through a sequence of **pair**. The **pair** type for the map above would be:

- `pair<long, vector<long>> collatz_element;`

Remember that, given such a **pair**, `collatz_element.first` is the key (the `long`) and `collatz_element.second` is the value (the `vector<long>` sequence).

For convenience, we have provided a using statement in the header.

`using Collatz = pair<long, vector<long>>;`

## Functions

The various functions, their inputs and their outputs are provided in functions.h. Read the descriptions and use them to solve the problem.

## Extra

If you get done early and wish to, trying printing out the three longest sequences in the range you just examined. This is shown on the example output.

- Hint! It is very simple if you use algorithms like sort, transform and write a compare function for the sort.

# Assignment Notes

1. Use **find** or **count**, not [ ] to see if a key is in the map.
   1. remember that, by using the [ ] to search a map, you **always** find the key because it will insert that key if it is not there. To see if something is in a map you have to use **find**.
   2. **find** returns either an iterator to the found element or `collatz_map.end()` if it did not find it.
   3. The iterator that **find** returns is a pointer to a pair. Remember the fun syntax I showed you: `(*itr).first` is the same as `itr->first`.
2. To append something to the end of a vector:
   1. you could write a loop.
   2. you could use **copy** and a **back_inserter**.

## Feedback and suggestions

- E-mail：<liutia20@msu.edu>

---------

Thanks for reading this help document
