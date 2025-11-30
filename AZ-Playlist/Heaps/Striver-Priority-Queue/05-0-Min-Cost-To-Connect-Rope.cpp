//BRUTE
//[Find smallest, erase, find second smallest, erase, push their sum] - do this while arr size > 1
//TC: O(N*N)
//SC: O(1)

//OPTIMAL
//TC: O(NlogN)
//SC: O(N)

//connect minimum two ropes, push their sum in the minHeap.
//this sum is added to total cost

long long connectRopes(int* arr, int n)
{
    // Your code goes here
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++)
        minHeap.push(arr[i]);

    int cost = 0;
    int r1 = 0, r2 = 0;

    while(!minHeap.empty())
    {
        r1 = minHeap.top();
        minHeap.pop();

        if(minHeap.empty())
            return cost;

        else
        {
            r2 = minHeap.top();
            minHeap.pop();
        }

        cost += (r1 + r2);
        minHeap.push(r1 + r2);
    }

    return cost;
}