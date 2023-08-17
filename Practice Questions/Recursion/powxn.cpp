double rec(double x, int n, double ans)
{
    if(n == 0)
        return ans;
    
    if(n & 1)
        ans = x * ans;
    
    return rec(x * x, n >> 1, ans);
}


double myPow(double x, int n) {

    double ans = 1;
    bool isNeg = false;

    if(n < 0)
    {
        isNeg = true;
        n = -n;
    }

    ans = rec(x, n, ans);
    
    return isNeg ? 1 / ans : ans;
}
