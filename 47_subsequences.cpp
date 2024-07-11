#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16&leftPanelTabValue=SUBMISSION

// Problem : Given a string, return a vector of all its substrings. A substring is made when we delete one or more letters of a string, keeping the order of other letters intact.
//  for ex. "abc" -> [ a, b, c, ab, bc, ac, abc ] (Note that empty case is excluded here!!)

// Approach:

void powerSet(string &str, string output, int index, vector<string> &ans)
{
    if (index >= str.size())
    {
        if (output.size() != 0)
            ans.push_back(output);
        return;
    }
    // non inclusive call
    powerSet(str, output, index + 1, ans);
    // inclusive call
    output += str[index];
    powerSet(str, output, index + 1, ans);
}

vector<string> subsequences(string str)
{
    string output = "";
    int index = 0;
    vector<string> ans;
    powerSet(str, output, index, ans);
    return ans;
}