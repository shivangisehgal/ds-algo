// https://lh3.googleusercontent.com/lQGGtwWBXL3Kvl15qC71jpZwvbokF4h963ahFBTd1fAathQjnPSbpxWbCaXv8c3OjJSaWJRot_Ug9WL85_SEPy9ShJxNNCLUFHTWsjS6pQKWGbGoK4Jhpe4Ebgr4VfbCWfOQ0uHC


//BRUTE
//for each node in l1, check if its present in l2
//TC: O(M*N)
//SC: O(1)

node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

//BETTER
//use a DS (like set) to store nodes of l1. check if a node of l2 is present
//TC: O(M + N)
//SC: O(M + N)

node* intersectionPresent(node* head1,node* head2)
{
    unordered_set<node*> st;
    while(head1 != NULL) 
    {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) 
    {
        if(st.find(head2) != st.end()) 
          return head2;
        head2 = head2->next;
    }
    return NULL;
}

//OPTIMAL - 1 
//calculate lengths of linked lists
//find difference between them
//place the pointer of bigger ll, ahead by difference.
//check if the two node are equal

//TC: O(M + N)
//SC: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        int l1 = 0;
        int l2 = 0;
        
        while(tempA != NULL)
        {
            l1++;
            tempA = tempA->next;
        }
        
        while(tempB != NULL)
        {
            l2++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        
        
        if(l2 > l1)
        {
            while(l2 != l1)
            {
                tempB = tempB->next;
                l2--;
            }
        }
        
        else
        {
            while(l1 != l2)
            {
                tempA = tempA->next;
                l1--;
            }
        }
        
        while(tempA != NULL and tempB != NULL)
        {
            if(tempA == tempB)
                return tempA;
            
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};

//OPTIMAL - 2 (SHORTER)
//traverse both ll simulatenously. once on pointer becomes NULL, difference in the pos would be the diff. -> place that pointer to the start of other ll
//when the other pointer pointer becomes NULL, it would've done 'difference' iterations and the other pointer which was at this (bigger) ll's start would be diff positions ahead
// move this other pointer to start of shorter ll
//problem becomes same as above soln.

//TC: O(M + N)
//SC: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {

        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        
        while(tempA != tempB)
        {
            
            if(tempA != NULL)
                tempA = tempA->next;
            else
                tempA = headB;
            
            if(tempB != NULL)
                tempB = tempB->next;
            else
                tempB = headA;
        }
        
        return tempA;
    }
};
