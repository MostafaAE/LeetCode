class Solution {
public:
    /* 
    * Approach:
    * Backtracking
    * 
    * Complexity:
    * Time Complexity : O(n.n!)
    * Space Complexity : O(n) auxiliary space for stack
    */
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> output;
        solve(0, nums, output);
        return output;
    }
    
    void solve(int idx, vector<int> &nums, vector<vector<int>> &output)
    {
        if(idx == (int)nums.size())
        {
            output.push_back(nums);
            return;
        }
        
        for(int i = idx ; i < (int)nums.size() ; i++)
        {
            swap(nums[idx], nums[i]);
            solve(idx + 1, nums, output);
            swap(nums[idx], nums[i]);     
        }
    }
};