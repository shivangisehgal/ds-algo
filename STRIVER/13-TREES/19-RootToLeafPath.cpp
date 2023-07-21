//LC
//Its a weird question wherein you have to use strng to store a path
//do notice the backtracking

//TC: O(N)
//SC: O(H) => O(N)
class Solution {
public:
    void getRootToLeafPaths(TreeNode* root, string path, vector<string>& ans)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
        {
            string node = to_string(root->val);
            
            if(path != "")
                path += "->" + node;
            
            else
                path += node;
            
            ans.push_back(path);
            
            return;
        }
        
        string node = to_string(root->val);
        
        if(path != "")
            node = "->" + node;
        
        getRootToLeafPaths(root->left, path + node, ans);
        getRootToLeafPaths(root->right, path + node, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        vector<string> ans;
        string s = "";
        getRootToLeafPaths(root, s, ans);
        return ans;
    }
};
