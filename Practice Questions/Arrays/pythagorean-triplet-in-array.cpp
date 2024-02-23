class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	
	//BRUTE
	//Use three loops, one for each number
	//TC: O(N^3)
	
	//BETTER
	//Use two loops and check if thrid exists using a hashmap (or a freq vector since n <= 1000)
	//TC: O(N^2.logN) (or O(N^2))
	//SC: O(N) (or O(1001) or O(maxi))
	
	//OPTIMAL
	//Since, maxi <= 1000, we can find the two elements by looping over the freq vector itself
	//Find two numbers using 2 loops over the freq vector, check if thrid exists.
	//TC: O(n + 1001^2) or O(n + maxi^2)
	//SC: O(1001) or O(maxi)
	
	bool checkTriplet(int arr[], int n) {
	    
	    vector<int> freq(1001, 0);
	    
	    int maxi = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        maxi = max(maxi, arr[i]);
	        freq[arr[i]]++;
	    }
	    
	    
	    for(int a = 1; a <= maxi; a++)
	    {
	        if(freq[a] == 0)
	            continue;
	            
	        for(int b = a + 1; b <= maxi; b++)
	        {
	            if(freq[b] == 0)
	                continue;
	           
	           int c2 = a*a + b*b;
	           int c = sqrt(c2);
	           if(((c * c) == c2) && freq[c] > 0)
	           {
	               //cout << a << b << c << endl;
	               return true;
	           }
	        }
	    }
	    
	    return false;
	    
	}
}
