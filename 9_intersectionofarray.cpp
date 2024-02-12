#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTabValue=SUBMISSION

// Problem : Given 2 arrays of size n and m respectively, find intersection of elements. arrays are sorted in ascending order

// Solution : 2 pointer approach. compare element at ith and jth index, if equal add to answer array, and increment both pointers. else, increment the one pointing smaller value

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> answer;
	int i=0,j=0;
	while(i<n && j<m)
	{
        if (arr1[i] == arr2[j])
		{
            answer.push_back(arr1[i]);
            i++;
            j++;
        } 
		else if (arr1[i] < arr2[j])
		i++;
		else
		j++;
	}
	return answer;
}