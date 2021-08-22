
// In c++
#include <iostream>
using namespace std;

int main()
{
    string orginalString, reverseString;
    cout << "Enter the string ";
    cin >> orginalString;

    for (int i = orginalString.length(); i >= 0; i--)
    {
        reverseString = reverseString + orginalString[i];
    }
    cout << "Reverse String is " << reverseString;
    return 0;
}
