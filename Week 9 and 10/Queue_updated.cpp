/// Implementing Queue ADT - Array Representation
#include<iostream>
using namespace std;
template <class T>
class Queue
{
private:
    T *Q;
    int Front, Rear, Size, len;
public:
    Queue(int);
    ~Queue(){ delete [] Q;}
    void EnQueue(T);
    void DeQueue(T&);
    bool Find(int, T&);
    int Search(T);
    bool isEmpty();
    bool isFull();
    int Length(){ return len;}
    void Display();
};
template <class T>
void Queue<T>::Display()
{
    for(int i=Front+1;i<=Rear;i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}
template <class T>
Queue<T>::Queue(int s)
{
    Size = s;
    Q = new T[Size];
    Front = Rear = -1;
    len = 0;
}

template <class T>
bool Queue<T>::isFull()
{
    return (Rear == Size - 1);
}
template <class T>
bool Queue<T>::isEmpty()
{
    return (Rear == Front);
}
template <class T>
void Queue<T>::EnQueue(T Element)
{
        if(isFull())
        {
            cout<<"\nQueue is FULL...";
            return;
        }
        Rear++;
        Q[Rear] = Element;
        len++;
}
template <class T>
void Queue<T>::DeQueue(T &Element)
{
        if(isEmpty())
        {
            cout<<"\nQueue is Empty...";
            return;
        }
        Front++;
        Element = Q[Front];
        len--;
}
template <class T>
bool Queue<T>::Find(int pos, T& Element)
{
    if(pos<1 || pos>len)
    {
        cout<<"\nInvalid Position....";
        return false;
    }
    Element = Q[Front + pos]; //Element = Q[Front + pos]; to correctly access 
    //elements relative to the front of the queue after dequeuing.
    return true;
}
template <class T>
int Queue<T>::Search(T Element)
{
    for(int i=Front + 1;i<=Rear;i++) 
    {
        if(Element == Q[i])
            return i - Front;
    }
    return -1;
}

int main()
{
    Queue<char> q(10);
    char x;
    char temp; 
    int pos;
    q.EnQueue('A');
    q.EnQueue('B');
    q.EnQueue('C');
    q.EnQueue('D');
    q.EnQueue('E');

    q.Display();

    q.DeQueue(x);
    cout<<"\nDeleted Element is ..."<<x <<endl;;
    q.Display();
    if(q.Find(9,x))
        cout<<"\nElement found is..."<<x;//after delete queue elements are 
        //front + 1 that means B,C,D,E
    pos=q.Search('E');
    if(pos != -1)
    cout<<"\nElement found at "<<pos<<" position.";
    else
    cout<<"\nElement Not Found";
}

