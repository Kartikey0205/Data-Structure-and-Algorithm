// Program to find factorial of  a given number

#include <iostream>
using namespace std;
int myFact(int n);
int main()
{
    int n;
    cout << "Enter a positive value: ";
    cin >> n;
    cout << "Factorial is " << myFact(n);
    return 0;
}

int myFact(int n)
{
    if (n > 1)
    {
        return n * myFact(n - 1);
    }
    else
    {
        return 1;
    }
}