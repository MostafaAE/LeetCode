class Solution {
public:
    /* 
    * Approach:
    * Calculate the summation on numbers from 1 to n then subtract the summation from the sum of the array elements, the remaining will be the missing number
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int missingNumber(vector<int>& nums) {
        int n{(int)nums.size()};
        
        int sumToN = n * (n + 1) / 2;
        
        int numsSum = accumulate(nums.begin(), nums.end(), 0);
        
        return sumToN - numsSum;
    }
};