//OPTIMAL (ONE PASS)

// Time Complexity: O(N)
// Space Complexity: O(1)

/*
If length of LL = N
Kth node from last => N - K + 1 th node from beginning

(assuming 1-indexed LL)
we require N - 1 iterations to traverse the list
to get to N - K + 1 th pos => N - K iterations from start
but we have to delete that node, so we have to go to N - K th pos => N - K - 1 iterations
=> N - 1 - (N - K - 1) => AFTER K iterations, we'll start moving the slow ptr.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL)
            return NULL;
    
        
        ListNode* fast = head;
        ListNode* slow = head; 
        
        for(int i = 0; i < n and fast != NULL; i++)
        {
            fast = fast->next;
        }
        
        //edge case, if n >= size of list
        if(fast == NULL)
            return head->next;
        
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        if(slow->next != NULL)
        {
            ListNode* toDelete = slow->next;
            slow->next = toDelete->next;
            delete(toDelete);
        }
        
        return head;
    }
};
