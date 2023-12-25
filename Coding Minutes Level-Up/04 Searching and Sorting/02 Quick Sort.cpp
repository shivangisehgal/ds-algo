#include <bits/stdc++.h> 

int partition(int s, int e, vector<int>& arr)
{
    int pivot = arr[e];

    int i = s - 1;
    int j = s;

    while(j < e)
    {
        if(arr[j] > pivot)
            j++;

        else
        {
            i++;
            swap(arr[i], arr[j]);
            j++;
        }
    }

    int pivotIndex = i + 1;
    swap(arr[pivotIndex], arr[e]);

    return pivotIndex;
}


void myQuickSort(int s, int e, vector<int>& arr)
{
    if(s >= e)
        return;

    int pivotIndex = partition(s, e, arr);
    myQuickSort(s, pivotIndex - 1, arr);
    myQuickSort(pivotIndex + 1, e, arr);
}


vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    int s = 0;
    int e = arr.size() - 1;

    myQuickSort(s, e, arr);

    return arr;
}
