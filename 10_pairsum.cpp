#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTabValue=SUBMISSION

// Problem : Given an array, and a integer k, return all pairs of integers that have the sum k. pairs must be sorted, array too.

// Approach : create a hash map. as we traverse through array, we check if complement of element exists in hash map (k-arr[i]) if yes, make a  sorted pair. Then we check frequency of complement, and push the pair that many times in answer array. we also add current element to hash map and increase its frequency by 1. at the end, we sort and return the master array.

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
   unordered_map<int,int> freq;
   vector<vector<int>> answer;

   for (auto c : arr)
   {
      int comp = s-c;
      if (freq.find(comp)!=freq.end())
      {
         int count = freq[comp];
         vector<int> temp;
         temp.push_back(min(c,comp));
         temp.push_back(max(c,comp));
         while(count--)
         {
            answer.push_back(temp);
         }
      }
      freq[c]++;
   }
   sort(answer.begin(),answer.end());
   return answer;
}