/// Singly Linked Lists 
#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
    T Data;
    Node<T> *link;
};

template<class T>
class Chain
{
    private:
      Node<T> *first, *last;
      int len;
    public:
        Chain();
        ~Chain();
        void Insert(int, T);
        void Delete(int, T&);
        bool Find(int, T&);
        int Search(T);
        void Display();
        int Length(){ return len;}
        bool isEmpty();
        //bool isFull();
};
template<class T>
Chain<T>::Chain()
{
    first = last = NULL;
    len=0;
}
template<class T>
bool Chain<T> ::isEmpty()
{
    if (first==NULL)
        return true;
    else
        return false;
}


template<class T>
int Chain<T>::Search(T Element)
{
    Node<T> *p = first;
    int i=1;
    while(p != NULL)
    {
        if(Element == p->Data)
            return i; /// Succ Search
        p=p->link;
        i++;
    }
    return -1; /// Unsucc Search

}
template<class T>
bool Chain<T>::Find(int pos, T &Element)
{
    if(pos < 1 || pos>len)
    {
        cout<<"Invalid Position....";
        return false;
    }
    Node<T> *p=first;
    for(int i=1;i<pos;i++)
        p=p->link;
    Element = p->Data;
    return true;
}
template<class T>
void Chain<T>::Insert(int pos,T Element)
{
    Node<T> *temp;
    temp = new Node<T>;
    temp->Data = Element;
    temp->link=NULL;
    if(len==0)
    {
        first = last = temp;
    }
    else
    {
        if(pos == 1)
        {
            temp->link = first;
            first = temp;
        }
        else if(pos == len+1)
        {
            last->link = temp;
            last = temp;
        }
        else
        {
            Node<T> *p=first;
            for(int i=1;i<=pos-2;i++)
                p=p->link;
            temp->link = p->link;
            p->link = temp;
        }
    }
    len++;
}
template<class T>
void Chain<T>::Delete(int pos, T &Element)
{
    Node<T> *p,*q;
    p=first;
    q=nullptr;
    if(len==0)
    {
        cout<<"Linked List is Empty...";
        return;
    }
    if(pos==1)
    {
        q = first;
        first=first->link;
    }
    else if(pos==len)
    {
        for(int i=1;i<=pos-2;i++)
        {
            p=p->link;
        }
        q=p->link;
        p->link=NULL;
        last=p;
    }
    else
    {
        for(int i=1;i<=pos-2;i++)
            p=p->link;
        q=p->link;
        p->link = q->link;
    }
    Element = q->Data;
    delete q;
    len--;
}

template<class T>
void Chain<T>::Display()
{
    Node<T> *p = first;
    while(p != NULL)
    {
        cout<<p->Data<<"->";
        p=p->link;
    }

}
template<class T>
Chain<T>::~Chain()
{
    Node<T> *p = first;
    while(p != NULL)
    {
        first = first->link;
        cout<<"\n"<<p->Data<<" deleted";
        delete p;
        p=first;
    }

}
int main()
{
    Chain<int> C;
    int x;
    C.Insert(1,10);
    C.Insert(2,20);
    C.Insert(3,30);
    C.Insert(4,40);
    C.Insert(5,50);
    C.Insert(1,100);

    C.Display();
    C.Delete(6,x);

    cout<<"\nThe Element Deleted is...."<<x <<endl;
    C.Display();
    cout<<endl;
    if(C.Find(2,x))
        cout<<"\nElement Found is..."<<x<<endl;
    x=C.Search(50);
    if(x != -1)
        cout<<"\nElement found at "<<x<<" position.";
    else
        cout<<"\nElement Not Found";
        
    if (C.isEmpty())
        cout<<"\nlist is empty.....";
    else
        cout<< "\nlist is not empty.....";
    return 0;
}




