class TimeMap {
private:
    unordered_map<string, map<int, string>> hashMap;
public:
    TimeMap() {
        
    }
    
    // O(logn)
    void set(string key, string value, int timestamp) 
    {
        if(hashMap.count(key))
            hashMap[key].insert({timestamp, value});
        else
            hashMap.insert({key, map<int,string>({{timestamp, value}})});
    }
    
    // O(logn)
    string get(string key, int timestamp) 
    {
        if(!hashMap.count(key))
            return "";
        
        // O(logn)
        auto itr = hashMap[key].upper_bound(timestamp);
        
        if(itr == hashMap[key].begin())
            return "";
        
        itr--;
        return itr->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */