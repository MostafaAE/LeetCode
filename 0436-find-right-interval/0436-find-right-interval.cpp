class Solution {
public:
    /* 
    * Approach:
    * use a map to map each start with its index, then find the right interval
    * for each end using map lower_bound
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        map<int, int> startToIdx;
        vector<int> result(intervals.size(), -1);
        
        // O(nlogn)
        for(int i = 0 ; i < (int)intervals.size() ; i++)
            startToIdx[intervals[i][0]] = i;
        
        // O(nlogn)
        for(int i = 0 ; i < (int)intervals.size() ; i++)
        {
            auto lb = startToIdx.lower_bound(intervals[i][1]);
            
            if(lb != startToIdx.end())
                result[i] = lb->second;
        }
        
        return result;
    }
};