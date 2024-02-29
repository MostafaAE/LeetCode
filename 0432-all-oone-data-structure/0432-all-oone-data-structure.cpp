class AllOne {
    /* 
    * Approach: 
    * We can solve it using a hashtable that map each key to its frequency and another BBST
    * that maps each frequency to its key, using this approach we can implement inc()
    * and dec() in O(logn), and getMaxKey() and getMinKey() in O(1)

    * We can also solve it in another approach by using a hashtable and a doubly linked list 
    * of hashtable of strings, each entry in the hashtable will map a key to its node in the 
    * linkedlist so we can inc() and dec() in O(1) and also getMaxKey() and getMinKey() in O(1).
    *
    */
    
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
        
        return freqStr.rbegin()->second;
    }
    
    // O(1)
    string getMinKey() {
        if(freqStr.empty())
            return "";

        return freqStr.begin()->second;
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