#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION

// Problem : Given is a array (unsorted) with random x-coordinates denoting position of stalls. we also have an integer k that is number of aggressive cows. we have to assign cows to stalls such that minimum distance between any two cows is maximum. Simply stating, we have to first sort the array and partition it in k-1 partitions such that value of difference of end points of partition is maximum possible. return the max possible minimum distance between cows.

// Approach : We use binary search. The search space has low=0 and high is max value present in the array. (technically not correct but works). remember to sort positions array prior to work. we calculate mid and check is it a possible answer, if yes we store it and take low to mid+1 so that we can check if a larger value is possible. but if it is not a possible value, that means it is too high distance and not all cows can be accomodated then we bring high to mid-1

// Approach for ispossible(): Once again remember that position array ush be sorted. We make 2 variables, 1 for assigning cows, initially assigned to 1 and one which stores the position of last cow, initially assigned to arr[0]. now we traverse the array, we check if arr[i]-lastposition is >=mid i.e. if a cow can be assigned at given location, if yes, increase cowcount and immediately check if cowcount has reached k, then return true. otherwise, assign lastposition to arr[i] as the next cow is assigned that position. at end of loop, if nothing occured, return a false.


bool ispossible(vector<int> &stalls, int k, long long int mid){
    int cowcount = 1;
    long long int prevpos = stalls[0];
    for(int i = 0; i<stalls.size(); i++){
        if(stalls[i]-prevpos>=mid){
            cowcount++;
            if (cowcount==k){
                return true;
            }
            prevpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    long long int low = 0;
    long long int high=-1;
    long long int ans = -1;
    for(int i =0; i<stalls.size();i++){
        if (stalls[i]>high)
        high = stalls[i];
    }
    long long int mid = low + (high-low)/2;
    while(low<=high){
        if (ispossible(stalls,k,mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        mid = low + (high-low)/2;
    }
    return ans;
}