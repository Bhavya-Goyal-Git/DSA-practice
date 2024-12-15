#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Problem : You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Approach : Given in a standard problem of Activity Selectivity, which is best solved by greedy algorithm. To ensure max allocation of resource, we sort the times in order of finishing times.. Then run across the array and keep taking non conflicting meetings.. (keep track of last ending time and compare it with begin of new one, if we can begin it, then count++ and update the last ending time to end time of current meet), at end return ans.. Time comp is O(nlog(n))

bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < start.size(); i++)
        {
            v.push_back(make_pair(start[i], end[i]));
        }
        sort(v.begin(), v.end(), comparator);
        int ans = 0;
        int lastendtime = -1;
        for (auto &p : v)
        {
            if (p.first > lastendtime)
            {
                lastendtime = p.second;
                ans++;
            }
        }
        return ans;
    }
};