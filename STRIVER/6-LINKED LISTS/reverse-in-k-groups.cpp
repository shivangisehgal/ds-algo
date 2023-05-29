//RECURSIVE SOLUTION - IS NOT SPACE OPTIMIZED

/*
  reverse the first sub-list of size k. (assign new_head for this sublist (from head to temp) (because hamein purane head ki location ki zaroorat hogi)
  purana head would now point to the last element of this reversed sub-list.
  so now, next of this head should point to the head of next reversed sublist (hence recursive call)
  return the head of the first sublist (new_head)
*/

//TC: O(N)
//SC: O(N/k) : For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.

class Solution {
public:
    
    ListNode* reverseFrom(ListNode* first, ListNode* last)
    {
        ListNode* prev = NULL;
        ListNode* end_next;
        
        if(last != NULL)
           end_next = last->next;
        
        prev = end_next;
        ListNode* curr = first;
        ListNode* n;
        
        
        while(curr != end_next)
        {
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL)
            return NULL;
        
        ListNode* temp = head;
        
        for(int i = 0; temp != NULL and i < k - 1; i++)
            temp = temp->next;
        
        if(temp == NULL)
            return head;
        
        ListNode* newHead = reverseFrom(head, temp);
        
        head->next = reverseKGroup(head->next, k);
        
        return newHead;
    }
};
