#include <bits/stdc++.h> 

class MinHeap
{
    public:
    vector<int> v;
    int size;

    MinHeap(int sz = 1000)
    {
        v.resize(sz + 1);

        size = 0;
        v[0] = -1;
    }

    void insert(int val)
    {
        //1. push at last
        //2. place at correct position by *comparing with parents*

        size = size + 1;
        int ind = size;

        v[ind] = val;

        int parent = ind / 2;

        while(parent > 0 && v[parent] > v[ind])
        {
            swap(v[parent], v[ind]);
            ind = parent;
            parent = ind / 2;
        }
    }

    void deleteMin()
    {
        //1. swap min element and last element
        //2. delete min element (Which is at last)
        //3. Place first element at correct position by *comparing with children*

        int ind = size;
        swap(v[1], v[ind]);

        v.pop_back();
        size = size - 1;

        Heapify(1);
    }

    void Heapify(int ind)
    {
        //Placing node at ind at correct position by *comparing with children*
        int leftChildPos = 2 * ind;
        int rightChildPos = 2 * ind + 1;

        int minPos = ind;

        if(leftChildPos <= size && v[leftChildPos] < v[minPos])
            minPos = leftChildPos;
        if(rightChildPos <= size && v[rightChildPos] < v[minPos])
            minPos = rightChildPos;

        if(minPos != ind)
        {
            swap(v[ind], v[minPos]);
            Heapify(minPos);
        }
    }

    int findMin()
    {
        return v[1];
    }

    bool empty()
    {
        return (size == 0);
    }
};

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();

    MinHeap minHeap(n);

    //BUILD HEAP
    for(int num : arr)
    {
        minHeap.insert(num);
    }

    int i = 0;

    while(!minHeap.empty())
    {
        arr[i++] = minHeap.findMin();
        minHeap.deleteMin();
    }

    return arr;
} 
