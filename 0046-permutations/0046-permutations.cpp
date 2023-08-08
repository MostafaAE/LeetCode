vector<bool> selected;
vector<int> nums, perm;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums_) 
    {
        nums = nums_;
        int n{(int)nums.size()};
        selected = vector<bool>(n);
        vector<vector<int>> output;
        solve(output);
        return output;
    }
    
    void solve(vector<vector<int>> &output)
    {
        if((int)perm.size() == (int)nums.size())
        {
            output.push_back(perm);
            return;
        }
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            if(!selected[i])
            {
                selected[i] = 1;
                perm.push_back(nums[i]);
                solve(output);
                perm.pop_back();
                selected[i] = 0;
            }       
        }
    }
};