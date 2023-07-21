//Create a max variable.
//diameter is defined as destance between any two nodes, so for 2 adjacent nodes, diameter would be 1
//Diameter of any subtree can be the sum of its (left height and right height + 1) - 1 => +1 contributed by the node itself.
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
        
        diameter = max(diameter, 1 + lh + rh - 1);
        
        return (1 + max(lh, rh));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
