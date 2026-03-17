/// Stack Using Linked Lists ( Linked Representation )
#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
    T Data;
    Node<T> *Link;
};
template<class T>
class LinkedStack
{

private:
    Node<T> *Top;
    int len;
public:
    LinkedStack();
    ~LinkedStack();
    void Push(T);
    void Pop(T&);
    bool Find(int, T&);
    int Search(T);
    int Length();
    bool isEmpty();
    void Display();
};

template<class T>
LinkedStack<T>::LinkedStack()
{
    Top = NULL;
    len = 0;
}
template<class T>
void LinkedStack<T>::Push(T Element)
{
    Node<T> *temp;
    temp = new Node<T>;
    temp->Data = Element;
    temp->Link = NULL;
    if(temp==NULL)
    {
        cout<<"\nStack OVERFLOWS...";
        return;
    }
    if(len==0)
    {
        Top = temp;
    }
    else
    {
        temp->Link = Top;
        Top = temp;
    }
    len++;
}

template<class T>
void LinkedStack<T>::Pop(T &Element)
{
    Node<T> *temp;
    if(len == 0)
    {
        cout<<"\nStack UNDERFLOWS...";
        return;
    }
    else
    {
           temp = Top;
           Top = Top->Link;
           Element = temp->Data;
           delete temp;
           len--;
    }
}
template<class T>
LinkedStack<T>::~LinkedStack()
{
    Node<T> *temp = Top;
    while(temp !=NULL)
    {
        Top = Top->Link;
        cout<<"\nDeleted Node is.."<<temp->Data;
        delete temp;
        temp=Top;
    }
}
template<class T>
void LinkedStack<T>::Display()
{
    Node<T> *temp = Top;
    while(temp !=NULL)
    {
        cout<<temp->Data<<"->";
        temp=temp->Link;
    }
}

int main()
{

    LinkedStack<char> St;
    char x;
    St.Push('a');
    St.Push('b');
    St.Push('c');
    St.Push('e');
    St.Push('f');

    St.Display();

    St.Pop(x);
    cout<<"\nElement Deleted is..."<<x;

    cout<<"\nStack After Deletion is...\n";
    St.Display();

}
