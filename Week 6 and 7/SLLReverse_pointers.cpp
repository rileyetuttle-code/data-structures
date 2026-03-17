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

        ~Chain()
        {
                Node<T> *temp=first;
                while(first!=NULL)
                {
                        first=first->link;
                        delete temp;
                        temp=first;
                }
        }
        void Insert(int pos,T x);
        void Delete(int pos,T &x);
        void Display();
        void Reverse();
        void ReverseByRearrange();
};

template<class T>
void Chain<T>::ReverseByRearrange()
{
    Node<T> *r=NULL, *p, *q=NULL;
    p =first;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;

}
template<class T>
void Chain<T>::Reverse()
{
    Node<T> *p = first, *q=first;
    T *temp;
    int i=0;
    temp = new T[len];
    while(p != NULL)
    {
        temp[i] = p->data;
        p = p->link;
        i++;
    }
    i--;
    while(q != NULL)
    {
        q->data = temp[i];
        i--;
        q = q->link;
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
		Chain<int> C;

		C.Insert(1,10);
		C.Insert(2,20);
		C.Insert(3,30);
		C.Insert(4,40);
		C.Insert(5,50);

     	C.Display();
     	cout<<"\nAfter Reversing the Linked List...\n";
     	C.Reverse();
     	C.Display();

        return 0;
}



