// Program to find Fibonacci series at specific position

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
    int count, i = 0, place, value;
    cout << "Enter a positive value: ";
    cin >> count;
    cout << "Enter the place ";
    cin >> place;

    while (i < count)
    {
        cout << " " << fib(i);
        if (i == (place - 1))
        {
            value = fib(i);
        }
        i++;
    }
    cout << endl;
    cout << "value at " << place << " is " << value;
    return 0;
}