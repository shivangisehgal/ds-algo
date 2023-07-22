//TC: O(H)
//SC: O(H)

int floorInBST(TreeNode<int> * root, int x)
{
    if(root == NULL)
        return -1;
    
    int floor = -1;

    while(root)
    {
        if(root->val == x)
            return x;
        
        if(root->val > x)
            root = root->left;
        
        else
        {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}
