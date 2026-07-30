class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        map<int, int> startToIndex;

        for(int i = 0 ; i < n ; ++i)
        {
            startToIndex[intervals[i][0]] = i;
        }

        vector<int> result(n, -1);
        for(int i = 0 ; i < n ; ++i)
        {
            auto lb = startToIndex.lower_bound(intervals[i][1]);
            if(lb != startToIndex.end())
            {
                result[i] = lb->second;
            }
        }

        return result;
    }
};