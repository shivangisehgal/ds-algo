//TC: O(N)
//SC:  O(H) Recursion Stack => O(N) //recursive stack space (in case of skewed)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
};
