/*
    Divide the array into two parts,
    Sort first half and second half via recursion,
    Merge the sorted parts.
    At every level, n points are being merged.
    height = log n
    time complexity => O(N * log(N))
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    private:
        void merge(int arr[], int left, int mid, int right)
        {
            int i = left, j = mid + 1, k = left;
            int ans[left + right];

            while (i <= mid and j <= right)
            {
                if (arr[i] > arr[j])
                {
                    ans[k] = arr[j];
                    j++;
                }

                else
                {
                    ans[k] = arr[i];
                    i++;
                }

                k++;
            }

            while (i <= mid)
            {
                ans[k] = arr[i];
                i++;
                k++;
            }

            while (j <= right)
            {
                ans[k] = arr[j];
                j++;
                k++;
            }

            for (int idx = left; idx <= right; idx++)
                arr[idx] = ans[idx];
        }

    private:

        void mergeSort(int arr[], int left, int right)
        {
            if (left < right)
            {
                int mid = (left + right) / 2;

                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                merge(arr, left, mid, right);
            }
        }
};

    void Merge(int *arr, int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = left;
        int* ans = new int[right - left];

        while (i <= mid and j <= right)
        {
            if (arr[i] > arr[j])
            {
                ans[k] = arr[j];
                j++;
            }

            else
            {
                ans[k] = arr[i];
                i++;
            }

            k++;
        }

        while (i <= mid)
        {
            ans[k] = arr[i];
            i++;
            k++;
        }

        while (j <= right)
        {
            ans[k] = arr[j];
            j++;
            k++;
        }

        for (int idx = left; idx <= right; idx++)
           arr[idx] = ans[idx];
}

void mergeSort(int *arr, int size, int left, int right)
{
    if(left == right) return;
    
    int mid = left + (right - left) / 2;

    mergeSort(arr, size, left, mid);
    mergeSort(arr, size, mid + 1, right);

    Merge(arr, left, mid, right);
}

void printArray(int *arr, int size)
{
    for (int idx = 0; idx < size; idx++)
        cout << arr[idx] << ' ';
}

int main()
{
    int size;

    cin >> size;

    int *arr = new int[size];

    for (int idx = 0; idx < size; idx++)
        cin >> arr[idx];

    mergeSort(arr, size, 0, size - 1);

    printArray(arr, size);

    return 0;
}