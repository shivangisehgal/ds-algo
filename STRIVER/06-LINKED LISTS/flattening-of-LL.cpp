// TC : O(N * N * M)
//SC: O(1)
// If we consider each vertical linked list of size O(M) in the worst case, then in this method we are merging two vertical sub-linked lists at a time.
// Time is taken to merge two linked lists of size M = O(M+M) =O(2M)
// Similarly, the time is taken to merge another linked list of size M with a linked list of size 2M = O(M+2M)=O(3M)
// Similarly, the time is taken to merge another linked list of size M with a linked list of size 3M = O(M+3M) =O(4M).

// This process will take place N times where N is the no of nodes in the horizontal linked list. So, the total time taken till all the nodes are merged = O(2M+3M+4M+5M+...N * M )
// = O(2+3+4+5+6...+N)* M
// =O(N* ( N + 1 ) / 2)* M
// = O(N * N * M)


//SOLUTION
/*
Elementry case:
you are given two sorted linked lists (bottom-wise) and you have to merge them
Conclusion:
apply recursion, where you recursively go to the last two lists (next-wise) and merge them (bottom-wise)
*/
//TC: O(N*N*M)
//SC: O(1) ??
Node* mergeSortedLists(Node* head1, Node* head2)
{
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;
    
    Node* list3 = new Node(0);
    Node* temp = list3;
    
    while(head1 != NULL and head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            temp->bottom = head1;
            head1 = head1->bottom;
        }
        
        else
        {
            temp->bottom = head2;
            head2 = head2->bottom;
        }
        
        temp = temp->bottom;
    }
    
    if(head1 != NULL)
        temp->bottom = head1;
        
    else 
        temp->bottom = head2;
    
    list3 = list3->bottom;
    
    return list3;
}

Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL) //no list or only one list
        return root; 
        
    //get the second list
    
    Node* l1 = root;
    Node* l2 = flatten(root->next);
    
    //merge the two lists
    
    return mergeSortedLists(l1, l2); //merge bottom-wise

}
