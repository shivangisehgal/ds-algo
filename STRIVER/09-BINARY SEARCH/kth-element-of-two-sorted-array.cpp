//BRUTE/BETTER
//Use pointer and fin kth element
//TC: O(M + N)
//SC: O(M+N) / O(1)
class Solution{
    public:
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;
        int j = 0;
        int count = 0;
        
        while(i < n and j < m)
        {
            
            if(arr1[i] <= arr2[j])
            {
                if(count + 1 == k)
                    return arr1[i];
                
                i++;
                count++;
            }
            
            
            else
            {
                if(count + 1 == k)
                    return arr2[j];
                j++;
                count++;
            }
        }
        
        while(i < n)
        {
            if(count + 1 == k)
                    return arr1[i];
                
                i++;
                count++;
        }
        
        while(j < m)
        {
            if(count + 1 == k)
                    return arr2[j];
                
                j++;
                count++;
        }
        
        return 0;
    }
}

//OPTIMAL
//create a partition when it'll have k elements to the left.
//note the edge cases.
//USE BINARY SEARCH
//TC: O(log(min(M, N))
//SC: O(1)


lass Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m)
        {
            return kthElement(arr2, arr1, m, n, k);
        }
            int s = max(0, k - m); //edge cases
            int e = min(k, n); //edge cases
            
            //for e: [0 0 0 0 0 | 0] [0 0] k = 5
            // what if size of arr1 was smaller than k -> e = n
            //if it is bigger than k, we know that our search space (for arr1) can lie max till k only.
            //=> e = k 
            
            //for s: [0 0 | 0 0 0 0 ] [0] k = 5 
            //we cannot have less than k elements TOTAL till cut1, 
            //if m is less than k, we need to have k - m elements till cut1 from arr1.
            //
            int cut1, cut2, l1, l2, r1, r2;
            
            while(s <= e)
            {
                cut1 = (s + e) / 2;
                
                cut2 = k - cut1;
                
                l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
                r1 = (cut1 >= n) ? INT_MAX : arr1[cut1];
                
                l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
                r2 = (cut2 >= m) ? INT_MAX : arr2[cut2];
                
                if(l1 > r2)
                    e = cut1 - 1;
                    
                else if(l2 > r1)
                    s = cut1 + 1;
                
                else
                {
                    return max(l1, l2);
                }
            }
        
        return -1;
    }
}
