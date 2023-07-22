//TC: O(H * logN) => O(logN * logN) (height of CBT is logN)
//SC: O(H) => O(logN)

//find left height and right height
//if they are same => perfect tree => 2^h - 1 nodes
//else, nodes of left + nodes of right + 1


class Solution {
    int leftHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        return 1 + leftHeight(root->left);
    }
    
    int rightHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        return 1 + rightHeight(root->right);
    }
public:
    
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        
        int lH = leftHeight(root);
        int rH = rightHeight(root);
        

        if(lH == rH)
            return (pow(2, lH) - 1);
        
        //else
        return (countNodes(root->left) + countNodes(root->right) + 1);
    }
};
