//not on LC

//TC: O(N + N)
//SC: O(N)

//same as top view, just don't keep the check.
vector<int> bottomView(BinaryTreeNode<int> * root){

       if(root == NULL)
        return {};
    
    vector<int> ans;
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int>*, int>> q;

    int v = 0;
    BinaryTreeNode<int>* temp = root;

    q.push({root, 0});

    while(!q.empty())
    {
        temp = q.front().first;
        v = q.front().second;
        q.pop();
        
        
        mp[v] = temp->data;
        
        if(temp->left)
            q.push({temp->left, v - 1});
        
        if(temp->right)
            q.push({temp->right, v + 1});
    }

    for(auto i : mp)
    {
        ans.push_back(i.second);
    }

    return ans;
    
}
