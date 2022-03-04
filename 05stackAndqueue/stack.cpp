#include <iostream>
#include <stack>

using namespace std;
void printStack(stack<int> s)
{
    cout << "Stack is " << endl;
    while (!s.empty())
    {
        cout << "\t" << s.top();
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(52);
    s.push(2);
    s.push(5289);
    s.push(289);
    s.push(9);
    s.push(24);
    s.push(97);
    cout << "\n Size of Stack is " << s.size() << endl;
    printStack(s);
    s.pop();
    printStack(s);

    return 0;
}