#include <iostream>
using namespace std;

// Creating a Node which has 2 object - data and next
class Node
{
public:
    int data;
    Node *next;
};

// Pushing at very first
void push(Node **head_ref, int new_value)
{
    Node *new_node = new Node();
    new_node->data = new_value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Insert At
void insertAt(Node *prev_node, int new_value)
{
    if (prev_node == NULL)
    {
        cout << "Previous Node is NULL";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_value;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Printing LinkedList
void printLinkedList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
int main()
{
    // Always creating head to Null
    Node *head = NULL;
    push(&head, 5);
    printLinkedList(head);
    push(&head, 3);
    cout << endl;
    printLinkedList(head);

    insertAt(head, 8);
    // printLinkedList(head);
    insertAt(head, 1);
    cout << endl;
    printLinkedList(head);
    return 0;
}