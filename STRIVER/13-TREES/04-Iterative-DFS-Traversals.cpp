//TC: O(N)
//SC: O(N)

//PREORDER: Root L R 
//As we have to devise an iterative solution, we have to use additional DS.
//In recursion, nodes were stored in auxiliary stack space, now, we shall use stack.
// To ensure that the left subtree is handled first, the right child is pushed before the left child as a stack is a LIFO data structure.

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s;
        
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            
            ans.push_back(temp->val);
            
            s.pop();
            
            
            if(temp->right)
                s.push(temp->right);
            
            if(temp->left)
                s.push(temp->left);
            
        }
        
        return ans;
    }
};


//INORDER: L Root R
//Again, replicating the auxilliary stack space.
//Keep going till left (and storing in stack), once the node's left is NULL, we have to print it (and this will be popped), then go to it's root (the now top of stack).
//Since this was the root node, print, go to its right (subtree)
//For this subtree, the same action will be repeated

//All this is happening, by keepinga tree node pointer.
//keep updating node.


class Solution {
public:
  
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s;
        
        TreeNode* temp = root;
        
        //stack can be empty, when there is no left child of the root node.
        //we have popped the root node. while we have started with right subtree, stack will be empty.
        //Take this example:
        
/*
                1
                 \
                  2
                  /
                  3
  
*/
        while(true)
        {
            if(temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            
            else //no left child -> print root, go one step right.
            {
                
                if(s.empty()) //current is null and stack is empty => tree traversed fully
                    break;
                
                temp = s.top();
                s.pop();
                
                ans.push_back(temp->val); 
                
                //go right subtree
                temp = temp->right;
            }
        }
        
        return ans;
    }
};


//POSTORDER: L R Root

//Method 1: Using 2 stacks
//Note: instead of second stack, we can simply return the reverse of array stored. This problem is for interview purpose only.
//Pre Order - Root L R

//If we can somehow get - Root R L, and then reverse it => L R Root.
//So, for PostOrder, follow the Preorder method, just push left first in the stack, instead of right.



class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s1;
        stack<int> s2;
        
        s1.push(root);
        TreeNode* temp;
        
        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            
           s2.push(temp->val);
          //or, ans.push_back(temp->val); //and return the reverse of this array
            
            if(temp->left != NULL)
                s1.push(temp->left);
            
            if(temp->right != NULL)
                s1.push(temp->right);
        }
        
        
        while(!s2.empty())
        {
            ans.push_back(s2.top());
            s2.pop();
        }
        
        return ans;
    }
};

//POSTORDER: L R Root

// https://drive.google.com/file/d/1SDV9OhA3S-nVuCJBAv459juSWrFv2Pfx/view?usp=drive_link


//Method 2: Using only one stack
//Keep going to the left (and pushing in stack)/
//When current node becomes NULL (obviously its root will be the top of stack), check if right subtree exists for its root
//if it does, update current node to the root's (top of stack's) right subtree
//else, if right subtree is also NULL, print the root (top of stack)
//and check if popped node is the right child of top of stack. If it isn't go to right of top of stack.

//LEAF -> print, CHECK IF RIGHT EXISTS FOR ITS ROOT, IF YES, UPDATE CURRENT

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        TreeNode* temp = new TreeNode();
        
        while(curr != NULL || !s.empty())
        {
            if(curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            
            else
            {
                temp = s.top()->right;
                
                if(temp != NULL) //right subtree exists, go one step right
                    curr = temp;
                
                else //leaf node
                {

                    //NOTE, YES THESE SEEM REPEATED AS THE WHILE LOOP,
                    //BUT THESE ARE NECESSARY IN CASE OF SKEWED LEFT SUBTREE
                    
                    //for left subtree
                    temp = s.top();
                    s.pop(); 
                    ans.push_back(temp->val); 
                    
                    
                    //for right subtree
                    while(!s.empty() && temp == s.top()->right)
                    {
                        temp = s.top();
                        s.pop();
                        
                        ans.push_back(temp->val);
                    }
                }
            }
        }
       
        return ans;
    }
};

// Stack simulates this:

// First time → expand children

// Second time → print node


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();

            if (node == NULL) continue;

            if (visited) {
                // Both children already processed
                ans.push_back(node->val);
            } else {
                // Postorder: left → right → root
                st.push({node, true});        // process root later
                st.push({node->right, false});
                st.push({node->left, false});
            }
        }
        return ans;
    }
};

