//if N = max nodes in a list, K = number of list OR N = total number of nodes
//BRUTE
//store all nodes in a vector and sort the nodes in the vector and then create a linked list
//TC: O(NK log NK) or O(NlogN)
//SC: O(NK) or O(N)

//ANOTHER APPROACH (Flatten Linked List)
//keep l1,l2...lk, do comparison and store
//TC: O(K * NK) or O(kN)

//OPTIMAL
//store l1,l2...lk in a minHeap
//pops the smallest out of the k and connects
//Keep popping and connecting them
//TC: O(NlogK) //insertion takes logK
//SC: O(K)

class Comp 
{
    public:
       bool operator() (ListNode* a, ListNode* b)
       {
           return a->val > b->val;
       }
};
class Solution {
    
    public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, Comp> minHeap;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
                minHeap.push(lists[i]);
        }
        
        while(!minHeap.empty())
        {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            if(smallest->next != NULL)
                minHeap.push(smallest->next);
            
            tail->next = smallest;
            tail = tail->next;
        }
        
        return dummy->next;
    }
};
