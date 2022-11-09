class Solution {
public:
    /* 
    * Approach:
    * calculate the summation on numbers from 1 to n then iterate on the array
    * and subtract each element, the remaining will be the missing number
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int missing = n * (n+1) / 2;
        
        for(int i = 0 ; i < n ; i++)
            missing -= nums[i];
        
        return missing;
    }
};