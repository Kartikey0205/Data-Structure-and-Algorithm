#include <iostream>
using namespace std;
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}

int combi(int n, int r)
{
    return (fact(n) / (fact(r) * fact(n - r)));
}
int main()
{
    int n, r;
    cout << "Enter the total number ";
    cin >> n;

    cout << "Enter the combination you want ";
    cin >> r;

    cout << "Combination is " << combi(n, r);
    return 0;
}