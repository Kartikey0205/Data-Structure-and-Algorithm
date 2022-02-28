#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
/*  Pushing element in very first--
        1- Head is Null
        2- Head has some list
*/
void pushElement(Node **head_ref, int data)
{
    Node *new_node = new Node();
    // if coming node is first node
    new_node->data = data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    //  If already have some node
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

// Insert element at Last

// Insert element at middle somewhere

//  Printing Doubly Linked List
void printDoublyLinkedList(Node *head_ref)
{
    while (head_ref != NULL)
    {
        cout << " " << head_ref->data << " ";
        head_ref = head_ref->next;
    }
}
int main()
{
    Node *head = NULL;
    pushElement(&head, 46);
    pushElement(&head, 66);
    pushElement(&head, 3);
    pushElement(&head, 7);

    printDoublyLinkedList(head);

    return 0;
}