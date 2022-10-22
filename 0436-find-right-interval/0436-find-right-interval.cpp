class Solution {
public:
    /* 
    * Approach:
    * use a vector to save each starts and its index and sort them,
    * then use lower_bound to find the riught interval of each end and return its index in the input
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(n)
    */
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        
        vector<pair<int,int>> starts;
        vector<int> result;
        
        // O(n)
        for(int i = 0 ; i < (int)intervals.size() ; i++)
            starts.push_back({intervals[i][0], i});
        
        sort(starts.begin(), starts.end());
        
        // O(nlogn)
        for(int i = 0 ; i < (int)intervals.size() ; i++)
        {
            int rightIntIdx = lower_bound(starts, intervals[i][1]);
            
            if(rightIntIdx < (int)intervals.size())
                result.push_back(starts[rightIntIdx].second);
            else
                result.push_back(-1);
        }
        
        return result;
    }
    
    int lower_bound(vector<pair<int,int>> &nums, int target)
    {
        int start{}, end{(int)nums.size() - 1};

        while (start <= end)
        {
            // prevent overflow
            int mid = start + (end - start) / 2;

            if (target <= nums[mid].first)
                end = mid - 1;

            else
                start = mid + 1;
        }

        return start;
    }
};