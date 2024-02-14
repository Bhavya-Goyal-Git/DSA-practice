#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTabValue=SUBMISSION

// Problem : Find triplets from array whose sum is given as k.

// Approach : First we sort the array. then using i to iterate over the array while using j and k for 2 pointer approach. if sum of elements at i j k is equal to req val, add the pair to answer array, then increment j and decrement k. also check duplicates in j and k and increment decrement appropriately. however, if sum is les than req val, increment j (remember that array is sorted), else (sum is greater than req val), decrement k

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> answer;
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            if (arr[i] + arr[j] + arr[k] == K) {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                answer.push_back(temp);
                j++;
                k--;
                // Skip duplicates
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            } else if (arr[i] + arr[j] + arr[k] < K) {
                j++;
            } else {
                k--;
            }
        }
    }
    return answer;
}