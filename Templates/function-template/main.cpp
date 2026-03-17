/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;


template <class Type>
Type getmax (Type a, Type b)
{
    if (a>b)
	    return a;
    else 
	    return b;

}

int main ()
{
int x=20, y=30;
int max = getmax(x,y);
cout<< "maximum number is " << max << endl;
float a= 5.07, b = 6.90;
float maxf = getmax(a,b);
cout<< "maximum number is " << maxf << endl;
return 0;
}


