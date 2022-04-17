// SELECTION SORT
/*
start from first index and choose smallest in right side and swap accordingly

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
// selection Sort LOGIC
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
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
    int arr[] = {5, 4, 3, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Selection Sort " << endl;
    printArray(arr, size);
    selectionSort(arr, size);
    cout << "\nAfter Selection Sort " << endl;

    printArray(arr, size);
    return 0;
}