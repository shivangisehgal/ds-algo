//a height balanced binary tree
//if the absolute difference between the left and right tree is not more than 1.
//Modify the height function. If any of the subtrees is not balanced, our tree won't be considered balanced

//TC: O(N)
//SC: O(H) => O(N) for a skewed tree.

class Solution {
public:
    
    int heightOfTreeHelper(TreeNode* root)
    {
        if(root == NULL)
            return 0; //base case
        
        int lH = heightOfTreeHelper(root->left);
        
        if(lH == -1)
            return -1; //false condition
        
        int rH = heightOfTreeHelper(root->right);
        
        if(rH == -1)
            return -1; //false condition
        
    
        if(abs(lH - rH) > 1)
            return -1; //false condition
        
        return max(lH, rH) + 1; //true condition
    }
    
    bool isBalanced(TreeNode* root) {
        
        return (heightOfTreeHelper(root) != -1);
    }
};
