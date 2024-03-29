class Solution {
public:
    /* 
    * Approach:
    * Sliding window technique
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n{(int)nums.size()}, maxElement, maxElementCount{};
        long long count{};
        maxElement = *max_element(nums.begin(), nums.end());
        
        for(int right = 0, left = 0 ; right < n ; ++right)
        {
            if(nums[right] == maxElement)
                maxElementCount++;
            
            while(maxElementCount == k)
            {
                count += n - right;
                if(nums[left++] == maxElement)
                    maxElementCount--;
            }
        }
        return count;
    }
};