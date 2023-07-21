//M1 - Optimal
//TC: O(N)
//SC: O(H)

//go to right,
//if arr size = level, add to answer
//in case right child doesn't exist, only then go left once
void helper(TreeNode* root, int level, vector<int>& ans)
{
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->val);
    
    helper(root->right, level + 1, ans);
    helper(root->left, level + 1, ans);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<int> ans;
        
        helper(root, 0, ans);
        
        return ans;
    }
};

//M2 - LEVEL ORDER

//we have to find last node in each level
//use a map for level

//TC: O(N)
//SC: O(H + N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        
        int level = 0;
        TreeNode* temp = root;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            temp = q.front().first;
            level = q.front().second;
            q.pop();
            
            
            mp[level] = temp->val;
            
            if(temp->left)
                q.push({temp->left, level + 1});
            
            if(temp->right)
                q.push({temp->right, level + 1});
        }
        
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
