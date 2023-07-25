//Two sum problem, but input is BST.

//Brute
//Store inorder array, it will be sorted, apply two pointer
//TC: O(N)
//SC: O(N) 

//Optimal
//SC can be reduced to O(H)
//by using BST iterator approach.
//also create a before function similar to next.

//Create two objects of bst iterator, 
//one for next (L Root R)
//One for prev (R Root L)

//TC: O(N)
//SC: O(H) 


class BSTIterator {
    
    private:
    stack<TreeNode*> s;
    bool isReverse;
    
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
    
    void pushAllRight(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        TreeNode* temp = root;
        
        while(temp)
        {
            s.push(temp);
            temp = temp->right;
        }
    }
    
public:
    BSTIterator(TreeNode* root, bool reverse) {
        if(reverse == false)
            pushAllLeft(root);
        else
            pushAllRight(root);
        
        isReverse = reverse;
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        
        if(isReverse == false)
            pushAllLeft(temp->right);
        
        else
            pushAllRight(temp->left);
        
        return temp->val;
    }
    
    
    bool hasNext() {
        return !s.empty();
    }
    

};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator forwardArray(root, false);
        BSTIterator reverseArray(root, true);
        
        int num1 = forwardArray.next();
        int num2 = reverseArray.next();
        
        while(num1 < num2)
        {
            if(num1 + num2 == k)
                return true;
            
            else if(num1 + num2 < k)
                num1 = forwardArray.next();
            else
                num2 = reverseArray.next();
        }
        
        return false;
    }
};
