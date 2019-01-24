# Assignment Overview

The aim of this assignment is practice the use of while loops and conditionals statements. You are going to write a program that prompts the user for an integer and then determines the **additive persistence** and corresponding **additive root**. You will continue prompting the user for an integer until they enter a negative number which indicates they are finished.

## Background

There are many properties of numbers that one can investigate. The ancient Greeks were fascinated with the properties of integers, even ascribing them mystical properties.

One such property is an integer's **additive persistence** and its resulting **additive root**. [This is link.](http://mathworld.wolfram.com/AdditivePersistence.html) Additive persistence is a property of the sum of the digits of an integer. The sum of the digits is found, and then the summation of digits is performed creating a new sum. This process repeats until a single integer digit is reached. Consider the following example:

1. The beginning integer is 1234
2. Sum its digits is 1 + 2 + 3 + 4 = 10
3. The integer is now 10
4. The sum of its digits is 1 + 0 = 1
5. The integer is 1. When the value reaches a single digit, we are finished. This final integer is the additive root.

The number of cycles is the additive persistence. The integer 1234 has an additive persistence of 2 (first sum was 10, then the second sum was 1). The final digit reached is called the integer’s additive root. The additive digital root of 1234 is 1.

# Program Specifications

The program should run as follows:

1. Program takes in a single long from input, the number being checked.
   - if the input long is 0 or less, print the single work "Error" and end the program.
2. Otherwise, the output should be two space separated longs.
   - the persistence
   - the additive root
3. If the input long is a single digit, report its additive persistence as 0 and its additive root is the input number.
4. Otherwise calculate the additive persistence.

## Getting Started

1. Create the lab02.cpp in your favorite editor.
2. Break the problem down into parts. Some obvious parts:
   - gather input from the file, and check for negative numbers (the quit condition)
   - check if the input is between 0 and 9.
    - fas
