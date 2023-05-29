class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        //total required
        
        int total = S * M;
        
        int ans =  (total / N);
        
        if((total % N) != 0)
        {
            ans += 1;
        } 
        
        if(ans > S - (S / 7)) //S / 7 is the number of sundays. We cant buy on sundays
            return -1;
        
        return ans;
    }
};


