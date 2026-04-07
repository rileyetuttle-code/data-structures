/// Binary Search Tree - Search(), Insert() and Delete()

#include <iostream>
using namespace std;

class Node
{
public:
    Node* left;
    int data;
    Node* right;
};

class BST
{
private:
    Node* root;
public:
    BST(){ root = NULL; }
    Node* GetRootElement(){ return root; }
    void Insert(int key);
    void Inorder(Node* p);
    Node* Search(int key);
    Node* Delete(Node* p, int key);
    Node* InOrderPred(Node* p);
    Node* InOrderSucc(Node* p);
    int Height(Node* p);
};

void BST::Insert(int key)
{
    Node* t = root;
    Node* p;
    Node* r = NULL;

    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->left = NULL;
        p->right = NULL;
        root = p;
        return;
    }

    while(t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->left;
        else if (key > t->data)
            t = t->right;
        else
            return;
    }

    p = new Node;
    p->data = key;
    p->left = NULL;
    p->right = NULL;

    if (key < r->data)
        r->left = p;
    else
        r->right = p;
}

void BST::Inorder(Node* p)
{
    if (p != NULL)
    {
        Inorder(p->left);
        cout << p->data << ", " << flush;
        Inorder(p->right);
    }
}

Node* BST::Search(int key)
{
    Node* t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}

Node* BST::Delete(Node *p, int key)
{
    Node* q;

    if (p == NULL)
    {
        return NULL;
    }

    if (p->left == NULL && p->right == NULL && p->data == key)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if (key < p->data)
    {
        p->left = Delete(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = Delete(p->right, key);
    }
    else
     {
        if (Height(p->left) > Height(p->right))
        {
            q = InOrderPred(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            q = InOrderSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
}

Node* BST::InOrderPred(Node *p)
{
    while (p && p->right != NULL)
    {
        p = p->right;
    }
    return p;
}

Node* BST::InOrderSucc(Node *p)
{
    while (p && p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

int BST::Height(Node *p)
{
    int l, r;
    if (p == NULL){
        return -1;
    }
    l = Height(p->left);
    r = Height(p->right);
    if( l > r)
        return (l+1);
    else
        return (r+1);
}

int main()
{
    BST b;

    b.Insert(30);
    b.Insert(50);
    b.Insert(40);
    b.Insert(10);
    b.Insert(20);
    b.Insert(70);

    b.Inorder(b.GetRootElement());
    cout << endl;

    b.Delete(b.GetRootElement(), 30);
    b.Inorder(b.GetRootElement());

    Node* temp = b.Search(40);
    if (temp != NULL)
        cout << temp->data << endl;
    else
        cout << "\nElement not found" << endl;

    cout<<"\nThe Height of BST is..."<<b.Height(b.GetRootElement());
    return 0;
}