//RECURSIVE SOLUTION - IS NOT SPACE OPTIMIZED

/*
  reverse the first sub-list of size k. (assign new_head for this sublist (from START to END): reverseFrom(head, temp)
  START would now be the last element of this reversed sub-list: head
  so now, next of this node should point to the head of next reversed sublist (hence recursive call): head->next = reverseKGroup(head->next, k);
  return the head of the first sublist (new_head)
*/

//TC: O(N)
//SC: O(N/k) : For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.

class Solution {
public:
    
    ListNode* reverseFrom(ListNode* start, ListNode* end)
    {
        ListNode* end_next;
        
        if(end != NULL)
           end_next = end->next;
        
        ListNode* prev = end_next;
        ListNode* curr = start;
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

//Iterative - Fraz
//TC: O(kN)
//SC: O(N/k)

class Solution {
public:
    
    void reverseFrom(ListNode* first, ListNode* last) {
        
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

    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* beforeStart = dummy;
        ListNode* end = head;
        
        int i = 0;
        
        while(end != NULL)
        {
            i++;
            
            if(i % k == 0)
            {
                ListNode* start = beforeStart->next;
                ListNode* afterEnd = end->next;
                reverseFrom(start, end);
                beforeStart->next = end;
                start->next = afterEnd;
                beforeStart = start;
                end = afterEnd;
            }
            
            else
            {
                end = end->next;
            }
        }
        
        return dummy->next;
        
    }
};
