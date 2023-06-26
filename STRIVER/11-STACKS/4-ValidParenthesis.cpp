//TC: O(N)
//SC: O(1)

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(auto ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
                stk.push(ch);
            
            else
            {
                if(stk.empty())
                    return false;
                else
                {
                    char top = stk.top();
                    
                    if((ch == ')' && top == '(') ||
                        (ch == ']' && top == '[') ||
                        (ch == '}' && top == '{'))
                        stk.pop();
                    
                    else 
                        return false;
                }
            }
        }
        
       return (stk.empty());
    }
};
