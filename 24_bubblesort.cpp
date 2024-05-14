#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
   for (int i=0;i<n-1;i++){
       for(int j=0;j<n-1-i;j++){
           if (arr[j]>arr[j+1]){
               swap(arr[j],arr[j+1]);
           }
       }
   }
}


// Optimised code ------------------------------------------
// In best case, if we get already sorted array, bubble sort runs only once, giving time complexity of O(n)

void bubbleSort(vector<int>& arr, int n)
{   
   for (int i=0;i<n-1;i++){
       bool swapped =false;
       for(int j=0;j<n-1-i;j++){
           if (arr[j]>arr[j+1]){
               swap(arr[j],arr[j+1]);
               swapped=true;
           }
       }
       if (!swapped){
           break;
       }
   }
}