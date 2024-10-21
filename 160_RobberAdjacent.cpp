#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM&count=25&page=1&search=&sort_entity=order&sort_order=ASC

// Problem : Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night. You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

// Approach : We can see that this is same as previous problem, max sum of non adjacent elements, however array is now circular. That introduces a little catch, when we include the first house we cant include the last, when we include last we have to ignore the first.
// To do this, we apply same logic as previous ques, once by including 1st and excluding last house, and once by excluding 1st and including last house, return the maximum of them. The last function, build using space opt is reused, with start and end indices provided. O(n) time and O(1) space.

long long solve4(vector<int> &nums, int startIndex, int endIndex)
{

    long long prev1 = nums[startIndex];
    if (endIndex == startIndex)
        return prev1;
    long long prev2 = max(nums[startIndex], nums[startIndex + 1]);

    for (int i = startIndex + 2; i <= endIndex; i++)
    {
        long long curr = max(prev1 + nums[i], prev2);
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return valueInHouse[0];
    int including0thHouse = solve4(valueInHouse, 0, n - 2); // excluding last
    int excluding0thHouse = solve4(valueInHouse, 1, n - 1); // including last
    return max(including0thHouse, excluding0thHouse);
}