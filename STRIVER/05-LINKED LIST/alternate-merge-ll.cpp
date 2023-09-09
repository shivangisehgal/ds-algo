 ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* next1;
        ListNode* next2;
        
        if(temp1 == NULL)
            return list2;
        
        if(temp2 == NULL)
            return list1;
        
        while(temp1->next != NULL and temp2 != NULL)
        {
             next1 = temp1->next;
             next2 = temp2->next;
            
            temp1->next = temp2;
            temp2->next = next1;
            
            temp1 = next1;
            temp2 = next2;
        }
        
        if(temp1->next == NULL)
            temp1->next = temp2;
          
        return list1;
