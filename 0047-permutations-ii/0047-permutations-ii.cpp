
class Solution {
public:
    /* 
    * Approach:
    * Backtracking
    * 
    * Complexity:
    * Time Complexity : O(n.n!)
    * Space Complexity : O(n)
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> output;
        unordered_set<string> uniquePerm;
        solve(0, nums, output, uniquePerm);
        return output;
    }
    
    void solve(int idx, vector<int> &nums, vector<vector<int>> &output, unordered_set<string> &uniquePerm)
    {
        if(idx == (int)nums.size())
        {
            string str;
            for(int num : nums)
                str += to_string(num);
            
            if(uniquePerm.insert(str).second)
                output.push_back(nums);
            return;
        }
        
        for(int i = idx ; i < (int)nums.size() ; i++)
        {
            swap(nums[idx], nums[i]);
            solve(idx + 1, nums, output, uniquePerm);
            swap(nums[idx], nums[i]);     
        }
    }
};