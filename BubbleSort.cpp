#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int>arr={23, 54, 2, 32, 1, 65, 7, 9, 0, 12};
    int size = arr.size();
    bubbleSort(arr, size);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}