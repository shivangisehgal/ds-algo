//BRUTE:
//HASHSET
//TC: O(N)
//SC: O(N)

bool cycleDetect(node* head) 
{
    unordered_set<node*> hashTable;
    while(head != NULL) 
    {
        if(hashTable.find(head) != hashTable.end()) 
          return true;
      
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}


//OPTIMAL - fast and slow
//TC: O(N) | In the worst case, all the nodes of the list are visited.
//SC: O(1)

// INTUITION:
// let's say 2 people are running in a circular track, one person is running slowly and another person is running faster(2 times the speed of first person)
// After a certain period of time person 2 again meet or overtake person 1,
// In that case we can conclude that the track is circular ( replace running track with our Linked list)

//PROOF
/*
Let k be the length of the linked list before the loop and l be the length of the loop.

In the base case where there is no loop, the fast pointer reaches the end of the linked list (null node) before the slow pointer. The time it takes for the fast pointer to reach the end is T = 2k (since it moves twice as fast).

For the inductive step, assume that for a linked list of length (k + l), the fast and slow pointers meet within the loop when the fast pointer has moved 2k steps.

Consider a linked list of length (k + l) + 1 with an additional node beyond the original length. The fast pointer will be at the (k mod l)th node within the loop after moving 2k steps, and the slow pointer will be at node X, which is at the (k mod l)th position or the node before it.

Since the fast pointer moves twice as fast as the slow pointer, it catches up to the slow pointer either at node X or the node before it, proving the inductive step.

By mathematical induction, we have shown that the fast and slow pointers will meet within the loop if there is one, or the fast pointer will reach the end of the linked list if there is no loop.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};
