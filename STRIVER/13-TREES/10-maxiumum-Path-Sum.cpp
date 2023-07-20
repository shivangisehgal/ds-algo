//TC: O(N)
//SC: O(H) => O(N)

class Solution {
public:
    int helper(TreeNode* root, int &maxpathsum)
    {
        if(root == NULL)
            return 0;
        
        int lPathSum = helper(root->left, maxpathsum);
        
        if(lPathSum < 0) //if negative, rather not take it
            lPathSum = 0;
        
        int rPathSum = helper(root->right, maxpathsum);
        
        if(rPathSum < 0) //if negative, rather not take it
            rPathSum = 0;
        
        maxpathsum = max(maxpathsum, lPathSum + rPathSum + root->val);
        
        return (max(lPathSum, rPathSum) + root->val); 
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int help = helper(root, ans);
        return ans;
    }
};
