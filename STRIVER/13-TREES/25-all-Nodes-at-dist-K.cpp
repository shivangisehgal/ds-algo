//problem can be broken down into:
//1. k distance downwards
//2. k distance upwards

//we can do a level order traversal, starting from the target node
//we know, for each level, distance = 1, i.e., k distance = k levels
//for downwards, left and right child will be considered
//for upwards, the parent will be considered. 
//Since we are pushing parents as well, situation can occur wherein node is already present in queue.
//Push nodes in case its not in queue already

//to track parent of every node, do the mapping beforehand.

//TC: O(N) + (O(K)=> O(N)) + O(NlogN) (for hashMap) = O(N) or O(NlogN) if hashmap takes logN for insertion.
//SC: O(N + N)

void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent)
{
    if(root == NULL)
        return;
    
    queue<TreeNode*> q;
    TreeNode* temp = root;
    
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        
        for(int i = 0; i < n; i++)
        {
            temp = q.front();
            q.pop();

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
    
    return;
    
}
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(root == NULL)
            return {};
        
        vector<int> ans;
        
        unordered_map<TreeNode*, TreeNode*> parent;
        getParent(root, parent);
        
    
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        
        
        q.push(target);
        visited[target] = true;
        
        TreeNode* temp = target;
        int level = 0;
        
        while(!q.empty())
        {
            if(level == k)
                break;
            
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
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};
