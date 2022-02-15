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
int main()
{

    Node *head = NULL;
    push(30, &head);
    push(20, &head);
    push(25, &head);
    printCircularList(head);
    return 0;
}