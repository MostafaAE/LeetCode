class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> groupSizeToGroup;
        vector<vector<int>> result;

        for(int i = 0 ; i < n ; ++i)
        {
            int groupSize = groupSizes[i];
            groupSizeToGroup[groupSize].push_back(i);

            if(groupSizeToGroup[groupSize].size() == groupSize)
            {
                result.push_back(groupSizeToGroup[groupSize]);
                groupSizeToGroup[groupSize].clear();
            }
        }

        return result;
    }
};