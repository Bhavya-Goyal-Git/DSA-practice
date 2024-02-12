#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number to be reversed : ";
    cin>>n;
    int answer=0;
    cout<< endl;
    for (int i = n;i!=0;i=i/10)
    {
        if (answer>__INT32_MAX__/10 || answer < INT32_MIN/10)
        return 0;
        answer = answer*10 + i%10;
    }
    //if (n<0)
    //answer = -answer;
    cout<< "Reversed number is : " << answer<<endl;
    return 0;
}