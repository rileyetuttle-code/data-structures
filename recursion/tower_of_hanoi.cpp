#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void tower_of_hanoi(int n, char fromRod, char auxRod , char toRod)
{
    // Base case
    if (n == 1)
    {
        cout << "Moving ring 1 from " << fromRod << " to " << toRod << endl;
    }
    else
    {
        tower_of_hanoi(n-1, fromRod, toRod, auxRod);
        cout << "Moving ring " << n << " from " << fromRod << " to " << toRod << endl;
        tower_of_hanoi(n-1, auxRod, fromRod, toRod);
    }
}

int main() 
{
    char A = 'A', B = 'B', C ='C';

    int n = 0;
    cin >> n;

    tower_of_hanoi(n, A, C, B);
    
    return 0;
}

