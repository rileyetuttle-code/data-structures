/// Parenthesis Matching
//(((A/B)-C)+(D*E))-(F*G)
//(((A/B)-C)+(D*E)-(F*G)
#include<iostream>
using namespace std;
template<class T>
class Stack
{
private:
    T *S;
    int top, len, Size;
public:
    Stack(int);
    ~Stack();
    void Push(T);
    void Pop();
    bool Find(int, T&);
    int Search(T);
    int Length(){return len;}
    bool isEmpty();
    bool isFull();
    void Display();
    T TopElement();
    bool isParenthesised(char *p);
};
template<class T>
bool Stack<T>::isParenthesised(char *p)
{
    int i=0;
    while(p[i] != '\0')
    {
        if(p[i] == '(')
            Push(p[i]);
        else if(p[i] == ')')
        {
            if(top == -1) return false;
            Pop();
        }
        i++;
    }
    if(top == -1) return true;
    return false;
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
    delete [] S;
}

template<class T>
void Stack<T>::Push(T Element)
{
    if(top == Size - 1)
    {
        cout<<"Stack OverFlows...";
        return;
    }
    S[++top] = Element;
    len++;
}
template<class T>
void Stack<T>::Pop()
{
    if(top == -1)
    {
        cout<<"Stack UnderFlows..";
        return;
    }
 //   Element = S[top];
    top--;
    len--;
}
/*
template<class T>
T Stack<T>::TopElement()
{
    return S[top];
}


template<class T>
void Stack<T>::Display()
{
    for(int i=0;i<=top;i++)
        cout<<S[i]<<" ";
    cout<<endl;
}

template<class T>
bool Stack<T>::isEmpty()
{
     return top == -1;
}

template<class T>
bool Stack<T>::isFull()
{
     return top == Size -1;
}
template<class T>
bool Stack<T>::Find(int pos, T& Element)
{
    if(pos < 1 || pos > top)
    {
        cout<<"\nINVALID Position";
        return false;
    }
    Element = S[pos - 1];
    return true;
}

template<class T>
int Stack<T>::Search(T Element)
{
    for(int i=0;i<=top;i++)
    {
        if(Element == S[i])
            return i+1;
    }
    return -1;
}
*/
int main()
{
    Stack<int> st(30);
    char expr[30];
    cout<<"\nEnter a Parenthesised  Expression \n";
    cin>>expr;

    if(st.isParenthesised(expr))
        cout<<"\nThe Expression is Fully Parenthesised...";
    else
        cout<<"\nThe Expression is Not Fully Parenthesised...";

 /*   int x;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);

    st.Display();

    st.Pop(x);

    cout<<"\nElement Deleted is ..."<<x;
    cout<<endl;
    st.Display();

    cout<<"\nThe TopMost Element in the Stack is..."<<st.TopElement();

    if(st.Find(4,x))
        cout<<"\nElement is ..."<<x;
    x = st.Search(50);
    if(x==-1)
        cout<<"\nElement NOT Found\n";
    else
        cout<<"\nElement Found at position "<<x;

    if(st.isEmpty())
        cout<<"\nSTACK UnderFlows...\n"<<x;
    if(st.isFull())
        cout<<"\nSTACK OverFlows...\n"<<x;
*/
}



