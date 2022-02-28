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
void insertLast(Node **head_ref, int data)
{
    Node *last = *head_ref;
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    // If coming node is first node
    if ((*head_ref) == NULL)
    {
        new_node->prev = NULL;
        (*head_ref) = new_node;
        return;
    }

    // If head is not NULL taht means already have a list
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last; // THIS IS VERY IMPORTANT CONCEPT OF ADDING PREVIOUS VALUE FOR NEW NODE
    return;
}

// Insert element at middle somewhere
void middleInsert(Node **head_ref, int data, int index)
{
    Node *prev_node = (*head_ref);
    // previous node find kr liye
    for (int i = 0; i < index; i++)
    {
        prev_node = prev_node->next;
    }

    // Making new node
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    // Still new node k next k prev k arrow remaing so  VERY VERY VERY IMPORTANT PART
    /*
     2 CASES -
            - NEW NODE WHICH IS ENTERED ITS LAST MEANS IT'S NEXT HAS NULL AND
            - IT HAS NOT NULL
    */

    // if nULL then no woorry because we had return each thing acording to it

    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

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
    insertLast(&head, 999);
    insertLast(&head, 1999);
    pushElement(&head, 17);
    middleInsert(&head, 4555, 2);
    middleInsert(&head, 12345, 6);

    printDoublyLinkedList(head);

    return 0;
}