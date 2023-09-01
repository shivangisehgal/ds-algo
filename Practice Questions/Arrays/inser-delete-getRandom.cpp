class RandomizedSet {
    
    unordered_map<int, int> map;
    int size;
    vector<int> v;
    
public:
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        //if not in map, add it with its index in array (which will be the last index)
        
        if(map.find(val) == map.end())
        {
            map[val] = size;
            v.push_back(val);
            size++;
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        
        //if in map, swap the value, with the value at the last place in the map,
        //simultaneously update the position of the last index's value in the map
        //delete this element from the map and array (its at last pos now)
        //decrease the size (ie, make pos = pos - 1)
        
        if(map.find(val) != map.end())
        {
            int i = map[val];
            
            map[v[size - 1]] = i;
            
            v[i] = v[size - 1];
            
            
            v.pop_back();
            map.erase(val);
            size--;
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        //use random function to fet a random index
        return v[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
