#include <iostream>
#include <array>
using namespace std;

// Problem: Given a string, return a character with maximum occurence
// Approach: We make an array size 26, initialized all to 0. traverse the string and increment counter to corresponding alphabet. at the end return the max index of made array. We could also use a hash map to make things simpler!

int maxIndex(array<int, 26> arr)
{
    int max = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    return max;
}

char maxOcc(string s)
{
    array<int, 26> alphabets = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a')
        {
            alphabets[s[i] - 'a']++;
        }
        else
        {
            alphabets[s[i] - 'A']++;
        }
    }
    return 'a' + maxIndex(alphabets);
}

int main()
{
    string s = "mmmmuuuuMMUU";
    cout << "Max occuring character in " << s << " is " << maxOcc(s) << endl;
}

// Some Bonus Questions String related:
// a function that replaces all " " in a string with "@40"
string replaceSpaces(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.replace(i, 1, "@40");
            // index, number of chars to erase, what to replace with
        }
    }
    return str;
}

// Removing all occurences of a given substring(part) from a bigger string (s)
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int len = part.length();
        int idx = s.find(part); // returns index of found / std:string::npos -> special null value
        while (idx != string::npos)
        {
            s.erase(idx, len);
            // from what index, how many letters
            idx = s.find(part);
        }
        return s;
    }
};