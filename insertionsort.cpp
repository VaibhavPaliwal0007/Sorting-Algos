/* 
    Best Case : O(N)
    Worst Case : O(N^2)
    used for smaller values of N 
    For partially sorted 
    always sorting the jth left part 
    ***partially sorting the array from left part !!!
*/

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int size, int* arr)
{
    for(int idx = 0; idx < size - 1; idx++)
    {
        for(int in = idx + 1; in > 0; in--)
        {
            if(arr[in] < arr[in - 1])
                swap(arr[in], arr[in - 1]);
            
            else break;
        }
    }

    for(int idx = 0; idx < size; idx++)
           cout << arr[idx] << " ";
}

int main()
{
    int size;

    cin >> size;

    int* arr = new int[size];

    for(int idx = 0; idx < size; idx++)
        cin >> arr[idx];

    insertionSort(size, arr);

    return 0;
}