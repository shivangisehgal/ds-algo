//TC: O(N)
//SC: O(N)
//quest on LC 

//INORDER: L Root R
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        
        v.push_back(root->val);
        
        inorder(root->right, v);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

//PREORDER: Root L R 
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        
        preorder(root->left, v);
        
        preorder(root->right, v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

//POSTORDER: L R Root
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
            return;
        
        
        postorder(root->left, v);
        
        postorder(root->right, v);
        
        v.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};


