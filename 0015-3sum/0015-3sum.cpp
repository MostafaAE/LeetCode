class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n{(int)nums.size()};
        unordered_map<int, int> hashMap;
        set<vector<int>> unique;
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n ; i++)
            hashMap[nums[i]] = i;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                int target = -1 * (nums[i] + nums[j]);
                if(hashMap.count(target))
                {
                    int idx = hashMap[target];
                    if(idx > j && unique.insert({nums[i], nums[j], target}).second)
                        result.push_back({nums[i], nums[j], target});
                }
            }
        }
        
        return result;
    }
};