//BRUTE
//use set
//TC: O(N)
//SC: O(N)

node* detectCycle(node* head) {
    unordered_set<node*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}

//OPTIMAL
//let l be length of non-looped list and m be distance in loop from start of loop
//we know, Df = 2 * Ds
//=> (l + nC + m) = 2 (l + m)
//=> l = nC - m
//=> l = (n - 1)C + k
//TC: O(N)
//SC: O(1)
//therefore, if we move slow and head, they'll meet the start of the loop ; covering the same distance
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        bool hasLoop = false;
        
        while(fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)
            {
                hasLoop = true;
                break;
            }
        }
        
        if(!hasLoop)
            return NULL;
        
        ListNode* listStart = head;
        
        while(listStart != slow)
        {
            listStart = listStart->next;
            slow = slow->next;
        }
        
        return listStart;
    }
};
