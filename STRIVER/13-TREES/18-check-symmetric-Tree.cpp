//TC: O(N)
//SC: O(H) => O(N)

class Solution {
public:
    
    bool helper(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL && r2 == NULL)
            return true;

        if (r1 == NULL || r2 == NULL)
            return false;

        if (r1->val != r2->val)
            return false;

        return (helper(r1->left, r2->right) && helper(r1->right, r2->left));
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        return helper(root, root);
    }
};
