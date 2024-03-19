#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION

// Problem : Given an array of size n, containing ranks of chefs. A cook with a rank ‘R’ can prepare 1 dish in the first ‘R’ minutes, 1 more dish in the next ‘2R’ minutes, 1 more dish in next ‘3R’ minutes, and so on (A cook can only make complete dishes) For example if a cook is ranked 2. He will prepare one dish in 2 minutes, one more dish in the next 4 mins and one more in the next 6 minutes hence in a total of 12 minutes he can make 3 dishes, Note, In 13 minutes also he can make only 3 dishes as he does not have enough time for the 4th dish). Given is also an integer m, that is number of dishes to be made. return the minimum time in which dishes can be prepared.

// Approach : Binary search. the search space is 0 to time taken by largest ranked chef to prepare all the dishes. if mid is satisfied value, store in answer and move to loweer part (high=mid-1) as we finding the minimum else do low = mid+1

// Approach for ispossible() : iterate through entire array. check for each chef how many dishes can he prepare in given time, add that value to a total. if total exceeds the value "m" at any point, return true, else at end of for loop, return false.


bool ispossible(vector<int> &rank, int m, int mid)
{
    int num_dishes = 0;
    for (int i = 0; i < rank.size(); i++)
    {
        int dishnumber = 1;
        int timeleft = mid;
        while (timeleft - dishnumber * rank[i] >= 0)
        {
            timeleft -= dishnumber * rank[i];
            dishnumber++;
            num_dishes++;
            if (num_dishes >= m)
            {
                return true;
            }
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    int low = 0;
    int high = 0;
    for (int i = 0; i < rank.size(); i++)
    {
        if (rank[i] > high)
            high = rank[i];
    }
    high = (high * (m + 1) * m) / 2; // time taken to prepare all dishes by largest ranked chef
    int ans = -1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (ispossible(rank, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> rank;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        rank.push_back(element);
    }
    cout << minCookTime(rank, m);
    return 0;
}