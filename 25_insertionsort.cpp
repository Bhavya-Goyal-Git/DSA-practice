#include <iostream>
#include <vector>
using namespace std;


void insertionSort(int n, vector<int> &arr){
    for (int i=1; i<n; i++){
        int current_element = arr[i];
        int j=i-1;
        while(arr[j]>current_element && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[++j]=current_element;
    }
}