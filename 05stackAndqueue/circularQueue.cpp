/*
35  25  12  41  19  47  75  96  74
 0   1  2   3   4   5   6   7   8
 F                              R
        R   F
 queue is full in 2 cases -
    when
        REAR is just behind the FRONT
        FRONT is at first and REAR is at last

(rear+1) % size == front
(front == 0&&rear == size-1) || (rear == (front-1)%(size-1))
*/

#include <iostream>
using namespace std;

// STRUCTURE OF QUEUE
struct circularQueue
{
    int rear, front;
    int size;
    int *arr;
    circularQueue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[s];
    }
    void enQueue(int data);
    int deQueue();
    void printCircularQueue();
};

void circularQueue ::enQueue(int data)
{
    cout << "Adding data = " << data << " in a queue " << endl;
    // FULL Queue
    if (((front == 0) && (rear == size - 1)) || (rear == (front - 1) % (size - 1)))
    {
        cout << "Queue is full" << endl;

        return;
    }
    else if (front == -1) // very first value
    {
        front = 0;
        rear = 0;
        arr[rear] = data;
    }
    else if ((rear == size - 1) && (front != 0)) // moving back again to front
    {
        rear = 0;
        arr[rear] = data;
    }
    else // all other cases
    {
        rear++;
        arr[rear] = data;
    }
}

int circularQueue ::deQueue()
{
    // Queue is Empty
    if (front == -1)
    {
        cout << "Queue is empty " << endl;
        return -1;
    }
    int data = arr[front];
    arr[front] = -1;
    // only one element is there in Queue
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1) // last element is deleted
    {
        front = 0;
    }
    else // alll other cases
    {
        front++;
    }
    return data;
}

void circularQueue::printCircularQueue()
{
    cout << "\nCircular Queue is" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    circularQueue myQueue(5);
    myQueue.enQueue(25);
    myQueue.enQueue(47);
    myQueue.enQueue(57);
    myQueue.enQueue(7);
    myQueue.printCircularQueue();
    cout << "\nData deleted is " << myQueue.deQueue() << endl;
    myQueue.printCircularQueue();
    myQueue.enQueue(97);

    myQueue.enQueue(74);

    myQueue.enQueue(17);
    myQueue.printCircularQueue();
    cout << "\nData deleted is " << myQueue.deQueue() << endl;

    cout << "\nData deleted is " << myQueue.deQueue() << endl;
    cout << "\nData deleted is " << myQueue.deQueue() << endl;
    cout << "\nData deleted is " << myQueue.deQueue() << endl;
    myQueue.printCircularQueue();
    myQueue.enQueue(27);
    myQueue.printCircularQueue();

    myQueue.enQueue(457);
    myQueue.enQueue(573);
    myQueue.enQueue(7489);
    myQueue.enQueue(89);

    myQueue.printCircularQueue();

    return 0;
}