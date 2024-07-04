#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/count-primes/description/

// Problem: Given a number n, return the number of prime numbers strictly less than n.

// Approach: Checking each number will result in O(n2). We will use sieve of eratothenes. form a vector of booleans of size n+1. these represets numbers 0 to n. initialize entire array to true, manuaaly set 0 and 1st position false as they are not primes. next we run a loop from index 2 upto <n and check if value is true, if yes then it is a prime and we incerement count. also, all its factors need to be cancelled so we run a loop from j=i*2 until j<n incerementing j by i each time and set arr[j] = false.. at end return count!!

class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                count++;
                for (int j = i * 2; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};