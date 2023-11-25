//BRUTE
//BFS using queue
//TC: O(N), O(N)

//BETTER
//Recursive, left ka next is equal to child, right ka next root ke next ka left
//TC: O(N), O(1) ignoring stack space

//OPTIMAL
//
//TC: O(N), SC: O(1)

class Solution {
public:
    Node* connect(Node* root) {
        //Initialize pointers
        Node *temp = root, *curr;
        while (temp) {
            curr = prev;
            while (curr && curr->left) { 
                //connects the left subtree of same level with right subtree of that same level 
                curr->left->next = curr->right;
                //connect the rightmost node of a level to the leftmost node of the next level.
                if (curr -> next) 
                  curr->right->next = curr->next->left;
              
                curr = curr->next;
            }
            prev = prev -> left;
        }
        return root;
    }
};
