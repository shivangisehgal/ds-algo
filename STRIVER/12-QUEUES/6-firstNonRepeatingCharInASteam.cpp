//Q. Find the the first non-repeating element till i'th element for each i.

//using a queue, we can store elements which have a frequency of 1 till each iteration.
//In case, in a an iteration, the frequency of front element (ie the first non rep element) becomes greater than 1, we'll pop it.

//TC: O(N), as the string is traversed once.
//SC: O(N)

class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    queue<char> q;
		    vector<int> freq(26, 0);
		    string ans = "";
		    
		    for(int i = 0; i < s.length(); i++)
		    {

		        q.push(s[i]);
		        freq[s[i] - 'a']++;
		        
		        while(!q.empty() && freq[q.front() - 'a'] > 1)
		            q.pop();
		        
		        if(!q.empty())
		            ans += q.front();
		            
		        else
		            ans += '#';
		    }
		    
		    return ans;
		}

};
