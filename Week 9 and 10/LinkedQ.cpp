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
		~LQ(){}
		void EnQueue(T x);
		void DeQueue(T &x);
		void Display();
};
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
		q.DeQueue(x);
		cout<<"\n The deleted Elemen is.... "<<x<<"\n";
		cout<<"\n The Queue after Deletion is... \n";
		q.Display();
        return 0;

}













































