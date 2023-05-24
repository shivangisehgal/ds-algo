//BRUTE
//TC: O(N) 
//SC: O(1)
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}
};

//OPTIMAL
//TC: O(N) but one-pass
//SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = fast;

        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
        
    }
};
