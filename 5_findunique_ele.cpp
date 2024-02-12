#include <iostream>
using namespace std;

// Problem link :
// https://www.codingninjas.com/studio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&count=25&page=2&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=SUBMISSION

// Problem : Given is an array of size n = 2m+1. m number of elements appear twice, but one element appears only once. find that unique element.

// Approach :
// We use XOR property, note that a^a=0, a^0=a. Therefore take XOR of all elements in the array, only non repeating element will be left.


int uniqueele(int arr[],int size)
{
    int result=0;
    for(int i=0;i<size;i++)
    {
        result = result^arr[i];
    }
    return result;
}
