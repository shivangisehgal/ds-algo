//TC: O(1)
//SC: O(1)

//Copy value of next node into this node
//skip next node

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        if(node->next == NULL)
            return;
        
        ListNode* nextNode = node->next;
        
        node->val = nextNode->val;
        
        node->next = node->next->next;
        
        delete(nextNode);
    }
};
