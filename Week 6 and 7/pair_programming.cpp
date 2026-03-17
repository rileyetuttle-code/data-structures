
#include <iostream>
using namespace std;

class Node {
public:
int data;
Node* next;
Node* prev;
Node(int val) {
data = val;
next = nullptr;
prev = nullptr;
}
};

//Write the function to remove duplicates
Node* removeDuplicates(Node* head)
{
    Node* comp = head; // node that we will leave in place to compare against when iterating through list
    Node* p = head; // node that will iterate through list to compare to the *comp node 

    while(comp->next != nullptr) // outside loop that iterates through the comp node and resets the p node to comp node 
    {
        while(p->next != nullptr) // inside loop that iterates through p node and checks if any p node equals the current comp node
        {
            p = p->next;

            if (p->data == comp->data) // if statement if p node is a duplicate of comp node
            {
                p->next->prev = p->prev; // left pointer on node in front changed to address of previous node
                p->prev->next = p->next; // right pointer on node behind changed to address of next node after p

                Node* temp = p->next; // temp node assigned p->next so that p can be reset and stay "alive" when it is deleted
                
                delete p; 

                p = temp; // reset p to the next node that temp was
            }

        }

        comp = comp->next; 
        p = comp; // start p where comp node is at the end of the loop so the next loop they start at the same place in the list and go through
    }

    return head;
}

void printList(Node* head) {
Node* curr = head;
while (curr != nullptr) {
cout << curr->data << " ";
curr = curr->next;
}
cout << endl;
}

int main() {
// Create a doubly linked list:
// 10 <-> 20 <-> 30 <-> 20 <-> 40
Node* head = new Node(10);
head->next = new Node(20);
head->next->prev = head;
head->next->next = new Node(30);
head->next->next->prev = head->next;
head->next->next->next = new Node(20);
head->next->next->next->prev = head->next->next;
head->next->next->next->next = new Node(40);
head->next->next->next->next->prev = head->next->next->next;
head = removeDuplicates(head); 
printList(head);
return 0;
}