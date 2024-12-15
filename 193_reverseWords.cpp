#include <iostream>
#include <string>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

// Problem : Given a string s, reverse the string without reversing its individual words. Words are separated by spaces. Note: The string may contain leading or trailing spaces, or multiple spaces between two words. The returned string should only have a single space separating the words, and no extra spaces should be included.

// Approach : This easy sounding question is horrible! This has weird test cases. So here's the code. There's no catch in it, just careful observation..

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string &s)
    {
        int j = s.size() - 1;
        int start = 0;
        while (s[j] == ' ')
            j--;
        while (s[start] == ' ')
            start++;
        string ans = "";
        for (int i = j; i >= start; i--)
        {
            if (s[i] == ' ' && i != j)
            {
                for (int k = i + 1; k <= j; k++)
                    ans.push_back(s[k]);
                ans.push_back(' ');
                j = i - 1;
            }
            if (s[i] == ' ' && i == j)
                j = i - 1;
        }
        if (j >= 0 && s[j] != ' ')
        {
            for (int k = start; k <= j; k++)
                ans.push_back(s[k]);
        }
        int end = ans.size() - 1;
        while (ans[end] == ' ')
            ans.pop_back();
        return ans;
    }
};