#include <iostream>
#include <vector>
using namespace std;

// This is the same question as previous one, just for strings.

void permute(string input, int index, vector<string> &ans)
{
    if (index >= input.size())
    {
        ans.push_back(input);
        return;
    }
    for (int i = index; i < input.length(); i++)
    {
        swap(input[index], input[i]);
        permute(input, index + 1, ans);
        swap(input[index], input[i]);
    }
}

int main()
{
    string a = "abc";
    int index = 0;
    vector<string> v;
    permute(a, index, v);
    int count = 0;
    for (string s : v)
    {
        cout << s << ", ";
        count++;
    }
    cout << "\nTotal permutations : " << count;
    return 0;
}