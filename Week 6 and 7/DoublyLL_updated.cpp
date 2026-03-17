/// Program implementing Doubly Linked Lists
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
    T Data;
    Node<T>* Lptr, * Rptr;
};

template<class T>
class DLL
{
private:
    Node<T>* first, * last;
    int len;
public:
    DLL();
    ~DLL();
    void Insert(int, T);
    void Delete(int, T&);
    bool Find(int, T&);
    int Search(T);
    void Display();
    bool isEmpty();
    int Length() { return len; }
};
template<class T>
DLL<T>::DLL()
{
    len = 0;
    first = NULL;
    last = NULL;
}
template<class T>
DLL<T>::~DLL()
{
    Node<T>* p = first;
    while (p != NULL)
    {

        first = first->Rptr;
        delete p;
        p = first;
    }
}
template<class T>
bool DLL<T>::Find(int pos, T& Element)
{
    if (pos<1 || pos>len)
    {
        cout << "\nInvalid Position...\n";
        return false;
    }
    Node<T>* p = first;
    for (int i = 1; i < pos; i++)
        p = p->Rptr;
    Element = p->Data;
    return true;
}

template<class T>
bool DLL<T>::isEmpty()
{
    return first == NULL;
}

template<class T>
int DLL<T>::Search(T Element)
{
    Node<T>* p = first;
    int i = 1;
    while (p)
    {
        if (p->Data == Element)
        {
            return i;
        }
        p = p->Rptr;
        i++;
    }
    return -1;
}
template<class T>
void DLL<T>::Display()
{
    Node<T>* p = first;
    cout << "\nList in Forward Direction....\n";
    while (p)
    {
        cout << p->Data << "->";
        p = p->Rptr;
    }
    cout << "\n";
    Node<T>* q = last;
    cout << "\nList in Backward Direction....\n";
    while (q)
    {
        cout << q->Data << "->";
        q = q->Lptr;
    }
    cout << "\n";
}
template<class T>
void DLL<T>::Delete(int pos, T& Element)
{
    Node<T>* p = first, * q;
    if (len == 0)
    {
        cout << "\nList is EMPTY...";
        return;
    }
    if (pos == 1)
    {
        p = first;
        first = first->Rptr;
        first->Lptr = NULL;
        Element = p->Data;
        delete p;
    }
    else if (pos == len)
    {
        p = last;
        last = last->Lptr;
        last->Rptr = NULL;
        Element = p->Data;
        delete p;
    }
    else
    {
        for (int i = 1; i <= pos - 2; i++)
            p = p->Rptr;
        q = p->Rptr;
        q->Rptr->Lptr = p;
        p->Rptr = q->Rptr;
        Element = q->Data;
        delete q;
    }
    len--;

}
template<class T>
void DLL<T>::Insert(int pos, T Element)
{
    Node<T>* temp;
    temp = new Node<T>;
    temp->Data = Element;
    temp->Lptr = NULL;
    temp->Rptr = NULL;

    if (len == 0)
    {
        first = last = temp;
    }
    else
    {

        if (pos == 1)
        {
            temp->Rptr = first;
            first->Lptr = temp;
            first = temp;
        }
        else if (pos == len + 1)
        {
            temp->Lptr = last;
            last->Rptr = temp;
            last = temp;
        }
        else
        {
            Node<T>* p = first, * q;
            for (int i = 1; i <= pos - 2; i++)
                p = p->Rptr;
            q = p->Rptr;
            temp->Rptr = q;
            q->Lptr = temp;
            temp->Lptr = p;
            p->Rptr = temp;
        }
    }
    len++;
}
int main()
{
    DLL<int> D;
    int x;

    D.Insert(1, 100);
    D.Insert(2, 200);
    D.Insert(2, 300);
    D.Insert(3, 400);
    D.Insert(1, 500);
    D.Insert(6, 600);
    D.Display();
    D.Delete(4, x);
    cout << "\nElement Deleted is..." << x << endl;
    D.Display();
    if (D.Find(1, x))
        cout << "\nElement Found is...." << x << endl;
    if (D.isEmpty())
        cout << "\nList is EMPTY...\n";
    else
        cout << "\nList is NOT EMPTY...\n";
    x = D.Search(300);
    cout << "\nElement Found at " << x << " Position\n";
    cout << "\nThe Length of the List is..." << D.Length();
    return 0;
}
