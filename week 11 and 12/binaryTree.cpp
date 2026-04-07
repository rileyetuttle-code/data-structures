/// Binary Tree Class ADT
#include <iostream>
using namespace std;

template<class T>
class node {
public:
  T data;
  node<T> *left;
  node<T> *right;
};

template<class T>
class BinaryTree
{
public:
    node<T> *root;
    BinaryTree(){ root=NULL;}
    node<T> *newNode(T);
    void traverseInOrder(node<T> *);
    void traversePreOrder(node<T> *);
    void traversePostOrder(node<T> *);
    int Height(node<T> *);
};


template<class T>
node<T> * BinaryTree<T>::newNode(T data)
{
        root = new node<T>;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return (root);
}

template<class T>
void BinaryTree<T>::traverseInOrder(node<T> *temp)
{
  if (temp != NULL)
  {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}

template<class T>
void BinaryTree<T>::traversePreOrder( node<T> *temp)
{
  if (temp != NULL)
  {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

template<class T>
void BinaryTree<T>::traversePostOrder(node<T> *temp)
{
  if (temp != NULL)
  {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}


template<class T>
int BinaryTree<T>::Height(node<T> *p)
{
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return -1;
    }

    l = Height(p->left);
    r = Height(p->right);
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

int main()
{
  BinaryTree<char> b;
  node<char> *r = b.newNode('A');
  r->left = b.newNode('B');
  r->right = b.newNode('C');
  r->right->left = b.newNode('D');
  r->left->right = b.newNode('E');
  
  cout << "\nInorder traversal: ";
  b.traverseInOrder(r);

  cout << "\npreorder traversal: ";
  b.traversePreOrder(r);

  cout << "\nPostorder traversal: ";
  b.traversePostOrder(r);
  
  cout<<"\nHeight  : "<<b.Height(r);
}


