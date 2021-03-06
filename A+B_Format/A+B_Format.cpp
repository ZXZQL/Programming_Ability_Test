// A+B_Format.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

void RecursiveCommas(long n, int mod = 10, int i = 0)
{
    if (n % mod == n)
    {
        //base case
        if (i % 3 == 0 && i != 0)
            cout << (n % mod) / (mod / 10) << ",";
        else
            cout << (n % mod) / (mod / 10);
    }
    else
    {
        if (i % 3 == 0 && i != 0)
        {
            //add commas
            RecursiveCommas(n, mod * 10, i + 1);
            cout << (n%mod) / (mod / 10) << ",";
        }
        else
        {
            //no comma needed
            RecursiveCommas(n, mod * 10, i + 1);
            cout << (n % mod) / (mod / 10);
        }
    }
}

int main()
{
    long a,b;
    cin >> a>>b;
    a = a + b;
    if (a < 0)
    {
        cout << "-";
        a = -a;
    }
    
    RecursiveCommas(a);
    return 0;
}

