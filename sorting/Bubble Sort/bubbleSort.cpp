// BUBBLE SORT
/*
start from first index and compare adjacent value, if right side is smaller then swap otherwise move next index and  in right hand side we wil get biggets value automatically

*/
#include <iostream>
using namespace std;
// swap Method
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// bubble sort
void bubbleSort(int arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
// printing Array
void printArray(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {40, 20, 50, 60, 30, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Bubble Sort " << endl;
    printArray(arr, size);
    bubbleSort(arr, size);
    cout << "\nAfter Bubble Sort " << endl;

    printArray(arr, size);
    return 0;
}