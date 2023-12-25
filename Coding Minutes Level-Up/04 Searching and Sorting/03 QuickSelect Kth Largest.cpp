//3-PARTITION PARTIAL QUICK SORT

//Worst case, assume that the pivot is always the greatest value
// O(N + N - 1 + N - 2 + N - 3 + ....) = O(N^2)

//Average case, pivot is somewhere in the middle always
//O(N + N/2 + N/3 + .... INFINITY) = O(N)


pair<int, int> partition(int s, int e, vector<int>& nums)
{
    
    //int pivotIndex = s + rand() % (s - e + 1);
    //swap(nums[e], nums[pivotIndex]);
    
    int pivot = nums[e];

    int pivotCount = 0; 
    
    int i = s - 1;
    
    for(int j = s; j < e; j++)
    {
        if(nums[j] >= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
        
        if(nums[j] == pivot)
            pivotCount++;
    }

    int pivotIndex = i + 1;
    
    swap(nums[pivotIndex], nums[e]);

    return {pivotIndex, pivotCount};
}


int quickSelect(int s, int e, int k, vector<int>& nums) 
{
    
    if(s < e)
    {
        pair<int, int> p = partition(s, e, nums);
        
        int pivotIndex = p.first;
        int pivotCount = p.second;

        if(k >= pivotIndex - pivotCount && k <= pivotIndex)
        {
            return nums[pivotIndex];
        } 

        if (k < pivotIndex) 
        {
            return quickSelect(s, pivotIndex - 1, k, nums);
        } 

        else 
        {
            return quickSelect(pivotIndex + 1, e, k, nums);
        }
    }
    
    //already sorted
    return nums[k];
}


class Solution 
{
    public:
    
    int findKthLargest(vector<int>& nums, int k) 
    {
        
        int n = nums.size();
        k = k - 1;
        return quickSelect(0, n - 1, k, nums);
    }
};
