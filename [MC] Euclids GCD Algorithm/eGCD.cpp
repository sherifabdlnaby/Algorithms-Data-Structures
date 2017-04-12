//
// Created by Sherif Abdel-Naby on 2/15/17.
//
#include <iostream>

int eGcd(int x, int y) //Euclid's Algorithm - Recursive
{
    int r = y % x;
    if (!r)
        return x;
    else
        return eGcd(r, x);
}

int GCD(int x, int y) //Insure proper input then call eGCD.
{
    if (!x && !y)//UNDEFIENED GCD case.
        return -1;
    else if (!x)
        return y;
    else if (!y)
        return x;
    else if (x > y)
        return eGcd(y, x);
    else
        return eGcd(x, y);
}

