// C++ program to check if a tree is BST
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
// Function to find max value in the subtree
int maxValue(Node* node) {
    if (node == nullptr)
        return INT_MIN;
    return max({node->data, maxValue(node->left), maxValue(node->right)});
}

// Function to find min value in the subtree
int minValue(Node* node) {
    if (node == nullptr) // base case for recursion to return values (INT_MAX returns an empty value)
        return INT_MAX;     
    return min({node->data, minValue(node->left), minValue(node->right)}); // returns smallest value after checking original node, left subtree and right subtree
}

// Returns true if the binary tree is a BST
bool isBST(Node* node) {
    if (node == nullptr)
    {
        return true;
    }

    if(maxValue(node->left) >= node->data)
    {
        return false;
    }
    else if(minValue(node->right) <= node->data)
    {
        return false;
    }
    else
    {
        return isBST(node->left) && isBST(node->right);
    }
}

int main() {

    Node* root = nullptr;

    // EXAMPLE 1
    root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(5);

    // EXAMPLE 3
    // root = new Node(10);
    // root->left = new Node(5);
    // root->right = new Node(20);
    // root->right->left = new Node(9);
    // root->right->right = new Node(25);

    if (isBST(root)) 
    {
        cout << "True" << endl;
    }
    else 
    {
        cout << "False" << endl;
    }
    return 0;
}