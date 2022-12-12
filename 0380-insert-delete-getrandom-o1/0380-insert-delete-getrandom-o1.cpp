class RandomizedSet {
private:
    unordered_map<int, int> valToIdx;
    vector<int> v;
public:
    RandomizedSet() 
    {
    }
    
    // O(1)
    bool insert(int val) 
    {
        if(valToIdx.count(val))
            return false;
        
        valToIdx[val] = (int)v.size();
        v.push_back(val);
        
        return true;
    }
    
    // O(1)
    bool remove(int val) 
    {
        if(!valToIdx.count(val))
            return false;
        
        int idx = valToIdx[val];
        valToIdx[v.back()] = idx;
        
        swap(v[idx], v.back());
        v.pop_back();
        valToIdx.erase(val);
        
        return true;
    }
    
    // O(1)
    int getRandom() 
    {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */