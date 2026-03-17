#include<iostream>
using namespace std;
template<class T>
class stack
{
private:
	T *s;
	int capacity;
	int size;
	int top;
public:
	stack(int cap);
	~stack(){delete[] s;}
	bool isEmpty();
	bool isFull();
	void push(T x);
	void pop(T &x);
	T TopElement();
	void display();
	int search(T x);
};
template<class T>
T stack<T>::TopElement()
{
	return s[top];
}
template<class T>
stack<T>::stack(int cap)
{
	if(cap<=0)throw "invalid capacity";
	capacity=cap;
	top=-1;
	size=0;
	s=new T[capacity];
}
template<class T>
bool stack<T>::isEmpty()
{
	return top==-1;
}
template<class T>
bool stack<T>::isFull()
{
	return top==capacity-1;
}
template<class T>
void stack<T>::push(T x)
{
	if(isFull())
	{
		cout<<"Stack is Full.";
		return;
	}
	s[++top]=x;
	size++;
}
template<class T>
void stack<T>::pop(T &x)
{
	if(isEmpty())
	{
	    cout<<"\nStack is Empty...";
	    return;
	}
	x=s[top];
	s[top--]; //.~T();
	size--;
}
template<class T>
void stack<T>::display()
{
	cout<<"\nThe elements in the stack are: \n";
	for(int i=0;i<=top;i++)
	cout<<s[i]<<"\t";
}
template<class T>
int stack<T>::search(T x)
{
	int i;
	for(i=0;i<=top;i++)
	{
		if(x==s[i])
		{
		return i+1;

		}
	}
	return -1;
}
int main()

{
	int x;
	int key;
	stack<int> s1(10);
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.display();
	cout<<"\nThe topmost element\n"<<s1.TopElement();
	if(s1.isFull())
	cout<<"\nstack is full\n";
	else
	cout<<"\nstack is not full\n";
	s1.pop(x);
	cout<<"\nThe Popped Element is\n"<<x;
	cout<<"\nAfter Pop\n";
	s1.display();
	cout<<"\nEnter a value to search in stack\n";
	cin>>key;
	cout<<"\nThe key "<<key<<" found at "<<s1.search(key);

}





