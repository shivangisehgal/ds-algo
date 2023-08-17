class Solution {
    
    long long myPow(long long x, long long n, long long mod) 
    {

        long long ans = 1;
        bool isNeg = false;

        if(n < 0)
        {
            isNeg = true;
            n = -n;
        }

        while(n)
        {
            if(n & 1)
                ans = (ans * x) % mod;

            x = (x * x) % mod; //x^2
            n = n >> 1; // n / 2
        }

        return isNeg ? 1 / ans : ans;
    }
    
    
public:
    int countGoodNumbers(long long n) {
        
        long long odd = n >> 1;
        long long even;
        
        if(n & 1)
            even = odd + 1;
        
        else
            even = odd;
        
        long long mod = 1e9 + 7;
        
        long long oddWays = myPow(4LL, odd, mod);
        long long evenWays = myPow(5LL, even, mod);
        
        long long ans = (oddWays * evenWays) % mod;
        return (int)ans;
    }
};
