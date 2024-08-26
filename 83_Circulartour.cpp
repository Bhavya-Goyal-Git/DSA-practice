#include <iostream>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

// Problem : Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data :
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between. Assume for 1 litre petrol, the truck can go 1 unit of distance.

// Approach : This is like a 2 pointer problem. Firstly see that, if there are pumps like a,b,c,d,e and you cannot reach d if we start at a, then note that you cannot reach d even if you start from b or c. Now the approach : we first set start to 0 and balance to 0 and at each step check whether is it possible to travel further that is balance += petrol - distance must be >=0 if yes, move forward a second pointer. At any step, if it is not possible then do start = secondpointer + 1 and set balance to 0 again and begin again. this runs until the second pointer reaches the start point again through circular increments.
// See that : in the case when the last pump is the answer, this approach would let us visit every pump twice to find the answer. What if we want to find the answer in single pass? Then we dont keep a second pointer. Rather: we initialize a balance, a deficit and a start all to 0; then begin traversing the array normally i=0 to n-1 and at each step check the balance. if its negative then firstly add the negative value to deficit variable. (this stores like required petrol for the path that could not be travelled) i.e. deficit+=balance. then do the regular of balance to 0 and start to i+1. After the loop has traversed, check if balance + deficit >=0 (can the paths be covered?) if yes return value of start. Else, return -1 as no possible petrol pump exists.

// The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int balance = 0;
        int deficet = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            balance += p[i].petrol - p[i].distance;
            if (balance < 0)
            {
                deficet += balance;
                balance = 0;
                start = i + 1;
            }
        }
        if (balance + deficet >= 0)
        {
            return start;
        }
        return -1;
    }
};