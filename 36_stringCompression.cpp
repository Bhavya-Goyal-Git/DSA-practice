#include <iostream>
#include <vector>
using namespace std;

// Problem link: https://leetcode.com/problems/string-compression/description/

// Problem: Given a vector of characters. Compress it in such a way that each character is followed by its number of consecutive occurence. However, if a char appears only once, no need to store its count. Modify the given vector in place and also return the length of new vector formed after compression

// Approach: We go for 2 pointer approach. one is a overwriter and another one traverses the array till the end. we check if char at given place is still equal to old value (stored), if yes, increment its count and move forward. Otherwise, firstly write that charater to overwriter position and increment the overwriter, then check if the count of that letter was more than one, if yes: make it a string using to_string function and write its values at the overwriter by using a for loop. this is to ensure that counts with more than 1 digit are handeled properly and not forced insert at one place. after all this, remember to make prevChar (stored for comparing) as the new one and reset the count value to 1. Remember, all this will still not affect the last group... so the thing done in for loop has do be done just once more, right after the loop. Also, the size of vector after compression is simply the value of our Overwriter!

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        char prevChar = chars[0];
        int overWriter = 0;
        int countChar = 1;
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == prevChar)
            {
                countChar++;
            }
            else
            {
                chars[overWriter++] = prevChar;
                if (countChar != 1)
                {
                    string numString = to_string(countChar);
                    for (char c : numString)
                    {
                        chars[overWriter++] = c;
                    }
                }
                prevChar = chars[i];
                countChar = 1;
            }
        }
        chars[overWriter++] = prevChar;
        if (countChar != 1)
        {
            string numString = to_string(countChar);
            for (char c : numString)
            {
                chars[overWriter++] = c;
            }
        }
        return overWriter;
    }
};