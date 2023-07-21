//Do level order traversal and assign/store indices of the tree nodes (just like in heap)
//calculate ideal length of each level with those indices.

//TC: O(N)
//SC: O(N)


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        long long ind = 0;
       
        long long maxWidth = INT_MIN;
        
        queue<pair<TreeNode*, int>> q;
        
        TreeNode* temp = new TreeNode();
        long long left = 0;
        long long right = 0;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            int n = q.size();
            
            long long ind_start = q.front().second;
            
            for(int i = 0; i < n; i++)
            {
                temp = q.front().first;
                ind = q.front().second - ind_start;
                
                if(i == 0)
                    left = q.front().second;
                
                if(i == n - 1)
                    right = q.front().second;
                
                q.pop();
                
                if(temp->left)
                    q.push({temp->left, 2 * ind + 1});
                
                if(temp->right)
                    q.push({temp->right, 2 * ind + 2});
                
            }
            
            maxWidth = max(right - left + 1, maxWidth);
        }
        
        return maxWidth;
    }
};
