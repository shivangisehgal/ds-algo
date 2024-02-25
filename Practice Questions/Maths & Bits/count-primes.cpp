//BETTER
//TC: O(N^(3/2))

class Solution {
public:
    
    bool isPrime(int n)
    {   
        if(n == 2 || n == 3)
            return true;
        
        if(n % 2 == 0 || n % 3 == 0)
            return false;
        
        // for(int i = 3; i * i <= n; i += 2) //even numbers can never be prime
        // {
        //     if(n % i == 0)
        //         return false;
        // }
        
        for(int i = 5; i * i <= n; i += 6) //multiples of 2 or 3 can never be prime, hence inc by 6
        {
            if(n % i == 0 || (n % (i + 2) == 0)) //cases which cover number not multiples of 2 or 3
                return false;
        }
        
        return true;
    }
    
    
    int countPrimes(int n) {
        
        int count = 0;
        
        for(int i = 2; i < n; i++)
            if(isPrime(i))
                count++;
        
        return count;
    }
};

//OPTIMAL
//TC: O()
class Solution {
public:
    
    vector<bool> sieveOfEratosthenes(int n)
    {
        vector<bool> sieve(n + 1, false);
        
        for(int i = 2; i * i <= n; i++)
        {
            if(sieve[i] == false)
            {
                //multiples of i
                for(int j = 2 * i; j <= n; j += i)
                    sieve[j] = true;
            }
        }
        
        return sieve;
    }
    
    
    int countPrimes(int n) {
        
        int count = 0;
        
        vector<bool> sieve = sieveOfEratosthenes(n);
        
        for(int i = 2; i < n; i++)
            if(sieve[i] == false)
                count++;
        
        return count;
    }
};
