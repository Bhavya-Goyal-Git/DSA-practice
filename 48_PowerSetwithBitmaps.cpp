#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Taking All subsets of a vector (Obtaining powerset) without using recursion. We use a trick called bitmaping here.
// Approach: Assuming our list has n elements, we know that possible subsets will be 2^n. For it, n binary digits will be sufficient to represent each number till 2^n or simply, numbers from 0 to 2^n -1 in binary can represent all our subsets mapped as bitmaps (We will consider an element is in subset if its corresponding index bit is 1 and not if its 0). Effectively, we will run a loop from 0 to 2^n -1 and individually inspect each number n times (0 to n-1 times in a nested loop) checking if LSB is 1, if yes we append out element into a temp vector. at each iteration, we right shift the value by 1. After compelete inspection, we push back the temp array into the answer array.

int main()
{
    cout << "Enter number of elements : ";
    int n;
    vector<int> v;
    cin >> n;
    cout << "\nEnter the elements : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int limit = pow(2, n);
    vector<vector<int>> ans;
    for (int i = 0; i < limit; i++)
    {
        int num = i;
        vector<int> iter;
        for (int j = 0; j < n; j++)
        {
            if (num & 1)
            {
                iter.push_back(v[j]);
            }
            num = num >> 1;
        }
        ans.push_back(iter);
    }
    int count = 0;
    cout << "[\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << "]" << endl;
        count++;
    }
    cout << "]";
    cout << "\nTotal : " << count << " Subsets.";
    return 0;
}