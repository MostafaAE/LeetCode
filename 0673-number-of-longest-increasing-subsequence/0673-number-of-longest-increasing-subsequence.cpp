class Solution {
private:
    static const int MAX = 2000 + 2;
    int memory[MAX], count[MAX];
    vector<int> nums;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick next mask one approach)
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int findNumberOfLIS(vector<int>& nums_) 
    {
        nums = nums_;
        memset(memory, -1, sizeof(memory));
        fill(count, count + MAX, 1); // Initialize count array with 1 (default count)
        nums.insert(nums.begin(), INT_MIN);
        
        int maxLength = LIS(0) - 1, result{};
        
        
        for(int i = 1 ; i < (int)nums.size() ; i++)
            if(memory[i] == maxLength)
                result += count[i];
        
        return result;
    }
    
    int LIS(int idx)
    {
        if(idx >= (int)nums.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int i = idx + 1 ; i < (int)nums.size() ; i++)
        {
            if(nums[i] > nums[idx])
            {
                int len = LIS(i);
                
                if(len > ret)
                    count[idx] = count[i];
                else if(len == ret)
                    count[idx] += count[i];
                
                ret = max(ret, len);
            }
        }
        ret++;
        return ret;
    }
};