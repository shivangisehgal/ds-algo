class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        vector<int> v;
        TreeNode* curr = root;
        
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                v.push_back(curr->val);
                curr = curr->right;
            }
            
            else //left child exists
            {
                TreeNode* temp = curr->left;
                
                while(temp->right != NULL && temp->right != curr)
                    temp = temp->right;
                
                //r
                if(temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                
                else
                {
                    temp->right = NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return v;
    }
};
