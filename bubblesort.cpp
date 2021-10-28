/* 
   also known as sinking or exchange sort
   **swapping positions of two consecutive elements
   Best Case -> O(N)
   Worst Case -> O(N^2)
   taking length - idx as the last ones are being sorted in idx passes.
   we dont need to sort the last element as it will already get sorted thats why loop will commence from 0 to size - 1
   ***stable and unstable sorting 
   We can also take a bool variable and break the loop if the array is already sorted. 
*/

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int size, int *arr)
{
    for(int idx = 0; idx < size - 1; idx++)
    {
        for(int in = 1; in < size - idx; in++)
        {
            if(arr[in - 1] > arr[in])
            {
                int temp = arr[in];

                arr[in] = arr[in - 1];
                arr[in - 1] = temp;
            }
        }
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
 
    bubbleSort(size, arr);

    for(int idx = 0; idx < size; idx++){
        cout << arr[idx] << " ";
    }
  
    return 0;
}