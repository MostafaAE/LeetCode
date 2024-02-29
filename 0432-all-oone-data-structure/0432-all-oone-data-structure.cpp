class AllOne {
private:
    unordered_map<string, int> strFreq;
    set<pair<int, string>> freqStr;
public:
    AllOne() {
        
    }
    
    // O(logn)
    void inc(string key) {
        
        if(strFreq.count(key))
        {
            int freq = strFreq[key];
            strFreq[key] = freq + 1;
            freqStr.erase({freq, key});
            freqStr.insert({freq + 1 , key});
        }
        else
        {
            strFreq[key] = 1;
            freqStr.insert({1, key});
        }
    }
    
    // O(logn)
    void dec(string key) {

        int freq = strFreq[key];
        freqStr.erase({freq, key});
        
        if(freq > 1)
        {
            strFreq[key] = freq - 1;
            freqStr.insert({freq - 1 , key});
        }
        else
            strFreq.erase(key);
    }
    
    // O(1)
    string getMaxKey() {
        if(freqStr.empty())
            return "";
        
        auto itr = freqStr.end();
        itr--;
        return (*itr).second;
    }
    
    // O(1)
    string getMinKey() {
        if(freqStr.empty())
            return "";
        auto itr = freqStr.begin();
        return (*itr).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */