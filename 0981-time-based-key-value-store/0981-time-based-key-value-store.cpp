/* 
    * Approach:
    * Utilize a hashmap that map each key to a vectror containing each timestamp and value pair.
    * To set a value we simply put it in the end of the key's corresponing vector.
    * To get a value we binary search for timestamp_prev <= timestamp in the corresponding vector and return the value of that timestamp.
    * 
    * Complexity:
    * Time Complexity :
    * set O(1), get O(logn)
    */
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> hashMap;
public:
    TimeMap() {
        
    }
    
    // O(1)
    void set(string key, string value, int timestamp) 
    {
        if(!hashMap.count(key))
            hashMap[key] = vector<pair<int, string>>();
        
        hashMap[key].push_back({timestamp, value});
    }
    
    // O(logn)
    string get(string key, int timestamp) 
    {
        if(!hashMap.count(key))
            return "";
        
        // O(logn)
        return binarySearch(hashMap[key], timestamp);
    }
    
    string binarySearch(vector<pair<int, string>>& v, int time)
    {
        
        int start{}, end{(int)v.size()-1};
        string res = "";
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(v[mid].first <= time)
            {
                res = v[mid].second;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */