// max. min. smax. smin. tmax. tmin....

//OPTIMAL - IN-PLACE.
// To modify array element without losing previous info (store two values in one place):
// arr[i] = arr[i] + N*newVal
// Hence, oldVal can be found out as arr[i] % N ( (arr[i] + N*newVal) % N ) 
// And newVal can be found out as arr[i] / N ( (arr[i] + N*newVal) / N )

class Solution{
    public:
    
    void rearrange(long long *arr, int n) 
    { 
    	
    	 int m = arr[n - 1] + 1;
    	 int maxInd = 0;
    	 int minInd = 1;
    	 
    	 if(n == 1)
    	    return;
    	    
    	 for(int i = 0; i <= n / 2; i++)
    	 {
    	     int j = n - 1 - i;
    	     
    	     arr[maxInd] = arr[maxInd] % m + (m * (arr[j]% m));
    	     maxInd += 2;
    	     
    	     arr[minInd] = arr[minInd] % m + (m * (arr[i] % m));
    	     minInd += 2;
    	 }
    	 
    	 for(int i = 0; i < n; i++)
    	 {
    	     arr[i] = arr[i] / m;
    	 }
    	 
    }
};
