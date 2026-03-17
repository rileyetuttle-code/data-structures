#include <iostream>

using namespace std;

int Prod(int a, int b)
{
    if(a == 0 || b == 0)
        return 0;

    return Prod(a, b-1) + a;
}

int main()
{

    int x, y, res;
    cout << "\nEnter 2 numbers...";
    cin >> x >> y;
    
    res = Prod(x,y);
    cout << "The Product of " << x << " and " << y << " is " << res;
    return 0;
}

