/// Circular Linked Lists 
#include<iostream>
using namespace std;
template<class T>
class Node
{
	public:
		T data;
		Node<T> *next;

};

template<class T>
class CLL
{
public:
    Node<T> *first, *last;
    int len;
public:
    CLL();
    ~CLL();
    void Insert(int, T);
    void Delete(int , T&);
    bool Find(int , T&);
    int Search(T);
    void Display();
    void RDisplay(Node<T> *p);
    int Length();
    bool isEmpty();
};
template<class T>
CLL<T>::CLL()
{
    len=0;
    first = NULL;
    last = NULL;
}
template<class T>
CLL<T>::~CLL()
{
    Node<T> *p = first;
    while(p->next != first)
        p=p->next;
    while(p!=first)
    {
        p->next=first->next;
        cout<<first->data<<" Deleted \n";
        delete first;
        first = p->next;

    }
    if(p==first)
    {
        cout<<first->data<<" Deleted \n";
        delete first;
        first = NULL;
    }
}
template<class T>
void CLL<T>::RDisplay(Node<T> *p)
{
    static int visited = 0;
    if(p!=first || visited==0)
    {
        visited = 1;
        cout<<p->data<<"->";
        RDisplay(p->next);
    }
    visited=0;

}
template<class T>
void CLL<T>::Display()
{
    Node<T> *p = first;
    cout<<p->data<<"->";
    p=p->next;
    while(p != first)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"\n\n";
}
template<class T>
void CLL<T>::Delete(int pos, T& Element)
{
    if(len==0)
    {
        cout<<"\nLinked List is EMPTY..\n";
        return;
    }
    Node<T> *p, *q;
    p=q=first;
    if(pos==1)
    {
        first = first->next;
        last->next = first;
    }
    else if(pos==len)
    {
        for(int i=1;i<=pos-2;i++)
            p=p->next;
        q = last;
        last = p;
        last->next = first;
    }
    else
    {
        for(int i=1;i<=pos-2;i++)
            p=p->next;
        q = p->next;
        p->next = q->next;
    }
    Element = q->data;
    delete q;
    len--;
}

template<class T>
void CLL<T>::Insert(int pos, T Element)
{
    Node<T> *temp;
    temp = new Node<T>;
    temp->data = Element;
    temp->next = temp;
    if(len==0)
    {
        first = last = temp;
    }
    else
    {
        if(pos==1)
        {
            temp->next = first;
            first = temp;
            last->next=first;
        }
        else if(pos==len+1)
        {
            last->next = temp;
            last = temp;
            last->next = first;
        }
        else
        {
            Node<T> *p = first;
            for(int i=1;i<=pos-2;i++)
                p=p->next;
            temp->next = p->next;
            p->next = temp;
        }
    }
    len++;
}

int main()
{
    CLL<int> C;
    int x;
    C.Insert(1,100);
    C.Insert(2,200);
    C.Insert(1,300);
    C.Insert(4,400);
    C.Insert(5,500);
    C.Insert(2,600);

    C.Display();

    C.Delete(1, x);
    cout<<"\nDeleted Element is ..."<<x;

    cout<<"\nAfter Delete....\n";
    

    C.RDisplay(C.first);
    cout<<endl;
}
