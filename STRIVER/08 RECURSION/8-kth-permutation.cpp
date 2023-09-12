//BRUTE 
//store all permutations, sort the array of string, find the kth perm.
//TC: O(N! * N) + O(N! Log N!)
//SC: O(N) //not considering stack space

class Solution {
public:
    void helper(int i, vector<string>& ans, string &s)
    {
        
        if(i == s.length())
        {
            ans.push_back(s);
            return;
        }
        
        for(int ind = i; ind < s.length(); ind++)
        {
            swap(s[ind], s[i]);
            helper(i + 1, ans, s);
            swap(s[ind], s[i]);
        }
    }
    
    string getPermutation(int n, int k) {
        
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            s += to_string(i);
        }
        vector<string> ans;
        helper(0, ans, s);
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};


//OPTIMAL
 
    //n = 4, k = 17
    //out of 24 perms, i have to find the 17th one
    
    //1 + 6perms(234) | 0-5
    //2 + 6 perms(134) | 6-11
    //3 + 6 perms(124) | 12 - 17
    //4 + 6 perms(123) | 18 - 23
    
    //fact = fact(n - 1) = 6
    //1 2 3 4
    //0 1 2 3
    //first number would be 16/6th => 3
    //fact => fact/n - 2 = 6/2 = 2
    //now we have to find (16) % 6th out of this sub sequence(124) => 4th sequence
    //1 2 4
    //0 1 2
    //second number = 4/2th => 4
    //fact = fact/n-3 => 2
    //now we have to find (4) % 2th seq => 0th seq of this subseq(12)
    //1 2
    //0 1
    //third number = 0/2th = 1

//TC: O(N^2) (for every number we are inserting in sequence, we are also erasing it in the vector as well)
//SC: O(N)
class Solution {
public:
    
    string getPermutation(int n, int k) {
        
        vector<int> num(n);
        int fact = 1;
        string ans = "";

        //calculate n! and store 1-n in nums 
        
        for(int i = 1; i <= n; i++)
        {
            fact = fact * i;
            num[i - 1] = i;
        }
        
        //calculate (n - 1)! and make k zero-based
        
        fact = fact / n; //for each number, we will have (n - 1)! combinations starting from it.
        k = k - 1;
        
        while(true)
        {
            int ind = k / fact; //calculate which (n - 1)! block does k lie in.
            
            ans += to_string(num[ind]);
            
            //remove num[ind] from vector
            num.erase(num.begin() + ind);
            n = n - 1;
            
            if(num.size() == 0)
                break;
            
            k = k % fact;
            
            fact = fact / n;
        }
        
        return ans;
    }
};

