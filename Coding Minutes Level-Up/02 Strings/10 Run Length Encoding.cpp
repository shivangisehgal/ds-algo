class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        int n = chars.size();
        
        while(i < n)
        {
            chars[k++] = chars[i];
            j = i + 1;
            
            while(j < n && chars[j] == chars[i])
                j++;
            
            int len = j - i;
            
            if(len > 1)
            {
                if(len < 10)
                    chars[k++] = len + '0';
                
                else
                {
                    string str = to_string(len);
                    
                    for(auto ch : str)
                        chars[k++] = ch;
                }
            }  
            
            i = j;
        }
        
        return k;
    }
};
