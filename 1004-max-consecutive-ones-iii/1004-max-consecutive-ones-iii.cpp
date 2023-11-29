class Solution {
public:
    /* 
    * Approach:
    * Iterate over the array with a variable size sliding window counting ones and zeros keeping at most k 0's
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int longestOnes(vector<int>& nums, int k) {
        int ones{}, zeros{}, maxConsecutiveOnes{}, left{};
        
        for(int right = 0 ; right < (int)nums.size() ; right++)
        {
            nums[right] ? ones++ : zeros++;
            
            while(zeros > k)
                nums[left++] ? ones-- : zeros--;
            
            maxConsecutiveOnes = max(maxConsecutiveOnes, ones + zeros);
        }
        
        return maxConsecutiveOnes;
    }
};