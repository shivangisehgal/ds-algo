//as late (deep) as we have p and q coming from left and right, we will have our ancestor
//if neither p nor q, return null.
//if either subtree is not null, return that for this whole tree

//TC: O(N)
//SC: O(H)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        if(root == p || root == q)
            return root == p ? p : q;
        
        TreeNode* leftTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightTree = lowestCommonAncestor(root->right, p, q);
        
        // if(leftTree == NULL && rightTree == NULL)
        //     return NULL;
        
        if(leftTree == NULL)
            return rightTree;
        
        if(rightTree == NULL)
            return leftTree;
        
        //else, p and q are returned from left and right
        return root;
    }
};
