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
   //Write the destructor function

	Node<T>* temp; // temp pointer to list to be able to delete elements in the list

    // while loop that iterates through list deleting the front element and moving front up a spot
    while (front != nullptr) 
    {
        temp = front;
        front = front->link;
        delete temp;
    }

    // reset rear and size because of the new empty list
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
{     
    //Write the Find function
    Node<T> *p=front;

    // error checking for input position
    if(pos < 1 || pos>size)
    {
        cout<<"Invalid Position....";
        return false;
    }

    // for loop that iterates through list and stops at input position
    for(int i=1; i < pos; i++)
    {
        p=p->link;
    }

    // set element to input position data to be able to show user the value and return true for successful find
    Element = p->data;
    return true;

}


template <class T>
int LQ<T>::Search(T Element)
{     
    //Write the search function

    Node<T> *p=front;

    // for loop that iterates through list until null and keeps track of position in list
    for(int pos = 1; p != NULL; pos++)
    {
        // if statement to catch when list data equals input element and then returns position
        if(p->data == Element)
        {
            return pos;
        }

        // iterate through list via p pointer
        p = p->link;
    }

    // in case of a fail or unsuccessful search, return -1 to shutdown search
    return -1;

}

template<class T>
bool LQ<T>::isEmpty()
{
       //Write the isEmpty function

       // if statement to check if front of list is NULL and if so, list is empty, if not, list has at least one element or more so 
       // it returns false and is not empty
       if(front == NULL)
            return true;
       else
            return false;

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











