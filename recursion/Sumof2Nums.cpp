#include <iostream>
using namespace std;
int Sum(int a, int b)
{
    if(a==0)
        return b;
    else if(b==0)
        return a;
    return Sum(a, b-1) + 1;
}

int main()
{
    int x,y,Result;
    cout<<"\nEnter 2 Numbers...";
    cin>>x>>y;
    Result = Sum(x,y);
    cout<<"\nThe Sum = "<<Result;
    return 0;
}

