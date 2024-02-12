#include <iostream>
using namespace std;

int numdone(int j, int n)
{
    int decrementval = 0, sum =0, i=1;
    while(i<j)
    {
        sum += n - decrementval;
        decrementval++; i++;
    }
    return sum;
}

int main()
{
    int i=1,j,n;
    cout<<"Enter numer of rows : "<<endl;
    cin>>n;
    cout<<endl;
    while(i<=n)
    {
        j=1;
        while(j<=i)
        {
            if (j%2==1)
                cout<<numdone(j,n)+i-j+1<<" ";
            else
                cout<<numdone(j,n)+n-i+1<<" ";
            j++;
        }
        cout<<"\n";
        i++;
    }
    cout<<endl;
    return 0;
}