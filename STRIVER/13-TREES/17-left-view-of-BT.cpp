//not on LC
//similar to right view
//TC: O(N)
//SC: O(H)

void leftView(TreeNode<int> *root, int level, vector<int>& ans)
{
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);
    
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    leftView(root, 0, ans);
    return ans;
}
