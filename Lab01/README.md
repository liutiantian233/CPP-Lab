# Assignment Overview

The New Horizons spacecraft, launched January 19th 2006, is the first earth spacecraft to have made contact with the planet Pluto. On January 1st, 2019 it is schedule to make contact with the first Kuiper belt object KBO-2014-KU69. [The NASA update page](http://pluto.jhuapl.edu/Mission/Where-is-New-Horizons.php) reports it (09/01/2017) at a distance of 39.33Astronomical Units (AU) from the Sun, traveling away from the Sun at 14.24 km/sec, 8.85 mi/sec.

For this lab you will use the **cin** and **cout** streams along with some simple mathematics for calculating New Horizon's distance. The important part of the project is to learn the skills needed to access the class web site, to access a project description, create a new program in C++ and finally to hand it in.

## Your Task

Your program will prompt the user for an integer number (a number without decimal points) which indicates the number of **days after** 09/01/2017, starting at the distance 39.33 AU from the sun. You will calculate the distance of New Horizons from the Sun using the numbers from 09/01/2017 (assume velocity is constant) **plus** the user provided number of days and report

- Updated distance in A.U.
- Distance in kilometers (1 AU = 149,598,000 km) on a line by itself
- Distance in miles (1 AU = 92,955,800 mile) on a line by itself
- Round trip time for radio communication in hours. Radio waves travel at the speed of light, listed at 299,792,458 meters/second, on a line by itself
- provide 2 decimal points of accuracy using **std::fixed** and **std::setprecision** (the later requiring #include <_iomanip_>).

# Assignment Notes

There are some rounding issues here so be careful! To make the km calculations, us the constants (speed and distance) provided. To make the mile calculations, use the constants (speed and distance) provided. To make the round trip calculation, use your distance in km and the speed of light constant provided. You'll get slightly different answers if you try to convert the two distance or the two speeds.

You will need to work with the **cin** and **cout** streams and their operators **>>** (for **cin**) and **<<** (for **cout**). You will also need to declare the appropriate variables: **long** (a 64 bit integer) for values like days and **double** for calculation values.

## Feedback and suggestions

- E-mail：<liutia20@msu.edu>

---------

Thanks for reading this help document
