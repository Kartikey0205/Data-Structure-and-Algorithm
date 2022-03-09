#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
// Creating BST
Node *newNode(int data)
{
    // struct node *temp = (struct node *)malloc(sizeof(struct node));
    Node *temp = new Node();
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Inserting Data in BST
Node *insert(Node *node, int data)
{
    // if very first node or last node
    if (node == NULL)
    {
        return newNode(data);
    }

    // rest inserting value in left and right
    if (data < node->key)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
}

// preOrder

int preOrder(Node *node)
{
    if (node != NULL)
    {
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
int main()
{

    return 0;
}