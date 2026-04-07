#include <iostream>
#include <stack>
using namespace std;
class Queue
{
private:
    stack<int> s;
    public:
    void EnQueue(int);
    int DeQueue();
    void Display();
};

void Queue::EnQueue(int data)
{
    s.push(data);
}
// write the DeQueue function
int Queue::DeQueue()
{
    int x = s.top(); // set a variable for top to be able to return the dequeued front of queue or "last pop in the stack"
    s.pop(); // pop that will be used with recursion to pop all the way down the stack and store the values when it unwinds

    if(s.empty()) // base case that stops when the stack is popped and returns the final popped value
    {
        return x;
    }
    else // recursive case
    {
        int result = DeQueue(); // set the recursive function equal to a variable so that s.push() can run before a return, but after the recursion so that it pushes back up the winded stack values

        s.push(x); // pushes up the winded stack values after the recursion is over

        return result; // return statement that is used to pass the found x value back up through the unwinding recursive calls
    }

}

void Queue::Display()
{
    stack<int> temp = s;  // copy so we don't destroy the original

    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    int keys[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
    Queue q;

    for (int key: keys)
        q.EnQueue(key);

    q.Display();

    cout << q.DeQueue() << endl;
    cout << q.DeQueue() << endl;
    cout << q.DeQueue() << endl;

    q.Display();

    return 0;
}