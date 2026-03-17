#include <iostream>
using namespace std;

int GCD(int m, int n)
{
    if(m==n)
        return n;
    if(m > n)
        return GCD(m-n, n);
    else
        return GCD(m, n-m);
}

int GCD2(int m,int n)
{
    if(n != 0)
    {
        return GCD2(n, m%n);
    }
    return m;
}
int main()
{
    int a,b;
    cout<<"\nEnter Any 2 Numbers...";
    cin>>a>>b;
    cout<<"The Result is..."<<GCD2(a,b);
    return 0;
}

