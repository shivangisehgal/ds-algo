//NOTE: IN ORDER TO CONSTRUCT A UNIQUE BT, WE WILL ALWAYS NEED INORDER TRAVERSAL
//TC: O(N)
//SC: O(N) 
//Refer handwritten notes
class Solution {
    
    void mapInorder(vector<int>& inorder, unordered_map<int, int>& inorderIndex)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }
    }
    
    
    TreeNode* helper(int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& inorderIndex, vector<int>& preorder, vector<int>& inorder)
    {
        if(preEnd < preStart || inEnd < inStart)
            return NULL;
        
        //1. select root from preorder 
        int rootVal = preorder[preStart];
        
        TreeNode* root = new TreeNode(rootVal);
        
        //2. find index of root in inorder
        int ind = inorderIndex[rootVal];
        
        //3. calculate size of leftSubtree
        int leftSize = ind - inStart;
        
        root->left = helper(preStart + 1, preStart + leftSize, inStart, ind - 1, inorderIndex, preorder, inorder);
        
        root->right = helper(preStart + leftSize + 1, preEnd, ind + 1, inEnd, inorderIndex, preorder, inorder);
        
        return root;
    }
    
public:
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preStart = 0;
        int preEnd = preorder.size() - 1;
        
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        
        unordered_map<int, int> inorderIndex;
        
        mapInorder(inorder, inorderIndex);
        
        TreeNode* root = helper(preStart, preEnd, inStart, inEnd, inorderIndex, preorder, inorder);
        
        return root;
    }
};
