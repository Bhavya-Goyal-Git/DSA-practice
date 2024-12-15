#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

// Problem : Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:
//  N: The maximum unit of food you can buy each day.
//  S: Number of days you are required to survive.
//  M: Unit of food required each day to survive.
//  Currently, it's Monday, and she needs to survive for the next S days.
//  Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn't possible to survive.

// Approach : The solution is greedy, as we only have to think about surviving a week. We need to check 2 conditions, if we can survive one day or not (M must be less than or equal to N) and if we buy food for 6 days in the week (Mon to Sat) can we survive for entire week including sunday? (i.e. 6N must be greater or equal to 7M), if any of these fail, we return -1. Else, we can survive, and we have to calculate number of days.. we get food required = S*M... now if it is a multiple of buuying amount, we simply return S*M/N else, we need to add 1 to it and return (this is equivalent to taking ceiling function if division is done in float)

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        if (M > N || (S >= 7 && (7 * M) > (6 * N)))
            return -1;
        int ans = S * M / N;
        if ((S * M) % N != 0)
            ans++;
        return ans;
    }
};