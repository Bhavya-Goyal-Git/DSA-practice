#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/pizza-with-3n-slices/description/

// Problem : There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows: You will pick any pizza slice. Your friend Alice will pick the next slice in the anti-clockwise direction of your pick. Your friend Bob will pick the next slice in the clockwise direction of your pick. Repeat until there are no more slices of pizzas.
//  Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

// Approach : Given problem is very similar to maximum sum of non adjacent elements in a array and adjacent house robbery problem. There is just one more constraint that we can include at most n numbers where n is (size of given array /3) [as we can eat 1/3 of slices available]. So we apply the same logic of maximum non adjacent sum with n slices condition, then memoise it, then tabulate it and finally space optimise to realise that we need only 3 rows and not the entire dp matrix. Then after this much, there is a similar constraint in this question as there was in house robbery, slices are circular.. therefore if we take first we can't take last and vice-versa. So we modify just the last approach to take a start and end index as well.. Then make 2 calls to the function with once index 0 to k-2 and once index 1 to k-1 (k being size of array), then return max of 2 ans.

class Solution
{
public:
    int solve(vector<int> &slices, int start, int end)
    {
        int k = slices.size();
        vector<int> curr(k / 3 + 1, 0);
        vector<int> next1(k / 3 + 1, 0);
        vector<int> next2(k / 3 + 1, 0);
        for (int index = end; index >= start; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int include = slices[index] + next2[n - 1];
                int exclude = next1[n];
                curr[n] = max(include, exclude);
            }
            next2 = next1;
            next1 = curr;
        }
        return next1[k / 3];
    }
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        int incl0 = solve(slices, 0, k - 2);
        int excl0 = solve(slices, 1, k - 1);
        return max(incl0, excl0);
    }
};