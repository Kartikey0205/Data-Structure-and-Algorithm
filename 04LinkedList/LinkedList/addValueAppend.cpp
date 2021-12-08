#include <iostream>
using namespace std;

// Creating a Node which has 2 object - data and next
class Node
{
public:
    int data;
    Node *next;
};

// Append

void append(Node **head_ref, int new_value)
{
    Node *new_node = new Node();
    new_node->data = new_value;
    Node *last = *head_ref;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
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
    append(&head, 5);
    append(&head, 8);
    append(&head, 3);
    append(&head, 1);

    printLinkedList(head);
    return 0;
}