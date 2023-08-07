vector<int> nums;
int target, k;
class Solution {
public:
    /* 
    * Approach:
    * Optimized Backtracking (Each partition searches for its numbers)
    * 
    * Complexity:
    * Time Complexity : O(K*2^N)
    * Space Complexity : O(N)
    */
    bool canPartitionKSubsets(vector<int>& nums_, int k_) 
    {
        nums = nums_;
        k = k_;
        int n{(int)nums.size()};
        vector<bool> selected(n, false);
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k == 0 && n >= k)
        {
            target = sum / k;
            return tryPartition(0, 0, 0, selected);
        }
        
        return false;
    }
    
    bool tryPartition(int partitionIdx, int numberIdx, int curPartitionSum, vector<bool> &selected)
    {
        // We are done with all the numbers
        if(numberIdx >= (int)nums.size())
        {
            // Successfully partitioned to K equal sum subsets
            if(curPartitionSum == target && partitionIdx == k - 1)
                return true;
            
            return false;
        }
        
        // We are done with this partition
        if(curPartitionSum == target)
            return tryPartition(partitionIdx + 1, 0, 0, selected);
        
        // Pick this element
        if(!selected[numberIdx] && nums[numberIdx] + curPartitionSum <= target)
        {
            selected[numberIdx] = true;
            if(tryPartition(partitionIdx, numberIdx + 1, curPartitionSum + nums[numberIdx], selected))
                return true;
            selected[numberIdx] = false;
        }
        
        // Leave this element
        return tryPartition(partitionIdx, numberIdx + 1, curPartitionSum, selected);
        
    }
};