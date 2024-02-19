#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.codingninjas.com/studio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTabValue=SUBMISSION

// Problem : Sorting an array of 0s 1s and 2s only

// Approach : DNF (dutch national flag) algorithm. similar to 2 pointer problem, we create 3 pointers low mid high. run the loop till mid<=high. if value at mid is 0, swap it with low and increment both mid and low. if alue is 1, do nothing and increment mid while if value is 2, swap with high and only decrement high. dont increment mid in last case as we dont have processed what might have been swapped


void sort012(int *arr, int n)
{
   int low=0,mid=0,high=n-1;
   while(mid<=high)
   {
       if (arr[mid]==0)
       {
           swap(arr[low],arr[mid]);
           mid++;
           low++;
       }
       else if (arr[mid]==2)
       {
           swap(arr[high],arr[mid]);
           high--;
       }
       else
       {
           mid++;
       }
       for (int i=0;i<6;i++)
       {
            cout<< arr[i] << " ";
       }
       cout<<endl;
   }
}

// int main()
// {
//     int arr[6]={2,1,2,0,1,0};
//     sort012(arr,6);
//     // for (int i=0;i<6;i++){
//     //     cout<< arr[i] << " ";
//     // }
// }