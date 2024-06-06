#include <iostream>
using namespace std;

// Problem link: https://leetcode.com/problems/permutation-in-string/submissions/1278214128/

// Problem: given two strings s1 and s2, check if there exists some permutation of s1 within s2.

// Approach: This is famous sliding window algorithm based question. we first form an array of 26 size that stores frequency of letters in s1(whose permutations are to be found) (kind of like a hash map) then a window is formed of size of s1(whose permutations are to be found), this length of window will traverse(or slide) across s2, count the frequency of letters it contains and match with array 1, if they are equal, we return true as same size and frequency would mean a permutation. How we slide: first window is made manually by traversing s2 upto length of s1 and making corresponding increments in array 2. then onwards, the value of previous letter is decremented and 1 next letter is incremented via a loop that slides the window until it finally reaches end of s2.

class Solution
{
private:
    bool checkArrayEquality(int arr1[26], int arr2[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        // Checking if it is even possible?
        if (s1.length() > s2.length())
            return false;

        // Sliding Window Problem
        // Making the array storing no. of letters in s1(the thing whose permutations are to be found)
        int arr1[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            arr1[s1[i] - 'a']++;
        }
        // Making the second array as a window for first time!!
        int arr2[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            arr2[s2[i] - 'a']++;
        }
        // Checking for first time
        if (checkArrayEquality(arr1, arr2))
            return true;

        // Making a sliding window and checking until its right does not reach the end
        int windowLeft = 1, windowRight = s1.length();
        while (windowRight < s2.length())
        {
            arr2[s2[windowLeft - 1] - 'a']--;
            arr2[s2[windowRight] - 'a']++;
            if (checkArrayEquality(arr1, arr2))
                return true;
            windowLeft++;
            windowRight++;
        }
        return false;
    }
};