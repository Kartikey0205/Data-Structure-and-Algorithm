// Print all fibonnacci series whose value is less than 100

#include <iostream>
using namespace std;
int fib(int num)
{
    if (num == 1 || num == 0)
    {
        return num;
    }
    else
    {
        return (fib(num - 1) + fib(num - 2));
    }
}

int main()
{
    int count, i = 0, store;
    cout << "Enter a positive value: ";
    cin >> count;

    while (i < count)
    {
        if (fib(i) < 100)
        {
            cout << " " << fib(i);
        }
        i++;
    }
    cout << endl;
    // cout << "All Fibonacci value below 100 is " << store;
    return 0;
}