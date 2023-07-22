//Recurisve and Iterative
//TC: O(N)
//SC: O(N)

//Morris
//TC: O(N)
//SC: O(1)

//Recursive soln:

class Solution {
public:
    void helper(TreeNode* root, int& k, int& ans)
    {
        if(root == NULL)
            return;
        
        helper(root->left, k, ans);
        
        k--;
        
        if(k == 0)
        {
            ans = root->val;
            return;
        }
        
        helper(root->right, k, ans);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        helper(root, k, ans);
        return ans;
    }
};
