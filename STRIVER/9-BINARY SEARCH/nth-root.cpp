//TC: N*Log2(M * (10)^d)
//WHERE: N is Nth Root
//       M is the number
//       d is the decimal places allowed

//SC: O(1)
class Solution{
	public:
	
	int NthRoot(int n, int m)
	{
	    //search space: 1 to m
	    //if one decimal place : 1 1.1 1.2 .... 2 2.1 ...... (m - 1).9 m
	    
	    if(m == 1 || m == 0)
	        return m;
    
	    long long low = 1, high = m, mid;
	    
	    long long diff = 0;
	    //choose diff = 10^(-d)
	    
	    while(high - low >= diff)
	    {
	        long long ans = 1;
	        mid = (low + high) / 2;
	        
        //calculate pow(mid, n)
	        for(int i = 0; i < n; i++)
	        {
	            ans *= mid;
	            if(ans > m)
	                break;
	        } 
	        
	        
	        if(ans == m)
	            return mid;
	            
	        else if(ans > m)
	            high = mid - 1; // use high = mid, in case of non-integral answer is allowed
	        else
	            low = mid + 1; // use low = mid, in case of non-integral answer is allowed
	    }
	    
	    return -1;
	    
	}  
	
}
