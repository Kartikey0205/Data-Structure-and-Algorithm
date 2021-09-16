// Program to find sum of Fibonacci series upto given specific number

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
    int count, i = 0, sum = 0, place;
    cout << "Enter a positive value: ";
    cin >> count;
    cout << "Enter the place ";
    cin >> place;

    while (i < count)
    {
        cout << " " << fib(i);
        if (i < place)
        {
            sum += fib(i);
        }

        i++;
    }
    cout << endl;
    cout << "Sum till  position " << place << " is " << sum;
    return 0;
}