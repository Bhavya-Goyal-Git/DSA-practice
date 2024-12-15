#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Problem: You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline. Your task is to find:
//  The maximum number of jobs that can be completed within their deadlines.
//  The total maximum profit earned by completing those jobs.

// Approach: We sort it by profits (greedy) and then try assigning jobs time slots, and decide!

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}
class Solution
{
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit)
    {
        vector<pair<int, int>> v; // deadline,profit
        for (int i = 0; i < id.size(); i++)
            v.push_back(make_pair(deadline[i], profit[i]));
        sort(v.begin(), v.end(), cmp);
        int maxdeadline = INT32_MIN;
        for (int i = 0; i < deadline.size(); i++)
            maxdeadline = max(maxdeadline, deadline[i]);
        vector<int> times(maxdeadline + 1, -1);
        int count = 0, maxprofit = 0;
        for (int i = 0; i < id.size(); i++)
        {
            for (int k = v[i].first; k >= 1; k--)
            {
                if (times[k] == -1)
                {
                    count++;
                    maxprofit += v[i].second;
                    times[k] = v[i].second;
                    break;
                }
                else if (v[i].second > times[k])
                {
                    maxprofit -= times[k];
                    maxprofit += v[i].second;
                    times[k] = v[i].second;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxprofit);
        return ans;
    }
};