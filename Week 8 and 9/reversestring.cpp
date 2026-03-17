/// Reversing a String Using Stack
#include<iostream>
#include<string.h>
using namespace std;
template<class T>
class Stack
{
private:
    T* S;
    int top, len, Size;
public:
    Stack(int);
    ~Stack();
    void Push(T);
    void Pop(T&);
    bool isEmpty();
    void Reverse(char* st, int l);
};

template<class T>
void Stack<T>::Reverse(char* st, int lt)
{

    char* Rev = new char[lt]; // dynamically allocating new mwmory address for Rev array
    Rev[lt] = '\0'; // putting termainating point 
    int i = 0, j = 0;
    char x;
    while (st[i] != '\0')
        Push(st[i++]);
    while (!isEmpty())
    {
        Pop(x);
        Rev[j++] = x;
    }
    cout << "Reverse String is ..." << Rev;
}
template<class T>
Stack<T>::Stack(int sz)
{
    Size = sz;
    S = new T[Size];
    top = -1;
    len = 0;
}

template<class T>
Stack<T>::~Stack()
{
    delete[] S;
}

template<class T>
void Stack<T>::Push(T Element)
{
    if (top == Size - 1)
    {
        cout << "Stack OverFlows...";
        return;
    }
    S[++top] = Element;
    len++;
}
template<class T>
void Stack<T>::Pop(T& Element)
{
    if (top == -1)
    {
        cout << "Stack UnderFlows..";
        return;
    }
    Element = S[top];
    top--;
    len--;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

int main()
{
    Stack<char> s(30);
    char st[30];
    cout << "\nEnter a String...";
    cin >> st;

    int l = strlen(st);
    s.Reverse(st, l);

}






