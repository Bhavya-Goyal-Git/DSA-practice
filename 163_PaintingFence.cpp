#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color. Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

// Approach : Observe that if n=1 then, there are k ways. When n=2, then there are k ways (in which both post have same color) and k*(k-1) ways (in which 2 posts have different color). Total for n=2 is k+K(k-1) = k^2. We see that three posts can never be of same color.. so we divide further cases (like we did with second one), when last 2 posts have same color and when diff. For n=3, observe: How many can be same coloured ways? For that, first 2 must be different. Therefore, different of 2 posts ways (take the color which is same as last post). So same(3) = diff(2). Now, for diff(3)... Well, take all total ways of 2, and each can have k-1 colors added at the end (differnt than the last one).. so diff(3) = total(2)*k-1...
//  IN this way we form 3 relations:
//  Total[i] = same[i] + diff[i]
//  Same[i] = diff[i-1]
//  diff[i] = total[i-1] * (k-1)
//  We are finding total(n).. And wish to get rid of so many relations, therefore by subsitution, observe that: total[i] = total[i-1] * (k-1) + total[i-2] * (k-1) = (total[i-1] + total[i-2])*(k-1)
//  Now that formula is ready, dp is easy to form

#define MOD 1000000007

// memoisation
int solve(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k % MOD; // k + k(k-1)
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (((solve(n - 2, k, dp) % MOD) + (solve(n - 1, k, dp) % MOD)) * 1LL * (k - 1)) % MOD;
    return dp[n];
}

// tabulation
int solve2(int n, int k)
{
    vector<int> dp(n + 1);
    dp[1] = k;
    dp[2] = k * k % MOD; // k + k(k-1)
    for (int i = 3; i <= n; i++)
        dp[i] = (((dp[i - 2] % MOD) + (dp[i - 1] % MOD)) * 1LL * (k - 1)) % MOD;
    return dp[n];
}

// space optimisation
int solve3(int n, int k)
{
    int prev1 = k;
    if (n == 1)
        return prev1;
    int prev2 = k * k % MOD; // k + k(k-1)
    for (int i = 3; i <= n; i++)
    {
        int ans = (((prev1 % MOD) + (prev2 % MOD)) * 1LL * (k - 1)) % MOD;
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}

int numberOfWays(int n, int k)
{
    // vector<int> dp(n+1,-1);
    return solve3(n, k);
}