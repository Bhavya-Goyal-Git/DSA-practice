#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Given an array of strings, return the longest common prefix to all the strings

// Approach : Not everywhere a datastructure is needed, even thought it feels like using a trie here. We iterate over the characters of first string and check its presence in all the other strings, if char is present in all, we append it to ans string. When we find first non-match we break out of loops and return the ans. If length of 1st string is 'm' then time comp. is  O(m*n), a trie could do no better.

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
    int len = arr[0].size();
    for (int i = 0; i < len; i++)
    {
        char ch = arr[0][i];
        bool isMatch = true;
        for (int j = 1; j < n; j++)
        {
            if (ch != arr[j][i])
            {
                isMatch = false;
                break;
            }
        }
        if (isMatch)
            ans.push_back(ch);
        else
            break;
    }
    return ans;
}
