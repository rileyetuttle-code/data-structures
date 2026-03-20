#include <iostream>
#include <stack>
using namespace std;
class MyStack
{
stack<int> s1;
stack<int> s2;
public:
void push(int val);
int pop();
int top();
int Size();
bool isEmpty();
int getMin();
};
void MyStack::push(int val)
{
    s1.push(val); // using stack library to just push to original stack

    if(s2.empty()) // for first push, check if minimum stack is empty and make the first push value the new and only minimum
    {
        s2.push(val);
    }
    else if (val <= s2.top()) // for the rest of pushes, compare push value to the current minimum(stack 2 top) and push if its smaller
    {
        s2.push(val);
    }
    
}
int MyStack::pop()
{
    int popVal = s1.top(); // set an int = to the current top which is about to be popped to be able to return at the end
    
    if(s1.top() == s2.top()) // check if stacks about to be popped value is the current minimum, if so pop the minimum stack too
                            // this will work even with duplicate pushes because of the val <= s2.top(), duplicate pushes also get pushed
                            // to the minimum stack too
    {
        s1.pop();
        s2.pop();
    }
    else    // if not, just pop in the original stack
    {
        s1.pop();
    }

    return popVal; // return the top of the original stack to show what is being popped or removed from the stack(s)
}
int MyStack::top()
{
    
    return s1.top();
}
int MyStack::Size()
{

    return s1.size();
}
bool MyStack::isEmpty()
{

    return s1.empty();
}
int MyStack::getMin()
{

    return s2.top();
}
int main(){
MyStack s;
s.push(10);
cout <<"Current Minimum is "<<s.getMin() << endl;
s.push(20);
cout <<"Current Minimum is "<< s.getMin() << endl;
s.push(25);
cout <<"Current Minimum is "<< s.getMin() << endl;
s.push(5);
cout <<"Current Minimum is "<< s.getMin() << endl;
s.push(6);
cout <<"Current Minimum is "<< s.getMin() << endl;
cout <<"Popped out "<< s.pop() << endl;
cout <<"Current Minimum is "<< s.getMin() << endl;
s.push(23);
cout <<"Current Minimum is "<< s.getMin() << endl;
cout <<"Popped out "<< s.pop() << endl;
cout <<"Current Minimum is "<< s.getMin() << endl;
cout <<"Popped out "<< s.pop() << endl;
cout <<"Current Minimum is "<< s.getMin() << endl;

return 0;
}