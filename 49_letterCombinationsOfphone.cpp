#include <iostream>
#include <vector>
using namespace std;

// Problem link : https : // leetcode.com/problems/letter-combinations-of-a-phone-number/description/

// Problem : Given is a string of digits 2-9. Similar to what we found in a keypad phone, each digit is mapped to certain alphabets ex (2-abc),(3-def) etc. We have to return a vector of strings containing all possible patters that can be made using given digits. For ex, by "23" we can -> [ad ae af bd be bf cd ce cf] the input string may be empty remember!

// Approach : First of all we make a string array that stores mapping, for simplicity we make it size 10, at each index 2-9 we store the respective string mappings abc def etc (leave 0 and 1 index with empty strings). Now we make a recursive function, to which we pass our digits string, a temporary string called output which at the base case will carry one possible pattern, a index to traverse the digits string, a vector of strings called ans (passed by ref) that will store the answers and our mapping array.
// If its the base case (i.e. index has gone out of bounds (>=digits.size)), we simply pushback the value of output into our ans vector and return. Non base case: we need to first extract out the mapping for the number present at current value of index. we first extract the character by digits[index] then to convert it to a number that can be fed to out mapping, we take digits[index] -'0', and take mapping of this i.e.  mapping[digits[index] - '0']. Store this in a temp variable val. Now we run a loop to traverse this val string. at each iteration, we pushback the val[j] into output string and make the recursive call with index+1, after the recursive call, we remember to popback from output string in order to ensure that next time the loop runs, we have a fresh value of output string.

class Solution
{
private:
    void solve(string &digits, string output, int index, vector<string> &ans, string mapping[])
    {
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }
        string val = mapping[digits[index] - '0'];
        for (int i = 0; i < val.length(); i++)
        {
            output.push_back(val[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back(); // this is called backtracking
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        string output = "";
        int index = 0;
        vector<string> ans;
        if (digits.size() == 0)
        {
            return ans;
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};