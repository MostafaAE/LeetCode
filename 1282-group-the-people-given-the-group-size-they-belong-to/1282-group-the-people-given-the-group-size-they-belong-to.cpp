class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        int n = groupSizes.size();
        unordered_map<int, vector<vector<int>>> groupSizeToGroups;
        vector<vector<int>> result;

        for(int i = 0 ; i < n ; ++i)
        {
            int groupSize = groupSizes[i];

            if(groupSizeToGroups.count(groupSize) && 
               groupSizeToGroups[groupSize].back().size() < groupSize)
            {
                groupSizeToGroups[groupSize].back().push_back(i);
            }
            else
                groupSizeToGroups[groupSize].push_back(vector<int>(1, i));
        }

        for(auto [groupSize, groups] : groupSizeToGroups)
            result.insert(result.end(), groups.begin(), groups.end());

        return result;
    }
};