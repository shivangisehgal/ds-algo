//Approach 1:
//Sort both, use two pointer: 
//TC: O(nlogn + mlogm)

//Approach 2:
//Sort one (eg arr 2), use binary search to find closest in 2, for each element in 1
//Closest would be [lower bound] (and [lower bound - 1] in case [lower bound] != el)

//TC: O(mlogm + nlogm)

int smallestDifferencePair(vector<int> arr1, int n, vector<int> arr2, int m) {
    // Write your code here

    if(n < m)
    {
        swap(arr1, arr2);
        swap(n, m);
    }

    sort(arr2.begin(), arr2.end());

    int diff = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        int x = arr1[i];

        //find index of lower bound of x (lower bound = value just greater than or equal to)
        int lbIndex = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
        
        if(lbIndex == arr2.size())
            diff = min(diff, abs(x - arr2[m - 1]));

        else
        {
            //if [lb] = equal, toh yahi hoga
            diff = min(diff, abs(x - arr2[lbIndex]));

            //otherwise, [lb] means greater, hence find diff with greater or lesser ([lb] or [lb - 1])
            if(lbIndex >= 1)
            diff = min(diff, abs(x - arr2[lbIndex - 1]));
        }

    }

    return diff;
}
