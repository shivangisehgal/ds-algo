//TC: O(N)
//SC: O(N)

class Solution {
public:
    bool helper(TreeNode* root, long long minVal, long long maxVal)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= minVal || root->val >= maxVal)
            return false;
        
        return (helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal)); 
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        
        long long minVal = LONG_MIN;
        long long maxVal = LONG_MAX;
        
        return helper(root, minVal, maxVal);
    }
};
