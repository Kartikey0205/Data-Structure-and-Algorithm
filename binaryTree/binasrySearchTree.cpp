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

// inOrder_Successor
Node *inOrder_Successor(Node *node)
{
    Node *newVal = node;
    while (newVal->left != NULL)
    {
        newVal = newVal->left;
    }
    return newVal;
}
//  Deletion ->
Node *
deleteNode(Node *root, int data)
{
    // Checking that root is not NUll
    if (root == NULL)
    {
        return root;
    }

    // Checking at which side data is
    if (data < root->key)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = deleteNode(root->right, data);
    }
    // data mil gya final now considering 3 cases simultaneously 0 node , 1 node , 2 node
    else
    {
        // 0 and 1 Node
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // 2 Node
        Node *temp = inOrder_Successor(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// preOrder
void preOrder(Node *node)
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