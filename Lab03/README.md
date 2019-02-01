# Lab Assignment

## Background

You remember calculus don't you? The basic concept of an integral is the area under the curve, the curve represented by some function. If you can integrate a function, you can calculate that area directly, but for some functions it is easier to approximate that area using discrete, iterative methods. We are going to investigate one of those methods, the [Trapezoid Rule](http://en.wikipedia.org/wiki/Trapezoidal_rule).

## Trapezoid Rule, area of a Trapezoid

The basic idea is to draw a series of trapezoids that approximate the area under a curve, where the more trapezoids we draw, the better the approximation.

**First, remember how to calculate the area of a trapezoid?**

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab03/lab03-1.png)

One measures the length of the parallel sides (**b1** and **b2**), then the distance between the parallel sides (**h**). Add the parallel distances, multiply those values by **h**, divide by 2.

Let's rotate that trapezoid 90 and model it as below. Now the **b1** length is the curve value **f(a)**, the **b2** length **f(b)** and the height **h** the difference between **b – a**.

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab03/lab03-2.png)

For two trapezoids next to each other with heights **f(a)**, **f(b)** and **f(c)**, **f(b)** a common side used by the two trapezoids, we get the formula:

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab03/lab03-3.png)

In general, for the definite integral:

1. from **a** to **b**
2. with **n** equally space trapezoids (**n + 1** points on the x axis)
3. grid spacing of **h = (b - a) / n**

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab03/lab03-4.png)

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab03/lab03-5.png)

This equation is the trapezoidal rule for approximating the integral which you will implement in one of your functions.

Please note that each **x** corresponds to an endpoint of the sides of the trapezoids on the x- axis. So if we have a grid spacing of **h = (b - a) / n**, then:

**x1 = a, x2 = a + h, x3 = a + 2h, ..., xn = a + (n - 1)h, xn + 1 = b**

# Program Specifications

1. Write three functions:
   1. a function **fn** to integrate over. Let's use **fn is -6x^2 + 5x + 3**
      1. **fn** takes a single **double** parameter, the value x
      2. **fn** returns a **double**, the result of the function evaluated at x
   2. a function **integral**, the actual integral of **fn** which is **integral is -2x^3 + (5 / 2)x^2 + 3x**
      1. **integral** takes a single **double** parameter, x
      2. **integral** returns a **double**, the result of the function evaluated at x
   
   let's further fix the interval to calculate the integral over as 0 to 1
   
   ![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab03/lab03-6.png)
   
   3. a function **trapezoid**. The specification for trapezoid is:
      1. take in three parameters:
         1. the two definite points of the integral **a** and **b** as doubles.
         2. the number **n**, the number of trapezoids, a long.
      2. calculates the area under the curve represented by the function **fn** given the provided number of trapezoids over the interval 0 to 1.
      3. returns a double, the sum of the area of the trapezoids.
2. A main function that does the following:
   1. takes in two values (in order)
      1. a float value tolerance
      2. an initial guess at the number **n**, the number of trapezoids
   2. you run a loop that measures the difference between the actual value of the integration (you have the **integral** function so you can calculate the exact value between **a** and **b**) and the estimated value from **trapezoid**.
      1. the actual value is **integral(b)- integral(a)** from the fundamental theorem of calculus.
      2. if the difference between the actual value and the estimated value is within tolerance, report to the user 4, space separated values on a single line. All output should be **fixed, setprecision(6)**.
         1. n
         2. estimate value
         3. exact value
         4. tolerance
      3. if the difference is not within tolerance, **double** the value of **n** and rerun. Continue the doubling and re-running until the estimate of the **trapezoid** function it is within tolerance of the actual value from **integral**.

# Example Run

![](https://raw.githubusercontent.com/liutiantian233/CPP-Lab/master/Lab03/lab03-7.png)


## Feedback and suggestions
- E-mail：<liutia20@msu.edu>

---------
Thanks for reading this help document
