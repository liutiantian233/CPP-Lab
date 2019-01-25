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
       that's a special case as indicated.
   - otherwise write a loop that calculates the persistence.
       track the count through this loop
   - inside that write a loop that can sum the digits of an integer until it reaches a single digit.
3. How do you get the digits of an integer? Look at a combination of division (/) and remainder (%) operators on integers.
4. I would add some “diagnostic output” so you can be sure things are working as they should. For each pass through the loop of the additive persistence, print each new integer created. Feel free to always do this as you need to work on your ability to debug problems. You can always fix it to give the exact, required output later.

## Want to do more?

There is also a multiplicative persistence. Put that in your loop and calculate it for each number. No Mimir checks for this but you can do it anyway if you have time.

## [The multiplicative persistence](http://mathworld.wolfram.com/MultiplicativePersistence.html)

Resulting multiplicative root are determined the same way, only multiplying the digits of an integer instead of adding. For example：

1. The beginning integer is 1234
2. The product of 1 * 2 * 3 * 4 = 24
3. The integer is now 24
4. The product of 2 * 4 = 8
5. The integer is now 8. When the value reaches a single digit, we are finished. This final integer is the multiplicative root.

As before, the number of cycles is the multiplicative persistence and the final number the multiplicative root. For 1234, the multiplicative persistence is 2, and its multiplicative root is 8.

# Things to think about

- what type should the integers be (int, long)
   - why
- what is the largest long you can have
   - look it up
- what happens when you enter a number that is too large? For example, the smallest number with and additive persistence of 4 is 19999999999999999999999. Can you make your calculation with that number?

## Feedback and suggestions
- E-mail：<liutia20@msu.edu>

---------
Thanks for reading this help document
