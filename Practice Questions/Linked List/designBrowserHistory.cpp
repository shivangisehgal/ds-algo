class BrowserHistory;

class Node
{
    string url;
    Node* prev;
    Node* next;
    
    friend class BrowserHistory;
    
    public:
    
    Node(string url)
    {
        this->url = url;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
    Node* head;
    Node* curr;
    Node* tail;
    
public:
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        tail = curr = head;
    }
    
    void visit(string url) {
        
        //delete all node after current
        Node* temp = curr;
        
        while(temp != NULL && temp->next != NULL)
        {
            Node* toBeDeleted = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            delete toBeDeleted;
        }
        
        Node* newPage = new Node(url);
        curr->next = newPage;
        newPage->prev = curr;
      
        //new tail and curr (head is never deleted)
        tail = curr = newPage;
    }
    
    string back(int steps) {
        
        for(int i = 0; i < steps; i++)
        {
            if(curr == head)
                return head->url;
            else
                curr = curr->prev;
        }
        
        return curr->url;
    }
    
    string forward(int steps) {
        
        for(int i = 0; i < steps; i++)
        {
            if(curr == tail)
                return tail->url;
            else
                curr = curr->next;
        }
        
        return curr->url;
    }
};
