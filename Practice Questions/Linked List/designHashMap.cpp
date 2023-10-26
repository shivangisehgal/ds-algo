//BRUTE
//Create a vector of pair of max size
int MAX_SIZE = 1e6 + 1;
class MyHashMap {
public:
    vector<int> v;
    
    MyHashMap() {
       v = vector<int>(MAX_SIZE, -1);
    }
    
    void put(int key, int value) {
        v[key] = value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key] = -1;
    }
};

//OPTIMAL
//Create a vector of linked lists with nodes having val = pair<int,int>
//store according to hash function
class MyHashMap {
    vector<list<pair<int, int>>> v;
    int size;
    
public:
    MyHashMap() {
        size = 100;
        v.resize(100);
    }
    
    int hash(int key)
    {
        return key % size;
    }
    
    list<pair<int, int>> :: iterator search(int key)
    {
        int index = hash(key);
        
        for(list<pair<int, int>> :: iterator  it = v[index].begin(); it != v[index].end(); it++)
        {
            if(it->first == key)
                return it;
        }
        
        return v[index].end();
    }
    
    bool contains(int key)
    {
        int index = hash(key);
        
        if(search(key) == v[index].end())
            return false;
        
        return true;
    }
    
    void put(int key, int value) {
        
        int index = hash(key);
        
        if(contains(key))
            remove(key);
        
        v[index].push_back({key, value});
    }
    
    int get(int key) {
        
        if(!contains(key))
            return -1;
        else
        {
            int index = hash(key);
            auto it = search(key);
            return it->second;
        }
    }
    
    void remove(int key) {
        
        if(!contains(key))
            return;
        
        int index = hash(key);
        auto it = search(key);
        v[index].erase(it);
    }
};
