#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        this->left = this->right = nullptr;
    };
};

Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node();
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
};

void takeInput(Node *&root)
{
    int data;
    cout << "Enter data: " << endl;
    while (data != -1)
    {
        cin >> data;
        insertIntoBST(root, data);
    }
}

int main()
{
    Node *root = nullptr;
    takeInput(root);
    return 0;
}