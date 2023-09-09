//Time Complexity: O( (2^N) * K * N )

//Reason: O(2^n) to generate every substring and O(n) to check if the substring generated is a palindrome. 
//O(k) is for inserting the palindromes in another data structure, where k is the average length of the palindrome list.

//Space Complexity: O(k * x)

//Reason: The space complexity can vary depending upon the length of the answer. 
//k is the average length of the list of palindromes and 
//if we have x such list of palindromes in our final answer. 
//The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

/*
we have to partition the string in such ways that each part is a palindrome
eg [aabbc]
one way - [a a b b c]
2nd - [a a bb c]
3rd - [aa b b c]
4th - [aa bb c]
create a recursive function - if first PART is pal, check for rest of the substring.
for first flow (i.e. starting from 0 index) part can be: 
0-0 (-> if pal, check for 1-n-1 => now parts can be 1-1, 1-2, 1-3, 1-4),
0-1 (-> if pal, check for 2-n-1),
0-2
0-3
0-4 -> end => base case. traced for all pal parts
*/



class Solution {
public:
    bool isPal(string s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
    void helper(int i, string s, vector<string>& v, vector<vector<string>>& ans)
    {
        if(i >= s.length())
        {
            ans.push_back(v);
            return;
        }
        
        for(int ind = i; ind < s.length(); ind++)
        {
            if(isPal(s, i, ind))
            {
                v.push_back(s.substr(i, ind - i + 1));
                helper(ind + 1, s, v, ans);
                v.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> v;
        helper(0, s, v, ans);
        return ans;
    }
};
