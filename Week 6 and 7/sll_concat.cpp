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
class Chain
{
        private:
            int    len;
            Node<T> *first,*last;
        public:
        Chain()
        {
                first=last=NULL;
                len=0;
        }

       //  ~Chain()
//         {
//                 Node<T> *temp=first;
//                 while(first!=NULL)
//                 {
//                         first=first->link;
//                         delete temp;
//                         temp=first;
//                 }
//         }
        void Insert(int pos,T x);
        void Delete(int pos,T &x);
        void Display();
        void Concat(Chain<T> *a,Chain<T> *b);
};

template<class T>
void Chain<T>::Concat(Chain<T> *a,Chain<T> *b)
{
    Node<T> *f, *s;
    f = a->first;
    s = b->first;
    Node<T> *p = s;
    while(p->link)
    {
        p = p->link;
    }
    p->link = f;
    f = NULL;

    cout << "\n\nConcatenated List..\n";
    Node<T> *temp = s;
    while(temp != NULL)
    {
            cout << temp->data << "->";
            temp = temp->link;
    }
}

template<class T>
void Chain<T>::Display()
{
        Node<T> *temp=first;
        while(temp!=NULL)
        {
                cout<<temp->data<<"->";
                temp=temp->link;
        }
}
template<class T>
void Chain<T>::Insert(int pos,T x)
{
        Node<T> *temp;
        temp=new Node<T>;
        temp->data=x;
        temp->link=NULL;
        if(len==0)
        {
                first=last=temp;
        }
        else
        {
                if(pos==1)
                {
                        temp->link=first;
                        first=temp;
                }
                else if(pos==len+1)
                {
                        last->link=temp;
                        last=temp;
                }
                else
                {
                        Node<T> *p=first;
                        for(int i=0;i<pos-1;i++)
                                p=p->link;
                        temp->link=p->link;
                        p->link=temp;
                }
        }
        len++;
}
template<class T>
void Chain<T>::Delete(int pos,T &x)
{
        Node<T> *p,*q;
        p=q=first;
        if(len==0)
            throw "list empty";
        if(pos==1)
        	first=first->link;
        else if(pos==len)
        {
                for(int i=0;i<pos-2;i++)
                        p=p->link;
                p->link=NULL;
                last=p;
	}
	else
	{
		for(int i=0;i<pos-2;i++)
			p=p->link;
		q=p->link;
		p->link=q->link;
	}
	x=q->data;
	delete q;
	len--;
}


int main()
{
		Chain<int> a,b,c;

		a.Insert(1,1);
		a.Insert(2,15);
		a.Insert(3,40);
		a.Insert(4,45);
        cout<<"First Linked List..\n";
		a.Display();

        b.Insert(1,5);
		b.Insert(2,14);
		b.Insert(3,30);
		cout<<"\n\nSecond Linked List..\n";
		b.Display();

		c.Concat(&a,&b);

        return 0;
}



