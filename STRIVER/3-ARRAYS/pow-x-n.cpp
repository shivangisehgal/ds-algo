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
