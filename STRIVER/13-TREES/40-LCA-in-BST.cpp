//use preorder
//if just left and just right of root are p and q, then it will be LCA
//else if both lie on right, go to right
//if both lie on left, go to left

//TC: O(H)
//SC: O(H)

class Solution {
public:
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(root->val < p->val && root->val < q->val){
            return rec(root->right, p , q);
        }
        else if(root->val > p->val && root->val > q->val){
            return rec(root->left, p , q);
        }
        // else->
        return root;
    }
    TreeNode* iter(TreeNode* root, TreeNode* p, TreeNode* q){
        while(root){
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else{
                break;
            }
        }
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //* Recursive Approach->
        // return rec(root, p, q);

        //* Iterative Soln->
        return iter(root, p, q);
    }
};
