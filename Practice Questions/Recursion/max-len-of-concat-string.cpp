class Solution {
public:
    
    int rec(int i, string s, vector<string>& arr)
    {
        if(i == arr.size())
            return s.length();
        
        string str = arr[i];
        cout << str << endl;
        int len = str.length();
        
        unordered_set<char> hashSet;
        
        bool hasRepeated = false;
        
        //check if arr[i] has any repeated characters with the existing string, o has repeated characters in its own.
        
        for(int ind = 0; ind < s.length(); ind++)
        {
            hashSet.insert(s[ind]);
        }
        
        for(int ind = 0; ind < len; ind++)
        {
            if(hashSet.find(str[ind]) != hashSet.end())
            {
                hasRepeated = true;
                break;
            }
            
            cout << str[ind] << " ";
            hashSet.insert(str[ind]);
        }
        
        cout << endl;
        
        int include = 0;
        int not_include = 0;
        
        if(hasRepeated == false)
            include = rec(i + 1, s + str, arr);
        
        not_include =  rec(i + 1, s, arr); //a condition for rec(i + 1, str) will obviously be created if s = "" and str has non repeating characters.
            
        return max(include, not_include);
    }
    
    int maxLength(vector<string>& arr) {
        
        return rec(0, "", arr);
    }
};
