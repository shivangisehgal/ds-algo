class RandomizedCollection {
    unordered_map<int, vector<int>> map; //stores val and vector of indices where it occurs in v.
    
    vector<pair<int, int>> v; //stores {val, index of val in map's vector}
    
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        bool ans = false;
        
        if(map.find(val) == map.end())
            ans = true;
        
        int i = v.size();
        
        map[val].push_back(i);
        
        v.push_back({val, map[val].size() - 1});
        
        return ans;
    }
    
    bool remove(int val) {
        
        if(map.find(val) == map.end())
            return false;
        
        int index = map[val].back();
        
        auto last = v.back();
        
        map[last.first][last.second] = index;
        
        v[index] = last;
        
        map[val].pop_back();
        
        if(map[val].empty()) 
                map.erase(val);
        
        
        v.pop_back();
        
        return true;
    }
    
    int getRandom() {
        
        return v[rand() % v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
