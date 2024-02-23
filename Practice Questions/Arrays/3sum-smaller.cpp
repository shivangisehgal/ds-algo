//count-triplets-with-sum-smaller-that-a-given-value.cpp

class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr, arr + n);
	    int count = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	         int low = i + 1;
	         int high = n - 1;
	         
	         while(low < high)
	         {
	             if(arr[low] + arr[high] + arr[i] >= sum)
	                high--;
	                
	             else
	             {
	                 //if x + arr[high] < y, then x + arr[high - 1] is also < y
	                 count += (high - low); //i, low, low + 1 | i, low, low + 2 | ....i, low, high - 1 | i, low, high
	                 low++; //possible: i, low + 1, low + 2 | i, low + 1, low + 3 | .....i, low + 1, high
	                 
	                 //HENCE, NOTE THAT NO PAIR WOULD BE SAME AS ARRAY HAS DISTINCT INTS.
	             }
	         }
	    }
	    
	    return count;
	}
};
