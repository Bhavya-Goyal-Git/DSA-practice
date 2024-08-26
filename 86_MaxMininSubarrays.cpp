#include <iostream>
#include <queue>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTabValue=SUBMISSION

// Problem : Given a array of size n and a integer k, find the sum of the maximum and the minimum element in every subarray of size k and return the sum of all such sums.

// Approach : We will need 2 deque of size k each for the O(n) time solution. These maintain the indices of maximum and minimum element seen at their front and indices of all sequential elements in descending and ascending orders respectively. This is kind of sliding window problem. Firstly we solve for the first window of size k. For each element we find position in the maxi and mini deque from the back and pop elements until necessary (or the queue's empty) and then push_back that element. After this, add the front element of both deque's to the ans. Now we have to process rest of the subarrays, therfore we loop from k to n-1 and firstly we do any removal if necessary, that is i-deque.front() >=k [ has entry in deque gone out of the subarray limit ] then pop from front. Then we do additon of element into the dequeus using the same way we did before. After it, add the queue's fronts to the ans. At the end of loop, return the ans.

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    // Write your code here.
    long long ans = 0;
    deque<int> maxi(k);
    deque<int> mini(k);

    // processing first window of k size
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && nums[mini.back()] >= nums[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    ans += nums[maxi.front()] + nums[mini.front()];

    // processing all other windows
    for (int i = k; i < n; i++)
    {

        // Removal from queues if required
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // Addition to the queues
        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && nums[mini.back()] >= nums[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        // calculating ans for the window
        ans += nums[maxi.front()] + nums[mini.front()];
    }
    return ans;
}