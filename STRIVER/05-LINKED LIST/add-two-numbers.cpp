//OPTIMAL - Simple maths
//TC: O(max(m,n))
//SC: O(max(m,n))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
    
        int c = 0;
        int sum = 0;
        int d;
        
        ListNode* l3 = new ListNode(0);
        
        ListNode* temp3 = l3;
        

        while(temp1 != NULL || temp2 != NULL || c)
        {
            
            sum = 0;
            
            if(temp1 != NULL)
            {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            
            if(temp2 != NULL)
            {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            
            sum += c;
            d = sum % 10;
            c = sum / 10;
            
            temp3->next = new ListNode(d);
            temp3 = temp3->next;
        }
        
        return l3->next;
    }
};
