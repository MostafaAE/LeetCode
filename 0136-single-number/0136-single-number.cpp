class Solution {
public:
    /* 
    * Approach:
    * XOR all the array elements together, the result will be the single number.
    * why? because xoring the same number will result in 0
    * and xoring a number with 0 will result in the same number
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int singleNumber(vector<int>& nums) 
    {
        int result {};
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
            result ^= nums[i];
        
        return result;
   
    }
};