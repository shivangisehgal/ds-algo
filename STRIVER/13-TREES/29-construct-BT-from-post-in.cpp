//not on LC
//TC: O(N)
//SC: O(N)

#include <bits/stdc++.h>

void mapInorder(vector<int>& inorder, unordered_map<int, int>& inorderIndex)
{
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }
}

TreeNode<int>* helper(int postStart, int postEnd, int inStart, int inEnd, unordered_map<int, int>& inorderIndex, vector<int>& postorder, vector<int>& inorder)
{
        if(postEnd < postStart || inEnd < inStart)
            return NULL;
        
        //1. select root from postorder 
        int rootVal = postorder[postEnd];
        
        TreeNode<int>* root = new TreeNode<int>(rootVal);
        
        //2. find index of root in inorder
        int ind = inorderIndex[rootVal];
        
        //3. calculate size of rightSubtree
        int rightSize = inEnd - ind;
        
        root->right = helper(postEnd - rightSize, postEnd - 1, ind + 1, inEnd, inorderIndex, postorder, inorder);
        
        root->left = helper(postStart, postEnd - rightSize - 1, inStart, ind - 1, inorderIndex, postorder, inorder);
        
        return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
     
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        
        unordered_map<int, int> inorderIndex;
        
        mapInorder(inorder, inorderIndex);
        
        TreeNode<int>* root = helper(postStart, postEnd, inStart, inEnd, inorderIndex, postorder, inorder);
        
        return root;
}
