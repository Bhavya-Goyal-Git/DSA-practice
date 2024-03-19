#include <iostream>
using namespace std;

// Problem link: https://www.codingninjas.com/studio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION

// Problem : Given a positive integer n, find its square root in O(logn) complexity. if root is a float value, return the floor. ex return 2 for 8

// Approach : Implement binary search in region 0 to n. if value of mid^2 == n return mid, if it is bigger, bring high = mid-1 else (it is smaller) it could be the answer, store it and move low to mid+1. Special : make mid, ans variable as long long else things may blow up.


long long int floorSqrt(int n)
{
    if (n==0 || n==1)
    return n;
    int low=0, high=n;
    long long int mid = low + (high-low)/2;
    long long int ans = -1;

    while(low<=high){

        long long int square = mid*mid;
        if (square==n) {
            return mid;
        }
        else if (square<n ){
            ans = mid;
            low=mid+1;
        }
        else
        high=mid-1;
        mid = low + (high-low)/2;
    }
    return ans;
}