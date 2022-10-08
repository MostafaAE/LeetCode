class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = -1;
        int end = -1;
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        
        if(lb != ub)
        {
            start = lb-nums.begin();
            end = ub - nums.begin()-1;
        }
        
        return {start,end};
        
    }
};