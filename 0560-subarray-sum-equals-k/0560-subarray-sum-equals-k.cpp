class Solution {
public:
    /* 
    * Approach:
    * Calculate the prefix sum and iterate over it counting subarrays sum that equals to k
    * Note: sum(i,j)=sum(0,j)-sum(0,i)
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int subarraySum(vector<int>& nums, int k) {
        int n{(int)nums.size()}, count{};
        unordered_map<int, int> freq;
        
        // prefix sum
        for(int i = 1 ; i < n ; i++)
            nums[i] += nums[i - 1];
        
        
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == k)
                count++;
            if(freq[nums[i] - k])
                count += freq[nums[i] - k];
            
            freq[nums[i]]++;
        }
        
        return count;
    }
};