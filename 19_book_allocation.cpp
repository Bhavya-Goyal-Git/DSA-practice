#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

// Similiar problem link (Painter partition): https://www.codingninjas.com/studio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION

// Problem : There can be many variations, but here is what the main objective is : given is a array with size m, and a number n. we have to divide the given array into "n" sub-arrays such that maximum value of sums of all sub arrays is the minimum possible, return it For example,
// if array is [10,20,30,40] and n=2
// then 10,20,30 and 40 will be good sub arrays as max sum is 60 which is minimum of all possible partitions.

// Approach : We use binary search. first we create a search space (set of all possible answers), here the low = 0 and high will be sum of all array elements (max possible allocation). now we check if mmid value is a possible solution through some funcion, if yes, store it in a answer and update high to mid-1 as all bigger answers will also do. if it is not solution, we update low to mid+1 as no smaller solutions will do.

// Approach of checking isSolution()  : set initial values of number of partitions to 1 and sum of partition to 0. iterate through the array, check if a new entery can be added to sum of partition without going out of bounds, if yes, add it in. else: make another partition by incrementing it. and check 2 conditions : if number of partitions has exceeded the amount give i.e. n or if value of arr[i] is higher than partiton sum possible, if any of these is matched, then return a false. also, set the sum of partitions to currentvalue i.e. arr[i] to continue working. At end return true as nothing blew up.

bool isSolution(int n, int m, vector<int> &time, long long int mid)
{
    long long int daycount = 1;
    long long int timespent = 0;
    for (long long int i = 0; i < m; i++)
    {
        if (timespent + time[i] <= mid)
        {
            timespent += time[i];
        }
        else
        {
            daycount++;
            if (daycount > n || time[i] > mid)
            {
                return false;
            }
            timespent = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long low = 0;
    long long high = 0;
    for (long long int i = 0; i < m; i++)
    {
        high += time[i];
    }
    long long int mid = low + (high - low) / 2;
    long long int ans = -1;
    while (low <= high)
    {
        if (isSolution(n, m, time, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}