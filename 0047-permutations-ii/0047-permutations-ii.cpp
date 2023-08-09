vector<int> perm, nums;
class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& nums_) 
    {
        vector<vector<int>> output;
        unordered_map<int, int> freqMp;
        nums = nums_;
        
        for(int num : nums)
            freqMp[num]++;
        
        solve(output, freqMp);
        return output;
    }
    
    void solve(vector<vector<int>> &output, unordered_map<int, int> &freqMp)
    {
        if((int)perm.size() == (int)nums.size())
        {
            output.push_back(perm);
            return;
        }
        
        for(auto [num , freq] : freqMp)
        {
            if(freq)
            {
                freqMp[num]--;
                perm.push_back(num);
                
                solve(output, freqMp);
                
                perm.pop_back();
                freqMp[num]++;
            }
        }
    }
};