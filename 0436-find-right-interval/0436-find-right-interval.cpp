class Solution {
public:
    /* 
    * Approach:
    * use a map to map each start with its end and index, then find the right interval
    * for each interval using map lower_bound
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        
        map<int, pair<int,int>> mp;
        vector<int> result;
        
        // O(nlogn)
        for(int i = 0 ; i < (int)intervals.size() ; i++)
            mp[intervals[i][0]] = {intervals[i][1], i};
        
        // O(nlogn)
        for(int i = 0 ; i < (int)intervals.size() ; i++)
        {
            auto lb = mp.lower_bound(intervals[i][1]);
            
            if(lb != mp.end())
                result.push_back(lb->second.second);
            else
                result.push_back(-1);
        }
        
        return result;
    }
};