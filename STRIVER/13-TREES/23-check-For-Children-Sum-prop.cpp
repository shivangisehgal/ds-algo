//If left and right child exist, check 
//keep checking for left and right subtree
//if leaf node, then return true

//TC: O(N)
//SC: O(H) => O(N)

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL)
            return true;
        
        int lSum = 0;
        int rSum = 0;
        
        if(root->left)
            lSum = root->left->val;
        
        if(root->right)
            rSum = root->right->val;
        
        if((root->val) != lSum + rSum)
            return false;
        
        return (checkTree(root->left) && checkTree(root->right));
    }
};
