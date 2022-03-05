#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> q1)
{
    queue<int> newQueue = q1;
    cout << "Queue is \n";
    while (!newQueue.empty())
    {
        cout << "\t " << newQueue.front();
        newQueue.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> myq;
    myq.push(45);
    myq.push(67);
    myq.push(7);
    myq.push(712);
    myq.push(1);
    myq.push(47);

    cout << "Size of Queue is " << myq.size() << endl;
    printQueue(myq);

    myq.pop();
    printQueue(myq);
    cout << "Front of Queue is " << myq.front() << endl;
    cout << "Rear of Queue is " << myq.back() << endl;

    return 0;
}