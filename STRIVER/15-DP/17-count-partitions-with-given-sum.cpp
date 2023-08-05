
//s1 = totsum - s2
//s1 - s2 = d
//s2 = totsum - d / 2
//=> COUNT SUBSETS with sum =  (totsum - d) / 2

int findWays(vector<int> &arr, int k) 
{
    int n = arr.size();
	int m = 1e9 + 7;
	
	vector<int> prevIndex(k + 1, 0);
	vector<int> currIndex(k + 1, 0);

    if(arr[0] == 0)
        prevIndex[0] = 2;
    else
	    prevIndex[0] = 1;

	currIndex[0] = 1;

	if(arr[0] <= k && (arr[0] != 0))
		prevIndex[arr[0]] = 1;

	for(int i = 1; i < n; i++)
	{
		for(int target = 0; target <= k; target++)
		{
			int not_pick = 0;
			int pick = 0;

			not_pick = prevIndex[target];

			if(arr[i] <= target)
				pick = prevIndex[target - arr[i]];
			
			currIndex[target] = (not_pick + pick) % m;
		}

		prevIndex = currIndex;

	}

    return prevIndex[k] % m;
}

int countPartitions(int n, int d, vector<int> &arr) {

    int sum = 0;
        
    for(int i = 0; i < n; i++)
        sum += arr[i];

    if(sum < d || ((sum - d) & 1))
        return 0;
    
    int k = (sum - d) / 2;
    
    return findWays(arr, k);

}


