//Use Queue
//TC: O(N)
//SC: O(N)

// We need to visit the nodes in a lower level before any node in a higher level, this idea is quite similar to that of a queue.
//Push the nodes of a lower level in the queue. For each level, when any node is visited, pop that node from the queue and push the child of that node in the queue.
// This ensures that the node of a lower level are visited prior to any node of a higher level.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<int> v;
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size(); //number of elements in one level
            v = {};
            
            while(n--)
            {
                TreeNode* temp = q.front();
                
                if(temp->left != NULL)
                    q.push(temp->left);
                
                if(temp->right != NULL)
                    q.push(temp->right);
                
                v.push_back(temp->val);
                
                q.pop();
            }
            
            ans.push_back(v);
                
        }
        
        return ans;
        
    }
};
