// Program to calculate power of given number
#include <iostream>
using namespace std;
int powerCal(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    else
    {
        return (powerCal(base, pow - 1) * base);
    }
}
int main()
{
    int base, power;
    cout << "Enter the base value: ";
    cin >> base;
    cout << "Enter the power: ";
    cin >> power;

    cout << base << " to the power " << power << " is " << powerCal(base, power);
    return 0;
}