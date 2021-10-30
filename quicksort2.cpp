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

#include<iostream>
using namespace std;

int main()
{
    int size;
    
    cin >> size;

    int arr[size];

    for(int i=0; i<size; i++)
        cin >> arr[i];

    int l = 0, r = size-1;
    int pivot = arr[size/2];

    while(l <= r)
    {
        while(arr[l] < pivot)
        {
            l++;
        }

        while(arr[r] > pivot)
        {
            r--;
        }

        if(l <= r)
        {
            int temp = arr[l];

            arr[l] = arr[r];
            arr[r] = temp;

            l++;
            r--;
        }
    }

    return 0;
}