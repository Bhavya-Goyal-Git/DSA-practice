#include <iostream>
using namespace std;

// Problem link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Problem: Given is a string, remove all occurences where 2 adjacent characters are same, keep doing so until no such pairs remain . For example, accaba -> aaba (removing cc) -> ba (removing aa).

// Approach: We solve via a sliding window algorithm, taking window size of 2. So, we take 2 letters at a time and compare if they are same. if not, we simply drag window forward until it clashes to the right. but if the window characters do match, we erase them off. now 2 new characters are at our window... which makes a possibility that the 1st one could make a pair with previous letter, so we drag the window 1 unit behind, however, we also check if the window left has reached the 0 index, then we cannot decrement the value.

class Solution
{
public:
    string removeDuplicates(string s)
    {
        int windowLeft = 0, windowRight = 1;
        while (windowRight < s.length())
        {
            if (s[windowLeft] == s[windowRight])
            {
                s.erase(windowLeft, 2);
                if (windowLeft != 0)
                {
                    windowLeft--;
                    windowRight--;
                }
            }
            else
            {
                windowLeft++;
                windowRight++;
            }
        }
        return s;
    }
};