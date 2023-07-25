//Next should print the current element in inorder array and move next.
//hasnext should return true if next is possible (i.e, still remaining in inorder)
//ques. also required to make constructor.

//BRUTE:
//store the inorder array, perform iteration
//TC: O(N)
//SC: O(N) 

//TC can be reduced to O(1) per operation.
//SC can be reduced to O(H)

//OPTIMAL: Use stack
//intially, constructor should push the root and all its left elements, becuase we need to print inorder.
//once next is called, the top of the stack (which is actually the leftmost element possible) is popped and printed
//now, inorder is actuall left, root, right. left is already taken care of, we have printed the root, now we need to go the right.
//so, for right, we have to push all the leftmost elements of the right of this root before this next call ends.

//Refer notes for more

//TC: O(1) per op.
//SC: O(H)

class BSTIterator {
    
    private:
    stack<TreeNode*> s;
    
    void pushAllLeft(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        TreeNode* temp = root;
        
        while(temp)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        
        pushAllLeft(temp->right);
        
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    
};
