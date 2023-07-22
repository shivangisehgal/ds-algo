//TC: O(H)
//SC: O(1)

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL)
            return new TreeNode(val);
        
        TreeNode* temp = root;
        
        while(true)
        {
            if(val <= temp->val)
            {
                if(temp->left == NULL)
                {
                    temp->left = new TreeNode(val);
                    return root;
                }
                
                temp = temp->left;
                
            }
            
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = new TreeNode(val);
                    return root;
                }
                
                temp = temp->right;
            }
        }
        
        
        return root;
        
    }
};
