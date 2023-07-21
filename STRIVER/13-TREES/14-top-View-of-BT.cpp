//not on LC

//basically, we have to return first node of each vertical
//we can use a map<vertical, node value>
//and use any traversal to traverse the tree. I prefer level
//In case, vertical is not present, add to map.

//TC: O(N) + O(N)
//SC: O(N)

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.

    if(root == NULL)
        return {};
    
    vector<int> ans;
    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;

    int v = 0;
    TreeNode<int>* temp = root;

    q.push({root, 0});

    while(!q.empty())
    {
        temp = q.front().first;
        v = q.front().second;
        q.pop();
        
        if(mp.find(v) == mp.end())
            mp[v] = temp->val;
        
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
