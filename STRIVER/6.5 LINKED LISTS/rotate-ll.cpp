//BRUTE:
//Rotate by one for k times
//TC: O(kN)
//SC: O(1)

node* rotateRight(node* head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    
    for (int i = 0; i < k; i++)
    {
        node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    
    return head;
}
//OPTIMAL
/*
  go to the node before the kth node from last (ie, k + 1 th node from last
  also store the last node of the list.
  now, the kth node from last will be the new head, and next of k + 1 th node from last = NULL
  the stored last node of the list would point to the earlier head of the list.
*/

//TC: O(N)
//SC: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0) 
            return head;
        
        //find k + 1 th node from end => n - (k + 1) + 1th from beginning = (n - k) th from beg
        ListNode* temp = head;
        int length = 1;
        
        while(temp->next != NULL) 
        {
            length++;
            temp = temp->next;
        }
        
        ListNode* last = temp;
        
        k = k % length;
        
        if(k == 0)
            return head;
        
        temp = head;
        
        for(int i = 0; i < length - k - 1; i++)
            temp = temp->next;
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        last->next = head;
        
        return newHead;
    }
};
