#include <iostream>
using namespace std;


int main()
{
    int n;
    cout << "Enter number to be checked : ";
    cin>>n;
    int count=0;
    cout<< endl;
    while(n!=0)
    {
        if (n&1)
        count++;
        if (count>1)
        {
            cout<< "NAh"<<endl;
            return 0;
        }
        n=n>>1;
    }
    cout<< "YAS"<<endl;
    return 0;
}