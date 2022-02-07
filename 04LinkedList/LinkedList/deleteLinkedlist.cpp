

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

//  Deleting a node of linked list
void deleteElementInLinkedList(Node **head_ref, int element)
{
    Node *temp = (*head_ref); // temp store the actual where head is pointing
    Node *prev;               // just making a prev  of Node type so that it can hold previous Node

    // Case 1 ->>   if element which has to be deleted is very first Element
    if ((temp != NULL) && (temp->data == element))
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Case 2 ->>   Element has to be deleted is head itself means no linked list exists

    if (temp == NULL)
    {
        cout << "No value in Linked list" << endl;
        return;
    }

    // Case 3 ->>   Element is somewhere in between linked list and we want to delete that particular element
    while ((temp != NULL) && (temp->data != element))
    {
        prev = temp;
        temp = temp->next;
    }

    // // case 4 ->>  last node to be deleted
    // while ((temp->next != NULL))
    // {
    //     prev = temp;
    //     temp = temp->next;
    //     if (temp == NULL)
    //     {
    //         free(temp);
    //         prev->next = NULL;
    //     }
    // }
    prev->next = temp->next;
    free(temp);
}

// DELETEING LINKED LIST COMPLETELY
void deleteLinkedListCompletely(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
    cout << "All nodes are deleted succesfully" << endl;
}
int main()
{
    // Always creating head to Null
    Node *head = NULL;
    push(&head, 5);
    // printLinkedList(head);
    push(&head, 3);
    push(&head, 1);
    push(&head, 6);
    deleteElementInLinkedList(&head, 6);
    deleteLinkedListCompletely(&head);
    printLinkedList(head);
    return 0;
}
