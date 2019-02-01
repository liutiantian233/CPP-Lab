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
