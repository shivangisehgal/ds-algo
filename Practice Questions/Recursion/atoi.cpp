class Solution {
public:
    
    int rec(string s, int i, int sign, int ans)
    {
        //base cases
        
        if(i >= s.length())
            ans * sign;
        
        if(s[i] < '0' || s[i] > '9')
            return ans * sign;
        
        int d = s[i] - '0';
        
        if(sign == 1)
        {
            if(ans > INT_MAX / 10)
                return INT_MAX;
            
            else if(ans == INT_MAX / 10 && d >= 8)
                return INT_MAX;
        }
        
        else if(sign == -1)
        {
            if(sign * ans < INT_MIN / 10)
                return INT_MIN;
            
            else if(sign * ans == INT_MIN / 10 && d > 7)
                return INT_MIN;
        }
            
       return ans = rec(s, i + 1, sign, (ans * 10) + d); 
        
    }
    
    int myAtoi(string s) {
        
        //string str = "";
        
        int i = 0;
        
        while(i < s.length() && s[i] == ' ')
            i++;
        
        int sign = 1;
        
        if(s[i] == '+')
            i++;
        
        else if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        
        int ans = 0;
        
        return rec(s, i, sign, ans);
    }
};
