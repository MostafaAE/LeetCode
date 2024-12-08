class MyHashSet {
private:
    const int MAXSIZE = 1001;
    vector<vector<int>> vals;
public:
    MyHashSet() {
        vals = vector<vector<int>>(MAXSIZE);
    }
    
    void add(int key) {
        int idx = hash(key);

        int pos = getPosition(idx, key);
        
        if(pos >= vals[idx].size())
            vals[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);

        int pos = getPosition(idx, key);
        
        if(pos != vals[idx].size())
            vals[idx][pos] = -1;
    }
    
    bool contains(int key) {
        int idx = hash(key);

        int pos = getPosition(idx, key);
        
        return pos < vals[idx].size();
    }
    
    int hash(int val)
    {
        return val % MAXSIZE;
    }

    int getPosition(int idx, int key)
    {
        int pos = 0;
        while(pos < vals[idx].size() && vals[idx][pos] != key)
            ++pos;
        return pos;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */