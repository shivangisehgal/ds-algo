//Perform preorder
//if both left and right are false, that means x is not present in both subtrees, so remove this element 
//else, it could be, check for left and right, if any is true. so we don't have to remove it.

//TC: O(N)
//SC: O(H) => O(N)
bool helper(TreeNode<int> *root, int x, vector<int>& ans)
{
	if(root == NULL)
		return false;

	ans.push_back(root->data);

	if(root->data == x)
		return true;

	if(helper(root->left, x, ans) || helper(root->right, x, ans)) 
		return true;

  //else
	ans.pop_back();
	
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	helper(root, x, ans);
	return ans;
}
