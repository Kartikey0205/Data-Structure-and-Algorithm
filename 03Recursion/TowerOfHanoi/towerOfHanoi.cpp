#include <iostream>
using namespace std;

void toh(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move Disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }

    toh(n - 1, from_rod, aux_rod, to_rod);

    cout << "Move Disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    toh(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{

    int disk;
    cout << "Enter the total number of Disk ";
    cin >> disk;
    toh(disk, 'A', 'C', 'B');
    return 0;
}

/*
                                    T(3, A C B)


        T(2 , A B C)                3-> A->C                T(2 , B C A)

T(1,A C B)  2-> A-> B  T(1,C B A)                   T(1,B A C)  2-> B-> C  T(1,A C B)


1 -> A -> C             1-> C -> B                   1-> B->A                 1-> A->C



*/