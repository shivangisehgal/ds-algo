//OPTIMAL
//BINARY EXPONENTIATION
//TC: O(logN)
//SC: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        
        
        double ans = 1;
        if(n < 0)
            x = 1 / x;
        
        n = abs(n);
        
        while(n > 0)
        {
            if(n & 1) //odd number
            {
                ans *= x; // ans = ans * x^2   
            }
            
            x = x * x;
            n = n >> 1; // n / 2
        }
        
        return ans;
    }
};

//MODULAR EXPONENTIATION

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) 
{
	long long ans = 1;

	while(n)
	{
		if(n & 1)
			ans = (ans % m) * (x % m);
		
		x = (1LL* x * x)% m;
		n = n >> 1;
	}

	return ans % m;
}
