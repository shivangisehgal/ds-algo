//TC: O(H)
//SC: O(H)

int findCeil(BinaryTreeNode<int> *root, int x){
    
    if(root == NULL)
        return -1;
        
    int ceil = -1;

    while(root)
    {
        if(root->data == x)
            return x;

        else if(root->data < x)
            root = root->right;
        
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}
