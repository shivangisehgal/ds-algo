//TC: O(H)
//SC: O(H)

class Solution {
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        
        if(root->val == val)
            return root;
        if(val < root->val)
            return searchBST(root->left, val);
        //else
        return searchBST(root->right, val);
    }
    
    
public:
    
    TreeNode* leftmostNode(TreeNode* root)
    {
        while(root->left != NULL)
        {
			root = root->left;
		}
		return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        //delete a leaf node
        //delete node with only one child
        //delete node with both children
        
        if(root == NULL)
        {
			return NULL;
		}
        
		else if(key < root->val)
        {
			root->left = deleteNode(root->left,key);
		}
        
		else if(key > root->val)
        {
			root->right = deleteNode(root->right,key);
		}
        
        else
        {
            //no child
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }

            //single child
            else if(root->left == NULL)
            {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }

            else if(root->right == NULL)
            {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }

            //both children
            else
            {
                TreeNode* leftmostOfRightTree = leftmostNode(root->right);

                root->val = leftmostOfRightTree->val;

                root->right = deleteNode(root->right, leftmostOfRightTree->val);
            }
        }
        
        
        return root;
    }
};
