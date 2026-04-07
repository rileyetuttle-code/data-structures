/// Queue using Linked List
#include<iostream>
using namespace std;
template<class T>
class Node
{
	public:
		T data;
		Node<T> *link;
};
template<class T>
class LQ
{
	private:
		Node<T> *front,*rear;
		int size;
	public:
		LQ()
		{
			front=rear=NULL;
			size=0;
			
		}
		~LQ();
		void EnQueue(T x);
		void DeQueue(T &x);
		void Display();
		bool Find(int, T&);
        int Search(T);
        bool isEmpty();
};

// Destructor definition
template<class T>
LQ<T>::~LQ() {
    Node<T>* temp;
    while (front != nullptr) {
        temp = front;
        front = front->link;
        delete temp;
    }
    rear = nullptr;
    size = 0;
    cout << "\nQueue destroyed successfully.\n";  
}

template<class T>
void LQ<T> :: EnQueue(T x)
{
	Node<T> *temp=new Node<T>;
	temp->data=x;
	temp->link=NULL;

	if(size==0)
	{
		front=rear=temp;
	}
	else
	{
		rear->link=temp;
		rear=temp;
	}
	size++;
}

template<class T>
void LQ<T> :: DeQueue(T &x)
{
	if(size==0)
		cout<<"\nQueue is empty";
	Node<T> *q=front;
	front=front->link;
	x=q->data;
	delete q;
	size--;
}
template<class T>
void LQ<T>:: Display()
{
	Node<T> *p=front;
	while(p!=NULL)
	{
		cout<<p->data<<" -> ";
		p=p->link;
	}
}


template<class T>
bool LQ<T>::Find(int pos, T &Element)
{   Node<T> *p=front;
    if(pos < 1 || pos>size)
    {
        cout<<"Invalid Position....";
        return false;
    }
    
    for(int i=1;i<pos;i++)
        p=p->link;
    Element = p->data;
    return true;
}


template <class T>
int LQ<T>::Search(T Element)
{   Node<T> *p=front;
    for(int i=1;p!=NULL;i++)
    {
        if(p->data == Element)
            return i;
        p = p->link;
    }
    return -1;
}

template<class T>
bool LQ<T>::isEmpty()
{
    return (rear == front);
}
// template<class T>
// // bool LQ<T>::isFull()
// // {
// //      return false;
// // }
int main()
{
		int x;
		LQ<int> q;
		q.EnQueue(10);
		q.EnQueue(20);
		q.EnQueue(30);
		q.EnQueue(40);
		q.EnQueue(50);
		q.EnQueue(60);
		q.Display();
		if(q.Find(2,x))
        cout<<"\nElement found is..."<<x<<endl;
		q.DeQueue(x);
		cout<<"The deleted Element is.... "<<x<<endl;
		cout<<"The Queue after Deletion is... \n";
		q.Display();
		x=q.Search(60);
        if(x != -1)
        cout<<"\nElement found at "<<x<<" position.";
        else
        cout<<"\nElement Not Found";
        if (q.isEmpty())
        cout<<"\nQueue is empty.....";
        else
        cout<< "\nQueue is not empty.....";
        return 0;

}















































