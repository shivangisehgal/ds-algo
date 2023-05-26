//BRUTE
//Create copy nodes, store in hashMAP the og list node and map it to copy node
//then, in another iteration, random of copy node = map[random of og node]

//TC: O(N)
//SC: O(N)
Node* cloneLinkedList(Node* head)
{
    // Map to store the mapping of 
    // old nodes with new ones
    unordered_map<Node*, Node*> mp;
    Node *temp, *copy;
  
    // Duplicate of the first node
    temp = head;
    copy = new Node(temp->val);
    mp[temp] = copy;
  
    // Loop to create duplicates of nodes 
    // with only next pointer
    while (temp->next != NULL) 
    {
        copy->next = new Node(temp->next->val);
        temp = temp->next;
        copy = copy->next;
        mp[temp] = copy;
    }
  
    temp = head;
  
    // Loop to clone the arbit pointers
    while (temp != NULL) 
    {
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
  
    // Return the head of the clone
    return mp[head];
}


//OPTIMAL - IN PLACE

//creaty the copy list nodes after each node of the og list in the og list itself
//assign random of copy nodes, as copy ka random = head ke random ka next
//extract copy nodes and make the og list

//TC: O(N)
//SC: O(1)


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        
       
        Node* copy;
        
        //creating copy
        while(temp != NULL)
        {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        
        temp = head;
        
        //assigning random's in copy
        while(temp != NULL)
        {
            if(temp->random != NULL)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            
            temp = temp->next->next;
        }
        
        Node* copyStart = new Node(0);
        copy = copyStart;
        temp = head;
        
        
        //extracting copy
        while(temp != NULL)
        {
            copy->next = temp->next;
            temp->next = temp->next->next;
            copy = copy->next;
            temp = temp->next;
        }
        
        
        copyStart = copyStart->next;
        
        return copyStart;
    }
};
