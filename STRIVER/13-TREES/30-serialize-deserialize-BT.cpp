//Use any traversal to serailize (eg. level order. where nodes are , separated
//use the same method to deserialize (eg. use a queue to deserialise)
//to deserialize, use a stringstream, and use getline to get each string ', separated.

//TC: O(N)
//SC: O(N)

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL)
            return "";
        
        queue<TreeNode*> q;
        string s = "";
        
        q.push(root);
        s += to_string(root->val);
        
        TreeNode* temp = root;
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                temp = q.front();
                q.pop();
                
                if(temp->left)
                {
                    s += "," + to_string(temp->left->val);
                    q.push(temp->left);
                }
                
                else 
                     s += ",null";
                
                if(temp->right)
                {
                    s += "," + to_string(temp->right->val);
                    q.push(temp->right);
                }
                
                else 
                   s += ",null";
            }
            
        }
        
        //q; 1|23|45|
        //s = 1,2,3,null,null,4,5,null,null,null,null
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0)
            return NULL;
        
        
        stringstream s(data); //stream allows the string's components to be used as objects.
        
        string node;
        getline(s, node, ','); 
        //node would be every string in s, that is separated by ','
        //currently, node is the first string before any ','
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(node));
        
        q.push(root);
        
        TreeNode* temp = root;
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                temp = q.front();
                q.pop();

                //for left child
                //since while serializing we used level order (where left comes first)
                
                getline(s, node, ',');
                
                if(node == "null")
                    temp->left = NULL;
                else
                {
                    temp->left = new TreeNode(stoi(node));
                    q.push(temp->left);
                }
                
                
                //for right child
                
                getline(s, node, ',');
                
                if(node == "null")
                    temp->right = NULL;
                else
                {
                    temp->right = new TreeNode(stoi(node));
                    q.push(temp->right);
                }
                
            }
            
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
