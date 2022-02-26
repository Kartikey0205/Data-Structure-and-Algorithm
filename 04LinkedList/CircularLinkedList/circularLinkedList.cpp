#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
// Insertion Method
void push(int data, Node **head_ref)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;

    Node *temp = *head_ref;
    //  If node alrady exists
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else // first node is coming
    {
        new_node->next = new_node;
    }
    *head_ref = new_node;
}
//  Traverse Method
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

//  count a node in cuircular Linked list
int countNode(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *current = head;
    int count = 0;
    do
    {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

// Deleting a Node from Circular Linked List
void deleteNode(int element, Node **head_ref)
{
    //  Case -1 : if list is Empty
    if (*head_ref == NULL)
    {
        return;
    }
    // Case-2 : if list contain single node and that is Head only
    if ((*head_ref)->data == element && (*head_ref)->next == *head_ref)
    {
        free(*head_ref);
        *head_ref = NULL;
    }

    // Case-3 :Head node to be deleted and many element is present there
    Node *last = *head_ref, *d;
    if ((*head_ref)->data == element)
    {
        while (last->next != (*head_ref))
        {
            last = last->next;
        }
        last->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = last->next;
    }

    // Case-4: Regular Node to be deleted

    while (last->next != (*head_ref) && last->next->data != element)
    {
        last = last->next;
    }
    if (last->next->data == element)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    //  Case 5 : Node not found
    else
    {
        cout << "Node not Found";
    }
}
int main()
{

    Node *head = NULL;
    push(30, &head);
    push(20, &head);
    push(25, &head);
    printCircularList(head);
    cout << "\n";
    deleteNode(25, &head);
    printCircularList(head);

    cout << "\nTotal number of node in Circular Linked List will be =  " << countNode(head);
    return 0;
}