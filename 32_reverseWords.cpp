#include <iostream>
#include <vector>
using namespace std;

// Problem: Given is a vector of chars containing words. Reverse the order of words.
// Approach: first we reverse the entire array, then traverse from front till end and reverse each word as it occurs (by indentifying spaces) Dont forget to reverse last word out of loop!!

void Reverse(vector<char> &ch, int i, int j)
{
    while (i < j)
    {
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}

void wordReverse(vector<char> &ch)
{
    // reverse the entire array
    Reverse(ch, 0, ch.size() - 1);
    // reverse each word as soon as a space occurs
    int prev = 0;
    for (int i = 0; i < ch.size(); i++)
    {
        if (ch[i] == ' ')
        {
            Reverse(ch, prev, i - 1);
            prev = i + 1;
        }
    }
    // reverse final word
    Reverse(ch, prev, ch.size() - 1);
}

int main()
{
    vector<char> ch = {'t', 'h', 'e'};
    wordReverse(ch);
    for (int i = 0; i < ch.size(); i++)
    {
        cout << ch[i];
    }
}