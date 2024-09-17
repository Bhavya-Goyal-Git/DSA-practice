#include <iostream>
#include <string>
#include <queue>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/rearrange-string_982765?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You are given a string 'S'. Your task is to rearrange the characters of a string 'S', such that it does not contain any two adjacent characters which are the same. If it is possible to rearrange the string 'S', then print any possible arrangement. else, print 'not possible' without quotes.
// For Example: For a string 'qaacde', This string has two same adjacent characters. So, one possible way to rearrange the string is 'qacade'. Now, this string does not have two adjacent characters that are the same.

// Approach : We can use a max-heap here. Firstly we will need to store freq of each character in the given string. For that we can use a array of size 26. Now, we need to create a max-heap that stores these char's based on their freq. For that we create a custom datatype (stores char and its freq) and we will have to override the < operator for the max-heap to work (be careful, it needs to be const). Into this max-heap we insert all non zero entries of the array. Now we declare a prev value of this custom datatype with garbage values (freq should be negative), the approach is that, we begin by inserting the most freq char, then pop it out of heap for next iteration, then use 2nd most freq char, pop it and push back the first one. This alternating will ensure no repition, how ever if a single char is left with >0 freq at end, reconstructed string will not be equal in length to the original one and we return "not possible". To do so, we run a while loop till heap is non-empty and push top character into string-ans. Then reduce its freq. Then push back the prev value into heap if freq of it was greater than 0. Then assign current top we popped out to prev. After the loop compare the length of 2 strings and return accordingly.
// This approach uses O(n log(26)) time, and a heap for space that is at most of 26 size.
// This approach is however not the best way to solve this problem, a better way is to use a hashmap to store freq by order and then begin inserting the max-freq one at odd/even places and also return not-possible if freq of most occuring char is > (length +1)/2 for the string... It would have O(n) time comp

class charFreq
{
public:
    char c;
    int freq;
    charFreq(char ch, int f)
    {
        c = ch;
        freq = f;
    }
    bool operator<(const charFreq &right) const
    {
        return freq < right.freq;
    }
};

string reArrangeString(string &s)
{
    priority_queue<charFreq> pq;
    int arr[26] = {0};
    for (char i : s)
    {
        arr[i - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i])
        {
            char x = 'a' + i;
            pq.push(charFreq{x, arr[i]});
        }
    }
    charFreq prev('#', -1);
    string ans = "";
    while (!pq.empty())
    {
        charFreq cf = pq.top();
        pq.pop();
        ans.push_back(cf.c);
        cf.freq--;
        if (prev.freq > 0)
        {
            pq.push(prev);
        }
        prev = cf;
    }
    if (ans.size() != s.size())
    {
        return "not possible";
    }
    return ans;
}