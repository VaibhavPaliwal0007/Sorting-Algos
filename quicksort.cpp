/*
    -> Taking a pivot(you can take any),
       and insert that pivot into its correct position i.e, 
    -> LHS of pivot < pivot and RHS of pivot > pivot
    -> An unstable algorithm as the complexity mainly depends on the situation of pivot. 
    -> In worst case, it can be O(n^2)
    -> Best case, it can be O(n log n)
    -> Merge sort is better in memory allocation 
       and it is stable
*/

#include<bits/stdc++.h>
using namespace std;

void quickSort(int* arr, int size, int left, int right)
{
    if(left >= right) return;

    int start = left, end = right;

    int pivot = arr[left + (right - left) / 2];

    while(start <= end)
    {
        while(arr[start] < pivot) start++;
        while(arr[end] > pivot) end--;

        if(start <= end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    //as the pivot has been inserted in the correct position now calling for the other two partitions
    //left partition and right partition i.e, from left to end and start to right.

    quickSort(arr, size, left, end);
    quickSort(arr, size, start, right);
}

void printArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size; 

    cin >> size;

    int* arr = new int[size];

    for(int idx = 0; idx < size; idx++)
        cin >> arr[idx];

    quickSort(arr, size, 0, size - 1);
    printArray(arr, size);

    return 0;
}