//ITERATIVE
//TC: O(N + M)
//SC: O(1) // we are not creating any new nodes

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;
        
        else if (list2 == NULL)
            return list1;


	ListNode* list3 = new ListNode();
	    
        ListNode* temp3 = list3;

        while (list1 != NULL && list2 != NULL) 
        {
            if (list1->val <= list2->val) 
            {
                temp3->next = list1;
                temp3 = temp3->next;
                list1 = list1->next;
            }
            
            else 
            {
                temp3->next = list2;
                temp3 = temp3->next;
                list2 = list2->next;
            }
        }

        if (list1 != NULL) 
            temp3->next = list1;

        if (list2 != NULL) 
            temp3->next = list2;
        
        list3 = list3->next;
        
        return list3;
    }
};



//RECURSIVE
//TC: O(N + M)
//SC: O(N + M) //REC STACK
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	
