//In case of get and put, that node would be most recently used
//Put/Insertion would be done at most recently used,
//In case, capacity is full, least recently will be deleted

//Thus, we have a doubly linked list
//Get: find the node from map, change its location to front
//Put: find the node from map, 
//  if exists, 
//      if Cache not at capacity, delete node wih old value and push new node at head
//      if Cache at capacity, delete node wih old value, delete tail and push new node at head
//  else, push node at head


class LRUCache;

class Node
{
    int key;
    int val;
    Node* prev;
    Node* next;
    
    friend class LRUCache;
    
    public:
    
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};



class LRUCache {
    
    int cap;
    unordered_map<int, Node*> map; //(key, node) pair | node stores value
    Node* head;
    Node* tail;
    
public:
    LRUCache(int capacity) {
        
        cap = capacity;
        
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->next = tail;
        tail->prev = head;
    }
    
     void deleteNode(Node* curNode)
     {
        Node* beforeNode = curNode->prev;
        Node* afterNode = curNode->next;

        if(beforeNode != NULL)
            beforeNode->next = afterNode; //head & tail sorted
         
        if(afterNode != NULL)
            afterNode->prev = beforeNode; //head & tail sorted
         
         //delete curNode;
    }
    
    void addNodeAtHead(Node* node)
    {
        Node* first = head->next;
        
        node->next = first;
        first->prev = node;
        
        node->prev = head;
        head->next = node;
    }
    
   int get(int key) 
   {
        if (map.find(key) == map.end())
            return -1;
        else 
        {
            Node* node = map[key];
            int value = node->val;
            
            // Move the accessed node to the front
            deleteNode(node);
            addNodeAtHead(node);
            
            return value;
        }
    }
    
    void put(int key, int value) 
    {
        //step 1, delete old node and put at head
        if (map.find(key) != map.end()) 
        {
            Node* oldNode = map[key];
            deleteNode(oldNode);
            
            oldNode->val = value; // Update the value of the existing node
            addNodeAtHead(oldNode);
        } 
        
        else 
        {
            if (map.size() == cap) 
            {
                // Remove the least recently used node (tail)
                Node* leastRecentlyUsed = tail->prev;
                
                deleteNode(leastRecentlyUsed);
                
                map.erase(leastRecentlyUsed->key);
            }

            Node* newNode = new Node(key, value);
            addNodeAtHead(newNode);
            map[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
