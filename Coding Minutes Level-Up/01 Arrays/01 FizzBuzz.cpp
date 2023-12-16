//mod operation is costly
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans;
        
        for(int i = 1; i <= n; i++)
        {
            string el = "";
            
            if(i % 3 == 0)
                el = "Fizz";
            
            if(i % 5 == 0)
                el += "Buzz";
                
            if(el == "")
                el = to_string(i);
            
            ans.push_back(el);
        }
        
        return ans;
    }
};

//better
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans(n);
        
        for(int i = 1; i <= n; i++)
            ans[i - 1] = to_string(i);
        
        for(int i = 3; i <= n; i += 3)
            ans[i - 1] = "Fizz";
        
        for(int i = 5; i <= n; i += 5)
            ans[i - 1] = "Buzz";
        
        for(int i = 15; i <= n; i += 15)
            ans[i - 1] = "FizzBuzz";
        
        return ans;
    }
};
