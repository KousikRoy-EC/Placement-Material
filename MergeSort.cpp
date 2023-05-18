#include <iostream>
using namespace std;

void merge(int arr[], int beg, int mid, int end)
{

    int sizeofFirstArray = mid - beg + 1;
    int sizeofSecArray = end - mid;

    int tempArray1[sizeofFirstArray];
    int tempArray2[sizeofSecArray];

    for (int i = 0; i < sizeofFirstArray; i++)
    {
        tempArray1[i] = arr[beg + i];
    }

    for (int j = 0; j < sizeofSecArray; j++)
    {
        tempArray2[j] = arr[mid + 1 + j];
    }

    int startingInd1 = 0;
    int startingInd2 = 0;
    int startingIndMergedArray = beg;

    while (startingInd1 < sizeofFirstArray && startingInd2 < sizeofSecArray)
    {
        if (tempArray1[startingInd1] >= tempArray2[startingInd2])
        {
            arr[startingIndMergedArray] = tempArray2[startingInd2];
            startingInd2++;
        }
        else
        {
            arr[startingIndMergedArray] = tempArray1[startingInd1];
            startingInd1++;
        }
        startingIndMergedArray++;
    }

    while (startingInd1 < sizeofFirstArray)
    {
        arr[startingIndMergedArray] = tempArray1[startingInd1];
        startingInd1++;
        startingIndMergedArray++;
    }

    while (startingInd2 < sizeofSecArray)
    {
        arr[startingIndMergedArray] = tempArray2[startingInd2];
        startingInd2++;
        startingIndMergedArray++;
    }
}

void mergeSort(int arr[], int beg, int end)
{
    if (beg>=end)
    {
       return;
    }
    
    int mid = beg + (end - beg) / 2;
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
}

int main()
{
    int arr[] = {23, 54, 2, 32, 1, 65, 7, 9, 0, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}