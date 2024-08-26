#include <iostream>
#include <queue>
using namespace std;

// Problem Link : https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// Problem : Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer. For example : Input: A = "aabc"  Output: "a#bb"
// Explanation: For every ith character we will consider the string from index 0 till index i first non repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - there are two non repeating characters 'b' and 'c', first non-repeating character is 'b' because 'b' comes before 'c' in the stream.

// Approach : We need a map to store the count of each letter here, we can use a unordered map, but we have used an array of 26 size here instead. Remember the ARRAY IS OF INTEGERS and initialized all to 0. We also have to use a queue to ensure that first such element is stored. Now, we traverse the given input stream (string) and firstly we increment the count of that letter in the array. Next we add the character to our queue. Then is processing. We check if queue is non empty and its front is a repeating character, if yes we pop it out. after that, either queue is empty (in that case we append # into answer) or queue's front is a non repeating character.. then we append it into answer. At the end return ans.

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        string ans = "";
        int arr[26] = {0};
        queue<char> q;

        for (char c : A)
        {
            // increase the count
            arr[c - 'a']++;
            // add to queue
            q.push(c);
            // jabtak queue khali nhi and front is repeating char, pop it
            while (!q.empty() && arr[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            // append to ans as per status of queue
            if (q.empty())
            {
                ans.push_back('#');
            }
            else
            {
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};