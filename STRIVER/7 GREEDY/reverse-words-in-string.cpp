class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string word = "";
        string ans = "";
        for(ch : S)
        {
            if(ch == '.')
            {
                if(ans == "")
                    ans = word;
                
                else
                    ans = word + '.' + ans;
                    
                word = "";
            }
            
            else
                word += ch;
        }
        
        if(ans == "")
            ans = word;
                
        else
            ans = word + '.' + ans;
            
        return ans;
    } 
};
