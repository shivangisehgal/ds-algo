//Better: using stack

//Optimal: Kinda like morris
//TC: O(N)
//SC: O(1)

class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) 
        {
            if (root->left) 
            {
                TreeNode* rightmost = root->left;
                
                while (rightmost->right) 
                {
                    rightmost = rightmost->right;
                }
                
                
                rightmost->right = root->right;
                
                root->right = root->left;
                
                root->left = NULL;
            }
            
            root = root->right;
        }
    }
};
