// BRUTE:
// Push all nodes of all lists into an array, sort by value, rebuild the list.
// TC: O(N log N), SC: O(N)
// N = total nodes across all lists.
//
// BETTER:
// Merge lists one by one (like merging 2 sorted lists repeatedly).
// TC: O(k * N)   // k merges, N total nodes
// SC: O(1)
//
// OPTIMAL:
// Use a min-heap of size k.
// Push the head of each list.
// Pop smallest node, attach to result, and push its next node.
// Repeat until heap empty.
// TC: O(N log k)  // each node pushed+pop once
// SC: O(k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 

struct Cmp{
    public:
        bool operator()(ListNode* a, ListNode* b){
            if(a->val > b->val){
                return true;
            }
            return false;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* temp = head;

        priority_queue<ListNode*, vector<ListNode*>, Cmp> minHeap;

        for(auto& list : lists){
            if(list)
                minHeap.push(list);
        }

        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();

            temp->next = node;
            temp = temp->next;

            if(node->next){
                minHeap.push(node->next);
            }
        }

        return head->next;
    }
};