class SnapshotArray {
private:
    vector<vector<pair<int,int>>> snapArr;
    int curSnapId{};
public:
    SnapshotArray(int length) 
    {
        snapArr = vector<vector<pair<int,int>>>(length);
    }
    
    // O(1)
    void set(int index, int val) 
    {
        vector<pair<int,int>>& v = snapArr[index];
        if(!v.empty() && v.back().first == curSnapId)
            v[(int)v.size()-1].second = val;
        else
            v.push_back({curSnapId, val});
    }
    
    // O(1)
    int snap() 
    {
        return curSnapId++;
    }
    
    // Binary search
    // O(logm) where m is the number of snaps at this index
    int get(int index, int snap_id) 
    {
        vector<pair<int,int>>& v = snapArr[index];
        int start{}, end{(int)v.size()-1}, res{-1};

        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            auto [id, val] = v[mid];
            
            if(id <= snap_id)
                start = mid + 1, res = mid;
            else
                end = mid - 1;
        }
        
        if(res != -1)
            return v[res].second;
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */