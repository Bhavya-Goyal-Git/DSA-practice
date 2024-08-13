#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// Problem : There are n people at a party, Given is a n*n matrix where M[i][j] represents whether ith person knows jth person or not (1 or 0). A celebrity is defined as a person who knows nobody but everyone knows him. Return the index of celebrity in the party if one exists or else return -1.

// Approach : We see, if there is a celebrity, his entire row will be of zeros (he knows nobody) however his entire column (except his own row) will be of 1s (everyone knows him). So this condition has to be checked by any approach. Basic could be to check it for each person, but it takes O(n2) time.

// Approach #1 : This approach uses stack and has O(n) time with O(n) space. We push all the indices from 0 to n-1 in a stack. Now, until the size of our stack isn't one we run a loop. We pop out 2 top elements (say A,B) and check Kya A, B ko jaanta hai? if yes, then A can't be celebrity aur hum B ko push krte hai stack mei and A ko ignore. Else, A B ko nhi jaanta means B can't be a celebrity aur hum A ko push krte hai stack mei B ko ignore. At the end we have one index, that is potential candidate for being a celebrity. We verify it by checking his row (all zeros) and his colum (all 1s except his row) and then return the ans.

// Approach #2 : This approach uses 2 pointers O(n) time and O(1) space. Effectively same to stack approach, just the 2 people we were choosing are now pointers. We initialize 2 indices start at 0 and end at n-1. Run a loop until start<end (until they meet at a index) If start knows end, increment start else decrement end (with same logic in above approach), at end of loop, start will be candidate for a celebrity. Do validation checks and return the ans.

// Approach 1
class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> mystack;
        for (int i = 0; i < n; i++)
        {
            mystack.push(i);
        }
        while (mystack.size() > 1)
        {
            int a = mystack.top();
            mystack.pop();
            int b = mystack.top();
            mystack.pop();
            if (M[a][b] == 1)
            {
                mystack.push(b);
            }
            else
            {
                mystack.push(a);
            }
        }
        int candidate = mystack.top();
        for (int i = 0; i < n; i++)
        {
            if (M[candidate][i] == 1)
                return -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (M[i][candidate] == 0 && candidate != i)
                return -1;
        }
        return candidate;
    }
};

// Approach 2
class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            if (M[start][end] == 1)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        // start is now a candidate
        for (int i = 0; i < n; i++)
        {
            if (M[start][i] == 1)
                return -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (M[i][start] == 0 && start != i)
                return -1;
        }
        return start;
    }
};