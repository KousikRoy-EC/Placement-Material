#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int size)
{

    int prevInd, Key;

    for (int i = 1; i < size; i++)
    {
        Key = arr[i];
        prevInd = i - 1;

        while (prevInd >= 0 && arr[prevInd] > Key)
        {
            arr[prevInd + 1] = arr[prevInd];
            prevInd--;
        }
        arr[prevInd + 1] = Key;
    }
}

void printArray(vector<int> &arr, int size)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {11, 12, 13, 5, 6};
    insertionSort(arr, arr.size());
    printArray(arr, arr.size());
    return 0;
}