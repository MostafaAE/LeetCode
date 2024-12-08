class MyHashMap {
private:
    const int MAXSIZE = 1001;
    vector<vector<pair<int, int>>> vals;
public:
    MyHashMap() {
        vals = vector<vector<pair<int, int>>>(MAXSIZE);
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        int pos = getPosition(idx, key);
        
        if(pos >= vals[idx].size())
            vals[idx].push_back({key, value});
        else
            vals[idx][pos] = {key, value};
    }
    
    int get(int key) {
        int idx = hash(key);

        int pos = getPosition(idx, key);
        
        if(pos >= vals[idx].size())
            return -1;

        return vals[idx][pos].second;
    }
    
    void remove(int key) {
        int idx = hash(key);

        int pos = getPosition(idx, key);
        
        if(pos != vals[idx].size())
            vals[idx][pos] = {-1, -1};
    }

    int hash(int val)
    {
        return val % MAXSIZE;
    }

    int getPosition(int idx, int key)
    {
        int pos = 0;
        while(pos < vals[idx].size() && vals[idx][pos].first != key)
            ++pos;
        return pos;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */