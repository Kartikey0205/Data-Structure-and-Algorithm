// Program to find sum of Fibonacci series
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
    int count, i = 0, sum = 0;
    cout << "Enter a positive value: ";
    cin >> count;

    while (i < count)
    {
        cout << " " << fib(i);
        sum += fib(i);
        i++;
    }
    cout << endl;
    cout << "Sum till last position is " << sum;
    return 0;
}