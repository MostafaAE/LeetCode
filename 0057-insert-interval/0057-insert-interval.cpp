class Solution {
public:
    /*
     * Approach:
     * Iterate over the intervals array
     * if the current interval comes before the new interval, then insert it in results
     * if the current interval comes after the new interval, then insert the new interval and rest of intervals
     * if the current inerval end overlap with the new interval, then stretch the start of the new interval
     * if the current interval start overlap with the new interval, then stretch the end of the new interval
     * if the current interval completely overlap the new interval, then make the new interval = cur interval
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1) => ignoring the output space
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n{(int)intervals.size()};
        bool isInserted{};
        vector<vector<int>> result;
        for(int i = 0 ; i < n ; i++)
        {
            vector<int> curInterval = intervals[i];
            
            // interval come before the new interval
            if(curInterval[1] < newInterval[0])
                result.push_back(curInterval);
            // interval comes after the new interval
            else if(curInterval[0] > newInterval[1])
            {
                result.push_back(newInterval);
                result.insert(result.end(), intervals.begin()+i, intervals.end());
                isInserted = true;
                break;
            }
            // interval end overlap with the new interval
            else if(curInterval[1] >= newInterval[0] && curInterval[1] <= newInterval[1])
                newInterval[0] = min(newInterval[0], curInterval[0]);
            // interval start overlap with the new interval
            else if(curInterval[0] >= newInterval[0] && curInterval[0] <= newInterval[1])
                newInterval[1] = max(newInterval[1], curInterval[1]);
            // cur interval completely overlap new interval
            else if(curInterval[0] <= newInterval[0] && curInterval[1] >= newInterval[1])
                newInterval = curInterval;
        }
        
        if(!isInserted)
            result.push_back(newInterval);
        
        return result;
    }
};