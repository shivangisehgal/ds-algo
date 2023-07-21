//TC: O(N * logN) //considering multiset takes logN for insertion
//SC: O(N) + O(3*N)

//in case we need to print in the same order in which they appear in a vertical,
//we would also need the level
//also, levels should be sorted, so do the verticals, so in both case we are choosing orderdered maps.
//so, for each vertical, we will have nodes at different levels
//and at each level in a single vertical, we can have more than 1 nodes 

//so create a map of vertical->level->[nodes]
//we have chosen a multiset, as it allows duplicates in a sorted manner (u can use priority queue too, same thing)
//we could have chosen a vector, but we would have to sort each vector -> tedious.
//since level is involved, we would require a queue

//here, row = level, col = vertical

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
       vector<vector<int>> ans;
        
        //vertical -> level -> [nodes]
       
        map<int, map<int, multiset<int>>> mp;
        
        
        //node, vertical, level
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        int r = 0, c = 0;
        TreeNode* temp = root;
        
        
        while(!q.empty())
        {
            auto qEl = q.front();
            q.pop();
            
            temp = qEl.first;
            c = qEl.second.first;
            r = qEl.second.second;
            
            mp[c][r].insert(temp->val);
            
            
            if(temp->left)
                q.push({temp->left, {c - 1, r + 1}});
            
            if(temp->right)
                q.push({temp->right, {c + 1, r + 1}});
        }
        
        //level order done.
        
        for(auto mpEl : mp)
        {
            //for all mpEl.first, store all mpEl.second.seconds
            vector<int> col;
            for(auto levelSet : mpEl.second)
            {
                col.insert(col.end(), levelSet.second.begin(), levelSet.second.end());
            }
            
            ans.push_back(col);
        }
        
        return ans;
        
    }
};
