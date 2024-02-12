#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    int n,i=0,answer=0;
    cout<< "enter a number : ";
    cin>>n;
    cout<<endl;

    if (n==0)   //edge case
    answer=1;

    while(n!=0)
    {
        if(!(n&1))
        {
            answer = answer + pow(2,i);
        }
        n = n>>1;
        i++;
    }
    cout<< "result : " << answer << endl;
    return 0;
}