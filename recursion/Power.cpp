#include <iostream>
using namespace std;

int Power(int a, int b)
{
    if(b==0) return 1;
    return Power(a, b-1) * a;
}

int OptPower(int a, int b)
{

    if(b==0) return 1;
    int temp;
    temp = OptPower(a, b/2);
    int power = temp * temp;
    if((b%2) != 0)
        return a*power; /// Odd Number
    return power; /// Even Number
}
int main()
{

    int x,y,res;
    cout<<"\nEnter Base and Power...";
    cin>>x>>y;
    res = Power(x,y);
    cout<<"\nThe Result of "<<x<<"^"<<y<<" is "<<res;
    res = OptPower(x,y);
     cout<<"\nThe Result of Optimized Power function "<<x<<"^"<<y<<" is "<<res;
    return 0;
}

