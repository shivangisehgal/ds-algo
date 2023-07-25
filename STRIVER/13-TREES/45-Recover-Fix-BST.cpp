//Brute:
//Store in an inorder array
//Sort
//Reiterate and change value of node in tree, wherever diff from array
//TC: O(N + NlogN + N)
//SC: O(N)

//Optimal
//Swapping should be done in inorder traversal
//Keep track of previous node.
//In case current node is less than the previous node (it should've been greater considering inorder is sorted)
//There can be two cases of mismatch:
  //either nodes to be swapped are adjacent
  //or a distant locations

//If 'first' mismatched node is not null, that means this is the second mismatch - this is the case when the two nodes to be swapped are at a distance
//if 'first' is null, that it means its first time mismatch has occured. store prev in first and current node in second.
//for second mismatch, upade the second to the current node.

//TC: O(N)
//SC: O(N)

class Solution {
    
    TreeNode* first, *second, *prev;
    
public:
    void inorder(TreeNode* root)
    {
        if(root == NULL) 
            return;
        
        inorder(root->left);
        
        if(prev != NULL && (root->val < prev->val))
        {
            if(first == NULL)
            {
                first = prev;
                second = root; 
            }
            
            else
                second = root;
        }
        
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = second = prev = NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};
