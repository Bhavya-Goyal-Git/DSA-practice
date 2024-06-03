#include <iostream>
#include <vector>
#include "../../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/algorithmfwd.h"
using namespace std;

// Problem link: https://www.naukri.com/code360/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4&leftPanelTabValue=SUBMISSION

// Problem: Given 2 vectors that represent positive integers, return a new vector containing sum of them. note that [1,2,3,4] represents the number 1234 in actual.

// Approach: we loop from backward in both arrays until one of htem exhausts. at each step we add both place values and carry from previous time (initially 0), take %10 for pushing back in answer and take /10 as next carry over. then do the same individually for both vectors to ensure no digit remains. at end, we repeat same process until the carry remaining is zero. Note that the answer vector being developed is in reverse form, so we reverese it before returning the answer.

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    vector<int> answer;
    int carryOver = 0;
    int firstNumPlace = n - 1;
    int secondNumPlace = m - 1;

    while (firstNumPlace != -1 && secondNumPlace != -1)
    {
        int CurrentVal = a[firstNumPlace] + b[secondNumPlace] + carryOver;
        answer.push_back(CurrentVal % 10);
        carryOver = CurrentVal / 10;
        firstNumPlace--;
        secondNumPlace--;
    }
    while (firstNumPlace != -1)
    {
        int CurrentVal = a[firstNumPlace] + carryOver;
        answer.push_back(CurrentVal % 10);
        carryOver = CurrentVal / 10;
        firstNumPlace--;
    }
    while (secondNumPlace != -1)
    {
        int CurrentVal = b[secondNumPlace] + carryOver;
        answer.push_back(CurrentVal % 10);
        carryOver = CurrentVal / 10;
        secondNumPlace--;
    }
    while (carryOver != 0)
    {
        answer.push_back(carryOver % 10);
        carryOver = carryOver / 10;
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}