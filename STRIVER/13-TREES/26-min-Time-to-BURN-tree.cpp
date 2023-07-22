//max distance between target to any leaf node
//TC: O(N) / O(NlogN)
//SC: O(N)

#include<bits/stdc++.h>

BinaryTreeNode<int>* getParentAndStoreTarget(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent, int start)
{
    if(root == NULL)
        return root;
    
    queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int>* temp = root;
    BinaryTreeNode<int>* target = root;

    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        
        for(int i = 0; i < n; i++)
        {
            temp = q.front();
            q.pop();

            if(temp->data == start)
                target = temp;

            if(temp->left)
            {
                parent[temp->left] = temp;
                q.push(temp->left);
            }

            if(temp->right)
            {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
    }
    
    return target;
    
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
     if(root == NULL)
            return {};
        
        vector<int> ans;
        
        BinaryTreeNode<int>* target = root;
        unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
        target = getParentAndStoreTarget(root, parent, start);
        
    
        queue<BinaryTreeNode<int>*> q;
        unordered_map<BinaryTreeNode<int>*, bool> visited;
        
        
        q.push(target);
        visited[target] = true;
        
        BinaryTreeNode<int>* temp = target;
        int level = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                temp = q.front();
                
                q.pop();
                
                if(temp->left && !visited[temp->left])
                {
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                
                if(temp->right && !visited[temp->right])
                {
                    visited[temp->right] = true;
                    q.push(temp->right);
                }
                
                if(parent[temp] && !visited[parent[temp]])
                {
                    visited[parent[temp]] = true;
                    q.push(parent[temp]);
                }
            }
            
            level++;
        }

        level--;
        
     
