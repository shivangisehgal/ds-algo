//Create a max variable.
//Diameter of any subtree CAN be the sum of its left height and right height.
//We have to find out the maximum (left height + right Height) out of all subtrees inside the tree.

//TC: O(N)
//SC: O(H) => O(N)

class Solution {
public:
    int height(TreeNode* root, int& diameter){
        
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        
        diameter = max(diameter, lh + rh);
        
        return (1 + max(lh, rh));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
