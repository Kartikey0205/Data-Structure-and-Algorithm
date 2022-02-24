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

// Printing LinkedList
void printLinkedList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

Node *toCircular(Node *head)
{
    Node *start = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = start;
    return start;
}

// Printing Circular LinkedList
void printCircularList(Node *head)
{
    Node *temp = head;

    cout << "Circular Linked List will be " << endl;
    if (head != NULL)
    {

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    else
    {
        cout << " No value in Circular Linked List" << endl;
    }
}
int main()
{
    // Always creating head to Null
    Node *head = NULL;
    Node *headAfterCircular;
    push(&head, 5);
    // printLinkedList(head);
    push(&head, 3);
    push(&head, 1);
    push(&head, 6);

    printLinkedList(head);
    headAfterCircular = toCircular(head);
    cout << "\n";
    printCircularList(headAfterCircular);

    return 0;
}