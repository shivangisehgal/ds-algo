//Iterative
//TC: O(N)
//SC: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* current = head;
       ListNode *prev = NULL, *n = NULL;
       while (current != NULL) 
       {
           // Store next
           n = current->next;
           // Reverse current node's pointer
           current->next = prev;
           // Move pointers one position ahead.
           prev = current;
           current = n;
       }
        
       head = prev;
       return head;
    }
};


//Recursive (IMP)
//TC: O(N)
//SC: 0(N) //Stack space or O(1) //ss not taken in consideration
class Solution {
public:
    
    ListNode* helper(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
        {
            return head;
        }
        
        ListNode* subReversedList = helper(head->next);
        ListNode* n = head->next;
        n->next = head;
        head->next = NULL;
        return subReversedList;
    }
    
    ListNode* reverseList(ListNode* head) 
    {
        return helper(head);
    }
};
