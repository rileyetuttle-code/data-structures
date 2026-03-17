#include <iostream>
using namespace std;

class Node
{
public:
int data;
Node* next;
};
void Insert(Node*& headRef, int data)
{
Node* newNode = new Node;
newNode->data = data;
newNode->next = headRef;
headRef = newNode;
}

// write detectCycle function
bool detectCycle(Node* headRef)
{
    // initialize slow and fast nodes to head ref and then starting position
    Node* s = headRef;
    Node* f = headRef;

    // loop that iterates through list using slow and fast pointer to either find end of the list or a loop if 
    // the fast pointer = the slow pointer to return true or false respectively
    while(f != nullptr && f->next != nullptr)
    {
        s = s->next;
        f = f->next->next;

        if (f == s)
        {
            return true;
        }
    }

    return false;
}


int main()
{
int keys[] = { 10, 12, 45, 66, 75 };
int n = 5;
Node* head = nullptr;
for (int i = n - 1; i >= 0; i--)
Insert(head, keys[i]);

head->next->next->next->next->next = NULL;

// //create a loop for testing to detect cycle
// head->next->next->next->next->next = head->next->next;

if (detectCycle(head))
cout << "\nYes There is Cycle Exists";
else
cout << "\nNo Cycle in Linked List Found";
return 0;
}