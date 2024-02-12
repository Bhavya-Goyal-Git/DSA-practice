#include <iostream>
using namespace std;

// An array of n elements given. 1 to n-1 elements appear atleast once. One element appears twice, find it.

//Approach 1- Running sum
int duplicate(int arr[], int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    return sum-((size-1)*size/2);
}

//Approach 2- XOR all array together with 0 to n-1 numbers
int duplicates(int arr[], int size)
{
    int result=0;
    for(int i=0;i<size;i++)
    {
        result = result^arr[i]^i;
    }
    return result;
}


int main()
{
    int numbers[10]={1,2,3,4,5,6,6,7,8,9};

    cout<<"Result : "<< duplicate(numbers,10)<<endl;
    cout<<"Result : "<< duplicates(numbers,10)<<endl;

    return 0;
}