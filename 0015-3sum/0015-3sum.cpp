class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n{(int)nums.size()};
        set<vector<int>> unique;
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n ; i++)
        {
            int start{i + 1}, end{n - 1};
            while(start < end)
            {
                if((nums[start] + nums[end]) == (-1*nums[i]))
                {
                    if(unique.insert({nums[i], nums[start], nums[end]}).second)
                        result.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if((nums[start] + nums[end]) < (-1 * nums[i]))
                    start++;
                else
                    end--;  
            }
        }
        
        return result;
    }
};