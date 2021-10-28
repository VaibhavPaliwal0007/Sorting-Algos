/*
     When numbers are given in 1 TO N, Cyclic Sort is used!! 
     As After sorting, index of a given no will be value - 1

     for(1 -> N) range
     Worst Case -> O(N)
     Best Case -> O(N) 
*/

#include<bits/stdc++.h>
using namespace std;

void cyclicSort(int* arr, int size)
{
    int idx = 0;

    while(idx < size)  //for(0 -> N, no -1 would be there )
    {
        int correctPos = arr[idx] - 1;       //correct position of arr[idx] => its index + 1, thereby placing it to its correct position.  

        if(arr[idx] != arr[correctPos])
           swap(arr[idx], arr[correctPos]);

        else idx++;
    }
}

int main()
{
    int size;

    cin >> size;

    int* arr = new int[size];

    for(int idx = 0; idx < size; idx++) 
       cin >> arr[idx];

    cyclicSort(arr,size);

    for(int idx = 0; idx < size; idx++)
      cout << arr[idx] << " ";

    return 0;
}