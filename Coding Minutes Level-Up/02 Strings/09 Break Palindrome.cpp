//make the first non-a letter as a (till first half before mid)
//else, last vaala b 
//edge case, size = 1 and s = "a", toh no way

class Solution {
public:
    
    string breakPalindrome(string palindrome) {
            
        int i = 0;
        
        string temp = palindrome;
        
        int n = temp.size();
        
        while(i < n / 2)
        {
            if(temp[i] != 'a')
            {
                char ch = temp[i];
                
                temp[i] = 'a';

                return temp;
            }
            
            i++;
        }
        
        if(n == 1)
            return "";
       
        temp[n - 1] = 'b';
        
        return temp;
    }
};
