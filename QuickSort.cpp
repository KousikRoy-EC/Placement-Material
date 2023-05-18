#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(vector<int> &arr, int low, int high)
{
    int leftIndex = low - 1;
    int pivot = arr[high];

    for (int i = low; i <= high - 1; i++)
    {
        if (arr[i] < pivot)
        {
            leftIndex++;
            swap(&arr[leftIndex], &arr[i]);
        }
    }
    swap(&arr[leftIndex + 1], &arr[high]);

    return leftIndex+1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partionIndex = Partition(arr, low, high);

        quickSort(arr, low, partionIndex - 1);
        quickSort(arr, partionIndex + 1, high);
    }
}

void printArray(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {11, 12, 13, 5, 6, 43, 32, 9,79,43,11,23,50};
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);
    return 0;
}