//TC: O(N)
//SC: O(N)

//just keep a bool flag for the direction
//also, no need to reverse the vector, make use of index

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
       if(root == NULL)
           return {};
        
        bool isRight = true;
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        TreeNode* temp = root;
        
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> v(n);
            int ind;
            
            for(int i = 0; i < n; i++)
            {
                temp = q.front();
                q.pop();
                
                ind = isRight ? i : n - 1 - i;
                v[ind] = temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                
            }
            
            ans.push_back(v);
            isRight = !isRight;
            
        }
        
        return ans;
        
    }
};
