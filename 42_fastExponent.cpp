#include <iostream>
using namespace std;

// Problem: Finding x^n in O(log(n)). since answer must be very big, we return it in %m form.
// Approach: we check if exponent is even/odd if odd, multiply result with that number. make the number sqaured and reduce the power by dividing it by 2. if even, we just square it and divide power by 2. effectivly if we see at each step, we take x^n into (x^2)^n/2

int modularExponentiation(int x, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1) // check odd
        {
            res = (1LL * res * (x % m)) % m; // res = res*x
        }
        x = (1LL * (x % m) * (x % m)) % m; // x= x^2
        n = n >> 1;                        // n=n/2
    }
    return res;
}
