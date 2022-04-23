#include <iostream>
using namespace std;

// Insertion Sort

void insertionSort(int arr[], int n)
{
    int i, j, val;
    // phase 0 thats why i = 1
    for (i = 1; i < n; i++)
    {
        val = arr[i];
        j = i - 1;
        // phase 1
        while (j >= 0 && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // condition for moving in phase 2
        arr[j + 1] = val;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int size;
    cout << "Enter the size of Array" << endl;
    cin >> size;
    int arr[size];
    // int size = sizeof(arr) / sizeof(arr[0]);
    cout << " Enter the elements of Array " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Before Insertion Sort " << endl;
    printArray(arr, size);
    insertionSort(arr, size);
    cout << "\nAfter Insertion Sort " << endl;
    printArray(arr, size);
    return 0;
}