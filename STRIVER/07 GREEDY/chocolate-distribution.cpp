class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        
        long long ans = LLONG_MAX;
        
        for(long long i = 0; i <= n - m; i++)
        {
            
            if(ans > (a[i + m - 1] - a[i]))
                ans = a[i + m - 1] - a[i];
        }
        
        return ans;
    }   

};
