#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5&leftPanelTabValue=SUBMISSION

// Problem : check whether given string is a palindrome. ignore special character and spaces. string is also case insensitive.

// Approach: Simply, 2 pointer approach, comparting lower case of each character from start and end. just remember to ignore symbols spaces etc, and in their condition, ensure that start and end dont go beyond the condition that start<end

char toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    return ch + 32;
}

bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        while (!isValid(s[start]) && start < end)
        {
            start++;
        }
        while (!isValid(s[end]) && start < end)
        {
            end--;
        }
        if (toLower(s[start]) != toLower(s[end]))
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
char toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    return ch + 32;
}

bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        while (!isValid(s[start]) && start < end)
        {
            start++;
        }
        while (!isValid(s[end]) && start < end)
        {
            end--;
        }
        if (toLower(s[start]) != toLower(s[end]))
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}