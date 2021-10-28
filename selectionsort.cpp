/*
    **finding max element or min element and swapping it into the first or last. 
    Also smalling the size of array
    Worst Case -> O(N^2)
    Best Case -> O(N^2)
    performs well on small size
*/

#include<bits/stdc++.h>
using namespace std;

int getMax(int* arr, int start, int last)
{
    int maxElement = start;

    for(int idx = start; idx <= last; idx++){
       if(arr[idx] > arr[maxElement]){
           maxElement = idx;
       }
    }

    return maxElement;
}

void selectionSort(int size, int* arr)
{
    for(int idx = 0; idx < size; idx++)
    {
        int lastIdx = size - idx - 1;
        int maxIdx = getMax(arr, 0, lastIdx);

        swap(arr[maxIdx], arr[lastIdx]);
    }
}

int main()
{
    int size;

    cin >> size;

    int* arr = new int[size];

    for(int idx = 0; idx < size; idx++){
        cin >> arr[idx];
    }
 
    selectionSort(size, arr);

    for(int idx = 0; idx < size; idx++){
        cout << arr[idx] << " ";
    }
  
    return 0;
}