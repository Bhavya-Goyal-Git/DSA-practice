#include <iostream>
using namespace std;

void printarray(int arr[], int size)
{
    cout<< "Printing the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<< " ";
    }
}

int uniqueele(int arr[],int size)
{
    //In an array of 2m+1 numbers, m numbers apper twice.
    //this function returns the number that appears only once
    //uses xor property that a^a=0 and a^0=a
    int result=0;
    for(int i=0;i<size;i++)
    {
        result = result^arr[i];
    }
    return result;
}

int main()
{
    int numbers[11]={1,2,4,3,6,5,5,1,2,4,3};
    cout<< "Answer is : "<<uniqueele(numbers,11);
    return 0;
}