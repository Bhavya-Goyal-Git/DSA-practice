#include <iostream>
#include <queue>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
//  A 1-day pass is sold for 'COST'[0] coins,
//  A 7-day pass is sold for 'COST'[1] coins, and
//  A 30-day  pass is sold for 'COST'[2] coins.
//  The passes allow for many days of consecutive travel. Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

// Approach : This is even better, O(n)time ans O(1) space approach to the previous problem, without any dp. This rather uses a queue and sliding window concept. 2 queues are week and month stores that store at most 7 and 30 entries. (no queue for day as day is simple: prevValue + cost[0]). So we make 2 queues and run a loop across days given. The queues are of pairs of form (day,cost). First of all we clear the queues of entires that are old. i.e. from month queue pop from front all enties such that q.front.first <= day (current day) and similarly for week. Then push currrent day entries into month and week queue. month.push(day,ans+cost[2]) and similarly week.push(day,ans+cost[1]) then make a comparison. ans = minimum of the three, that is ans+cost[0] (1 day pass i.e. prevValue + cost[0]) and month.front.cost and week.front.cost. After the loop, ans variable has minimum cost possible.

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;
    queue<pair<int, int>> week; // (day,cost)
    queue<pair<int, int>> month;
    for (int day : days)
    {
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();
        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();
        month.push({day, ans + cost[2]});
        week.push({day, ans + cost[1]});
        ans = min(ans + cost[0], min(month.front().second, week.front().second));
    }
    return ans;
}