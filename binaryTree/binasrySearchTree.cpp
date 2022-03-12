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
        node = newNode(data);
        return node;
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
    return node;
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
Node *deleteNode(Node *root, int data)
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

// inOrder
void inOrder(Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
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
// postOrder
void postOrder(Node *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }
}
int main()
{
    Node *n = NULL;
    n = insert(n, 60);
    n = insert(n, 50);
    n = insert(n, 20);
    n = insert(n, 960);
    n = deleteNode(n, 50);
    n = insert(n, 4360);
    n = insert(n, 600);
    cout << "In Order Traversal of BST is " << endl;
    inOrder(n);
    cout << "\n pre Order Traversal of BST is " << endl;
    preOrder(n);
    cout << "\n postOOrder Traversal of BST is " << endl;
    postOrder(n);
    return 0;
}